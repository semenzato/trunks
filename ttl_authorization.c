/* Copyright (c) 2011 The Chromium OS Authors. All rights reserved.
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include <openssl/hmac.h>
#include <openssl/sha.h>
#include <string.h>

#include "trunks_internal.h"

static uint32_t ComputeReqParamHashOffset(uint32_t ordinal) {
  switch (ordinal) {
    case TPM_ORD_ActivateIdentity:
    case TPM_ORD_ChangeAuth:
    case TPM_ORD_ChangeAuthAsymStart:
    case TPM_ORD_CMK_ConvertMigration:
    case TPM_ORD_CMK_CreateBlob:
    case TPM_ORD_CMK_CreateKey:
    case TPM_ORD_ConvertMigrationBlob:
    case TPM_ORD_CreateMigrationBlob:
    case TPM_ORD_CreateWrapKey:
    case TPM_ORD_Delegate_CreateKeyDelegation:
    case TPM_ORD_DSAP:
    case TPM_ORD_EstablishTransport:
    case TPM_ORD_EvictKey:
    case TPM_ORD_FlushSpecific:
    case TPM_ORD_GetAuditDigestSigned:
    case TPM_ORD_GetPubKey:
    case TPM_ORD_KeyControlOwner:
    case TPM_ORD_LoadKey:
    case TPM_ORD_LoadKey2:
    case TPM_ORD_MigrateKey:
    case TPM_ORD_Quote:
    case TPM_ORD_Quote2:
    case TPM_ORD_ReleaseTransportSigned:
    case TPM_ORD_SaveKeyContext:
    case TPM_ORD_Seal:
    case TPM_ORD_Sealx:
    case TPM_ORD_SetRedirection:
    case TPM_ORD_Sign:
    case TPM_ORD_TickStampBlob:
    case TPM_ORD_UnBind:
    case TPM_ORD_Unseal:
    case TPM_ORD_DAA_Join:
    case TPM_ORD_DAA_Sign:
      return 4;

    case TPM_ORD_CertifyKey:
    case TPM_ORD_CertifyKey2:
    case TPM_ORD_ChangeAuthAsymFinish:
      return 8;

    case TPM_ORD_OSAP:
      return 26;

    default:
      return 0;
  }
}

static uint32_t ComputeRspParamHashOffset(uint32_t ordinal) {
  switch (ordinal) {
    case TPM_ORD_EstablishTransport:
    case TPM_ORD_LoadKey2:
      return 4;

    case TPM_ORD_OIAP:
      return 24;

    case TPM_ORD_OSAP:
      return 44;

    default:
      return 0;
  }
}

static void ComputeReqParamsHash(const uint8_t* cmd, uint32_t cmd_length,
                                 uint32_t ordinal, uint8_t* params_hash) {
  /* Compute the SHA1 hash over all request parameters but skip
     the command header and all leading handles. */
  uint32_t params_offset = TPM_RQU_HEADER_SIZE +
      ComputeReqParamHashOffset(ordinal);
  SHA_CTX sha_ctx;
  SHA1_Init(&sha_ctx);
  SHA1_Update(&sha_ctx, &cmd[TPM_RQU_ORDINAL_OFFSET], 4);
  if (cmd_length > params_offset) {
    SHA1_Update(&sha_ctx, &cmd[params_offset], cmd_length - params_offset);
  }
  SHA1_Final(params_hash, &sha_ctx);
}

static void ComputeRspParamsHash(const uint8_t* cmd, uint32_t cmd_length,
                                 uint32_t ordinal, uint8_t* params_hash) {
  /* Compute the SHA1 hash over all response parameters but skip
     the command header and all leading handles. */
  uint8_t ordinal_buf[4];
  uint8_t* ptr = ordinal_buf;
  TtlMarshal_uint32_t(&ptr, &ordinal);
  uint32_t params_offset = TPM_RSP_HEADER_SIZE +
      ComputeRspParamHashOffset(ordinal);
  SHA_CTX sha_ctx;
  SHA1_Init(&sha_ctx);
  SHA1_Update(&sha_ctx, &cmd[TPM_RSP_RESULT_OFFSET], 4);
  SHA1_Update(&sha_ctx, ordinal_buf, 4);
  if (cmd_length > params_offset) {
    SHA1_Update(&sha_ctx, &cmd[params_offset], cmd_length - params_offset);
  }
  SHA1_Final(params_hash, &sha_ctx);
}

static void ComputeCmdAuth(const APSession* auth, const uint8_t* params_hash,
                           uint8_t* auth_data) {
  /* Compute authorization value. */
  HMAC_CTX hmac_ctx;
  HMAC_CTX_init(&hmac_ctx);
  HMAC_Init(&hmac_ctx, auth->secret, sizeof(auth->secret), EVP_sha1());
  HMAC_Update(&hmac_ctx, params_hash, TPM_SHA1_160_HASH_LEN);
  HMAC_Update(&hmac_ctx, auth->nonceEven.nonce, sizeof(auth->nonceEven.nonce));
  HMAC_Update(&hmac_ctx, auth->nonceOdd.nonce, sizeof(auth->nonceOdd.nonce));
  HMAC_Update(&hmac_ctx, &auth->continueAuthSession, 1);
  HMAC_Final(&hmac_ctx, auth_data, NULL);
  HMAC_CTX_cleanup(&hmac_ctx);
}

void TtlComputeAndMarshal_TPM_AUTH(
    APSession* auth, uint8_t* cmd, uint32_t cmd_length,
    uint32_t ordinal, uint8_t** cursor) {
  uint8_t params_hash[TPM_SHA1_160_HASH_LEN];
  uint8_t auth_data[TPM_SHA1_160_HASH_LEN];
  ComputeReqParamsHash(cmd, cmd_length, ordinal, params_hash);
  ComputeCmdAuth(auth, params_hash, auth_data);
  /* Marshal authorization trailer. */
  TtlMarshal_uint32_t(cursor, &auth->handle);
  TtlMarshal_TPM_NONCE(cursor, &auth->nonceOdd);
  TtlMarshal_uint8_t(cursor, &auth->continueAuthSession);
  memcpy(*cursor, auth_data, sizeof(auth_data));
  *cursor += sizeof(auth_data);
}

TPM_RESULT TtlUnmarshalAndVerify_TPM_AUTH(
    APSession* auth, uint8_t* cmd, uint32_t cmd_length,
    uint32_t ordinal, uint8_t** cursor) {
  /* Read authorization trailer. */
  TtlUnmarshal_TPM_NONCE(cursor, &auth->nonceEven);
  TtlUnmarshal_uint8_t(cursor, &auth->continueAuthSession);
  uint8_t received_auth_data[TPM_SHA1_160_HASH_LEN];
  memcpy(received_auth_data, *cursor, sizeof(received_auth_data));
  *cursor += sizeof(received_auth_data);
  /* Compute authorization value and compare it to the received one. */
  uint8_t params_hash[TPM_SHA1_160_HASH_LEN];
  uint8_t auth_data[TPM_SHA1_160_HASH_LEN];
  ComputeRspParamsHash(cmd, cmd_length, ordinal, params_hash);
  ComputeCmdAuth(auth, params_hash, auth_data);
  if (memcmp(received_auth_data, auth_data, TPM_SHA1_160_HASH_LEN) != 0) {
    return TPM_AUTHFAIL;
  } else {
    return TPM_SUCCESS;
  }
}
