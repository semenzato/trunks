// Copyright (c) 2013 The Chromium OS Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "tss/tspi.h"

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "result.h"
#include "resource_manager.h"
#include "resource_manager_mock.h"
#include "context_manager.h"
#include "context_manager_tsp_mock.h"
#include "tsp_context.h"
#include "tsp_context_mock.h"
#include "tsp.h"

using ::testing::_;
using ::testing::Return;

namespace trunks {

// Tests that we get a TSP instance.
TEST(TspiTest, GetTspInstance) {
  Tsp* tsp = GetTspInstance();
  ASSERT_TRUE(tsp != NULL);
}

// Tests context creation via the TSS API.
TEST(TspiTest, Tspi_Context_CreateClose) {
  Tsp* tsp = GetTspInstance();
  ASSERT_TRUE(tsp != NULL);

  ContextManagerTspMock context_manager;
  tsp->SetContextManagerTspMock(&context_manager);

  // Tests context creation via TSS API.
  TSS_HCONTEXT handle;
  EXPECT_CALL(context_manager, OpenContext(&handle))
    .WillOnce(Return(TSS_SUCCESS));
  TSS_RESULT result = Tspi_Context_Create(&handle);
  ASSERT_EQ(Result::TspResult(TSS_SUCCESS), result);

  // Tests context destruction via TSS API.
  EXPECT_CALL(context_manager, CloseContext(handle))
    .WillOnce(Return(TSS_SUCCESS));
  result = Tspi_Context_Close(handle);
  ASSERT_EQ(Result::TspResult(TSS_SUCCESS), result);
}

// Tests memory freeing via the TSS API.
TEST(TspiTest, Tspi_Context_FreeMemory) {
  Tsp* tsp = GetTspInstance();
  ASSERT_TRUE(tsp != NULL);

  // Sets up some mocks.
  ContextManagerTspMock context_manager;
  tsp->SetContextManagerTspMock(&context_manager);
  TspContextMock* context = new TspContextMock(1);
  std::tr1::shared_ptr<TspContext> ptr(context);
  ResourceManagerMock resource_manager;

  // Tests context memory freeing via TSS API.
  BYTE dummy;
  EXPECT_CALL(context_manager, GetContext(1))
    .WillRepeatedly(Return(ptr));
  EXPECT_CALL(*context, GetResourceManager())
    .WillRepeatedly(Return(&resource_manager));
  EXPECT_CALL(resource_manager, FreeMemory(&dummy))
    .WillOnce(Return(TSS_SUCCESS))
    .WillOnce(Return(TSS_E_INVALID_RESOURCE));
  TSS_RESULT result = Tspi_Context_FreeMemory(1, &dummy);
  ASSERT_EQ(Result::TspResult(TSS_SUCCESS), result);
  result = Tspi_Context_FreeMemory(1, &dummy);
  ASSERT_EQ(Result::TspResult(TSS_E_INVALID_RESOURCE), result);

  std::tr1::shared_ptr<TspContext> empty_ptr;
  // Tests the invalid handle check via TSS API.
  EXPECT_CALL(context_manager, GetContext(2))
    .WillOnce(Return(empty_ptr));
  result = Tspi_Context_FreeMemory(2, 0);
  ASSERT_EQ(Result::TspResult(TSS_E_INVALID_HANDLE), result);
}

// Tests not implemented functions.
TEST(TspiTest, Tspi_Context_Connect) {
  ASSERT_EQ(Result::TspResult(TSS_E_NOTIMPL), Tspi_Context_Connect(0, NULL));
}

TEST(TspiTest, Tspi_TPM_GetRandom) {
  ASSERT_EQ(Result::TspResult(TSS_E_NOTIMPL), Tspi_TPM_GetRandom(0, 0, NULL));
}

TEST(TspiTest, Tspi_TPM_StirRandom) {
  ASSERT_EQ(Result::TspResult(TSS_E_NOTIMPL), Tspi_TPM_StirRandom(0, 0, NULL));
}

}  // namespace trunks
