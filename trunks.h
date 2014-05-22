/* Copyright (c) 2011 The Chromium OS Authors. All rights reserved.
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 *
 * The Trunks TPM Library.
 */

#ifndef TRUNKS_TRUNKS_H
#define TRUNKS_TRUNKS_H

#include "g_tpm_structures.h"
#include "ttl_error_messages.h"

void TtlInit(void);

uint32_t TtlStartup(void);
uint32_t TtlSaveState(void);
uint32_t TtlResume(void);
uint32_t TtlSelfTestFull(void);
uint32_t TtlContinueSelfTest(void);
uint32_t TtlDefineSpace(uint32_t index, uint32_t perm, uint32_t size,
                        uint8_t owner_auth[TPM_SHA1_160_HASH_LEN]);
uint32_t TtlWrite(uint32_t index, uint8_t* data, uint32_t length);
uint32_t TtlRead(uint32_t index, uint8_t* data, uint32_t length);
uint32_t TtlWriteLock(uint32_t index);
uint32_t TtlReadLock(uint32_t index);
uint32_t TtlAssertPhysicalPresence(void);
uint32_t TtlPhysicalPresenceCMDEnable(void);
uint32_t TtlFinalizePhysicalPresence(void);
uint32_t TtlAssertPhysicalPresenceResult(void);
uint32_t TtlLockPhysicalPresence(void);
uint32_t TtlSetNvLocked(void);
int TtlIsOwned(void);
uint32_t TtlForceClear(void);
uint32_t TtlSetEnable(void);
uint32_t TtlClearEnable(void);
uint32_t TtlSetDeactivated(uint8_t flag);
uint32_t TtlGetPermanentFlags(TPM_PERMANENT_FLAGS* flags);
uint32_t TtlGetSTClearFlags(TPM_STCLEAR_FLAGS* flags);
uint32_t TtlGetFlags(uint8_t* disable,
                        uint8_t* deactivated,
                        uint8_t *nvlocked);
uint32_t TtlSetGlobalLock(void);
uint32_t TtlExtend(int pcr_num, const uint8_t* in_digest,
                      uint8_t* out_digest);
uint32_t TtlGetPermissions(uint32_t index, uint32_t* permissions);

uint32_t TtlTakeOwnership(uint8_t owner_auth[TPM_SHA1_160_HASH_LEN],
                             uint8_t srk_auth[TPM_SHA1_160_HASH_LEN]);
uint32_t TtlOwnerClear(uint8_t owner_auth[TPM_SHA1_160_HASH_LEN]);
uint32_t TtlChangeAuthOwner(uint32_t entity_type,
                               uint8_t old_auth[TPM_SHA1_160_HASH_LEN],
                               uint8_t new_auth[TPM_SHA1_160_HASH_LEN]);
uint32_t TtlFlushSpecific(uint32_t handle, uint32_t resource_type);
uint32_t TtlOSAP(APSession* session, uint8_t* secret,
                 uint16_t entity_type, uint32_t entity_value);
uint32_t TtlOIAP(APSession* session, uint8_t* secret);
uint32_t TtlGetTestResult(uint32_t* length, uint8_t* test_result);

#endif  /* TRUNKS_TRUNKS_H */
