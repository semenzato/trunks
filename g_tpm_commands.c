/* Copyright (c) 2011 The Chromium OS Authors. All rights reserved.
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "g_tpm_commands.h"

/* Sends a TPM_Startup command to the TPM and reads the response. */
uint32_t Ttl_TPM_Startup(TPM_Startup_rqu* in_parameters) {
  void* out_parameters = NULL;
  uint8_t buffer[TPM_MAX_COMMAND_LENGTH];
  int buffer_size = sizeof(buffer);
  void* auth1 = NULL;
  void* auth2 = NULL;
  RETURN_ON_FAILURE(TtlRunCommand(TPM_ORD_Startup,
         1830, -1, in_parameters, out_parameters,
         auth1, auth2, buffer, buffer_size));
  return TPM_SUCCESS;
}

/* Sends a TPM_SaveState command to the TPM and reads the response. */
uint32_t Ttl_TPM_SaveState(void) {
  void* in_parameters = NULL;
  void* out_parameters = NULL;
  uint8_t buffer[TPM_MAX_COMMAND_LENGTH];
  int buffer_size = sizeof(buffer);
  void* auth1 = NULL;
  void* auth2 = NULL;
  RETURN_ON_FAILURE(TtlRunCommand(TPM_ORD_SaveState,
         -1, -1, in_parameters, out_parameters,
         auth1, auth2, buffer, buffer_size));
  return TPM_SUCCESS;
}

/* Sends a TPM_SelfTestFull command to the TPM and reads the response. */
uint32_t Ttl_TPM_SelfTestFull(void) {
  void* in_parameters = NULL;
  void* out_parameters = NULL;
  uint8_t buffer[TPM_MAX_COMMAND_LENGTH];
  int buffer_size = sizeof(buffer);
  void* auth1 = NULL;
  void* auth2 = NULL;
  RETURN_ON_FAILURE(TtlRunCommand(TPM_ORD_SelfTestFull,
         -1, -1, in_parameters, out_parameters,
         auth1, auth2, buffer, buffer_size));
  return TPM_SUCCESS;
}

/* Sends a TPM_ContinueSelfTest command to the TPM and reads the response. */
uint32_t Ttl_TPM_ContinueSelfTest(void) {
  void* in_parameters = NULL;
  void* out_parameters = NULL;
  uint8_t buffer[TPM_MAX_COMMAND_LENGTH];
  int buffer_size = sizeof(buffer);
  void* auth1 = NULL;
  void* auth2 = NULL;
  RETURN_ON_FAILURE(TtlRunCommand(TPM_ORD_ContinueSelfTest,
         -1, -1, in_parameters, out_parameters,
         auth1, auth2, buffer, buffer_size));
  return TPM_SUCCESS;
}

/* Sends a TPM_GetTestResult command to the TPM and reads the response. */
uint32_t Ttl_TPM_GetTestResult(TPM_GetTestResult_rsp* out_parameters, uint8_t* buffer, int buffer_size) {
  void* in_parameters = NULL;
  void* auth1 = NULL;
  void* auth2 = NULL;
  RETURN_ON_FAILURE(TtlRunCommand(TPM_ORD_GetTestResult,
         -1, 1836, in_parameters, out_parameters,
         auth1, auth2, buffer, buffer_size));
  return TPM_SUCCESS;
}

/* Sends a TPM_SetOwnerInstall command to the TPM and reads the response. */
uint32_t Ttl_TPM_SetOwnerInstall(TPM_SetOwnerInstall_rqu* in_parameters) {
  void* out_parameters = NULL;
  uint8_t buffer[TPM_MAX_COMMAND_LENGTH];
  int buffer_size = sizeof(buffer);
  void* auth1 = NULL;
  void* auth2 = NULL;
  RETURN_ON_FAILURE(TtlRunCommand(TPM_ORD_SetOwnerInstall,
         1847, -1, in_parameters, out_parameters,
         auth1, auth2, buffer, buffer_size));
  return TPM_SUCCESS;
}

/* Sends a TPM_OwnerSetDisable command to the TPM and reads the response. */
uint32_t Ttl_TPM_OwnerSetDisable(TPM_OwnerSetDisable_rqu* in_parameters, APSession* auth1) {
  void* out_parameters = NULL;
  uint8_t buffer[TPM_MAX_COMMAND_LENGTH];
  int buffer_size = sizeof(buffer);
  void* auth2 = NULL;
  RETURN_ON_FAILURE(TtlRunCommand(TPM_ORD_OwnerSetDisable,
         1853, -1, in_parameters, out_parameters,
         auth1, auth2, buffer, buffer_size));
  return TPM_SUCCESS;
}

/* Sends a TPM_PhysicalEnable command to the TPM and reads the response. */
uint32_t Ttl_TPM_PhysicalEnable(void) {
  void* in_parameters = NULL;
  void* out_parameters = NULL;
  uint8_t buffer[TPM_MAX_COMMAND_LENGTH];
  int buffer_size = sizeof(buffer);
  void* auth1 = NULL;
  void* auth2 = NULL;
  RETURN_ON_FAILURE(TtlRunCommand(TPM_ORD_PhysicalEnable,
         -1, -1, in_parameters, out_parameters,
         auth1, auth2, buffer, buffer_size));
  return TPM_SUCCESS;
}

/* Sends a TPM_PhysicalDisable command to the TPM and reads the response. */
uint32_t Ttl_TPM_PhysicalDisable(void) {
  void* in_parameters = NULL;
  void* out_parameters = NULL;
  uint8_t buffer[TPM_MAX_COMMAND_LENGTH];
  int buffer_size = sizeof(buffer);
  void* auth1 = NULL;
  void* auth2 = NULL;
  RETURN_ON_FAILURE(TtlRunCommand(TPM_ORD_PhysicalDisable,
         -1, -1, in_parameters, out_parameters,
         auth1, auth2, buffer, buffer_size));
  return TPM_SUCCESS;
}

/* Sends a TPM_PhysicalSetDeactivated command to the TPM and reads the response. */
uint32_t Ttl_TPM_PhysicalSetDeactivated(TPM_PhysicalSetDeactivated_rqu* in_parameters) {
  void* out_parameters = NULL;
  uint8_t buffer[TPM_MAX_COMMAND_LENGTH];
  int buffer_size = sizeof(buffer);
  void* auth1 = NULL;
  void* auth2 = NULL;
  RETURN_ON_FAILURE(TtlRunCommand(TPM_ORD_PhysicalSetDeactivated,
         1859, -1, in_parameters, out_parameters,
         auth1, auth2, buffer, buffer_size));
  return TPM_SUCCESS;
}

/* Sends a TPM_SetTempDeactivated command to the TPM and reads the response. */
uint32_t Ttl_TPM_SetTempDeactivated(APSession* auth1) {
  void* in_parameters = NULL;
  void* out_parameters = NULL;
  uint8_t buffer[TPM_MAX_COMMAND_LENGTH];
  int buffer_size = sizeof(buffer);
  void* auth2 = NULL;
  RETURN_ON_FAILURE(TtlRunCommand(TPM_ORD_SetTempDeactivated,
         -1, -1, in_parameters, out_parameters,
         auth1, auth2, buffer, buffer_size));
  return TPM_SUCCESS;
}

/* Sends a TPM_SetOperatorAuth command to the TPM and reads the response. */
uint32_t Ttl_TPM_SetOperatorAuth(TPM_SetOperatorAuth_rqu* in_parameters) {
  void* out_parameters = NULL;
  uint8_t buffer[TPM_MAX_COMMAND_LENGTH];
  int buffer_size = sizeof(buffer);
  void* auth1 = NULL;
  void* auth2 = NULL;
  RETURN_ON_FAILURE(TtlRunCommand(TPM_ORD_SetOperatorAuth,
         1865, -1, in_parameters, out_parameters,
         auth1, auth2, buffer, buffer_size));
  return TPM_SUCCESS;
}

/* Sends a TPM_TakeOwnership command to the TPM and reads the response. */
uint32_t Ttl_TPM_TakeOwnership(TPM_TakeOwnership_rqu* in_parameters, TPM_TakeOwnership_rsp* out_parameters, uint8_t* buffer, int buffer_size, APSession* auth1) {
  void* auth2 = NULL;
  RETURN_ON_FAILURE(TtlRunCommand(TPM_ORD_TakeOwnership,
         1876, 1906, in_parameters, out_parameters,
         auth1, auth2, buffer, buffer_size));
  return TPM_SUCCESS;
}

/* Sends a TPM_OwnerClear command to the TPM and reads the response. */
uint32_t Ttl_TPM_OwnerClear(APSession* auth1) {
  void* in_parameters = NULL;
  void* out_parameters = NULL;
  uint8_t buffer[TPM_MAX_COMMAND_LENGTH];
  int buffer_size = sizeof(buffer);
  void* auth2 = NULL;
  RETURN_ON_FAILURE(TtlRunCommand(TPM_ORD_OwnerClear,
         -1, -1, in_parameters, out_parameters,
         auth1, auth2, buffer, buffer_size));
  return TPM_SUCCESS;
}

/* Sends a TPM_ForceClear command to the TPM and reads the response. */
uint32_t Ttl_TPM_ForceClear(void) {
  void* in_parameters = NULL;
  void* out_parameters = NULL;
  uint8_t buffer[TPM_MAX_COMMAND_LENGTH];
  int buffer_size = sizeof(buffer);
  void* auth1 = NULL;
  void* auth2 = NULL;
  RETURN_ON_FAILURE(TtlRunCommand(TPM_ORD_ForceClear,
         -1, -1, in_parameters, out_parameters,
         auth1, auth2, buffer, buffer_size));
  return TPM_SUCCESS;
}

/* Sends a TPM_DisableOwnerClear command to the TPM and reads the response. */
uint32_t Ttl_TPM_DisableOwnerClear(APSession* auth1) {
  void* in_parameters = NULL;
  void* out_parameters = NULL;
  uint8_t buffer[TPM_MAX_COMMAND_LENGTH];
  int buffer_size = sizeof(buffer);
  void* auth2 = NULL;
  RETURN_ON_FAILURE(TtlRunCommand(TPM_ORD_DisableOwnerClear,
         -1, -1, in_parameters, out_parameters,
         auth1, auth2, buffer, buffer_size));
  return TPM_SUCCESS;
}

/* Sends a TPM_DisableForceClear command to the TPM and reads the response. */
uint32_t Ttl_TPM_DisableForceClear(void) {
  void* in_parameters = NULL;
  void* out_parameters = NULL;
  uint8_t buffer[TPM_MAX_COMMAND_LENGTH];
  int buffer_size = sizeof(buffer);
  void* auth1 = NULL;
  void* auth2 = NULL;
  RETURN_ON_FAILURE(TtlRunCommand(TPM_ORD_DisableForceClear,
         -1, -1, in_parameters, out_parameters,
         auth1, auth2, buffer, buffer_size));
  return TPM_SUCCESS;
}

/* Sends a TSC_PhysicalPresence command to the TPM and reads the response. */
uint32_t Ttl_TSC_PhysicalPresence(TSC_PhysicalPresence_rqu* in_parameters) {
  void* out_parameters = NULL;
  uint8_t buffer[TPM_MAX_COMMAND_LENGTH];
  int buffer_size = sizeof(buffer);
  void* auth1 = NULL;
  void* auth2 = NULL;
  RETURN_ON_FAILURE(TtlRunCommand(TSC_ORD_PhysicalPresence,
         1914, -1, in_parameters, out_parameters,
         auth1, auth2, buffer, buffer_size));
  return TPM_SUCCESS;
}

/* Sends a TSC_ResetEstablishmentBit command to the TPM and reads the response. */
uint32_t Ttl_TSC_ResetEstablishmentBit(void) {
  void* in_parameters = NULL;
  void* out_parameters = NULL;
  uint8_t buffer[TPM_MAX_COMMAND_LENGTH];
  int buffer_size = sizeof(buffer);
  void* auth1 = NULL;
  void* auth2 = NULL;
  RETURN_ON_FAILURE(TtlRunCommand(TSC_ORD_ResetEstablishmentBit,
         -1, -1, in_parameters, out_parameters,
         auth1, auth2, buffer, buffer_size));
  return TPM_SUCCESS;
}

/* Sends a TPM_GetCapability command to the TPM and reads the response. */
uint32_t Ttl_TPM_GetCapability(TPM_GetCapability_rqu* in_parameters, TPM_GetCapability_rsp* out_parameters, uint8_t* buffer, int buffer_size) {
  void* auth1 = NULL;
  void* auth2 = NULL;
  RETURN_ON_FAILURE(TtlRunCommand(TPM_ORD_GetCapability,
         1920, 1935, in_parameters, out_parameters,
         auth1, auth2, buffer, buffer_size));
  return TPM_SUCCESS;
}

/* Sends a TPM_SetCapability command to the TPM and reads the response. */
uint32_t Ttl_TPM_SetCapability(TPM_SetCapability_rqu* in_parameters, APSession* auth1) {
  void* out_parameters = NULL;
  uint8_t buffer[TPM_MAX_COMMAND_LENGTH];
  int buffer_size = sizeof(buffer);
  void* auth2 = NULL;
  RETURN_ON_FAILURE(TtlRunCommand(TPM_ORD_SetCapability,
         1946, -1, in_parameters, out_parameters,
         auth1, auth2, buffer, buffer_size));
  return TPM_SUCCESS;
}

/* Sends a TPM_GetCapabilityOwner command to the TPM and reads the response. */
uint32_t Ttl_TPM_GetCapabilityOwner(TPM_GetCapabilityOwner_rsp* out_parameters, uint8_t* buffer, int buffer_size, APSession* auth1) {
  void* in_parameters = NULL;
  void* auth2 = NULL;
  RETURN_ON_FAILURE(TtlRunCommand(TPM_ORD_GetCapabilityOwner,
         -1, 1970, in_parameters, out_parameters,
         auth1, auth2, buffer, buffer_size));
  return TPM_SUCCESS;
}

/* Sends a TPM_GetAuditDigest command to the TPM and reads the response. */
uint32_t Ttl_TPM_GetAuditDigest(TPM_GetAuditDigest_rqu* in_parameters, TPM_GetAuditDigest_rsp* out_parameters, uint8_t* buffer, int buffer_size) {
  void* auth1 = NULL;
  void* auth2 = NULL;
  RETURN_ON_FAILURE(TtlRunCommand(TPM_ORD_GetAuditDigest,
         1985, 1991, in_parameters, out_parameters,
         auth1, auth2, buffer, buffer_size));
  return TPM_SUCCESS;
}

/* Sends a TPM_GetAuditDigestSigned command to the TPM and reads the response. */
uint32_t Ttl_TPM_GetAuditDigestSigned(TPM_GetAuditDigestSigned_rqu* in_parameters, TPM_GetAuditDigestSigned_rsp* out_parameters, uint8_t* buffer, int buffer_size, APSession* auth1) {
  void* auth2 = NULL;
  RETURN_ON_FAILURE(TtlRunCommand(TPM_ORD_GetAuditDigestSigned,
         2016, 2031, in_parameters, out_parameters,
         auth1, auth2, buffer, buffer_size));
  return TPM_SUCCESS;
}

/* Sends a TPM_SetOrdinalAuditStatus command to the TPM and reads the response. */
uint32_t Ttl_TPM_SetOrdinalAuditStatus(TPM_SetOrdinalAuditStatus_rqu* in_parameters, APSession* auth1) {
  void* out_parameters = NULL;
  uint8_t buffer[TPM_MAX_COMMAND_LENGTH];
  int buffer_size = sizeof(buffer);
  void* auth2 = NULL;
  RETURN_ON_FAILURE(TtlRunCommand(TPM_ORD_SetOrdinalAuditStatus,
         2057, -1, in_parameters, out_parameters,
         auth1, auth2, buffer, buffer_size));
  return TPM_SUCCESS;
}

/* Sends a TPM_SetRedirection command to the TPM and reads the response. */
uint32_t Ttl_TPM_SetRedirection(TPM_SetRedirection_rqu* in_parameters, APSession* auth1) {
  void* out_parameters = NULL;
  uint8_t buffer[TPM_MAX_COMMAND_LENGTH];
  int buffer_size = sizeof(buffer);
  void* auth2 = NULL;
  RETURN_ON_FAILURE(TtlRunCommand(TPM_ORD_SetRedirection,
         2067, -1, in_parameters, out_parameters,
         auth1, auth2, buffer, buffer_size));
  return TPM_SUCCESS;
}

/* Sends a TPM_ResetLockValue command to the TPM and reads the response. */
uint32_t Ttl_TPM_ResetLockValue(APSession* auth1) {
  void* in_parameters = NULL;
  void* out_parameters = NULL;
  uint8_t buffer[TPM_MAX_COMMAND_LENGTH];
  int buffer_size = sizeof(buffer);
  void* auth2 = NULL;
  RETURN_ON_FAILURE(TtlRunCommand(TPM_ORD_ResetLockValue,
         -1, -1, in_parameters, out_parameters,
         auth1, auth2, buffer, buffer_size));
  return TPM_SUCCESS;
}

/* Sends a TPM_Seal command to the TPM and reads the response. */
uint32_t Ttl_TPM_Seal(TPM_Seal_rqu* in_parameters, TPM_Seal_rsp* out_parameters, uint8_t* buffer, int buffer_size, APSession* auth1) {
  void* auth2 = NULL;
  RETURN_ON_FAILURE(TtlRunCommand(TPM_ORD_Seal,
         2085, 2115, in_parameters, out_parameters,
         auth1, auth2, buffer, buffer_size));
  return TPM_SUCCESS;
}

/* Sends a TPM_Unseal command to the TPM and reads the response. */
uint32_t Ttl_TPM_Unseal(TPM_Unseal_rqu* in_parameters, TPM_Unseal_rsp* out_parameters, uint8_t* buffer, int buffer_size, APSession* auth1, APSession* auth2) {
  RETURN_ON_FAILURE(TtlRunCommand(TPM_ORD_Unseal,
         2123, 2135, in_parameters, out_parameters,
         auth1, auth2, buffer, buffer_size));
  return TPM_SUCCESS;
}

/* Sends a TPM_UnBind command to the TPM and reads the response. */
uint32_t Ttl_TPM_UnBind(TPM_UnBind_rqu* in_parameters, TPM_UnBind_rsp* out_parameters, uint8_t* buffer, int buffer_size, APSession* auth1) {
  void* auth2 = NULL;
  RETURN_ON_FAILURE(TtlRunCommand(TPM_ORD_UnBind,
         2146, 2161, in_parameters, out_parameters,
         auth1, auth2, buffer, buffer_size));
  return TPM_SUCCESS;
}

/* Sends a TPM_CreateWrapKey command to the TPM and reads the response. */
uint32_t Ttl_TPM_CreateWrapKey(TPM_CreateWrapKey_rqu* in_parameters, TPM_CreateWrapKey_rsp* out_parameters, uint8_t* buffer, int buffer_size, APSession* auth1) {
  void* auth2 = NULL;
  RETURN_ON_FAILURE(TtlRunCommand(TPM_ORD_CreateWrapKey,
         2172, 2194, in_parameters, out_parameters,
         auth1, auth2, buffer, buffer_size));
  return TPM_SUCCESS;
}

/* Sends a TPM_LoadKey2 command to the TPM and reads the response. */
uint32_t Ttl_TPM_LoadKey2(TPM_LoadKey2_rqu* in_parameters, TPM_LoadKey2_rsp* out_parameters, uint8_t* buffer, int buffer_size, APSession* auth1) {
  void* auth2 = NULL;
  RETURN_ON_FAILURE(TtlRunCommand(TPM_ORD_LoadKey2,
         2202, 2214, in_parameters, out_parameters,
         auth1, auth2, buffer, buffer_size));
  return TPM_SUCCESS;
}

/* Sends a TPM_GetPubKey command to the TPM and reads the response. */
uint32_t Ttl_TPM_GetPubKey(TPM_GetPubKey_rqu* in_parameters, TPM_GetPubKey_rsp* out_parameters, uint8_t* buffer, int buffer_size, APSession* auth1) {
  void* auth2 = NULL;
  RETURN_ON_FAILURE(TtlRunCommand(TPM_ORD_GetPubKey,
         2220, 2226, in_parameters, out_parameters,
         auth1, auth2, buffer, buffer_size));
  return TPM_SUCCESS;
}

/* Sends a TPM_Sealx command to the TPM and reads the response. */
uint32_t Ttl_TPM_Sealx(TPM_Sealx_rqu* in_parameters, TPM_Sealx_rsp* out_parameters, uint8_t* buffer, int buffer_size, APSession* auth1) {
  void* auth2 = NULL;
  RETURN_ON_FAILURE(TtlRunCommand(TPM_ORD_Sealx,
         2234, 2264, in_parameters, out_parameters,
         auth1, auth2, buffer, buffer_size));
  return TPM_SUCCESS;
}

/* Sends a TPM_CreateMigrationBlob command to the TPM and reads the response. */
uint32_t Ttl_TPM_CreateMigrationBlob(TPM_CreateMigrationBlob_rqu* in_parameters, TPM_CreateMigrationBlob_rsp* out_parameters, uint8_t* buffer, int buffer_size, APSession* auth1, APSession* auth2) {
  RETURN_ON_FAILURE(TtlRunCommand(TPM_ORD_CreateMigrationBlob,
         2272, 2297, in_parameters, out_parameters,
         auth1, auth2, buffer, buffer_size));
  return TPM_SUCCESS;
}

/* Sends a TPM_ConvertMigrationBlob command to the TPM and reads the response. */
uint32_t Ttl_TPM_ConvertMigrationBlob(TPM_ConvertMigrationBlob_rqu* in_parameters, TPM_ConvertMigrationBlob_rsp* out_parameters, uint8_t* buffer, int buffer_size, APSession* auth1) {
  void* auth2 = NULL;
  RETURN_ON_FAILURE(TtlRunCommand(TPM_ORD_ConvertMigrationBlob,
         2317, 2341, in_parameters, out_parameters,
         auth1, auth2, buffer, buffer_size));
  return TPM_SUCCESS;
}

/* Sends a TPM_AuthorizeMigrationKey command to the TPM and reads the response. */
uint32_t Ttl_TPM_AuthorizeMigrationKey(TPM_AuthorizeMigrationKey_rqu* in_parameters, TPM_AuthorizeMigrationKey_rsp* out_parameters, uint8_t* buffer, int buffer_size, APSession* auth1) {
  void* auth2 = NULL;
  RETURN_ON_FAILURE(TtlRunCommand(TPM_ORD_AuthorizeMigrationKey,
         2352, 2364, in_parameters, out_parameters,
         auth1, auth2, buffer, buffer_size));
  return TPM_SUCCESS;
}

/* Sends a TPM_MigrateKey command to the TPM and reads the response. */
uint32_t Ttl_TPM_MigrateKey(TPM_MigrateKey_rqu* in_parameters, TPM_MigrateKey_rsp* out_parameters, uint8_t* buffer, int buffer_size, APSession* auth1) {
  void* auth2 = NULL;
  RETURN_ON_FAILURE(TtlRunCommand(TPM_ORD_MigrateKey,
         2372, 2393, in_parameters, out_parameters,
         auth1, auth2, buffer, buffer_size));
  return TPM_SUCCESS;
}

/* Sends a TPM_CMK_SetRestrictions command to the TPM and reads the response. */
uint32_t Ttl_TPM_CMK_SetRestrictions(TPM_CMK_SetRestrictions_rqu* in_parameters, APSession* auth1) {
  void* out_parameters = NULL;
  uint8_t buffer[TPM_MAX_COMMAND_LENGTH];
  int buffer_size = sizeof(buffer);
  void* auth2 = NULL;
  RETURN_ON_FAILURE(TtlRunCommand(TPM_ORD_CMK_SetRestrictions,
         2404, -1, in_parameters, out_parameters,
         auth1, auth2, buffer, buffer_size));
  return TPM_SUCCESS;
}

/* Sends a TPM_CMK_ApproveMA command to the TPM and reads the response. */
uint32_t Ttl_TPM_CMK_ApproveMA(TPM_CMK_ApproveMA_rqu* in_parameters, TPM_CMK_ApproveMA_rsp* out_parameters, uint8_t* buffer, int buffer_size, APSession* auth1) {
  void* auth2 = NULL;
  RETURN_ON_FAILURE(TtlRunCommand(TPM_ORD_CMK_ApproveMA,
         2410, 2417, in_parameters, out_parameters,
         auth1, auth2, buffer, buffer_size));
  return TPM_SUCCESS;
}

/* Sends a TPM_CMK_CreateKey command to the TPM and reads the response. */
uint32_t Ttl_TPM_CMK_CreateKey(TPM_CMK_CreateKey_rqu* in_parameters, TPM_CMK_CreateKey_rsp* out_parameters, uint8_t* buffer, int buffer_size, APSession* auth1) {
  void* auth2 = NULL;
  RETURN_ON_FAILURE(TtlRunCommand(TPM_ORD_CMK_CreateKey,
         2424, 2451, in_parameters, out_parameters,
         auth1, auth2, buffer, buffer_size));
  return TPM_SUCCESS;
}

/* Sends a TPM_CMK_CreateTicket command to the TPM and reads the response. */
uint32_t Ttl_TPM_CMK_CreateTicket(TPM_CMK_CreateTicket_rqu* in_parameters, TPM_CMK_CreateTicket_rsp* out_parameters, uint8_t* buffer, int buffer_size, APSession* auth1) {
  void* auth2 = NULL;
  RETURN_ON_FAILURE(TtlRunCommand(TPM_ORD_CMK_CreateTicket,
         2459, 2481, in_parameters, out_parameters,
         auth1, auth2, buffer, buffer_size));
  return TPM_SUCCESS;
}

/* Sends a TPM_CMK_CreateBlob command to the TPM and reads the response. */
uint32_t Ttl_TPM_CMK_CreateBlob(TPM_CMK_CreateBlob_rqu* in_parameters, TPM_CMK_CreateBlob_rsp* out_parameters, uint8_t* buffer, int buffer_size, APSession* auth1) {
  void* auth2 = NULL;
  RETURN_ON_FAILURE(TtlRunCommand(TPM_ORD_CMK_CreateBlob,
         2488, 2550, in_parameters, out_parameters,
         auth1, auth2, buffer, buffer_size));
  return TPM_SUCCESS;
}

/* Sends a TPM_CMK_ConvertMigration command to the TPM and reads the response. */
uint32_t Ttl_TPM_CMK_ConvertMigration(TPM_CMK_ConvertMigration_rqu* in_parameters, TPM_CMK_ConvertMigration_rsp* out_parameters, uint8_t* buffer, int buffer_size, APSession* auth1) {
  void* auth2 = NULL;
  RETURN_ON_FAILURE(TtlRunCommand(TPM_ORD_CMK_ConvertMigration,
         2570, 2621, in_parameters, out_parameters,
         auth1, auth2, buffer, buffer_size));
  return TPM_SUCCESS;
}

/* Sends a TPM_CreateMaintenanceArchive command to the TPM and reads the response. */
uint32_t Ttl_TPM_CreateMaintenanceArchive(TPM_CreateMaintenanceArchive_rqu* in_parameters, TPM_CreateMaintenanceArchive_rsp* out_parameters, uint8_t* buffer, int buffer_size, APSession* auth1) {
  void* auth2 = NULL;
  RETURN_ON_FAILURE(TtlRunCommand(TPM_ORD_CreateMaintenanceArchive,
         2632, 2638, in_parameters, out_parameters,
         auth1, auth2, buffer, buffer_size));
  return TPM_SUCCESS;
}

/* Sends a TPM_LoadMaintenanceArchive command to the TPM and reads the response. */
uint32_t Ttl_TPM_LoadMaintenanceArchive(TPM_LoadMaintenanceArchive_rqu* in_parameters, APSession* auth1) {
  void* out_parameters = NULL;
  uint8_t buffer[TPM_MAX_COMMAND_LENGTH];
  int buffer_size = sizeof(buffer);
  void* auth2 = NULL;
  RETURN_ON_FAILURE(TtlRunCommand(TPM_ORD_LoadMaintenanceArchive,
         2658, -1, in_parameters, out_parameters,
         auth1, auth2, buffer, buffer_size));
  return TPM_SUCCESS;
}

/* Sends a TPM_KillMaintenanceFeature command to the TPM and reads the response. */
uint32_t Ttl_TPM_KillMaintenanceFeature(APSession* auth1) {
  void* in_parameters = NULL;
  void* out_parameters = NULL;
  uint8_t buffer[TPM_MAX_COMMAND_LENGTH];
  int buffer_size = sizeof(buffer);
  void* auth2 = NULL;
  RETURN_ON_FAILURE(TtlRunCommand(TPM_ORD_KillMaintenanceFeature,
         -1, -1, in_parameters, out_parameters,
         auth1, auth2, buffer, buffer_size));
  return TPM_SUCCESS;
}

/* Sends a TPM_LoadManuMaintPub command to the TPM and reads the response. */
uint32_t Ttl_TPM_LoadManuMaintPub(TPM_LoadManuMaintPub_rqu* in_parameters, TPM_LoadManuMaintPub_rsp* out_parameters, uint8_t* buffer, int buffer_size) {
  void* auth1 = NULL;
  void* auth2 = NULL;
  RETURN_ON_FAILURE(TtlRunCommand(TPM_ORD_LoadManuMaintPub,
         2669, 2682, in_parameters, out_parameters,
         auth1, auth2, buffer, buffer_size));
  return TPM_SUCCESS;
}

/* Sends a TPM_ReadManuMaintPub command to the TPM and reads the response. */
uint32_t Ttl_TPM_ReadManuMaintPub(TPM_ReadManuMaintPub_rqu* in_parameters, TPM_ReadManuMaintPub_rsp* out_parameters, uint8_t* buffer, int buffer_size) {
  void* auth1 = NULL;
  void* auth2 = NULL;
  RETURN_ON_FAILURE(TtlRunCommand(TPM_ORD_ReadManuMaintPub,
         2689, 2696, in_parameters, out_parameters,
         auth1, auth2, buffer, buffer_size));
  return TPM_SUCCESS;
}

/* Sends a TPM_SHA1Start command to the TPM and reads the response. */
uint32_t Ttl_TPM_SHA1Start(TPM_SHA1Start_rsp* out_parameters, uint8_t* buffer, int buffer_size) {
  void* in_parameters = NULL;
  void* auth1 = NULL;
  void* auth2 = NULL;
  RETURN_ON_FAILURE(TtlRunCommand(TPM_ORD_SHA1Start,
         -1, 2703, in_parameters, out_parameters,
         auth1, auth2, buffer, buffer_size));
  return TPM_SUCCESS;
}

/* Sends a TPM_SHA1Update command to the TPM and reads the response. */
uint32_t Ttl_TPM_SHA1Update(TPM_SHA1Update_rqu* in_parameters) {
  void* out_parameters = NULL;
  uint8_t buffer[TPM_MAX_COMMAND_LENGTH];
  int buffer_size = sizeof(buffer);
  void* auth1 = NULL;
  void* auth2 = NULL;
  RETURN_ON_FAILURE(TtlRunCommand(TPM_ORD_SHA1Update,
         2709, -1, in_parameters, out_parameters,
         auth1, auth2, buffer, buffer_size));
  return TPM_SUCCESS;
}

/* Sends a TPM_SHA1Complete command to the TPM and reads the response. */
uint32_t Ttl_TPM_SHA1Complete(TPM_SHA1Complete_rqu* in_parameters, TPM_SHA1Complete_rsp* out_parameters, uint8_t* buffer, int buffer_size) {
  void* auth1 = NULL;
  void* auth2 = NULL;
  RETURN_ON_FAILURE(TtlRunCommand(TPM_ORD_SHA1Complete,
         2720, 2731, in_parameters, out_parameters,
         auth1, auth2, buffer, buffer_size));
  return TPM_SUCCESS;
}

/* Sends a TPM_SHA1CompleteExtend command to the TPM and reads the response. */
uint32_t Ttl_TPM_SHA1CompleteExtend(TPM_SHA1CompleteExtend_rqu* in_parameters, TPM_SHA1CompleteExtend_rsp* out_parameters, uint8_t* buffer, int buffer_size) {
  void* auth1 = NULL;
  void* auth2 = NULL;
  RETURN_ON_FAILURE(TtlRunCommand(TPM_ORD_SHA1CompleteExtend,
         2738, 2753, in_parameters, out_parameters,
         auth1, auth2, buffer, buffer_size));
  return TPM_SUCCESS;
}

/* Sends a TPM_Sign command to the TPM and reads the response. */
uint32_t Ttl_TPM_Sign(TPM_Sign_rqu* in_parameters, TPM_Sign_rsp* out_parameters, uint8_t* buffer, int buffer_size, APSession* auth1) {
  void* auth2 = NULL;
  RETURN_ON_FAILURE(TtlRunCommand(TPM_ORD_Sign,
         2765, 2780, in_parameters, out_parameters,
         auth1, auth2, buffer, buffer_size));
  return TPM_SUCCESS;
}

/* Sends a TPM_GetRandom command to the TPM and reads the response. */
uint32_t Ttl_TPM_GetRandom(TPM_GetRandom_rqu* in_parameters, TPM_GetRandom_rsp* out_parameters, uint8_t* buffer, int buffer_size) {
  void* auth1 = NULL;
  void* auth2 = NULL;
  RETURN_ON_FAILURE(TtlRunCommand(TPM_ORD_GetRandom,
         2791, 2797, in_parameters, out_parameters,
         auth1, auth2, buffer, buffer_size));
  return TPM_SUCCESS;
}

/* Sends a TPM_StirRandom command to the TPM and reads the response. */
uint32_t Ttl_TPM_StirRandom(TPM_StirRandom_rqu* in_parameters) {
  void* out_parameters = NULL;
  uint8_t buffer[TPM_MAX_COMMAND_LENGTH];
  int buffer_size = sizeof(buffer);
  void* auth1 = NULL;
  void* auth2 = NULL;
  RETURN_ON_FAILURE(TtlRunCommand(TPM_ORD_StirRandom,
         2808, -1, in_parameters, out_parameters,
         auth1, auth2, buffer, buffer_size));
  return TPM_SUCCESS;
}

/* Sends a TPM_CertifyKey command to the TPM and reads the response. */
uint32_t Ttl_TPM_CertifyKey(TPM_CertifyKey_rqu* in_parameters, TPM_CertifyKey_rsp* out_parameters, uint8_t* buffer, int buffer_size, APSession* auth1, APSession* auth2) {
  RETURN_ON_FAILURE(TtlRunCommand(TPM_ORD_CertifyKey,
         2819, 2834, in_parameters, out_parameters,
         auth1, auth2, buffer, buffer_size));
  return TPM_SUCCESS;
}

/* Sends a TPM_CertifyKey2 command to the TPM and reads the response. */
uint32_t Ttl_TPM_CertifyKey2(TPM_CertifyKey2_rqu* in_parameters, TPM_CertifyKey2_rsp* out_parameters, uint8_t* buffer, int buffer_size, APSession* auth1, APSession* auth2) {
  RETURN_ON_FAILURE(TtlRunCommand(TPM_ORD_CertifyKey2,
         2857, 2877, in_parameters, out_parameters,
         auth1, auth2, buffer, buffer_size));
  return TPM_SUCCESS;
}

/* Sends a TPM_CreateEndorsementKeyPair command to the TPM and reads the response. */
uint32_t Ttl_TPM_CreateEndorsementKeyPair(TPM_CreateEndorsementKeyPair_rqu* in_parameters, TPM_CreateEndorsementKeyPair_rsp* out_parameters, uint8_t* buffer, int buffer_size) {
  void* auth1 = NULL;
  void* auth2 = NULL;
  RETURN_ON_FAILURE(TtlRunCommand(TPM_ORD_CreateEndorsementKeyPair,
         2900, 2913, in_parameters, out_parameters,
         auth1, auth2, buffer, buffer_size));
  return TPM_SUCCESS;
}

/* Sends a TPM_CreateRevocableEK command to the TPM and reads the response. */
uint32_t Ttl_TPM_CreateRevocableEK(TPM_CreateRevocableEK_rqu* in_parameters, TPM_CreateRevocableEK_rsp* out_parameters, uint8_t* buffer, int buffer_size) {
  void* auth1 = NULL;
  void* auth2 = NULL;
  RETURN_ON_FAILURE(TtlRunCommand(TPM_ORD_CreateRevocableEK,
         2926, 2948, in_parameters, out_parameters,
         auth1, auth2, buffer, buffer_size));
  return TPM_SUCCESS;
}

/* Sends a TPM_RevokeTrust command to the TPM and reads the response. */
uint32_t Ttl_TPM_RevokeTrust(TPM_RevokeTrust_rqu* in_parameters) {
  void* out_parameters = NULL;
  uint8_t buffer[TPM_MAX_COMMAND_LENGTH];
  int buffer_size = sizeof(buffer);
  void* auth1 = NULL;
  void* auth2 = NULL;
  RETURN_ON_FAILURE(TtlRunCommand(TPM_ORD_RevokeTrust,
         2966, -1, in_parameters, out_parameters,
         auth1, auth2, buffer, buffer_size));
  return TPM_SUCCESS;
}

/* Sends a TPM_ReadPubek command to the TPM and reads the response. */
uint32_t Ttl_TPM_ReadPubek(TPM_ReadPubek_rqu* in_parameters, TPM_ReadPubek_rsp* out_parameters, uint8_t* buffer, int buffer_size) {
  void* auth1 = NULL;
  void* auth2 = NULL;
  RETURN_ON_FAILURE(TtlRunCommand(TPM_ORD_ReadPubek,
         2973, 2980, in_parameters, out_parameters,
         auth1, auth2, buffer, buffer_size));
  return TPM_SUCCESS;
}

/* Sends a TPM_OwnerReadInternalPub command to the TPM and reads the response. */
uint32_t Ttl_TPM_OwnerReadInternalPub(TPM_OwnerReadInternalPub_rqu* in_parameters, TPM_OwnerReadInternalPub_rsp* out_parameters, uint8_t* buffer, int buffer_size, APSession* auth1) {
  void* auth2 = NULL;
  RETURN_ON_FAILURE(TtlRunCommand(TPM_ORD_OwnerReadInternalPub,
         2993, 2999, in_parameters, out_parameters,
         auth1, auth2, buffer, buffer_size));
  return TPM_SUCCESS;
}

/* Sends a TPM_MakeIdentity command to the TPM and reads the response. */
uint32_t Ttl_TPM_MakeIdentity(TPM_MakeIdentity_rqu* in_parameters, TPM_MakeIdentity_rsp* out_parameters, uint8_t* buffer, int buffer_size, APSession* auth1, APSession* auth2) {
  RETURN_ON_FAILURE(TtlRunCommand(TPM_ORD_MakeIdentity,
         3007, 3025, in_parameters, out_parameters,
         auth1, auth2, buffer, buffer_size));
  return TPM_SUCCESS;
}

/* Sends a TPM_ActivateIdentity command to the TPM and reads the response. */
uint32_t Ttl_TPM_ActivateIdentity(TPM_ActivateIdentity_rqu* in_parameters, TPM_ActivateIdentity_rsp* out_parameters, uint8_t* buffer, int buffer_size, APSession* auth1, APSession* auth2) {
  RETURN_ON_FAILURE(TtlRunCommand(TPM_ORD_ActivateIdentity,
         3042, 3057, in_parameters, out_parameters,
         auth1, auth2, buffer, buffer_size));
  return TPM_SUCCESS;
}

/* Sends a TPM_Extend command to the TPM and reads the response. */
uint32_t Ttl_TPM_Extend(TPM_Extend_rqu* in_parameters, TPM_Extend_rsp* out_parameters, uint8_t* buffer, int buffer_size) {
  void* auth1 = NULL;
  void* auth2 = NULL;
  RETURN_ON_FAILURE(TtlRunCommand(TPM_ORD_Extend,
         3065, 3076, in_parameters, out_parameters,
         auth1, auth2, buffer, buffer_size));
  return TPM_SUCCESS;
}

/* Sends a TPM_PCRRead command to the TPM and reads the response. */
uint32_t Ttl_TPM_PCRRead(TPM_PCRRead_rqu* in_parameters, TPM_PCRRead_rsp* out_parameters, uint8_t* buffer, int buffer_size) {
  void* auth1 = NULL;
  void* auth2 = NULL;
  RETURN_ON_FAILURE(TtlRunCommand(TPM_ORD_PCRRead,
         3083, 3089, in_parameters, out_parameters,
         auth1, auth2, buffer, buffer_size));
  return TPM_SUCCESS;
}

/* Sends a TPM_Quote command to the TPM and reads the response. */
uint32_t Ttl_TPM_Quote(TPM_Quote_rqu* in_parameters, TPM_Quote_rsp* out_parameters, uint8_t* buffer, int buffer_size, APSession* auth1) {
  void* auth2 = NULL;
  RETURN_ON_FAILURE(TtlRunCommand(TPM_ORD_Quote,
         3096, 3113, in_parameters, out_parameters,
         auth1, auth2, buffer, buffer_size));
  return TPM_SUCCESS;
}

/* Sends a TPM_PCR_Reset command to the TPM and reads the response. */
uint32_t Ttl_TPM_PCR_Reset(TPM_PCR_Reset_rqu* in_parameters) {
  void* out_parameters = NULL;
  uint8_t buffer[TPM_MAX_COMMAND_LENGTH];
  int buffer_size = sizeof(buffer);
  void* auth1 = NULL;
  void* auth2 = NULL;
  RETURN_ON_FAILURE(TtlRunCommand(TPM_ORD_PCR_Reset,
         3130, -1, in_parameters, out_parameters,
         auth1, auth2, buffer, buffer_size));
  return TPM_SUCCESS;
}

/* Sends a TPM_Quote2 command to the TPM and reads the response. */
uint32_t Ttl_TPM_Quote2(TPM_Quote2_rqu* in_parameters, TPM_Quote2_rsp* out_parameters, uint8_t* buffer, int buffer_size, APSession* auth1) {
  void* auth2 = NULL;
  RETURN_ON_FAILURE(TtlRunCommand(TPM_ORD_Quote2,
         3138, 3159, in_parameters, out_parameters,
         auth1, auth2, buffer, buffer_size));
  return TPM_SUCCESS;
}

/* Sends a TPM_ChangeAuth command to the TPM and reads the response. */
uint32_t Ttl_TPM_ChangeAuth(TPM_ChangeAuth_rqu* in_parameters, TPM_ChangeAuth_rsp* out_parameters, uint8_t* buffer, int buffer_size, APSession* auth1, APSession* auth2) {
  RETURN_ON_FAILURE(TtlRunCommand(TPM_ORD_ChangeAuth,
         3186, 3214, in_parameters, out_parameters,
         auth1, auth2, buffer, buffer_size));
  return TPM_SUCCESS;
}

/* Sends a TPM_ChangeAuthOwner command to the TPM and reads the response. */
uint32_t Ttl_TPM_ChangeAuthOwner(TPM_ChangeAuthOwner_rqu* in_parameters, APSession* auth1) {
  void* out_parameters = NULL;
  uint8_t buffer[TPM_MAX_COMMAND_LENGTH];
  int buffer_size = sizeof(buffer);
  void* auth2 = NULL;
  RETURN_ON_FAILURE(TtlRunCommand(TPM_ORD_ChangeAuthOwner,
         3225, -1, in_parameters, out_parameters,
         auth1, auth2, buffer, buffer_size));
  return TPM_SUCCESS;
}

/* Sends a TPM_OIAP command to the TPM and reads the response. */
uint32_t Ttl_TPM_OIAP(TPM_OIAP_rsp* out_parameters, uint8_t* buffer, int buffer_size) {
  void* in_parameters = NULL;
  void* auth1 = NULL;
  void* auth2 = NULL;
  RETURN_ON_FAILURE(TtlRunCommand(TPM_ORD_OIAP,
         -1, 3240, in_parameters, out_parameters,
         auth1, auth2, buffer, buffer_size));
  return TPM_SUCCESS;
}

/* Sends a TPM_OSAP command to the TPM and reads the response. */
uint32_t Ttl_TPM_OSAP(TPM_OSAP_rqu* in_parameters, TPM_OSAP_rsp* out_parameters, uint8_t* buffer, int buffer_size) {
  void* auth1 = NULL;
  void* auth2 = NULL;
  RETURN_ON_FAILURE(TtlRunCommand(TPM_ORD_OSAP,
         3251, 3266, in_parameters, out_parameters,
         auth1, auth2, buffer, buffer_size));
  return TPM_SUCCESS;
}

/* Sends a TPM_DSAP command to the TPM and reads the response. */
uint32_t Ttl_TPM_DSAP(TPM_DSAP_rqu* in_parameters, TPM_DSAP_rsp* out_parameters, uint8_t* buffer, int buffer_size) {
  void* auth1 = NULL;
  void* auth2 = NULL;
  RETURN_ON_FAILURE(TtlRunCommand(TPM_ORD_DSAP,
         3282, 3306, in_parameters, out_parameters,
         auth1, auth2, buffer, buffer_size));
  return TPM_SUCCESS;
}

/* Sends a TPM_SetOwnerPointer command to the TPM and reads the response. */
uint32_t Ttl_TPM_SetOwnerPointer(TPM_SetOwnerPointer_rqu* in_parameters) {
  void* out_parameters = NULL;
  uint8_t buffer[TPM_MAX_COMMAND_LENGTH];
  int buffer_size = sizeof(buffer);
  void* auth1 = NULL;
  void* auth2 = NULL;
  RETURN_ON_FAILURE(TtlRunCommand(TPM_ORD_SetOwnerPointer,
         3322, -1, in_parameters, out_parameters,
         auth1, auth2, buffer, buffer_size));
  return TPM_SUCCESS;
}

/* Sends a TPM_Delegate_Manage command to the TPM and reads the response. */
uint32_t Ttl_TPM_Delegate_Manage(TPM_Delegate_Manage_rqu* in_parameters, TPM_Delegate_Manage_rsp* out_parameters, uint8_t* buffer, int buffer_size, APSession* auth1) {
  void* auth2 = NULL;
  RETURN_ON_FAILURE(TtlRunCommand(TPM_ORD_Delegate_Manage,
         3332, 3351, in_parameters, out_parameters,
         auth1, auth2, buffer, buffer_size));
  return TPM_SUCCESS;
}

/* Sends a TPM_Delegate_CreateKeyDelegation command to the TPM and reads the response. */
uint32_t Ttl_TPM_Delegate_CreateKeyDelegation(TPM_Delegate_CreateKeyDelegation_rqu* in_parameters, TPM_Delegate_CreateKeyDelegation_rsp* out_parameters, uint8_t* buffer, int buffer_size, APSession* auth1) {
  void* auth2 = NULL;
  RETURN_ON_FAILURE(TtlRunCommand(TPM_ORD_Delegate_CreateKeyDelegation,
         3362, 3379, in_parameters, out_parameters,
         auth1, auth2, buffer, buffer_size));
  return TPM_SUCCESS;
}

/* Sends a TPM_Delegate_CreateOwnerDelegation command to the TPM and reads the response. */
uint32_t Ttl_TPM_Delegate_CreateOwnerDelegation(TPM_Delegate_CreateOwnerDelegation_rqu* in_parameters, TPM_Delegate_CreateOwnerDelegation_rsp* out_parameters, uint8_t* buffer, int buffer_size, APSession* auth1) {
  void* auth2 = NULL;
  RETURN_ON_FAILURE(TtlRunCommand(TPM_ORD_Delegate_CreateOwnerDelegation,
         3391, 3408, in_parameters, out_parameters,
         auth1, auth2, buffer, buffer_size));
  return TPM_SUCCESS;
}

/* Sends a TPM_Delegate_LoadOwnerDelegation command to the TPM and reads the response. */
uint32_t Ttl_TPM_Delegate_LoadOwnerDelegation(TPM_Delegate_LoadOwnerDelegation_rqu* in_parameters, APSession* auth1) {
  void* out_parameters = NULL;
  uint8_t buffer[TPM_MAX_COMMAND_LENGTH];
  int buffer_size = sizeof(buffer);
  void* auth2 = NULL;
  RETURN_ON_FAILURE(TtlRunCommand(TPM_ORD_Delegate_LoadOwnerDelegation,
         3420, -1, in_parameters, out_parameters,
         auth1, auth2, buffer, buffer_size));
  return TPM_SUCCESS;
}

/* Sends a TPM_Delegate_ReadTable command to the TPM and reads the response. */
uint32_t Ttl_TPM_Delegate_ReadTable(TPM_Delegate_ReadTable_rsp* out_parameters, uint8_t* buffer, int buffer_size) {
  void* in_parameters = NULL;
  void* auth1 = NULL;
  void* auth2 = NULL;
  RETURN_ON_FAILURE(TtlRunCommand(TPM_ORD_Delegate_ReadTable,
         -1, 3436, in_parameters, out_parameters,
         auth1, auth2, buffer, buffer_size));
  return TPM_SUCCESS;
}

/* Sends a TPM_Delegate_UpdateVerification command to the TPM and reads the response. */
uint32_t Ttl_TPM_Delegate_UpdateVerification(TPM_Delegate_UpdateVerification_rqu* in_parameters, TPM_Delegate_UpdateVerification_rsp* out_parameters, uint8_t* buffer, int buffer_size, APSession* auth1) {
  void* auth2 = NULL;
  RETURN_ON_FAILURE(TtlRunCommand(TPM_ORD_Delegate_UpdateVerification,
         3456, 3472, in_parameters, out_parameters,
         auth1, auth2, buffer, buffer_size));
  return TPM_SUCCESS;
}

/* Sends a TPM_Delegate_VerifyDelegation command to the TPM and reads the response. */
uint32_t Ttl_TPM_Delegate_VerifyDelegation(TPM_Delegate_VerifyDelegation_rqu* in_parameters) {
  void* out_parameters = NULL;
  uint8_t buffer[TPM_MAX_COMMAND_LENGTH];
  int buffer_size = sizeof(buffer);
  void* auth1 = NULL;
  void* auth2 = NULL;
  RETURN_ON_FAILURE(TtlRunCommand(TPM_ORD_Delegate_VerifyDelegation,
         3488, -1, in_parameters, out_parameters,
         auth1, auth2, buffer, buffer_size));
  return TPM_SUCCESS;
}

/* Sends a TPM_NV_DefineSpace command to the TPM and reads the response. */
uint32_t Ttl_TPM_NV_DefineSpace(TPM_NV_DefineSpace_rqu* in_parameters, APSession* auth1) {
  void* out_parameters = NULL;
  uint8_t buffer[TPM_MAX_COMMAND_LENGTH];
  int buffer_size = sizeof(buffer);
  void* auth2 = NULL;
  RETURN_ON_FAILURE(TtlRunCommand(TPM_ORD_NV_DefineSpace,
         3505, -1, in_parameters, out_parameters,
         auth1, auth2, buffer, buffer_size));
  return TPM_SUCCESS;
}

/* Sends a TPM_NV_WriteValue command to the TPM and reads the response. */
uint32_t Ttl_TPM_NV_WriteValue(TPM_NV_WriteValue_rqu* in_parameters, APSession* auth1) {
  void* out_parameters = NULL;
  uint8_t buffer[TPM_MAX_COMMAND_LENGTH];
  int buffer_size = sizeof(buffer);
  void* auth2 = NULL;
  RETURN_ON_FAILURE(TtlRunCommand(TPM_ORD_NV_WriteValue,
         3518, -1, in_parameters, out_parameters,
         auth1, auth2, buffer, buffer_size));
  return TPM_SUCCESS;
}

/* Sends a TPM_NV_WriteValueAuth command to the TPM and reads the response. */
uint32_t Ttl_TPM_NV_WriteValueAuth(TPM_NV_WriteValueAuth_rqu* in_parameters, APSession* auth1) {
  void* out_parameters = NULL;
  uint8_t buffer[TPM_MAX_COMMAND_LENGTH];
  int buffer_size = sizeof(buffer);
  void* auth2 = NULL;
  RETURN_ON_FAILURE(TtlRunCommand(TPM_ORD_NV_WriteValueAuth,
         3537, -1, in_parameters, out_parameters,
         auth1, auth2, buffer, buffer_size));
  return TPM_SUCCESS;
}

/* Sends a TPM_NV_ReadValue command to the TPM and reads the response. */
uint32_t Ttl_TPM_NV_ReadValue(TPM_NV_ReadValue_rqu* in_parameters, TPM_NV_ReadValue_rsp* out_parameters, uint8_t* buffer, int buffer_size, APSession* auth1) {
  void* auth2 = NULL;
  RETURN_ON_FAILURE(TtlRunCommand(TPM_ORD_NV_ReadValue,
         3555, 3569, in_parameters, out_parameters,
         auth1, auth2, buffer, buffer_size));
  return TPM_SUCCESS;
}

/* Sends a TPM_NV_ReadValueAuth command to the TPM and reads the response. */
uint32_t Ttl_TPM_NV_ReadValueAuth(TPM_NV_ReadValueAuth_rqu* in_parameters, TPM_NV_ReadValueAuth_rsp* out_parameters, uint8_t* buffer, int buffer_size, APSession* auth1) {
  void* auth2 = NULL;
  RETURN_ON_FAILURE(TtlRunCommand(TPM_ORD_NV_ReadValueAuth,
         3580, 3590, in_parameters, out_parameters,
         auth1, auth2, buffer, buffer_size));
  return TPM_SUCCESS;
}

/* Sends a TPM_KeyControlOwner command to the TPM and reads the response. */
uint32_t Ttl_TPM_KeyControlOwner(TPM_KeyControlOwner_rqu* in_parameters, APSession* auth1) {
  void* out_parameters = NULL;
  uint8_t buffer[TPM_MAX_COMMAND_LENGTH];
  int buffer_size = sizeof(buffer);
  void* auth2 = NULL;
  RETURN_ON_FAILURE(TtlRunCommand(TPM_ORD_KeyControlOwner,
         3601, -1, in_parameters, out_parameters,
         auth1, auth2, buffer, buffer_size));
  return TPM_SUCCESS;
}

/* Sends a TPM_SaveContext command to the TPM and reads the response. */
uint32_t Ttl_TPM_SaveContext(TPM_SaveContext_rqu* in_parameters, TPM_SaveContext_rsp* out_parameters, uint8_t* buffer, int buffer_size) {
  void* auth1 = NULL;
  void* auth2 = NULL;
  RETURN_ON_FAILURE(TtlRunCommand(TPM_ORD_SaveContext,
         3621, 3639, in_parameters, out_parameters,
         auth1, auth2, buffer, buffer_size));
  return TPM_SUCCESS;
}

/* Sends a TPM_LoadContext command to the TPM and reads the response. */
uint32_t Ttl_TPM_LoadContext(TPM_LoadContext_rqu* in_parameters, TPM_LoadContext_rsp* out_parameters, uint8_t* buffer, int buffer_size) {
  void* auth1 = NULL;
  void* auth2 = NULL;
  RETURN_ON_FAILURE(TtlRunCommand(TPM_ORD_LoadContext,
         3647, 3667, in_parameters, out_parameters,
         auth1, auth2, buffer, buffer_size));
  return TPM_SUCCESS;
}

/* Sends a TPM_FlushSpecific command to the TPM and reads the response. */
uint32_t Ttl_TPM_FlushSpecific(TPM_FlushSpecific_rqu* in_parameters) {
  void* out_parameters = NULL;
  uint8_t buffer[TPM_MAX_COMMAND_LENGTH];
  int buffer_size = sizeof(buffer);
  void* auth1 = NULL;
  void* auth2 = NULL;
  RETURN_ON_FAILURE(TtlRunCommand(TPM_ORD_FlushSpecific,
         3673, -1, in_parameters, out_parameters,
         auth1, auth2, buffer, buffer_size));
  return TPM_SUCCESS;
}

/* Sends a TPM_GetTicks command to the TPM and reads the response. */
uint32_t Ttl_TPM_GetTicks(TPM_GetTicks_rsp* out_parameters, uint8_t* buffer, int buffer_size) {
  void* in_parameters = NULL;
  void* auth1 = NULL;
  void* auth2 = NULL;
  RETURN_ON_FAILURE(TtlRunCommand(TPM_ORD_GetTicks,
         -1, 3683, in_parameters, out_parameters,
         auth1, auth2, buffer, buffer_size));
  return TPM_SUCCESS;
}

/* Sends a TPM_TickStampBlob command to the TPM and reads the response. */
uint32_t Ttl_TPM_TickStampBlob(TPM_TickStampBlob_rqu* in_parameters, TPM_TickStampBlob_rsp* out_parameters, uint8_t* buffer, int buffer_size, APSession* auth1) {
  void* auth2 = NULL;
  RETURN_ON_FAILURE(TtlRunCommand(TPM_ORD_TickStampBlob,
         3691, 3707, in_parameters, out_parameters,
         auth1, auth2, buffer, buffer_size));
  return TPM_SUCCESS;
}

/* Sends a TPM_EstablishTransport command to the TPM and reads the response. */
uint32_t Ttl_TPM_EstablishTransport(TPM_EstablishTransport_rqu* in_parameters, TPM_EstablishTransport_rsp* out_parameters, uint8_t* buffer, int buffer_size, APSession* auth1) {
  void* auth2 = NULL;
  RETURN_ON_FAILURE(TtlRunCommand(TPM_ORD_EstablishTransport,
         3724, 3745, in_parameters, out_parameters,
         auth1, auth2, buffer, buffer_size));
  return TPM_SUCCESS;
}

/* Sends a TPM_ExecuteTransport command to the TPM and reads the response. */
uint32_t Ttl_TPM_ExecuteTransport(TPM_ExecuteTransport_rqu* in_parameters, TPM_ExecuteTransport_rsp* out_parameters, uint8_t* buffer, int buffer_size, APSession* auth1) {
  void* auth2 = NULL;
  RETURN_ON_FAILURE(TtlRunCommand(TPM_ORD_ExecuteTransport,
         3766, 3777, in_parameters, out_parameters,
         auth1, auth2, buffer, buffer_size));
  return TPM_SUCCESS;
}

/* Sends a TPM_ReleaseTransportSigned command to the TPM and reads the response. */
uint32_t Ttl_TPM_ReleaseTransportSigned(TPM_ReleaseTransportSigned_rqu* in_parameters, TPM_ReleaseTransportSigned_rsp* out_parameters, uint8_t* buffer, int buffer_size, APSession* auth1, APSession* auth2) {
  RETURN_ON_FAILURE(TtlRunCommand(TPM_ORD_ReleaseTransportSigned,
         3796, 3807, in_parameters, out_parameters,
         auth1, auth2, buffer, buffer_size));
  return TPM_SUCCESS;
}

/* Sends a TPM_CreateCounter command to the TPM and reads the response. */
uint32_t Ttl_TPM_CreateCounter(TPM_CreateCounter_rqu* in_parameters, TPM_CreateCounter_rsp* out_parameters, uint8_t* buffer, int buffer_size, APSession* auth1) {
  void* auth2 = NULL;
  RETURN_ON_FAILURE(TtlRunCommand(TPM_ORD_CreateCounter,
         3828, 3839, in_parameters, out_parameters,
         auth1, auth2, buffer, buffer_size));
  return TPM_SUCCESS;
}

/* Sends a TPM_IncrementCounter command to the TPM and reads the response. */
uint32_t Ttl_TPM_IncrementCounter(TPM_IncrementCounter_rqu* in_parameters, TPM_IncrementCounter_rsp* out_parameters, uint8_t* buffer, int buffer_size, APSession* auth1) {
  void* auth2 = NULL;
  RETURN_ON_FAILURE(TtlRunCommand(TPM_ORD_IncrementCounter,
         3850, 3856, in_parameters, out_parameters,
         auth1, auth2, buffer, buffer_size));
  return TPM_SUCCESS;
}

/* Sends a TPM_ReadCounter command to the TPM and reads the response. */
uint32_t Ttl_TPM_ReadCounter(TPM_ReadCounter_rqu* in_parameters, TPM_ReadCounter_rsp* out_parameters, uint8_t* buffer, int buffer_size) {
  void* auth1 = NULL;
  void* auth2 = NULL;
  RETURN_ON_FAILURE(TtlRunCommand(TPM_ORD_ReadCounter,
         3863, 3869, in_parameters, out_parameters,
         auth1, auth2, buffer, buffer_size));
  return TPM_SUCCESS;
}

/* Sends a TPM_ReleaseCounter command to the TPM and reads the response. */
uint32_t Ttl_TPM_ReleaseCounter(TPM_ReleaseCounter_rqu* in_parameters, APSession* auth1) {
  void* out_parameters = NULL;
  uint8_t buffer[TPM_MAX_COMMAND_LENGTH];
  int buffer_size = sizeof(buffer);
  void* auth2 = NULL;
  RETURN_ON_FAILURE(TtlRunCommand(TPM_ORD_ReleaseCounter,
         3876, -1, in_parameters, out_parameters,
         auth1, auth2, buffer, buffer_size));
  return TPM_SUCCESS;
}

/* Sends a TPM_ReleaseCounterOwner command to the TPM and reads the response. */
uint32_t Ttl_TPM_ReleaseCounterOwner(TPM_ReleaseCounterOwner_rqu* in_parameters, APSession* auth1) {
  void* out_parameters = NULL;
  uint8_t buffer[TPM_MAX_COMMAND_LENGTH];
  int buffer_size = sizeof(buffer);
  void* auth2 = NULL;
  RETURN_ON_FAILURE(TtlRunCommand(TPM_ORD_ReleaseCounterOwner,
         3882, -1, in_parameters, out_parameters,
         auth1, auth2, buffer, buffer_size));
  return TPM_SUCCESS;
}

/* Sends a TPM_DAA_Join command to the TPM and reads the response. */
uint32_t Ttl_TPM_DAA_Join(TPM_DAA_Join_rqu* in_parameters, TPM_DAA_Join_rsp* out_parameters, uint8_t* buffer, int buffer_size, APSession* auth1) {
  void* auth2 = NULL;
  RETURN_ON_FAILURE(TtlRunCommand(TPM_ORD_DAA_Join,
         3888, 3916, in_parameters, out_parameters,
         auth1, auth2, buffer, buffer_size));
  return TPM_SUCCESS;
}

/* Sends a TPM_DAA_Sign command to the TPM and reads the response. */
uint32_t Ttl_TPM_DAA_Sign(TPM_DAA_Sign_rqu* in_parameters, TPM_DAA_Sign_rsp* out_parameters, uint8_t* buffer, int buffer_size, APSession* auth1) {
  void* auth2 = NULL;
  RETURN_ON_FAILURE(TtlRunCommand(TPM_ORD_DAA_Sign,
         3927, 3955, in_parameters, out_parameters,
         auth1, auth2, buffer, buffer_size));
  return TPM_SUCCESS;
}

/* Sends a TPM_EvictKey command to the TPM and reads the response. */
uint32_t Ttl_TPM_EvictKey(TPM_EvictKey_rqu* in_parameters) {
  void* out_parameters = NULL;
  uint8_t buffer[TPM_MAX_COMMAND_LENGTH];
  int buffer_size = sizeof(buffer);
  void* auth1 = NULL;
  void* auth2 = NULL;
  RETURN_ON_FAILURE(TtlRunCommand(TPM_ORD_EvictKey,
         3966, -1, in_parameters, out_parameters,
         auth1, auth2, buffer, buffer_size));
  return TPM_SUCCESS;
}

/* Sends a TPM_Terminate_Handle command to the TPM and reads the response. */
uint32_t Ttl_TPM_Terminate_Handle(TPM_Terminate_Handle_rqu* in_parameters) {
  void* out_parameters = NULL;
  uint8_t buffer[TPM_MAX_COMMAND_LENGTH];
  int buffer_size = sizeof(buffer);
  void* auth1 = NULL;
  void* auth2 = NULL;
  RETURN_ON_FAILURE(TtlRunCommand(TPM_ORD_Terminate_Handle,
         3972, -1, in_parameters, out_parameters,
         auth1, auth2, buffer, buffer_size));
  return TPM_SUCCESS;
}

/* Sends a TPM_SaveKeyContext command to the TPM and reads the response. */
uint32_t Ttl_TPM_SaveKeyContext(TPM_SaveKeyContext_rqu* in_parameters, TPM_SaveKeyContext_rsp* out_parameters, uint8_t* buffer, int buffer_size) {
  void* auth1 = NULL;
  void* auth2 = NULL;
  RETURN_ON_FAILURE(TtlRunCommand(TPM_ORD_SaveKeyContext,
         3978, 3984, in_parameters, out_parameters,
         auth1, auth2, buffer, buffer_size));
  return TPM_SUCCESS;
}

/* Sends a TPM_LoadKeyContext command to the TPM and reads the response. */
uint32_t Ttl_TPM_LoadKeyContext(TPM_LoadKeyContext_rqu* in_parameters, TPM_LoadKeyContext_rsp* out_parameters, uint8_t* buffer, int buffer_size) {
  void* auth1 = NULL;
  void* auth2 = NULL;
  RETURN_ON_FAILURE(TtlRunCommand(TPM_ORD_LoadKeyContext,
         3995, 4006, in_parameters, out_parameters,
         auth1, auth2, buffer, buffer_size));
  return TPM_SUCCESS;
}

/* Sends a TPM_SaveAuthContext command to the TPM and reads the response. */
uint32_t Ttl_TPM_SaveAuthContext(TPM_SaveAuthContext_rqu* in_parameters, TPM_SaveAuthContext_rsp* out_parameters, uint8_t* buffer, int buffer_size) {
  void* auth1 = NULL;
  void* auth2 = NULL;
  RETURN_ON_FAILURE(TtlRunCommand(TPM_ORD_SaveAuthContext,
         4012, 4018, in_parameters, out_parameters,
         auth1, auth2, buffer, buffer_size));
  return TPM_SUCCESS;
}

/* Sends a TPM_LoadAuthContext command to the TPM and reads the response. */
uint32_t Ttl_TPM_LoadAuthContext(TPM_LoadAuthContext_rqu* in_parameters, TPM_LoadAuthContext_rsp* out_parameters, uint8_t* buffer, int buffer_size) {
  void* auth1 = NULL;
  void* auth2 = NULL;
  RETURN_ON_FAILURE(TtlRunCommand(TPM_ORD_LoadAuthContext,
         4029, 4040, in_parameters, out_parameters,
         auth1, auth2, buffer, buffer_size));
  return TPM_SUCCESS;
}

/* Sends a TPM_DirWriteAuth command to the TPM and reads the response. */
uint32_t Ttl_TPM_DirWriteAuth(TPM_DirWriteAuth_rqu* in_parameters, APSession* auth1) {
  void* out_parameters = NULL;
  uint8_t buffer[TPM_MAX_COMMAND_LENGTH];
  int buffer_size = sizeof(buffer);
  void* auth2 = NULL;
  RETURN_ON_FAILURE(TtlRunCommand(TPM_ORD_DirWriteAuth,
         4046, -1, in_parameters, out_parameters,
         auth1, auth2, buffer, buffer_size));
  return TPM_SUCCESS;
}

/* Sends a TPM_DirRead command to the TPM and reads the response. */
uint32_t Ttl_TPM_DirRead(TPM_DirRead_rqu* in_parameters, TPM_DirRead_rsp* out_parameters, uint8_t* buffer, int buffer_size) {
  void* auth1 = NULL;
  void* auth2 = NULL;
  RETURN_ON_FAILURE(TtlRunCommand(TPM_ORD_DirRead,
         4057, 4063, in_parameters, out_parameters,
         auth1, auth2, buffer, buffer_size));
  return TPM_SUCCESS;
}

/* Sends a TPM_ChangeAuthAsymStart command to the TPM and reads the response. */
uint32_t Ttl_TPM_ChangeAuthAsymStart(TPM_ChangeAuthAsymStart_rqu* in_parameters, TPM_ChangeAuthAsymStart_rsp* out_parameters, uint8_t* buffer, int buffer_size, APSession* auth1) {
  void* auth2 = NULL;
  RETURN_ON_FAILURE(TtlRunCommand(TPM_ORD_ChangeAuthAsymStart,
         4070, 4087, in_parameters, out_parameters,
         auth1, auth2, buffer, buffer_size));
  return TPM_SUCCESS;
}

/* Sends a TPM_ChangeAuthAsymFinish command to the TPM and reads the response. */
uint32_t Ttl_TPM_ChangeAuthAsymFinish(TPM_ChangeAuthAsymFinish_rqu* in_parameters, TPM_ChangeAuthAsymFinish_rsp* out_parameters, uint8_t* buffer, int buffer_size, APSession* auth1) {
  void* auth2 = NULL;
  RETURN_ON_FAILURE(TtlRunCommand(TPM_ORD_ChangeAuthAsymFinish,
         4114, 4151, in_parameters, out_parameters,
         auth1, auth2, buffer, buffer_size));
  return TPM_SUCCESS;
}

/* Sends a TPM_Reset command to the TPM and reads the response. */
uint32_t Ttl_TPM_Reset(void) {
  void* in_parameters = NULL;
  void* out_parameters = NULL;
  uint8_t buffer[TPM_MAX_COMMAND_LENGTH];
  int buffer_size = sizeof(buffer);
  void* auth1 = NULL;
  void* auth2 = NULL;
  RETURN_ON_FAILURE(TtlRunCommand(TPM_ORD_Reset,
         -1, -1, in_parameters, out_parameters,
         auth1, auth2, buffer, buffer_size));
  return TPM_SUCCESS;
}

/* Sends a TPM_OwnerReadPubek command to the TPM and reads the response. */
uint32_t Ttl_TPM_OwnerReadPubek(TPM_OwnerReadPubek_rsp* out_parameters, uint8_t* buffer, int buffer_size, APSession* auth1) {
  void* in_parameters = NULL;
  void* auth2 = NULL;
  RETURN_ON_FAILURE(TtlRunCommand(TPM_ORD_OwnerReadPubek,
         -1, 4172, in_parameters, out_parameters,
         auth1, auth2, buffer, buffer_size));
  return TPM_SUCCESS;
}

/* Sends a TPM_DisablePubekRead command to the TPM and reads the response. */
uint32_t Ttl_TPM_DisablePubekRead(APSession* auth1) {
  void* in_parameters = NULL;
  void* out_parameters = NULL;
  uint8_t buffer[TPM_MAX_COMMAND_LENGTH];
  int buffer_size = sizeof(buffer);
  void* auth2 = NULL;
  RETURN_ON_FAILURE(TtlRunCommand(TPM_ORD_DisablePubekRead,
         -1, -1, in_parameters, out_parameters,
         auth1, auth2, buffer, buffer_size));
  return TPM_SUCCESS;
}

/* Sends a TPM_LoadKey command to the TPM and reads the response. */
uint32_t Ttl_TPM_LoadKey(TPM_LoadKey_rqu* in_parameters, TPM_LoadKey_rsp* out_parameters, uint8_t* buffer, int buffer_size, APSession* auth1) {
  void* auth2 = NULL;
  RETURN_ON_FAILURE(TtlRunCommand(TPM_ORD_LoadKey,
         4180, 4192, in_parameters, out_parameters,
         auth1, auth2, buffer, buffer_size));
  return TPM_SUCCESS;
}

/* Sends a TPM_GetOrdinalAuditStatus command to the TPM and reads the response. */
uint32_t Ttl_TPM_GetOrdinalAuditStatus(TPM_GetOrdinalAuditStatus_rqu* in_parameters, TPM_GetOrdinalAuditStatus_rsp* out_parameters, uint8_t* buffer, int buffer_size) {
  void* auth1 = NULL;
  void* auth2 = NULL;
  RETURN_ON_FAILURE(TtlRunCommand(TPM_ORD_GetOrdinalAuditStatus,
         4198, 4204, in_parameters, out_parameters,
         auth1, auth2, buffer, buffer_size));
  return TPM_SUCCESS;
}

