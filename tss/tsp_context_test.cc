// Copyright (c) 2013 The Chromium OS Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include <gtest/gtest.h>

#include "result.h"
#include "tsp_context.h"
#include "tss/tss_error.h"

namespace trunks {

// Tests GetHandle returns the appropriate handle.
TEST(TspContextTest, ContextHandle) {
  TspContext context(1);
  ASSERT_EQ(1, context.GetContextHandle());
}

// Tests not implemented functions.
TEST(TspContextTest, NotImpl) {
  TspContext context(0);
  ASSERT_EQ(Result::TspResult(TSS_E_NOTIMPL),
    context.GetAttribUint32(0, 0, NULL));
  ASSERT_EQ(Result::TspResult(TSS_E_NOTIMPL),
    context.SetAttribUint32(0, 0, 0));
  ASSERT_EQ(Result::TspResult(TSS_E_NOTIMPL),
    context.GetAttribData(0, 0, NULL, NULL));
  ASSERT_EQ(Result::TspResult(TSS_E_NOTIMPL),
    context.SetAttribData(0, 0, 0, NULL));
}

}  // namespace trunks
