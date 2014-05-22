// Copyright (c) 2013 The Chromium OS Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef TRUNKS_TSS_TCS_CONTEXT_H_
#define TRUNKS_TSS_TCS_CONTEXT_H_

#include <map>

#include <base/basictypes.h>

#include "resource_manager.h"
#include "tss/tss_error.h"
#include "tss/tss_typedef.h"
#include "tss/tcs.h"

namespace trunks {

// Defines an object representing a server-side context for applications
// interfacing with Trunks. A context is responsible for:
//  - handling and maintaining any resources (bytestreams) associated with it.
class TcsContext {
 public:
  TcsContext(TCS_CONTEXT_HANDLE handle) : handle_(handle) {}
  virtual ~TcsContext() {}

  // Gets the resource manager.
  // Returns |resource_manager_|.
  virtual ResourceManager* GetResourceManager() { return &resource_manager_; }

  // Gets the context handle bound to this context object.
  // Returns |handle_|.
  TSS_HCONTEXT GetContextHandle() { return handle_; }

 private:
  // The context handle.
  TCS_CONTEXT_HANDLE handle_;

  // The resource manager.
  ResourceManager resource_manager_;

  DISALLOW_COPY_AND_ASSIGN(TcsContext);
};

}  // namespace trunks

#endif  // TRUNKS_TSS_TCS_CONTEXT_H_
