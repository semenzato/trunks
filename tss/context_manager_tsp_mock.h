// Copyright (c) 2013 The Chromium OS Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef TRUNKS_TSS_CONTEXT_MANAGER_TSP_MOCK_H_
#define TRUNKS_TSS_CONTEXT_MANAGER_TSP_MOCK_H_

#include "context_manager.h"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "tsp_context.h"
#include "tss/tss_typedef.h"
#include "tss/tss_error.h"

namespace trunks {

// Defines a TspContext-specific ContextManager mock for testing that
// the methods are called by the C-based TSPI API.
class ContextManagerTspMock : public ContextManager<TspContext> {
 public:
  MOCK_METHOD1_T(OpenContext, TSS_RESULT (TSS_HCONTEXT*));
  MOCK_METHOD1_T(CloseContext, TSS_RESULT (TSS_HCONTEXT));
  MOCK_METHOD1_T(GetContext, std::tr1::shared_ptr<TspContext> (TSS_HCONTEXT));
};

}  // namespace trunks

#endif  // TRUNKS_TSS_CONTEXT_MANAGER_TSP_MOCK_H_
