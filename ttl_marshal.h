/* Copyright (c) 2011 The Chromium OS Authors. All rights reserved.
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 *
 * Definitions for TPM command marshalling/unmarshalling.
 */

#ifndef TRUNKS_TPM_MARSHAL_H_
#define TRUNKS_TPM_MARSHAL_H_

#include <stdint.h>
#include <string.h>

#define TPM_MAX_COMMAND_LENGTH 4096

#define POSSIBLY_UNUSED
#define INLINE inline

POSSIBLY_UNUSED
static INLINE void TtlMarshal_uint64_t(uint8_t** cursor, const uint64_t* x) {
  /* Use local variables to remove aliasing concerns */
  uint8_t* buffer = *cursor;
  uint64_t y = *x;
  buffer[0] = (uint8_t)(y >> 56);
  buffer[1] = (uint8_t)((y >> 48) & 0xff);
  buffer[2] = (uint8_t)((y >> 40) & 0xff);
  buffer[3] = (uint8_t)((y >> 32) & 0xff);
  buffer[4] = (uint8_t)((y >> 24) & 0xff);
  buffer[5] = (uint8_t)((y >> 16) & 0xff);
  buffer[6] = (uint8_t)((y >> 8) & 0xff);
  buffer[7] = (uint8_t)(y & 0xff);
  *cursor += 8;
}

POSSIBLY_UNUSED
static INLINE void TtlUnmarshal_uint64_t(uint8_t** cursor, uint64_t* x) {
  uint8_t* buffer = *cursor;
  *x = (((uint64_t) buffer[0]) << 56) |
      (((uint64_t)buffer[1]) << 48) |
      (((uint64_t)buffer[2]) << 40) |
      (((uint64_t)buffer[3]) << 32) |
      (((uint64_t)buffer[4]) << 24) |
      (((uint64_t)buffer[5]) << 16) |
      (((uint64_t)buffer[6]) << 8)  |
      (((uint64_t)buffer[7]) << 0);
  *cursor += 8;
}

POSSIBLY_UNUSED
static INLINE void TtlMarshal_uint32_t(uint8_t** cursor, const uint32_t* x) {
  /* Use local variables to remove aliasing concerns */
  uint8_t* buffer = *cursor;
  uint32_t y = *x;
  buffer[0] = (uint8_t)(y >> 24);
  buffer[1] = (uint8_t)((y >> 16) & 0xff);
  buffer[2] = (uint8_t)((y >> 8) & 0xff);
  buffer[3] = (uint8_t)((y >> 0) & 0xff);
  *cursor += 4;
}

POSSIBLY_UNUSED
static INLINE void TtlUnmarshal_uint32_t(uint8_t** cursor, uint32_t* x) {
  uint8_t* buffer = *cursor;
  *x = ((buffer[0] << 24) |
        (buffer[1] << 16) |
        (buffer[2] << 8) |
        (buffer[3] << 0));
  *cursor += 4;
}

POSSIBLY_UNUSED
static INLINE void TtlMarshal_uint16_t(uint8_t** cursor, const uint16_t* x) {
  /* Use local variables to remove aliasing concerns */
  uint8_t* buffer = *cursor;
  uint16_t y = *x;
  buffer[0] = (uint8_t)(y >> 8);
  buffer[1] = (uint8_t)((y >> 0) & 0xff);
  *cursor += 2;
}

POSSIBLY_UNUSED
static INLINE void TtlUnmarshal_uint16_t(uint8_t** cursor, uint16_t* x) {
  uint8_t* buffer = *cursor;
  *x = ((buffer[0] << 8) |
        (buffer[1] << 0));
  *cursor += 2;
}


POSSIBLY_UNUSED
static INLINE void TtlMarshal_uint8_t(uint8_t** cursor, const uint8_t* x) {
  **cursor = *x;
  *cursor += 1;
}

POSSIBLY_UNUSED
static INLINE void TtlUnmarshal_uint8_t(uint8_t** cursor, uint8_t* x) {
  *x = **cursor;
  *cursor += 1;
}

#define TtlMarshal_BYTE(x, cursor) TtlMarshal_uint8_t(x, cursor)
#define TtlMarshal_TSS_BOOL(x, cursor) TtlMarshal_uint8_t(x, cursor)
#define TtlMarshal_BOOL(x, cursor) TtlMarshal_uint8_t(x, cursor)
#define TtlMarshal_UINT16(x, cursor) TtlMarshal_uint16_t(x, cursor)
#define TtlMarshal_UINT32(x, cursor) TtlMarshal_uint32_t(x, cursor)
#define TtlMarshal_UINT64(x, cursor) TtlMarshal_uint64_t(x, cursor)

POSSIBLY_UNUSED
static INLINE void TtlMarshal_Blob(const uint8_t* from,
                                   uint8_t** cursor, int size) {
  memcpy(*cursor, from, size);
  *cursor += size;
}

POSSIBLY_UNUSED
static INLINE void TtlUnmarshal_Blob(uint8_t** to,
                                     uint8_t** cursor, int size) {
  *to = *cursor;
  *cursor += size;
}

void TtlMarshal_TPM_NONCE(uint8_t** cursor, TPM_NONCE* nonce);
void TtlUnmarshal_TPM_NONCE(uint8_t** cursor, TPM_NONCE* nonce);
void TtlMarshal_TPM_NV_DATA_PUBLIC(uint8_t** cursor, TPM_NV_DATA_PUBLIC* ndp);
void TtlUnmarshal_TPM_NV_DATA_PUBLIC(uint8_t** cursor, TPM_NV_DATA_PUBLIC* ndp);
void TtlMarshal_TPM_RSA_KEY_PARMS(uint8_t** cursor, TPM_RSA_KEY_PARMS* rkp);
void TtlUnmarshal_TPM_RSA_KEY_PARMS(uint8_t** cursor, TPM_RSA_KEY_PARMS* rkp);
int TtlSizeCalc_TPM_RSA_KEY_PARMS(TPM_RSA_KEY_PARMS* rkp);
void TtlMarshal_TPM_PUBKEY(uint8_t** cursor, TPM_PUBKEY* pk);
void TtlUnmarshal_TPM_PUBKEY(uint8_t** cursor, TPM_PUBKEY* pk);

#endif  /* TRUNKS_TPM_MARSHAL_H_ */
