/* Copyright (c) 2011 The Chromium OS Authors. All rights reserved.
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 *
 * TPM type and value constants.
 */

#ifndef TRUNKS_TPM_CONSTANTS_H_
#define TRUNKS_TPM_CONSTANTS_H_

/* TPM type and field sizes. */

#define TPM_SHA1_160_HASH_LEN          20
#define TPM_SHA1BASED_NONCE_LEN        20

#define TPM_WELL_KNOWN_SECRET "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
#define TPM_WELL_KNOWN_SECRET_LEN      20

#define TPM_RQU_ORDINAL_OFFSET         6
#define TPM_RQU_HEADER_SIZE            10
#define TPM_RQU_AUTH_SIZE              45
#define TPM_RSP_RESULT_OFFSET          6
#define TPM_RSP_HEADER_SIZE            10
#define TPM_RSP_AUTH_SIZE              41

#define TPM_PCR_DIGEST_LENGTH          20

/* TPM command tags. */

#define TPM_TAG_RQU_COMMAND            0x00C1
#define TPM_TAG_RQU_AUTH1_COMMAND      0x00C2
#define TPM_TAG_RQU_AUTH2_COMMAND      0x00C3
#define TPM_TAG_RSP_COMMAND            0x00C4
#define TPM_TAG_RSP_AUTH1_COMMAND      0x00C5
#define TPM_TAG_RSP_AUTH2_COMMAND      0x00C6

/* TPM command ordinals. */

#define TPM_PROTECTED_COMMAND          0x00000000
#define TPM_UNPROTECTED_COMMAND        0x80000000
#define TPM_CONNECTION_COMMAND         0x40000000
#define TPM_VENDOR_COMMAND             0x20000000

#define TPM_ORD_OIAP                            10
#define TPM_ORD_OSAP                            11
#define TPM_ORD_ChangeAuth                      12
#define TPM_ORD_TakeOwnership                   13
#define TPM_ORD_ChangeAuthAsymStart             14
#define TPM_ORD_ChangeAuthAsymFinish            15
#define TPM_ORD_ChangeAuthOwner                 16
#define TPM_ORD_DSAP                            17
#define TPM_ORD_CMK_CreateTicket                18
#define TPM_ORD_CMK_CreateKey                   19
#define TPM_ORD_Extend                          20
#define TPM_ORD_PCRRead                         21
#define TPM_ORD_Quote                           22
#define TPM_ORD_Seal                            23
#define TPM_ORD_Unseal                          24
#define TPM_ORD_DirWriteAuth                    25
#define TPM_ORD_DirRead                         26
#define TPM_ORD_CMK_CreateBlob                  27
#define TPM_ORD_CMK_SetRestrictions             28
#define TPM_ORD_CMK_ApproveMA                   29
#define TPM_ORD_UnBind                          30
#define TPM_ORD_CreateWrapKey                   31
#define TPM_ORD_LoadKey                         32
#define TPM_ORD_GetPubKey                       33
#define TPM_ORD_EvictKey                        34
#define TPM_ORD_KeyControlOwner                 35
#define TPM_ORD_CMK_ConvertMigration            36
#define TPM_ORD_MigrateKey                      37
#define TPM_ORD_CreateMigrationBlob             40
#define TPM_ORD_DAA_Join                        41
#define TPM_ORD_ConvertMigrationBlob            42
#define TPM_ORD_AuthorizeMigrationKey           43
#define TPM_ORD_CreateMaintenanceArchive        44
#define TPM_ORD_LoadMaintenanceArchive          45
#define TPM_ORD_KillMaintenanceFeature          46
#define TPM_ORD_LoadManuMaintPub                47
#define TPM_ORD_ReadManuMaintPub                48
#define TPM_ORD_DAA_Sign                        49
#define TPM_ORD_CertifyKey                      50
#define TPM_ORD_CertifyKey2                     51
#define TPM_ORD_Sign                            60
#define TPM_ORD_Sealx                           61
#define TPM_ORD_Quote2                          62
#define TPM_ORD_SetCapability                   63
#define TPM_ORD_ResetLockValue                  64
#define TPM_ORD_LoadKey2                        65
#define TPM_ORD_GetRandom                       70
#define TPM_ORD_StirRandom                      71
#define TPM_ORD_SelfTestFull                    80
#define TPM_ORD_ContinueSelfTest                83
#define TPM_ORD_GetTestResult                   84
#define TPM_ORD_Reset                           90
#define TPM_ORD_OwnerClear                      91
#define TPM_ORD_DisableOwnerClear               92
#define TPM_ORD_ForceClear                      93
#define TPM_ORD_DisableForceClear               94
#define TPM_ORD_GetCapability                   101
#define TPM_ORD_GetCapabilityOwner              102
#define TPM_ORD_OwnerSetDisable                 110
#define TPM_ORD_PhysicalEnable                  111
#define TPM_ORD_PhysicalDisable                 112
#define TPM_ORD_SetOwnerInstall                 113
#define TPM_ORD_PhysicalSetDeactivated          114
#define TPM_ORD_SetTempDeactivated              115
#define TPM_ORD_SetOperatorAuth                 116
#define TPM_ORD_SetOwnerPointer                 117
#define TPM_ORD_CreateEndorsementKeyPair        120
#define TPM_ORD_MakeIdentity                    121
#define TPM_ORD_ActivateIdentity                122
#define TPM_ORD_ReadPubek                       124
#define TPM_ORD_OwnerReadPubek                  125
#define TPM_ORD_DisablePubekRead                126
#define TPM_ORD_CreateRevocableEK               127
#define TPM_ORD_RevokeTrust                     128
#define TPM_ORD_OwnerReadInternalPub            129
#define TPM_ORD_GetAuditDigest                  133
#define TPM_ORD_GetAuditDigestSigned            134
#define TPM_ORD_GetOrdinalAuditStatus           140
#define TPM_ORD_SetOrdinalAuditStatus           141
#define TPM_ORD_Terminate_Handle                150
#define TPM_ORD_Init                            151
#define TPM_ORD_SaveState                       152
#define TPM_ORD_Startup                         153
#define TPM_ORD_SetRedirection                  154
#define TPM_ORD_SHA1Start                       160
#define TPM_ORD_SHA1Update                      161
#define TPM_ORD_SHA1Complete                    162
#define TPM_ORD_SHA1CompleteExtend              163
#define TPM_ORD_FieldUpgrade                    170
#define TPM_ORD_SaveKeyContext                  180
#define TPM_ORD_LoadKeyContext                  181
#define TPM_ORD_SaveAuthContext                 182
#define TPM_ORD_LoadAuthContext                 183
#define TPM_ORD_SaveContext                     184
#define TPM_ORD_LoadContext                     185
#define TPM_ORD_FlushSpecific                   186
#define TPM_ORD_PCR_Reset                       200
#define TPM_ORD_NV_DefineSpace                  204
#define TPM_ORD_NV_WriteValue                   205
#define TPM_ORD_NV_WriteValueAuth               206
#define TPM_ORD_NV_ReadValue                    207
#define TPM_ORD_NV_ReadValueAuth                208
#define TPM_ORD_Delegate_UpdateVerification     209
#define TPM_ORD_Delegate_Manage                 210
#define TPM_ORD_Delegate_CreateKeyDelegation    212
#define TPM_ORD_Delegate_CreateOwnerDelegation  213
#define TPM_ORD_Delegate_VerifyDelegation       214
#define TPM_ORD_Delegate_LoadOwnerDelegation    216
#define TPM_ORD_Delegate_ReadAuth               217
#define TPM_ORD_Delegate_ReadTable              219
#define TPM_ORD_CreateCounter                   220
#define TPM_ORD_IncrementCounter                221
#define TPM_ORD_ReadCounter                     222
#define TPM_ORD_ReleaseCounter                  223
#define TPM_ORD_ReleaseCounterOwner             224
#define TPM_ORD_EstablishTransport              230
#define TPM_ORD_ExecuteTransport                231
#define TPM_ORD_ReleaseTransportSigned          232
#define TPM_ORD_GetTicks                        241
#define TPM_ORD_TickStampBlob                   242

#define TSC_ORD_PhysicalPresence                (10 + TPM_CONNECTION_COMMAND)
#define TSC_ORD_ResetEstablishmentBit           (11 + TPM_CONNECTION_COMMAND)

/* TPM protocol ids. */

#define TPM_PID_OIAP            0x0001
#define TPM_PID_OSAP            0x0002
#define TPM_PID_ADIP            0x0003
#define TPM_PID_ADCP            0x0004
#define TPM_PID_OWNER           0x0005
#define TPM_PID_DSAP            0x0006
#define TPM_PID_TRANSPORT       0x0007

/* TPM algorithm ids. */

#define TPM_ALG_RSA             0x00000001
#define TPM_ALG_DES             0x00000002
#define TPM_ALG_3DES            0x00000003
#define TPM_ALG_SHA             0x00000004
#define TPM_ALG_HMAC            0x00000005
#define TPM_ALG_AES128          0x00000006
#define TPM_ALG_MGF1            0x00000007
#define TPM_ALG_AES192          0x00000008
#define TPM_ALG_AES256          0x00000009
#define TPM_ALG_XOR             0x0000000A

/* TPM resource types. */

#define TPM_RT_KEY              0x00000001
#define TPM_RT_AUTH             0x00000002
#define TPM_RT_HASH             0x00000003
#define TPM_RT_TRANS            0x00000004
#define TPM_RT_CONTEXT          0x00000005
#define TPM_RT_COUNTER          0x00000006
#define TPM_RT_DELEGATE         0x00000007
#define TPM_RT_DAA_TPM          0x00000008
#define TPM_RT_DAA_V0           0x00000009
#define TPM_RT_DAA_V1           0x0000000A

/* TPM payload types. */

#define TPM_PT_ASYM                     0x01
#define TPM_PT_BIND                     0x02
#define TPM_PT_MIGRATE                  0x03
#define TPM_PT_MAINT                    0x04
#define TPM_PT_SEAL                     0x05
#define TPM_PT_MIGRATE_RESTRICTED       0x06
#define TPM_PT_MIGRATE_EXTERNAL         0x07
#define TPM_PT_CMK_MIGRATE              0x08
#define TPM_PT_NONE                     0x00

/* TPM entity and ADIP encryption schemes. */

/* LSB Values */
#define TPM_ET_KEYHANDLE        0x01
#define TPM_ET_OWNER            0x02
#define TPM_ET_DATA             0x03
#define TPM_ET_SRK              0x04
#define TPM_ET_KEY              0x05
#define TPM_ET_REVOKE           0x06
#define TPM_ET_DEL_OWNER_BLOB   0x07
#define TPM_ET_DEL_ROW          0x08
#define TPM_ET_DEL_KEY_BLOB     0x09
#define TPM_ET_COUNTER          0x0A
#define TPM_ET_NV               0x0B
#define TPM_ET_OPERATOR         0x0C
#define TPM_ET_VERIFICATION_AUTH 0x0D
#define TPM_ET_RESERVED_HANDLE  0x40
/* MSB Values */
#define TPM_ET_XOR              0x00
#define TPM_ET_AES128_CTR       0x06

/* TPM key types. */

#define TPM_KEY_SIGNING         0x0010
#define TPM_KEY_STORAGE         0x0011
#define TPM_KEY_IDENTITY        0x0012
#define TPM_KEY_AUTHCHANGE      0x0013
#define TPM_KEY_BIND            0x0014
#define TPM_KEY_LEGACY          0x0015
#define TPM_KEY_MIGRATE         0x0016

/* TPM encryption schemes. */

#define TPM_ES_NONE                    0x0001
#define TPM_ES_RSAESPKCSv15            0x0002
#define TPM_ES_RSAESOAEP_SHA1_MGF1     0x0003
#define TPM_ES_SYM_CTR                 0x0004
#define TPM_ES_SYM_OFB                 0x0005

/* TPM sgnature schemes. */

#define TPM_SS_NONE                    0x0001
#define TPM_SS_RSASSAPKCS1v15_SHA1     0x0002
#define TPM_SS_RSASSAPKCS1v15_DER      0x0003
#define TPM_SS_RSASSAPKCS1v15_INFO     0x0004

/* TPM authorization policy. */

#define TPM_AUTH_NEVER          0x00
#define TPM_AUTH_ALWAYS         0x01
#define TPM_AUTH_PRIV_USE_ONLY  0x03

/* TPM NV space permissions. */

#define TPM_NV_PER_PPWRITE       0x00000001
#define TPM_NV_PER_OWNERWRITE    0x00000002
#define TPM_NV_PER_AUTHWRITE     0x00000004
#define TPM_NV_PER_WRITEALL      0x00001000
#define TPM_NV_PER_WRITEDEFINE   0x00002000
#define TPM_NV_PER_WRITE_STCLEAR 0x00004000
#define TPM_NV_PER_GLOBALLOCK    0x00008000
#define TPM_NV_PER_PPREAD        0x00010000
#define TPM_NV_PER_OWNERREAD     0x00020000
#define TPM_NV_PER_AUTHREAD      0x00040000
#define TPM_NV_PER_READ_STCLEAR  0x80000000

/* TPM error codes. */

#define TPM_NON_FATAL                   0x00000800
#define TPM_BASE                        0x00000000

#define TPM_SUCCESS                     (TPM_BASE + 0)
#define TPM_AUTHFAIL                    (TPM_BASE + 1)
#define TPM_BADINDEX                    (TPM_BASE + 2)
#define TPM_BAD_PARAMETER               (TPM_BASE + 3)
#define TPM_AUDITFAILURE                (TPM_BASE + 4)
#define TPM_CLEAR_DISABLED              (TPM_BASE + 5)
#define TPM_DEACTIVATED                 (TPM_BASE + 6)
#define TPM_DISABLED                    (TPM_BASE + 7)
#define TPM_DISABLED_CMD                (TPM_BASE + 8)
#define TPM_FAIL                        (TPM_BASE + 9)
#define TPM_BAD_ORDINAL                 (TPM_BASE + 10)
#define TPM_INSTALL_DISABLED            (TPM_BASE + 11)
#define TPM_INVALID_KEYHANDLE           (TPM_BASE + 12)
#define TPM_KEYNOTFOUND                 (TPM_BASE + 13)
#define TPM_INAPPROPRIATE_ENC           (TPM_BASE + 14)
#define TPM_MIGRATEFAIL                 (TPM_BASE + 15)
#define TPM_INVALID_PCR_INFO            (TPM_BASE + 16)
#define TPM_NOSPACE                     (TPM_BASE + 17)
#define TPM_NOSRK                       (TPM_BASE + 18)
#define TPM_NOTSEALED_BLOB              (TPM_BASE + 19)
#define TPM_OWNER_SET                   (TPM_BASE + 20)
#define TPM_RESOURCES                   (TPM_BASE + 21)
#define TPM_SHORTRANDOM                 (TPM_BASE + 22)
#define TPM_SIZE                        (TPM_BASE + 23)
#define TPM_WRONGPCRVAL                 (TPM_BASE + 24)
#define TPM_BAD_PARAM_SIZE              (TPM_BASE + 25)
#define TPM_SHA_THREAD                  (TPM_BASE + 26)
#define TPM_SHA_ERROR                   (TPM_BASE + 27)
#define TPM_FAILEDSELFTEST              (TPM_BASE + 28)
#define TPM_AUTH2FAIL                   (TPM_BASE + 29)
#define TPM_BADTAG                      (TPM_BASE + 30)
#define TPM_IOERROR                     (TPM_BASE + 31)
#define TPM_ENCRYPT_ERROR               (TPM_BASE + 32)
#define TPM_DECRYPT_ERROR               (TPM_BASE + 33)
#define TPM_INVALID_AUTHHANDLE          (TPM_BASE + 34)
#define TPM_NO_ENDORSEMENT              (TPM_BASE + 35)
#define TPM_INVALID_KEYUSAGE            (TPM_BASE + 36)
#define TPM_WRONG_ENTITYTYPE            (TPM_BASE + 37)
#define TPM_INVALID_POSTINIT            (TPM_BASE + 38)
#define TPM_INAPPROPRIATE_SIG           (TPM_BASE + 39)
#define TPM_BAD_KEY_PROPERTY            (TPM_BASE + 40)
#define TPM_BAD_MIGRATION               (TPM_BASE + 41)
#define TPM_BAD_SCHEME                  (TPM_BASE + 42)
#define TPM_BAD_DATASIZE                (TPM_BASE + 43)
#define TPM_BAD_MODE                    (TPM_BASE + 44)
#define TPM_BAD_PRESENCE                (TPM_BASE + 45)
#define TPM_BAD_VERSION                 (TPM_BASE + 46)
#define TPM_NO_WRAP_TRANSPORT           (TPM_BASE + 47)
#define TPM_AUDITFAIL_UNSUCCESSFUL      (TPM_BASE + 48)
#define TPM_AUDITFAIL_SUCCESSFUL        (TPM_BASE + 49)
#define TPM_NOTRESETABLE                (TPM_BASE + 50)
#define TPM_NOTLOCAL                    (TPM_BASE + 51)
#define TPM_BAD_TYPE                    (TPM_BASE + 52)
#define TPM_INVALID_RESOURCE            (TPM_BASE + 53)
#define TPM_NOTFIPS                     (TPM_BASE + 54)
#define TPM_INVALID_FAMILY              (TPM_BASE + 55)
#define TPM_NO_NV_PERMISSION            (TPM_BASE + 56)
#define TPM_REQUIRES_SIGN               (TPM_BASE + 57)
#define TPM_KEY_NOTSUPPORTED            (TPM_BASE + 58)
#define TPM_AUTH_CONFLICT               (TPM_BASE + 59)
#define TPM_AREA_LOCKED                 (TPM_BASE + 60)
#define TPM_BAD_LOCALITY                (TPM_BASE + 61)
#define TPM_READ_ONLY                   (TPM_BASE + 62)
#define TPM_PER_NOWRITE                 (TPM_BASE + 63)
#define TPM_FAMILYCOUNT                 (TPM_BASE + 64)
#define TPM_WRITE_LOCKED                (TPM_BASE + 65)
#define TPM_BAD_ATTRIBUTES              (TPM_BASE + 66)
#define TPM_INVALID_STRUCTURE           (TPM_BASE + 67)
#define TPM_KEY_OWNER_CONTROL           (TPM_BASE + 68)
#define TPM_BAD_COUNTER                 (TPM_BASE + 69)
#define TPM_NOT_FULLWRITE               (TPM_BASE + 70)
#define TPM_CONTEXT_GAP                 (TPM_BASE + 71)
#define TPM_MAXNVWRITES                 (TPM_BASE + 72)
#define TPM_NOOPERATOR                  (TPM_BASE + 73)
#define TPM_RESOURCEMISSING             (TPM_BASE + 74)
#define TPM_DELEGATE_LOCK               (TPM_BASE + 75)
#define TPM_DELEGATE_FAMILY             (TPM_BASE + 76)
#define TPM_DELEGATE_ADMIN              (TPM_BASE + 77)
#define TPM_TRANSPORT_NOTEXCLUSIVE      (TPM_BASE + 78)
#define TPM_OWNER_CONTROL               (TPM_BASE + 79)
#define TPM_DAA_RESOURCES               (TPM_BASE + 80)
#define TPM_DAA_INPUT_DATA0             (TPM_BASE + 81)
#define TPM_DAA_INPUT_DATA1             (TPM_BASE + 82)
#define TPM_DAA_ISSUER_SETTINGS         (TPM_BASE + 83)
#define TPM_DAA_TPM_SETTINGS            (TPM_BASE + 84)
#define TPM_DAA_STAGE                   (TPM_BASE + 85)
#define TPM_DAA_ISSUER_VALIDITY         (TPM_BASE + 86)
#define TPM_DAA_WRONG_W                 (TPM_BASE + 87)
#define TPM_BAD_HANDLE                  (TPM_BASE + 88)
#define TPM_BAD_DELEGATE                (TPM_BASE + 89)
#define TPM_BADCONTEXT                  (TPM_BASE + 90)
#define TPM_TOOMANYCONTEXTS             (TPM_BASE + 91)
#define TPM_MA_TICKET_SIGNATURE         (TPM_BASE + 92)
#define TPM_MA_DESTINATION              (TPM_BASE + 93)
#define TPM_MA_SOURCE                   (TPM_BASE + 94)
#define TPM_MA_AUTHORITY                (TPM_BASE + 95)
#define TPM_PERMANENTEK                 (TPM_BASE + 97)
#define TPM_BAD_SIGNATURE               (TPM_BASE + 98)
#define TPM_NOCONTEXTSPACE              (TPM_BASE + 99)
#define TPM_RETRY                       (TPM_BASE + TPM_NON_FATAL)
#define TPM_NEEDS_SELFTEST              (TPM_BASE + TPM_NON_FATAL + 1)
#define TPM_DOING_SELFTEST              (TPM_BASE + TPM_NON_FATAL + 2)
#define TPM_DEFEND_LOCK_RUNNING         (TPM_BASE + TPM_NON_FATAL + 3)

/* Structure tags. */

#define TPM_TAG_CONTEXTBLOB          0x1
#define TPM_TAG_CONTEXT_SENSITIVE    0x2
#define TPM_TAG_CONTEXTPOINTER       0x3
#define TPM_TAG_CONTEXTLIST          0x4
#define TPM_TAG_SIGNINFO             0x5
#define TPM_TAG_PCR_INFO_LONG        0x6
#define TPM_TAG_PERSISTENT_FLAGS     0x7
#define TPM_TAG_VOLATILE_FLAGS       0x8
#define TPM_TAG_PERSISTENT_DATA      0x9
#define TPM_TAG_VOLATILE_DATA        0xa
#define TPM_TAG_SV_DATA              0xb
#define TPM_TAG_EK_BLOB              0xc
#define TPM_TAG_EK_BLOB_AUTH         0xd
#define TPM_TAG_COUNTER_VALUE        0xe
#define TPM_TAG_TRANSPORT_INTERNAL   0xf
#define TPM_TAG_TRANSPORT_LOG_IN     0x10
#define TPM_TAG_TRANSPORT_LOG_OUT    0x11
#define TPM_TAG_AUDIT_EVENT_IN       0x12
#define TPM_TAG_AUDIT_EVENT_OUT      0x13
#define TPM_TAG_CURRENT_TICKS        0x14
#define TPM_TAG_KEY                  0x15
#define TPM_TAG_STORED_DATA12        0x16
#define TPM_TAG_NV_ATTRIBUTES        0x17
#define TPM_TAG_NV_DATA_PUBLIC       0x18
#define TPM_TAG_NV_DATA_SENSITIVE    0x19
#define TPM_TAG_DELEGATIONS          0x1a
#define TPM_TAG_DELEGATE_PUBLIC      0x1b
#define TPM_TAG_DELEGATE_TABLE_ROW   0x1c
#define TPM_TAG_TRANSPORT_AUTH       0x1d
#define TPM_TAG_TRANSPORT_PUBLIC     0x1e
#define TPM_TAG_PERMANENT_FLAGS      0x1f
#define TPM_TAG_STCLEAR_FLAGS        0x20
#define TPM_TAG_STANY_FLAGS          0x21
#define TPM_TAG_PERMANENT_DATA       0x22
#define TPM_TAG_STCLEAR_DATA         0x23
#define TPM_TAG_STANY_DATA           0x24
#define TPM_TAG_FAMILY_TABLE_ENTRY   0x25
#define TPM_TAG_DELEGATE_SENSITIVE   0x26
#define TPM_TAG_DELG_KEY_BLOB        0x27
#define TPM_TAG_KEY12                0x28
#define TPM_TAG_CERTIFY_INFO2        0x29
#define TPM_TAG_DELEGATE_OWNER_BLOB  0x2a
#define TPM_TAG_EK_BLOB_ACTIVATE     0x2b
#define TPM_TAG_DAA_BLOB             0x2c
#define TPM_TAG_DAA_CONTEXT          0x2d
#define TPM_TAG_DAA_ENFORCE          0x2e
#define TPM_TAG_DAA_ISSUER           0x2f
#define TPM_TAG_CAP_VERSION_INFO     0x30
#define TPM_TAG_DAA_SENSITIVE        0x31
#define TPM_TAG_DAA_TPM              0x32
#define TPM_TAG_CMK_MIGAUTH          0x33
#define TPM_TAG_CMK_SIGTICKET        0x34
#define TPM_TAG_CMK_MA_APPROVAL      0x35
#define TPM_TAG_QUOTE_INFO2          0x36
#define TPM_TAG_DA_INFO              0x37
#define TPM_TAG_DA_INFO_LIMITED      0x38
#define TPM_TAG_DA_ACTION_TYPE       0x39

#define TPM_E_NON_FATAL              0x800
#define TPM_E_NEEDS_SELFTEST         ((uint32_t)(TPM_E_NON_FATAL + 1))
#define TPM_E_DOING_SELFTEST         ((uint32_t)(TPM_E_NON_FATAL + 2))

/* Library errors */

#define TPM_E_INTERNAL_ERROR         ((uint32_t)0x00005001)
#define TPM_E_COMMUNICATION_ERROR    ((uint32_t)0x00005004)  /* vboot local */

/* TPM startup types. */

#define TPM_ST_CLEAR            0x0001
#define TPM_ST_STATE            0x0002
#define TPM_ST_DEACTIVATED      0x0003

/* Reserved NV index values. */

#define TPM_NV_INDEX_LOCK               0xFFFFFFFF
#define TPM_NV_INDEX0                   0x00000000
#define TPM_NV_INDEX_DIR                0x10000001
#define TPM_NV_INDEX_T                  (1 << 31)
#define TPM_NV_INDEX_P                  (1 << 30)
#define TPM_NV_INDEX_U                  (1 << 29)
#define TPM_NV_INDEX_D                  (1 << 28)
#define TPM_NV_INDEX_EKCert             0x0000F000
#define TPM_NV_INDEX_TPM_CC             0x0000F001
#define TPM_NV_INDEX_PlatformCert       0x0000F002
#define TPM_NV_INDEX_Platform_CC        0x0000F003
#define TPM_NV_INDEX_TRIAL              0x0000F004

/* TPM physical presence settings. */

#define TPM_PHYSICAL_PRESENCE_LOCK          ((uint16_t)0x004)
#define TPM_PHYSICAL_PRESENCE_PRESENT       ((uint16_t)0x008)
#define TPM_PHYSICAL_PRESENCE_NOTPRESENT    ((uint16_t)0x010)
#define TPM_PHYSICAL_PRESENCE_CMD_ENABLE    ((uint16_t)0x020)
#define TPM_PHYSICAL_PRESENCE_HW_ENABLE     ((uint16_t)0x040)
#define TPM_PHYSICAL_PRESENCE_LIFETIME_LOCK ((uint16_t)0x080)
#define TPM_PHYSICAL_PRESENCE_CMD_DISABLE   ((uint16_t)0x100)
#define TPM_PHYSICAL_PRESENCE_HW_DISABLE    ((uint16_t)0x200)

/* TPM capability areas */

#define TPM_CAP_ORD                     0x00000001
#define TPM_CAP_ALG                     0x00000002
#define TPM_CAP_PID                     0x00000003
#define TPM_CAP_FLAG                    0x00000004
#define TPM_CAP_PROPERTY                0x00000005
#define TPM_CAP_VERSION                 0x00000006
#define TPM_CAP_KEY_HANDLE              0x00000007
#define TPM_CAP_CHECK_LOADED            0x00000008
#define TPM_CAP_SYM_MODE                0x00000009
#define TPM_CAP_KEY_STATUS              0x0000000C
#define TPM_CAP_NV_LIST                 0x0000000D
#define TPM_CAP_MFR                     0x00000010
#define TPM_CAP_NV_INDEX                0x00000011
#define TPM_CAP_TRANS_ALG               0x00000012
#define TPM_CAP_HANDLE                  0x00000014
#define TPM_CAP_TRANS_ES                0x00000015
#define TPM_CAP_AUTH_ENCRYPT            0x00000017
#define TPM_CAP_SELECT_SIZE             0x00000018
#define TPM_CAP_DA_LOGIC                0x00000019
#define TPM_CAP_VERSION_VAL             0x0000001A

/* TPM capability sub areas */

#define TPM_CAP_PROP_PCR                0x00000101
#define TPM_CAP_PROP_DIR                0x00000102
#define TPM_CAP_PROP_MANUFACTURER       0x00000103
#define TPM_CAP_PROP_KEYS               0x00000104
#define TPM_CAP_PROP_MIN_COUNTER        0x00000107
#define TPM_CAP_FLAG_PERMANENT          0x00000108
#define TPM_CAP_FLAG_VOLATILE           0x00000109
#define TPM_CAP_PROP_AUTHSESS           0x0000010A
#define TPM_CAP_PROP_TRANSESS           0x0000010B
#define TPM_CAP_PROP_COUNTERS           0x0000010C
#define TPM_CAP_PROP_MAX_AUTHSESS       0x0000010D
#define TPM_CAP_PROP_MAX_TRANSESS       0x0000010E
#define TPM_CAP_PROP_MAX_COUNTERS       0x0000010F
#define TPM_CAP_PROP_MAX_KEYS           0x00000110
#define TPM_CAP_PROP_OWNER              0x00000111
#define TPM_CAP_PROP_CONTEXT            0x00000112
#define TPM_CAP_PROP_MAX_CONTEXT        0x00000113
#define TPM_CAP_PROP_FAMILYROWS         0x00000114
#define TPM_CAP_PROP_TIS_TIMEOUT        0x00000115
#define TPM_CAP_PROP_STARTUP_EFFECT     0x00000116
#define TPM_CAP_PROP_DELEGATE_ROW       0x00000117
#define TPM_CAP_PROP_MAX_DAASESS        0x00000119
#define TPM_CAP_PROP_DAASESS            0x0000011A
#define TPM_CAP_PROP_CONTEXT_DIST       0x0000011B
#define TPM_CAP_PROP_DAA_INTERRUPT      0x0000011C
#define TPM_CAP_PROP_SESSIONS           0x0000011D
#define TPM_CAP_PROP_MAX_SESSIONS       0x0000011E
#define TPM_CAP_PROP_CMK_RESTRICTION    0x0000011F
#define TPM_CAP_PROP_DURATION           0x00000120
#define TPM_CAP_PROP_ACTIVE_COUNTER     0x00000122
#define TPM_CAP_PROP_MAX_NV_AVAILABLE   0x00000123
#define TPM_CAP_PROP_INPUT_BUFFER       0x00000124

/* TPM locality selection types. */

#define TPM_LOC_ZERO  0x1
#define TPM_LOC_ONE   0x2
#define TPM_LOC_TWO   0x4
#define TPM_LOC_THREE 0x8
#define TPM_LOC_FOUR  0x10
#define TPM_ALL_LOCALITIES (TPM_LOC_ZERO | TPM_LOC_ONE | TPM_LOC_TWO    \
                            | TPM_LOC_THREE | TPM_LOC_FOUR)  /* 0x1f */

#endif  /* TRUNKS_TPM_CONSTANTS_H_ */
