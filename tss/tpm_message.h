// Copyright (c) 2013 The Chromium OS Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef TRUNKS_TSS_TPM_MESSAGE_H_
#define TRUNKS_TSS_TPM_MESSAGE_H_

#include <base/basictypes.h>

#include <stdint.h>
#include <stddef.h>
#include <vector>

namespace trunks {

// A class that manages proper formatting of messages to and from the TPM.
// Main features are: (a) safe functions to add single values and arrays, and
// (b) endian correction in case the host endianness differs from that of the
// TPM.

class TpmMessage {
 public:
  TpmMessage();
  ~TpmMessage();

  // A series of functions that push |value| to the end of |data_|.
  // Corrects for endianness (converts from host to big-endian). Returns the
  // number of bytes added.
  uint32_t PushBackUint8(uint8_t value);
  uint32_t PushBackInt8(int8_t value);
  uint32_t PushBackUint16(uint16_t value);
  uint32_t PushBackUint32(uint32_t value);
  uint32_t PushBackUint64(uint64_t value);

  // A series of functions that push arrays to the end of |data_|. First
  // the size of |array| is pushed as a uint32_t, then the contents of |array|
  // are pushed individually. Corrects for endianness (converts from host to
  // big-endian). Returns the number of bytes added.
  uint32_t PushBackArrayUint8(const std::vector<uint8_t>& array);
  uint32_t PushBackArrayInt8(const std::vector<int8_t>& array);
  uint32_t PushBackArrayUint16(const std::vector<uint16_t>& array);
  uint32_t PushBackArrayUint32(const std::vector<uint32_t>& array);
  uint32_t PushBackArrayUint64(const std::vector<uint64_t>& array);

  // A series of functions that pop from the start of |data_| into |value|.
  // Corrects for endianness (converts from big-endian to host). Returns the
  // number of bytes read, or 0 if there is not enough data to create such a
  // value.
  uint32_t PopFrontUint8(uint8_t* value);
  uint32_t PopFrontInt8(int8_t* value);
  uint32_t PopFrontUint16(uint16_t* value);
  uint32_t PopFrontUint32(uint32_t* value);
  uint32_t PopFrontUint64(uint64_t* value);

  // A series of functions that pop arrays from the start of |data_|. First
  // the size of |array| is popped as a uint32_t, then |array| is filled with
  // the appropriate number of elements. Corrects for endianness (converts from
  // big-endian to host). Returns the number of bytes read, or 0 if there is
  // not enough data to produce an array.
  // Side effect: |array| is initially cleared such that |array| will only
  // contain the contents popped off from |data_|.
  uint32_t PopFrontArrayUint8(std::vector<uint8_t>* array);
  uint32_t PopFrontArrayInt8(std::vector<int8_t>* array);
  uint32_t PopFrontArrayUint16(std::vector<uint16_t>* array);
  uint32_t PopFrontArrayUint32(std::vector<uint32_t>* array);
  uint32_t PopFrontArrayUint64(std::vector<uint64_t>* array);

  // Convenience function to push a uint32_t to the front of |data_|
  // should there be a size mismatch in popping off an array.
  // The TPM specification defines the way arrays are sent/received in a
  // byte-stream as consisting of a uint32_t size (defining the number of
  // elements that are in the array). This function serves to pop the size
  // back on the buffer should we find that the amount of data remaining on the
  // buffer is less than the size we received.
  uint32_t PushFrontUint32(uint32_t value);

  // Sets the message header (request |tag_|, ordinal |code_|).
  void SetHeader(uint16_t tag, uint32_t code);

  // Gets the message header (response |tag_|, response |code_|).
  void GetHeader(uint16_t* tag, uint32_t* code);

  // Exports the contents of this TpmMessage into |buffer| for writing to the
  // TPM. Returns |size|, the number of bytes that were written to |buffer|.
  // |buffer| must be at least of size kTpmPacketSize.
  void ExportPacketData(uint8_t* packet_buffer, uint32_t* size);

  // Imports data from |buffer| into this TpmMessage, up to |size| bytes.
  void ImportPacketData(const uint8_t* packet_buffer, uint32_t size);

  // Clears |data_| and resets |tag_| and |code_| to zero.
  void Clear();

  // Returns a pointer to a const version of |data_| (for testing purposes).
  const std::vector<uint8_t>* GetDataForTest() { return &data_; }

 private:
  // Internal data buffer.
  std::vector<uint8_t> data_;
  // Request/Response tag.
  uint16_t tag_;
  // Ordinal/Return code.
  uint32_t code_;

  DISALLOW_COPY_AND_ASSIGN(TpmMessage);
};

}  // namespace trunks

#endif  // TRUNKS_TSS_TPM_MESSAGE_H_
