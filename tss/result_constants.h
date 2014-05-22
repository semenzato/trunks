// Copyright (c) 2013 The Chromium OS Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef TRUNKS_TSS_RESULT_CONSTANTS_H_
#define TRUNKS_TSS_RESULT_CONSTANTS_H_

#include "tss/tss_typedef.h"

namespace trunks {

struct ResultTablePair {
  UINT32 code;
  const char* text;
};

struct ResultTable {
  const char* subsystem;
  const ResultTablePair* code_table;
};

extern const ResultTablePair kGenericCodeTable[];
extern const ResultTablePair kTspCodeTable[];
extern const ResultTablePair kTcsCodeTable[];
extern const ResultTablePair kTddlCodeTable[];
extern const ResultTablePair kTpm12CodeTable[];
extern const ResultTable kResultTable[];

}  // namespace trunks

#endif  // TRUNKS_TSS_RESULT_CONSTANTS_H_
