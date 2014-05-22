// Copyright (c) 2013 The Chromium OS Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "tpm_message.h"

#include <base/logging.h>

#include <endian.h>

#include "tpm_constants.h"

namespace trunks {

TpmMessage::TpmMessage():tag_(0),code_(0) {}

TpmMessage::~TpmMessage() {}

void TpmMessage::SetHeader(uint16_t tag, uint32_t code) {
  tag_ = tag;
  code_ = code;
}

void TpmMessage::GetHeader(uint16_t* tag, uint32_t* code) {
  *tag = tag_;
  *code = code_;
}

void TpmMessage::Clear() {
  tag_ = 0;
  code_ = 0;
  data_.clear();
}

void TpmMessage::ExportPacketData(uint8_t* packet_buffer, uint32_t* size) {
  if (data_.size() > kTpmBufferSize) {
    LOG(WARNING) << "TDDL: Buffer contains more than " << kTpmBufferSize
      << " bytes, and will not all make it into the packet.";
  }
  *size = kTpmHeaderSize + data_.size();
  memset(packet_buffer, 0, kTpmBufferSize);

  // Copy header into the packet.
  uint16_t tag = htobe16(tag_);
  memcpy(packet_buffer, &tag, 2);
  uint32_t packet_size = htobe32(*size);
  memcpy(packet_buffer+2, &packet_size, 4);
  uint32_t code = htobe32(code_);
  memcpy(packet_buffer+6, &code, 4);

  // Copy data into the packet.
  for (uint32_t i = kTpmHeaderSize; i < *size; i++) {
    packet_buffer[i] = data_.at(i-kTpmHeaderSize);
  }
}

void TpmMessage::ImportPacketData(const uint8_t* buffer, uint32_t size) {
  if (size < kTpmHeaderSize) {
    LOG(WARNING) << "TDDL: Not enough data to form a packet!";
    return;
  }
  // Copy header from packet.
  memcpy(&tag_, buffer, 2);
  tag_ = be16toh(tag_);
  uint32_t packet_size;
  memcpy(&packet_size, buffer+2, 4);
  packet_size = be32toh(packet_size);
  if (packet_size != size) {
    LOG(WARNING) << "TDDL: Packet size mismatch (" << packet_size << " vs "
      << size << ")! Using whichever value is smaller.";
    if (packet_size > size)
      packet_size = size;
  }
  memcpy(&code_, buffer+6, 4);
  code_ = be32toh(code_);

  // Copy data from packet.
  data_.clear();
  for (uint32_t i = kTpmHeaderSize; i < packet_size; i++) {
    data_.push_back(buffer[i]);
  }
}

uint32_t TpmMessage::PopFrontUint8(uint8_t* value) {
  if (data_.size() == 0) {
    LOG(ERROR) << "TDDL: No more data left to read!";
    return 0;
  }
  *value = data_.front();
  data_.erase(data_.begin());
  return 1;
}

uint32_t TpmMessage::PopFrontInt8(int8_t* value) {
  if (data_.size() == 0) {
    LOG(ERROR) << "TDDL: No more data left to read!";
    return 0;
  }
  uint8_t buf = data_.front();
  *value = buf;
  data_.erase(data_.begin());
  return 1;
}

uint32_t TpmMessage::PopFrontUint16(uint16_t* value) {
  if (data_.size() < 2) {
    LOG(ERROR) << "TDDL: Not enough data left to pop out a uint16_t!";
    return 0;
  }
  uint8_t buf[2];
  for (int i = 0; i < 2; i++)
    buf[i] = data_.at(i);
  memcpy(value, buf, 2);
  *value = be16toh(*value);
  data_.erase(data_.begin(), data_.begin()+2);
  return 2;
}

uint32_t TpmMessage::PopFrontUint32(uint32_t* value) {
  if (data_.size() < 4) {
    LOG(ERROR) << "TDDL: Not enough data left to pop out a uint32_t!";
    return 0;
  }
  uint8_t buf[4];
  for (int i = 0; i < 4; i++)
    buf[i] = data_.at(i);
  memcpy(value, buf, 4);
  *value = be32toh(*value);
  data_.erase(data_.begin(), data_.begin()+4);
  return 4;
}

uint32_t TpmMessage::PopFrontUint64(uint64_t* value) {
  if (data_.size() < 8) {
    LOG(ERROR) << "TDDL: Not enough data left to pop out a uint64_t!";
    return 0;
  }
  uint8_t buf[8];
  for (int i = 0; i < 8; i++)
    buf[i] = data_.at(i);
  memcpy(value, buf, 8);
  *value = be64toh(*value);
  data_.erase(data_.begin(), data_.begin()+8);
  return 8;
}

uint32_t TpmMessage::PopFrontArrayUint8(std::vector<uint8_t>* array) {
  uint32_t old_size = data_.size();
  uint32_t array_size;
  PopFrontUint32(&array_size);
  array->clear();
  if (array_size == 0) {
    LOG(WARNING) << "TDDL: Nothing to put in the array...";
  } else {
    if (data_.size() < array_size) {
      LOG(WARNING) << "TDDL: Not enough data to fill uint8_t array!"
        << " Pushing the size to the front of the buffer.";
      PushFrontUint32(array_size);
      return 0;
    }
    while (array_size--) {
      uint8_t value;
      PopFrontUint8(&value);
      array->push_back(value);
    }
  }
  return old_size - data_.size();
}

uint32_t TpmMessage::PopFrontArrayInt8(std::vector<int8_t>* array) {
  uint32_t old_size = data_.size();
  uint32_t array_size;
  PopFrontUint32(&array_size);
  array->clear();
  if (array_size == 0) {
    LOG(WARNING) << "TDDL: Nothing to put in the array...";
  } else {
    if (data_.size() < array_size) {
      LOG(WARNING) << "TDDL: Not enough data to fill int8_t array!"
        << " Pushing the size to the front of the buffer.";
      PushFrontUint32(array_size);
      return 0;
    }
    while (array_size--) {
      int8_t value;
      PopFrontInt8(&value);
      array->push_back(value);
    }
  }
  return old_size - data_.size();
}

uint32_t TpmMessage::PopFrontArrayUint16(std::vector<uint16_t>* array) {
  uint32_t old_size = data_.size();
  uint32_t array_size;
  PopFrontUint32(&array_size);
  array->clear();
  if (array_size == 0) {
    LOG(WARNING) << "TDDL: Nothing to put in the array...";
  } else {
    if (data_.size() < (array_size * 2)) {
      LOG(WARNING) << "TDDL: Not enough data to fill uint16_t array!"
        << " Pushing the size to the front of the buffer.";
      PushFrontUint32(array_size);
      return 0;
    }
    while (array_size--) {
      uint16_t value;
      PopFrontUint16(&value);
      array->push_back(value);
    }
  }
  return old_size - data_.size();
}

uint32_t TpmMessage::PopFrontArrayUint32(std::vector<uint32_t>* array) {
  uint32_t old_size = data_.size();
  uint32_t array_size;
  PopFrontUint32(&array_size);
  array->clear();
  if (array_size == 0) {
    LOG(WARNING) << "TDDL: Nothing to put in the array...";
  } else {
    if (data_.size() < (array_size * 4)) {
      LOG(WARNING) << "TDDL: Not enough data to fill uint32_t array!"
        << " Pushing the size to the front of the buffer.";
      PushFrontUint32(array_size);
      return 0;
    }
    while (array_size--) {
      uint32_t value;
      PopFrontUint32(&value);
      array->push_back(value);
    }
  }
  return old_size - data_.size();
}

uint32_t TpmMessage::PopFrontArrayUint64(std::vector<uint64_t>* array) {
  uint32_t old_size = data_.size();
  uint32_t array_size;
  PopFrontUint32(&array_size);
  array->clear();
  if (array_size == 0) {
    LOG(WARNING) << "TDDL: Nothing to put in the array...";
  } else {
    if (data_.size() < (array_size * 8)) {
      LOG(WARNING) << "TDDL: Not enough data to fill uint64_t array!"
        << " Pushing the size to the front of the buffer.";
      PushFrontUint32(array_size);
      return 0;
    }
    while (array_size--) {
      uint64_t value;
      PopFrontUint64(&value);
      array->push_back(value);
    }
  }
  return old_size - data_.size();
}

uint32_t TpmMessage::PushFrontUint32(uint32_t value) {
  value = htobe32(value);
  uint8_t buf[4];
  memcpy(buf, &value, 4);
  for (int i = 3; i >= 0; i--) {
    data_.insert(data_.begin(), buf[i]);
  }
  return 4;
}

uint32_t TpmMessage::PushBackUint8(uint8_t value) {
  data_.push_back(value);
  return 1;
}

uint32_t TpmMessage::PushBackInt8(int8_t value) {
  uint8_t buf = value;
  data_.push_back(buf);
  return 1;
}

uint32_t TpmMessage::PushBackUint16(uint16_t value) {
  value = htobe16(value);
  uint8_t buf[2];
  memcpy(buf, &value, 2);
  data_.insert(data_.end(), buf, buf+2);
  return 2;
}

uint32_t TpmMessage::PushBackUint32(uint32_t value) {
  value = htobe32(value);
  uint8_t buf[4];
  memcpy(buf, &value, 4);
  data_.insert(data_.end(), buf, buf+4);
  return 4;
}

uint32_t TpmMessage::PushBackUint64(uint64_t value) {
  value = htobe64(value);
  uint8_t buf[8];
  memcpy(buf, &value, 8);
  data_.insert(data_.end(), buf, buf+8);
  return 8;
}

uint32_t TpmMessage::PushBackArrayUint8(const std::vector<uint8_t>& array) {
  uint32_t old_size = data_.size();
  PushBackUint32(array.size());
  for (uint32_t i = 0; i < array.size(); i++) {
    PushBackUint8(array.at(i));
  }
  return data_.size() - old_size;
}

uint32_t TpmMessage::PushBackArrayInt8(const std::vector<int8_t>& array) {
  uint32_t old_size = data_.size();
  PushBackUint32(array.size());
  for (uint32_t i = 0; i < array.size(); i++) {
    PushBackInt8(array.at(i));
  }
  return data_.size() - old_size;
}

uint32_t TpmMessage::PushBackArrayUint16(const std::vector<uint16_t>& array) {
  uint32_t old_size = data_.size();
  PushBackUint32(array.size());
  for (uint32_t i = 0; i < array.size(); i++) {
    PushBackUint16(array.at(i));
  }
  return data_.size() - old_size;
}

uint32_t TpmMessage::PushBackArrayUint32(const std::vector<uint32_t>& array) {
  uint32_t old_size = data_.size();
  PushBackUint32(array.size());
  for (uint32_t i = 0; i < array.size(); i++) {
    PushBackUint32(array.at(i));
  }
  return data_.size() - old_size;
}

uint32_t TpmMessage::PushBackArrayUint64(const std::vector<uint64_t>& array) {
  uint32_t old_size = data_.size();
  PushFrontUint32(array.size());
  for (uint32_t i = 0; i < array.size(); i++) {
    PushBackUint64(array.at(i));
  }
  return data_.size() - old_size;
}

}  // namespace trunks
