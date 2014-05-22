/* Copyright (c) 2011 The Chromium OS Authors. All rights reserved.
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 *
 * Marshalling/unmarshalling useful data structures.
 */


#include "trunks_internal.h"
#include "g_tpm_commands.h"


void TtlMarshal_TPM_NONCE(uint8_t** cursor, TPM_NONCE* nonce) {
  uint8_t* code = ByteCodeIndexToAddress(TTL_TPM_NONCE_BYTECODE_OFFSET);
  TtlMarshal(&code, cursor, nonce);
}

void TtlUnmarshal_TPM_NONCE(uint8_t** cursor, TPM_NONCE* nonce) {
  uint8_t* code = ByteCodeIndexToAddress(TTL_TPM_NONCE_BYTECODE_OFFSET);
  TtlUnmarshal(&code, cursor, nonce);
}

/* --- */

void TtlMarshal_TPM_NV_DATA_PUBLIC(uint8_t** cursor, TPM_NV_DATA_PUBLIC* ndp) {
  uint8_t* code =
      ByteCodeIndexToAddress(TTL_TPM_NV_DATA_PUBLIC_BYTECODE_OFFSET);
  TtlMarshal(&code, cursor, ndp);
}

void TtlUnmarshal_TPM_NV_DATA_PUBLIC(uint8_t** cursor,
                                     TPM_NV_DATA_PUBLIC* ndp) {
  uint8_t* code =
      ByteCodeIndexToAddress(TTL_TPM_NV_DATA_PUBLIC_BYTECODE_OFFSET);
  TtlUnmarshal(&code, cursor, ndp);
}

/* --- */

void TtlMarshal_TPM_RSA_KEY_PARMS(uint8_t** cursor, TPM_RSA_KEY_PARMS* rkp) {
  uint8_t* code = ByteCodeIndexToAddress(TTL_TPM_RSA_KEY_PARMS_BYTECODE_OFFSET);
  TtlMarshal(&code, cursor, rkp);
}

void TtlUnmarshal_TPM_RSA_KEY_PARMS(uint8_t** cursor, TPM_RSA_KEY_PARMS* rkp) {
  uint8_t* code = ByteCodeIndexToAddress(TTL_TPM_RSA_KEY_PARMS_BYTECODE_OFFSET);
  TtlUnmarshal(&code, cursor, rkp);
}

int TtlSizeCalc_TPM_RSA_KEY_PARMS(TPM_RSA_KEY_PARMS* rkp) {
  uint8_t* code = ByteCodeIndexToAddress(TTL_TPM_RSA_KEY_PARMS_BYTECODE_OFFSET);
  return TtlSizeCalc(&code, rkp);
}

/* --- */

void TtlMarshal_TPM_PUBKEY(uint8_t** cursor, TPM_PUBKEY* pk) {
  uint8_t* code = ByteCodeIndexToAddress(TTL_TPM_PUBKEY_BYTECODE_OFFSET);
  TtlMarshal(&code, cursor, pk);
}

void TtlUnmarshal_TPM_PUBKEY(uint8_t** cursor, TPM_PUBKEY* pk) {
  uint8_t* code = ByteCodeIndexToAddress(TTL_TPM_PUBKEY_BYTECODE_OFFSET);
  TtlUnmarshal(&code, cursor, pk);
}
