/* Copyright (c) 2011 The Chromium OS Authors. All rights reserved.
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef TRUNKS_G_TPM_COMMANDS_H_
#define TRUNKS_G_TPM_COMMANDS_H_

#include "g_tpm_structures.h"
#include "trunks_internal.h"
#define TTL_TPM_NONCE_BYTECODE_OFFSET 42
#define TTL_TPM_RSA_KEY_PARMS_BYTECODE_OFFSET 575
#define TTL_TPM_PUBKEY_BYTECODE_OFFSET 624
#define TTL_TPM_NV_DATA_PUBLIC_BYTECODE_OFFSET 1399


typedef struct TPM_Startup_rqu {
  TPM_STARTUP_TYPE startupType;
} TPM_Startup_rqu;


/* Sends a TPM_Startup command to the TPM and reads the response. */
uint32_t Ttl_TPM_Startup(TPM_Startup_rqu* in_parameters);

/* Sends a TPM_SaveState command to the TPM and reads the response. */
uint32_t Ttl_TPM_SaveState(void);

/* Sends a TPM_SelfTestFull command to the TPM and reads the response. */
uint32_t Ttl_TPM_SelfTestFull(void);

/* Sends a TPM_ContinueSelfTest command to the TPM and reads the response. */
uint32_t Ttl_TPM_ContinueSelfTest(void);

typedef struct TPM_GetTestResult_rsp {
  uint32_t outDataSize;
  uint8_t* outData;
} TPM_GetTestResult_rsp;


/* Sends a TPM_GetTestResult command to the TPM and reads the response. */
uint32_t Ttl_TPM_GetTestResult(TPM_GetTestResult_rsp* out_parameters, uint8_t* buffer, int buffer_size);

typedef struct TPM_SetOwnerInstall_rqu {
  uint8_t state;
} TPM_SetOwnerInstall_rqu;


/* Sends a TPM_SetOwnerInstall command to the TPM and reads the response. */
uint32_t Ttl_TPM_SetOwnerInstall(TPM_SetOwnerInstall_rqu* in_parameters);

typedef struct TPM_OwnerSetDisable_rqu {
  uint8_t disableState;
} TPM_OwnerSetDisable_rqu;


/* Sends a TPM_OwnerSetDisable command to the TPM and reads the response. */
uint32_t Ttl_TPM_OwnerSetDisable(TPM_OwnerSetDisable_rqu* in_parameters, APSession* auth1);

/* Sends a TPM_PhysicalEnable command to the TPM and reads the response. */
uint32_t Ttl_TPM_PhysicalEnable(void);

/* Sends a TPM_PhysicalDisable command to the TPM and reads the response. */
uint32_t Ttl_TPM_PhysicalDisable(void);

typedef struct TPM_PhysicalSetDeactivated_rqu {
  uint8_t state;
} TPM_PhysicalSetDeactivated_rqu;


/* Sends a TPM_PhysicalSetDeactivated command to the TPM and reads the response. */
uint32_t Ttl_TPM_PhysicalSetDeactivated(TPM_PhysicalSetDeactivated_rqu* in_parameters);

/* Sends a TPM_SetTempDeactivated command to the TPM and reads the response. */
uint32_t Ttl_TPM_SetTempDeactivated(APSession* auth1);

typedef struct TPM_SetOperatorAuth_rqu {
  TPM_SECRET operatorAuth;
  TPM_TAG tag;
} TPM_SetOperatorAuth_rqu;


/* Sends a TPM_SetOperatorAuth command to the TPM and reads the response. */
uint32_t Ttl_TPM_SetOperatorAuth(TPM_SetOperatorAuth_rqu* in_parameters);

typedef struct TPM_TakeOwnership_rqu {
  TPM_PROTOCOL_ID protocolID;
  uint32_t encOwnerAuthSize;
  uint8_t* encOwnerAuth;
  uint32_t encSrkAuthSize;
  uint8_t* encSrkAuth;
  TPM_KEY12 srkParams;
} TPM_TakeOwnership_rqu;


typedef struct TPM_TakeOwnership_rsp {
  TPM_KEY srkPub;
} TPM_TakeOwnership_rsp;


/* Sends a TPM_TakeOwnership command to the TPM and reads the response. */
uint32_t Ttl_TPM_TakeOwnership(TPM_TakeOwnership_rqu* in_parameters, TPM_TakeOwnership_rsp* out_parameters, uint8_t* buffer, int buffer_size, APSession* auth1);

/* Sends a TPM_OwnerClear command to the TPM and reads the response. */
uint32_t Ttl_TPM_OwnerClear(APSession* auth1);

/* Sends a TPM_ForceClear command to the TPM and reads the response. */
uint32_t Ttl_TPM_ForceClear(void);

/* Sends a TPM_DisableOwnerClear command to the TPM and reads the response. */
uint32_t Ttl_TPM_DisableOwnerClear(APSession* auth1);

/* Sends a TPM_DisableForceClear command to the TPM and reads the response. */
uint32_t Ttl_TPM_DisableForceClear(void);

typedef struct TSC_PhysicalPresence_rqu {
  TPM_PHYSICAL_PRESENCE physicalPresence;
} TSC_PhysicalPresence_rqu;


/* Sends a TSC_PhysicalPresence command to the TPM and reads the response. */
uint32_t Ttl_TSC_PhysicalPresence(TSC_PhysicalPresence_rqu* in_parameters);

/* Sends a TSC_ResetEstablishmentBit command to the TPM and reads the response. */
uint32_t Ttl_TSC_ResetEstablishmentBit(void);

typedef struct TPM_GetCapability_rqu {
  TPM_CAPABILITY_AREA capArea;
  uint32_t subCapSize;
  uint8_t* subCap;
} TPM_GetCapability_rqu;


typedef struct TPM_GetCapability_rsp {
  uint32_t respSize;
  uint8_t* resp;
} TPM_GetCapability_rsp;


/* Sends a TPM_GetCapability command to the TPM and reads the response. */
uint32_t Ttl_TPM_GetCapability(TPM_GetCapability_rqu* in_parameters, TPM_GetCapability_rsp* out_parameters, uint8_t* buffer, int buffer_size);

typedef struct TPM_SetCapability_rqu {
  TPM_CAPABILITY_AREA capArea;
  uint32_t subCapSize;
  uint8_t* subCap;
  uint32_t setValueSize;
  uint8_t* setValue;
} TPM_SetCapability_rqu;


/* Sends a TPM_SetCapability command to the TPM and reads the response. */
uint32_t Ttl_TPM_SetCapability(TPM_SetCapability_rqu* in_parameters, APSession* auth1);

typedef struct TPM_GetCapabilityOwner_rsp {
  TPM_VERSION version;
  uint32_t non_volatile_flags;
  uint32_t volatile_flags;
} TPM_GetCapabilityOwner_rsp;


/* Sends a TPM_GetCapabilityOwner command to the TPM and reads the response. */
uint32_t Ttl_TPM_GetCapabilityOwner(TPM_GetCapabilityOwner_rsp* out_parameters, uint8_t* buffer, int buffer_size, APSession* auth1);

typedef struct TPM_GetAuditDigest_rqu {
  uint32_t startOrdinal;
} TPM_GetAuditDigest_rqu;


typedef struct TPM_GetAuditDigest_rsp {
  TPM_COUNTER_VALUE counterValue;
  TPM_DIGEST auditDigest;
  uint8_t more;
  uint32_t ordSize;
  uint8_t* ordList;
} TPM_GetAuditDigest_rsp;


/* Sends a TPM_GetAuditDigest command to the TPM and reads the response. */
uint32_t Ttl_TPM_GetAuditDigest(TPM_GetAuditDigest_rqu* in_parameters, TPM_GetAuditDigest_rsp* out_parameters, uint8_t* buffer, int buffer_size);

typedef struct TPM_GetAuditDigestSigned_rqu {
  TPM_KEY_HANDLE keyHandle;
  uint8_t closeAudit;
  TPM_NONCE antiReplay;
} TPM_GetAuditDigestSigned_rqu;


typedef struct TPM_GetAuditDigestSigned_rsp {
  TPM_COUNTER_VALUE counterValue;
  TPM_DIGEST auditDigest;
  TPM_DIGEST ordinalDigest;
  uint32_t sigSize;
  uint8_t* sig;
} TPM_GetAuditDigestSigned_rsp;


/* Sends a TPM_GetAuditDigestSigned command to the TPM and reads the response. */
uint32_t Ttl_TPM_GetAuditDigestSigned(TPM_GetAuditDigestSigned_rqu* in_parameters, TPM_GetAuditDigestSigned_rsp* out_parameters, uint8_t* buffer, int buffer_size, APSession* auth1);

typedef struct TPM_SetOrdinalAuditStatus_rqu {
  TPM_COMMAND_CODE ordinalToAudit;
  uint8_t auditState;
} TPM_SetOrdinalAuditStatus_rqu;


/* Sends a TPM_SetOrdinalAuditStatus command to the TPM and reads the response. */
uint32_t Ttl_TPM_SetOrdinalAuditStatus(TPM_SetOrdinalAuditStatus_rqu* in_parameters, APSession* auth1);

typedef struct TPM_SetRedirection_rqu {
  TPM_KEY_HANDLE keyHandle;
  TPM_COMMAND_CODE redirCmd;
  uint32_t inputDataSize;
  uint8_t inputData;
} TPM_SetRedirection_rqu;


/* Sends a TPM_SetRedirection command to the TPM and reads the response. */
uint32_t Ttl_TPM_SetRedirection(TPM_SetRedirection_rqu* in_parameters, APSession* auth1);

/* Sends a TPM_ResetLockValue command to the TPM and reads the response. */
uint32_t Ttl_TPM_ResetLockValue(APSession* auth1);

typedef struct TPM_Seal_rqu {
  TPM_KEY_HANDLE keyHandle;
  TPM_ENCAUTH encAuth;
  uint32_t pcrInfoSize;
  TPM_PCR_INFO pcrInfo;
  uint32_t inDataSize;
  uint8_t* inData;
} TPM_Seal_rqu;


typedef struct TPM_Seal_rsp {
  TPM_STORED_DATA sealedData;
} TPM_Seal_rsp;


/* Sends a TPM_Seal command to the TPM and reads the response. */
uint32_t Ttl_TPM_Seal(TPM_Seal_rqu* in_parameters, TPM_Seal_rsp* out_parameters, uint8_t* buffer, int buffer_size, APSession* auth1);

typedef struct TPM_Unseal_rqu {
  TPM_KEY_HANDLE parentHandle;
  TPM_STORED_DATA inData;
} TPM_Unseal_rqu;


typedef struct TPM_Unseal_rsp {
  uint32_t secretSize;
  uint8_t* secret;
} TPM_Unseal_rsp;


/* Sends a TPM_Unseal command to the TPM and reads the response. */
uint32_t Ttl_TPM_Unseal(TPM_Unseal_rqu* in_parameters, TPM_Unseal_rsp* out_parameters, uint8_t* buffer, int buffer_size, APSession* auth1, APSession* auth2);

typedef struct TPM_UnBind_rqu {
  TPM_KEY_HANDLE keyHandle;
  uint32_t inDataSize;
  uint8_t* inData;
} TPM_UnBind_rqu;


typedef struct TPM_UnBind_rsp {
  uint32_t outDataSize;
  uint8_t* outData;
} TPM_UnBind_rsp;


/* Sends a TPM_UnBind command to the TPM and reads the response. */
uint32_t Ttl_TPM_UnBind(TPM_UnBind_rqu* in_parameters, TPM_UnBind_rsp* out_parameters, uint8_t* buffer, int buffer_size, APSession* auth1);

typedef struct TPM_CreateWrapKey_rqu {
  TPM_KEY_HANDLE parentHandle;
  TPM_ENCAUTH dataUsageAuth;
  TPM_ENCAUTH dataMigrationAuth;
  TPM_KEY keyInfo;
} TPM_CreateWrapKey_rqu;


typedef struct TPM_CreateWrapKey_rsp {
  TPM_KEY wrappedKey;
} TPM_CreateWrapKey_rsp;


/* Sends a TPM_CreateWrapKey command to the TPM and reads the response. */
uint32_t Ttl_TPM_CreateWrapKey(TPM_CreateWrapKey_rqu* in_parameters, TPM_CreateWrapKey_rsp* out_parameters, uint8_t* buffer, int buffer_size, APSession* auth1);

typedef struct TPM_LoadKey2_rqu {
  TPM_KEY_HANDLE parentHandle;
  TPM_KEY inKey;
} TPM_LoadKey2_rqu;


typedef struct TPM_LoadKey2_rsp {
  TPM_KEY_HANDLE inkeyHandle;
} TPM_LoadKey2_rsp;


/* Sends a TPM_LoadKey2 command to the TPM and reads the response. */
uint32_t Ttl_TPM_LoadKey2(TPM_LoadKey2_rqu* in_parameters, TPM_LoadKey2_rsp* out_parameters, uint8_t* buffer, int buffer_size, APSession* auth1);

typedef struct TPM_GetPubKey_rqu {
  TPM_KEY_HANDLE keyHandle;
} TPM_GetPubKey_rqu;


typedef struct TPM_GetPubKey_rsp {
  TPM_PUBKEY pubKey;
} TPM_GetPubKey_rsp;


/* Sends a TPM_GetPubKey command to the TPM and reads the response. */
uint32_t Ttl_TPM_GetPubKey(TPM_GetPubKey_rqu* in_parameters, TPM_GetPubKey_rsp* out_parameters, uint8_t* buffer, int buffer_size, APSession* auth1);

typedef struct TPM_Sealx_rqu {
  TPM_KEY_HANDLE keyHandle;
  TPM_ENCAUTH encAuth;
  uint32_t pcrInfoSize;
  TPM_PCR_INFO pcrInfo;
  uint32_t inDataSize;
  uint8_t* inData;
} TPM_Sealx_rqu;


typedef struct TPM_Sealx_rsp {
  TPM_STORED_DATA sealedData;
} TPM_Sealx_rsp;


/* Sends a TPM_Sealx command to the TPM and reads the response. */
uint32_t Ttl_TPM_Sealx(TPM_Sealx_rqu* in_parameters, TPM_Sealx_rsp* out_parameters, uint8_t* buffer, int buffer_size, APSession* auth1);

typedef struct TPM_CreateMigrationBlob_rqu {
  TPM_KEY_HANDLE parentHandle;
  TPM_MIGRATE_SCHEME migrationType;
  TPM_MIGRATIONKEYAUTH migrationKeyAuth;
  uint32_t encDataSize;
  uint8_t* encData;
} TPM_CreateMigrationBlob_rqu;


typedef struct TPM_CreateMigrationBlob_rsp {
  uint32_t randomSize;
  uint8_t* random;
  uint32_t outDataSize;
  uint8_t* outData;
} TPM_CreateMigrationBlob_rsp;


/* Sends a TPM_CreateMigrationBlob command to the TPM and reads the response. */
uint32_t Ttl_TPM_CreateMigrationBlob(TPM_CreateMigrationBlob_rqu* in_parameters, TPM_CreateMigrationBlob_rsp* out_parameters, uint8_t* buffer, int buffer_size, APSession* auth1, APSession* auth2);

typedef struct TPM_ConvertMigrationBlob_rqu {
  TPM_KEY_HANDLE parentHandle;
  uint32_t inDataSize;
  uint8_t* inData;
  uint32_t randomSize;
  uint8_t* random;
} TPM_ConvertMigrationBlob_rqu;


typedef struct TPM_ConvertMigrationBlob_rsp {
  uint32_t outDataSize;
  uint8_t* outData;
} TPM_ConvertMigrationBlob_rsp;


/* Sends a TPM_ConvertMigrationBlob command to the TPM and reads the response. */
uint32_t Ttl_TPM_ConvertMigrationBlob(TPM_ConvertMigrationBlob_rqu* in_parameters, TPM_ConvertMigrationBlob_rsp* out_parameters, uint8_t* buffer, int buffer_size, APSession* auth1);

typedef struct TPM_AuthorizeMigrationKey_rqu {
  TPM_MIGRATE_SCHEME migrationScheme;
  TPM_PUBKEY migrationKey;
} TPM_AuthorizeMigrationKey_rqu;


typedef struct TPM_AuthorizeMigrationKey_rsp {
  TPM_MIGRATIONKEYAUTH outData;
} TPM_AuthorizeMigrationKey_rsp;


/* Sends a TPM_AuthorizeMigrationKey command to the TPM and reads the response. */
uint32_t Ttl_TPM_AuthorizeMigrationKey(TPM_AuthorizeMigrationKey_rqu* in_parameters, TPM_AuthorizeMigrationKey_rsp* out_parameters, uint8_t* buffer, int buffer_size, APSession* auth1);

typedef struct TPM_MigrateKey_rqu {
  TPM_KEY_HANDLE maKeyHandle;
  TPM_PUBKEY pubKey;
  uint32_t inDataSize;
  uint8_t* inData;
} TPM_MigrateKey_rqu;


typedef struct TPM_MigrateKey_rsp {
  uint32_t outDataSize;
  uint8_t* outData;
} TPM_MigrateKey_rsp;


/* Sends a TPM_MigrateKey command to the TPM and reads the response. */
uint32_t Ttl_TPM_MigrateKey(TPM_MigrateKey_rqu* in_parameters, TPM_MigrateKey_rsp* out_parameters, uint8_t* buffer, int buffer_size, APSession* auth1);

typedef struct TPM_CMK_SetRestrictions_rqu {
  TPM_CMK_DELEGATE restriction;
} TPM_CMK_SetRestrictions_rqu;


/* Sends a TPM_CMK_SetRestrictions command to the TPM and reads the response. */
uint32_t Ttl_TPM_CMK_SetRestrictions(TPM_CMK_SetRestrictions_rqu* in_parameters, APSession* auth1);

typedef struct TPM_CMK_ApproveMA_rqu {
  TPM_DIGEST migrationAuthorityDigest;
} TPM_CMK_ApproveMA_rqu;


typedef struct TPM_CMK_ApproveMA_rsp {
  TPM_HMAC outData;
} TPM_CMK_ApproveMA_rsp;


/* Sends a TPM_CMK_ApproveMA command to the TPM and reads the response. */
uint32_t Ttl_TPM_CMK_ApproveMA(TPM_CMK_ApproveMA_rqu* in_parameters, TPM_CMK_ApproveMA_rsp* out_parameters, uint8_t* buffer, int buffer_size, APSession* auth1);

typedef struct TPM_CMK_CreateKey_rqu {
  TPM_KEY_HANDLE parentHandle;
  TPM_ENCAUTH dataUsageAuth;
  TPM_KEY12 keyInfo;
  TPM_HMAC migrationAuthorityApproval;
  TPM_DIGEST migrationAuthorityDigest;
} TPM_CMK_CreateKey_rqu;


typedef struct TPM_CMK_CreateKey_rsp {
  TPM_KEY12 wrappedKey;
} TPM_CMK_CreateKey_rsp;


/* Sends a TPM_CMK_CreateKey command to the TPM and reads the response. */
uint32_t Ttl_TPM_CMK_CreateKey(TPM_CMK_CreateKey_rqu* in_parameters, TPM_CMK_CreateKey_rsp* out_parameters, uint8_t* buffer, int buffer_size, APSession* auth1);

typedef struct TPM_CMK_CreateTicket_rqu {
  TPM_PUBKEY verificationKey;
  TPM_DIGEST signedData;
  uint32_t signatureValueSize;
  uint8_t* signatureValue;
} TPM_CMK_CreateTicket_rqu;


typedef struct TPM_CMK_CreateTicket_rsp {
  TPM_HMAC sigTicket;
} TPM_CMK_CreateTicket_rsp;


/* Sends a TPM_CMK_CreateTicket command to the TPM and reads the response. */
uint32_t Ttl_TPM_CMK_CreateTicket(TPM_CMK_CreateTicket_rqu* in_parameters, TPM_CMK_CreateTicket_rsp* out_parameters, uint8_t* buffer, int buffer_size, APSession* auth1);

typedef struct TPM_CMK_CreateBlob_rqu {
  TPM_KEY_HANDLE parentHandle;
  TPM_MIGRATE_SCHEME migrationType;
  TPM_MIGRATIONKEYAUTH migrationKeyAuth;
  TPM_DIGEST pubSourceKeyDigest;
  uint32_t msaListSize;
  TPM_MSA_COMPOSITE structure;
  TPM_MSA_COMPOSITE msaList;
  uint32_t restrictTicketSize;
  uint8_t* restrictTicket;
  uint32_t sigTicketSize;
  uint8_t* sigTicket;
  uint32_t encDataSize;
  uint8_t* encData;
} TPM_CMK_CreateBlob_rqu;


typedef struct TPM_CMK_CreateBlob_rsp {
  uint32_t randomSize;
  uint8_t* random;
  uint32_t outDataSize;
  uint8_t* outData;
} TPM_CMK_CreateBlob_rsp;


/* Sends a TPM_CMK_CreateBlob command to the TPM and reads the response. */
uint32_t Ttl_TPM_CMK_CreateBlob(TPM_CMK_CreateBlob_rqu* in_parameters, TPM_CMK_CreateBlob_rsp* out_parameters, uint8_t* buffer, int buffer_size, APSession* auth1);

typedef struct TPM_CMK_ConvertMigration_rqu {
  TPM_KEY_HANDLE parentHandle;
  TPM_CMK_AUTH restrictTicket;
  TPM_HMAC sigTicket;
  TPM_KEY12 migratedKey;
  TPM_MIGRATE_ASYMKEY properly;
  uint32_t msaListSize;
  TPM_MSA_COMPOSITE structure;
  TPM_MSA_COMPOSITE msaList;
  uint32_t randomSize;
  uint8_t* random;
} TPM_CMK_ConvertMigration_rqu;


typedef struct TPM_CMK_ConvertMigration_rsp {
  uint32_t outDataSize;
  uint8_t* outData;
} TPM_CMK_ConvertMigration_rsp;


/* Sends a TPM_CMK_ConvertMigration command to the TPM and reads the response. */
uint32_t Ttl_TPM_CMK_ConvertMigration(TPM_CMK_ConvertMigration_rqu* in_parameters, TPM_CMK_ConvertMigration_rsp* out_parameters, uint8_t* buffer, int buffer_size, APSession* auth1);

typedef struct TPM_CreateMaintenanceArchive_rqu {
  uint8_t generateRandom;
} TPM_CreateMaintenanceArchive_rqu;


typedef struct TPM_CreateMaintenanceArchive_rsp {
  uint32_t randomSize;
  uint8_t* random;
  uint32_t archiveSize;
  uint8_t* archive;
} TPM_CreateMaintenanceArchive_rsp;


/* Sends a TPM_CreateMaintenanceArchive command to the TPM and reads the response. */
uint32_t Ttl_TPM_CreateMaintenanceArchive(TPM_CreateMaintenanceArchive_rqu* in_parameters, TPM_CreateMaintenanceArchive_rsp* out_parameters, uint8_t* buffer, int buffer_size, APSession* auth1);

typedef struct TPM_LoadMaintenanceArchive_rqu {
  uint32_t archiveSize;
  uint8_t* archive;
} TPM_LoadMaintenanceArchive_rqu;


/* Sends a TPM_LoadMaintenanceArchive command to the TPM and reads the response. */
uint32_t Ttl_TPM_LoadMaintenanceArchive(TPM_LoadMaintenanceArchive_rqu* in_parameters, APSession* auth1);

/* Sends a TPM_KillMaintenanceFeature command to the TPM and reads the response. */
uint32_t Ttl_TPM_KillMaintenanceFeature(APSession* auth1);

typedef struct TPM_LoadManuMaintPub_rqu {
  TPM_NONCE antiReplay;
  TPM_PUBKEY pubKey;
} TPM_LoadManuMaintPub_rqu;


typedef struct TPM_LoadManuMaintPub_rsp {
  TPM_DIGEST checksum;
} TPM_LoadManuMaintPub_rsp;


/* Sends a TPM_LoadManuMaintPub command to the TPM and reads the response. */
uint32_t Ttl_TPM_LoadManuMaintPub(TPM_LoadManuMaintPub_rqu* in_parameters, TPM_LoadManuMaintPub_rsp* out_parameters, uint8_t* buffer, int buffer_size);

typedef struct TPM_ReadManuMaintPub_rqu {
  TPM_NONCE antiReplay;
} TPM_ReadManuMaintPub_rqu;


typedef struct TPM_ReadManuMaintPub_rsp {
  TPM_DIGEST checksum;
} TPM_ReadManuMaintPub_rsp;


/* Sends a TPM_ReadManuMaintPub command to the TPM and reads the response. */
uint32_t Ttl_TPM_ReadManuMaintPub(TPM_ReadManuMaintPub_rqu* in_parameters, TPM_ReadManuMaintPub_rsp* out_parameters, uint8_t* buffer, int buffer_size);

typedef struct TPM_SHA1Start_rsp {
  uint32_t maxNumBytes;
} TPM_SHA1Start_rsp;


/* Sends a TPM_SHA1Start command to the TPM and reads the response. */
uint32_t Ttl_TPM_SHA1Start(TPM_SHA1Start_rsp* out_parameters, uint8_t* buffer, int buffer_size);

typedef struct TPM_SHA1Update_rqu {
  uint32_t numBytes;
  uint8_t* hashData;
} TPM_SHA1Update_rqu;


/* Sends a TPM_SHA1Update command to the TPM and reads the response. */
uint32_t Ttl_TPM_SHA1Update(TPM_SHA1Update_rqu* in_parameters);

typedef struct TPM_SHA1Complete_rqu {
  uint32_t hashDataSize;
  uint8_t* hashData;
} TPM_SHA1Complete_rqu;


typedef struct TPM_SHA1Complete_rsp {
  TPM_DIGEST hashValue;
} TPM_SHA1Complete_rsp;


/* Sends a TPM_SHA1Complete command to the TPM and reads the response. */
uint32_t Ttl_TPM_SHA1Complete(TPM_SHA1Complete_rqu* in_parameters, TPM_SHA1Complete_rsp* out_parameters, uint8_t* buffer, int buffer_size);

typedef struct TPM_SHA1CompleteExtend_rqu {
  TPM_PCRINDEX pcrNum;
  uint32_t hashDataSize;
  uint8_t* hashData;
} TPM_SHA1CompleteExtend_rqu;


typedef struct TPM_SHA1CompleteExtend_rsp {
  TPM_DIGEST hashValue;
  TPM_PCRVALUE outDigest;
} TPM_SHA1CompleteExtend_rsp;


/* Sends a TPM_SHA1CompleteExtend command to the TPM and reads the response. */
uint32_t Ttl_TPM_SHA1CompleteExtend(TPM_SHA1CompleteExtend_rqu* in_parameters, TPM_SHA1CompleteExtend_rsp* out_parameters, uint8_t* buffer, int buffer_size);

typedef struct TPM_Sign_rqu {
  TPM_KEY_HANDLE keyHandle;
  uint32_t areaToSignSize;
  uint8_t* areaToSign;
} TPM_Sign_rqu;


typedef struct TPM_Sign_rsp {
  uint32_t sigSize;
  uint8_t* sig;
} TPM_Sign_rsp;


/* Sends a TPM_Sign command to the TPM and reads the response. */
uint32_t Ttl_TPM_Sign(TPM_Sign_rqu* in_parameters, TPM_Sign_rsp* out_parameters, uint8_t* buffer, int buffer_size, APSession* auth1);

typedef struct TPM_GetRandom_rqu {
  uint32_t bytesRequested;
} TPM_GetRandom_rqu;


typedef struct TPM_GetRandom_rsp {
  uint32_t randomBytesSize;
  uint8_t* randomBytes;
} TPM_GetRandom_rsp;


/* Sends a TPM_GetRandom command to the TPM and reads the response. */
uint32_t Ttl_TPM_GetRandom(TPM_GetRandom_rqu* in_parameters, TPM_GetRandom_rsp* out_parameters, uint8_t* buffer, int buffer_size);

typedef struct TPM_StirRandom_rqu {
  uint32_t dataSize;
  uint8_t* inData;
} TPM_StirRandom_rqu;


/* Sends a TPM_StirRandom command to the TPM and reads the response. */
uint32_t Ttl_TPM_StirRandom(TPM_StirRandom_rqu* in_parameters);

typedef struct TPM_CertifyKey_rqu {
  TPM_KEY_HANDLE certHandle;
  TPM_KEY_HANDLE keyHandle;
  TPM_NONCE antiReplay;
} TPM_CertifyKey_rqu;


typedef struct TPM_CertifyKey_rsp {
  TPM_CERTIFY_INFO certifyInfo;
  TPM_CERTIFY_INFO or;
  uint32_t outDataSize;
  uint8_t* outData;
} TPM_CertifyKey_rsp;


/* Sends a TPM_CertifyKey command to the TPM and reads the response. */
uint32_t Ttl_TPM_CertifyKey(TPM_CertifyKey_rqu* in_parameters, TPM_CertifyKey_rsp* out_parameters, uint8_t* buffer, int buffer_size, APSession* auth1, APSession* auth2);

typedef struct TPM_CertifyKey2_rqu {
  TPM_KEY_HANDLE keyHandle;
  TPM_KEY_HANDLE certHandle;
  TPM_DIGEST migrationPubDigest;
  TPM_NONCE antiReplay;
} TPM_CertifyKey2_rqu;


typedef struct TPM_CertifyKey2_rsp {
  TPM_CERTIFY_INFO2 certifyInfo;
  TPM_CERTIFY_INFO2 relative;
  uint32_t outDataSize;
  uint8_t* outData;
} TPM_CertifyKey2_rsp;


/* Sends a TPM_CertifyKey2 command to the TPM and reads the response. */
uint32_t Ttl_TPM_CertifyKey2(TPM_CertifyKey2_rqu* in_parameters, TPM_CertifyKey2_rsp* out_parameters, uint8_t* buffer, int buffer_size, APSession* auth1, APSession* auth2);

typedef struct TPM_CreateEndorsementKeyPair_rqu {
  TPM_NONCE antiReplay;
  TPM_KEY_PARMS keyInfo;
} TPM_CreateEndorsementKeyPair_rqu;


typedef struct TPM_CreateEndorsementKeyPair_rsp {
  TPM_PUBKEY pubEndorsementKey;
  TPM_DIGEST checksum;
} TPM_CreateEndorsementKeyPair_rsp;


/* Sends a TPM_CreateEndorsementKeyPair command to the TPM and reads the response. */
uint32_t Ttl_TPM_CreateEndorsementKeyPair(TPM_CreateEndorsementKeyPair_rqu* in_parameters, TPM_CreateEndorsementKeyPair_rsp* out_parameters, uint8_t* buffer, int buffer_size);

typedef struct TPM_CreateRevocableEK_rqu {
  TPM_NONCE antiReplay;
  TPM_KEY_PARMS keyInfo;
  uint8_t generateReset;
  TPM_NONCE inputEKreset;
} TPM_CreateRevocableEK_rqu;


typedef struct TPM_CreateRevocableEK_rsp {
  TPM_PUBKEY pubEndorsementKey;
  TPM_DIGEST checksum;
  TPM_NONCE outputEKreset;
} TPM_CreateRevocableEK_rsp;


/* Sends a TPM_CreateRevocableEK command to the TPM and reads the response. */
uint32_t Ttl_TPM_CreateRevocableEK(TPM_CreateRevocableEK_rqu* in_parameters, TPM_CreateRevocableEK_rsp* out_parameters, uint8_t* buffer, int buffer_size);

typedef struct TPM_RevokeTrust_rqu {
  TPM_NONCE EKReset;
} TPM_RevokeTrust_rqu;


/* Sends a TPM_RevokeTrust command to the TPM and reads the response. */
uint32_t Ttl_TPM_RevokeTrust(TPM_RevokeTrust_rqu* in_parameters);

typedef struct TPM_ReadPubek_rqu {
  TPM_NONCE antiReplay;
} TPM_ReadPubek_rqu;


typedef struct TPM_ReadPubek_rsp {
  TPM_PUBKEY pubEndorsementKey;
  TPM_DIGEST checksum;
} TPM_ReadPubek_rsp;


/* Sends a TPM_ReadPubek command to the TPM and reads the response. */
uint32_t Ttl_TPM_ReadPubek(TPM_ReadPubek_rqu* in_parameters, TPM_ReadPubek_rsp* out_parameters, uint8_t* buffer, int buffer_size);

typedef struct TPM_OwnerReadInternalPub_rqu {
  TPM_KEY_HANDLE keyHandle;
} TPM_OwnerReadInternalPub_rqu;


typedef struct TPM_OwnerReadInternalPub_rsp {
  TPM_PUBKEY publicPortion;
} TPM_OwnerReadInternalPub_rsp;


/* Sends a TPM_OwnerReadInternalPub command to the TPM and reads the response. */
uint32_t Ttl_TPM_OwnerReadInternalPub(TPM_OwnerReadInternalPub_rqu* in_parameters, TPM_OwnerReadInternalPub_rsp* out_parameters, uint8_t* buffer, int buffer_size, APSession* auth1);

typedef struct TPM_MakeIdentity_rqu {
  TPM_ENCAUTH identityAuth;
  TPM_CHOSENID_HASH labelPrivCADigest;
  TPM_KEY idKeyParams;
} TPM_MakeIdentity_rqu;


typedef struct TPM_MakeIdentity_rsp {
  TPM_KEY idKey;
  uint32_t identityBindingSize;
  uint8_t* identityBinding;
} TPM_MakeIdentity_rsp;


/* Sends a TPM_MakeIdentity command to the TPM and reads the response. */
uint32_t Ttl_TPM_MakeIdentity(TPM_MakeIdentity_rqu* in_parameters, TPM_MakeIdentity_rsp* out_parameters, uint8_t* buffer, int buffer_size, APSession* auth1, APSession* auth2);

typedef struct TPM_ActivateIdentity_rqu {
  TPM_KEY_HANDLE idKeyHandle;
  uint32_t blobSize;
  uint8_t* blob;
} TPM_ActivateIdentity_rqu;


typedef struct TPM_ActivateIdentity_rsp {
  TPM_SYMMETRIC_KEY symmetricKey;
} TPM_ActivateIdentity_rsp;


/* Sends a TPM_ActivateIdentity command to the TPM and reads the response. */
uint32_t Ttl_TPM_ActivateIdentity(TPM_ActivateIdentity_rqu* in_parameters, TPM_ActivateIdentity_rsp* out_parameters, uint8_t* buffer, int buffer_size, APSession* auth1, APSession* auth2);

typedef struct TPM_Extend_rqu {
  TPM_PCRINDEX pcrNum;
  TPM_DIGEST inDigest;
} TPM_Extend_rqu;


typedef struct TPM_Extend_rsp {
  TPM_PCRVALUE outDigest;
} TPM_Extend_rsp;


/* Sends a TPM_Extend command to the TPM and reads the response. */
uint32_t Ttl_TPM_Extend(TPM_Extend_rqu* in_parameters, TPM_Extend_rsp* out_parameters, uint8_t* buffer, int buffer_size);

typedef struct TPM_PCRRead_rqu {
  TPM_PCRINDEX pcrIndex;
} TPM_PCRRead_rqu;


typedef struct TPM_PCRRead_rsp {
  TPM_PCRVALUE outDigest;
} TPM_PCRRead_rsp;


/* Sends a TPM_PCRRead command to the TPM and reads the response. */
uint32_t Ttl_TPM_PCRRead(TPM_PCRRead_rqu* in_parameters, TPM_PCRRead_rsp* out_parameters, uint8_t* buffer, int buffer_size);

typedef struct TPM_Quote_rqu {
  TPM_KEY_HANDLE keyHandle;
  TPM_NONCE externalData;
  TPM_PCR_SELECTION targetPCR;
} TPM_Quote_rqu;


typedef struct TPM_Quote_rsp {
  TPM_PCR_COMPOSITE pcrData;
  uint32_t sigSize;
  uint8_t* sig;
} TPM_Quote_rsp;


/* Sends a TPM_Quote command to the TPM and reads the response. */
uint32_t Ttl_TPM_Quote(TPM_Quote_rqu* in_parameters, TPM_Quote_rsp* out_parameters, uint8_t* buffer, int buffer_size, APSession* auth1);

typedef struct TPM_PCR_Reset_rqu {
  TPM_PCR_SELECTION pcrSelection;
} TPM_PCR_Reset_rqu;


/* Sends a TPM_PCR_Reset command to the TPM and reads the response. */
uint32_t Ttl_TPM_PCR_Reset(TPM_PCR_Reset_rqu* in_parameters);

typedef struct TPM_Quote2_rqu {
  TPM_KEY_HANDLE keyHandle;
  TPM_NONCE externalData;
  TPM_PCR_SELECTION targetPCR;
  uint8_t addVersion;
} TPM_Quote2_rqu;


typedef struct TPM_Quote2_rsp {
  TPM_PCR_INFO_SHORT pcrData;
  uint32_t versionInfoSize;
  TPM_CAP_VERSION_INFO versionInfo;
  uint32_t sigSize;
  uint8_t* sig;
} TPM_Quote2_rsp;


/* Sends a TPM_Quote2 command to the TPM and reads the response. */
uint32_t Ttl_TPM_Quote2(TPM_Quote2_rqu* in_parameters, TPM_Quote2_rsp* out_parameters, uint8_t* buffer, int buffer_size, APSession* auth1);

typedef struct TPM_ChangeAuth_rqu {
  TPM_KEY_HANDLE parentHandle;
  TPM_PROTOCOL_ID protocolID;
  TPM_ENCAUTH newAuth;
  TPM_ENTITY_TYPE entityType;
  uint32_t encDataSize;
  uint8_t* encData;
} TPM_ChangeAuth_rqu;


typedef struct TPM_ChangeAuth_rsp {
  uint32_t outDataSize;
  uint8_t* outData;
} TPM_ChangeAuth_rsp;


/* Sends a TPM_ChangeAuth command to the TPM and reads the response. */
uint32_t Ttl_TPM_ChangeAuth(TPM_ChangeAuth_rqu* in_parameters, TPM_ChangeAuth_rsp* out_parameters, uint8_t* buffer, int buffer_size, APSession* auth1, APSession* auth2);

typedef struct TPM_ChangeAuthOwner_rqu {
  TPM_PROTOCOL_ID protocolID;
  TPM_ENCAUTH newAuth;
  TPM_ENTITY_TYPE entityType;
} TPM_ChangeAuthOwner_rqu;


/* Sends a TPM_ChangeAuthOwner command to the TPM and reads the response. */
uint32_t Ttl_TPM_ChangeAuthOwner(TPM_ChangeAuthOwner_rqu* in_parameters, APSession* auth1);

typedef struct TPM_OIAP_rsp {
  TPM_AUTHHANDLE authHandle;
  TPM_NONCE nonceEven;
} TPM_OIAP_rsp;


/* Sends a TPM_OIAP command to the TPM and reads the response. */
uint32_t Ttl_TPM_OIAP(TPM_OIAP_rsp* out_parameters, uint8_t* buffer, int buffer_size);

typedef struct TPM_OSAP_rqu {
  TPM_ENTITY_TYPE entityType;
  uint32_t entityValue;
  TPM_NONCE nonceOddOSAP;
} TPM_OSAP_rqu;


typedef struct TPM_OSAP_rsp {
  TPM_AUTHHANDLE authHandle;
  TPM_NONCE nonceEven;
  TPM_NONCE nonceEvenOSAP;
} TPM_OSAP_rsp;


/* Sends a TPM_OSAP command to the TPM and reads the response. */
uint32_t Ttl_TPM_OSAP(TPM_OSAP_rqu* in_parameters, TPM_OSAP_rsp* out_parameters, uint8_t* buffer, int buffer_size);

typedef struct TPM_DSAP_rqu {
  TPM_ENTITY_TYPE entityType;
  TPM_KEY_HANDLE keyHandle;
  TPM_NONCE nonceOddDSAP;
  uint32_t entityValueSize;
  uint8_t* entityValue;
} TPM_DSAP_rqu;


typedef struct TPM_DSAP_rsp {
  TPM_AUTHHANDLE authHandle;
  TPM_NONCE nonceEven;
  TPM_NONCE nonceEvenDSAP;
} TPM_DSAP_rsp;


/* Sends a TPM_DSAP command to the TPM and reads the response. */
uint32_t Ttl_TPM_DSAP(TPM_DSAP_rqu* in_parameters, TPM_DSAP_rsp* out_parameters, uint8_t* buffer, int buffer_size);

typedef struct TPM_SetOwnerPointer_rqu {
  TPM_ENTITY_TYPE entityType;
  uint32_t entityValue;
} TPM_SetOwnerPointer_rqu;


/* Sends a TPM_SetOwnerPointer command to the TPM and reads the response. */
uint32_t Ttl_TPM_SetOwnerPointer(TPM_SetOwnerPointer_rqu* in_parameters);

typedef struct TPM_Delegate_Manage_rqu {
  TPM_FAMILY_ID familyID;
  TPM_FAMILY_OPERATION opCode;
  uint32_t opDataSize;
  uint8_t* opData;
} TPM_Delegate_Manage_rqu;


typedef struct TPM_Delegate_Manage_rsp {
  uint32_t retDataSize;
  uint8_t* retData;
} TPM_Delegate_Manage_rsp;


/* Sends a TPM_Delegate_Manage command to the TPM and reads the response. */
uint32_t Ttl_TPM_Delegate_Manage(TPM_Delegate_Manage_rqu* in_parameters, TPM_Delegate_Manage_rsp* out_parameters, uint8_t* buffer, int buffer_size, APSession* auth1);

typedef struct TPM_Delegate_CreateKeyDelegation_rqu {
  TPM_KEY_HANDLE keyHandle;
  TPM_DELEGATE_PUBLIC publicInfo;
  TPM_ENCAUTH delAuth;
} TPM_Delegate_CreateKeyDelegation_rqu;


typedef struct TPM_Delegate_CreateKeyDelegation_rsp {
  uint32_t blobSize;
  TPM_DELEGATE_KEY_BLOB blob;
} TPM_Delegate_CreateKeyDelegation_rsp;


/* Sends a TPM_Delegate_CreateKeyDelegation command to the TPM and reads the response. */
uint32_t Ttl_TPM_Delegate_CreateKeyDelegation(TPM_Delegate_CreateKeyDelegation_rqu* in_parameters, TPM_Delegate_CreateKeyDelegation_rsp* out_parameters, uint8_t* buffer, int buffer_size, APSession* auth1);

typedef struct TPM_Delegate_CreateOwnerDelegation_rqu {
  uint8_t increment;
  TPM_DELEGATE_PUBLIC publicInfo;
  TPM_ENCAUTH delAuth;
} TPM_Delegate_CreateOwnerDelegation_rqu;


typedef struct TPM_Delegate_CreateOwnerDelegation_rsp {
  uint32_t blobSize;
  TPM_DELEGATE_OWNER_BLOB blob;
} TPM_Delegate_CreateOwnerDelegation_rsp;


/* Sends a TPM_Delegate_CreateOwnerDelegation command to the TPM and reads the response. */
uint32_t Ttl_TPM_Delegate_CreateOwnerDelegation(TPM_Delegate_CreateOwnerDelegation_rqu* in_parameters, TPM_Delegate_CreateOwnerDelegation_rsp* out_parameters, uint8_t* buffer, int buffer_size, APSession* auth1);

typedef struct TPM_Delegate_LoadOwnerDelegation_rqu {
  TPM_DELEGATE_INDEX index;
  uint32_t blobSize;
  TPM_DELEGATE_OWNER_BLOB blob;
} TPM_Delegate_LoadOwnerDelegation_rqu;


/* Sends a TPM_Delegate_LoadOwnerDelegation command to the TPM and reads the response. */
uint32_t Ttl_TPM_Delegate_LoadOwnerDelegation(TPM_Delegate_LoadOwnerDelegation_rqu* in_parameters, APSession* auth1);

typedef struct TPM_Delegate_ReadTable_rsp {
  uint32_t familyTableSize;
  uint8_t* familyTable;
  uint32_t delegateTableSize;
  uint8_t* delegateTable;
} TPM_Delegate_ReadTable_rsp;


/* Sends a TPM_Delegate_ReadTable command to the TPM and reads the response. */
uint32_t Ttl_TPM_Delegate_ReadTable(TPM_Delegate_ReadTable_rsp* out_parameters, uint8_t* buffer, int buffer_size);

typedef struct TPM_Delegate_UpdateVerification_rqu {
  uint32_t inputSize;
  uint8_t inputData;
  TPM_DELEGATE_KEY_BLOB or;
} TPM_Delegate_UpdateVerification_rqu;


typedef struct TPM_Delegate_UpdateVerification_rsp {
  uint32_t outputSize;
  uint8_t outputData;
  TPM_DELEGATE_KEY_BLOB or;
} TPM_Delegate_UpdateVerification_rsp;


/* Sends a TPM_Delegate_UpdateVerification command to the TPM and reads the response. */
uint32_t Ttl_TPM_Delegate_UpdateVerification(TPM_Delegate_UpdateVerification_rqu* in_parameters, TPM_Delegate_UpdateVerification_rsp* out_parameters, uint8_t* buffer, int buffer_size, APSession* auth1);

typedef struct TPM_Delegate_VerifyDelegation_rqu {
  uint32_t delegationSize;
  uint8_t* delegation;
  TPM_DELEGATE_KEY_BLOB or;
} TPM_Delegate_VerifyDelegation_rqu;


/* Sends a TPM_Delegate_VerifyDelegation command to the TPM and reads the response. */
uint32_t Ttl_TPM_Delegate_VerifyDelegation(TPM_Delegate_VerifyDelegation_rqu* in_parameters);

typedef struct TPM_NV_DefineSpace_rqu {
  TPM_NV_DATA_PUBLIC pubInfo;
  TPM_ENCAUTH encAuth;
} TPM_NV_DefineSpace_rqu;


/* Sends a TPM_NV_DefineSpace command to the TPM and reads the response. */
uint32_t Ttl_TPM_NV_DefineSpace(TPM_NV_DefineSpace_rqu* in_parameters, APSession* auth1);

typedef struct TPM_NV_WriteValue_rqu {
  TPM_NV_INDEX nvIndex;
  uint32_t offset;
  uint32_t dataSize;
  uint8_t* data;
} TPM_NV_WriteValue_rqu;


/* Sends a TPM_NV_WriteValue command to the TPM and reads the response. */
uint32_t Ttl_TPM_NV_WriteValue(TPM_NV_WriteValue_rqu* in_parameters, APSession* auth1);

typedef struct TPM_NV_WriteValueAuth_rqu {
  TPM_NV_INDEX nvIndex;
  uint32_t offset;
  uint32_t dataSize;
  uint8_t data;
} TPM_NV_WriteValueAuth_rqu;


/* Sends a TPM_NV_WriteValueAuth command to the TPM and reads the response. */
uint32_t Ttl_TPM_NV_WriteValueAuth(TPM_NV_WriteValueAuth_rqu* in_parameters, APSession* auth1);

typedef struct TPM_NV_ReadValue_rqu {
  TPM_NV_INDEX nvIndex;
  uint32_t offset;
  uint32_t dataSize;
} TPM_NV_ReadValue_rqu;


typedef struct TPM_NV_ReadValue_rsp {
  uint32_t dataSize;
  uint8_t* data;
} TPM_NV_ReadValue_rsp;


/* Sends a TPM_NV_ReadValue command to the TPM and reads the response. */
uint32_t Ttl_TPM_NV_ReadValue(TPM_NV_ReadValue_rqu* in_parameters, TPM_NV_ReadValue_rsp* out_parameters, uint8_t* buffer, int buffer_size, APSession* auth1);

typedef struct TPM_NV_ReadValueAuth_rqu {
  TPM_NV_INDEX nvIndex;
  uint32_t dataSize;
} TPM_NV_ReadValueAuth_rqu;


typedef struct TPM_NV_ReadValueAuth_rsp {
  uint32_t dataSize;
  uint8_t* data;
} TPM_NV_ReadValueAuth_rsp;


/* Sends a TPM_NV_ReadValueAuth command to the TPM and reads the response. */
uint32_t Ttl_TPM_NV_ReadValueAuth(TPM_NV_ReadValueAuth_rqu* in_parameters, TPM_NV_ReadValueAuth_rsp* out_parameters, uint8_t* buffer, int buffer_size, APSession* auth1);

typedef struct TPM_KeyControlOwner_rqu {
  TPM_KEY_HANDLE keyHandle;
  TPM_PUBKEY pubKey;
  TPM_KEY_CONTROL bitName;
  uint8_t bitValue;
} TPM_KeyControlOwner_rqu;


/* Sends a TPM_KeyControlOwner command to the TPM and reads the response. */
uint32_t Ttl_TPM_KeyControlOwner(TPM_KeyControlOwner_rqu* in_parameters, APSession* auth1);

typedef struct TPM_SaveContext_rqu {
  TPM_HANDLE handle;
  TPM_RESOURCE_TYPE resourceType;
  uint8_t label[16];
  TPM_TAG tag;
} TPM_SaveContext_rqu;


typedef struct TPM_SaveContext_rsp {
  TPM_CONTEXT_BLOB contextBlob;
} TPM_SaveContext_rsp;


/* Sends a TPM_SaveContext command to the TPM and reads the response. */
uint32_t Ttl_TPM_SaveContext(TPM_SaveContext_rqu* in_parameters, TPM_SaveContext_rsp* out_parameters, uint8_t* buffer, int buffer_size);

typedef struct TPM_LoadContext_rqu {
  TPM_HANDLE entityHandle;
  uint8_t keepHandle;
  uint32_t contextSize;
  TPM_CONTEXT_BLOB contextBlob;
} TPM_LoadContext_rqu;


typedef struct TPM_LoadContext_rsp {
  TPM_HANDLE handle;
} TPM_LoadContext_rsp;


/* Sends a TPM_LoadContext command to the TPM and reads the response. */
uint32_t Ttl_TPM_LoadContext(TPM_LoadContext_rqu* in_parameters, TPM_LoadContext_rsp* out_parameters, uint8_t* buffer, int buffer_size);

typedef struct TPM_FlushSpecific_rqu {
  TPM_HANDLE handle;
  TPM_RESOURCE_TYPE resourceType;
} TPM_FlushSpecific_rqu;


/* Sends a TPM_FlushSpecific command to the TPM and reads the response. */
uint32_t Ttl_TPM_FlushSpecific(TPM_FlushSpecific_rqu* in_parameters);

typedef struct TPM_GetTicks_rsp {
  TPM_CURRENT_TICKS currentTime;
} TPM_GetTicks_rsp;


/* Sends a TPM_GetTicks command to the TPM and reads the response. */
uint32_t Ttl_TPM_GetTicks(TPM_GetTicks_rsp* out_parameters, uint8_t* buffer, int buffer_size);

typedef struct TPM_TickStampBlob_rqu {
  TPM_KEY_HANDLE keyHandle;
  TPM_NONCE antiReplay;
  TPM_DIGEST digestToStamp;
} TPM_TickStampBlob_rqu;


typedef struct TPM_TickStampBlob_rsp {
  TPM_CURRENT_TICKS currentTicks;
  uint32_t sigSize;
  uint8_t* sig;
} TPM_TickStampBlob_rsp;


/* Sends a TPM_TickStampBlob command to the TPM and reads the response. */
uint32_t Ttl_TPM_TickStampBlob(TPM_TickStampBlob_rqu* in_parameters, TPM_TickStampBlob_rsp* out_parameters, uint8_t* buffer, int buffer_size, APSession* auth1);

typedef struct TPM_EstablishTransport_rqu {
  TPM_KEY_HANDLE encHandle;
  TPM_TRANSPORT_PUBLIC transPublic;
  uint32_t secretSize;
  uint8_t* secret;
} TPM_EstablishTransport_rqu;


typedef struct TPM_EstablishTransport_rsp {
  TPM_TRANSHANDLE transHandle;
  TPM_MODIFIER_INDICATOR locality;
  TPM_CURRENT_TICKS currentTicks;
  TPM_NONCE transNonceEven;
} TPM_EstablishTransport_rsp;


/* Sends a TPM_EstablishTransport command to the TPM and reads the response. */
uint32_t Ttl_TPM_EstablishTransport(TPM_EstablishTransport_rqu* in_parameters, TPM_EstablishTransport_rsp* out_parameters, uint8_t* buffer, int buffer_size, APSession* auth1);

typedef struct TPM_ExecuteTransport_rqu {
  uint32_t wrappedCmdSize;
  uint8_t* wrappedCmd;
} TPM_ExecuteTransport_rqu;


typedef struct TPM_ExecuteTransport_rsp {
  uint64_t currentTicks;
  TPM_MODIFIER_INDICATOR locality;
  uint32_t wrappedRspSize;
  uint8_t* wrappedRsp;
} TPM_ExecuteTransport_rsp;


/* Sends a TPM_ExecuteTransport command to the TPM and reads the response. */
uint32_t Ttl_TPM_ExecuteTransport(TPM_ExecuteTransport_rqu* in_parameters, TPM_ExecuteTransport_rsp* out_parameters, uint8_t* buffer, int buffer_size, APSession* auth1);

typedef struct TPM_ReleaseTransportSigned_rqu {
  TPM_KEY_HANDLE keyHandle;
  TPM_NONCE antiReplay;
} TPM_ReleaseTransportSigned_rqu;


typedef struct TPM_ReleaseTransportSigned_rsp {
  TPM_MODIFIER_INDICATOR locality;
  TPM_CURRENT_TICKS currentTicks;
  uint32_t signSize;
  uint8_t* signature;
} TPM_ReleaseTransportSigned_rsp;


/* Sends a TPM_ReleaseTransportSigned command to the TPM and reads the response. */
uint32_t Ttl_TPM_ReleaseTransportSigned(TPM_ReleaseTransportSigned_rqu* in_parameters, TPM_ReleaseTransportSigned_rsp* out_parameters, uint8_t* buffer, int buffer_size, APSession* auth1, APSession* auth2);

typedef struct TPM_CreateCounter_rqu {
  TPM_ENCAUTH encAuth;
  uint8_t label;
} TPM_CreateCounter_rqu;


typedef struct TPM_CreateCounter_rsp {
  TPM_COUNT_ID countID;
  TPM_COUNTER_VALUE counterValue;
} TPM_CreateCounter_rsp;


/* Sends a TPM_CreateCounter command to the TPM and reads the response. */
uint32_t Ttl_TPM_CreateCounter(TPM_CreateCounter_rqu* in_parameters, TPM_CreateCounter_rsp* out_parameters, uint8_t* buffer, int buffer_size, APSession* auth1);

typedef struct TPM_IncrementCounter_rqu {
  TPM_COUNT_ID countID;
} TPM_IncrementCounter_rqu;


typedef struct TPM_IncrementCounter_rsp {
  TPM_COUNTER_VALUE count;
} TPM_IncrementCounter_rsp;


/* Sends a TPM_IncrementCounter command to the TPM and reads the response. */
uint32_t Ttl_TPM_IncrementCounter(TPM_IncrementCounter_rqu* in_parameters, TPM_IncrementCounter_rsp* out_parameters, uint8_t* buffer, int buffer_size, APSession* auth1);

typedef struct TPM_ReadCounter_rqu {
  TPM_COUNT_ID countID;
} TPM_ReadCounter_rqu;


typedef struct TPM_ReadCounter_rsp {
  TPM_COUNTER_VALUE count;
} TPM_ReadCounter_rsp;


/* Sends a TPM_ReadCounter command to the TPM and reads the response. */
uint32_t Ttl_TPM_ReadCounter(TPM_ReadCounter_rqu* in_parameters, TPM_ReadCounter_rsp* out_parameters, uint8_t* buffer, int buffer_size);

typedef struct TPM_ReleaseCounter_rqu {
  TPM_COUNT_ID countID;
} TPM_ReleaseCounter_rqu;


/* Sends a TPM_ReleaseCounter command to the TPM and reads the response. */
uint32_t Ttl_TPM_ReleaseCounter(TPM_ReleaseCounter_rqu* in_parameters, APSession* auth1);

typedef struct TPM_ReleaseCounterOwner_rqu {
  TPM_COUNT_ID countID;
} TPM_ReleaseCounterOwner_rqu;


/* Sends a TPM_ReleaseCounterOwner command to the TPM and reads the response. */
uint32_t Ttl_TPM_ReleaseCounterOwner(TPM_ReleaseCounterOwner_rqu* in_parameters, APSession* auth1);

typedef struct TPM_DAA_Join_rqu {
  TPM_HANDLE handle;
  uint8_t stage;
  uint32_t inputSize0;
  uint8_t* inputData0;
  uint32_t inputSize1;
  uint8_t* inputData1;
} TPM_DAA_Join_rqu;


typedef struct TPM_DAA_Join_rsp {
  uint32_t outputSize;
  uint8_t* outputData;
} TPM_DAA_Join_rsp;


/* Sends a TPM_DAA_Join command to the TPM and reads the response. */
uint32_t Ttl_TPM_DAA_Join(TPM_DAA_Join_rqu* in_parameters, TPM_DAA_Join_rsp* out_parameters, uint8_t* buffer, int buffer_size, APSession* auth1);

typedef struct TPM_DAA_Sign_rqu {
  TPM_HANDLE handle;
  uint8_t stage;
  uint32_t inputSize0;
  uint8_t* inputData0;
  uint32_t inputSize1;
  uint8_t* inputData1;
} TPM_DAA_Sign_rqu;


typedef struct TPM_DAA_Sign_rsp {
  uint32_t outputSize;
  uint8_t* outputData;
} TPM_DAA_Sign_rsp;


/* Sends a TPM_DAA_Sign command to the TPM and reads the response. */
uint32_t Ttl_TPM_DAA_Sign(TPM_DAA_Sign_rqu* in_parameters, TPM_DAA_Sign_rsp* out_parameters, uint8_t* buffer, int buffer_size, APSession* auth1);

typedef struct TPM_EvictKey_rqu {
  TPM_KEY_HANDLE evictHandle;
} TPM_EvictKey_rqu;


/* Sends a TPM_EvictKey command to the TPM and reads the response. */
uint32_t Ttl_TPM_EvictKey(TPM_EvictKey_rqu* in_parameters);

typedef struct TPM_Terminate_Handle_rqu {
  TPM_AUTHHANDLE handle;
} TPM_Terminate_Handle_rqu;


/* Sends a TPM_Terminate_Handle command to the TPM and reads the response. */
uint32_t Ttl_TPM_Terminate_Handle(TPM_Terminate_Handle_rqu* in_parameters);

typedef struct TPM_SaveKeyContext_rqu {
  TPM_KEY_HANDLE keyHandle;
} TPM_SaveKeyContext_rqu;


typedef struct TPM_SaveKeyContext_rsp {
  uint32_t keyContextSize;
  uint8_t* keyContextBlob;
} TPM_SaveKeyContext_rsp;


/* Sends a TPM_SaveKeyContext command to the TPM and reads the response. */
uint32_t Ttl_TPM_SaveKeyContext(TPM_SaveKeyContext_rqu* in_parameters, TPM_SaveKeyContext_rsp* out_parameters, uint8_t* buffer, int buffer_size);

typedef struct TPM_LoadKeyContext_rqu {
  uint32_t keyContextSize;
  uint8_t* keyContextBlob;
} TPM_LoadKeyContext_rqu;


typedef struct TPM_LoadKeyContext_rsp {
  TPM_KEY_HANDLE keyHandle;
} TPM_LoadKeyContext_rsp;


/* Sends a TPM_LoadKeyContext command to the TPM and reads the response. */
uint32_t Ttl_TPM_LoadKeyContext(TPM_LoadKeyContext_rqu* in_parameters, TPM_LoadKeyContext_rsp* out_parameters, uint8_t* buffer, int buffer_size);

typedef struct TPM_SaveAuthContext_rqu {
  TPM_AUTHHANDLE authHandle;
} TPM_SaveAuthContext_rqu;


typedef struct TPM_SaveAuthContext_rsp {
  uint32_t authContextSize;
  uint8_t* authContextBlob;
} TPM_SaveAuthContext_rsp;


/* Sends a TPM_SaveAuthContext command to the TPM and reads the response. */
uint32_t Ttl_TPM_SaveAuthContext(TPM_SaveAuthContext_rqu* in_parameters, TPM_SaveAuthContext_rsp* out_parameters, uint8_t* buffer, int buffer_size);

typedef struct TPM_LoadAuthContext_rqu {
  uint32_t authContextSize;
  uint8_t* authContextBlob;
} TPM_LoadAuthContext_rqu;


typedef struct TPM_LoadAuthContext_rsp {
  TPM_KEY_HANDLE authHandle;
} TPM_LoadAuthContext_rsp;


/* Sends a TPM_LoadAuthContext command to the TPM and reads the response. */
uint32_t Ttl_TPM_LoadAuthContext(TPM_LoadAuthContext_rqu* in_parameters, TPM_LoadAuthContext_rsp* out_parameters, uint8_t* buffer, int buffer_size);

typedef struct TPM_DirWriteAuth_rqu {
  TPM_DIRINDEX dirIndex;
  TPM_DIRVALUE newContents;
} TPM_DirWriteAuth_rqu;


/* Sends a TPM_DirWriteAuth command to the TPM and reads the response. */
uint32_t Ttl_TPM_DirWriteAuth(TPM_DirWriteAuth_rqu* in_parameters, APSession* auth1);

typedef struct TPM_DirRead_rqu {
  TPM_DIRINDEX dirIndex;
} TPM_DirRead_rqu;


typedef struct TPM_DirRead_rsp {
  TPM_DIRVALUE dirContents;
} TPM_DirRead_rsp;


/* Sends a TPM_DirRead command to the TPM and reads the response. */
uint32_t Ttl_TPM_DirRead(TPM_DirRead_rqu* in_parameters, TPM_DirRead_rsp* out_parameters, uint8_t* buffer, int buffer_size);

typedef struct TPM_ChangeAuthAsymStart_rqu {
  TPM_KEY_HANDLE idHandle;
  TPM_NONCE antiReplay;
  TPM_KEY_PARMS tempKey;
} TPM_ChangeAuthAsymStart_rqu;


typedef struct TPM_ChangeAuthAsymStart_rsp {
  TPM_CERTIFY_INFO certifyInfo;
  uint32_t sigSize;
  uint8_t* sig;
  TPM_KEY_HANDLE ephHandle;
  TPM_KEY tempKey;
} TPM_ChangeAuthAsymStart_rsp;


/* Sends a TPM_ChangeAuthAsymStart command to the TPM and reads the response. */
uint32_t Ttl_TPM_ChangeAuthAsymStart(TPM_ChangeAuthAsymStart_rqu* in_parameters, TPM_ChangeAuthAsymStart_rsp* out_parameters, uint8_t* buffer, int buffer_size, APSession* auth1);

typedef struct TPM_ChangeAuthAsymFinish_rqu {
  TPM_KEY_HANDLE parentHandle;
  TPM_KEY_HANDLE ephHandle;
  TPM_ENTITY_TYPE entityType;
  TPM_HMAC newAuthLink;
  uint32_t newAuthSize;
  uint8_t* encNewAuth;
  uint32_t encDataSize;
  uint8_t* encData;
} TPM_ChangeAuthAsymFinish_rqu;


typedef struct TPM_ChangeAuthAsymFinish_rsp {
  uint32_t outDataSize;
  uint8_t* outData;
  TPM_NONCE saltNonce;
  TPM_DIGEST changeProof;
} TPM_ChangeAuthAsymFinish_rsp;


/* Sends a TPM_ChangeAuthAsymFinish command to the TPM and reads the response. */
uint32_t Ttl_TPM_ChangeAuthAsymFinish(TPM_ChangeAuthAsymFinish_rqu* in_parameters, TPM_ChangeAuthAsymFinish_rsp* out_parameters, uint8_t* buffer, int buffer_size, APSession* auth1);

/* Sends a TPM_Reset command to the TPM and reads the response. */
uint32_t Ttl_TPM_Reset(void);

typedef struct TPM_OwnerReadPubek_rsp {
  TPM_PUBKEY pubEndorsementKey;
} TPM_OwnerReadPubek_rsp;


/* Sends a TPM_OwnerReadPubek command to the TPM and reads the response. */
uint32_t Ttl_TPM_OwnerReadPubek(TPM_OwnerReadPubek_rsp* out_parameters, uint8_t* buffer, int buffer_size, APSession* auth1);

/* Sends a TPM_DisablePubekRead command to the TPM and reads the response. */
uint32_t Ttl_TPM_DisablePubekRead(APSession* auth1);

typedef struct TPM_LoadKey_rqu {
  TPM_KEY_HANDLE parentHandle;
  TPM_KEY inKey;
} TPM_LoadKey_rqu;


typedef struct TPM_LoadKey_rsp {
  TPM_KEY_HANDLE inkeyHandle;
} TPM_LoadKey_rsp;


/* Sends a TPM_LoadKey command to the TPM and reads the response. */
uint32_t Ttl_TPM_LoadKey(TPM_LoadKey_rqu* in_parameters, TPM_LoadKey_rsp* out_parameters, uint8_t* buffer, int buffer_size, APSession* auth1);

typedef struct TPM_GetOrdinalAuditStatus_rqu {
  TPM_COMMAND_CODE ordinalToQuery;
} TPM_GetOrdinalAuditStatus_rqu;


typedef struct TPM_GetOrdinalAuditStatus_rsp {
  uint8_t State;
} TPM_GetOrdinalAuditStatus_rsp;


/* Sends a TPM_GetOrdinalAuditStatus command to the TPM and reads the response. */
uint32_t Ttl_TPM_GetOrdinalAuditStatus(TPM_GetOrdinalAuditStatus_rqu* in_parameters, TPM_GetOrdinalAuditStatus_rsp* out_parameters, uint8_t* buffer, int buffer_size);

#endif  /* TRUNKS_G_TPM_COMMANDS_H_ */
