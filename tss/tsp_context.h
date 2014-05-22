// Copyright (c) 2013 The Chromium OS Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef TRUNKS_TSS_TSP_CONTEXT_H_
#define TRUNKS_TSS_TSP_CONTEXT_H_

#include <map>
#include <base/basictypes.h>

#include "resource_manager.h"
#include "tss/tss_error.h"
#include "tss/tss_typedef.h"

namespace trunks {

// Defines an object representing a client-side context for applications
// interfacing with Trunks. A context is responsible for:
//  - handling connections to the TCS (which directly interfaces with the TPM).
//  - handling and maintaining any resources (BYTE arrays) associated with it.
class TspContext {
 public:
  TspContext(TSS_HCONTEXT handle) : handle_(handle) {}
  virtual ~TspContext() {}

  // Gets a 32-bit attribute of the context object (see p.187, 173).
  //  attribFlag: Flag indicating the attribute to be retrieved.
  //  subFlag: Sub flag indicating the attribute to be retrieved.
  //  pulAttrib: Returns value of the specified attribute.
  virtual TSS_RESULT GetAttribUint32(TSS_FLAG attribFlag,
                                     TSS_FLAG subFlag,
                                     UINT32* pulAttrib);

  // Sets a 32-bit attribute of the context object (see p.185, 171).
  //  attribFlag: Flag indicating the attribute to be set.
  //  subFlag: Sub flag indicating the attribute to be set.
  //  pulAttrib: Value to be set for the specified attribute.
  virtual TSS_RESULT SetAttribUint32(TSS_FLAG attribFlag,
                                     TSS_FLAG subFlag,
                                     UINT32 ulAttrib);

  // Gets a non 32-bit attribute of the context object (see p.190, 176).
  //  attribFlag: Flag indicating the attribute to be retrieved.
  //  subFlag: Sub flag indicating the attribute to be retrieved.
  //  pulAttribDataSize: Returns the size of the value for the attribute.
  //  prgbAttribData: Returns the value for the specified attribute.
  virtual TSS_RESULT GetAttribData(TSS_FLAG attribFlag,
                                   TSS_FLAG subFlag,
                                   UINT32* pulAttribDataSize,
                                   BYTE** prgbAttribData);

  // Gets a non 32-bit attribute of the context object (see p.189).
  //  attribFlag: Flag indicating the attribute to be set.
  //  subFlag: Sub flag indicating the attribute to be set.
  //  ulAttribDataSize: Indicates the size of the value for the attribute.
  //  rgbAttribData: Value to be set for the specified attribute.
  virtual TSS_RESULT SetAttribData(TSS_FLAG attribFlag,
                                   TSS_FLAG subFlag,
                                   UINT32 ulAttribDataSize,
                                   BYTE* rgbAttribData);

  // Gets the resource manager for this context.
  virtual ResourceManager* GetResourceManager() { return &resource_manager_; }

  // Gets the context handle for this context.
  TSS_HCONTEXT GetContextHandle() { return handle_; }

 private:
  // The context handle.
  TSS_HCONTEXT handle_;

  // The resource manager.
  ResourceManager resource_manager_;

  DISALLOW_COPY_AND_ASSIGN(TspContext);
};

}  // namespace trunks

#endif  // TRUNKS_TSS_TSP_CONTEXT_H_
