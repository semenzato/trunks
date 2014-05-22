// Copyright (c) 2013 The Chromium OS Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef TRUNKS_TSS_STUB_CONTEXT_H_
#define TRUNKS_TSS_STUB_CONTEXT_H_

#include <map>

#include <base/basictypes.h>

#include "tss/tss_error.h"
#include "tss/tss_typedef.h"

namespace trunks {

// Defines an object representing a dummy context for tests.
class StubContext {
 public:
  StubContext(TSS_HCONTEXT handle) : handle_(handle) {}
  virtual ~StubContext() {}

  TSS_HCONTEXT GetContextHandle() { return handle_; }

 private:
  TSS_HCONTEXT handle_;

  DISALLOW_COPY_AND_ASSIGN(StubContext);
};

}  // namespace trunks

#endif  // TRUNKS_TSS_STUB_CONTEXT_H_
