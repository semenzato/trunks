// Copyright (c) 2013 The Chromium OS Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include <gtest/gtest.h>

#include "tpm_message.h"
#include "tpm_constants.h"

namespace trunks {

// Tests individual value push and pop functions.
TEST(TpmMessageTest, PushPopValue) {
  TpmMessage message;
  const std::vector<uint8_t>* data = message.GetDataForTest();

  ASSERT_EQ(1, message.PushBackUint8(0x80));
  ASSERT_EQ(data->size() , 1);
  ASSERT_EQ(data->at(0), 0x80);

  uint8_t u8;
  ASSERT_EQ(1, message.PopFrontUint8(&u8));
  ASSERT_EQ(data->size(), 0);
  ASSERT_EQ(u8, 0x80);

  ASSERT_EQ(1, message.PushBackInt8(-1));
  ASSERT_EQ(data->size(), 1);
  ASSERT_EQ(data->at(0), 0xFF);

  int8_t i8;
  ASSERT_EQ(1, message.PopFrontInt8(&i8));
  ASSERT_EQ(data->size(), 0);
  ASSERT_EQ(i8, -1);

  ASSERT_EQ(2, message.PushBackUint16(0x1234));
  ASSERT_EQ(data->size(), 2);
  ASSERT_EQ(data->at(0), 0x12);
  ASSERT_EQ(data->at(1), 0x34);

  uint16_t u16;
  ASSERT_EQ(2, message.PopFrontUint16(&u16));
  ASSERT_EQ(data->size(), 0);
  ASSERT_EQ(u16, 0x1234);

  ASSERT_EQ(4, message.PushBackUint32(0x12345678));
  ASSERT_EQ(data->size(), 4);
  ASSERT_EQ(data->at(0), 0x12);
  ASSERT_EQ(data->at(1), 0x34);
  ASSERT_EQ(data->at(2), 0x56);
  ASSERT_EQ(data->at(3), 0x78);

  uint32_t u32;
  ASSERT_EQ(4, message.PopFrontUint32(&u32));
  ASSERT_EQ(data->size(), 0);
  ASSERT_EQ(u32, 0x12345678);

  ASSERT_EQ(8, message.PushBackUint64(0x1234567890ABCDEF));
  ASSERT_EQ(data->size(), 8);
  ASSERT_EQ(data->at(0), 0x12);
  ASSERT_EQ(data->at(1), 0x34);
  ASSERT_EQ(data->at(2), 0x56);
  ASSERT_EQ(data->at(3), 0x78);
  ASSERT_EQ(data->at(4), 0x90);
  ASSERT_EQ(data->at(5), 0xAB);
  ASSERT_EQ(data->at(6), 0xCD);
  ASSERT_EQ(data->at(7), 0xEF);

  uint64_t u64;
  ASSERT_EQ(8, message.PopFrontUint64(&u64));
  ASSERT_EQ(data->size(), 0);
  ASSERT_EQ(u64, 0x1234567890ABCDEF);

  // Tests that trying to read more results in an error.
  ASSERT_EQ(0, message.PopFrontUint8(&u8));
  ASSERT_EQ(0, message.PopFrontInt8(&i8));
  ASSERT_EQ(0, message.PopFrontUint16(&u16));
  ASSERT_EQ(0, message.PopFrontUint32(&u32));
  ASSERT_EQ(0, message.PopFrontUint64(&u64));
}

// Tests array push and pop functions.
TEST(TpmMessageTest, PushPopArray) {
  TpmMessage message;
  const std::vector<uint8_t>* data = message.GetDataForTest();

  std::vector<uint8_t> au8;
  au8.push_back(0x80);
  au8.push_back(0x80);

  ASSERT_EQ(6, message.PushBackArrayUint8(au8));
  ASSERT_EQ(6, data->size());
  ASSERT_EQ(0, data->at(0));
  ASSERT_EQ(0, data->at(1));
  ASSERT_EQ(0, data->at(2));
  ASSERT_EQ(0x02, data->at(3));
  ASSERT_EQ(0x80, data->at(4));
  ASSERT_EQ(0x80, data->at(5));

  au8.clear();
  ASSERT_EQ(0, au8.size());
  ASSERT_EQ(6, message.PopFrontArrayUint8(&au8));
  ASSERT_EQ(2, au8.size());
  ASSERT_EQ(0x80, au8.at(0));
  ASSERT_EQ(0x80, au8.at(1));

  std::vector<int8_t> ai8;
  ai8.push_back(-1);
  ai8.push_back(-1);

  ASSERT_EQ(6, message.PushBackArrayInt8(ai8));
  ASSERT_EQ(6, data->size());
  ASSERT_EQ(0, data->at(0));
  ASSERT_EQ(0, data->at(1));
  ASSERT_EQ(0, data->at(2));
  ASSERT_EQ(0x02, data->at(3));
  ASSERT_EQ(0xFF, data->at(4));
  ASSERT_EQ(0xFF, data->at(5));

  ai8.clear();
  ASSERT_EQ(0, ai8.size());
  ASSERT_EQ(6, message.PopFrontArrayInt8(&ai8));
  ASSERT_EQ(2, ai8.size());
  ASSERT_EQ(-1, ai8.at(0));
  ASSERT_EQ(-1, ai8.at(1));

  std::vector<uint16_t> au16;
  au16.push_back(0x1234);
  au16.push_back(0x1234);

  ASSERT_EQ(8, message.PushBackArrayUint16(au16));
  ASSERT_EQ(8, data->size());
  ASSERT_EQ(0, data->at(0));
  ASSERT_EQ(0, data->at(1));
  ASSERT_EQ(0, data->at(2));
  ASSERT_EQ(0x02, data->at(3));
  ASSERT_EQ(0x12, data->at(4));
  ASSERT_EQ(0x34, data->at(5));
  ASSERT_EQ(0x12, data->at(6));
  ASSERT_EQ(0x34, data->at(7));

  au16.clear();
  ASSERT_EQ(0, au16.size());
  ASSERT_EQ(8, message.PopFrontArrayUint16(&au16));
  ASSERT_EQ(2, au16.size());
  ASSERT_EQ(0x1234, au16.at(0));
  ASSERT_EQ(0x1234, au16.at(1));

  std::vector<uint32_t> au32;
  au32.push_back(0x12345678);
  au32.push_back(0x12345678);

  ASSERT_EQ(12, message.PushBackArrayUint32(au32));
  ASSERT_EQ(12, data->size());
  ASSERT_EQ(0, data->at(0));
  ASSERT_EQ(0, data->at(1));
  ASSERT_EQ(0, data->at(2));
  ASSERT_EQ(0x02, data->at(3));
  ASSERT_EQ(0x12, data->at(4));
  ASSERT_EQ(0x34, data->at(5));
  ASSERT_EQ(0x56, data->at(6));
  ASSERT_EQ(0x78, data->at(7));
  ASSERT_EQ(0x12, data->at(8));
  ASSERT_EQ(0x34, data->at(9));
  ASSERT_EQ(0x56, data->at(10));
  ASSERT_EQ(0x78, data->at(11));

  au32.clear();
  ASSERT_EQ(0, au32.size());
  ASSERT_EQ(12, message.PopFrontArrayUint32(&au32));
  ASSERT_EQ(2, au32.size());
  ASSERT_EQ(0x12345678, au32.at(0));
  ASSERT_EQ(0x12345678, au32.at(1));

  std::vector<uint64_t> au64;
  au64.push_back(0x1234567890ABCDEF);
  au64.push_back(0x1234567890ABCDEF);

  ASSERT_EQ(20, message.PushBackArrayUint64(au64));
  ASSERT_EQ(20, data->size());
  ASSERT_EQ(0, data->at(0));
  ASSERT_EQ(0, data->at(1));
  ASSERT_EQ(0, data->at(2));
  ASSERT_EQ(0x02, data->at(3));
  ASSERT_EQ(0x12, data->at(4));
  ASSERT_EQ(0x34, data->at(5));
  ASSERT_EQ(0x56, data->at(6));
  ASSERT_EQ(0x78, data->at(7));
  ASSERT_EQ(0x90, data->at(8));
  ASSERT_EQ(0xAB, data->at(9));
  ASSERT_EQ(0xCD, data->at(10));
  ASSERT_EQ(0xEF, data->at(11));
  ASSERT_EQ(0x12, data->at(12));
  ASSERT_EQ(0x34, data->at(13));
  ASSERT_EQ(0x56, data->at(14));
  ASSERT_EQ(0x78, data->at(15));
  ASSERT_EQ(0x90, data->at(16));
  ASSERT_EQ(0xAB, data->at(17));
  ASSERT_EQ(0xCD, data->at(18));
  ASSERT_EQ(0xEF, data->at(19));

  au64.clear();
  ASSERT_EQ(0, au64.size());
  ASSERT_EQ(20, message.PopFrontArrayUint64(&au64));
  ASSERT_EQ(2, au64.size());
  ASSERT_EQ(0x1234567890ABCDEF, au64.at(0));
  ASSERT_EQ(0x1234567890ABCDEF, au64.at(1));

  // Tests that trying to read more results in an error.
  ASSERT_EQ(0, message.PopFrontArrayUint8(&au8));
  ASSERT_EQ(0, message.PopFrontArrayInt8(&ai8));
  ASSERT_EQ(0, message.PopFrontArrayUint16(&au16));
  ASSERT_EQ(0, message.PopFrontArrayUint32(&au32));
  ASSERT_EQ(0, message.PopFrontArrayUint64(&au64));
}

// Tests packet formatting.
TEST(TpmMessageTest, DataFormatting) {
  TpmMessage message;
  uint8_t buffer[kTpmPacketSize];
  uint8_t buffer_test_data[] = { 0x12, 0x34,
                                 0x00, 0x00, 0x00, 0x0C,
                                 0x56, 0x78, 0x90, 0xAB,
                                 0x80, 0x80 };
  memcpy(buffer, buffer_test_data, 12);

  message.ImportPacketData(buffer, 12);

  uint16_t tag;
  uint32_t code;
  uint16_t value;
  message.GetHeader(&tag, &code);
  ASSERT_EQ(0x1234, tag);
  ASSERT_EQ(0x567890AB, code);
  ASSERT_EQ(2, message.PopFrontUint16(&value));
  ASSERT_EQ(0x8080, value);
  ASSERT_EQ(0, message.GetDataForTest()->size());

  memset(buffer, 0, 12);
  message.Clear();
  message.GetHeader(&tag, &code);
  ASSERT_EQ(0, tag);
  ASSERT_EQ(0, code);
  ASSERT_EQ(0, message.GetDataForTest()->size());

  message.SetHeader(0x90AB, 0x12345678);
  message.PushBackUint16(0xEFEF);

  uint32_t size;
  message.ExportPacketData(buffer, &size);

  ASSERT_EQ(12, size);
  ASSERT_EQ(0x90, buffer[0]);
  ASSERT_EQ(0xAB, buffer[1]);
  ASSERT_EQ(0x00, buffer[2]);
  ASSERT_EQ(0x00, buffer[3]);
  ASSERT_EQ(0x00, buffer[4]);
  ASSERT_EQ(0x0C, buffer[5]);
  ASSERT_EQ(0x12, buffer[6]);
  ASSERT_EQ(0x34, buffer[7]);
  ASSERT_EQ(0x56, buffer[8]);
  ASSERT_EQ(0x78, buffer[9]);
  ASSERT_EQ(0xEF, buffer[10]);
  ASSERT_EQ(0xEF, buffer[11]);
}

}  // namespace trunks
