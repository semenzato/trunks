// Copyright (c) 2013 The Chromium OS Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include <gtest/gtest.h>

#include "result.h"
#include "tcs_context.h"
#include "tss/tss_error.h"

namespace trunks {

// Tests GetHandle returns the appropriate handle.
TEST(TcsContextTest, ContextHandle) {
  TcsContext context(1);
  ASSERT_EQ(1, context.GetContextHandle());
}

}  // namespace trunks
