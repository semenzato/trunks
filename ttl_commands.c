/* Copyright (c) 2010-2011 The Chromium OS Authors. All rights reserved.
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 *
 * TPM command library.
 */

#include <stdint.h>
#include <string.h>
#include <openssl/hmac.h>
#include <openssl/rand.h>
#include <openssl/rsa.h>
#include <openssl/sha.h>

#include "g_tpm_commands.h"
#include "g_tpm_structures.h"
#include "trunks.h"
#include "trunks_internal.h"

#define TPM_MAX_RSA_KEY_LENGTH 2048

typedef struct {
  uint32_t algorithmID;
  uint16_t encScheme;
  uint16_t sigScheme;
  RSA* rsa;
} TtlPubKey;

uint8_t null_pcr_selection[] = {0, 0, 0};

/* Exported functions. */

void TtlInit(void) {
  TtlOpenDevice();
}

uint32_t TtlStartup(void) {
  TTLDEBUG(("TPM: Startup\n"));
  TPM_Startup_rqu request;
  request.startupType = TPM_ST_CLEAR;
  return Ttl_TPM_Startup(&request);
}

uint32_t TtlSaveState(void) {
  TTLDEBUG(("TPM: SaveState\n"));
  return Ttl_TPM_SaveState();
}

uint32_t TtlResume(void) {
  TTLDEBUG(("TPM: Resume\n"));
  TPM_Startup_rqu request;
  request.startupType = TPM_ST_STATE;
  return Ttl_TPM_Startup(&request);
}

uint32_t TtlSelfTestFull(void) {
  TTLDEBUG(("TPM: Self test full\n"));
  return Ttl_TPM_SelfTestFull();
}

uint32_t TtlContinueSelfTest(void) {
  return Ttl_TPM_ContinueSelfTest();
}

static void TtlInitializePcrInfoShort(TPM_PCR_INFO_SHORT* pcr_info) {
  pcr_info->pcrSelection.sizeOfSelect = 3;
  pcr_info->pcrSelection.pcrSelect = null_pcr_selection;
  pcr_info->localityAtRelease = TPM_ALL_LOCALITIES;
}

uint32_t TtlDefineSpace(uint32_t index, uint32_t perm, uint32_t size,
                        uint8_t owner_auth[TPM_SHA1_160_HASH_LEN]) {
  TPM_NV_DefineSpace_rqu request;
  TTLDEBUG(("TPM: TpmlibDefineSpace(0x%x, 0x%x, %d)\n", index, perm, size));
  memset(&request, 0, sizeof(request));
  request.pubInfo.nvIndex = index;
  request.pubInfo.permission.attributes = perm;
  request.pubInfo.dataSize = size;
  TtlInitializePcrInfoShort(&request.pubInfo.pcrInfoRead);
  TtlInitializePcrInfoShort(&request.pubInfo.pcrInfoWrite);
  if (owner_auth) {
    APSession auth;
    uint32_t result;
    RETURN_ON_FAILURE(TtlOSAP(&auth, owner_auth, TPM_ET_OWNER, 0));
    result = Ttl_TPM_NV_DefineSpace(&request, &auth);
    TtlFlushSpecific(auth.handle, TPM_RT_AUTH);
    return result;
  } else {
    return Ttl_TPM_NV_DefineSpace(&request, NULL);
  }
}

uint32_t TtlWrite(uint32_t index, uint8_t* data, uint32_t length) {
  TPM_NV_WriteValue_rqu request;
  TTLDEBUG(("TPM: TtlWrite(0x%x, %d)\n", index, length));
  request.nvIndex = index;
  request.offset = 0;
  request.dataSize = length;
  request.data = data;
  return Ttl_TPM_NV_WriteValue(&request, NULL);
}

uint32_t TtlRead(uint32_t index, uint8_t* data, uint32_t length) {
  TPM_NV_ReadValue_rqu request;
  TPM_NV_ReadValue_rsp response;
  uint8_t buffer[TPM_MAX_COMMAND_LENGTH];
  uint32_t result;
  TTLDEBUG(("TPM: TtlRead(0x%x, %d)\n", index, length));
  request.nvIndex = index;
  request.offset = 0;
  request.dataSize = length;
  result = Ttl_TPM_NV_ReadValue(&request, &response, buffer,
                                TPM_MAX_COMMAND_LENGTH, NULL);
  if (result == TPM_SUCCESS) {
    memcpy(data, response.data, length);
  }
  return result;
}

uint32_t TtlWriteLock(uint32_t index) {
  TTLDEBUG(("TPM: Write lock 0x%x\n", index));
  return TtlWrite(index, NULL, 0);
}

uint32_t TtlReadLock(uint32_t index) {
  TTLDEBUG(("TPM: Read lock 0x%x\n", index));
  return TtlRead(index, NULL, 0);
}

uint32_t TtlAssertPhysicalPresence(void) {
  TSC_PhysicalPresence_rqu request;
  TTLDEBUG(("TPM: Asserting physical presence\n"));
  request.physicalPresence = TPM_PHYSICAL_PRESENCE_PRESENT;
  return Ttl_TSC_PhysicalPresence(&request);
}

uint32_t TtlPhysicalPresenceCMDEnable(void) {
  TSC_PhysicalPresence_rqu request;
  TTLDEBUG(("TPM: Enable the physical presence command\n"));
  request.physicalPresence = TPM_PHYSICAL_PRESENCE_CMD_ENABLE;
  return Ttl_TSC_PhysicalPresence(&request);
}

uint32_t TtlFinalizePhysicalPresence(void) {
  TSC_PhysicalPresence_rqu request;
  TTLDEBUG(("TPM: Enable PP cmd, disable HW pp, and set lifetime lock\n"));
  request.physicalPresence =
      TPM_PHYSICAL_PRESENCE_CMD_ENABLE |
      TPM_PHYSICAL_PRESENCE_HW_DISABLE |
      TPM_PHYSICAL_PRESENCE_LIFETIME_LOCK;
  return Ttl_TSC_PhysicalPresence(&request);
}

uint32_t TtlLockPhysicalPresence(void) {
  TSC_PhysicalPresence_rqu request;
  TTLDEBUG(("TPM: Lock physical presence\n"));
  request.physicalPresence = TPM_PHYSICAL_PRESENCE_LOCK;
  return Ttl_TSC_PhysicalPresence(&request);
}

uint32_t TtlSetNvLocked(void) {
  TTLDEBUG(("TPM: Set NV locked\n"));
  return TtlDefineSpace(TPM_NV_INDEX_LOCK, 0, 0, NULL);
}

int TtlIsOwned(void) {
  TPM_ReadPubek_rqu request;
  TPM_ReadPubek_rsp response;
  uint8_t buffer[TPM_MAX_COMMAND_LENGTH];
  uint32_t result;
  TTLDEBUG(("TPM: IsOwned?\n"));
  result = Ttl_TPM_ReadPubek(&request, &response,
                             buffer, TPM_MAX_COMMAND_LENGTH);
  return (result != TPM_SUCCESS);
}

uint32_t TtlForceClear(void) {
  TTLDEBUG(("TPM: Force clear\n"));
  return Ttl_TPM_ForceClear();
}

uint32_t TtlSetEnable(void) {
  TTLDEBUG(("TPM: Enabling TPM\n"));
  return Ttl_TPM_PhysicalEnable();
}

uint32_t TtlClearEnable(void) {
  TTLDEBUG(("TPM: Disabling TPM\n"));
  return Ttl_TPM_PhysicalDisable();
}

uint32_t TtlSetDeactivated(uint8_t flag) {
  TPM_PhysicalSetDeactivated_rqu request;
  TTLDEBUG(("TPM: SetDeactivated(%d)\n", flag));
  request.state = flag;
  return Ttl_TPM_PhysicalSetDeactivated(&request);
}

static uint32_t TtlGetCapUint32(uint32_t cap,
                                uint32_t subcap,
                                TPM_GetCapability_rqu* request,
                                TPM_GetCapability_rsp* response,
                                uint8_t* buffer) {
  uint8_t subcap_array[4];
  uint8_t* subcap_cursor = subcap_array;
  request->capArea = cap;
  request->subCapSize = 4;
  request->subCap = subcap_cursor;
  TtlMarshal_uint32_t(&subcap_cursor, &subcap);
  return Ttl_TPM_GetCapability(request, response, buffer,
                                  TPM_MAX_COMMAND_LENGTH);
}


static uint32_t TtlGetCapFlags(uint32_t subcap,
                               TPM_GetCapability_rqu* request,
                               TPM_GetCapability_rsp* response,
                               uint8_t* buffer) {
  return TtlGetCapUint32(TPM_CAP_FLAG, subcap, request, response, buffer);
}


uint32_t TtlGetPermanentFlags(TPM_PERMANENT_FLAGS* flags) {
  TPM_GetCapability_rqu request;
  TPM_GetCapability_rsp response;
  uint8_t buffer[TPM_MAX_COMMAND_LENGTH];
  uint32_t result;
  TTLDEBUG(("TPM: GetPermanentFlags\n"));
  result = TtlGetCapFlags(TPM_CAP_FLAG_PERMANENT,
                             &request, &response, buffer);
  if (result == TPM_SUCCESS) {
    assert(response.respSize == sizeof(TPM_PERMANENT_FLAGS));
    memcpy(flags, response.resp, sizeof(TPM_PERMANENT_FLAGS));
  }
  return result;
}


uint32_t TtlGetSTClearFlags(TPM_STCLEAR_FLAGS* flags) {
  TPM_GetCapability_rqu request;
  TPM_GetCapability_rsp response;
  uint8_t buffer[TPM_MAX_COMMAND_LENGTH];
  uint32_t result;
  TTLDEBUG(("TPM: GetSTClearFlags\n"));
  result = TtlGetCapFlags(TPM_CAP_FLAG_VOLATILE,
                          &request, &response, buffer);
  if (result == TPM_SUCCESS) {
    /* Ugly assertion, but the struct is padded up by one byte. */
    assert(response.respSize == 7 && sizeof(TPM_STCLEAR_FLAGS) - 1 == 7);
    memcpy(flags, response.resp, sizeof(TPM_STCLEAR_FLAGS));
  }
  return result;
}


uint32_t TtlGetFlags(uint8_t* disable,
                     uint8_t* deactivated,
                     uint8_t *nvlocked) {
  TPM_PERMANENT_FLAGS flags;
  uint32_t result = TtlGetPermanentFlags(&flags);
  if (result == TPM_SUCCESS) {
    if (disable)
      *disable = flags.disable;
    if (deactivated)
      *deactivated = flags.deactivated;
    if (nvlocked)
      *nvlocked = flags.nvLocked;
    TTLDEBUG(("TPM: Got flags disable=%d, deactivated=%d, nvlocked=%d\n",
             flags.disable, flags.deactivated, flags.nvLocked));
  }
  return result;
}

uint32_t TtlSetGlobalLock(void) {
  uint32_t x;
  TTLDEBUG(("TPM: Set global lock\n"));
  return TtlWrite(TPM_NV_INDEX0, (uint8_t*) &x, 0);
}

uint32_t TtlExtend(int pcr_num, const uint8_t* in_digest, uint8_t* out_digest) {
  TPM_Extend_rqu request;
  TPM_Extend_rsp response;
  uint8_t buffer[TPM_MAX_COMMAND_LENGTH];
  uint32_t result;

  request.pcrNum = pcr_num;
  memcpy(request.inDigest.digest, in_digest, TPM_PCR_DIGEST_LENGTH);
  result = Ttl_TPM_Extend(&request, &response, buffer, TPM_MAX_COMMAND_LENGTH);
  if (result != TPM_SUCCESS) {
    return result;
  }
  memcpy(out_digest, response.outDigest.digest, TPM_PCR_DIGEST_LENGTH);
  return result;
}

uint32_t TtlGetPermissions(uint32_t index, uint32_t* permissions) {
  TPM_GetCapability_rqu request;
  TPM_GetCapability_rsp response;
  uint8_t buffer[TPM_MAX_COMMAND_LENGTH];
  uint32_t result;
  TTLDEBUG(("TPM: GetPermissions\n"));
  result = TtlGetCapUint32(TPM_CAP_NV_INDEX, index,
                           &request, &response, buffer);
  if (result == TPM_SUCCESS) {
    TPM_NV_DATA_PUBLIC nv_data;
    uint8_t* cursor = response.resp;
    TtlUnmarshal_TPM_NV_DATA_PUBLIC(&cursor, &nv_data);
    *permissions = nv_data.permission.attributes;
  }
  return result;
}

static void GenerateNonce(TPM_NONCE* nonce) {
  RAND_bytes(nonce->nonce, sizeof(nonce->nonce));
}

uint32_t TtlOIAP(APSession* session, uint8_t* secret) {
  TPM_OIAP_rsp response;
  uint8_t buffer[TPM_MAX_COMMAND_LENGTH];
  uint32_t result;
  TTLDEBUG(("TPM: OIAP\n"));
  result = Ttl_TPM_OIAP(&response, buffer, sizeof(buffer));
  if (result == TPM_SUCCESS) {
    // Initialize session data.
    memset(session, 0, sizeof(APSession));
    GenerateNonce(&session->nonceOdd);
    session->handle = response.authHandle;
    memcpy(&session->nonceEven, &response.nonceEven, sizeof(TPM_NONCE));
    memcpy(&session->secret, secret, sizeof(session->secret));
  }
  return result;
}

uint32_t TtlOSAP(APSession* session, uint8_t* secret,
                 uint16_t entity_type, uint32_t entity_value) {
  TPM_OSAP_rqu request;
  TPM_OSAP_rsp response;
  uint8_t buffer[TPM_MAX_COMMAND_LENGTH];
  uint32_t result;
  TTLDEBUG(("TPM: OSAP\n"));
  request.entityType = entity_type;
  request.entityValue = entity_value;
  GenerateNonce(&request.nonceOddOSAP);
  result = Ttl_TPM_OSAP(&request, &response, buffer, sizeof(buffer));
  if (result == TPM_SUCCESS) {
    // Initialize session data.
    memset(session, 0, sizeof(APSession));
    GenerateNonce(&session->nonceOdd);
    memcpy(&session->nonceOddOSAP, &request.nonceOddOSAP, sizeof(TPM_NONCE));
    session->handle = response.authHandle;
    memcpy(&session->nonceEven, &response.nonceEven, sizeof(TPM_NONCE));
    memcpy(&session->nonceEvenOSAP, &response.nonceEvenOSAP, sizeof(TPM_NONCE));
    // Compute session secret.
    HMAC_CTX hmac_ctx;
    HMAC_CTX_init(&hmac_ctx);
    HMAC_Init(&hmac_ctx, secret, TPM_SHA1_160_HASH_LEN, EVP_sha1());
    HMAC_Update(&hmac_ctx, session->nonceEvenOSAP.nonce,
                sizeof(session->nonceEvenOSAP.nonce));
    HMAC_Update(&hmac_ctx, session->nonceOddOSAP.nonce,
                sizeof(session->nonceOddOSAP.nonce));
    HMAC_Final(&hmac_ctx, session->secret, NULL);
    HMAC_CTX_cleanup(&hmac_ctx);
  }
  return result;
}

uint32_t TtlFlushSpecific(uint32_t handle, uint32_t resource_type) {
  TPM_FlushSpecific_rqu request;
  TTLDEBUG(("TPM: FlushSpecific\n"));
  request.handle = handle;
  request.resourceType = resource_type;
  return Ttl_TPM_FlushSpecific(&request);
}

static uint32_t ConvertPubKey(const TPM_PUBKEY* inkey, TtlPubKey* outkey) {
  uint8_t* cursor;
  TPM_RSA_KEY_PARMS rsa_parms;
  uint8_t pkcs1_buffer[TPM_MAX_COMMAND_LENGTH];
  uint32_t pkcs1_length;
  // For now, we only support RSA keys.
  if (inkey->algorithmParms.algorithmID != TPM_ALG_RSA) {
    return TPM_BAD_KEY_PROPERTY;
  }
  cursor = inkey->algorithmParms.parms;
  TtlUnmarshal_TPM_RSA_KEY_PARMS(&cursor, &rsa_parms);
  if (TtlSizeCalc_TPM_RSA_KEY_PARMS(&rsa_parms) !=
      inkey->algorithmParms.parmSize) {
    return TPM_BAD_PARAMETER;
  }
  if (rsa_parms.exponentSize == 0) {
    rsa_parms.exponentSize = 3;
    rsa_parms.exponent = (uint8_t*)"\x01\x00\x01";
  }
  outkey->algorithmID = inkey->algorithmParms.algorithmID;
  outkey->encScheme = inkey->algorithmParms.encScheme;
  outkey->sigScheme = inkey->algorithmParms.sigScheme;
  // Create a PKCS #1 RSAPublicKey structure and convert it
  // into a OpenSSL RSA key using d2i_RSAPublicKey().
  pkcs1_length = 12 + inkey->pubKey.keyLength + rsa_parms.exponentSize;
  if (sizeof(pkcs1_buffer) < (6 + pkcs1_length)) {
    return TPM_BAD_PARAMETER;
  }
  cursor = pkcs1_buffer;
  *cursor++ = 0x30;
  *cursor++ = 0x84;
  TtlMarshal_uint32_t(&cursor, &pkcs1_length);
  *cursor++ = 0x02;
  *cursor++ = 0x84;
  TtlMarshal_uint32_t(&cursor, &inkey->pubKey.keyLength);
  TtlMarshal_Blob(inkey->pubKey.key, &cursor, inkey->pubKey.keyLength);
  *cursor++ = 0x02;
  *cursor++ = 0x84;
  TtlMarshal_uint32_t(&cursor, &rsa_parms.exponentSize);
  TtlMarshal_Blob(rsa_parms.exponent, &cursor, rsa_parms.exponentSize);
  cursor = pkcs1_buffer;
  outkey->rsa = d2i_RSAPublicKey(NULL, (const uint8_t**)&cursor,
                                 6 + pkcs1_length);
  return (outkey->rsa != NULL) ? TPM_SUCCESS : TPM_BAD_PARAMETER;
}

uint32_t TtlReadPubek(TtlPubKey* pubek) {
  TPM_ReadPubek_rqu request;
  TPM_ReadPubek_rsp response;
  uint8_t buffer[TPM_MAX_COMMAND_LENGTH];
  uint8_t digest[TPM_MAX_COMMAND_LENGTH];
  uint32_t result;
  TTLDEBUG(("TPM: ReadPubek\n"));
  GenerateNonce(&request.antiReplay);
  result = Ttl_TPM_ReadPubek(&request, &response, buffer, sizeof(buffer));
  if (result == TPM_SUCCESS) {
    uint8_t* cursor = digest;
    TtlMarshal_TPM_PUBKEY(&cursor, &response.pubEndorsementKey);
    TtlMarshal_Blob(request.antiReplay.nonce, &cursor,
                    sizeof(request.antiReplay.nonce));
    SHA1(digest, cursor - digest, digest);
    if (memcmp(digest, response.checksum.digest, sizeof(TPM_DIGEST))) {
      result = TPM_FAIL;
    } else {
      result = ConvertPubKey(&response.pubEndorsementKey, pubek);
    }
  }
  return result;
}

uint32_t TtlTakeOwnership(uint8_t owner_auth[TPM_SHA1_160_HASH_LEN],
                             uint8_t srk_auth[TPM_SHA1_160_HASH_LEN]) {
  TPM_TakeOwnership_rqu request;
  TPM_TakeOwnership_rsp response;
  uint8_t buffer[TPM_MAX_COMMAND_LENGTH];
  uint32_t result;
  APSession auth;
  TtlPubKey pubek;
  uint8_t padded[TPM_MAX_RSA_KEY_LENGTH / 8];
  uint8_t enc_owner_auth[TPM_MAX_RSA_KEY_LENGTH / 8];
  uint8_t enc_srk_auth[TPM_MAX_RSA_KEY_LENGTH / 8];
  uint32_t rsa_enc_length;
  TPM_RSA_KEY_PARMS rsa_parms;
  uint8_t rsa_parms_buffer[12];
  uint8_t *cursor;
  TTLDEBUG(("TPM: TakeOwnership\n"));
  // Read public part of TPM EK and use it to encrypt the owner and srk secret.
  result = TtlReadPubek(&pubek);
  if (result != TPM_SUCCESS) return result;
  rsa_enc_length = RSA_size(pubek.rsa);
  if (rsa_enc_length > (TPM_MAX_RSA_KEY_LENGTH / 8)) {
    return TPM_ENCRYPT_ERROR;
  }
  memset(enc_owner_auth, 0, sizeof(enc_owner_auth));
  if (RSA_padding_add_PKCS1_OAEP(padded, rsa_enc_length,
                                 owner_auth, TPM_SHA1_160_HASH_LEN,
                                 (uint8_t*)"TCPA", 4) != 1 ||
      RSA_public_encrypt(rsa_enc_length, padded, enc_owner_auth,
                         pubek.rsa, RSA_NO_PADDING) < 0) {
    RSA_free(pubek.rsa);
    return TPM_ENCRYPT_ERROR;
  }
  memset(enc_srk_auth, 0, sizeof(enc_srk_auth));
  if (RSA_padding_add_PKCS1_OAEP(padded, rsa_enc_length,
                                 srk_auth, TPM_SHA1_160_HASH_LEN,
                                 (uint8_t*)"TCPA", 4) != 1 ||
      RSA_public_encrypt(rsa_enc_length, padded, enc_srk_auth,
                         pubek.rsa, RSA_NO_PADDING) < 0) {
     RSA_free(pubek.rsa);
    return TPM_ENCRYPT_ERROR;
  }
  RSA_free(pubek.rsa);
  result = TtlOIAP(&auth, owner_auth);
  if (result != TPM_SUCCESS) return result;
  request.protocolID = TPM_PID_OWNER;
  request.encOwnerAuthSize = rsa_enc_length;
  request.encOwnerAuth = enc_owner_auth;
  request.encSrkAuthSize = rsa_enc_length;
  request.encSrkAuth = enc_srk_auth;
  request.srkParams.tag = TPM_TAG_KEY12;
  request.srkParams.fill = 0;
  request.srkParams.keyUsage = TPM_KEY_STORAGE;
  request.srkParams.keyFlags = 0;
  request.srkParams.authDataUsage = TPM_AUTH_ALWAYS;
  request.srkParams.algorithmParms.algorithmID = TPM_ALG_RSA;
  request.srkParams.algorithmParms.encScheme = TPM_ES_RSAESOAEP_SHA1_MGF1;
  request.srkParams.algorithmParms.sigScheme = TPM_SS_NONE;
  request.srkParams.algorithmParms.parmSize = 12;
  rsa_parms.keyLength = 2048;
  rsa_parms.numPrimes = 2;
  rsa_parms.exponentSize = 0;
  cursor = rsa_parms_buffer;
  TtlMarshal_TPM_RSA_KEY_PARMS(&cursor, &rsa_parms);
  request.srkParams.algorithmParms.parms = rsa_parms_buffer;
  request.srkParams.PCRInfoSize = 0;
  request.srkParams.pubKey.keyLength = 0;
  request.srkParams.encSize = 0;
  result = Ttl_TPM_TakeOwnership(&request, &response,
                                 buffer, sizeof(buffer), &auth);
  TtlFlushSpecific(auth.handle, TPM_RT_AUTH);
  return result;
}

uint32_t TtlOwnerClear(uint8_t owner_auth[TPM_SHA1_160_HASH_LEN]) {
  uint32_t result;
  APSession auth;
  TTLDEBUG(("TPM: OwnerClear\n"));
  result = TtlOIAP(&auth, owner_auth);
  if (result != TPM_SUCCESS) return result;
  result = Ttl_TPM_OwnerClear(&auth);
  TtlFlushSpecific(auth.handle, TPM_RT_AUTH);
  return result;
}

uint32_t TtlChangeAuthOwner(uint32_t entity_type,
                            uint8_t old_auth[TPM_SHA1_160_HASH_LEN],
                            uint8_t new_auth[TPM_SHA1_160_HASH_LEN]) {
  TPM_ChangeAuthOwner_rqu request;
  uint32_t result;
  APSession auth;
  int i;
  TTLDEBUG(("TPM: ChangeAuthOwner\n"));
  result = TtlOSAP(&auth, old_auth, entity_type, 0);
  if (result != TPM_SUCCESS) return result;
  // Encrypt new owner secret.
  SHA_CTX sha_ctx;
  SHA1_Init(&sha_ctx);
  SHA1_Update(&sha_ctx, auth.secret, sizeof(auth.secret));
  SHA1_Update(&sha_ctx, auth.nonceEven.nonce, sizeof(auth.nonceEven.nonce));
  SHA1_Final(request.newAuth.authdata, &sha_ctx);
  for (i = 0; i < sizeof(request.newAuth.authdata); ++i) {
    request.newAuth.authdata[i] ^= new_auth[i];
  }
  request.protocolID = TPM_PID_ADCP;
  request.entityType = entity_type;
  result = Ttl_TPM_ChangeAuthOwner(&request, &auth);
  TtlFlushSpecific(auth.handle, TPM_RT_AUTH);
  return result;
}

uint32_t TtlGetTestResult(uint32_t *length, uint8_t *test_result)
{
  TPM_GetTestResult_rsp response;
  uint8_t buffer[TPM_MAX_COMMAND_LENGTH];
  uint32_t result = Ttl_TPM_GetTestResult(&response, buffer, sizeof(buffer));
  if (result != 0) {
    return result;
  }
  *length = response.outDataSize;
  memcpy(test_result, response.outData, response.outDataSize);
  return result;
}
