// Copyright (c) 2013 The Chromium OS Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef TRUNKS_TSS_TCS_H_
#define TRUNKS_TSS_TCS_H_

#include <base/basictypes.h>

#include "context_manager.h"
#include "tcs_context.h"
#include "tpm.h"

namespace trunks {

// Defines the singleton class that holds the context manager and the object
// representing the TPM device.
class Tcs {
 public:
  Tcs();
  virtual ~Tcs();

  // Gets the TCS context manager.
  ContextManager<TcsContext>* context_manager() { return &context_manager_; }

  // Gets an object representing the TPM.
  virtual Tpm* tpm() { return &tpm_; }

  // Gets the singleton instance for the TCS.
  static Tcs* GetInstance();

 private:
  // The TCS context manager.
  ContextManager<TcsContext> context_manager_;

  // The TPM.
  Tpm tpm_;

  DISALLOW_COPY_AND_ASSIGN(Tcs);
};

}  // namespace trunks

#endif  // TRUNKS_TSS_TCS_H_
