// Copyright (c) 2013 The Chromium OS Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "tsp_context.h"

#include <string>

#include "result.h"

namespace trunks {

TSS_RESULT TspContext::GetAttribUint32(TSS_FLAG attribFlag,
                                       TSS_FLAG subFlag,
                                       UINT32* pulAttrib) {
  return Result::TspResult(TSS_E_NOTIMPL);
}

TSS_RESULT TspContext::SetAttribUint32(TSS_FLAG attribFlag,
                                       TSS_FLAG subFlag,
                                       UINT32 ulAttrib) {
  return Result::TspResult(TSS_E_NOTIMPL);
}

TSS_RESULT TspContext::GetAttribData(TSS_FLAG attribFlag,
                                     TSS_FLAG subFlag,
                                     UINT32* pulAttribDataSize,
                                     BYTE** prgbAttribData) {
  return Result::TspResult(TSS_E_NOTIMPL);
}

TSS_RESULT TspContext::SetAttribData(TSS_FLAG attribFlag,
                                     TSS_FLAG subFlag,
                                     UINT32 ulAttribDataSize,
                                     BYTE* rgbAttribData) {
  return Result::TspResult(TSS_E_NOTIMPL);
}

}  // namespace trunks
