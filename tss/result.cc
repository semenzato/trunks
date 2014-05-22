// Copyright (c) 2013 The Chromium OS Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "result.h"

#include <base/stringprintf.h>

#include "tss/tss_error.h"
#include "tss/tss_error_basics.h"

namespace trunks {

bool Result::IsSuccess(TSS_RESULT return_code) {
  return ((return_code & TSS_ERROR_MASK) == TSS_SUCCESS);
}

TSS_RESULT Result::TspResult(TSS_RESULT return_code) {
  return (return_code & ~TSS_LAYER_MASK) | (TSS_LAYER_TSP);
}

TSS_RESULT Result::TcsResult(TSS_RESULT return_code) {
  return (return_code & ~TSS_LAYER_MASK) | (TSS_LAYER_TCS);
}

TSS_RESULT Result::TddlResult(TSS_RESULT return_code) {
  return (return_code & ~TSS_LAYER_MASK) | (TSS_LAYER_TDDL);
}

TSS_RESULT Result::TpmResult(TSS_RESULT return_code) {
  return (return_code & ~TSS_LAYER_MASK) | (TSS_LAYER_TPM);
}

const char* Result::GetTextFromTable(TSS_RESULT return_code,
                                     const ResultTablePair* table) {
  while (table->text != NULL) {
    if (return_code == table->code)
      return table->text;
    table++;
  }
  return NULL;
}

std::string Result::ToString(TSS_RESULT return_code) {
  UINT32 subsystem_code = (return_code & TSS_LAYER_MASK) >> 12;
  UINT32 error_code = (return_code & TSS_ERROR_MASK);

  // Attempt to lookup subsystem-specific error message.
  const char* error_message =
    GetTextFromTable(error_code, kResultTable[subsystem_code].code_table);
  // Fall back to generic error message (unless subsystem is TPM).
  if (!error_message && subsystem_code != 0)
    error_message = GetTextFromTable(error_code, kGenericCodeTable);
  // Fall back to unknown error message.
  if (!error_message)
    error_message = "Unknown error.";

  const char* subsystem_message;
  if (subsystem_code > 3)
    subsystem_message = "Unknown subsystem";
  else
    subsystem_message = kResultTable[subsystem_code].subsystem;

  return StringPrintf("Error %08X: (%s) %s", return_code, subsystem_message,
                      error_message);
}

}
