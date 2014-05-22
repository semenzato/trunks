#!/bin/sh
# Copyright (c) 2011 The Chromium OS Authors. All rights reserved.
# Use of this source code is governed by a BSD-style license that can be
# found in the LICENSE file.

cat tpm_commands_specification.txt |
  # Remove headers and footers.
  sed 's/^.*TPM Main Part 3 Commands.*$//' |
  sed 's/^.*Specification Version 1.2.*$//' |
  sed 's/^.*Level 2 Revision 116 28 February 2011.*$//' |
  sed 's/^.*TCG Published.*$//' |
  sed 's/^.*Copyright.*$//' |
  # Mark descriptions and actions in the body.
  sed 's/^[0-9][0-9]* *Description$/_DESCRIPTION_START/' |
  sed 's/^[0-9][0-9]* *Actions$/_ACTIONS_START/' |
  sed 's/^[0-9][0-9]* *Action$/_ACTIONS_START/' |
  # Remove line numbers, hash index, and type size.
  sed 's/^[0-9]S$//' | sed 's/^[0-9]H[0-9]$//' |
  sed 's/^SZ$//' | sed 's/^#$//' | sed 's/^<>$//' |
  sed 's/^[0-9][0-9]*//' |
  # Replace 'BYTE[ ]' with BYTE[]
  sed 's/BYTE\[ *\]/BYTE\[\]/' |
  # Remove leading spaces.
  sed 's/^[ ][ ]*//' |
  # Remove table headers.
  sed 's/^PARAM$//' | sed 's/^HMAC$//' | sed 's/^Type$//' |
  sed 's/^Name$//' | sed 's/^Description$//' |
  # Remove empty lines.
  sed '/^$/d' |
  # Add TPM command start.
  sed 's/^\.[0-9].*$/_TPM_COMMAND_START/' |
  # Mark informative comment.
  sed 's/^Start of informative comment:$/_COMMENT_START/' |
  sed 's/^End of informative comment.$/_COMMENT_END/' |
  # Mark parameters.
  sed 's/^Incoming Operands and Sizes$/_IN_PARAMS_START/' |
  sed 's/^Incoming Parameters and Sizes$/_IN_PARAMS_START/' |
  sed 's/^Outgoing Operands and Sizes$/_OUT_PARAMS_START/' |
  sed 's/^Outgoing Parameters and Sizes$/_OUT_PARAMS_START/' |
  # Finalize comment.
  awk '
    BEGIN { state = 0; buf = ""; }
    /^[^_].*$/ { if (state) { buf = buf " " $0; } else { print $0; } }
    /^_.*$/    { if ($1 == "_COMMENT_START") { state = 1; buf = ""; }
                 else if ($1 == "_COMMENT_END") {
                     print "_COMMENT" buf; state = 0; }
                 else if ($1 == "_TPM_COMMAND_START") {
                   if (!state) { print $0; state = 0; } }
                 else { print $0; state = 0; } }
  ' |
  # Finalize TPM command start.
  awk '
    BEGIN { state = 0; buf = ""; }
    /^[^_].*$/ { if (state) { if ($1 ~ /^TPM_/ || $1 ~ /^TSC_/) { buf = $0; } }
                 else { print $0; } }
    /^_.*$/    { if ($1 == "_TPM_COMMAND_START") { state = 1; buf = ""; }
                 else { if (state) { print "_TPM_COMMAND " buf; }
                        print $0; state = 0; } }
  ' |
  # Finalize input parameters.
  awk '
    BEGIN { state = 0; buf = ""; }
    /^[^_].*$/ { if (state > 0) {
                   if ($1 ~ "TPM_TAG_") { buf = buf " " $0; }
                   else if ($1 == "BOOL" || $1 ~ "^BYTE" ||
                            $1 ~ "^UINT" || $1 ~ "^TPM_") {
                     if (state > 1) { print "_IN_PARAM " buf; }
                     buf = $0; state = 2; }
                   else if (state > 1) { buf = buf " " $0; } }
                 else { print $0; } }
    /^_.*$/    { if ($1 == "_IN_PARAMS_START") { state = 1; buf = ""; }
                 else { if (state) { print "_IN_PARAM " buf; }
                        print $0; state = 0; } }
  ' |
  # Finalize output parameters.
  awk '
    BEGIN { state = 0; buf = ""; }
    /^[^_].*$/ { if (state > 0) {
                   if ($1 ~ "TPM_TAG_") { buf = buf " " $0; }
                   else if ($1 == "BOOL" || $1 ~ "^BYTE" ||
                            $1 ~ "^UINT" || $1 ~ "^TPM_") {
                     if (state > 1) { print "_OUT_PARAM " buf; }
                     buf = $0; state = 2; }
                   else if (state > 1) { buf = buf " " $0; } }
                 else { print $0; } }
    /^_.*$/    { if ($1 == "_OUT_PARAMS_START") { state = 1; buf = ""; }
                 else { if (state) { print "_OUT_PARAM " buf; }
                        print $0; state = 0; } }
  ' |
  # Remove non marshaled output parameters.
  grep -v '^_OUT_PARAM TPM_COMMAND_CODE ordinal' |
  grep -v '^_OUT_PARAM TPM_NONCE.*onceOdd' |
  # Remove noise and add some structure.
  grep '^_.*' | grep -v '^_DESCRIPTION_START' |
  grep -v '^_ACTIONS_START' | grep -v '^_TPM_COMMAND *$' |
  awk '/^_TPM_COMMAND/ { printf("\n"); } /^.*$/ { print $0; } '

exit 0
