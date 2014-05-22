// Copyright (c) 2013 The Chromium OS Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef TRUNKS_TSS_RESOURCE_MANAGER_MOCK_H_
#define TRUNKS_TSS_RESOURCE_MANAGER_MOCK_H_

#include "resource_manager.h"

#include <base/basictypes.h>
#include <gmock/gmock.h>

#include "tss/tss_error.h"
#include "tss/tss_typedef.h"

namespace trunks {

// Defines a mock for ResourceManager for testing that methods are called by
// the C-based TSPI API.
class ResourceManagerMock : public ResourceManager {
 public:
  MOCK_METHOD1(FreeMemory, TSS_RESULT (BYTE* memory));
};

}  // namespace trunks

#endif  // TRUNKS_TSS_RESOURCE_MANAGER_MOCK_H_
