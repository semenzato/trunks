// Copyright (c) 2013 The Chromium OS Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include <gtest/gtest.h>

#include "context_manager.h"
#include "stub_context.h"

namespace trunks {

// Tests all ContextManager functions.
TEST(ContextManagerTest, OpenCloseContext) {
  ContextManager<StubContext> context_manager;
  ASSERT_EQ(0, context_manager.GetNumContexts());

  TSS_HCONTEXT handle;

  // Tests context creation.
  TSS_RESULT result = context_manager.OpenContext(&handle);
  ASSERT_EQ(TSS_SUCCESS, result);
  ASSERT_EQ(1, context_manager.GetNumContexts());
  std::tr1::shared_ptr<StubContext> context =
    context_manager.GetContext(handle);
  ASSERT_NE(context, std::tr1::shared_ptr<StubContext>());
  ASSERT_EQ(handle, context->GetContextHandle());

  // Tests context deletion.
  result = context_manager.CloseContext(handle);
  ASSERT_EQ(TSS_SUCCESS, result);
  ASSERT_EQ(0, context_manager.GetNumContexts());
  context = context_manager.GetContext(handle);
  ASSERT_EQ(context, std::tr1::shared_ptr<StubContext>());

  // Tests for proper error if invalid context is sent to be destroyed.
  result = context_manager.CloseContext(handle);
  ASSERT_EQ(TSS_E_INVALID_HANDLE, result);

  // Tests for destroying all the contexts.
  for (int i = 0; i < 3; i++) {
    result = context_manager.OpenContext(&handle);
    ASSERT_EQ(TSS_SUCCESS, result);
    ASSERT_EQ(i+1, context_manager.GetNumContexts());
  }
  context_manager.CloseAllContexts();
  ASSERT_EQ(0, context_manager.GetNumContexts());
}

}  // namespace trunks
