/* Copyright (c) 2011 The Chromium OS Authors. All rights reserved.
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef TRUNKS_G_TPM_STRUCTURES_H_
#define TRUNKS_G_TPM_STRUCTURES_H_

#include <stdint.h>
#include <string.h>

#include "trunks_tpm.h"

typedef uint8_t TPM_BOOL;
typedef uint8_t TPM_LOCALITY_MODIFIER;
typedef uint32_t TPM_COMMAND_CODE;
typedef uint32_t TPM_COUNT_ID;
typedef uint32_t TPM_REDIT_COMMAND;
typedef uint32_t TPM_HANDLE;
typedef uint32_t TPM_AUTHHANDLE;
typedef uint32_t TPM_TRANSHANDLE;
typedef uint32_t TPM_KEYHANDLE;
typedef uint32_t TPM_DIRINDEX;
typedef uint32_t TPM_PCRINDEX;
typedef uint32_t TPM_RESULT;
typedef uint32_t TPM_MODIFIER_INDICATOR;
typedef uint16_t TPM_STRUCTURE_TAG;
typedef uint32_t TPM_RESOURCE_TYPE;
typedef uint8_t TPM_PAYLOAD_TYPE;
typedef uint16_t TPM_ENTITY_TYPE;
typedef uint32_t TPM_KEY_HANDLE;
typedef uint16_t TPM_STARTUP_TYPE;
typedef uint16_t TPM_PROTOCOL_ID;
typedef uint32_t TPM_ALGORITHM_ID;
typedef uint16_t TPM_PHYSICAL_PRESENCE;
typedef uint16_t TPM_MIGRATE_SCHEME;
typedef uint16_t TPM_EK_TYPE;
typedef uint16_t TPM_PLATFORM_SPECIFIC;

typedef struct TPM_STRUCT_VER {
  uint8_t major;
  uint8_t minor;
  uint8_t revMajor;
  uint8_t revMinor;
} TPM_STRUCT_VER;


typedef struct TPM_VERSION {
  uint8_t major;
  uint8_t minor;
  uint8_t revMajor;
  uint8_t revMinor;
} TPM_VERSION;


typedef struct TPM_DIGEST {
  uint8_t digest[TPM_SHA1_160_HASH_LEN];
} TPM_DIGEST;

typedef TPM_DIGEST TPM_COMPOSITE_HASH;
typedef TPM_DIGEST TPM_DIRVALUE;
typedef TPM_DIGEST TPM_HMAC;
typedef TPM_DIGEST TPM_PCRVALUE;
typedef TPM_DIGEST TPM_AUDITDIGEST;
typedef TPM_DIGEST TPM_DAA_TPM_SEED;
typedef TPM_DIGEST TPM_DAA_CONTEXT_SEED;

typedef struct TPM_NONCE {
  uint8_t nonce[TPM_SHA1BASED_NONCE_LEN];
} TPM_NONCE;


typedef struct TPM_AUTHDATA {
  uint8_t authdata[TPM_SHA1_160_HASH_LEN];
} TPM_AUTHDATA;

typedef TPM_AUTHDATA TPM_SECRET;
typedef TPM_AUTHDATA TPM_ENCAUTH;
typedef uint16_t TPM_KEY_USAGE;
typedef uint16_t TPM_SIG_SCHEME;
typedef uint16_t TPM_ENC_SCHEME;
typedef uint8_t TPM_AUTH_DATA_USAGE;
typedef uint32_t TPM_KEY_FLAGS;

typedef struct TPM_CHANGEAUTH_VALIDATE {
  TPM_SECRET newAuthSecret;
  TPM_NONCE n1;
} TPM_CHANGEAUTH_VALIDATE;

typedef uint32_t TPM_ACTUAL_COUNT;

typedef struct TPM_COUNTER_VALUE {
  TPM_STRUCTURE_TAG tag;
  uint8_t label[4];
  TPM_ACTUAL_COUNT counter;
} TPM_COUNTER_VALUE;


typedef struct TPM_SIGN_INFO {
  TPM_STRUCTURE_TAG tag;
  uint8_t fixed[4];
  TPM_NONCE replay;
  uint32_t dataLen;
  uint8_t* data;
} TPM_SIGN_INFO;


typedef struct TPM_MSA_COMPOSITE {
  uint32_t MSAlist;
  TPM_DIGEST* migAuthDigest;
} TPM_MSA_COMPOSITE;


typedef struct TPM_CMK_AUTH {
  TPM_DIGEST migrationAuthorityDigest;
  TPM_DIGEST destinationKeyDigest;
  TPM_DIGEST sourceKeyDigest;
} TPM_CMK_AUTH;

typedef uint32_t TPM_CMK_DELEGATE;

typedef struct TPM_SELECT_SIZE {
  uint8_t major;
  uint8_t minor;
  uint16_t reqSize;
} TPM_SELECT_SIZE;


typedef struct TPM_CMK_MIGAUTH {
  TPM_STRUCTURE_TAG tag;
  TPM_DIGEST msaDigest;
  TPM_DIGEST pubKeyDigest;
} TPM_CMK_MIGAUTH;


typedef struct TPM_CMK_SIGTICKET {
  TPM_STRUCTURE_TAG tag;
  TPM_DIGEST verKeyDigest;
  TPM_DIGEST signedData;
} TPM_CMK_SIGTICKET;


typedef struct TPM_CMK_MA_APPROVAL {
  TPM_STRUCTURE_TAG tag;
  TPM_DIGEST migrationAuthorityDigest;
} TPM_CMK_MA_APPROVAL;

typedef uint16_t TPM_TAG;

typedef struct TPM_PERMANENT_FLAGS {
  TPM_STRUCTURE_TAG tag;
  uint8_t disable;
  uint8_t ownership;
  uint8_t deactivated;
  uint8_t readPubek;
  uint8_t disableOwnerClear;
  uint8_t allowMaintenance;
  uint8_t physicalPresenceLifetimeLock;
  uint8_t physicalPresenceHWEnable;
  uint8_t physicalPresenceCMDEnable;
  uint8_t CEKPUsed;
  uint8_t TPMpost;
  uint8_t TPMpostLock;
  uint8_t FIPS;
  uint8_t Operator;
  uint8_t enableRevokeEK;
  uint8_t nvLocked;
  uint8_t readSRKPub;
  uint8_t tpmEstablished;
  uint8_t maintenanceDone;
} TPM_PERMANENT_FLAGS;


typedef struct TPM_STCLEAR_FLAGS {
  TPM_STRUCTURE_TAG tag;
  uint8_t deactivated;
  uint8_t disableForceClear;
  uint8_t physicalPresence;
  uint8_t physicalPresenceLock;
  uint8_t bGlobalLock;
} TPM_STCLEAR_FLAGS;


typedef struct TPM_STANY_FLAGS {
  TPM_STRUCTURE_TAG tag;
  uint8_t postInitialise;
  TPM_MODIFIER_INDICATOR localityModifier;
  uint8_t transportExclusive;
  uint8_t TOSPresent;
} TPM_STANY_FLAGS;

typedef uint8_t TPM_LOCALITY_SELECTION;

typedef struct TPM_PCR_SELECTION {
  uint16_t sizeOfSelect;
  uint8_t* pcrSelect;
} TPM_PCR_SELECTION;


typedef struct TPM_PCR_COMPOSITE {
  TPM_PCR_SELECTION select;
  uint32_t valueSize;
  TPM_PCRVALUE* pcrValue;
} TPM_PCR_COMPOSITE;


typedef struct TPM_PCR_INFO {
  TPM_PCR_SELECTION pcrSelection;
  TPM_COMPOSITE_HASH digestAtRelease;
  TPM_COMPOSITE_HASH digestAtCreation;
} TPM_PCR_INFO;


typedef struct TPM_PCR_INFO_LONG {
  TPM_STRUCTURE_TAG tag;
  TPM_LOCALITY_SELECTION localityAtCreation;
  TPM_LOCALITY_SELECTION localityAtRelease;
  TPM_PCR_SELECTION creationPCRSelection;
  TPM_PCR_SELECTION releasePCRSelection;
  TPM_COMPOSITE_HASH digestAtCreation;
  TPM_COMPOSITE_HASH digestAtRelease;
} TPM_PCR_INFO_LONG;


typedef struct TPM_PCR_INFO_SHORT {
  TPM_PCR_SELECTION pcrSelection;
  TPM_LOCALITY_SELECTION localityAtRelease;
  TPM_COMPOSITE_HASH digestAtRelease;
} TPM_PCR_INFO_SHORT;


typedef struct TPM_PCR_ATTRIBUTES {
  uint8_t pcrReset;
  TPM_LOCALITY_SELECTION pcrExtendLocal;
  TPM_LOCALITY_SELECTION pcrResetLocal;
} TPM_PCR_ATTRIBUTES;


typedef struct TPM_STORED_DATA {
  TPM_STRUCT_VER ver;
  uint32_t sealInfoSize;
  uint8_t* sealInfo;
  uint32_t encDataSize;
  uint8_t* encData;
} TPM_STORED_DATA;


typedef struct TPM_STORED_DATA12 {
  TPM_STRUCTURE_TAG tag;
  TPM_ENTITY_TYPE et;
  uint32_t sealInfoSize;
  uint8_t* sealInfo;
  uint32_t encDataSize;
  uint8_t* encData;
} TPM_STORED_DATA12;


typedef struct TPM_SEALED_DATA {
  TPM_PAYLOAD_TYPE payload;
  TPM_SECRET authData;
  TPM_NONCE tpmProof;
  TPM_DIGEST storedDigest;
  uint32_t dataSize;
  uint8_t* data;
} TPM_SEALED_DATA;


typedef struct TPM_SYMMETRIC_KEY {
  TPM_ALGORITHM_ID algId;
  TPM_ENC_SCHEME encScheme;
  uint16_t size;
  uint8_t* data;
} TPM_SYMMETRIC_KEY;


typedef struct TPM_BOUND_DATA {
  TPM_STRUCT_VER ver;
  TPM_PAYLOAD_TYPE payload;
  uint8_t* payloadData;
} TPM_BOUND_DATA;


typedef struct TPM_KEY_PARMS {
  TPM_ALGORITHM_ID algorithmID;
  TPM_ENC_SCHEME encScheme;
  TPM_SIG_SCHEME sigScheme;
  uint32_t parmSize;
  uint8_t* parms;
} TPM_KEY_PARMS;


typedef struct TPM_RSA_KEY_PARMS {
  uint32_t keyLength;
  uint32_t numPrimes;
  uint32_t exponentSize;
  uint8_t* exponent;
} TPM_RSA_KEY_PARMS;


typedef struct TPM_SYMMETRIC_KEY_PARMS {
  uint32_t keyLength;
  uint32_t blockSize;
  uint32_t ivSize;
  uint8_t* IV;
} TPM_SYMMETRIC_KEY_PARMS;


typedef struct TPM_STORE_PUBKEY {
  uint32_t keyLength;
  uint8_t* key;
} TPM_STORE_PUBKEY;


typedef struct TPM_PUBKEY {
  TPM_KEY_PARMS algorithmParms;
  TPM_STORE_PUBKEY pubKey;
} TPM_PUBKEY;


typedef struct TPM_STORE_PRIVKEY {
  uint32_t keyLength;
  uint8_t* key;
} TPM_STORE_PRIVKEY;


typedef struct TPM_STORE_ASYMKEY {
  TPM_PAYLOAD_TYPE payload;
  TPM_SECRET usageAuth;
  TPM_SECRET migrationAuth;
  TPM_DIGEST pubDataDigest;
  TPM_STORE_PRIVKEY privKey;
} TPM_STORE_ASYMKEY;


typedef struct TPM_KEY {
  TPM_STRUCT_VER ver;
  TPM_KEY_USAGE keyUsage;
  TPM_KEY_FLAGS keyFlags;
  TPM_AUTH_DATA_USAGE authDataUsage;
  TPM_KEY_PARMS algorithmParms;
  uint32_t PCRInfoSize;
  uint8_t* PCRInfo;
  TPM_STORE_PUBKEY pubKey;
  uint32_t encSize;
  uint8_t* encData;
} TPM_KEY;


typedef struct TPM_KEY12 {
  TPM_STRUCTURE_TAG tag;
  uint16_t fill;
  TPM_KEY_USAGE keyUsage;
  TPM_KEY_FLAGS keyFlags;
  TPM_AUTH_DATA_USAGE authDataUsage;
  TPM_KEY_PARMS algorithmParms;
  uint32_t PCRInfoSize;
  uint8_t* PCRInfo;
  TPM_STORE_PUBKEY pubKey;
  uint32_t encSize;
  uint8_t* encData;
} TPM_KEY12;


typedef struct TPM_MIGRATE_ASYMKEY {
  TPM_PAYLOAD_TYPE payload;
  TPM_SECRET usageAuth;
  TPM_DIGEST pubDataDigest;
  uint32_t partPrivKeyLen;
  uint8_t* partPrivKey;
} TPM_MIGRATE_ASYMKEY;

typedef uint32_t TPM_KEY_CONTROL;

typedef struct TPM_MIGRATIONKEYAUTH {
  TPM_PUBKEY migrationKey;
  TPM_MIGRATE_SCHEME migrationScheme;
  TPM_DIGEST digest;
} TPM_MIGRATIONKEYAUTH;


typedef struct TPM_CERTIFY_INFO {
  TPM_STRUCT_VER version;
  TPM_KEY_USAGE keyUsage;
  TPM_KEY_FLAGS keyFlags;
  TPM_AUTH_DATA_USAGE authDataUsage;
  TPM_KEY_PARMS algorithmParms;
  TPM_DIGEST pubkeyDigest;
  TPM_NONCE data;
  TPM_BOOL parentPCRStatus;
  uint32_t PCRInfoSize;
  uint8_t* PCRInfo;
} TPM_CERTIFY_INFO;


typedef struct TPM_CERTIFY_INFO2 {
  TPM_STRUCTURE_TAG tag;
  uint8_t fill;
  TPM_PAYLOAD_TYPE payloadType;
  TPM_KEY_USAGE keyUsage;
  TPM_KEY_FLAGS keyFlags;
  TPM_AUTH_DATA_USAGE authDataUsage;
  TPM_KEY_PARMS algorithmParms;
  TPM_DIGEST pubkeyDigest;
  TPM_NONCE data;
  TPM_BOOL parentPCRStatus;
  uint32_t PCRInfoSize;
  uint8_t* PCRInfo;
  uint32_t migrationAuthoritySize;
  uint8_t* migrationAuthority;
} TPM_CERTIFY_INFO2;


typedef struct TPM_QUOTE_INFO {
  TPM_STRUCT_VER version;
  uint8_t fixed[4];
  TPM_COMPOSITE_HASH compositeHash;
  TPM_NONCE externalData;
} TPM_QUOTE_INFO;


typedef struct TPM_QUOTE_INFO2 {
  TPM_STRUCTURE_TAG tag;
  uint8_t fixed[4];
  TPM_NONCE externalData;
  TPM_PCR_INFO_SHORT infoShort;
} TPM_QUOTE_INFO2;


typedef struct TPM_EK_BLOB {
  TPM_STRUCTURE_TAG tag;
  TPM_EK_TYPE ekType;
  uint32_t blobSize;
  uint8_t* blob;
} TPM_EK_BLOB;


typedef struct TPM_EK_BLOB_ACTIVATE {
  TPM_STRUCTURE_TAG tag;
  TPM_SYMMETRIC_KEY sessionKey;
  TPM_DIGEST idDigest;
  TPM_PCR_INFO_SHORT pcrInfo;
} TPM_EK_BLOB_ACTIVATE;


typedef struct TPM_EK_BLOB_AUTH {
  TPM_STRUCTURE_TAG tag;
  TPM_SECRET authValue;
} TPM_EK_BLOB_AUTH;

typedef TPM_DIGEST TPM_CHOSENID_HASH;

typedef struct TPM_IDENTITY_CONTENTS {
  TPM_STRUCT_VER ver;
  uint32_t ordinal;
  TPM_CHOSENID_HASH labelPrivCADigest;
  TPM_PUBKEY identityPubKey;
} TPM_IDENTITY_CONTENTS;


typedef struct TPM_IDENTITY_REQ {
  uint32_t asymSize;
  uint32_t symSize;
  TPM_KEY_PARMS asymAlgorithm;
  TPM_KEY_PARMS symAlgorithm;
  uint8_t* asymBlob;
  uint8_t* symBlob;
} TPM_IDENTITY_REQ;


typedef struct TPM_IDENTITY_PROOF {
  TPM_STRUCT_VER ver;
  uint32_t labelSize;
  uint32_t identityBindingSize;
  uint32_t endorsementSize;
  uint32_t platformSize;
  uint32_t conformanceSize;
  TPM_PUBKEY identityKey;
  uint8_t* labelArea;
  uint8_t* identityBinding;
  uint8_t* endorsementCredential;
  uint8_t* platformCredential;
  uint8_t* conformanceCredential;
} TPM_IDENTITY_PROOF;


typedef struct TPM_ASYM_CA_CONTENTS {
  TPM_SYMMETRIC_KEY sessionKey;
  TPM_DIGEST idDigest;
} TPM_ASYM_CA_CONTENTS;


typedef struct TPM_SYM_CA_ATTESTATION {
  uint32_t credSize;
  TPM_KEY_PARMS algorithm;
  uint8_t* credential;
} TPM_SYM_CA_ATTESTATION;


typedef struct TPM_CURRENT_TICKS {
  TPM_STRUCTURE_TAG tag;
  uint64_t currentTicks;
  uint16_t tickRate;
  TPM_NONCE tickNonce;
} TPM_CURRENT_TICKS;

typedef uint32_t TPM_TRANSPORT_ATTRIBUTES;

typedef struct TPM_TRANSPORT_PUBLIC {
  TPM_STRUCTURE_TAG tag;
  TPM_TRANSPORT_ATTRIBUTES transAttributes;
  TPM_ALGORITHM_ID algId;
  TPM_ENC_SCHEME encScheme;
} TPM_TRANSPORT_PUBLIC;


typedef struct TPM_TRANSPORT_INTERNAL {
  TPM_STRUCTURE_TAG tag;
  TPM_AUTHDATA authData;
  TPM_TRANSPORT_PUBLIC transPublic;
  TPM_TRANSHANDLE transHandle;
  TPM_NONCE transNonceEven;
  TPM_DIGEST transDigest;
} TPM_TRANSPORT_INTERNAL;


typedef struct TPM_TRANSPORT_LOG_IN {
  TPM_STRUCTURE_TAG tag;
  TPM_DIGEST parameters;
  TPM_DIGEST pubKeyHash;
} TPM_TRANSPORT_LOG_IN;


typedef struct TPM_TRANSPORT_LOG_OUT {
  TPM_STRUCTURE_TAG tag;
  TPM_CURRENT_TICKS currentTicks;
  TPM_DIGEST parameters;
  TPM_MODIFIER_INDICATOR locality;
} TPM_TRANSPORT_LOG_OUT;


typedef struct TPM_TRANSPORT_AUTH {
  TPM_STRUCTURE_TAG tag;
  TPM_AUTHDATA authData;
} TPM_TRANSPORT_AUTH;


typedef struct TPM_AUDIT_EVENT_IN {
  TPM_STRUCTURE_TAG tag;
  TPM_DIGEST inputParms;
  TPM_COUNTER_VALUE auditCount;
} TPM_AUDIT_EVENT_IN;


typedef struct TPM_AUDIT_EVENT_OUT {
  TPM_STRUCTURE_TAG tag;
  TPM_COMMAND_CODE ordinal;
  TPM_DIGEST outputParms;
  TPM_COUNTER_VALUE auditCount;
  TPM_RESULT returnCode;
} TPM_AUDIT_EVENT_OUT;


typedef struct TPM_CONTEXT_BLOB {
  TPM_STRUCTURE_TAG tag;
  TPM_RESOURCE_TYPE resourceType;
  TPM_HANDLE handle;
  uint8_t label[16];
  uint32_t contextCount;
  TPM_DIGEST integrityDigest;
  uint32_t additionalSize;
  uint8_t* additionalData;
  uint32_t sensitiveSize;
  uint8_t* sensitiveData;
} TPM_CONTEXT_BLOB;


typedef struct TPM_CONTEXT_SENSITIVE {
  TPM_STRUCTURE_TAG tag;
  TPM_NONCE contextNonce;
  uint32_t internalSize;
  uint8_t* internalData;
} TPM_CONTEXT_SENSITIVE;

typedef uint32_t TPM_NV_INDEX;
typedef uint32_t TPM_NV_PER_ATTRIBUTES;

typedef struct TPM_NV_ATTRIBUTES {
  TPM_STRUCTURE_TAG tag;
  TPM_NV_PER_ATTRIBUTES attributes;
} TPM_NV_ATTRIBUTES;


typedef struct TPM_NV_DATA_PUBLIC {
  TPM_STRUCTURE_TAG tag;
  TPM_NV_INDEX nvIndex;
  TPM_PCR_INFO_SHORT pcrInfoRead;
  TPM_PCR_INFO_SHORT pcrInfoWrite;
  TPM_NV_ATTRIBUTES permission;
  TPM_BOOL bReadSTClear;
  TPM_BOOL bWriteSTClear;
  TPM_BOOL bWriteDefine;
  uint32_t dataSize;
} TPM_NV_DATA_PUBLIC;

typedef uint32_t TPM_FAMILY_VERIFICATION;
typedef uint32_t TPM_FAMILY_ID;
typedef uint32_t TPM_DELEGATE_INDEX;
typedef uint32_t TPM_FAMILY_OPERATION;
typedef uint32_t TPM_FAMILY_FLAGS;

typedef struct TPM_FAMILY_LABEL {
  uint8_t label;
} TPM_FAMILY_LABEL;


typedef struct TPM_FAMILY_TABLE_ENTRY {
  TPM_STRUCTURE_TAG tag;
  TPM_FAMILY_LABEL label;
  TPM_FAMILY_ID familyID;
  TPM_FAMILY_VERIFICATION verificationCount;
  TPM_FAMILY_FLAGS flags;
} TPM_FAMILY_TABLE_ENTRY;


typedef struct TPM_DELEGATE_LABEL {
  uint8_t label;
} TPM_DELEGATE_LABEL;

typedef uint32_t TPM_DELEGATE_TYPE;

typedef struct TPM_DELEGATIONS {
  TPM_STRUCTURE_TAG tag;
  TPM_DELEGATE_TYPE delegateType;
  uint32_t per1;
  uint32_t per2;
} TPM_DELEGATIONS;


typedef struct TPM_DELEGATE_PUBLIC {
  TPM_STRUCTURE_TAG tag;
  TPM_DELEGATE_LABEL label;
  TPM_PCR_INFO_SHORT pcrInfo;
  TPM_DELEGATIONS permissions;
  TPM_FAMILY_ID familyID;
  TPM_FAMILY_VERIFICATION verificationCount;
} TPM_DELEGATE_PUBLIC;


typedef struct TPM_DELEGATE_TABLE_ROW {
  TPM_STRUCTURE_TAG tag;
  TPM_DELEGATE_PUBLIC pub;
  TPM_SECRET authValue;
} TPM_DELEGATE_TABLE_ROW;


typedef struct TPM_DELEGATE_SENSITIVE {
  TPM_STRUCTURE_TAG tag;
  TPM_SECRET authValue;
} TPM_DELEGATE_SENSITIVE;


typedef struct TPM_DELEGATE_OWNER_BLOB {
  TPM_STRUCTURE_TAG tag;
  TPM_DELEGATE_PUBLIC pub;
  TPM_DIGEST integrityDigest;
  uint32_t additionalSize;
  uint8_t* additionalArea;
  uint32_t sensitiveSize;
  uint8_t* sensitiveArea;
} TPM_DELEGATE_OWNER_BLOB;


typedef struct TPM_DELEGATE_KEY_BLOB {
  TPM_STRUCTURE_TAG tag;
  TPM_DELEGATE_PUBLIC pub;
  TPM_DIGEST integrityDigest;
  TPM_DIGEST pubKeyDigest;
  uint32_t additionalSize;
  uint8_t* additionalArea;
  uint32_t sensitiveSize;
  uint8_t* sensitiveArea;
} TPM_DELEGATE_KEY_BLOB;

typedef uint32_t TPM_CAPABILITY_AREA;

typedef struct TPM_CAP_VERSION_INFO {
  TPM_STRUCTURE_TAG tag;
  TPM_VERSION version;
  uint16_t specLevel;
  uint8_t errataRev;
  uint8_t tpmVendorID[4];
  uint16_t vendorSpecificSize;
  uint8_t* vendorSpecific;
} TPM_CAP_VERSION_INFO;


typedef struct TPM_DAA_ISSUER {
  TPM_STRUCTURE_TAG tag;
  TPM_DIGEST DAA_digest_R0;
  TPM_DIGEST DAA_digest_R1;
  TPM_DIGEST DAA_digest_S0;
  TPM_DIGEST DAA_digest_S1;
  TPM_DIGEST DAA_digest_n;
  TPM_DIGEST DAA_digest_gamma;
  uint8_t DAA_generic_q[26];
} TPM_DAA_ISSUER;


typedef struct TPM_DAA_TPM {
  TPM_STRUCTURE_TAG tag;
  TPM_DIGEST DAA_digestIssuer;
  TPM_DIGEST DAA_digest_v0;
  TPM_DIGEST DAA_digest_v1;
  TPM_DIGEST DAA_rekey;
  uint32_t DAA_count;
} TPM_DAA_TPM;


typedef struct TPM_DAA_CONTEXT {
  TPM_STRUCTURE_TAG tag;
  TPM_DIGEST DAA_digestContext;
  TPM_DIGEST DAA_digest;
  TPM_DAA_CONTEXT_SEED DAA_contextSeed;
  uint8_t DAA_scratch[256];
  uint8_t DAA_stage;
} TPM_DAA_CONTEXT;


typedef struct TPM_DAA_JOINDATA {
  uint8_t DAA_join_u0[128];
  uint8_t DAA_join_u1[138];
  TPM_DIGEST DAA_digest_n0;
} TPM_DAA_JOINDATA;


typedef struct TPM_DAA_BLOB {
  TPM_STRUCTURE_TAG tag;
  TPM_RESOURCE_TYPE resourceType;
  uint8_t label[16];
  TPM_DIGEST blobIntegrity;
  uint32_t additionalSize;
  uint8_t* additionalData;
  uint32_t sensitiveSize;
  uint8_t* sensitiveData;
} TPM_DAA_BLOB;


typedef struct TPM_DAA_SENSITIVE {
  TPM_STRUCTURE_TAG tag;
  uint32_t internalSize;
  uint8_t* internalData;
} TPM_DAA_SENSITIVE;

typedef uint32_t TPM_SYM_MODE;

#endif  /* TRUNKS_G_TPM_STRUCTURES_H_ */
