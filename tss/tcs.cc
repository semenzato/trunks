// Copyright (c) 2013 The Chromium OS Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "tcs.h"

#include <base/lazy_instance.h>

static base::LazyInstance<trunks::Tcs> tcs_instance = LAZY_INSTANCE_INITIALIZER;

namespace trunks {

Tcs::Tcs() {
  tpm_.Open();
}

Tcs::~Tcs() {
  tpm_.Close();
}

Tcs* Tcs::GetInstance() {
  return tcs_instance.Pointer();
}

}  // namespace trunks
