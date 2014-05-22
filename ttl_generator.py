#!/usr/bin/python
# Copyright (c) 2011 The Chromium OS Authors. All rights reserved.
# Use of this source code is governed by a BSD-style license that can be
# found in the LICENSE file.
#
# Originally written by Mario and Luigi at Google.

"""A code generator for TPM utility functions.

The generator inputs the Trousers header file "tpm.h" (here renamed
"tss_tpm_h") as well as massaged representation of TPM commands from
the TPM specs, and outputs marshalling/unmarshalling functions and
type declarations for the TPM structures and commands.
"""

import re, sys, os


# Global copyright header.
_COPYRIGHT_HEADER = """\
/* Copyright (c) 2011 The Chromium OS Authors. All rights reserved.
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */
"""

# Header file include guards.
_HEADER_FILE_GUARD_HEADER = """
#ifndef %(name)s
#define %(name)s
"""

_HEADER_FILE_GUARD_FOOTER = """
#endif  /* %(name)s */
"""

# The tag name for the following structures does not follow the convention.
_STRUCTURE_TAG_EXCEPTIONS = dict(
    TPM_SIGN_INFO="TPM_TAG_SIGNINFO",
    TPM_CONTEXT_BLOB="TPM_TAG_CONTEXTBLOB",
    TPM_DELEGATE_KEY_BLOB="TPM_TAG_DELG_KEY_BLOB")


# A dictionary of commands that are ignored.
IGNORED_COMMANDS = set(["TPM_FieldUpgrade", "TPM_CertifySelfTest"])


# A set of struct declarations that are ignored.
IGNORED_STRUCTS = set([
    "TPM_VERSION_BYTE",
    "TPM_NV_DATA_SENSITIVE",
    "TPM_KEY_HANDLE_LIST"])


# Bytecodes

BC_INT8 = "BC_INT8"
BC_INT16 = "BC_INT16"
BC_INT32 = "BC_INT32"
BC_REF = "BC_REF"
BC_ARRAY = "BC_ARRAY"
BC_RECORD = "BC_RECORD"
BC_FIELD_KIND_NORMAL = "BC_FIELD_KIND_NORMAL"
BC_FIELD_KIND_VARIABLE = "BC_FIELD_KIND_VARIABLE"

# This variable keeps track of bytecode positions
BYTECODE_OFFSET = 0

# Structures whose bytecode offset is required in hand-written C code.
MANUALLY_MARSHALLED_STRUCTS = set([
    "TPM_NONCE",
    "TPM_NV_DATA_PUBLIC",
    "TPM_PUBKEY",
    "TPM_RSA_KEY_PARMS",
    ])

# Variable-length integers (varints) are encoded as 7-bit digits, most
# significant first (big endian, for readability).  Each digit is stored in a
# byte.  The most significant bit is 1 when there are more digits, 0 otherwise.
# For instance:
#
# 4 -> 0x04
# 257 -> 0x81, 0x01
#
# We can use varints only for known integer values, for instance bytecode
# offsets.  A bunch of values are only known at C compilation time.

def IntToByteCode(x):
  return IntToByteCode1(x / 128) + [x % 128]


def IntToByteCode1(x):
  if x == 0:
    return []
  else:
    return IntToByteCode1(x / 128) + [x % 128 + 128]


def OutputVarInt(x, file):
  global BYTECODE_OFFSET
  file.write("/* (%04d) varint: %d */" % (BYTECODE_OFFSET, x))
  bytes = IntToByteCode(x)
  file.write("".join(map(lambda x: " %d," % x, bytes)))
  BYTECODE_OFFSET += len(bytes)
  file.write("\n")


def OutputByte(byte, file):
  global BYTECODE_OFFSET
  file.write("/* (%04d) */ %s,\n" % (BYTECODE_OFFSET, str(byte)))
  BYTECODE_OFFSET += 1


def OutputTwoBytes(x, file):
  global BYTECODE_OFFSET
  file.write("/* (%04d) */ TWO_BYTES_INT(%s),\n" % (BYTECODE_OFFSET, str(x)))
  BYTECODE_OFFSET += 2


def OutputOffsetOf(field_name, record_name, file):
  global BYTECODE_OFFSET
  file.write("/* (%04d) */ OFFSETOF_TWO_BYTES(%s, %s),\n" %
             (BYTECODE_OFFSET, field_name, record_name))
  BYTECODE_OFFSET += 2


# We parse a C header file (MIDL, actually) and produce descriptors for each
# type defined by the header file.  Then we use the descriptors to output
# useful code.
#
# (Before we go any further: confusion may arise in the uninitiated from the
# use of Python objects to describe C types.  The Python objects have types
# themselves.  To reduce the confusion we try to call them "classes" and
# "subclasses" since, luckily, that's what they are.  We reserve the words
# "struct", "record", and "type" for the C types.)
#
# Every named type has a descriptor.  Each kind of type (struct, typedef, etc)
# has an associated class, which is a subclass of TypeDesc.  Other classes are
# used internally to type descriptors, as described below.
#
# There are four kinds of types: built-in types, types defined by typedef,
# types defined by a struct declaration, and pointers.

class TypeDesc(object):
  """Generic type desriptor."""
  def __init__(self):
    self.bytecode_offset = -1

  def OutputByteCodeOffset(self, file):
    OutputVarInt(self.bytecode_offset, file)

  def OutputByteCodeRef(self, file):
    assert self.bytecode_offset >= 0
    OutputByte(BC_REF, file)
    self.OutputByteCodeOffset(file)


class NamedTypeDesc(TypeDesc):
  """Desriptor for named types."""

  def __init__(self, name):
    super(NamedTypeDesc, self).__init__()
    self.name = name

  def Format(self):
    return self.name


class BuiltInTypeDesc(NamedTypeDesc):
  """Desriptor for built-in types."""

  def __init__(self, name, bytecode):
    super(BuiltInTypeDesc, self).__init__(name)
    self.bytecode = bytecode

  def BaseType(self):
    return self

  def OutputByteCodeRef(self, file):
    OutputByte(self.bytecode, file)


class TypedefDesc(NamedTypeDesc):
  """Types defined by another type (i.e. aliases)."""

  def __init__(self, name, definition):
    super(TypedefDesc, self).__init__(name)
    self.definition = definition

  def BaseType(self):
    return self.definition.BaseType()

  def OutputDeclarations(self, out_file):
    # Type declaration only
    out_file.write("typedef %s %s;\n" % (self.definition.name, self.name))

  def OutputDefinitions(self, out_file):
    pass

  def OutputByteCode(self, out_file):
    pass

  def OutputByteCodeRef(self, out_file):
    self.definition.OutputByteCodeRef(out_file)


class RecordDesc(NamedTypeDesc):
  """Descriptor for structs (also typedefs of structs, for simplicity)."""

  def BaseType(self):
    return self

  def OutputByteCode(self, out_file):
    if self.fields:
      bytecode_offset = BYTECODE_OFFSET
      out_file.write("/* Record: %s */\n" % self.name)
      OutputByte(BC_RECORD, out_file)
      OutputByte(len(self.fields), out_file)
      for field in self.fields:
        field.OutputByteCode(out_file)
      self.bytecode_offset = bytecode_offset

  def OutputDeclarations(self, out_file):
    if self.fields:
      self.OutputTypeDeclaration(out_file)

  def OutputTypeDeclaration(self, out_file):
    out_file.write("\ntypedef struct %s {\n" % self.name)
    for field in self.fields:
      field.OutputFieldDeclaration(out_file)
    out_file.write("} %s;\n\n" % self.name)

  def TagName(self):
    if self.name in _STRUCTURE_TAG_EXCEPTIONS:
      return _STRUCTURE_TAG_EXCEPTIONS[self.name]
    else:
      return "TPM_TAG_" + self.name[4:]


class FieldDesc(object):
  """A RecordDesc has a list of fields.

  Each field is described by either a FieldDesc, a VarFieldDesc (for
  variable-length fields), or an ImplicitVarFieldDesc (special case of
  variable-length field where the length is defined implicitly by a
  payload type).
  """

  def __init__(self, record, index):
    # RECORD is the containing record descriptor, used to emit code that lets
    # the C compiler compute field offsets.  INDEX is the position of the field
    # in the record, used to find the size field for variable-length fields.
    self.record = record
    self.index = index
    self.size_field = None

  def OutputByteCode(self, out_file):
    out_file.write("/* Field: %s */\n" % self.name)
    OutputByte(BC_FIELD_KIND_NORMAL, out_file)
    OutputOffsetOf(self.name, self.record.name, out_file)
    self.type.OutputByteCodeRef(out_file)

  def OutputFieldDeclaration(self, out_file):
    out_file.write("  %s %s;\n" % (self.type.name, self.name))


class VarFieldDesc(FieldDesc):
  """Descriptor for variable-length fields."""

  def OutputByteCode(self, out_file):
    out_file.write("/* Variable-length field: %s */\n" % self.name)
    OutputByte(BC_FIELD_KIND_VARIABLE, out_file)
    OutputOffsetOf(self.name, self.record.name, out_file)
    OutputByte(self.size_field.index, out_file)
    self.type.OutputByteCodeRef(out_file)

  def OutputFieldDeclaration(self, out_file):
    out_file.write("  %s* %s;\n" % (self.type.name, self.name))


class ImplicitVarFieldDesc(VarFieldDesc):
  """Descriptor for implicit variable-length fields."""
  pass

class ArrayFieldDesc(FieldDesc):
  """Descriptor for fixed-length array (e.g. TPM_SaveContext, TPM_NONCE)."""

  def OutputFieldDeclaration(self, out_file):
    out_file.write("  %s %s[%s];\n" % (self.element_type.name,
                                       self.name,
                                       self.length))

  def OutputByteCode(self, out_file):
    out_file.write("/* Array field: %s */\n" % self.name)
    OutputByte(BC_ARRAY, out_file)
    OutputTwoBytes(self.length, out_file)
    self.element_type.OutputByteCodeRef(out_file)


class ArgDesc(object):
  """Descriptor for formal argument of a function."""
  def __init__(self, argtype, name):
    self.type = argtype
    self.name = name


class PointerDesc(TypeDesc):
  """Pointer type (used in argument lists)."""

  def __init__(self, base_type):
    super(PointerDesc, self).__init__()
    self.base_type = base_type

  def Format(self):
    return self.base_type.Format() + "*"


# The symbol table, i.e. a dictionary mapping type names to type descriptors.
# It is initialized here with the predefined types.
TYPES_DICT = dict(
    BYTE=BuiltInTypeDesc("uint8_t", "BC_INT8"),
    TSS_BOOL=BuiltInTypeDesc("uint8_t", "BC_INT8"),
    BOOL=BuiltInTypeDesc("uint8_t", "BC_INT8"),
    UINT16=BuiltInTypeDesc("uint16_t", "BC_INT16"),
    UINT32=BuiltInTypeDesc("uint32_t", "BC_INT32"),
    UINT64=BuiltInTypeDesc("uint64_t", "BC_INT64"),
    APSession=BuiltInTypeDesc("APSession", "BC_APSESSION"),
    TPM_RESULT=BuiltInTypeDesc("TPM_RESULT", "BC_INT32"),
    int=BuiltInTypeDesc("int", "BC_INT32"),
    )


class StructureParser(object):
  """Type structure parser.

  "Doing It Right (TM)" would be overkill here. To parse the header file
  "the right way" we would need a full C parser (MIDL, actually). So instead
  we make heavy assumptions on the file format and the types we need to deal
  with. Since the input is quite stable (no changes are expected), this
  works well enough.
  """

  # compile regular expressions
  _STRUCT_RE = re.compile("^typedef\s+struct\s+td(\w+)")
  _ENDSTRUCT_RE = re.compile("^}")
  _TYPEDEF_RE = re.compile("^typedef\s+(\w+)\s+(\w+)")
  # "type name" or "type name[...]" or "type *name"
  _FIELD_RE = re.compile("^\s+(\w+(?:\s*[*])?)\s*(\w+)((?:[[].*[]])?)")
  _SIZEIS_RE = re.compile("^\s+SIZEIS.(\w+)")

  def Parse(self, filename):
    """Parses the TPM header file to extract structure information.

    Args:
      filename: Name of the TPM header file

    Returns:
      List of extracted type descriptors.
    """

    types = []
    header_file = open(filename)

    for line in header_file:

      match = self._STRUCT_RE.search(line)
      if match:
        name = match.group(1)
        if name in IGNORED_STRUCTS:
          continue
        desc = RecordDesc(name)
        TYPES_DICT[name] = desc
        self.ParseRecord(header_file, desc)
        types.append(desc)
        continue

      match = self._TYPEDEF_RE.search(line)
      if match:
        old_name = match.group(1)
        new_name = match.group(2)
        old_desc = TYPES_DICT[old_name]
        desc = TypedefDesc(new_name, old_desc)
        TYPES_DICT[new_name] = desc
        types.append(desc)
        continue

    return types


  def ParseRecord(self, in_file, record_desc):
    """Parses the body of a TPM struct declaration (all but the first line)."""
    fields_list = []
    i = 0
    size_field_name = None
    line = in_file.next()  # skip open brace
    while True:
      line = in_file.next()

      match = self._SIZEIS_RE.search(line)
      if match:
        size_field_name = match.group(1)
        continue

      match = self._FIELD_RE.search(line)
      if match:
        type_name = match.group(1) + match.group(3)
        field_name = match.group(2)
        field_desc = FieldDesc(record_desc, i)
        field_desc.name = field_name
        field_desc.type = type_name
        if size_field_name:
          size_field_index = next((f for f in xrange(len(fields_list))
                                   if fields_list[f].name == size_field_name))
          field_desc.size_field_index = size_field_index
          size_field_name = None
        fields_list.append(field_desc)
        i = i + 1
        continue

      match = self._ENDSTRUCT_RE.search(line)
      if match:
        record_desc.fields = fields_list
        return


class StructureGenerator(object):
  """TPM structure types and marshaling code generator."""

  def Generate(self, types, filename_h, filename_c):
    """Generates the .c and .h file for the given types."""
    # Declarations (.h file)
    h = open(filename_h, "w")
    h.write(_COPYRIGHT_HEADER)
    guard_name = "TRUNKS_%s_" % filename_h.upper().replace(".", "_")
    h.write(_HEADER_FILE_GUARD_HEADER % {"name": guard_name})
    h.write("""
#include <stdint.h>
#include <string.h>

#include "trunks_tpm.h"

""")
    for t in types:
      t.OutputDeclarations(h)
    h.write(_HEADER_FILE_GUARD_FOOTER % {"name": guard_name})
    h.close()

    # Bytecodes (.c file)
    c = open(filename_c, "w")
    c.write(_COPYRIGHT_HEADER)
    c.write("""
#include <stdint.h>
#include <string.h>

#include "%s"
#include "trunks_internal.h"
#include "g_tpm_commands.h"

uint8_t StructureByteCodes[] = {

""" % filename_h)
    for t in types:
      t.OutputByteCode(c)

    c.close()


class Command(object):
  """Descriptor for a TPM command."""

  def __init__(self, name):
    self.name = name
    self.has_auth1 = False
    self.has_auth2 = False
    self.has_ins = False
    self.has_outs = False

  def OutputDeclarations(self, out_file):
    self.request.OutputDeclarations(out_file)
    self.response.OutputDeclarations(out_file)
    out_file.write("\n")
    self.OutputFunctionHeader(out_file, ";\n")

  def OutputByteCode(self, out_file):
    self.request.OutputByteCode(out_file)
    self.response.OutputByteCode(out_file)

  def OutputDefinitions(self, out_file):
    self.OutputFunctionHeader(out_file, " {")
    self.OutputFunctionBody(out_file)

  def OutputFunctionHeader(self, out_file, suffix):
    """Outputs the function header for this command."""
    out_file.write("""\
/* Sends a %s command to the TPM and reads the response. */
uint32_t Ttl_%s(%s)%s""" % (self.name, self.name, self.ArgList(), suffix))

  def ArgList(self):
    if self.args:
      arg_list = map(lambda a: "%s %s" % (a.type.Format(), a.name), self.args)
      return ", ".join(arg_list)
    else:
      return "void"

  def OutputFunctionBody(self, out_file):
    """Outputs the function body for this command."""
    body_template = """
%(initializers)s  RETURN_ON_FAILURE(TtlRunCommand(%(ordinal)s,
         %(rqu_bytecode)s, %(rsp_bytecode)s, in_parameters, out_parameters,
         auth1, auth2, buffer, buffer_size));
  return TPM_SUCCESS;
}

"""
    initializers = ""
    if not self.has_ins:
      initializers += "  void* in_parameters = NULL;\n"
    if not self.has_outs:
      initializers += "  void* out_parameters = NULL;\n"
      initializers += "  uint8_t buffer[TPM_MAX_COMMAND_LENGTH];\n"
      initializers += "  int buffer_size = sizeof(buffer);\n"
    if not self.has_auth1:
      initializers += "  void* auth1 = NULL;\n"
    if not self.has_auth2:
      initializers += "  void* auth2 = NULL;\n"

    # write function body
    out_file.write(body_template % {
        "initializers": initializers,
        "ordinal": self.ordinal,
        "rqu_bytecode": self.request.bytecode_offset,
        "rsp_bytecode": self.response.bytecode_offset,
        })


class CommandParser(object):
  """Command definition parser.

  The text file is extracted from the PDF file containing the TPM
  command specification from the Trusted Computing Group. The syntax
  of the text file is ad-hoc.
  """

  _LINE_SKIP_RE = re.compile("^(\s*$)|(^_COMMENT)")
  _TYPE_RE = "(\w+(?:\s*[[].*[]])?)"
  _COMMAND_RE = re.compile("^_TPM_COMMAND\s+(\w+)$")
  _IN_PARAM_RE = re.compile("^_IN_PARAM\s+%s\s+(\w+)\s+(.*)$" % _TYPE_RE)
  _OUT_PARAM_RE = re.compile("^_OUT_PARAM\s+%s\s+(\w+)\s+(.*)$" % _TYPE_RE)

  # One line of lookahead
  _line = None

  def NextLine(self, in_file):
    try:
      while True:
        self._line = in_file.next()
        if not self._LINE_SKIP_RE.search(self._line):
          break
    except StopIteration:
      self._line = None

  def Parse(self, filename):
    """Parses a text version of the TPM command specification.

    Args:
      filename: Name of the TPM command specification file.

    Returns:
      List of extracted command descriptors.
    """

    commands = []
    f = open(filename)
    self.NextLine(f)

    while True:
      cmd = self.ParseCommand(f)
      if not cmd:
        return commands
      if cmd.name not in IGNORED_COMMANDS:
        commands.append(cmd)

  def ParseCommand(self, f):
    """Parses a TPM command structure."""
    if not self._line:
      return None
    match = self._COMMAND_RE.search(self._line)
    if not match:
      print "cannot match command from line: %s\n" % self._line
    name = match.group(1)
    cmd = Command(name)
    self.NextLine(f)
    cmd.request = self.ParseCommandRR(f, self._IN_PARAM_RE, name + "_rqu")
    cmd.response = self.ParseCommandRR(f, self._OUT_PARAM_RE, name + "_rsp")
    assert ((cmd.request.fields and cmd.response.fields) or
            cmd.name in IGNORED_COMMANDS)
    return cmd

  def ParseCommandRR(self, f, regexp, name):
    """Parses a request or response structure."""
    fields = []
    i = 0
    record = RecordDesc(name)
    while self._line:
      match = regexp.search(self._line)
      if not match:
        break
      field = FieldDesc(record, i)
      field.name = match.group(2)
      # For now assign the type name, not the descriptor, and resolve later.
      # The type resolution also includes transforming a FIELD into a VARFIELD
      # or ARRAYFIELD when applicable.
      field.type = match.group(1)
      field.description = match.group(3)
      field.size_field_name = None
      fields.append(field)
      i = i + 1
      self.NextLine(f)

    record.fields = fields
    return record


class Rewriter(object):
  """TPM type and command rewriter."""

  _POINTER_RE = re.compile("^(\w+)\s*[*]$")
  _ARRAY_RE = re.compile("^(\w+)\s*[[]\s*[]]$")
  _FIXARRAY_RE = re.compile("^(\w+)\s*[[]\s*(\w+)\s*[]]$")
  _TAG_RE = re.compile("^\s*(\w+)\s*$")
  _ORD_RE = re.compile("^.*((TPM|TSC)_ORD_\w+).*$")

  def Rewrite(self, commands):
    for command in commands:
      self.FixTypes(command.request)
      self.FixTypes(command.response)
      self.ExtractConstants(command)
      self.FixRequestHeaderAndTrailer(command)
      self.FixResponseHeaderAndTrailer(command)
      self.ComputeCommandArgs(command)

  def FixTypes(self, record):
    """Fixes the given command structures.

    Args:
      record: structure to be fixed.

    The following modifications are applied:
    1. Replace type names in fields with their type descriptors
    2. Change Fields into VarFields as applicable.
    3. Change Fields into ArrayFields as applicable.
    """

    if not isinstance(record, RecordDesc):
      return

    new_fields = []
    previous_old_field = None
    previous_new_field = None

    for field in record.fields:
      match = Rewriter._POINTER_RE.match(field.type)
      if not match:
        match = Rewriter._ARRAY_RE.match(field.type)
      if match:
        new_field = VarFieldDesc(record, field.index)
        new_field.name = field.name
        new_field.type = TYPES_DICT[match.group(1)]
        new_field.size_field = previous_new_field
      else:
        match = Rewriter._FIXARRAY_RE.match(field.type)
        if match:
          new_field = ArrayFieldDesc(record, field.index)
          element_type = TYPES_DICT[match.group(1)]
          new_field.element_type = element_type
          new_field.name = field.name
          new_field.length = match.group(2)
        else:
          new_field = field  # recycle
          new_field.type = TYPES_DICT[field.type]

      new_fields.append(new_field)
      previous_old_field = field
      previous_new_field = new_field

    record.fields = new_fields

  def ExtractConstants(self, cmd):
    """Extracts the command tag and ordinal."""
    match = Rewriter._TAG_RE.search(cmd.request.fields[0].description)
    if match:
      cmd.tag = match.group(1)
    match = Rewriter._ORD_RE.search(cmd.request.fields[2].description)
    if match:
      cmd.ordinal = match.group(1)
    if not cmd.tag or not cmd.ordinal:
      print "Could not extract tag or ordinal for command %s" % cmd.name

  def FixFields(self, fields, len):
    fields = fields[3:len]
    for field in fields:
      field.index -= 3
    return fields

  def FixRequestHeaderAndTrailer(self, cmd):
    """Fixes the request header and trailer according to the command type."""
    req_params_len = len(cmd.request.fields)
    if cmd.tag == "TPM_TAG_RQU_AUTH2_COMMAND":
      req_params_len -= 10
      cmd.has_auth1 = True
      cmd.has_auth2 = True
    elif cmd.tag == "TPM_TAG_RQU_AUTH1_COMMAND":
      req_params_len -= 5
      cmd.has_auth1 = True
    # remove first three fields
    cmd.request.fields = self.FixFields(cmd.request.fields, req_params_len)
    cmd.has_ins = len(cmd.request.fields) > 0

  def FixResponseHeaderAndTrailer(self, cmd):
    """Fixes the response header and trailer according to the command type."""
    rsp_params_len = len(cmd.response.fields)
    if cmd.tag == "TPM_TAG_RQU_AUTH2_COMMAND":
      rsp_params_len -= 6
    elif cmd.tag == "TPM_TAG_RQU_AUTH1_COMMAND":
      rsp_params_len -= 3
    cmd.response.fields = self.FixFields(cmd.response.fields, rsp_params_len)
    cmd.has_outs = len(cmd.response.fields) > 0

  def ComputeCommandArgs(self, cmd):
    """Generates the argument list for the given command."""
    cmd.args = []
    if cmd.has_ins:
      cmd.args.append(ArgDesc(PointerDesc(cmd.request), "in_parameters"))
    if cmd.has_outs:
      cmd.args.append(ArgDesc(PointerDesc(cmd.response), "out_parameters"))
      cmd.args.append(ArgDesc(PointerDesc(TYPES_DICT["BYTE"]), "buffer"))
      cmd.args.append(ArgDesc(TYPES_DICT["int"], "buffer_size"))
    if cmd.has_auth1:
      cmd.args.append(ArgDesc(PointerDesc(TYPES_DICT["APSession"]), "auth1"))
    if cmd.has_auth2:
      cmd.args.append(ArgDesc(PointerDesc(TYPES_DICT["APSession"]), "auth2"))


class CommandGenerator(object):
  """TPM command types and marshaling code generator."""

  def Generate(self, commands, filename_h, filename_b, filename_c):
    """Generates the .c and .h file for the given commands."""
    h = open(filename_h, "w")
    h.write(_COPYRIGHT_HEADER)
    guard_name = "TRUNKS_%s_" % filename_h.upper().replace(".", "_")
    h.write(_HEADER_FILE_GUARD_HEADER % {"name": guard_name})
    h.write("""
#include "g_tpm_structures.h"
#include "trunks_internal.h"
""")
    b = open(filename_b, "a")
    b.write("\n\n/* Command Structures (request and response) */\n\n")
    c = open(filename_c, "w")
    c.write(_COPYRIGHT_HEADER)
    c.write("""
#include "%s"

""" % filename_h)
    # Output addresses of bytecodes for some struct types.
    for name in MANUALLY_MARSHALLED_STRUCTS:
      struct = TYPES_DICT[name]
      h.write("#define TTL_%s_BYTECODE_OFFSET %d\n" %
              (name, struct.bytecode_offset))
    h.write("\n")
    # Output commands.
    for command in commands:
      command.OutputDeclarations(h)
      command.OutputByteCode(b)
      command.OutputDefinitions(c)
    h.write(_HEADER_FILE_GUARD_FOOTER % {"name": guard_name})
    h.close()
    b.write("};\n")
    b.close()
    c.close()


def Run():
  tpm_structures = StructureParser().Parse("tss_tpm_h")
  for structure in tpm_structures:
    Rewriter().FixTypes(structure)
  StructureGenerator().Generate(
      tpm_structures, "g_tpm_structures.h", "g_tpm_structures.c")
  tpm_commands = CommandParser().Parse("g_tpm_commands_structure.txt")
  Rewriter().Rewrite(tpm_commands)
  CommandGenerator().Generate(tpm_commands, "g_tpm_commands.h",
                              "g_tpm_structures.c", "g_tpm_commands.c")

def Test():
  print "no tests yet"
  exit(1)

# main program

if __name__ == "__main__":
  if len(sys.argv) == 1:
    Run()
  elif len(sys.argv) == 2 and sys.argv[1] == "test":
    Test()
  else:
    sys.stderr.write("usage: %s [test]\n" % sys.argv[0])
    exit(1)
