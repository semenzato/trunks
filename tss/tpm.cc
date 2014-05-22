// Copyright (c) 2013 The Chromium OS Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "tpm.h"

#include <base/logging.h>
#include <base/string_number_conversions.h>
#include <base/string_piece.h>

#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdint.h>
#include <sys/stat.h>
#include <sys/types.h>

#include "result.h"
#include "tpm_message.h"
#include "tss/tss_error.h"

namespace trunks {

Tpm::Tpm() : fd_(-1) {}

Tpm::~Tpm() {
  if (fd_ != -1)
    Close();
}

TSS_RESULT Tpm::Open() {
  if (fd_ == -1) {
    LOG(WARNING) << "TDDL: TPM is already open!";
    return Result::TddlResult(TSS_SUCCESS);
  }
  fd_ = open(kTpmDevice, O_RDWR);
  if (fd_ == -1)  {
    PLOG(ERROR) << "TDDL: Unable to open " << kTpmDevice;
    return Result::TddlResult(TSS_E_FAIL);
  }
  LOG(INFO) << "TDDL: Opened device on " << kTpmDevice;
  return Result::TddlResult(TSS_SUCCESS);
}

TSS_RESULT Tpm::Close() {
  if (fd_ == -1) {
    LOG(WARNING) << "TDDL: Warning: TPM was never opened";
    return Result::TddlResult(TSS_SUCCESS);
  }
  int result = close(fd_);
  if (result == -1) {
    PLOG(ERROR) << "TDDL: Unable to close " << kTpmDevice;
    return Result::TddlResult(TSS_E_FAIL);
  }
  fd_ = -1;
  return Result::TcsResult(TSS_SUCCESS);
}

TSS_RESULT Tpm::Send(TpmMessage* message) {
  uint8_t packet_buffer[kTpmPacketSize];
  uint32_t size;
  message->ExportPacketData(packet_buffer, &size);
  ssize_t result = write(fd_, packet_buffer, size);
  if (result == -1) {
    PLOG(ERROR) << "TDDL: Unable to write to device";
    return Result::TddlResult(TSS_E_FAIL);
  }
  return Result::TddlResult(TSS_SUCCESS);
}

TSS_RESULT Tpm::Recv(TpmMessage* message) {
  uint8_t packet_buffer[kTpmPacketSize];
  uint32_t size = 0;
  ssize_t result = read(fd_, packet_buffer, kTpmPacketSize);
  if (result == -1) {
    PLOG(ERROR) << "TDDL: Unable to read from device";
    return Result::TddlResult(TSS_E_FAIL);
  }
  size += result;
  message->ImportPacketData(packet_buffer, size);
  return Result::TddlResult(TSS_SUCCESS);
}

TSS_RESULT Tpm::GetRandom(uint32_t size, std::vector<uint8_t>* data) {
  TpmMessage message;
  message.SetHeader(TPM_TAG_RQU_COMMAND, TPM_ORD_GetRandom);
  message.PushBackUint32(size);

  TSS_RESULT result = Send(&message);
  if (!Result::IsSuccess(result)) {
    LOG(ERROR) << Result::ToString(result);
    return result;
  }

  message.Clear();

  result = Recv(&message);
  if (!Result::IsSuccess(result)) {
    LOG(ERROR) << Result::ToString(result);
    return result;
  }

  uint16_t resp;
  uint32_t code;
  message.GetHeader(&resp, &code);
  if (!Result::IsSuccess(code)) {
    LOG(ERROR) << Result::ToString(code);
    return code;
  }
  message.PopFrontArrayUint8(data);
  return code;
}

}  // namespace trunks
