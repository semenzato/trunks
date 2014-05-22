// Copyright (c) 2013 The Chromium OS Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef TRUNKS_TSS_TPM_CONSTANTS_H_
#define TRUNKS_TSS_TPM_CONSTANTS_H_

#include <stdint.h>

namespace trunks {

extern const char kTpmDevice[];
extern const uint32_t kTpmHeaderSize;
extern const uint32_t kTpmBufferSize;
extern const uint32_t kTpmPacketSize;

}  // namespace trunks

#endif  // TRUNKS_TSS_TPM_CONSTANTS_H_
