// Copyright (c) 2013 The Chromium OS Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef TRUNKS_TSS_TSP_H_
#define TRUNKS_TSS_TSP_H_

#include <base/basictypes.h>

#include "context_manager.h"
#include "context_manager_tsp_mock.h"

namespace trunks {

// Defines the singleton class that holds the context manager for the TSP
// (along with its mock).
class Tsp {
 public:
  Tsp() {}
  virtual ~Tsp() {}

  // Returns the context manager (or the mock instead if that has been set).
  ContextManager<TspContext>* context_manager();

  // Sets a mock context manager.
  void SetContextManagerTspMock(ContextManagerTspMock* context_manager_mock);

 private:
  // The context manager.
  ContextManager<TspContext> context_manager_;

  // The mock context manager.
  ContextManagerTspMock* context_manager_mock_;

  DISALLOW_COPY_AND_ASSIGN(Tsp);
};

// Function that grabs the singleton instance of the TSP.
Tsp* GetTspInstance();

}  // namespace trunks

#endif  // TRUNKS_TSS_TSP_H_
