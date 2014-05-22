/* Copyright (c) 2011 The Chromium OS Authors. All rights reserved.
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 *
 * Byte code interpreter for marshalling/unmarshalling.
 */

#include "trunks_internal.h"

/*
 * Bytecodes
 * ---------
 *
 * Type descriptor:
 * - type kind (byte)
 * - (possibly) type-dependent data
 *
 * Type-dependent data for BC_TYPE:
 * - byte index of type descriptor bytecode (2 bytes)
 *
 * Type-dependent data for BC_ARRAY:
 * - array size (2 bytes)
 *
 * Type-dependent data for BC_RECORD:
 * - number of fields (1 byte)
 * - field bytecodes for field 0
 * - field bytecodes for field 1
 * ...
 *
 * Field bytecodes:
 * - field kind (byte)
 * - field offset in record (2 bytes)
 * - (for variable-length fields:) field number for length field (1 byte)
 * - type descriptor for field (usually leaf type or BC_TYPE)
 *
 */

/* Local declarations for recursion. */


/* Functions that parse bytecodes take a bytecode pointer as a (reference)
 * argument and advance it as a side effect.  If you need to parse it more than
 * once (why?), save the pointer first.
 *
 * The Ttl(Un)MarshalXXX functions also advance their *cursor args as they copy
 * data into the command buffer.
 */

/* Takes a two-byte bytecode and returns the integer it represents. */

static inline int BC2ByteToInt(uint8_t** codep) {
  int n = (*codep)[0] * 256 + (*codep)[1];
  *codep += 2;
  return n;
}

static inline uint8_t* ByteCodeOffsetToPointer(uint8_t** codep) {
  int offset = BC2ByteToInt(codep);
  return ByteCodeIndexToAddress(offset);
}

static int TtlSizeCalcVarfield(void* data, uint8_t* length_field_bc) {
  uint8_t length_field_kind = *length_field_bc++;
  int length_field_offset = BC2ByteToInt(&length_field_bc);
  int length_field_type = *length_field_bc++;
  int length;
  assert(length_field_kind == BC_FIELD_KIND_NORMAL);
  switch (length_field_type) {
    /* A length field may only be an integer. */
    case BC_INT32:
      length = *(uint32_t *) (data + length_field_offset);
      break;
    case BC_INT16:
      length = *(uint16_t *) (data + length_field_offset);
      break;
    default:
      TtlError("invalid type %d of length field", *length_field_bc);
      break;
  }
  return length;
}


static int TtlSizeCalcField(uint8_t** codep, void* data, uint8_t** field_bcs) {
  uint8_t *cp = *codep;
  int field_kind = *cp++;
  int field_offset = BC2ByteToInt(&cp);
  int size;

  switch (field_kind) {

    case BC_FIELD_KIND_NORMAL:
      size = TtlSizeCalc(&cp, data + field_offset);
      break;

    case BC_FIELD_KIND_VARIABLE: {
      int length_field_index = *cp++;
      uint8_t* length_field_bc = field_bcs[length_field_index];
      size = TtlSizeCalcVarfield(data, length_field_bc);
      break;
    }

    default:
      TtlError("invalid field kind %d", field_kind);
      break;
  }

  *codep = cp;
  return size;
}

static int TtlSizeCalcRecord(uint8_t** codep, void* data) {
  uint8_t* field_bcs[TTL_RECORD_FIELDS_MAX];
  uint8_t *cp = *codep;
  int size = 0;
  int nfields = *cp++;
  int i;

  for (i = 0; i < nfields; i++) {
    field_bcs[i] = cp;
    size += TtlSizeCalcField(&cp, data, field_bcs);
  }
  *codep = cp;
  return size;
}

static int TtlSizeCalcArray(uint8_t** codep) {
  uint8_t *cp = *codep;
  int size;
  uint8_t* bogus = 0;

  assert(*cp == BC_INT8 ||
         *cp == BC_INT16 ||
         *cp == BC_INT32 ||
         *cp == BC_INT64);
  size = TtlSizeCalc(&cp, &bogus);
  *codep = cp;
  return size;
}


int TtlSizeCalc(uint8_t** codep, void* data) {
  uint8_t *cp = *codep;
  int size;

  switch (*cp++) {

    case BC_INT64:
      size = 8;
      break;

    case BC_INT32:
      size = 4;
      break;

    case BC_INT16:
      size = 2;
      break;

    case BC_INT8:
      size = 1;
      break;

    case BC_REF: {
      uint8_t* typecode;
      typecode = ByteCodeOffsetToPointer(&cp);
      size = TtlSizeCalc(&typecode, data);
      break;
    }

    case BC_ARRAY:
      size = TtlSizeCalcArray(&cp);
      break;

    case BC_RECORD:
      size = TtlSizeCalcRecord(&cp, data);
      break;

    default:
      TtlError("unknown bytecode %d", *cp);
  }

  *codep = cp;
  return size;
}


static void TtlMarshalField(uint8_t** codep, uint8_t** cursor, void* from,
                            uint8_t** field_bcs) {
  uint8_t *to = *cursor;
  uint8_t *cp = *codep;
  int field_kind = *cp++;
  int field_offset = BC2ByteToInt(&cp);

  switch (field_kind) {

    case BC_FIELD_KIND_NORMAL:
      TtlMarshal(&cp, &to, from + field_offset);
      break;

    case BC_FIELD_KIND_VARIABLE: {
      int length_field_index = *cp++;
      uint8_t* length_field_bc = field_bcs[length_field_index];
      int length = TtlSizeCalcVarfield(from, length_field_bc);
      TtlMarshal_Blob(*(uint8_t**)(((uint8_t*) from) + field_offset),
                      &to, length);
      break;
    }

    default:
      TtlError("invalid field kind %d", field_kind);
      break;
  }

  *cursor = to;
  *codep = cp;
}


static void TtlUnmarshalField(uint8_t** codep, uint8_t** cursor, void* to,
                              uint8_t** field_bcs) {
  uint8_t *from = *cursor;
  uint8_t *cp = *codep;
  int field_kind = *cp++;
  int field_offset = BC2ByteToInt(&cp);

  switch (field_kind) {

    case BC_FIELD_KIND_NORMAL:
      TtlUnmarshal(&cp, &from, to + field_offset);
      break;

    case BC_FIELD_KIND_VARIABLE: {
      int length_field_index = *cp++;
      uint8_t* length_field_bc = field_bcs[length_field_index];
      int length = TtlSizeCalcVarfield(to, length_field_bc);
      TtlUnmarshal_Blob((uint8_t**) (((uint8_t*) to) + field_offset),
                        &from, length);
      break;
    }

    default:
      TtlError("invalid field kind %d", field_kind);
      break;
  }

  *cursor = from;
  *codep = cp;
}


static void TtlMarshalRecord(uint8_t** codep, uint8_t** cursor, void* from) {
  int i;
  uint8_t* to = *cursor;
  uint8_t* cp = *codep;
  uint8_t* field_bcs[TTL_RECORD_FIELDS_MAX];
  int nfields = *cp++;

  for (i = 0; i < nfields; i++) {
    field_bcs[i] = cp;
    TtlMarshalField(&cp, &to, from, field_bcs);
  }

  *cursor = to;
  *codep = cp;
}


static void TtlUnmarshalRecord(uint8_t** codep, uint8_t** cursor, void* to) {
  int i;
  uint8_t* from = *cursor;
  uint8_t* cp = *codep;
  uint8_t* field_bcs[TTL_RECORD_FIELDS_MAX];
  int nfields = *cp++;

  for (i = 0; i < nfields; i++) {
    field_bcs[i] = cp;
    TtlUnmarshalField(&cp, &from, to, field_bcs);
  }

  *cursor = from;
  *codep = cp;
}


static void TtlMarshalArray(uint8_t** codep, uint8_t** cursor, void* from) {
  uint8_t* to = *cursor;
  uint8_t* cp = *codep;
  int size = BC2ByteToInt(&cp);
  /* A fixed-size arrays is allocated inside the structure. */
  memcpy(to, (uint8_t*) from, size);
  to += size;
  *cursor = to;
  *codep = cp;
}


static void TtlUnmarshalArray(uint8_t** codep, uint8_t** cursor, void* to) {
  uint8_t* from = *cursor;
  uint8_t* cp = *codep;
  int size = BC2ByteToInt(&cp);
  /* A fixed-size arrays is allocated inside the structure. */
  memcpy((uint8_t*) to, from, size);
  from += size;
  *cursor = from;
  *codep = cp;
}


void TtlMarshal(uint8_t** codep, uint8_t** cursor, void* from) {
  uint8_t *to = *cursor;
  uint8_t *cp = *codep;

  switch (*cp++) {

    case BC_INT32:
      TtlMarshal_uint32_t(&to, (uint32_t*) from);
      break;

    case BC_INT16:
      TtlMarshal_uint16_t(&to, (uint16_t*) from);
      break;

    case BC_INT8:
      TtlMarshal_uint8_t(&to, (uint8_t*) from);
      break;

    case BC_REF: {
      uint8_t* typecode = ByteCodeOffsetToPointer(&cp);
      TtlMarshal(&typecode, &to, from);
      break;
    }

    case BC_ARRAY:
      TtlMarshalArray(&cp, &to, from);
      break;

    case BC_RECORD:
      TtlMarshalRecord(&cp, &to, from);
      break;

    default:
      TtlError("unknown bytecode %d", *cp);
  }

  *cursor = to;
  *codep = cp;
}


void TtlUnmarshal(uint8_t** codep, uint8_t** cursor, void* to) {
  uint8_t *from = *cursor;
  uint8_t *cp = *codep;

  switch (*cp++) {

    case BC_INT32:
      TtlUnmarshal_uint32_t(&from, (uint32_t*) to);
      break;

    case BC_INT16:
      TtlUnmarshal_uint16_t(&from, (uint16_t*) to);
      break;

    case BC_INT8:
      TtlUnmarshal_uint8_t(&from, (uint8_t*) to);
      break;

    case BC_REF: {
      uint8_t* typecode = ByteCodeOffsetToPointer(&cp);
      TtlUnmarshal(&typecode, &from, to);
      break;
    }

    case BC_ARRAY:
      TtlUnmarshalArray(&cp, &from, to);
      break;

    case BC_RECORD:
      TtlUnmarshalRecord(&cp, &from, to);
      break;

    default:
      TtlError("unknown bytecode %d", *cp);
  }

  *cursor = from;
  *codep = cp;
}


uint32_t TtlRunCommand(uint32_t command_ordinal,
                       int rqu_index, int rsp_index,
                       void* rqu_struct, void* rsp_struct,
                       void* auth1, void* auth2,
                       uint8_t* buffer, const uint32_t buffer_size) {
  uint8_t* cursor = buffer;
  TPM_TAG tag = auth1 == NULL ? TPM_TAG_RQU_COMMAND :
      (auth2 == NULL ? TPM_TAG_RQU_AUTH1_COMMAND : TPM_TAG_RQU_AUTH2_COMMAND);
  uint32_t message_size = TPM_RQU_HEADER_SIZE;
  int auth_size = auth1 == NULL ? 0:
      (auth2 == NULL ? TPM_RQU_AUTH_SIZE: 2 * TPM_RQU_AUTH_SIZE);
  uint32_t read_bytes;
  uint32_t return_code;
  int expected_size;

  /* First compute message size to ensure buffer is large enough. */
  if (rqu_index >= 0) {
    uint8_t* bytecode = ByteCodeIndexToAddress(rqu_index);
    message_size += TtlSizeCalc(&bytecode, rqu_struct);
  }

  message_size += auth_size;

  if (message_size > buffer_size) {
    return TPM_BAD_PARAM_SIZE;
  }

  /* Then marshal the various parts of the message. First the header. */
  TtlMarshal_uint16_t(&cursor, &tag);
  TtlMarshal_uint32_t(&cursor, &message_size);
  TtlMarshal_uint32_t(&cursor, &command_ordinal);

  /* Then the additional command parameters, if any. */
  if (rqu_index >= 0) {
    uint8_t* bytecode = ByteCodeIndexToAddress(rqu_index);
    TtlMarshal(&bytecode, &cursor, rqu_struct);
  }

  /* Then the auths (if any) */
  if (auth1 != NULL) {
    TtlComputeAndMarshal_TPM_AUTH(auth1, buffer, message_size - auth_size,
                                  command_ordinal, &cursor);
    if (auth2 != NULL) {
      TtlComputeAndMarshal_TPM_AUTH(auth2, buffer, message_size - auth_size,
                                    command_ordinal, &cursor);
    }
  }

  /* Check that the computed message size matches the actual size.  This is an
   * important consistency check, since we don't trust the bytecodes. */
  if (cursor - buffer != message_size) {
    return TPM_E_INTERNAL_ERROR;
  }

  /* Send the command to the TPM and receive a response. */
  RETURN_ON_FAILURE(TtlExecute(buffer, message_size, buffer_size, &read_bytes));
  cursor = buffer;

  /* Extract the response header. */
  TtlUnmarshal_uint16_t(&cursor, &tag);
  TtlUnmarshal_uint32_t(&cursor, &message_size);
  TtlUnmarshal_uint32_t(&cursor, &return_code);

  if (return_code != TPM_SUCCESS) {
    return return_code;
  }
  if (message_size > buffer_size) {
    /* Is message_size doesn't lie, we have a buffer overflow.  Anything could
     * happen. TODO(semenzato): the error code could be more specific. */
    return TPM_BAD_PARAM_SIZE;
  }
  if (message_size != read_bytes) {
    return TPM_E_COMMUNICATION_ERROR;
  }

  /* Extract the response parameters, if any */
  if (rsp_index >= 0) {
    uint8_t* bytecode = ByteCodeIndexToAddress(rsp_index);
    TtlUnmarshal(&bytecode, &cursor, rsp_struct);
  }

  /* Compute the expected size of the command response, for a consistency
   * check. */
  expected_size = TPM_RSP_HEADER_SIZE;

  if (rsp_index >= 0) {
    uint8_t* bytecode = ByteCodeIndexToAddress(rsp_index);
    expected_size += TtlSizeCalc(&bytecode, rsp_struct);
  }
  if (auth1 != NULL) {
    expected_size += TPM_RSP_AUTH_SIZE;
  }

  if (message_size != expected_size) {
    /* This isn't necessarily our fault (if message size lies, for instance,
     * then it may be a communication error) so we pick the most likely
     * cause. */
    return TPM_E_INTERNAL_ERROR;
  }

  /* Check the response auth.  Do this last so that earlier unmarshalling or
   * communication errors are reported more precisely. */
  if (auth1 != NULL) {
    int auth_size = TPM_RSP_AUTH_SIZE;
    RETURN_ON_FAILURE(TtlUnmarshalAndVerify_TPM_AUTH(auth1, buffer,
                                                     message_size - auth_size,
                                                     command_ordinal, &cursor));
  }
  return TPM_SUCCESS;
}
