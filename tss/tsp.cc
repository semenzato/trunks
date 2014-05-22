// Copyright (c) 2013 The Chromium OS Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "tsp.h"

#include <base/lazy_instance.h>

namespace trunks {

// TSP singleton using the lazy instance initializer.
static base::LazyInstance<Tsp> tsp_instance = LAZY_INSTANCE_INITIALIZER;

Tsp* GetTspInstance() { return tsp_instance.Pointer(); }

ContextManager<TspContext>* Tsp::context_manager() {
  if (context_manager_mock_ != NULL)
    return context_manager_mock_;
  return &context_manager_;
}

void Tsp::SetContextManagerTspMock(ContextManagerTspMock*
                                   context_manager_mock) {
  context_manager_mock_ = context_manager_mock;
}

}  // namespace trunks
