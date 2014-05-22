// Copyright (c) 2013 The Chromium OS Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef TRUNKS_TSS_TSP_CONTEXT_MOCK_H_
#define TRUNKS_TSS_TSP_CONTEXT_MOCK_H_

#include "tsp_context.h"

#include <gmock/gmock.h>

#include "tss/tss_error.h"
#include "tss/tss_typedef.h"

namespace trunks {

// Defines a TspContext mock for test purposes.
class TspContextMock : public TspContext {
 public:
  TspContextMock(TSS_HCONTEXT handle) : TspContext(handle) {}
  MOCK_METHOD0(GetResourceManager, ResourceManager*());
};

}  // namespace trunks

#endif  // TRUNKS_TSS_TSP_CONTEXT_MOCK_H_
