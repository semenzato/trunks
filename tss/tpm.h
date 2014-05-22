// Copyright (c) 2013 The Chromium OS Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef TRUNKS_TSS_TPM_H_
#define TRUNKS_TSS_TPM_H_

#include <vector>
#include <base/basictypes.h>

#include "tss/tss_typedef.h"
#include "tpm_constants.h"
#include "tpm_message.h"

namespace trunks {

// A class that interacts with the TPM device, and provides an abstraction to
// all the low-level functionality (reading, writing, etc.).

class Tpm {
 public:
  Tpm();
  virtual ~Tpm();

  // Opens the TPM device and stores the file descriptor in |fd_|.
  virtual TSS_RESULT Open();

  // Closes the TPM device.
  virtual TSS_RESULT Close();

  // Gets |size| random bytes from the TPM device and stores it in |bytes|.
  TSS_RESULT GetRandom(uint32_t size, std::vector<uint8_t>* bytes);

 private:
  // Sends |message| to the TPM device. Performs proper size calculation of the
  // buffer, inserts the header and data, and sends it to the TPM device.
  // Returns:
  //   - TSS_SUCCESS if successful
  //   - TSS_E_FAIL if there was a problem writing to the device.
  virtual TSS_RESULT Send(TpmMessage* message);

  // Recvs |message| from the TPM device. Extracts the header and separates it
  // from the rest of the data.
  // Returns:
  //   - TSS_SUCCESS if successful
  //   - TSS_E_FAIL if there was a problem writing to the device.
  virtual TSS_RESULT Recv(TpmMessage* message);

  // TPM device file descriptor.
  int fd_;

  DISALLOW_COPY_AND_ASSIGN(Tpm);
};

}  // namespace trunks

#endif // TRUNKS_TSS_TPM_H_
