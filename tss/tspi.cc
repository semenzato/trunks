// Copyright (c) 2013 The Chromium OS Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "tss/tspi.h"

#include "result.h"
#include "context_manager.h"
#include "tsp.h"
#include "tsp_context.h"

using ::trunks::Result;
using ::trunks::ContextManager;
using ::trunks::GetTspInstance;
using ::trunks::TspContext;

// This file implements parts of the C-based TSP interface as defined in the
// TSS specification. Some variable names have been changed for readability.

TSPICALL Tspi_Context_Create(TSS_HCONTEXT* handle) {
  ContextManager<TspContext>* context_manager =
      GetTspInstance()->context_manager();
  return Result::TspResult(context_manager->OpenContext(handle));
}

TSPICALL Tspi_Context_Close(TSS_HCONTEXT handle) {
  ContextManager<TspContext>* context_manager =
      GetTspInstance()->context_manager();
  return Result::TspResult(context_manager->CloseContext(handle));
}

TSPICALL Tspi_Context_FreeMemory(TSS_HCONTEXT handle,
                                 BYTE* memory) {
  ContextManager<TspContext>* context_manager =
      GetTspInstance()->context_manager();
  std::tr1::shared_ptr<TspContext> context =
      context_manager->GetContext(handle);
  if (!context)
    return Result::TspResult(TSS_E_INVALID_HANDLE);
  return Result::TspResult(context->GetResourceManager()->FreeMemory(memory));
}

TSPICALL Tspi_Context_Connect(TSS_HCONTEXT handle,
                              TSS_UNICODE* destination) {
  return Result::TspResult(TSS_E_NOTIMPL);
}

TSPICALL Tspi_TPM_GetRandom(TSS_HTPM handle,
                            UINT32 random_data_length,
                            BYTE** random_data) {
  return Result::TspResult(TSS_E_NOTIMPL);
}

TSPICALL Tspi_TPM_StirRandom(TSS_HTPM handle,
                             UINT32 entropy_data_length,
                             BYTE* entropy_data) {
  return Result::TspResult(TSS_E_NOTIMPL);
}

