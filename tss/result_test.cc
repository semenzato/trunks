// Copyright (c) 2013 The Chromium OS Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include <gtest/gtest.h>

#include "tss/tss_error.h"
#include "tss/tss_error_basics.h"

#include "result.h"

namespace trunks {

TEST(ResultTest, Success) {
  ASSERT_TRUE(Result::IsSuccess(TSS_SUCCESS & TSS_LAYER_TSP));
  ASSERT_TRUE(Result::IsSuccess(TSS_SUCCESS & TSS_LAYER_TCS));
  ASSERT_TRUE(Result::IsSuccess(TSS_SUCCESS & TSS_LAYER_TDDL));
  ASSERT_TRUE(Result::IsSuccess(TSS_SUCCESS & TSS_LAYER_TPM));
}

TEST(ResultTest, SubsystemCode) {
  ASSERT_EQ(TSS_LAYER_TSP, ((Result::TspResult(TSS_E_FAIL)) & TSS_LAYER_MASK));
  ASSERT_EQ(TSS_LAYER_TCS, ((Result::TcsResult(TSS_E_FAIL)) & TSS_LAYER_MASK));
  ASSERT_EQ(TSS_LAYER_TDDL,
            ((Result::TddlResult(TSS_E_FAIL)) & TSS_LAYER_MASK));
  ASSERT_EQ(TSS_LAYER_TPM, ((Result::TpmResult(TSS_E_FAIL)) & TSS_LAYER_MASK));
}

TEST(ResultTest, Clobber) {
  ASSERT_EQ(TSS_LAYER_TSP,
            ((Result::TspResult(Result::TcsResult(TSS_E_FAIL))) &
              TSS_LAYER_MASK));
  ASSERT_EQ(TSS_LAYER_TSP,
            ((Result::TspResult(Result::TddlResult(TSS_E_FAIL))) &
              TSS_LAYER_MASK));
  ASSERT_EQ(TSS_LAYER_TSP,
            ((Result::TspResult(Result::TpmResult(TSS_E_FAIL))) &
              TSS_LAYER_MASK));
  ASSERT_EQ(TSS_LAYER_TCS,
            ((Result::TcsResult(Result::TspResult(TSS_E_FAIL))) &
              TSS_LAYER_MASK));
  ASSERT_EQ(TSS_LAYER_TCS,
            ((Result::TcsResult(Result::TddlResult(TSS_E_FAIL))) &
              TSS_LAYER_MASK));
  ASSERT_EQ(TSS_LAYER_TCS,
            ((Result::TcsResult(Result::TpmResult(TSS_E_FAIL))) &
              TSS_LAYER_MASK));
  ASSERT_EQ(TSS_LAYER_TDDL,
            ((Result::TddlResult(Result::TspResult(TSS_E_FAIL))) &
              TSS_LAYER_MASK));
  ASSERT_EQ(TSS_LAYER_TDDL,
            ((Result::TddlResult(Result::TcsResult(TSS_E_FAIL))) &
              TSS_LAYER_MASK));
  ASSERT_EQ(TSS_LAYER_TDDL,
            ((Result::TddlResult(Result::TpmResult(TSS_E_FAIL))) &
              TSS_LAYER_MASK));
  ASSERT_EQ(TSS_LAYER_TPM,
            ((Result::TpmResult(Result::TspResult(TSS_E_FAIL))) &
              TSS_LAYER_MASK));
  ASSERT_EQ(TSS_LAYER_TPM,
            ((Result::TpmResult(Result::TcsResult(TSS_E_FAIL))) &
              TSS_LAYER_MASK));
  ASSERT_EQ(TSS_LAYER_TPM,
            ((Result::TpmResult(Result::TddlResult(TSS_E_FAIL))) &
              TSS_LAYER_MASK));
}

TEST(ResultTest, Preservation) {
  ASSERT_EQ(TSS_E_FAIL, Result::TspResult(TSS_E_FAIL) & (~TSS_LAYER_MASK));
  ASSERT_EQ(TSS_E_FAIL, Result::TcsResult(TSS_E_FAIL) & (~TSS_LAYER_MASK));
  ASSERT_EQ(TSS_E_FAIL, Result::TddlResult(TSS_E_FAIL) & (~TSS_LAYER_MASK));
  ASSERT_EQ(TSS_E_FAIL, Result::TpmResult(TSS_E_FAIL) & (~TSS_LAYER_MASK));
}

}  // namespace trunks
