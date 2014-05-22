// Copyright (c) 2013 The Chromium OS Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "tpm_constants.h"

namespace trunks {

const char kTpmDevice[] = "/dev/tpm0";
const uint32_t kTpmHeaderSize = 10;
const uint32_t kTpmBufferSize = 4086;
const uint32_t kTpmPacketSize = 4096;

}  //namespace trunks
