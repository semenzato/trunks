// Copyright (c) 2013 The Chromium OS Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include <gtest/gtest.h>

#include "resource_manager.h"
#include "tss/tss_error.h"

namespace trunks {

// Tests all ResourceManager functions.
TEST(ResourceManagerTest, AllocateFreeMemory) {
  ResourceManager resource_manager;
  BYTE* data = resource_manager.AllocateMemory(64);
  TSS_RESULT result = resource_manager.FreeMemory(data);
  ASSERT_EQ(TSS_SUCCESS, result);
  result = resource_manager.FreeMemory(data);
  ASSERT_EQ(TSS_E_INVALID_RESOURCE, result);
  result = resource_manager.FreeMemory(NULL);
  ASSERT_EQ(TSS_SUCCESS, result);
}

}  // namespace trunks
