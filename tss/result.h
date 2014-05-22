// Copyright (c) 2013 The Chromium OS Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef TRUNKS_TSS_RESULT_H_
#define TRUNKS_TSS_RESULT_H_

#include <string>

#include "tss/tss_typedef.h"

#include "result_constants.h"

namespace trunks {

// Helper functions to return appropriately set return codes in different
// parts of the TSS (i.e. to identify which subsystem they originate from).
// Additionally provides helper functions to convert return codes into nice
// error messages.
class Result {

public:
  // Checks if |return_code| is a success message. Although TSS_SUCCESS is
  // currently defined to be 0, |return_code| may be bitwise-ORed with layer
  // information that tells which part of the TSS the code came from.
  static bool IsSuccess(TSS_RESULT return_code);

  // Adds TSP layer information to |return_code|.
  static TSS_RESULT TspResult(TSS_RESULT return_code);

  // Adds TCS layer information to |return_code|.
  static TSS_RESULT TcsResult(TSS_RESULT return_code);

  // Adds TDDL layer information to |return_code|.
  static TSS_RESULT TddlResult(TSS_RESULT return_code);

  // Adds TPM layer information to |return_code|.
  static TSS_RESULT TpmResult(TSS_RESULT return_code);

  // Provides an English-readable string of |return_code| for use in logging.
  static std::string ToString(TSS_RESULT return_code);

private:
  // Function to lookup English-readable error messages from |return_code|.
  static const char* GetTextFromTable(TSS_RESULT return_code,
                                      const ResultTablePair* table);
};

}  // namespace trunks

#endif  // TRUNKS_TSS_TRUNKS_ERROR_H_
