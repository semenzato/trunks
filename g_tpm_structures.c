/* Copyright (c) 2011 The Chromium OS Authors. All rights reserved.
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include <stdint.h>
#include <string.h>

#include "g_tpm_structures.h"
#include "trunks_internal.h"
#include "g_tpm_commands.h"

uint8_t StructureByteCodes[] = {

/* Record: TPM_STRUCT_VER */
/* (0000) */ BC_RECORD,
/* (0001) */ 4,
/* Field: major */
/* (0002) */ BC_FIELD_KIND_NORMAL,
/* (0003) */ OFFSETOF_TWO_BYTES(major, TPM_STRUCT_VER),
/* (0005) */ BC_INT8,
/* Field: minor */
/* (0006) */ BC_FIELD_KIND_NORMAL,
/* (0007) */ OFFSETOF_TWO_BYTES(minor, TPM_STRUCT_VER),
/* (0009) */ BC_INT8,
/* Field: revMajor */
/* (0010) */ BC_FIELD_KIND_NORMAL,
/* (0011) */ OFFSETOF_TWO_BYTES(revMajor, TPM_STRUCT_VER),
/* (0013) */ BC_INT8,
/* Field: revMinor */
/* (0014) */ BC_FIELD_KIND_NORMAL,
/* (0015) */ OFFSETOF_TWO_BYTES(revMinor, TPM_STRUCT_VER),
/* (0017) */ BC_INT8,
/* Record: TPM_VERSION */
/* (0018) */ BC_RECORD,
/* (0019) */ 4,
/* Field: major */
/* (0020) */ BC_FIELD_KIND_NORMAL,
/* (0021) */ OFFSETOF_TWO_BYTES(major, TPM_VERSION),
/* (0023) */ BC_INT8,
/* Field: minor */
/* (0024) */ BC_FIELD_KIND_NORMAL,
/* (0025) */ OFFSETOF_TWO_BYTES(minor, TPM_VERSION),
/* (0027) */ BC_INT8,
/* Field: revMajor */
/* (0028) */ BC_FIELD_KIND_NORMAL,
/* (0029) */ OFFSETOF_TWO_BYTES(revMajor, TPM_VERSION),
/* (0031) */ BC_INT8,
/* Field: revMinor */
/* (0032) */ BC_FIELD_KIND_NORMAL,
/* (0033) */ OFFSETOF_TWO_BYTES(revMinor, TPM_VERSION),
/* (0035) */ BC_INT8,
/* Record: TPM_DIGEST */
/* (0036) */ BC_RECORD,
/* (0037) */ 1,
/* Array field: digest */
/* (0038) */ BC_ARRAY,
/* (0039) */ TWO_BYTES_INT(TPM_SHA1_160_HASH_LEN),
/* (0041) */ BC_INT8,
/* Record: TPM_NONCE */
/* (0042) */ BC_RECORD,
/* (0043) */ 1,
/* Array field: nonce */
/* (0044) */ BC_ARRAY,
/* (0045) */ TWO_BYTES_INT(TPM_SHA1BASED_NONCE_LEN),
/* (0047) */ BC_INT8,
/* Record: TPM_AUTHDATA */
/* (0048) */ BC_RECORD,
/* (0049) */ 1,
/* Array field: authdata */
/* (0050) */ BC_ARRAY,
/* (0051) */ TWO_BYTES_INT(TPM_SHA1_160_HASH_LEN),
/* (0053) */ BC_INT8,
/* Record: TPM_CHANGEAUTH_VALIDATE */
/* (0054) */ BC_RECORD,
/* (0055) */ 2,
/* Field: newAuthSecret */
/* (0056) */ BC_FIELD_KIND_NORMAL,
/* (0057) */ OFFSETOF_TWO_BYTES(newAuthSecret, TPM_CHANGEAUTH_VALIDATE),
/* (0059) */ BC_REF,
/* (0060) varint: 48 */ 48,
/* Field: n1 */
/* (0061) */ BC_FIELD_KIND_NORMAL,
/* (0062) */ OFFSETOF_TWO_BYTES(n1, TPM_CHANGEAUTH_VALIDATE),
/* (0064) */ BC_REF,
/* (0065) varint: 42 */ 42,
/* Record: TPM_COUNTER_VALUE */
/* (0066) */ BC_RECORD,
/* (0067) */ 3,
/* Field: tag */
/* (0068) */ BC_FIELD_KIND_NORMAL,
/* (0069) */ OFFSETOF_TWO_BYTES(tag, TPM_COUNTER_VALUE),
/* (0071) */ BC_INT16,
/* Array field: label */
/* (0072) */ BC_ARRAY,
/* (0073) */ TWO_BYTES_INT(4),
/* (0075) */ BC_INT8,
/* Field: counter */
/* (0076) */ BC_FIELD_KIND_NORMAL,
/* (0077) */ OFFSETOF_TWO_BYTES(counter, TPM_COUNTER_VALUE),
/* (0079) */ BC_INT32,
/* Record: TPM_SIGN_INFO */
/* (0080) */ BC_RECORD,
/* (0081) */ 5,
/* Field: tag */
/* (0082) */ BC_FIELD_KIND_NORMAL,
/* (0083) */ OFFSETOF_TWO_BYTES(tag, TPM_SIGN_INFO),
/* (0085) */ BC_INT16,
/* Array field: fixed */
/* (0086) */ BC_ARRAY,
/* (0087) */ TWO_BYTES_INT(4),
/* (0089) */ BC_INT8,
/* Field: replay */
/* (0090) */ BC_FIELD_KIND_NORMAL,
/* (0091) */ OFFSETOF_TWO_BYTES(replay, TPM_SIGN_INFO),
/* (0093) */ BC_REF,
/* (0094) varint: 42 */ 42,
/* Field: dataLen */
/* (0095) */ BC_FIELD_KIND_NORMAL,
/* (0096) */ OFFSETOF_TWO_BYTES(dataLen, TPM_SIGN_INFO),
/* (0098) */ BC_INT32,
/* Variable-length field: data */
/* (0099) */ BC_FIELD_KIND_VARIABLE,
/* (0100) */ OFFSETOF_TWO_BYTES(data, TPM_SIGN_INFO),
/* (0102) */ 3,
/* (0103) */ BC_INT8,
/* Record: TPM_MSA_COMPOSITE */
/* (0104) */ BC_RECORD,
/* (0105) */ 2,
/* Field: MSAlist */
/* (0106) */ BC_FIELD_KIND_NORMAL,
/* (0107) */ OFFSETOF_TWO_BYTES(MSAlist, TPM_MSA_COMPOSITE),
/* (0109) */ BC_INT32,
/* Variable-length field: migAuthDigest */
/* (0110) */ BC_FIELD_KIND_VARIABLE,
/* (0111) */ OFFSETOF_TWO_BYTES(migAuthDigest, TPM_MSA_COMPOSITE),
/* (0113) */ 0,
/* (0114) */ BC_REF,
/* (0115) varint: 36 */ 36,
/* Record: TPM_CMK_AUTH */
/* (0116) */ BC_RECORD,
/* (0117) */ 3,
/* Field: migrationAuthorityDigest */
/* (0118) */ BC_FIELD_KIND_NORMAL,
/* (0119) */ OFFSETOF_TWO_BYTES(migrationAuthorityDigest, TPM_CMK_AUTH),
/* (0121) */ BC_REF,
/* (0122) varint: 36 */ 36,
/* Field: destinationKeyDigest */
/* (0123) */ BC_FIELD_KIND_NORMAL,
/* (0124) */ OFFSETOF_TWO_BYTES(destinationKeyDigest, TPM_CMK_AUTH),
/* (0126) */ BC_REF,
/* (0127) varint: 36 */ 36,
/* Field: sourceKeyDigest */
/* (0128) */ BC_FIELD_KIND_NORMAL,
/* (0129) */ OFFSETOF_TWO_BYTES(sourceKeyDigest, TPM_CMK_AUTH),
/* (0131) */ BC_REF,
/* (0132) varint: 36 */ 36,
/* Record: TPM_SELECT_SIZE */
/* (0133) */ BC_RECORD,
/* (0134) */ 3,
/* Field: major */
/* (0135) */ BC_FIELD_KIND_NORMAL,
/* (0136) */ OFFSETOF_TWO_BYTES(major, TPM_SELECT_SIZE),
/* (0138) */ BC_INT8,
/* Field: minor */
/* (0139) */ BC_FIELD_KIND_NORMAL,
/* (0140) */ OFFSETOF_TWO_BYTES(minor, TPM_SELECT_SIZE),
/* (0142) */ BC_INT8,
/* Field: reqSize */
/* (0143) */ BC_FIELD_KIND_NORMAL,
/* (0144) */ OFFSETOF_TWO_BYTES(reqSize, TPM_SELECT_SIZE),
/* (0146) */ BC_INT16,
/* Record: TPM_CMK_MIGAUTH */
/* (0147) */ BC_RECORD,
/* (0148) */ 3,
/* Field: tag */
/* (0149) */ BC_FIELD_KIND_NORMAL,
/* (0150) */ OFFSETOF_TWO_BYTES(tag, TPM_CMK_MIGAUTH),
/* (0152) */ BC_INT16,
/* Field: msaDigest */
/* (0153) */ BC_FIELD_KIND_NORMAL,
/* (0154) */ OFFSETOF_TWO_BYTES(msaDigest, TPM_CMK_MIGAUTH),
/* (0156) */ BC_REF,
/* (0157) varint: 36 */ 36,
/* Field: pubKeyDigest */
/* (0158) */ BC_FIELD_KIND_NORMAL,
/* (0159) */ OFFSETOF_TWO_BYTES(pubKeyDigest, TPM_CMK_MIGAUTH),
/* (0161) */ BC_REF,
/* (0162) varint: 36 */ 36,
/* Record: TPM_CMK_SIGTICKET */
/* (0163) */ BC_RECORD,
/* (0164) */ 3,
/* Field: tag */
/* (0165) */ BC_FIELD_KIND_NORMAL,
/* (0166) */ OFFSETOF_TWO_BYTES(tag, TPM_CMK_SIGTICKET),
/* (0168) */ BC_INT16,
/* Field: verKeyDigest */
/* (0169) */ BC_FIELD_KIND_NORMAL,
/* (0170) */ OFFSETOF_TWO_BYTES(verKeyDigest, TPM_CMK_SIGTICKET),
/* (0172) */ BC_REF,
/* (0173) varint: 36 */ 36,
/* Field: signedData */
/* (0174) */ BC_FIELD_KIND_NORMAL,
/* (0175) */ OFFSETOF_TWO_BYTES(signedData, TPM_CMK_SIGTICKET),
/* (0177) */ BC_REF,
/* (0178) varint: 36 */ 36,
/* Record: TPM_CMK_MA_APPROVAL */
/* (0179) */ BC_RECORD,
/* (0180) */ 2,
/* Field: tag */
/* (0181) */ BC_FIELD_KIND_NORMAL,
/* (0182) */ OFFSETOF_TWO_BYTES(tag, TPM_CMK_MA_APPROVAL),
/* (0184) */ BC_INT16,
/* Field: migrationAuthorityDigest */
/* (0185) */ BC_FIELD_KIND_NORMAL,
/* (0186) */ OFFSETOF_TWO_BYTES(migrationAuthorityDigest, TPM_CMK_MA_APPROVAL),
/* (0188) */ BC_REF,
/* (0189) varint: 36 */ 36,
/* Record: TPM_PERMANENT_FLAGS */
/* (0190) */ BC_RECORD,
/* (0191) */ 20,
/* Field: tag */
/* (0192) */ BC_FIELD_KIND_NORMAL,
/* (0193) */ OFFSETOF_TWO_BYTES(tag, TPM_PERMANENT_FLAGS),
/* (0195) */ BC_INT16,
/* Field: disable */
/* (0196) */ BC_FIELD_KIND_NORMAL,
/* (0197) */ OFFSETOF_TWO_BYTES(disable, TPM_PERMANENT_FLAGS),
/* (0199) */ BC_INT8,
/* Field: ownership */
/* (0200) */ BC_FIELD_KIND_NORMAL,
/* (0201) */ OFFSETOF_TWO_BYTES(ownership, TPM_PERMANENT_FLAGS),
/* (0203) */ BC_INT8,
/* Field: deactivated */
/* (0204) */ BC_FIELD_KIND_NORMAL,
/* (0205) */ OFFSETOF_TWO_BYTES(deactivated, TPM_PERMANENT_FLAGS),
/* (0207) */ BC_INT8,
/* Field: readPubek */
/* (0208) */ BC_FIELD_KIND_NORMAL,
/* (0209) */ OFFSETOF_TWO_BYTES(readPubek, TPM_PERMANENT_FLAGS),
/* (0211) */ BC_INT8,
/* Field: disableOwnerClear */
/* (0212) */ BC_FIELD_KIND_NORMAL,
/* (0213) */ OFFSETOF_TWO_BYTES(disableOwnerClear, TPM_PERMANENT_FLAGS),
/* (0215) */ BC_INT8,
/* Field: allowMaintenance */
/* (0216) */ BC_FIELD_KIND_NORMAL,
/* (0217) */ OFFSETOF_TWO_BYTES(allowMaintenance, TPM_PERMANENT_FLAGS),
/* (0219) */ BC_INT8,
/* Field: physicalPresenceLifetimeLock */
/* (0220) */ BC_FIELD_KIND_NORMAL,
/* (0221) */ OFFSETOF_TWO_BYTES(physicalPresenceLifetimeLock, TPM_PERMANENT_FLAGS),
/* (0223) */ BC_INT8,
/* Field: physicalPresenceHWEnable */
/* (0224) */ BC_FIELD_KIND_NORMAL,
/* (0225) */ OFFSETOF_TWO_BYTES(physicalPresenceHWEnable, TPM_PERMANENT_FLAGS),
/* (0227) */ BC_INT8,
/* Field: physicalPresenceCMDEnable */
/* (0228) */ BC_FIELD_KIND_NORMAL,
/* (0229) */ OFFSETOF_TWO_BYTES(physicalPresenceCMDEnable, TPM_PERMANENT_FLAGS),
/* (0231) */ BC_INT8,
/* Field: CEKPUsed */
/* (0232) */ BC_FIELD_KIND_NORMAL,
/* (0233) */ OFFSETOF_TWO_BYTES(CEKPUsed, TPM_PERMANENT_FLAGS),
/* (0235) */ BC_INT8,
/* Field: TPMpost */
/* (0236) */ BC_FIELD_KIND_NORMAL,
/* (0237) */ OFFSETOF_TWO_BYTES(TPMpost, TPM_PERMANENT_FLAGS),
/* (0239) */ BC_INT8,
/* Field: TPMpostLock */
/* (0240) */ BC_FIELD_KIND_NORMAL,
/* (0241) */ OFFSETOF_TWO_BYTES(TPMpostLock, TPM_PERMANENT_FLAGS),
/* (0243) */ BC_INT8,
/* Field: FIPS */
/* (0244) */ BC_FIELD_KIND_NORMAL,
/* (0245) */ OFFSETOF_TWO_BYTES(FIPS, TPM_PERMANENT_FLAGS),
/* (0247) */ BC_INT8,
/* Field: Operator */
/* (0248) */ BC_FIELD_KIND_NORMAL,
/* (0249) */ OFFSETOF_TWO_BYTES(Operator, TPM_PERMANENT_FLAGS),
/* (0251) */ BC_INT8,
/* Field: enableRevokeEK */
/* (0252) */ BC_FIELD_KIND_NORMAL,
/* (0253) */ OFFSETOF_TWO_BYTES(enableRevokeEK, TPM_PERMANENT_FLAGS),
/* (0255) */ BC_INT8,
/* Field: nvLocked */
/* (0256) */ BC_FIELD_KIND_NORMAL,
/* (0257) */ OFFSETOF_TWO_BYTES(nvLocked, TPM_PERMANENT_FLAGS),
/* (0259) */ BC_INT8,
/* Field: readSRKPub */
/* (0260) */ BC_FIELD_KIND_NORMAL,
/* (0261) */ OFFSETOF_TWO_BYTES(readSRKPub, TPM_PERMANENT_FLAGS),
/* (0263) */ BC_INT8,
/* Field: tpmEstablished */
/* (0264) */ BC_FIELD_KIND_NORMAL,
/* (0265) */ OFFSETOF_TWO_BYTES(tpmEstablished, TPM_PERMANENT_FLAGS),
/* (0267) */ BC_INT8,
/* Field: maintenanceDone */
/* (0268) */ BC_FIELD_KIND_NORMAL,
/* (0269) */ OFFSETOF_TWO_BYTES(maintenanceDone, TPM_PERMANENT_FLAGS),
/* (0271) */ BC_INT8,
/* Record: TPM_STCLEAR_FLAGS */
/* (0272) */ BC_RECORD,
/* (0273) */ 6,
/* Field: tag */
/* (0274) */ BC_FIELD_KIND_NORMAL,
/* (0275) */ OFFSETOF_TWO_BYTES(tag, TPM_STCLEAR_FLAGS),
/* (0277) */ BC_INT16,
/* Field: deactivated */
/* (0278) */ BC_FIELD_KIND_NORMAL,
/* (0279) */ OFFSETOF_TWO_BYTES(deactivated, TPM_STCLEAR_FLAGS),
/* (0281) */ BC_INT8,
/* Field: disableForceClear */
/* (0282) */ BC_FIELD_KIND_NORMAL,
/* (0283) */ OFFSETOF_TWO_BYTES(disableForceClear, TPM_STCLEAR_FLAGS),
/* (0285) */ BC_INT8,
/* Field: physicalPresence */
/* (0286) */ BC_FIELD_KIND_NORMAL,
/* (0287) */ OFFSETOF_TWO_BYTES(physicalPresence, TPM_STCLEAR_FLAGS),
/* (0289) */ BC_INT8,
/* Field: physicalPresenceLock */
/* (0290) */ BC_FIELD_KIND_NORMAL,
/* (0291) */ OFFSETOF_TWO_BYTES(physicalPresenceLock, TPM_STCLEAR_FLAGS),
/* (0293) */ BC_INT8,
/* Field: bGlobalLock */
/* (0294) */ BC_FIELD_KIND_NORMAL,
/* (0295) */ OFFSETOF_TWO_BYTES(bGlobalLock, TPM_STCLEAR_FLAGS),
/* (0297) */ BC_INT8,
/* Record: TPM_STANY_FLAGS */
/* (0298) */ BC_RECORD,
/* (0299) */ 5,
/* Field: tag */
/* (0300) */ BC_FIELD_KIND_NORMAL,
/* (0301) */ OFFSETOF_TWO_BYTES(tag, TPM_STANY_FLAGS),
/* (0303) */ BC_INT16,
/* Field: postInitialise */
/* (0304) */ BC_FIELD_KIND_NORMAL,
/* (0305) */ OFFSETOF_TWO_BYTES(postInitialise, TPM_STANY_FLAGS),
/* (0307) */ BC_INT8,
/* Field: localityModifier */
/* (0308) */ BC_FIELD_KIND_NORMAL,
/* (0309) */ OFFSETOF_TWO_BYTES(localityModifier, TPM_STANY_FLAGS),
/* (0311) */ BC_INT32,
/* Field: transportExclusive */
/* (0312) */ BC_FIELD_KIND_NORMAL,
/* (0313) */ OFFSETOF_TWO_BYTES(transportExclusive, TPM_STANY_FLAGS),
/* (0315) */ BC_INT8,
/* Field: TOSPresent */
/* (0316) */ BC_FIELD_KIND_NORMAL,
/* (0317) */ OFFSETOF_TWO_BYTES(TOSPresent, TPM_STANY_FLAGS),
/* (0319) */ BC_INT8,
/* Record: TPM_PCR_SELECTION */
/* (0320) */ BC_RECORD,
/* (0321) */ 2,
/* Field: sizeOfSelect */
/* (0322) */ BC_FIELD_KIND_NORMAL,
/* (0323) */ OFFSETOF_TWO_BYTES(sizeOfSelect, TPM_PCR_SELECTION),
/* (0325) */ BC_INT16,
/* Variable-length field: pcrSelect */
/* (0326) */ BC_FIELD_KIND_VARIABLE,
/* (0327) */ OFFSETOF_TWO_BYTES(pcrSelect, TPM_PCR_SELECTION),
/* (0329) */ 0,
/* (0330) */ BC_INT8,
/* Record: TPM_PCR_COMPOSITE */
/* (0331) */ BC_RECORD,
/* (0332) */ 3,
/* Field: select */
/* (0333) */ BC_FIELD_KIND_NORMAL,
/* (0334) */ OFFSETOF_TWO_BYTES(select, TPM_PCR_COMPOSITE),
/* (0336) */ BC_REF,
/* (0337) varint: 320 */ 130, 64,
/* Field: valueSize */
/* (0339) */ BC_FIELD_KIND_NORMAL,
/* (0340) */ OFFSETOF_TWO_BYTES(valueSize, TPM_PCR_COMPOSITE),
/* (0342) */ BC_INT32,
/* Variable-length field: pcrValue */
/* (0343) */ BC_FIELD_KIND_VARIABLE,
/* (0344) */ OFFSETOF_TWO_BYTES(pcrValue, TPM_PCR_COMPOSITE),
/* (0346) */ 1,
/* (0347) */ BC_REF,
/* (0348) varint: 36 */ 36,
/* Record: TPM_PCR_INFO */
/* (0349) */ BC_RECORD,
/* (0350) */ 3,
/* Field: pcrSelection */
/* (0351) */ BC_FIELD_KIND_NORMAL,
/* (0352) */ OFFSETOF_TWO_BYTES(pcrSelection, TPM_PCR_INFO),
/* (0354) */ BC_REF,
/* (0355) varint: 320 */ 130, 64,
/* Field: digestAtRelease */
/* (0357) */ BC_FIELD_KIND_NORMAL,
/* (0358) */ OFFSETOF_TWO_BYTES(digestAtRelease, TPM_PCR_INFO),
/* (0360) */ BC_REF,
/* (0361) varint: 36 */ 36,
/* Field: digestAtCreation */
/* (0362) */ BC_FIELD_KIND_NORMAL,
/* (0363) */ OFFSETOF_TWO_BYTES(digestAtCreation, TPM_PCR_INFO),
/* (0365) */ BC_REF,
/* (0366) varint: 36 */ 36,
/* Record: TPM_PCR_INFO_LONG */
/* (0367) */ BC_RECORD,
/* (0368) */ 7,
/* Field: tag */
/* (0369) */ BC_FIELD_KIND_NORMAL,
/* (0370) */ OFFSETOF_TWO_BYTES(tag, TPM_PCR_INFO_LONG),
/* (0372) */ BC_INT16,
/* Field: localityAtCreation */
/* (0373) */ BC_FIELD_KIND_NORMAL,
/* (0374) */ OFFSETOF_TWO_BYTES(localityAtCreation, TPM_PCR_INFO_LONG),
/* (0376) */ BC_INT8,
/* Field: localityAtRelease */
/* (0377) */ BC_FIELD_KIND_NORMAL,
/* (0378) */ OFFSETOF_TWO_BYTES(localityAtRelease, TPM_PCR_INFO_LONG),
/* (0380) */ BC_INT8,
/* Field: creationPCRSelection */
/* (0381) */ BC_FIELD_KIND_NORMAL,
/* (0382) */ OFFSETOF_TWO_BYTES(creationPCRSelection, TPM_PCR_INFO_LONG),
/* (0384) */ BC_REF,
/* (0385) varint: 320 */ 130, 64,
/* Field: releasePCRSelection */
/* (0387) */ BC_FIELD_KIND_NORMAL,
/* (0388) */ OFFSETOF_TWO_BYTES(releasePCRSelection, TPM_PCR_INFO_LONG),
/* (0390) */ BC_REF,
/* (0391) varint: 320 */ 130, 64,
/* Field: digestAtCreation */
/* (0393) */ BC_FIELD_KIND_NORMAL,
/* (0394) */ OFFSETOF_TWO_BYTES(digestAtCreation, TPM_PCR_INFO_LONG),
/* (0396) */ BC_REF,
/* (0397) varint: 36 */ 36,
/* Field: digestAtRelease */
/* (0398) */ BC_FIELD_KIND_NORMAL,
/* (0399) */ OFFSETOF_TWO_BYTES(digestAtRelease, TPM_PCR_INFO_LONG),
/* (0401) */ BC_REF,
/* (0402) varint: 36 */ 36,
/* Record: TPM_PCR_INFO_SHORT */
/* (0403) */ BC_RECORD,
/* (0404) */ 3,
/* Field: pcrSelection */
/* (0405) */ BC_FIELD_KIND_NORMAL,
/* (0406) */ OFFSETOF_TWO_BYTES(pcrSelection, TPM_PCR_INFO_SHORT),
/* (0408) */ BC_REF,
/* (0409) varint: 320 */ 130, 64,
/* Field: localityAtRelease */
/* (0411) */ BC_FIELD_KIND_NORMAL,
/* (0412) */ OFFSETOF_TWO_BYTES(localityAtRelease, TPM_PCR_INFO_SHORT),
/* (0414) */ BC_INT8,
/* Field: digestAtRelease */
/* (0415) */ BC_FIELD_KIND_NORMAL,
/* (0416) */ OFFSETOF_TWO_BYTES(digestAtRelease, TPM_PCR_INFO_SHORT),
/* (0418) */ BC_REF,
/* (0419) varint: 36 */ 36,
/* Record: TPM_PCR_ATTRIBUTES */
/* (0420) */ BC_RECORD,
/* (0421) */ 3,
/* Field: pcrReset */
/* (0422) */ BC_FIELD_KIND_NORMAL,
/* (0423) */ OFFSETOF_TWO_BYTES(pcrReset, TPM_PCR_ATTRIBUTES),
/* (0425) */ BC_INT8,
/* Field: pcrExtendLocal */
/* (0426) */ BC_FIELD_KIND_NORMAL,
/* (0427) */ OFFSETOF_TWO_BYTES(pcrExtendLocal, TPM_PCR_ATTRIBUTES),
/* (0429) */ BC_INT8,
/* Field: pcrResetLocal */
/* (0430) */ BC_FIELD_KIND_NORMAL,
/* (0431) */ OFFSETOF_TWO_BYTES(pcrResetLocal, TPM_PCR_ATTRIBUTES),
/* (0433) */ BC_INT8,
/* Record: TPM_STORED_DATA */
/* (0434) */ BC_RECORD,
/* (0435) */ 5,
/* Field: ver */
/* (0436) */ BC_FIELD_KIND_NORMAL,
/* (0437) */ OFFSETOF_TWO_BYTES(ver, TPM_STORED_DATA),
/* (0439) */ BC_REF,
/* (0440) varint: 0 */ 0,
/* Field: sealInfoSize */
/* (0441) */ BC_FIELD_KIND_NORMAL,
/* (0442) */ OFFSETOF_TWO_BYTES(sealInfoSize, TPM_STORED_DATA),
/* (0444) */ BC_INT32,
/* Variable-length field: sealInfo */
/* (0445) */ BC_FIELD_KIND_VARIABLE,
/* (0446) */ OFFSETOF_TWO_BYTES(sealInfo, TPM_STORED_DATA),
/* (0448) */ 1,
/* (0449) */ BC_INT8,
/* Field: encDataSize */
/* (0450) */ BC_FIELD_KIND_NORMAL,
/* (0451) */ OFFSETOF_TWO_BYTES(encDataSize, TPM_STORED_DATA),
/* (0453) */ BC_INT32,
/* Variable-length field: encData */
/* (0454) */ BC_FIELD_KIND_VARIABLE,
/* (0455) */ OFFSETOF_TWO_BYTES(encData, TPM_STORED_DATA),
/* (0457) */ 3,
/* (0458) */ BC_INT8,
/* Record: TPM_STORED_DATA12 */
/* (0459) */ BC_RECORD,
/* (0460) */ 6,
/* Field: tag */
/* (0461) */ BC_FIELD_KIND_NORMAL,
/* (0462) */ OFFSETOF_TWO_BYTES(tag, TPM_STORED_DATA12),
/* (0464) */ BC_INT16,
/* Field: et */
/* (0465) */ BC_FIELD_KIND_NORMAL,
/* (0466) */ OFFSETOF_TWO_BYTES(et, TPM_STORED_DATA12),
/* (0468) */ BC_INT16,
/* Field: sealInfoSize */
/* (0469) */ BC_FIELD_KIND_NORMAL,
/* (0470) */ OFFSETOF_TWO_BYTES(sealInfoSize, TPM_STORED_DATA12),
/* (0472) */ BC_INT32,
/* Variable-length field: sealInfo */
/* (0473) */ BC_FIELD_KIND_VARIABLE,
/* (0474) */ OFFSETOF_TWO_BYTES(sealInfo, TPM_STORED_DATA12),
/* (0476) */ 2,
/* (0477) */ BC_INT8,
/* Field: encDataSize */
/* (0478) */ BC_FIELD_KIND_NORMAL,
/* (0479) */ OFFSETOF_TWO_BYTES(encDataSize, TPM_STORED_DATA12),
/* (0481) */ BC_INT32,
/* Variable-length field: encData */
/* (0482) */ BC_FIELD_KIND_VARIABLE,
/* (0483) */ OFFSETOF_TWO_BYTES(encData, TPM_STORED_DATA12),
/* (0485) */ 4,
/* (0486) */ BC_INT8,
/* Record: TPM_SEALED_DATA */
/* (0487) */ BC_RECORD,
/* (0488) */ 6,
/* Field: payload */
/* (0489) */ BC_FIELD_KIND_NORMAL,
/* (0490) */ OFFSETOF_TWO_BYTES(payload, TPM_SEALED_DATA),
/* (0492) */ BC_INT8,
/* Field: authData */
/* (0493) */ BC_FIELD_KIND_NORMAL,
/* (0494) */ OFFSETOF_TWO_BYTES(authData, TPM_SEALED_DATA),
/* (0496) */ BC_REF,
/* (0497) varint: 48 */ 48,
/* Field: tpmProof */
/* (0498) */ BC_FIELD_KIND_NORMAL,
/* (0499) */ OFFSETOF_TWO_BYTES(tpmProof, TPM_SEALED_DATA),
/* (0501) */ BC_REF,
/* (0502) varint: 42 */ 42,
/* Field: storedDigest */
/* (0503) */ BC_FIELD_KIND_NORMAL,
/* (0504) */ OFFSETOF_TWO_BYTES(storedDigest, TPM_SEALED_DATA),
/* (0506) */ BC_REF,
/* (0507) varint: 36 */ 36,
/* Field: dataSize */
/* (0508) */ BC_FIELD_KIND_NORMAL,
/* (0509) */ OFFSETOF_TWO_BYTES(dataSize, TPM_SEALED_DATA),
/* (0511) */ BC_INT32,
/* Variable-length field: data */
/* (0512) */ BC_FIELD_KIND_VARIABLE,
/* (0513) */ OFFSETOF_TWO_BYTES(data, TPM_SEALED_DATA),
/* (0515) */ 4,
/* (0516) */ BC_INT8,
/* Record: TPM_SYMMETRIC_KEY */
/* (0517) */ BC_RECORD,
/* (0518) */ 4,
/* Field: algId */
/* (0519) */ BC_FIELD_KIND_NORMAL,
/* (0520) */ OFFSETOF_TWO_BYTES(algId, TPM_SYMMETRIC_KEY),
/* (0522) */ BC_INT32,
/* Field: encScheme */
/* (0523) */ BC_FIELD_KIND_NORMAL,
/* (0524) */ OFFSETOF_TWO_BYTES(encScheme, TPM_SYMMETRIC_KEY),
/* (0526) */ BC_INT16,
/* Field: size */
/* (0527) */ BC_FIELD_KIND_NORMAL,
/* (0528) */ OFFSETOF_TWO_BYTES(size, TPM_SYMMETRIC_KEY),
/* (0530) */ BC_INT16,
/* Variable-length field: data */
/* (0531) */ BC_FIELD_KIND_VARIABLE,
/* (0532) */ OFFSETOF_TWO_BYTES(data, TPM_SYMMETRIC_KEY),
/* (0534) */ 2,
/* (0535) */ BC_INT8,
/* Record: TPM_BOUND_DATA */
/* (0536) */ BC_RECORD,
/* (0537) */ 3,
/* Field: ver */
/* (0538) */ BC_FIELD_KIND_NORMAL,
/* (0539) */ OFFSETOF_TWO_BYTES(ver, TPM_BOUND_DATA),
/* (0541) */ BC_REF,
/* (0542) varint: 0 */ 0,
/* Field: payload */
/* (0543) */ BC_FIELD_KIND_NORMAL,
/* (0544) */ OFFSETOF_TWO_BYTES(payload, TPM_BOUND_DATA),
/* (0546) */ BC_INT8,
/* Variable-length field: payloadData */
/* (0547) */ BC_FIELD_KIND_VARIABLE,
/* (0548) */ OFFSETOF_TWO_BYTES(payloadData, TPM_BOUND_DATA),
/* (0550) */ 1,
/* (0551) */ BC_INT8,
/* Record: TPM_KEY_PARMS */
/* (0552) */ BC_RECORD,
/* (0553) */ 5,
/* Field: algorithmID */
/* (0554) */ BC_FIELD_KIND_NORMAL,
/* (0555) */ OFFSETOF_TWO_BYTES(algorithmID, TPM_KEY_PARMS),
/* (0557) */ BC_INT32,
/* Field: encScheme */
/* (0558) */ BC_FIELD_KIND_NORMAL,
/* (0559) */ OFFSETOF_TWO_BYTES(encScheme, TPM_KEY_PARMS),
/* (0561) */ BC_INT16,
/* Field: sigScheme */
/* (0562) */ BC_FIELD_KIND_NORMAL,
/* (0563) */ OFFSETOF_TWO_BYTES(sigScheme, TPM_KEY_PARMS),
/* (0565) */ BC_INT16,
/* Field: parmSize */
/* (0566) */ BC_FIELD_KIND_NORMAL,
/* (0567) */ OFFSETOF_TWO_BYTES(parmSize, TPM_KEY_PARMS),
/* (0569) */ BC_INT32,
/* Variable-length field: parms */
/* (0570) */ BC_FIELD_KIND_VARIABLE,
/* (0571) */ OFFSETOF_TWO_BYTES(parms, TPM_KEY_PARMS),
/* (0573) */ 3,
/* (0574) */ BC_INT8,
/* Record: TPM_RSA_KEY_PARMS */
/* (0575) */ BC_RECORD,
/* (0576) */ 4,
/* Field: keyLength */
/* (0577) */ BC_FIELD_KIND_NORMAL,
/* (0578) */ OFFSETOF_TWO_BYTES(keyLength, TPM_RSA_KEY_PARMS),
/* (0580) */ BC_INT32,
/* Field: numPrimes */
/* (0581) */ BC_FIELD_KIND_NORMAL,
/* (0582) */ OFFSETOF_TWO_BYTES(numPrimes, TPM_RSA_KEY_PARMS),
/* (0584) */ BC_INT32,
/* Field: exponentSize */
/* (0585) */ BC_FIELD_KIND_NORMAL,
/* (0586) */ OFFSETOF_TWO_BYTES(exponentSize, TPM_RSA_KEY_PARMS),
/* (0588) */ BC_INT32,
/* Variable-length field: exponent */
/* (0589) */ BC_FIELD_KIND_VARIABLE,
/* (0590) */ OFFSETOF_TWO_BYTES(exponent, TPM_RSA_KEY_PARMS),
/* (0592) */ 2,
/* (0593) */ BC_INT8,
/* Record: TPM_SYMMETRIC_KEY_PARMS */
/* (0594) */ BC_RECORD,
/* (0595) */ 4,
/* Field: keyLength */
/* (0596) */ BC_FIELD_KIND_NORMAL,
/* (0597) */ OFFSETOF_TWO_BYTES(keyLength, TPM_SYMMETRIC_KEY_PARMS),
/* (0599) */ BC_INT32,
/* Field: blockSize */
/* (0600) */ BC_FIELD_KIND_NORMAL,
/* (0601) */ OFFSETOF_TWO_BYTES(blockSize, TPM_SYMMETRIC_KEY_PARMS),
/* (0603) */ BC_INT32,
/* Field: ivSize */
/* (0604) */ BC_FIELD_KIND_NORMAL,
/* (0605) */ OFFSETOF_TWO_BYTES(ivSize, TPM_SYMMETRIC_KEY_PARMS),
/* (0607) */ BC_INT32,
/* Variable-length field: IV */
/* (0608) */ BC_FIELD_KIND_VARIABLE,
/* (0609) */ OFFSETOF_TWO_BYTES(IV, TPM_SYMMETRIC_KEY_PARMS),
/* (0611) */ 2,
/* (0612) */ BC_INT8,
/* Record: TPM_STORE_PUBKEY */
/* (0613) */ BC_RECORD,
/* (0614) */ 2,
/* Field: keyLength */
/* (0615) */ BC_FIELD_KIND_NORMAL,
/* (0616) */ OFFSETOF_TWO_BYTES(keyLength, TPM_STORE_PUBKEY),
/* (0618) */ BC_INT32,
/* Variable-length field: key */
/* (0619) */ BC_FIELD_KIND_VARIABLE,
/* (0620) */ OFFSETOF_TWO_BYTES(key, TPM_STORE_PUBKEY),
/* (0622) */ 0,
/* (0623) */ BC_INT8,
/* Record: TPM_PUBKEY */
/* (0624) */ BC_RECORD,
/* (0625) */ 2,
/* Field: algorithmParms */
/* (0626) */ BC_FIELD_KIND_NORMAL,
/* (0627) */ OFFSETOF_TWO_BYTES(algorithmParms, TPM_PUBKEY),
/* (0629) */ BC_REF,
/* (0630) varint: 552 */ 132, 40,
/* Field: pubKey */
/* (0632) */ BC_FIELD_KIND_NORMAL,
/* (0633) */ OFFSETOF_TWO_BYTES(pubKey, TPM_PUBKEY),
/* (0635) */ BC_REF,
/* (0636) varint: 613 */ 132, 101,
/* Record: TPM_STORE_PRIVKEY */
/* (0638) */ BC_RECORD,
/* (0639) */ 2,
/* Field: keyLength */
/* (0640) */ BC_FIELD_KIND_NORMAL,
/* (0641) */ OFFSETOF_TWO_BYTES(keyLength, TPM_STORE_PRIVKEY),
/* (0643) */ BC_INT32,
/* Variable-length field: key */
/* (0644) */ BC_FIELD_KIND_VARIABLE,
/* (0645) */ OFFSETOF_TWO_BYTES(key, TPM_STORE_PRIVKEY),
/* (0647) */ 0,
/* (0648) */ BC_INT8,
/* Record: TPM_STORE_ASYMKEY */
/* (0649) */ BC_RECORD,
/* (0650) */ 5,
/* Field: payload */
/* (0651) */ BC_FIELD_KIND_NORMAL,
/* (0652) */ OFFSETOF_TWO_BYTES(payload, TPM_STORE_ASYMKEY),
/* (0654) */ BC_INT8,
/* Field: usageAuth */
/* (0655) */ BC_FIELD_KIND_NORMAL,
/* (0656) */ OFFSETOF_TWO_BYTES(usageAuth, TPM_STORE_ASYMKEY),
/* (0658) */ BC_REF,
/* (0659) varint: 48 */ 48,
/* Field: migrationAuth */
/* (0660) */ BC_FIELD_KIND_NORMAL,
/* (0661) */ OFFSETOF_TWO_BYTES(migrationAuth, TPM_STORE_ASYMKEY),
/* (0663) */ BC_REF,
/* (0664) varint: 48 */ 48,
/* Field: pubDataDigest */
/* (0665) */ BC_FIELD_KIND_NORMAL,
/* (0666) */ OFFSETOF_TWO_BYTES(pubDataDigest, TPM_STORE_ASYMKEY),
/* (0668) */ BC_REF,
/* (0669) varint: 36 */ 36,
/* Field: privKey */
/* (0670) */ BC_FIELD_KIND_NORMAL,
/* (0671) */ OFFSETOF_TWO_BYTES(privKey, TPM_STORE_ASYMKEY),
/* (0673) */ BC_REF,
/* (0674) varint: 638 */ 132, 126,
/* Record: TPM_KEY */
/* (0676) */ BC_RECORD,
/* (0677) */ 10,
/* Field: ver */
/* (0678) */ BC_FIELD_KIND_NORMAL,
/* (0679) */ OFFSETOF_TWO_BYTES(ver, TPM_KEY),
/* (0681) */ BC_REF,
/* (0682) varint: 0 */ 0,
/* Field: keyUsage */
/* (0683) */ BC_FIELD_KIND_NORMAL,
/* (0684) */ OFFSETOF_TWO_BYTES(keyUsage, TPM_KEY),
/* (0686) */ BC_INT16,
/* Field: keyFlags */
/* (0687) */ BC_FIELD_KIND_NORMAL,
/* (0688) */ OFFSETOF_TWO_BYTES(keyFlags, TPM_KEY),
/* (0690) */ BC_INT32,
/* Field: authDataUsage */
/* (0691) */ BC_FIELD_KIND_NORMAL,
/* (0692) */ OFFSETOF_TWO_BYTES(authDataUsage, TPM_KEY),
/* (0694) */ BC_INT8,
/* Field: algorithmParms */
/* (0695) */ BC_FIELD_KIND_NORMAL,
/* (0696) */ OFFSETOF_TWO_BYTES(algorithmParms, TPM_KEY),
/* (0698) */ BC_REF,
/* (0699) varint: 552 */ 132, 40,
/* Field: PCRInfoSize */
/* (0701) */ BC_FIELD_KIND_NORMAL,
/* (0702) */ OFFSETOF_TWO_BYTES(PCRInfoSize, TPM_KEY),
/* (0704) */ BC_INT32,
/* Variable-length field: PCRInfo */
/* (0705) */ BC_FIELD_KIND_VARIABLE,
/* (0706) */ OFFSETOF_TWO_BYTES(PCRInfo, TPM_KEY),
/* (0708) */ 5,
/* (0709) */ BC_INT8,
/* Field: pubKey */
/* (0710) */ BC_FIELD_KIND_NORMAL,
/* (0711) */ OFFSETOF_TWO_BYTES(pubKey, TPM_KEY),
/* (0713) */ BC_REF,
/* (0714) varint: 613 */ 132, 101,
/* Field: encSize */
/* (0716) */ BC_FIELD_KIND_NORMAL,
/* (0717) */ OFFSETOF_TWO_BYTES(encSize, TPM_KEY),
/* (0719) */ BC_INT32,
/* Variable-length field: encData */
/* (0720) */ BC_FIELD_KIND_VARIABLE,
/* (0721) */ OFFSETOF_TWO_BYTES(encData, TPM_KEY),
/* (0723) */ 8,
/* (0724) */ BC_INT8,
/* Record: TPM_KEY12 */
/* (0725) */ BC_RECORD,
/* (0726) */ 11,
/* Field: tag */
/* (0727) */ BC_FIELD_KIND_NORMAL,
/* (0728) */ OFFSETOF_TWO_BYTES(tag, TPM_KEY12),
/* (0730) */ BC_INT16,
/* Field: fill */
/* (0731) */ BC_FIELD_KIND_NORMAL,
/* (0732) */ OFFSETOF_TWO_BYTES(fill, TPM_KEY12),
/* (0734) */ BC_INT16,
/* Field: keyUsage */
/* (0735) */ BC_FIELD_KIND_NORMAL,
/* (0736) */ OFFSETOF_TWO_BYTES(keyUsage, TPM_KEY12),
/* (0738) */ BC_INT16,
/* Field: keyFlags */
/* (0739) */ BC_FIELD_KIND_NORMAL,
/* (0740) */ OFFSETOF_TWO_BYTES(keyFlags, TPM_KEY12),
/* (0742) */ BC_INT32,
/* Field: authDataUsage */
/* (0743) */ BC_FIELD_KIND_NORMAL,
/* (0744) */ OFFSETOF_TWO_BYTES(authDataUsage, TPM_KEY12),
/* (0746) */ BC_INT8,
/* Field: algorithmParms */
/* (0747) */ BC_FIELD_KIND_NORMAL,
/* (0748) */ OFFSETOF_TWO_BYTES(algorithmParms, TPM_KEY12),
/* (0750) */ BC_REF,
/* (0751) varint: 552 */ 132, 40,
/* Field: PCRInfoSize */
/* (0753) */ BC_FIELD_KIND_NORMAL,
/* (0754) */ OFFSETOF_TWO_BYTES(PCRInfoSize, TPM_KEY12),
/* (0756) */ BC_INT32,
/* Variable-length field: PCRInfo */
/* (0757) */ BC_FIELD_KIND_VARIABLE,
/* (0758) */ OFFSETOF_TWO_BYTES(PCRInfo, TPM_KEY12),
/* (0760) */ 6,
/* (0761) */ BC_INT8,
/* Field: pubKey */
/* (0762) */ BC_FIELD_KIND_NORMAL,
/* (0763) */ OFFSETOF_TWO_BYTES(pubKey, TPM_KEY12),
/* (0765) */ BC_REF,
/* (0766) varint: 613 */ 132, 101,
/* Field: encSize */
/* (0768) */ BC_FIELD_KIND_NORMAL,
/* (0769) */ OFFSETOF_TWO_BYTES(encSize, TPM_KEY12),
/* (0771) */ BC_INT32,
/* Variable-length field: encData */
/* (0772) */ BC_FIELD_KIND_VARIABLE,
/* (0773) */ OFFSETOF_TWO_BYTES(encData, TPM_KEY12),
/* (0775) */ 9,
/* (0776) */ BC_INT8,
/* Record: TPM_MIGRATE_ASYMKEY */
/* (0777) */ BC_RECORD,
/* (0778) */ 5,
/* Field: payload */
/* (0779) */ BC_FIELD_KIND_NORMAL,
/* (0780) */ OFFSETOF_TWO_BYTES(payload, TPM_MIGRATE_ASYMKEY),
/* (0782) */ BC_INT8,
/* Field: usageAuth */
/* (0783) */ BC_FIELD_KIND_NORMAL,
/* (0784) */ OFFSETOF_TWO_BYTES(usageAuth, TPM_MIGRATE_ASYMKEY),
/* (0786) */ BC_REF,
/* (0787) varint: 48 */ 48,
/* Field: pubDataDigest */
/* (0788) */ BC_FIELD_KIND_NORMAL,
/* (0789) */ OFFSETOF_TWO_BYTES(pubDataDigest, TPM_MIGRATE_ASYMKEY),
/* (0791) */ BC_REF,
/* (0792) varint: 36 */ 36,
/* Field: partPrivKeyLen */
/* (0793) */ BC_FIELD_KIND_NORMAL,
/* (0794) */ OFFSETOF_TWO_BYTES(partPrivKeyLen, TPM_MIGRATE_ASYMKEY),
/* (0796) */ BC_INT32,
/* Variable-length field: partPrivKey */
/* (0797) */ BC_FIELD_KIND_VARIABLE,
/* (0798) */ OFFSETOF_TWO_BYTES(partPrivKey, TPM_MIGRATE_ASYMKEY),
/* (0800) */ 3,
/* (0801) */ BC_INT8,
/* Record: TPM_MIGRATIONKEYAUTH */
/* (0802) */ BC_RECORD,
/* (0803) */ 3,
/* Field: migrationKey */
/* (0804) */ BC_FIELD_KIND_NORMAL,
/* (0805) */ OFFSETOF_TWO_BYTES(migrationKey, TPM_MIGRATIONKEYAUTH),
/* (0807) */ BC_REF,
/* (0808) varint: 624 */ 132, 112,
/* Field: migrationScheme */
/* (0810) */ BC_FIELD_KIND_NORMAL,
/* (0811) */ OFFSETOF_TWO_BYTES(migrationScheme, TPM_MIGRATIONKEYAUTH),
/* (0813) */ BC_INT16,
/* Field: digest */
/* (0814) */ BC_FIELD_KIND_NORMAL,
/* (0815) */ OFFSETOF_TWO_BYTES(digest, TPM_MIGRATIONKEYAUTH),
/* (0817) */ BC_REF,
/* (0818) varint: 36 */ 36,
/* Record: TPM_CERTIFY_INFO */
/* (0819) */ BC_RECORD,
/* (0820) */ 10,
/* Field: version */
/* (0821) */ BC_FIELD_KIND_NORMAL,
/* (0822) */ OFFSETOF_TWO_BYTES(version, TPM_CERTIFY_INFO),
/* (0824) */ BC_REF,
/* (0825) varint: 0 */ 0,
/* Field: keyUsage */
/* (0826) */ BC_FIELD_KIND_NORMAL,
/* (0827) */ OFFSETOF_TWO_BYTES(keyUsage, TPM_CERTIFY_INFO),
/* (0829) */ BC_INT16,
/* Field: keyFlags */
/* (0830) */ BC_FIELD_KIND_NORMAL,
/* (0831) */ OFFSETOF_TWO_BYTES(keyFlags, TPM_CERTIFY_INFO),
/* (0833) */ BC_INT32,
/* Field: authDataUsage */
/* (0834) */ BC_FIELD_KIND_NORMAL,
/* (0835) */ OFFSETOF_TWO_BYTES(authDataUsage, TPM_CERTIFY_INFO),
/* (0837) */ BC_INT8,
/* Field: algorithmParms */
/* (0838) */ BC_FIELD_KIND_NORMAL,
/* (0839) */ OFFSETOF_TWO_BYTES(algorithmParms, TPM_CERTIFY_INFO),
/* (0841) */ BC_REF,
/* (0842) varint: 552 */ 132, 40,
/* Field: pubkeyDigest */
/* (0844) */ BC_FIELD_KIND_NORMAL,
/* (0845) */ OFFSETOF_TWO_BYTES(pubkeyDigest, TPM_CERTIFY_INFO),
/* (0847) */ BC_REF,
/* (0848) varint: 36 */ 36,
/* Field: data */
/* (0849) */ BC_FIELD_KIND_NORMAL,
/* (0850) */ OFFSETOF_TWO_BYTES(data, TPM_CERTIFY_INFO),
/* (0852) */ BC_REF,
/* (0853) varint: 42 */ 42,
/* Field: parentPCRStatus */
/* (0854) */ BC_FIELD_KIND_NORMAL,
/* (0855) */ OFFSETOF_TWO_BYTES(parentPCRStatus, TPM_CERTIFY_INFO),
/* (0857) */ BC_INT8,
/* Field: PCRInfoSize */
/* (0858) */ BC_FIELD_KIND_NORMAL,
/* (0859) */ OFFSETOF_TWO_BYTES(PCRInfoSize, TPM_CERTIFY_INFO),
/* (0861) */ BC_INT32,
/* Variable-length field: PCRInfo */
/* (0862) */ BC_FIELD_KIND_VARIABLE,
/* (0863) */ OFFSETOF_TWO_BYTES(PCRInfo, TPM_CERTIFY_INFO),
/* (0865) */ 8,
/* (0866) */ BC_INT8,
/* Record: TPM_CERTIFY_INFO2 */
/* (0867) */ BC_RECORD,
/* (0868) */ 14,
/* Field: tag */
/* (0869) */ BC_FIELD_KIND_NORMAL,
/* (0870) */ OFFSETOF_TWO_BYTES(tag, TPM_CERTIFY_INFO2),
/* (0872) */ BC_INT16,
/* Field: fill */
/* (0873) */ BC_FIELD_KIND_NORMAL,
/* (0874) */ OFFSETOF_TWO_BYTES(fill, TPM_CERTIFY_INFO2),
/* (0876) */ BC_INT8,
/* Field: payloadType */
/* (0877) */ BC_FIELD_KIND_NORMAL,
/* (0878) */ OFFSETOF_TWO_BYTES(payloadType, TPM_CERTIFY_INFO2),
/* (0880) */ BC_INT8,
/* Field: keyUsage */
/* (0881) */ BC_FIELD_KIND_NORMAL,
/* (0882) */ OFFSETOF_TWO_BYTES(keyUsage, TPM_CERTIFY_INFO2),
/* (0884) */ BC_INT16,
/* Field: keyFlags */
/* (0885) */ BC_FIELD_KIND_NORMAL,
/* (0886) */ OFFSETOF_TWO_BYTES(keyFlags, TPM_CERTIFY_INFO2),
/* (0888) */ BC_INT32,
/* Field: authDataUsage */
/* (0889) */ BC_FIELD_KIND_NORMAL,
/* (0890) */ OFFSETOF_TWO_BYTES(authDataUsage, TPM_CERTIFY_INFO2),
/* (0892) */ BC_INT8,
/* Field: algorithmParms */
/* (0893) */ BC_FIELD_KIND_NORMAL,
/* (0894) */ OFFSETOF_TWO_BYTES(algorithmParms, TPM_CERTIFY_INFO2),
/* (0896) */ BC_REF,
/* (0897) varint: 552 */ 132, 40,
/* Field: pubkeyDigest */
/* (0899) */ BC_FIELD_KIND_NORMAL,
/* (0900) */ OFFSETOF_TWO_BYTES(pubkeyDigest, TPM_CERTIFY_INFO2),
/* (0902) */ BC_REF,
/* (0903) varint: 36 */ 36,
/* Field: data */
/* (0904) */ BC_FIELD_KIND_NORMAL,
/* (0905) */ OFFSETOF_TWO_BYTES(data, TPM_CERTIFY_INFO2),
/* (0907) */ BC_REF,
/* (0908) varint: 42 */ 42,
/* Field: parentPCRStatus */
/* (0909) */ BC_FIELD_KIND_NORMAL,
/* (0910) */ OFFSETOF_TWO_BYTES(parentPCRStatus, TPM_CERTIFY_INFO2),
/* (0912) */ BC_INT8,
/* Field: PCRInfoSize */
/* (0913) */ BC_FIELD_KIND_NORMAL,
/* (0914) */ OFFSETOF_TWO_BYTES(PCRInfoSize, TPM_CERTIFY_INFO2),
/* (0916) */ BC_INT32,
/* Variable-length field: PCRInfo */
/* (0917) */ BC_FIELD_KIND_VARIABLE,
/* (0918) */ OFFSETOF_TWO_BYTES(PCRInfo, TPM_CERTIFY_INFO2),
/* (0920) */ 10,
/* (0921) */ BC_INT8,
/* Field: migrationAuthoritySize */
/* (0922) */ BC_FIELD_KIND_NORMAL,
/* (0923) */ OFFSETOF_TWO_BYTES(migrationAuthoritySize, TPM_CERTIFY_INFO2),
/* (0925) */ BC_INT32,
/* Variable-length field: migrationAuthority */
/* (0926) */ BC_FIELD_KIND_VARIABLE,
/* (0927) */ OFFSETOF_TWO_BYTES(migrationAuthority, TPM_CERTIFY_INFO2),
/* (0929) */ 12,
/* (0930) */ BC_INT8,
/* Record: TPM_QUOTE_INFO */
/* (0931) */ BC_RECORD,
/* (0932) */ 4,
/* Field: version */
/* (0933) */ BC_FIELD_KIND_NORMAL,
/* (0934) */ OFFSETOF_TWO_BYTES(version, TPM_QUOTE_INFO),
/* (0936) */ BC_REF,
/* (0937) varint: 0 */ 0,
/* Array field: fixed */
/* (0938) */ BC_ARRAY,
/* (0939) */ TWO_BYTES_INT(4),
/* (0941) */ BC_INT8,
/* Field: compositeHash */
/* (0942) */ BC_FIELD_KIND_NORMAL,
/* (0943) */ OFFSETOF_TWO_BYTES(compositeHash, TPM_QUOTE_INFO),
/* (0945) */ BC_REF,
/* (0946) varint: 36 */ 36,
/* Field: externalData */
/* (0947) */ BC_FIELD_KIND_NORMAL,
/* (0948) */ OFFSETOF_TWO_BYTES(externalData, TPM_QUOTE_INFO),
/* (0950) */ BC_REF,
/* (0951) varint: 42 */ 42,
/* Record: TPM_QUOTE_INFO2 */
/* (0952) */ BC_RECORD,
/* (0953) */ 4,
/* Field: tag */
/* (0954) */ BC_FIELD_KIND_NORMAL,
/* (0955) */ OFFSETOF_TWO_BYTES(tag, TPM_QUOTE_INFO2),
/* (0957) */ BC_INT16,
/* Array field: fixed */
/* (0958) */ BC_ARRAY,
/* (0959) */ TWO_BYTES_INT(4),
/* (0961) */ BC_INT8,
/* Field: externalData */
/* (0962) */ BC_FIELD_KIND_NORMAL,
/* (0963) */ OFFSETOF_TWO_BYTES(externalData, TPM_QUOTE_INFO2),
/* (0965) */ BC_REF,
/* (0966) varint: 42 */ 42,
/* Field: infoShort */
/* (0967) */ BC_FIELD_KIND_NORMAL,
/* (0968) */ OFFSETOF_TWO_BYTES(infoShort, TPM_QUOTE_INFO2),
/* (0970) */ BC_REF,
/* (0971) varint: 403 */ 131, 19,
/* Record: TPM_EK_BLOB */
/* (0973) */ BC_RECORD,
/* (0974) */ 4,
/* Field: tag */
/* (0975) */ BC_FIELD_KIND_NORMAL,
/* (0976) */ OFFSETOF_TWO_BYTES(tag, TPM_EK_BLOB),
/* (0978) */ BC_INT16,
/* Field: ekType */
/* (0979) */ BC_FIELD_KIND_NORMAL,
/* (0980) */ OFFSETOF_TWO_BYTES(ekType, TPM_EK_BLOB),
/* (0982) */ BC_INT16,
/* Field: blobSize */
/* (0983) */ BC_FIELD_KIND_NORMAL,
/* (0984) */ OFFSETOF_TWO_BYTES(blobSize, TPM_EK_BLOB),
/* (0986) */ BC_INT32,
/* Variable-length field: blob */
/* (0987) */ BC_FIELD_KIND_VARIABLE,
/* (0988) */ OFFSETOF_TWO_BYTES(blob, TPM_EK_BLOB),
/* (0990) */ 2,
/* (0991) */ BC_INT8,
/* Record: TPM_EK_BLOB_ACTIVATE */
/* (0992) */ BC_RECORD,
/* (0993) */ 4,
/* Field: tag */
/* (0994) */ BC_FIELD_KIND_NORMAL,
/* (0995) */ OFFSETOF_TWO_BYTES(tag, TPM_EK_BLOB_ACTIVATE),
/* (0997) */ BC_INT16,
/* Field: sessionKey */
/* (0998) */ BC_FIELD_KIND_NORMAL,
/* (0999) */ OFFSETOF_TWO_BYTES(sessionKey, TPM_EK_BLOB_ACTIVATE),
/* (1001) */ BC_REF,
/* (1002) varint: 517 */ 132, 5,
/* Field: idDigest */
/* (1004) */ BC_FIELD_KIND_NORMAL,
/* (1005) */ OFFSETOF_TWO_BYTES(idDigest, TPM_EK_BLOB_ACTIVATE),
/* (1007) */ BC_REF,
/* (1008) varint: 36 */ 36,
/* Field: pcrInfo */
/* (1009) */ BC_FIELD_KIND_NORMAL,
/* (1010) */ OFFSETOF_TWO_BYTES(pcrInfo, TPM_EK_BLOB_ACTIVATE),
/* (1012) */ BC_REF,
/* (1013) varint: 403 */ 131, 19,
/* Record: TPM_EK_BLOB_AUTH */
/* (1015) */ BC_RECORD,
/* (1016) */ 2,
/* Field: tag */
/* (1017) */ BC_FIELD_KIND_NORMAL,
/* (1018) */ OFFSETOF_TWO_BYTES(tag, TPM_EK_BLOB_AUTH),
/* (1020) */ BC_INT16,
/* Field: authValue */
/* (1021) */ BC_FIELD_KIND_NORMAL,
/* (1022) */ OFFSETOF_TWO_BYTES(authValue, TPM_EK_BLOB_AUTH),
/* (1024) */ BC_REF,
/* (1025) varint: 48 */ 48,
/* Record: TPM_IDENTITY_CONTENTS */
/* (1026) */ BC_RECORD,
/* (1027) */ 4,
/* Field: ver */
/* (1028) */ BC_FIELD_KIND_NORMAL,
/* (1029) */ OFFSETOF_TWO_BYTES(ver, TPM_IDENTITY_CONTENTS),
/* (1031) */ BC_REF,
/* (1032) varint: 0 */ 0,
/* Field: ordinal */
/* (1033) */ BC_FIELD_KIND_NORMAL,
/* (1034) */ OFFSETOF_TWO_BYTES(ordinal, TPM_IDENTITY_CONTENTS),
/* (1036) */ BC_INT32,
/* Field: labelPrivCADigest */
/* (1037) */ BC_FIELD_KIND_NORMAL,
/* (1038) */ OFFSETOF_TWO_BYTES(labelPrivCADigest, TPM_IDENTITY_CONTENTS),
/* (1040) */ BC_REF,
/* (1041) varint: 36 */ 36,
/* Field: identityPubKey */
/* (1042) */ BC_FIELD_KIND_NORMAL,
/* (1043) */ OFFSETOF_TWO_BYTES(identityPubKey, TPM_IDENTITY_CONTENTS),
/* (1045) */ BC_REF,
/* (1046) varint: 624 */ 132, 112,
/* Record: TPM_IDENTITY_REQ */
/* (1048) */ BC_RECORD,
/* (1049) */ 6,
/* Field: asymSize */
/* (1050) */ BC_FIELD_KIND_NORMAL,
/* (1051) */ OFFSETOF_TWO_BYTES(asymSize, TPM_IDENTITY_REQ),
/* (1053) */ BC_INT32,
/* Field: symSize */
/* (1054) */ BC_FIELD_KIND_NORMAL,
/* (1055) */ OFFSETOF_TWO_BYTES(symSize, TPM_IDENTITY_REQ),
/* (1057) */ BC_INT32,
/* Field: asymAlgorithm */
/* (1058) */ BC_FIELD_KIND_NORMAL,
/* (1059) */ OFFSETOF_TWO_BYTES(asymAlgorithm, TPM_IDENTITY_REQ),
/* (1061) */ BC_REF,
/* (1062) varint: 552 */ 132, 40,
/* Field: symAlgorithm */
/* (1064) */ BC_FIELD_KIND_NORMAL,
/* (1065) */ OFFSETOF_TWO_BYTES(symAlgorithm, TPM_IDENTITY_REQ),
/* (1067) */ BC_REF,
/* (1068) varint: 552 */ 132, 40,
/* Variable-length field: asymBlob */
/* (1070) */ BC_FIELD_KIND_VARIABLE,
/* (1071) */ OFFSETOF_TWO_BYTES(asymBlob, TPM_IDENTITY_REQ),
/* (1073) */ 3,
/* (1074) */ BC_INT8,
/* Variable-length field: symBlob */
/* (1075) */ BC_FIELD_KIND_VARIABLE,
/* (1076) */ OFFSETOF_TWO_BYTES(symBlob, TPM_IDENTITY_REQ),
/* (1078) */ 4,
/* (1079) */ BC_INT8,
/* Record: TPM_IDENTITY_PROOF */
/* (1080) */ BC_RECORD,
/* (1081) */ 12,
/* Field: ver */
/* (1082) */ BC_FIELD_KIND_NORMAL,
/* (1083) */ OFFSETOF_TWO_BYTES(ver, TPM_IDENTITY_PROOF),
/* (1085) */ BC_REF,
/* (1086) varint: 0 */ 0,
/* Field: labelSize */
/* (1087) */ BC_FIELD_KIND_NORMAL,
/* (1088) */ OFFSETOF_TWO_BYTES(labelSize, TPM_IDENTITY_PROOF),
/* (1090) */ BC_INT32,
/* Field: identityBindingSize */
/* (1091) */ BC_FIELD_KIND_NORMAL,
/* (1092) */ OFFSETOF_TWO_BYTES(identityBindingSize, TPM_IDENTITY_PROOF),
/* (1094) */ BC_INT32,
/* Field: endorsementSize */
/* (1095) */ BC_FIELD_KIND_NORMAL,
/* (1096) */ OFFSETOF_TWO_BYTES(endorsementSize, TPM_IDENTITY_PROOF),
/* (1098) */ BC_INT32,
/* Field: platformSize */
/* (1099) */ BC_FIELD_KIND_NORMAL,
/* (1100) */ OFFSETOF_TWO_BYTES(platformSize, TPM_IDENTITY_PROOF),
/* (1102) */ BC_INT32,
/* Field: conformanceSize */
/* (1103) */ BC_FIELD_KIND_NORMAL,
/* (1104) */ OFFSETOF_TWO_BYTES(conformanceSize, TPM_IDENTITY_PROOF),
/* (1106) */ BC_INT32,
/* Field: identityKey */
/* (1107) */ BC_FIELD_KIND_NORMAL,
/* (1108) */ OFFSETOF_TWO_BYTES(identityKey, TPM_IDENTITY_PROOF),
/* (1110) */ BC_REF,
/* (1111) varint: 624 */ 132, 112,
/* Variable-length field: labelArea */
/* (1113) */ BC_FIELD_KIND_VARIABLE,
/* (1114) */ OFFSETOF_TWO_BYTES(labelArea, TPM_IDENTITY_PROOF),
/* (1116) */ 6,
/* (1117) */ BC_INT8,
/* Variable-length field: identityBinding */
/* (1118) */ BC_FIELD_KIND_VARIABLE,
/* (1119) */ OFFSETOF_TWO_BYTES(identityBinding, TPM_IDENTITY_PROOF),
/* (1121) */ 7,
/* (1122) */ BC_INT8,
/* Variable-length field: endorsementCredential */
/* (1123) */ BC_FIELD_KIND_VARIABLE,
/* (1124) */ OFFSETOF_TWO_BYTES(endorsementCredential, TPM_IDENTITY_PROOF),
/* (1126) */ 8,
/* (1127) */ BC_INT8,
/* Variable-length field: platformCredential */
/* (1128) */ BC_FIELD_KIND_VARIABLE,
/* (1129) */ OFFSETOF_TWO_BYTES(platformCredential, TPM_IDENTITY_PROOF),
/* (1131) */ 9,
/* (1132) */ BC_INT8,
/* Variable-length field: conformanceCredential */
/* (1133) */ BC_FIELD_KIND_VARIABLE,
/* (1134) */ OFFSETOF_TWO_BYTES(conformanceCredential, TPM_IDENTITY_PROOF),
/* (1136) */ 10,
/* (1137) */ BC_INT8,
/* Record: TPM_ASYM_CA_CONTENTS */
/* (1138) */ BC_RECORD,
/* (1139) */ 2,
/* Field: sessionKey */
/* (1140) */ BC_FIELD_KIND_NORMAL,
/* (1141) */ OFFSETOF_TWO_BYTES(sessionKey, TPM_ASYM_CA_CONTENTS),
/* (1143) */ BC_REF,
/* (1144) varint: 517 */ 132, 5,
/* Field: idDigest */
/* (1146) */ BC_FIELD_KIND_NORMAL,
/* (1147) */ OFFSETOF_TWO_BYTES(idDigest, TPM_ASYM_CA_CONTENTS),
/* (1149) */ BC_REF,
/* (1150) varint: 36 */ 36,
/* Record: TPM_SYM_CA_ATTESTATION */
/* (1151) */ BC_RECORD,
/* (1152) */ 3,
/* Field: credSize */
/* (1153) */ BC_FIELD_KIND_NORMAL,
/* (1154) */ OFFSETOF_TWO_BYTES(credSize, TPM_SYM_CA_ATTESTATION),
/* (1156) */ BC_INT32,
/* Field: algorithm */
/* (1157) */ BC_FIELD_KIND_NORMAL,
/* (1158) */ OFFSETOF_TWO_BYTES(algorithm, TPM_SYM_CA_ATTESTATION),
/* (1160) */ BC_REF,
/* (1161) varint: 552 */ 132, 40,
/* Variable-length field: credential */
/* (1163) */ BC_FIELD_KIND_VARIABLE,
/* (1164) */ OFFSETOF_TWO_BYTES(credential, TPM_SYM_CA_ATTESTATION),
/* (1166) */ 1,
/* (1167) */ BC_INT8,
/* Record: TPM_CURRENT_TICKS */
/* (1168) */ BC_RECORD,
/* (1169) */ 4,
/* Field: tag */
/* (1170) */ BC_FIELD_KIND_NORMAL,
/* (1171) */ OFFSETOF_TWO_BYTES(tag, TPM_CURRENT_TICKS),
/* (1173) */ BC_INT16,
/* Field: currentTicks */
/* (1174) */ BC_FIELD_KIND_NORMAL,
/* (1175) */ OFFSETOF_TWO_BYTES(currentTicks, TPM_CURRENT_TICKS),
/* (1177) */ BC_INT64,
/* Field: tickRate */
/* (1178) */ BC_FIELD_KIND_NORMAL,
/* (1179) */ OFFSETOF_TWO_BYTES(tickRate, TPM_CURRENT_TICKS),
/* (1181) */ BC_INT16,
/* Field: tickNonce */
/* (1182) */ BC_FIELD_KIND_NORMAL,
/* (1183) */ OFFSETOF_TWO_BYTES(tickNonce, TPM_CURRENT_TICKS),
/* (1185) */ BC_REF,
/* (1186) varint: 42 */ 42,
/* Record: TPM_TRANSPORT_PUBLIC */
/* (1187) */ BC_RECORD,
/* (1188) */ 4,
/* Field: tag */
/* (1189) */ BC_FIELD_KIND_NORMAL,
/* (1190) */ OFFSETOF_TWO_BYTES(tag, TPM_TRANSPORT_PUBLIC),
/* (1192) */ BC_INT16,
/* Field: transAttributes */
/* (1193) */ BC_FIELD_KIND_NORMAL,
/* (1194) */ OFFSETOF_TWO_BYTES(transAttributes, TPM_TRANSPORT_PUBLIC),
/* (1196) */ BC_INT32,
/* Field: algId */
/* (1197) */ BC_FIELD_KIND_NORMAL,
/* (1198) */ OFFSETOF_TWO_BYTES(algId, TPM_TRANSPORT_PUBLIC),
/* (1200) */ BC_INT32,
/* Field: encScheme */
/* (1201) */ BC_FIELD_KIND_NORMAL,
/* (1202) */ OFFSETOF_TWO_BYTES(encScheme, TPM_TRANSPORT_PUBLIC),
/* (1204) */ BC_INT16,
/* Record: TPM_TRANSPORT_INTERNAL */
/* (1205) */ BC_RECORD,
/* (1206) */ 6,
/* Field: tag */
/* (1207) */ BC_FIELD_KIND_NORMAL,
/* (1208) */ OFFSETOF_TWO_BYTES(tag, TPM_TRANSPORT_INTERNAL),
/* (1210) */ BC_INT16,
/* Field: authData */
/* (1211) */ BC_FIELD_KIND_NORMAL,
/* (1212) */ OFFSETOF_TWO_BYTES(authData, TPM_TRANSPORT_INTERNAL),
/* (1214) */ BC_REF,
/* (1215) varint: 48 */ 48,
/* Field: transPublic */
/* (1216) */ BC_FIELD_KIND_NORMAL,
/* (1217) */ OFFSETOF_TWO_BYTES(transPublic, TPM_TRANSPORT_INTERNAL),
/* (1219) */ BC_REF,
/* (1220) varint: 1187 */ 137, 35,
/* Field: transHandle */
/* (1222) */ BC_FIELD_KIND_NORMAL,
/* (1223) */ OFFSETOF_TWO_BYTES(transHandle, TPM_TRANSPORT_INTERNAL),
/* (1225) */ BC_INT32,
/* Field: transNonceEven */
/* (1226) */ BC_FIELD_KIND_NORMAL,
/* (1227) */ OFFSETOF_TWO_BYTES(transNonceEven, TPM_TRANSPORT_INTERNAL),
/* (1229) */ BC_REF,
/* (1230) varint: 42 */ 42,
/* Field: transDigest */
/* (1231) */ BC_FIELD_KIND_NORMAL,
/* (1232) */ OFFSETOF_TWO_BYTES(transDigest, TPM_TRANSPORT_INTERNAL),
/* (1234) */ BC_REF,
/* (1235) varint: 36 */ 36,
/* Record: TPM_TRANSPORT_LOG_IN */
/* (1236) */ BC_RECORD,
/* (1237) */ 3,
/* Field: tag */
/* (1238) */ BC_FIELD_KIND_NORMAL,
/* (1239) */ OFFSETOF_TWO_BYTES(tag, TPM_TRANSPORT_LOG_IN),
/* (1241) */ BC_INT16,
/* Field: parameters */
/* (1242) */ BC_FIELD_KIND_NORMAL,
/* (1243) */ OFFSETOF_TWO_BYTES(parameters, TPM_TRANSPORT_LOG_IN),
/* (1245) */ BC_REF,
/* (1246) varint: 36 */ 36,
/* Field: pubKeyHash */
/* (1247) */ BC_FIELD_KIND_NORMAL,
/* (1248) */ OFFSETOF_TWO_BYTES(pubKeyHash, TPM_TRANSPORT_LOG_IN),
/* (1250) */ BC_REF,
/* (1251) varint: 36 */ 36,
/* Record: TPM_TRANSPORT_LOG_OUT */
/* (1252) */ BC_RECORD,
/* (1253) */ 4,
/* Field: tag */
/* (1254) */ BC_FIELD_KIND_NORMAL,
/* (1255) */ OFFSETOF_TWO_BYTES(tag, TPM_TRANSPORT_LOG_OUT),
/* (1257) */ BC_INT16,
/* Field: currentTicks */
/* (1258) */ BC_FIELD_KIND_NORMAL,
/* (1259) */ OFFSETOF_TWO_BYTES(currentTicks, TPM_TRANSPORT_LOG_OUT),
/* (1261) */ BC_REF,
/* (1262) varint: 1168 */ 137, 16,
/* Field: parameters */
/* (1264) */ BC_FIELD_KIND_NORMAL,
/* (1265) */ OFFSETOF_TWO_BYTES(parameters, TPM_TRANSPORT_LOG_OUT),
/* (1267) */ BC_REF,
/* (1268) varint: 36 */ 36,
/* Field: locality */
/* (1269) */ BC_FIELD_KIND_NORMAL,
/* (1270) */ OFFSETOF_TWO_BYTES(locality, TPM_TRANSPORT_LOG_OUT),
/* (1272) */ BC_INT32,
/* Record: TPM_TRANSPORT_AUTH */
/* (1273) */ BC_RECORD,
/* (1274) */ 2,
/* Field: tag */
/* (1275) */ BC_FIELD_KIND_NORMAL,
/* (1276) */ OFFSETOF_TWO_BYTES(tag, TPM_TRANSPORT_AUTH),
/* (1278) */ BC_INT16,
/* Field: authData */
/* (1279) */ BC_FIELD_KIND_NORMAL,
/* (1280) */ OFFSETOF_TWO_BYTES(authData, TPM_TRANSPORT_AUTH),
/* (1282) */ BC_REF,
/* (1283) varint: 48 */ 48,
/* Record: TPM_AUDIT_EVENT_IN */
/* (1284) */ BC_RECORD,
/* (1285) */ 3,
/* Field: tag */
/* (1286) */ BC_FIELD_KIND_NORMAL,
/* (1287) */ OFFSETOF_TWO_BYTES(tag, TPM_AUDIT_EVENT_IN),
/* (1289) */ BC_INT16,
/* Field: inputParms */
/* (1290) */ BC_FIELD_KIND_NORMAL,
/* (1291) */ OFFSETOF_TWO_BYTES(inputParms, TPM_AUDIT_EVENT_IN),
/* (1293) */ BC_REF,
/* (1294) varint: 36 */ 36,
/* Field: auditCount */
/* (1295) */ BC_FIELD_KIND_NORMAL,
/* (1296) */ OFFSETOF_TWO_BYTES(auditCount, TPM_AUDIT_EVENT_IN),
/* (1298) */ BC_REF,
/* (1299) varint: 66 */ 66,
/* Record: TPM_AUDIT_EVENT_OUT */
/* (1300) */ BC_RECORD,
/* (1301) */ 5,
/* Field: tag */
/* (1302) */ BC_FIELD_KIND_NORMAL,
/* (1303) */ OFFSETOF_TWO_BYTES(tag, TPM_AUDIT_EVENT_OUT),
/* (1305) */ BC_INT16,
/* Field: ordinal */
/* (1306) */ BC_FIELD_KIND_NORMAL,
/* (1307) */ OFFSETOF_TWO_BYTES(ordinal, TPM_AUDIT_EVENT_OUT),
/* (1309) */ BC_INT32,
/* Field: outputParms */
/* (1310) */ BC_FIELD_KIND_NORMAL,
/* (1311) */ OFFSETOF_TWO_BYTES(outputParms, TPM_AUDIT_EVENT_OUT),
/* (1313) */ BC_REF,
/* (1314) varint: 36 */ 36,
/* Field: auditCount */
/* (1315) */ BC_FIELD_KIND_NORMAL,
/* (1316) */ OFFSETOF_TWO_BYTES(auditCount, TPM_AUDIT_EVENT_OUT),
/* (1318) */ BC_REF,
/* (1319) varint: 66 */ 66,
/* Field: returnCode */
/* (1320) */ BC_FIELD_KIND_NORMAL,
/* (1321) */ OFFSETOF_TWO_BYTES(returnCode, TPM_AUDIT_EVENT_OUT),
/* (1323) */ BC_INT32,
/* Record: TPM_CONTEXT_BLOB */
/* (1324) */ BC_RECORD,
/* (1325) */ 10,
/* Field: tag */
/* (1326) */ BC_FIELD_KIND_NORMAL,
/* (1327) */ OFFSETOF_TWO_BYTES(tag, TPM_CONTEXT_BLOB),
/* (1329) */ BC_INT16,
/* Field: resourceType */
/* (1330) */ BC_FIELD_KIND_NORMAL,
/* (1331) */ OFFSETOF_TWO_BYTES(resourceType, TPM_CONTEXT_BLOB),
/* (1333) */ BC_INT32,
/* Field: handle */
/* (1334) */ BC_FIELD_KIND_NORMAL,
/* (1335) */ OFFSETOF_TWO_BYTES(handle, TPM_CONTEXT_BLOB),
/* (1337) */ BC_INT32,
/* Array field: label */
/* (1338) */ BC_ARRAY,
/* (1339) */ TWO_BYTES_INT(16),
/* (1341) */ BC_INT8,
/* Field: contextCount */
/* (1342) */ BC_FIELD_KIND_NORMAL,
/* (1343) */ OFFSETOF_TWO_BYTES(contextCount, TPM_CONTEXT_BLOB),
/* (1345) */ BC_INT32,
/* Field: integrityDigest */
/* (1346) */ BC_FIELD_KIND_NORMAL,
/* (1347) */ OFFSETOF_TWO_BYTES(integrityDigest, TPM_CONTEXT_BLOB),
/* (1349) */ BC_REF,
/* (1350) varint: 36 */ 36,
/* Field: additionalSize */
/* (1351) */ BC_FIELD_KIND_NORMAL,
/* (1352) */ OFFSETOF_TWO_BYTES(additionalSize, TPM_CONTEXT_BLOB),
/* (1354) */ BC_INT32,
/* Variable-length field: additionalData */
/* (1355) */ BC_FIELD_KIND_VARIABLE,
/* (1356) */ OFFSETOF_TWO_BYTES(additionalData, TPM_CONTEXT_BLOB),
/* (1358) */ 6,
/* (1359) */ BC_INT8,
/* Field: sensitiveSize */
/* (1360) */ BC_FIELD_KIND_NORMAL,
/* (1361) */ OFFSETOF_TWO_BYTES(sensitiveSize, TPM_CONTEXT_BLOB),
/* (1363) */ BC_INT32,
/* Variable-length field: sensitiveData */
/* (1364) */ BC_FIELD_KIND_VARIABLE,
/* (1365) */ OFFSETOF_TWO_BYTES(sensitiveData, TPM_CONTEXT_BLOB),
/* (1367) */ 8,
/* (1368) */ BC_INT8,
/* Record: TPM_CONTEXT_SENSITIVE */
/* (1369) */ BC_RECORD,
/* (1370) */ 4,
/* Field: tag */
/* (1371) */ BC_FIELD_KIND_NORMAL,
/* (1372) */ OFFSETOF_TWO_BYTES(tag, TPM_CONTEXT_SENSITIVE),
/* (1374) */ BC_INT16,
/* Field: contextNonce */
/* (1375) */ BC_FIELD_KIND_NORMAL,
/* (1376) */ OFFSETOF_TWO_BYTES(contextNonce, TPM_CONTEXT_SENSITIVE),
/* (1378) */ BC_REF,
/* (1379) varint: 42 */ 42,
/* Field: internalSize */
/* (1380) */ BC_FIELD_KIND_NORMAL,
/* (1381) */ OFFSETOF_TWO_BYTES(internalSize, TPM_CONTEXT_SENSITIVE),
/* (1383) */ BC_INT32,
/* Variable-length field: internalData */
/* (1384) */ BC_FIELD_KIND_VARIABLE,
/* (1385) */ OFFSETOF_TWO_BYTES(internalData, TPM_CONTEXT_SENSITIVE),
/* (1387) */ 2,
/* (1388) */ BC_INT8,
/* Record: TPM_NV_ATTRIBUTES */
/* (1389) */ BC_RECORD,
/* (1390) */ 2,
/* Field: tag */
/* (1391) */ BC_FIELD_KIND_NORMAL,
/* (1392) */ OFFSETOF_TWO_BYTES(tag, TPM_NV_ATTRIBUTES),
/* (1394) */ BC_INT16,
/* Field: attributes */
/* (1395) */ BC_FIELD_KIND_NORMAL,
/* (1396) */ OFFSETOF_TWO_BYTES(attributes, TPM_NV_ATTRIBUTES),
/* (1398) */ BC_INT32,
/* Record: TPM_NV_DATA_PUBLIC */
/* (1399) */ BC_RECORD,
/* (1400) */ 9,
/* Field: tag */
/* (1401) */ BC_FIELD_KIND_NORMAL,
/* (1402) */ OFFSETOF_TWO_BYTES(tag, TPM_NV_DATA_PUBLIC),
/* (1404) */ BC_INT16,
/* Field: nvIndex */
/* (1405) */ BC_FIELD_KIND_NORMAL,
/* (1406) */ OFFSETOF_TWO_BYTES(nvIndex, TPM_NV_DATA_PUBLIC),
/* (1408) */ BC_INT32,
/* Field: pcrInfoRead */
/* (1409) */ BC_FIELD_KIND_NORMAL,
/* (1410) */ OFFSETOF_TWO_BYTES(pcrInfoRead, TPM_NV_DATA_PUBLIC),
/* (1412) */ BC_REF,
/* (1413) varint: 403 */ 131, 19,
/* Field: pcrInfoWrite */
/* (1415) */ BC_FIELD_KIND_NORMAL,
/* (1416) */ OFFSETOF_TWO_BYTES(pcrInfoWrite, TPM_NV_DATA_PUBLIC),
/* (1418) */ BC_REF,
/* (1419) varint: 403 */ 131, 19,
/* Field: permission */
/* (1421) */ BC_FIELD_KIND_NORMAL,
/* (1422) */ OFFSETOF_TWO_BYTES(permission, TPM_NV_DATA_PUBLIC),
/* (1424) */ BC_REF,
/* (1425) varint: 1389 */ 138, 109,
/* Field: bReadSTClear */
/* (1427) */ BC_FIELD_KIND_NORMAL,
/* (1428) */ OFFSETOF_TWO_BYTES(bReadSTClear, TPM_NV_DATA_PUBLIC),
/* (1430) */ BC_INT8,
/* Field: bWriteSTClear */
/* (1431) */ BC_FIELD_KIND_NORMAL,
/* (1432) */ OFFSETOF_TWO_BYTES(bWriteSTClear, TPM_NV_DATA_PUBLIC),
/* (1434) */ BC_INT8,
/* Field: bWriteDefine */
/* (1435) */ BC_FIELD_KIND_NORMAL,
/* (1436) */ OFFSETOF_TWO_BYTES(bWriteDefine, TPM_NV_DATA_PUBLIC),
/* (1438) */ BC_INT8,
/* Field: dataSize */
/* (1439) */ BC_FIELD_KIND_NORMAL,
/* (1440) */ OFFSETOF_TWO_BYTES(dataSize, TPM_NV_DATA_PUBLIC),
/* (1442) */ BC_INT32,
/* Record: TPM_FAMILY_LABEL */
/* (1443) */ BC_RECORD,
/* (1444) */ 1,
/* Field: label */
/* (1445) */ BC_FIELD_KIND_NORMAL,
/* (1446) */ OFFSETOF_TWO_BYTES(label, TPM_FAMILY_LABEL),
/* (1448) */ BC_INT8,
/* Record: TPM_FAMILY_TABLE_ENTRY */
/* (1449) */ BC_RECORD,
/* (1450) */ 5,
/* Field: tag */
/* (1451) */ BC_FIELD_KIND_NORMAL,
/* (1452) */ OFFSETOF_TWO_BYTES(tag, TPM_FAMILY_TABLE_ENTRY),
/* (1454) */ BC_INT16,
/* Field: label */
/* (1455) */ BC_FIELD_KIND_NORMAL,
/* (1456) */ OFFSETOF_TWO_BYTES(label, TPM_FAMILY_TABLE_ENTRY),
/* (1458) */ BC_REF,
/* (1459) varint: 1443 */ 139, 35,
/* Field: familyID */
/* (1461) */ BC_FIELD_KIND_NORMAL,
/* (1462) */ OFFSETOF_TWO_BYTES(familyID, TPM_FAMILY_TABLE_ENTRY),
/* (1464) */ BC_INT32,
/* Field: verificationCount */
/* (1465) */ BC_FIELD_KIND_NORMAL,
/* (1466) */ OFFSETOF_TWO_BYTES(verificationCount, TPM_FAMILY_TABLE_ENTRY),
/* (1468) */ BC_INT32,
/* Field: flags */
/* (1469) */ BC_FIELD_KIND_NORMAL,
/* (1470) */ OFFSETOF_TWO_BYTES(flags, TPM_FAMILY_TABLE_ENTRY),
/* (1472) */ BC_INT32,
/* Record: TPM_DELEGATE_LABEL */
/* (1473) */ BC_RECORD,
/* (1474) */ 1,
/* Field: label */
/* (1475) */ BC_FIELD_KIND_NORMAL,
/* (1476) */ OFFSETOF_TWO_BYTES(label, TPM_DELEGATE_LABEL),
/* (1478) */ BC_INT8,
/* Record: TPM_DELEGATIONS */
/* (1479) */ BC_RECORD,
/* (1480) */ 4,
/* Field: tag */
/* (1481) */ BC_FIELD_KIND_NORMAL,
/* (1482) */ OFFSETOF_TWO_BYTES(tag, TPM_DELEGATIONS),
/* (1484) */ BC_INT16,
/* Field: delegateType */
/* (1485) */ BC_FIELD_KIND_NORMAL,
/* (1486) */ OFFSETOF_TWO_BYTES(delegateType, TPM_DELEGATIONS),
/* (1488) */ BC_INT32,
/* Field: per1 */
/* (1489) */ BC_FIELD_KIND_NORMAL,
/* (1490) */ OFFSETOF_TWO_BYTES(per1, TPM_DELEGATIONS),
/* (1492) */ BC_INT32,
/* Field: per2 */
/* (1493) */ BC_FIELD_KIND_NORMAL,
/* (1494) */ OFFSETOF_TWO_BYTES(per2, TPM_DELEGATIONS),
/* (1496) */ BC_INT32,
/* Record: TPM_DELEGATE_PUBLIC */
/* (1497) */ BC_RECORD,
/* (1498) */ 6,
/* Field: tag */
/* (1499) */ BC_FIELD_KIND_NORMAL,
/* (1500) */ OFFSETOF_TWO_BYTES(tag, TPM_DELEGATE_PUBLIC),
/* (1502) */ BC_INT16,
/* Field: label */
/* (1503) */ BC_FIELD_KIND_NORMAL,
/* (1504) */ OFFSETOF_TWO_BYTES(label, TPM_DELEGATE_PUBLIC),
/* (1506) */ BC_REF,
/* (1507) varint: 1473 */ 139, 65,
/* Field: pcrInfo */
/* (1509) */ BC_FIELD_KIND_NORMAL,
/* (1510) */ OFFSETOF_TWO_BYTES(pcrInfo, TPM_DELEGATE_PUBLIC),
/* (1512) */ BC_REF,
/* (1513) varint: 403 */ 131, 19,
/* Field: permissions */
/* (1515) */ BC_FIELD_KIND_NORMAL,
/* (1516) */ OFFSETOF_TWO_BYTES(permissions, TPM_DELEGATE_PUBLIC),
/* (1518) */ BC_REF,
/* (1519) varint: 1479 */ 139, 71,
/* Field: familyID */
/* (1521) */ BC_FIELD_KIND_NORMAL,
/* (1522) */ OFFSETOF_TWO_BYTES(familyID, TPM_DELEGATE_PUBLIC),
/* (1524) */ BC_INT32,
/* Field: verificationCount */
/* (1525) */ BC_FIELD_KIND_NORMAL,
/* (1526) */ OFFSETOF_TWO_BYTES(verificationCount, TPM_DELEGATE_PUBLIC),
/* (1528) */ BC_INT32,
/* Record: TPM_DELEGATE_TABLE_ROW */
/* (1529) */ BC_RECORD,
/* (1530) */ 3,
/* Field: tag */
/* (1531) */ BC_FIELD_KIND_NORMAL,
/* (1532) */ OFFSETOF_TWO_BYTES(tag, TPM_DELEGATE_TABLE_ROW),
/* (1534) */ BC_INT16,
/* Field: pub */
/* (1535) */ BC_FIELD_KIND_NORMAL,
/* (1536) */ OFFSETOF_TWO_BYTES(pub, TPM_DELEGATE_TABLE_ROW),
/* (1538) */ BC_REF,
/* (1539) varint: 1497 */ 139, 89,
/* Field: authValue */
/* (1541) */ BC_FIELD_KIND_NORMAL,
/* (1542) */ OFFSETOF_TWO_BYTES(authValue, TPM_DELEGATE_TABLE_ROW),
/* (1544) */ BC_REF,
/* (1545) varint: 48 */ 48,
/* Record: TPM_DELEGATE_SENSITIVE */
/* (1546) */ BC_RECORD,
/* (1547) */ 2,
/* Field: tag */
/* (1548) */ BC_FIELD_KIND_NORMAL,
/* (1549) */ OFFSETOF_TWO_BYTES(tag, TPM_DELEGATE_SENSITIVE),
/* (1551) */ BC_INT16,
/* Field: authValue */
/* (1552) */ BC_FIELD_KIND_NORMAL,
/* (1553) */ OFFSETOF_TWO_BYTES(authValue, TPM_DELEGATE_SENSITIVE),
/* (1555) */ BC_REF,
/* (1556) varint: 48 */ 48,
/* Record: TPM_DELEGATE_OWNER_BLOB */
/* (1557) */ BC_RECORD,
/* (1558) */ 7,
/* Field: tag */
/* (1559) */ BC_FIELD_KIND_NORMAL,
/* (1560) */ OFFSETOF_TWO_BYTES(tag, TPM_DELEGATE_OWNER_BLOB),
/* (1562) */ BC_INT16,
/* Field: pub */
/* (1563) */ BC_FIELD_KIND_NORMAL,
/* (1564) */ OFFSETOF_TWO_BYTES(pub, TPM_DELEGATE_OWNER_BLOB),
/* (1566) */ BC_REF,
/* (1567) varint: 1497 */ 139, 89,
/* Field: integrityDigest */
/* (1569) */ BC_FIELD_KIND_NORMAL,
/* (1570) */ OFFSETOF_TWO_BYTES(integrityDigest, TPM_DELEGATE_OWNER_BLOB),
/* (1572) */ BC_REF,
/* (1573) varint: 36 */ 36,
/* Field: additionalSize */
/* (1574) */ BC_FIELD_KIND_NORMAL,
/* (1575) */ OFFSETOF_TWO_BYTES(additionalSize, TPM_DELEGATE_OWNER_BLOB),
/* (1577) */ BC_INT32,
/* Variable-length field: additionalArea */
/* (1578) */ BC_FIELD_KIND_VARIABLE,
/* (1579) */ OFFSETOF_TWO_BYTES(additionalArea, TPM_DELEGATE_OWNER_BLOB),
/* (1581) */ 3,
/* (1582) */ BC_INT8,
/* Field: sensitiveSize */
/* (1583) */ BC_FIELD_KIND_NORMAL,
/* (1584) */ OFFSETOF_TWO_BYTES(sensitiveSize, TPM_DELEGATE_OWNER_BLOB),
/* (1586) */ BC_INT32,
/* Variable-length field: sensitiveArea */
/* (1587) */ BC_FIELD_KIND_VARIABLE,
/* (1588) */ OFFSETOF_TWO_BYTES(sensitiveArea, TPM_DELEGATE_OWNER_BLOB),
/* (1590) */ 5,
/* (1591) */ BC_INT8,
/* Record: TPM_DELEGATE_KEY_BLOB */
/* (1592) */ BC_RECORD,
/* (1593) */ 8,
/* Field: tag */
/* (1594) */ BC_FIELD_KIND_NORMAL,
/* (1595) */ OFFSETOF_TWO_BYTES(tag, TPM_DELEGATE_KEY_BLOB),
/* (1597) */ BC_INT16,
/* Field: pub */
/* (1598) */ BC_FIELD_KIND_NORMAL,
/* (1599) */ OFFSETOF_TWO_BYTES(pub, TPM_DELEGATE_KEY_BLOB),
/* (1601) */ BC_REF,
/* (1602) varint: 1497 */ 139, 89,
/* Field: integrityDigest */
/* (1604) */ BC_FIELD_KIND_NORMAL,
/* (1605) */ OFFSETOF_TWO_BYTES(integrityDigest, TPM_DELEGATE_KEY_BLOB),
/* (1607) */ BC_REF,
/* (1608) varint: 36 */ 36,
/* Field: pubKeyDigest */
/* (1609) */ BC_FIELD_KIND_NORMAL,
/* (1610) */ OFFSETOF_TWO_BYTES(pubKeyDigest, TPM_DELEGATE_KEY_BLOB),
/* (1612) */ BC_REF,
/* (1613) varint: 36 */ 36,
/* Field: additionalSize */
/* (1614) */ BC_FIELD_KIND_NORMAL,
/* (1615) */ OFFSETOF_TWO_BYTES(additionalSize, TPM_DELEGATE_KEY_BLOB),
/* (1617) */ BC_INT32,
/* Variable-length field: additionalArea */
/* (1618) */ BC_FIELD_KIND_VARIABLE,
/* (1619) */ OFFSETOF_TWO_BYTES(additionalArea, TPM_DELEGATE_KEY_BLOB),
/* (1621) */ 4,
/* (1622) */ BC_INT8,
/* Field: sensitiveSize */
/* (1623) */ BC_FIELD_KIND_NORMAL,
/* (1624) */ OFFSETOF_TWO_BYTES(sensitiveSize, TPM_DELEGATE_KEY_BLOB),
/* (1626) */ BC_INT32,
/* Variable-length field: sensitiveArea */
/* (1627) */ BC_FIELD_KIND_VARIABLE,
/* (1628) */ OFFSETOF_TWO_BYTES(sensitiveArea, TPM_DELEGATE_KEY_BLOB),
/* (1630) */ 6,
/* (1631) */ BC_INT8,
/* Record: TPM_CAP_VERSION_INFO */
/* (1632) */ BC_RECORD,
/* (1633) */ 7,
/* Field: tag */
/* (1634) */ BC_FIELD_KIND_NORMAL,
/* (1635) */ OFFSETOF_TWO_BYTES(tag, TPM_CAP_VERSION_INFO),
/* (1637) */ BC_INT16,
/* Field: version */
/* (1638) */ BC_FIELD_KIND_NORMAL,
/* (1639) */ OFFSETOF_TWO_BYTES(version, TPM_CAP_VERSION_INFO),
/* (1641) */ BC_REF,
/* (1642) varint: 18 */ 18,
/* Field: specLevel */
/* (1643) */ BC_FIELD_KIND_NORMAL,
/* (1644) */ OFFSETOF_TWO_BYTES(specLevel, TPM_CAP_VERSION_INFO),
/* (1646) */ BC_INT16,
/* Field: errataRev */
/* (1647) */ BC_FIELD_KIND_NORMAL,
/* (1648) */ OFFSETOF_TWO_BYTES(errataRev, TPM_CAP_VERSION_INFO),
/* (1650) */ BC_INT8,
/* Array field: tpmVendorID */
/* (1651) */ BC_ARRAY,
/* (1652) */ TWO_BYTES_INT(4),
/* (1654) */ BC_INT8,
/* Field: vendorSpecificSize */
/* (1655) */ BC_FIELD_KIND_NORMAL,
/* (1656) */ OFFSETOF_TWO_BYTES(vendorSpecificSize, TPM_CAP_VERSION_INFO),
/* (1658) */ BC_INT16,
/* Variable-length field: vendorSpecific */
/* (1659) */ BC_FIELD_KIND_VARIABLE,
/* (1660) */ OFFSETOF_TWO_BYTES(vendorSpecific, TPM_CAP_VERSION_INFO),
/* (1662) */ 5,
/* (1663) */ BC_INT8,
/* Record: TPM_DAA_ISSUER */
/* (1664) */ BC_RECORD,
/* (1665) */ 8,
/* Field: tag */
/* (1666) */ BC_FIELD_KIND_NORMAL,
/* (1667) */ OFFSETOF_TWO_BYTES(tag, TPM_DAA_ISSUER),
/* (1669) */ BC_INT16,
/* Field: DAA_digest_R0 */
/* (1670) */ BC_FIELD_KIND_NORMAL,
/* (1671) */ OFFSETOF_TWO_BYTES(DAA_digest_R0, TPM_DAA_ISSUER),
/* (1673) */ BC_REF,
/* (1674) varint: 36 */ 36,
/* Field: DAA_digest_R1 */
/* (1675) */ BC_FIELD_KIND_NORMAL,
/* (1676) */ OFFSETOF_TWO_BYTES(DAA_digest_R1, TPM_DAA_ISSUER),
/* (1678) */ BC_REF,
/* (1679) varint: 36 */ 36,
/* Field: DAA_digest_S0 */
/* (1680) */ BC_FIELD_KIND_NORMAL,
/* (1681) */ OFFSETOF_TWO_BYTES(DAA_digest_S0, TPM_DAA_ISSUER),
/* (1683) */ BC_REF,
/* (1684) varint: 36 */ 36,
/* Field: DAA_digest_S1 */
/* (1685) */ BC_FIELD_KIND_NORMAL,
/* (1686) */ OFFSETOF_TWO_BYTES(DAA_digest_S1, TPM_DAA_ISSUER),
/* (1688) */ BC_REF,
/* (1689) varint: 36 */ 36,
/* Field: DAA_digest_n */
/* (1690) */ BC_FIELD_KIND_NORMAL,
/* (1691) */ OFFSETOF_TWO_BYTES(DAA_digest_n, TPM_DAA_ISSUER),
/* (1693) */ BC_REF,
/* (1694) varint: 36 */ 36,
/* Field: DAA_digest_gamma */
/* (1695) */ BC_FIELD_KIND_NORMAL,
/* (1696) */ OFFSETOF_TWO_BYTES(DAA_digest_gamma, TPM_DAA_ISSUER),
/* (1698) */ BC_REF,
/* (1699) varint: 36 */ 36,
/* Array field: DAA_generic_q */
/* (1700) */ BC_ARRAY,
/* (1701) */ TWO_BYTES_INT(26),
/* (1703) */ BC_INT8,
/* Record: TPM_DAA_TPM */
/* (1704) */ BC_RECORD,
/* (1705) */ 6,
/* Field: tag */
/* (1706) */ BC_FIELD_KIND_NORMAL,
/* (1707) */ OFFSETOF_TWO_BYTES(tag, TPM_DAA_TPM),
/* (1709) */ BC_INT16,
/* Field: DAA_digestIssuer */
/* (1710) */ BC_FIELD_KIND_NORMAL,
/* (1711) */ OFFSETOF_TWO_BYTES(DAA_digestIssuer, TPM_DAA_TPM),
/* (1713) */ BC_REF,
/* (1714) varint: 36 */ 36,
/* Field: DAA_digest_v0 */
/* (1715) */ BC_FIELD_KIND_NORMAL,
/* (1716) */ OFFSETOF_TWO_BYTES(DAA_digest_v0, TPM_DAA_TPM),
/* (1718) */ BC_REF,
/* (1719) varint: 36 */ 36,
/* Field: DAA_digest_v1 */
/* (1720) */ BC_FIELD_KIND_NORMAL,
/* (1721) */ OFFSETOF_TWO_BYTES(DAA_digest_v1, TPM_DAA_TPM),
/* (1723) */ BC_REF,
/* (1724) varint: 36 */ 36,
/* Field: DAA_rekey */
/* (1725) */ BC_FIELD_KIND_NORMAL,
/* (1726) */ OFFSETOF_TWO_BYTES(DAA_rekey, TPM_DAA_TPM),
/* (1728) */ BC_REF,
/* (1729) varint: 36 */ 36,
/* Field: DAA_count */
/* (1730) */ BC_FIELD_KIND_NORMAL,
/* (1731) */ OFFSETOF_TWO_BYTES(DAA_count, TPM_DAA_TPM),
/* (1733) */ BC_INT32,
/* Record: TPM_DAA_CONTEXT */
/* (1734) */ BC_RECORD,
/* (1735) */ 6,
/* Field: tag */
/* (1736) */ BC_FIELD_KIND_NORMAL,
/* (1737) */ OFFSETOF_TWO_BYTES(tag, TPM_DAA_CONTEXT),
/* (1739) */ BC_INT16,
/* Field: DAA_digestContext */
/* (1740) */ BC_FIELD_KIND_NORMAL,
/* (1741) */ OFFSETOF_TWO_BYTES(DAA_digestContext, TPM_DAA_CONTEXT),
/* (1743) */ BC_REF,
/* (1744) varint: 36 */ 36,
/* Field: DAA_digest */
/* (1745) */ BC_FIELD_KIND_NORMAL,
/* (1746) */ OFFSETOF_TWO_BYTES(DAA_digest, TPM_DAA_CONTEXT),
/* (1748) */ BC_REF,
/* (1749) varint: 36 */ 36,
/* Field: DAA_contextSeed */
/* (1750) */ BC_FIELD_KIND_NORMAL,
/* (1751) */ OFFSETOF_TWO_BYTES(DAA_contextSeed, TPM_DAA_CONTEXT),
/* (1753) */ BC_REF,
/* (1754) varint: 36 */ 36,
/* Array field: DAA_scratch */
/* (1755) */ BC_ARRAY,
/* (1756) */ TWO_BYTES_INT(256),
/* (1758) */ BC_INT8,
/* Field: DAA_stage */
/* (1759) */ BC_FIELD_KIND_NORMAL,
/* (1760) */ OFFSETOF_TWO_BYTES(DAA_stage, TPM_DAA_CONTEXT),
/* (1762) */ BC_INT8,
/* Record: TPM_DAA_JOINDATA */
/* (1763) */ BC_RECORD,
/* (1764) */ 3,
/* Array field: DAA_join_u0 */
/* (1765) */ BC_ARRAY,
/* (1766) */ TWO_BYTES_INT(128),
/* (1768) */ BC_INT8,
/* Array field: DAA_join_u1 */
/* (1769) */ BC_ARRAY,
/* (1770) */ TWO_BYTES_INT(138),
/* (1772) */ BC_INT8,
/* Field: DAA_digest_n0 */
/* (1773) */ BC_FIELD_KIND_NORMAL,
/* (1774) */ OFFSETOF_TWO_BYTES(DAA_digest_n0, TPM_DAA_JOINDATA),
/* (1776) */ BC_REF,
/* (1777) varint: 36 */ 36,
/* Record: TPM_DAA_BLOB */
/* (1778) */ BC_RECORD,
/* (1779) */ 8,
/* Field: tag */
/* (1780) */ BC_FIELD_KIND_NORMAL,
/* (1781) */ OFFSETOF_TWO_BYTES(tag, TPM_DAA_BLOB),
/* (1783) */ BC_INT16,
/* Field: resourceType */
/* (1784) */ BC_FIELD_KIND_NORMAL,
/* (1785) */ OFFSETOF_TWO_BYTES(resourceType, TPM_DAA_BLOB),
/* (1787) */ BC_INT32,
/* Array field: label */
/* (1788) */ BC_ARRAY,
/* (1789) */ TWO_BYTES_INT(16),
/* (1791) */ BC_INT8,
/* Field: blobIntegrity */
/* (1792) */ BC_FIELD_KIND_NORMAL,
/* (1793) */ OFFSETOF_TWO_BYTES(blobIntegrity, TPM_DAA_BLOB),
/* (1795) */ BC_REF,
/* (1796) varint: 36 */ 36,
/* Field: additionalSize */
/* (1797) */ BC_FIELD_KIND_NORMAL,
/* (1798) */ OFFSETOF_TWO_BYTES(additionalSize, TPM_DAA_BLOB),
/* (1800) */ BC_INT32,
/* Variable-length field: additionalData */
/* (1801) */ BC_FIELD_KIND_VARIABLE,
/* (1802) */ OFFSETOF_TWO_BYTES(additionalData, TPM_DAA_BLOB),
/* (1804) */ 4,
/* (1805) */ BC_INT8,
/* Field: sensitiveSize */
/* (1806) */ BC_FIELD_KIND_NORMAL,
/* (1807) */ OFFSETOF_TWO_BYTES(sensitiveSize, TPM_DAA_BLOB),
/* (1809) */ BC_INT32,
/* Variable-length field: sensitiveData */
/* (1810) */ BC_FIELD_KIND_VARIABLE,
/* (1811) */ OFFSETOF_TWO_BYTES(sensitiveData, TPM_DAA_BLOB),
/* (1813) */ 6,
/* (1814) */ BC_INT8,
/* Record: TPM_DAA_SENSITIVE */
/* (1815) */ BC_RECORD,
/* (1816) */ 3,
/* Field: tag */
/* (1817) */ BC_FIELD_KIND_NORMAL,
/* (1818) */ OFFSETOF_TWO_BYTES(tag, TPM_DAA_SENSITIVE),
/* (1820) */ BC_INT16,
/* Field: internalSize */
/* (1821) */ BC_FIELD_KIND_NORMAL,
/* (1822) */ OFFSETOF_TWO_BYTES(internalSize, TPM_DAA_SENSITIVE),
/* (1824) */ BC_INT32,
/* Variable-length field: internalData */
/* (1825) */ BC_FIELD_KIND_VARIABLE,
/* (1826) */ OFFSETOF_TWO_BYTES(internalData, TPM_DAA_SENSITIVE),
/* (1828) */ 1,
/* (1829) */ BC_INT8,


/* Command Structures (request and response) */

/* Record: TPM_Startup_rqu */
/* (1830) */ BC_RECORD,
/* (1831) */ 1,
/* Field: startupType */
/* (1832) */ BC_FIELD_KIND_NORMAL,
/* (1833) */ OFFSETOF_TWO_BYTES(startupType, TPM_Startup_rqu),
/* (1835) */ BC_INT16,
/* Record: TPM_GetTestResult_rsp */
/* (1836) */ BC_RECORD,
/* (1837) */ 2,
/* Field: outDataSize */
/* (1838) */ BC_FIELD_KIND_NORMAL,
/* (1839) */ OFFSETOF_TWO_BYTES(outDataSize, TPM_GetTestResult_rsp),
/* (1841) */ BC_INT32,
/* Variable-length field: outData */
/* (1842) */ BC_FIELD_KIND_VARIABLE,
/* (1843) */ OFFSETOF_TWO_BYTES(outData, TPM_GetTestResult_rsp),
/* (1845) */ 0,
/* (1846) */ BC_INT8,
/* Record: TPM_SetOwnerInstall_rqu */
/* (1847) */ BC_RECORD,
/* (1848) */ 1,
/* Field: state */
/* (1849) */ BC_FIELD_KIND_NORMAL,
/* (1850) */ OFFSETOF_TWO_BYTES(state, TPM_SetOwnerInstall_rqu),
/* (1852) */ BC_INT8,
/* Record: TPM_OwnerSetDisable_rqu */
/* (1853) */ BC_RECORD,
/* (1854) */ 1,
/* Field: disableState */
/* (1855) */ BC_FIELD_KIND_NORMAL,
/* (1856) */ OFFSETOF_TWO_BYTES(disableState, TPM_OwnerSetDisable_rqu),
/* (1858) */ BC_INT8,
/* Record: TPM_PhysicalSetDeactivated_rqu */
/* (1859) */ BC_RECORD,
/* (1860) */ 1,
/* Field: state */
/* (1861) */ BC_FIELD_KIND_NORMAL,
/* (1862) */ OFFSETOF_TWO_BYTES(state, TPM_PhysicalSetDeactivated_rqu),
/* (1864) */ BC_INT8,
/* Record: TPM_SetOperatorAuth_rqu */
/* (1865) */ BC_RECORD,
/* (1866) */ 2,
/* Field: operatorAuth */
/* (1867) */ BC_FIELD_KIND_NORMAL,
/* (1868) */ OFFSETOF_TWO_BYTES(operatorAuth, TPM_SetOperatorAuth_rqu),
/* (1870) */ BC_REF,
/* (1871) varint: 48 */ 48,
/* Field: tag */
/* (1872) */ BC_FIELD_KIND_NORMAL,
/* (1873) */ OFFSETOF_TWO_BYTES(tag, TPM_SetOperatorAuth_rqu),
/* (1875) */ BC_INT16,
/* Record: TPM_TakeOwnership_rqu */
/* (1876) */ BC_RECORD,
/* (1877) */ 6,
/* Field: protocolID */
/* (1878) */ BC_FIELD_KIND_NORMAL,
/* (1879) */ OFFSETOF_TWO_BYTES(protocolID, TPM_TakeOwnership_rqu),
/* (1881) */ BC_INT16,
/* Field: encOwnerAuthSize */
/* (1882) */ BC_FIELD_KIND_NORMAL,
/* (1883) */ OFFSETOF_TWO_BYTES(encOwnerAuthSize, TPM_TakeOwnership_rqu),
/* (1885) */ BC_INT32,
/* Variable-length field: encOwnerAuth */
/* (1886) */ BC_FIELD_KIND_VARIABLE,
/* (1887) */ OFFSETOF_TWO_BYTES(encOwnerAuth, TPM_TakeOwnership_rqu),
/* (1889) */ 1,
/* (1890) */ BC_INT8,
/* Field: encSrkAuthSize */
/* (1891) */ BC_FIELD_KIND_NORMAL,
/* (1892) */ OFFSETOF_TWO_BYTES(encSrkAuthSize, TPM_TakeOwnership_rqu),
/* (1894) */ BC_INT32,
/* Variable-length field: encSrkAuth */
/* (1895) */ BC_FIELD_KIND_VARIABLE,
/* (1896) */ OFFSETOF_TWO_BYTES(encSrkAuth, TPM_TakeOwnership_rqu),
/* (1898) */ 3,
/* (1899) */ BC_INT8,
/* Field: srkParams */
/* (1900) */ BC_FIELD_KIND_NORMAL,
/* (1901) */ OFFSETOF_TWO_BYTES(srkParams, TPM_TakeOwnership_rqu),
/* (1903) */ BC_REF,
/* (1904) varint: 725 */ 133, 85,
/* Record: TPM_TakeOwnership_rsp */
/* (1906) */ BC_RECORD,
/* (1907) */ 1,
/* Field: srkPub */
/* (1908) */ BC_FIELD_KIND_NORMAL,
/* (1909) */ OFFSETOF_TWO_BYTES(srkPub, TPM_TakeOwnership_rsp),
/* (1911) */ BC_REF,
/* (1912) varint: 676 */ 133, 36,
/* Record: TSC_PhysicalPresence_rqu */
/* (1914) */ BC_RECORD,
/* (1915) */ 1,
/* Field: physicalPresence */
/* (1916) */ BC_FIELD_KIND_NORMAL,
/* (1917) */ OFFSETOF_TWO_BYTES(physicalPresence, TSC_PhysicalPresence_rqu),
/* (1919) */ BC_INT16,
/* Record: TPM_GetCapability_rqu */
/* (1920) */ BC_RECORD,
/* (1921) */ 3,
/* Field: capArea */
/* (1922) */ BC_FIELD_KIND_NORMAL,
/* (1923) */ OFFSETOF_TWO_BYTES(capArea, TPM_GetCapability_rqu),
/* (1925) */ BC_INT32,
/* Field: subCapSize */
/* (1926) */ BC_FIELD_KIND_NORMAL,
/* (1927) */ OFFSETOF_TWO_BYTES(subCapSize, TPM_GetCapability_rqu),
/* (1929) */ BC_INT32,
/* Variable-length field: subCap */
/* (1930) */ BC_FIELD_KIND_VARIABLE,
/* (1931) */ OFFSETOF_TWO_BYTES(subCap, TPM_GetCapability_rqu),
/* (1933) */ 1,
/* (1934) */ BC_INT8,
/* Record: TPM_GetCapability_rsp */
/* (1935) */ BC_RECORD,
/* (1936) */ 2,
/* Field: respSize */
/* (1937) */ BC_FIELD_KIND_NORMAL,
/* (1938) */ OFFSETOF_TWO_BYTES(respSize, TPM_GetCapability_rsp),
/* (1940) */ BC_INT32,
/* Variable-length field: resp */
/* (1941) */ BC_FIELD_KIND_VARIABLE,
/* (1942) */ OFFSETOF_TWO_BYTES(resp, TPM_GetCapability_rsp),
/* (1944) */ 0,
/* (1945) */ BC_INT8,
/* Record: TPM_SetCapability_rqu */
/* (1946) */ BC_RECORD,
/* (1947) */ 5,
/* Field: capArea */
/* (1948) */ BC_FIELD_KIND_NORMAL,
/* (1949) */ OFFSETOF_TWO_BYTES(capArea, TPM_SetCapability_rqu),
/* (1951) */ BC_INT32,
/* Field: subCapSize */
/* (1952) */ BC_FIELD_KIND_NORMAL,
/* (1953) */ OFFSETOF_TWO_BYTES(subCapSize, TPM_SetCapability_rqu),
/* (1955) */ BC_INT32,
/* Variable-length field: subCap */
/* (1956) */ BC_FIELD_KIND_VARIABLE,
/* (1957) */ OFFSETOF_TWO_BYTES(subCap, TPM_SetCapability_rqu),
/* (1959) */ 1,
/* (1960) */ BC_INT8,
/* Field: setValueSize */
/* (1961) */ BC_FIELD_KIND_NORMAL,
/* (1962) */ OFFSETOF_TWO_BYTES(setValueSize, TPM_SetCapability_rqu),
/* (1964) */ BC_INT32,
/* Variable-length field: setValue */
/* (1965) */ BC_FIELD_KIND_VARIABLE,
/* (1966) */ OFFSETOF_TWO_BYTES(setValue, TPM_SetCapability_rqu),
/* (1968) */ 3,
/* (1969) */ BC_INT8,
/* Record: TPM_GetCapabilityOwner_rsp */
/* (1970) */ BC_RECORD,
/* (1971) */ 3,
/* Field: version */
/* (1972) */ BC_FIELD_KIND_NORMAL,
/* (1973) */ OFFSETOF_TWO_BYTES(version, TPM_GetCapabilityOwner_rsp),
/* (1975) */ BC_REF,
/* (1976) varint: 18 */ 18,
/* Field: non_volatile_flags */
/* (1977) */ BC_FIELD_KIND_NORMAL,
/* (1978) */ OFFSETOF_TWO_BYTES(non_volatile_flags, TPM_GetCapabilityOwner_rsp),
/* (1980) */ BC_INT32,
/* Field: volatile_flags */
/* (1981) */ BC_FIELD_KIND_NORMAL,
/* (1982) */ OFFSETOF_TWO_BYTES(volatile_flags, TPM_GetCapabilityOwner_rsp),
/* (1984) */ BC_INT32,
/* Record: TPM_GetAuditDigest_rqu */
/* (1985) */ BC_RECORD,
/* (1986) */ 1,
/* Field: startOrdinal */
/* (1987) */ BC_FIELD_KIND_NORMAL,
/* (1988) */ OFFSETOF_TWO_BYTES(startOrdinal, TPM_GetAuditDigest_rqu),
/* (1990) */ BC_INT32,
/* Record: TPM_GetAuditDigest_rsp */
/* (1991) */ BC_RECORD,
/* (1992) */ 5,
/* Field: counterValue */
/* (1993) */ BC_FIELD_KIND_NORMAL,
/* (1994) */ OFFSETOF_TWO_BYTES(counterValue, TPM_GetAuditDigest_rsp),
/* (1996) */ BC_REF,
/* (1997) varint: 66 */ 66,
/* Field: auditDigest */
/* (1998) */ BC_FIELD_KIND_NORMAL,
/* (1999) */ OFFSETOF_TWO_BYTES(auditDigest, TPM_GetAuditDigest_rsp),
/* (2001) */ BC_REF,
/* (2002) varint: 36 */ 36,
/* Field: more */
/* (2003) */ BC_FIELD_KIND_NORMAL,
/* (2004) */ OFFSETOF_TWO_BYTES(more, TPM_GetAuditDigest_rsp),
/* (2006) */ BC_INT8,
/* Field: ordSize */
/* (2007) */ BC_FIELD_KIND_NORMAL,
/* (2008) */ OFFSETOF_TWO_BYTES(ordSize, TPM_GetAuditDigest_rsp),
/* (2010) */ BC_INT32,
/* Variable-length field: ordList */
/* (2011) */ BC_FIELD_KIND_VARIABLE,
/* (2012) */ OFFSETOF_TWO_BYTES(ordList, TPM_GetAuditDigest_rsp),
/* (2014) */ 3,
/* (2015) */ BC_INT8,
/* Record: TPM_GetAuditDigestSigned_rqu */
/* (2016) */ BC_RECORD,
/* (2017) */ 3,
/* Field: keyHandle */
/* (2018) */ BC_FIELD_KIND_NORMAL,
/* (2019) */ OFFSETOF_TWO_BYTES(keyHandle, TPM_GetAuditDigestSigned_rqu),
/* (2021) */ BC_INT32,
/* Field: closeAudit */
/* (2022) */ BC_FIELD_KIND_NORMAL,
/* (2023) */ OFFSETOF_TWO_BYTES(closeAudit, TPM_GetAuditDigestSigned_rqu),
/* (2025) */ BC_INT8,
/* Field: antiReplay */
/* (2026) */ BC_FIELD_KIND_NORMAL,
/* (2027) */ OFFSETOF_TWO_BYTES(antiReplay, TPM_GetAuditDigestSigned_rqu),
/* (2029) */ BC_REF,
/* (2030) varint: 42 */ 42,
/* Record: TPM_GetAuditDigestSigned_rsp */
/* (2031) */ BC_RECORD,
/* (2032) */ 5,
/* Field: counterValue */
/* (2033) */ BC_FIELD_KIND_NORMAL,
/* (2034) */ OFFSETOF_TWO_BYTES(counterValue, TPM_GetAuditDigestSigned_rsp),
/* (2036) */ BC_REF,
/* (2037) varint: 66 */ 66,
/* Field: auditDigest */
/* (2038) */ BC_FIELD_KIND_NORMAL,
/* (2039) */ OFFSETOF_TWO_BYTES(auditDigest, TPM_GetAuditDigestSigned_rsp),
/* (2041) */ BC_REF,
/* (2042) varint: 36 */ 36,
/* Field: ordinalDigest */
/* (2043) */ BC_FIELD_KIND_NORMAL,
/* (2044) */ OFFSETOF_TWO_BYTES(ordinalDigest, TPM_GetAuditDigestSigned_rsp),
/* (2046) */ BC_REF,
/* (2047) varint: 36 */ 36,
/* Field: sigSize */
/* (2048) */ BC_FIELD_KIND_NORMAL,
/* (2049) */ OFFSETOF_TWO_BYTES(sigSize, TPM_GetAuditDigestSigned_rsp),
/* (2051) */ BC_INT32,
/* Variable-length field: sig */
/* (2052) */ BC_FIELD_KIND_VARIABLE,
/* (2053) */ OFFSETOF_TWO_BYTES(sig, TPM_GetAuditDigestSigned_rsp),
/* (2055) */ 3,
/* (2056) */ BC_INT8,
/* Record: TPM_SetOrdinalAuditStatus_rqu */
/* (2057) */ BC_RECORD,
/* (2058) */ 2,
/* Field: ordinalToAudit */
/* (2059) */ BC_FIELD_KIND_NORMAL,
/* (2060) */ OFFSETOF_TWO_BYTES(ordinalToAudit, TPM_SetOrdinalAuditStatus_rqu),
/* (2062) */ BC_INT32,
/* Field: auditState */
/* (2063) */ BC_FIELD_KIND_NORMAL,
/* (2064) */ OFFSETOF_TWO_BYTES(auditState, TPM_SetOrdinalAuditStatus_rqu),
/* (2066) */ BC_INT8,
/* Record: TPM_SetRedirection_rqu */
/* (2067) */ BC_RECORD,
/* (2068) */ 4,
/* Field: keyHandle */
/* (2069) */ BC_FIELD_KIND_NORMAL,
/* (2070) */ OFFSETOF_TWO_BYTES(keyHandle, TPM_SetRedirection_rqu),
/* (2072) */ BC_INT32,
/* Field: redirCmd */
/* (2073) */ BC_FIELD_KIND_NORMAL,
/* (2074) */ OFFSETOF_TWO_BYTES(redirCmd, TPM_SetRedirection_rqu),
/* (2076) */ BC_INT32,
/* Field: inputDataSize */
/* (2077) */ BC_FIELD_KIND_NORMAL,
/* (2078) */ OFFSETOF_TWO_BYTES(inputDataSize, TPM_SetRedirection_rqu),
/* (2080) */ BC_INT32,
/* Field: inputData */
/* (2081) */ BC_FIELD_KIND_NORMAL,
/* (2082) */ OFFSETOF_TWO_BYTES(inputData, TPM_SetRedirection_rqu),
/* (2084) */ BC_INT8,
/* Record: TPM_Seal_rqu */
/* (2085) */ BC_RECORD,
/* (2086) */ 6,
/* Field: keyHandle */
/* (2087) */ BC_FIELD_KIND_NORMAL,
/* (2088) */ OFFSETOF_TWO_BYTES(keyHandle, TPM_Seal_rqu),
/* (2090) */ BC_INT32,
/* Field: encAuth */
/* (2091) */ BC_FIELD_KIND_NORMAL,
/* (2092) */ OFFSETOF_TWO_BYTES(encAuth, TPM_Seal_rqu),
/* (2094) */ BC_REF,
/* (2095) varint: 48 */ 48,
/* Field: pcrInfoSize */
/* (2096) */ BC_FIELD_KIND_NORMAL,
/* (2097) */ OFFSETOF_TWO_BYTES(pcrInfoSize, TPM_Seal_rqu),
/* (2099) */ BC_INT32,
/* Field: pcrInfo */
/* (2100) */ BC_FIELD_KIND_NORMAL,
/* (2101) */ OFFSETOF_TWO_BYTES(pcrInfo, TPM_Seal_rqu),
/* (2103) */ BC_REF,
/* (2104) varint: 349 */ 130, 93,
/* Field: inDataSize */
/* (2106) */ BC_FIELD_KIND_NORMAL,
/* (2107) */ OFFSETOF_TWO_BYTES(inDataSize, TPM_Seal_rqu),
/* (2109) */ BC_INT32,
/* Variable-length field: inData */
/* (2110) */ BC_FIELD_KIND_VARIABLE,
/* (2111) */ OFFSETOF_TWO_BYTES(inData, TPM_Seal_rqu),
/* (2113) */ 4,
/* (2114) */ BC_INT8,
/* Record: TPM_Seal_rsp */
/* (2115) */ BC_RECORD,
/* (2116) */ 1,
/* Field: sealedData */
/* (2117) */ BC_FIELD_KIND_NORMAL,
/* (2118) */ OFFSETOF_TWO_BYTES(sealedData, TPM_Seal_rsp),
/* (2120) */ BC_REF,
/* (2121) varint: 434 */ 131, 50,
/* Record: TPM_Unseal_rqu */
/* (2123) */ BC_RECORD,
/* (2124) */ 2,
/* Field: parentHandle */
/* (2125) */ BC_FIELD_KIND_NORMAL,
/* (2126) */ OFFSETOF_TWO_BYTES(parentHandle, TPM_Unseal_rqu),
/* (2128) */ BC_INT32,
/* Field: inData */
/* (2129) */ BC_FIELD_KIND_NORMAL,
/* (2130) */ OFFSETOF_TWO_BYTES(inData, TPM_Unseal_rqu),
/* (2132) */ BC_REF,
/* (2133) varint: 434 */ 131, 50,
/* Record: TPM_Unseal_rsp */
/* (2135) */ BC_RECORD,
/* (2136) */ 2,
/* Field: secretSize */
/* (2137) */ BC_FIELD_KIND_NORMAL,
/* (2138) */ OFFSETOF_TWO_BYTES(secretSize, TPM_Unseal_rsp),
/* (2140) */ BC_INT32,
/* Variable-length field: secret */
/* (2141) */ BC_FIELD_KIND_VARIABLE,
/* (2142) */ OFFSETOF_TWO_BYTES(secret, TPM_Unseal_rsp),
/* (2144) */ 0,
/* (2145) */ BC_INT8,
/* Record: TPM_UnBind_rqu */
/* (2146) */ BC_RECORD,
/* (2147) */ 3,
/* Field: keyHandle */
/* (2148) */ BC_FIELD_KIND_NORMAL,
/* (2149) */ OFFSETOF_TWO_BYTES(keyHandle, TPM_UnBind_rqu),
/* (2151) */ BC_INT32,
/* Field: inDataSize */
/* (2152) */ BC_FIELD_KIND_NORMAL,
/* (2153) */ OFFSETOF_TWO_BYTES(inDataSize, TPM_UnBind_rqu),
/* (2155) */ BC_INT32,
/* Variable-length field: inData */
/* (2156) */ BC_FIELD_KIND_VARIABLE,
/* (2157) */ OFFSETOF_TWO_BYTES(inData, TPM_UnBind_rqu),
/* (2159) */ 1,
/* (2160) */ BC_INT8,
/* Record: TPM_UnBind_rsp */
/* (2161) */ BC_RECORD,
/* (2162) */ 2,
/* Field: outDataSize */
/* (2163) */ BC_FIELD_KIND_NORMAL,
/* (2164) */ OFFSETOF_TWO_BYTES(outDataSize, TPM_UnBind_rsp),
/* (2166) */ BC_INT32,
/* Variable-length field: outData */
/* (2167) */ BC_FIELD_KIND_VARIABLE,
/* (2168) */ OFFSETOF_TWO_BYTES(outData, TPM_UnBind_rsp),
/* (2170) */ 0,
/* (2171) */ BC_INT8,
/* Record: TPM_CreateWrapKey_rqu */
/* (2172) */ BC_RECORD,
/* (2173) */ 4,
/* Field: parentHandle */
/* (2174) */ BC_FIELD_KIND_NORMAL,
/* (2175) */ OFFSETOF_TWO_BYTES(parentHandle, TPM_CreateWrapKey_rqu),
/* (2177) */ BC_INT32,
/* Field: dataUsageAuth */
/* (2178) */ BC_FIELD_KIND_NORMAL,
/* (2179) */ OFFSETOF_TWO_BYTES(dataUsageAuth, TPM_CreateWrapKey_rqu),
/* (2181) */ BC_REF,
/* (2182) varint: 48 */ 48,
/* Field: dataMigrationAuth */
/* (2183) */ BC_FIELD_KIND_NORMAL,
/* (2184) */ OFFSETOF_TWO_BYTES(dataMigrationAuth, TPM_CreateWrapKey_rqu),
/* (2186) */ BC_REF,
/* (2187) varint: 48 */ 48,
/* Field: keyInfo */
/* (2188) */ BC_FIELD_KIND_NORMAL,
/* (2189) */ OFFSETOF_TWO_BYTES(keyInfo, TPM_CreateWrapKey_rqu),
/* (2191) */ BC_REF,
/* (2192) varint: 676 */ 133, 36,
/* Record: TPM_CreateWrapKey_rsp */
/* (2194) */ BC_RECORD,
/* (2195) */ 1,
/* Field: wrappedKey */
/* (2196) */ BC_FIELD_KIND_NORMAL,
/* (2197) */ OFFSETOF_TWO_BYTES(wrappedKey, TPM_CreateWrapKey_rsp),
/* (2199) */ BC_REF,
/* (2200) varint: 676 */ 133, 36,
/* Record: TPM_LoadKey2_rqu */
/* (2202) */ BC_RECORD,
/* (2203) */ 2,
/* Field: parentHandle */
/* (2204) */ BC_FIELD_KIND_NORMAL,
/* (2205) */ OFFSETOF_TWO_BYTES(parentHandle, TPM_LoadKey2_rqu),
/* (2207) */ BC_INT32,
/* Field: inKey */
/* (2208) */ BC_FIELD_KIND_NORMAL,
/* (2209) */ OFFSETOF_TWO_BYTES(inKey, TPM_LoadKey2_rqu),
/* (2211) */ BC_REF,
/* (2212) varint: 676 */ 133, 36,
/* Record: TPM_LoadKey2_rsp */
/* (2214) */ BC_RECORD,
/* (2215) */ 1,
/* Field: inkeyHandle */
/* (2216) */ BC_FIELD_KIND_NORMAL,
/* (2217) */ OFFSETOF_TWO_BYTES(inkeyHandle, TPM_LoadKey2_rsp),
/* (2219) */ BC_INT32,
/* Record: TPM_GetPubKey_rqu */
/* (2220) */ BC_RECORD,
/* (2221) */ 1,
/* Field: keyHandle */
/* (2222) */ BC_FIELD_KIND_NORMAL,
/* (2223) */ OFFSETOF_TWO_BYTES(keyHandle, TPM_GetPubKey_rqu),
/* (2225) */ BC_INT32,
/* Record: TPM_GetPubKey_rsp */
/* (2226) */ BC_RECORD,
/* (2227) */ 1,
/* Field: pubKey */
/* (2228) */ BC_FIELD_KIND_NORMAL,
/* (2229) */ OFFSETOF_TWO_BYTES(pubKey, TPM_GetPubKey_rsp),
/* (2231) */ BC_REF,
/* (2232) varint: 624 */ 132, 112,
/* Record: TPM_Sealx_rqu */
/* (2234) */ BC_RECORD,
/* (2235) */ 6,
/* Field: keyHandle */
/* (2236) */ BC_FIELD_KIND_NORMAL,
/* (2237) */ OFFSETOF_TWO_BYTES(keyHandle, TPM_Sealx_rqu),
/* (2239) */ BC_INT32,
/* Field: encAuth */
/* (2240) */ BC_FIELD_KIND_NORMAL,
/* (2241) */ OFFSETOF_TWO_BYTES(encAuth, TPM_Sealx_rqu),
/* (2243) */ BC_REF,
/* (2244) varint: 48 */ 48,
/* Field: pcrInfoSize */
/* (2245) */ BC_FIELD_KIND_NORMAL,
/* (2246) */ OFFSETOF_TWO_BYTES(pcrInfoSize, TPM_Sealx_rqu),
/* (2248) */ BC_INT32,
/* Field: pcrInfo */
/* (2249) */ BC_FIELD_KIND_NORMAL,
/* (2250) */ OFFSETOF_TWO_BYTES(pcrInfo, TPM_Sealx_rqu),
/* (2252) */ BC_REF,
/* (2253) varint: 349 */ 130, 93,
/* Field: inDataSize */
/* (2255) */ BC_FIELD_KIND_NORMAL,
/* (2256) */ OFFSETOF_TWO_BYTES(inDataSize, TPM_Sealx_rqu),
/* (2258) */ BC_INT32,
/* Variable-length field: inData */
/* (2259) */ BC_FIELD_KIND_VARIABLE,
/* (2260) */ OFFSETOF_TWO_BYTES(inData, TPM_Sealx_rqu),
/* (2262) */ 4,
/* (2263) */ BC_INT8,
/* Record: TPM_Sealx_rsp */
/* (2264) */ BC_RECORD,
/* (2265) */ 1,
/* Field: sealedData */
/* (2266) */ BC_FIELD_KIND_NORMAL,
/* (2267) */ OFFSETOF_TWO_BYTES(sealedData, TPM_Sealx_rsp),
/* (2269) */ BC_REF,
/* (2270) varint: 434 */ 131, 50,
/* Record: TPM_CreateMigrationBlob_rqu */
/* (2272) */ BC_RECORD,
/* (2273) */ 5,
/* Field: parentHandle */
/* (2274) */ BC_FIELD_KIND_NORMAL,
/* (2275) */ OFFSETOF_TWO_BYTES(parentHandle, TPM_CreateMigrationBlob_rqu),
/* (2277) */ BC_INT32,
/* Field: migrationType */
/* (2278) */ BC_FIELD_KIND_NORMAL,
/* (2279) */ OFFSETOF_TWO_BYTES(migrationType, TPM_CreateMigrationBlob_rqu),
/* (2281) */ BC_INT16,
/* Field: migrationKeyAuth */
/* (2282) */ BC_FIELD_KIND_NORMAL,
/* (2283) */ OFFSETOF_TWO_BYTES(migrationKeyAuth, TPM_CreateMigrationBlob_rqu),
/* (2285) */ BC_REF,
/* (2286) varint: 802 */ 134, 34,
/* Field: encDataSize */
/* (2288) */ BC_FIELD_KIND_NORMAL,
/* (2289) */ OFFSETOF_TWO_BYTES(encDataSize, TPM_CreateMigrationBlob_rqu),
/* (2291) */ BC_INT32,
/* Variable-length field: encData */
/* (2292) */ BC_FIELD_KIND_VARIABLE,
/* (2293) */ OFFSETOF_TWO_BYTES(encData, TPM_CreateMigrationBlob_rqu),
/* (2295) */ 3,
/* (2296) */ BC_INT8,
/* Record: TPM_CreateMigrationBlob_rsp */
/* (2297) */ BC_RECORD,
/* (2298) */ 4,
/* Field: randomSize */
/* (2299) */ BC_FIELD_KIND_NORMAL,
/* (2300) */ OFFSETOF_TWO_BYTES(randomSize, TPM_CreateMigrationBlob_rsp),
/* (2302) */ BC_INT32,
/* Variable-length field: random */
/* (2303) */ BC_FIELD_KIND_VARIABLE,
/* (2304) */ OFFSETOF_TWO_BYTES(random, TPM_CreateMigrationBlob_rsp),
/* (2306) */ 0,
/* (2307) */ BC_INT8,
/* Field: outDataSize */
/* (2308) */ BC_FIELD_KIND_NORMAL,
/* (2309) */ OFFSETOF_TWO_BYTES(outDataSize, TPM_CreateMigrationBlob_rsp),
/* (2311) */ BC_INT32,
/* Variable-length field: outData */
/* (2312) */ BC_FIELD_KIND_VARIABLE,
/* (2313) */ OFFSETOF_TWO_BYTES(outData, TPM_CreateMigrationBlob_rsp),
/* (2315) */ 2,
/* (2316) */ BC_INT8,
/* Record: TPM_ConvertMigrationBlob_rqu */
/* (2317) */ BC_RECORD,
/* (2318) */ 5,
/* Field: parentHandle */
/* (2319) */ BC_FIELD_KIND_NORMAL,
/* (2320) */ OFFSETOF_TWO_BYTES(parentHandle, TPM_ConvertMigrationBlob_rqu),
/* (2322) */ BC_INT32,
/* Field: inDataSize */
/* (2323) */ BC_FIELD_KIND_NORMAL,
/* (2324) */ OFFSETOF_TWO_BYTES(inDataSize, TPM_ConvertMigrationBlob_rqu),
/* (2326) */ BC_INT32,
/* Variable-length field: inData */
/* (2327) */ BC_FIELD_KIND_VARIABLE,
/* (2328) */ OFFSETOF_TWO_BYTES(inData, TPM_ConvertMigrationBlob_rqu),
/* (2330) */ 1,
/* (2331) */ BC_INT8,
/* Field: randomSize */
/* (2332) */ BC_FIELD_KIND_NORMAL,
/* (2333) */ OFFSETOF_TWO_BYTES(randomSize, TPM_ConvertMigrationBlob_rqu),
/* (2335) */ BC_INT32,
/* Variable-length field: random */
/* (2336) */ BC_FIELD_KIND_VARIABLE,
/* (2337) */ OFFSETOF_TWO_BYTES(random, TPM_ConvertMigrationBlob_rqu),
/* (2339) */ 3,
/* (2340) */ BC_INT8,
/* Record: TPM_ConvertMigrationBlob_rsp */
/* (2341) */ BC_RECORD,
/* (2342) */ 2,
/* Field: outDataSize */
/* (2343) */ BC_FIELD_KIND_NORMAL,
/* (2344) */ OFFSETOF_TWO_BYTES(outDataSize, TPM_ConvertMigrationBlob_rsp),
/* (2346) */ BC_INT32,
/* Variable-length field: outData */
/* (2347) */ BC_FIELD_KIND_VARIABLE,
/* (2348) */ OFFSETOF_TWO_BYTES(outData, TPM_ConvertMigrationBlob_rsp),
/* (2350) */ 0,
/* (2351) */ BC_INT8,
/* Record: TPM_AuthorizeMigrationKey_rqu */
/* (2352) */ BC_RECORD,
/* (2353) */ 2,
/* Field: migrationScheme */
/* (2354) */ BC_FIELD_KIND_NORMAL,
/* (2355) */ OFFSETOF_TWO_BYTES(migrationScheme, TPM_AuthorizeMigrationKey_rqu),
/* (2357) */ BC_INT16,
/* Field: migrationKey */
/* (2358) */ BC_FIELD_KIND_NORMAL,
/* (2359) */ OFFSETOF_TWO_BYTES(migrationKey, TPM_AuthorizeMigrationKey_rqu),
/* (2361) */ BC_REF,
/* (2362) varint: 624 */ 132, 112,
/* Record: TPM_AuthorizeMigrationKey_rsp */
/* (2364) */ BC_RECORD,
/* (2365) */ 1,
/* Field: outData */
/* (2366) */ BC_FIELD_KIND_NORMAL,
/* (2367) */ OFFSETOF_TWO_BYTES(outData, TPM_AuthorizeMigrationKey_rsp),
/* (2369) */ BC_REF,
/* (2370) varint: 802 */ 134, 34,
/* Record: TPM_MigrateKey_rqu */
/* (2372) */ BC_RECORD,
/* (2373) */ 4,
/* Field: maKeyHandle */
/* (2374) */ BC_FIELD_KIND_NORMAL,
/* (2375) */ OFFSETOF_TWO_BYTES(maKeyHandle, TPM_MigrateKey_rqu),
/* (2377) */ BC_INT32,
/* Field: pubKey */
/* (2378) */ BC_FIELD_KIND_NORMAL,
/* (2379) */ OFFSETOF_TWO_BYTES(pubKey, TPM_MigrateKey_rqu),
/* (2381) */ BC_REF,
/* (2382) varint: 624 */ 132, 112,
/* Field: inDataSize */
/* (2384) */ BC_FIELD_KIND_NORMAL,
/* (2385) */ OFFSETOF_TWO_BYTES(inDataSize, TPM_MigrateKey_rqu),
/* (2387) */ BC_INT32,
/* Variable-length field: inData */
/* (2388) */ BC_FIELD_KIND_VARIABLE,
/* (2389) */ OFFSETOF_TWO_BYTES(inData, TPM_MigrateKey_rqu),
/* (2391) */ 2,
/* (2392) */ BC_INT8,
/* Record: TPM_MigrateKey_rsp */
/* (2393) */ BC_RECORD,
/* (2394) */ 2,
/* Field: outDataSize */
/* (2395) */ BC_FIELD_KIND_NORMAL,
/* (2396) */ OFFSETOF_TWO_BYTES(outDataSize, TPM_MigrateKey_rsp),
/* (2398) */ BC_INT32,
/* Variable-length field: outData */
/* (2399) */ BC_FIELD_KIND_VARIABLE,
/* (2400) */ OFFSETOF_TWO_BYTES(outData, TPM_MigrateKey_rsp),
/* (2402) */ 0,
/* (2403) */ BC_INT8,
/* Record: TPM_CMK_SetRestrictions_rqu */
/* (2404) */ BC_RECORD,
/* (2405) */ 1,
/* Field: restriction */
/* (2406) */ BC_FIELD_KIND_NORMAL,
/* (2407) */ OFFSETOF_TWO_BYTES(restriction, TPM_CMK_SetRestrictions_rqu),
/* (2409) */ BC_INT32,
/* Record: TPM_CMK_ApproveMA_rqu */
/* (2410) */ BC_RECORD,
/* (2411) */ 1,
/* Field: migrationAuthorityDigest */
/* (2412) */ BC_FIELD_KIND_NORMAL,
/* (2413) */ OFFSETOF_TWO_BYTES(migrationAuthorityDigest, TPM_CMK_ApproveMA_rqu),
/* (2415) */ BC_REF,
/* (2416) varint: 36 */ 36,
/* Record: TPM_CMK_ApproveMA_rsp */
/* (2417) */ BC_RECORD,
/* (2418) */ 1,
/* Field: outData */
/* (2419) */ BC_FIELD_KIND_NORMAL,
/* (2420) */ OFFSETOF_TWO_BYTES(outData, TPM_CMK_ApproveMA_rsp),
/* (2422) */ BC_REF,
/* (2423) varint: 36 */ 36,
/* Record: TPM_CMK_CreateKey_rqu */
/* (2424) */ BC_RECORD,
/* (2425) */ 5,
/* Field: parentHandle */
/* (2426) */ BC_FIELD_KIND_NORMAL,
/* (2427) */ OFFSETOF_TWO_BYTES(parentHandle, TPM_CMK_CreateKey_rqu),
/* (2429) */ BC_INT32,
/* Field: dataUsageAuth */
/* (2430) */ BC_FIELD_KIND_NORMAL,
/* (2431) */ OFFSETOF_TWO_BYTES(dataUsageAuth, TPM_CMK_CreateKey_rqu),
/* (2433) */ BC_REF,
/* (2434) varint: 48 */ 48,
/* Field: keyInfo */
/* (2435) */ BC_FIELD_KIND_NORMAL,
/* (2436) */ OFFSETOF_TWO_BYTES(keyInfo, TPM_CMK_CreateKey_rqu),
/* (2438) */ BC_REF,
/* (2439) varint: 725 */ 133, 85,
/* Field: migrationAuthorityApproval */
/* (2441) */ BC_FIELD_KIND_NORMAL,
/* (2442) */ OFFSETOF_TWO_BYTES(migrationAuthorityApproval, TPM_CMK_CreateKey_rqu),
/* (2444) */ BC_REF,
/* (2445) varint: 36 */ 36,
/* Field: migrationAuthorityDigest */
/* (2446) */ BC_FIELD_KIND_NORMAL,
/* (2447) */ OFFSETOF_TWO_BYTES(migrationAuthorityDigest, TPM_CMK_CreateKey_rqu),
/* (2449) */ BC_REF,
/* (2450) varint: 36 */ 36,
/* Record: TPM_CMK_CreateKey_rsp */
/* (2451) */ BC_RECORD,
/* (2452) */ 1,
/* Field: wrappedKey */
/* (2453) */ BC_FIELD_KIND_NORMAL,
/* (2454) */ OFFSETOF_TWO_BYTES(wrappedKey, TPM_CMK_CreateKey_rsp),
/* (2456) */ BC_REF,
/* (2457) varint: 725 */ 133, 85,
/* Record: TPM_CMK_CreateTicket_rqu */
/* (2459) */ BC_RECORD,
/* (2460) */ 4,
/* Field: verificationKey */
/* (2461) */ BC_FIELD_KIND_NORMAL,
/* (2462) */ OFFSETOF_TWO_BYTES(verificationKey, TPM_CMK_CreateTicket_rqu),
/* (2464) */ BC_REF,
/* (2465) varint: 624 */ 132, 112,
/* Field: signedData */
/* (2467) */ BC_FIELD_KIND_NORMAL,
/* (2468) */ OFFSETOF_TWO_BYTES(signedData, TPM_CMK_CreateTicket_rqu),
/* (2470) */ BC_REF,
/* (2471) varint: 36 */ 36,
/* Field: signatureValueSize */
/* (2472) */ BC_FIELD_KIND_NORMAL,
/* (2473) */ OFFSETOF_TWO_BYTES(signatureValueSize, TPM_CMK_CreateTicket_rqu),
/* (2475) */ BC_INT32,
/* Variable-length field: signatureValue */
/* (2476) */ BC_FIELD_KIND_VARIABLE,
/* (2477) */ OFFSETOF_TWO_BYTES(signatureValue, TPM_CMK_CreateTicket_rqu),
/* (2479) */ 2,
/* (2480) */ BC_INT8,
/* Record: TPM_CMK_CreateTicket_rsp */
/* (2481) */ BC_RECORD,
/* (2482) */ 1,
/* Field: sigTicket */
/* (2483) */ BC_FIELD_KIND_NORMAL,
/* (2484) */ OFFSETOF_TWO_BYTES(sigTicket, TPM_CMK_CreateTicket_rsp),
/* (2486) */ BC_REF,
/* (2487) varint: 36 */ 36,
/* Record: TPM_CMK_CreateBlob_rqu */
/* (2488) */ BC_RECORD,
/* (2489) */ 13,
/* Field: parentHandle */
/* (2490) */ BC_FIELD_KIND_NORMAL,
/* (2491) */ OFFSETOF_TWO_BYTES(parentHandle, TPM_CMK_CreateBlob_rqu),
/* (2493) */ BC_INT32,
/* Field: migrationType */
/* (2494) */ BC_FIELD_KIND_NORMAL,
/* (2495) */ OFFSETOF_TWO_BYTES(migrationType, TPM_CMK_CreateBlob_rqu),
/* (2497) */ BC_INT16,
/* Field: migrationKeyAuth */
/* (2498) */ BC_FIELD_KIND_NORMAL,
/* (2499) */ OFFSETOF_TWO_BYTES(migrationKeyAuth, TPM_CMK_CreateBlob_rqu),
/* (2501) */ BC_REF,
/* (2502) varint: 802 */ 134, 34,
/* Field: pubSourceKeyDigest */
/* (2504) */ BC_FIELD_KIND_NORMAL,
/* (2505) */ OFFSETOF_TWO_BYTES(pubSourceKeyDigest, TPM_CMK_CreateBlob_rqu),
/* (2507) */ BC_REF,
/* (2508) varint: 36 */ 36,
/* Field: msaListSize */
/* (2509) */ BC_FIELD_KIND_NORMAL,
/* (2510) */ OFFSETOF_TWO_BYTES(msaListSize, TPM_CMK_CreateBlob_rqu),
/* (2512) */ BC_INT32,
/* Field: structure */
/* (2513) */ BC_FIELD_KIND_NORMAL,
/* (2514) */ OFFSETOF_TWO_BYTES(structure, TPM_CMK_CreateBlob_rqu),
/* (2516) */ BC_REF,
/* (2517) varint: 104 */ 104,
/* Field: msaList */
/* (2518) */ BC_FIELD_KIND_NORMAL,
/* (2519) */ OFFSETOF_TWO_BYTES(msaList, TPM_CMK_CreateBlob_rqu),
/* (2521) */ BC_REF,
/* (2522) varint: 104 */ 104,
/* Field: restrictTicketSize */
/* (2523) */ BC_FIELD_KIND_NORMAL,
/* (2524) */ OFFSETOF_TWO_BYTES(restrictTicketSize, TPM_CMK_CreateBlob_rqu),
/* (2526) */ BC_INT32,
/* Variable-length field: restrictTicket */
/* (2527) */ BC_FIELD_KIND_VARIABLE,
/* (2528) */ OFFSETOF_TWO_BYTES(restrictTicket, TPM_CMK_CreateBlob_rqu),
/* (2530) */ 7,
/* (2531) */ BC_INT8,
/* Field: sigTicketSize */
/* (2532) */ BC_FIELD_KIND_NORMAL,
/* (2533) */ OFFSETOF_TWO_BYTES(sigTicketSize, TPM_CMK_CreateBlob_rqu),
/* (2535) */ BC_INT32,
/* Variable-length field: sigTicket */
/* (2536) */ BC_FIELD_KIND_VARIABLE,
/* (2537) */ OFFSETOF_TWO_BYTES(sigTicket, TPM_CMK_CreateBlob_rqu),
/* (2539) */ 9,
/* (2540) */ BC_INT8,
/* Field: encDataSize */
/* (2541) */ BC_FIELD_KIND_NORMAL,
/* (2542) */ OFFSETOF_TWO_BYTES(encDataSize, TPM_CMK_CreateBlob_rqu),
/* (2544) */ BC_INT32,
/* Variable-length field: encData */
/* (2545) */ BC_FIELD_KIND_VARIABLE,
/* (2546) */ OFFSETOF_TWO_BYTES(encData, TPM_CMK_CreateBlob_rqu),
/* (2548) */ 11,
/* (2549) */ BC_INT8,
/* Record: TPM_CMK_CreateBlob_rsp */
/* (2550) */ BC_RECORD,
/* (2551) */ 4,
/* Field: randomSize */
/* (2552) */ BC_FIELD_KIND_NORMAL,
/* (2553) */ OFFSETOF_TWO_BYTES(randomSize, TPM_CMK_CreateBlob_rsp),
/* (2555) */ BC_INT32,
/* Variable-length field: random */
/* (2556) */ BC_FIELD_KIND_VARIABLE,
/* (2557) */ OFFSETOF_TWO_BYTES(random, TPM_CMK_CreateBlob_rsp),
/* (2559) */ 0,
/* (2560) */ BC_INT8,
/* Field: outDataSize */
/* (2561) */ BC_FIELD_KIND_NORMAL,
/* (2562) */ OFFSETOF_TWO_BYTES(outDataSize, TPM_CMK_CreateBlob_rsp),
/* (2564) */ BC_INT32,
/* Variable-length field: outData */
/* (2565) */ BC_FIELD_KIND_VARIABLE,
/* (2566) */ OFFSETOF_TWO_BYTES(outData, TPM_CMK_CreateBlob_rsp),
/* (2568) */ 2,
/* (2569) */ BC_INT8,
/* Record: TPM_CMK_ConvertMigration_rqu */
/* (2570) */ BC_RECORD,
/* (2571) */ 10,
/* Field: parentHandle */
/* (2572) */ BC_FIELD_KIND_NORMAL,
/* (2573) */ OFFSETOF_TWO_BYTES(parentHandle, TPM_CMK_ConvertMigration_rqu),
/* (2575) */ BC_INT32,
/* Field: restrictTicket */
/* (2576) */ BC_FIELD_KIND_NORMAL,
/* (2577) */ OFFSETOF_TWO_BYTES(restrictTicket, TPM_CMK_ConvertMigration_rqu),
/* (2579) */ BC_REF,
/* (2580) varint: 116 */ 116,
/* Field: sigTicket */
/* (2581) */ BC_FIELD_KIND_NORMAL,
/* (2582) */ OFFSETOF_TWO_BYTES(sigTicket, TPM_CMK_ConvertMigration_rqu),
/* (2584) */ BC_REF,
/* (2585) varint: 36 */ 36,
/* Field: migratedKey */
/* (2586) */ BC_FIELD_KIND_NORMAL,
/* (2587) */ OFFSETOF_TWO_BYTES(migratedKey, TPM_CMK_ConvertMigration_rqu),
/* (2589) */ BC_REF,
/* (2590) varint: 725 */ 133, 85,
/* Field: properly */
/* (2592) */ BC_FIELD_KIND_NORMAL,
/* (2593) */ OFFSETOF_TWO_BYTES(properly, TPM_CMK_ConvertMigration_rqu),
/* (2595) */ BC_REF,
/* (2596) varint: 777 */ 134, 9,
/* Field: msaListSize */
/* (2598) */ BC_FIELD_KIND_NORMAL,
/* (2599) */ OFFSETOF_TWO_BYTES(msaListSize, TPM_CMK_ConvertMigration_rqu),
/* (2601) */ BC_INT32,
/* Field: structure */
/* (2602) */ BC_FIELD_KIND_NORMAL,
/* (2603) */ OFFSETOF_TWO_BYTES(structure, TPM_CMK_ConvertMigration_rqu),
/* (2605) */ BC_REF,
/* (2606) varint: 104 */ 104,
/* Field: msaList */
/* (2607) */ BC_FIELD_KIND_NORMAL,
/* (2608) */ OFFSETOF_TWO_BYTES(msaList, TPM_CMK_ConvertMigration_rqu),
/* (2610) */ BC_REF,
/* (2611) varint: 104 */ 104,
/* Field: randomSize */
/* (2612) */ BC_FIELD_KIND_NORMAL,
/* (2613) */ OFFSETOF_TWO_BYTES(randomSize, TPM_CMK_ConvertMigration_rqu),
/* (2615) */ BC_INT32,
/* Variable-length field: random */
/* (2616) */ BC_FIELD_KIND_VARIABLE,
/* (2617) */ OFFSETOF_TWO_BYTES(random, TPM_CMK_ConvertMigration_rqu),
/* (2619) */ 8,
/* (2620) */ BC_INT8,
/* Record: TPM_CMK_ConvertMigration_rsp */
/* (2621) */ BC_RECORD,
/* (2622) */ 2,
/* Field: outDataSize */
/* (2623) */ BC_FIELD_KIND_NORMAL,
/* (2624) */ OFFSETOF_TWO_BYTES(outDataSize, TPM_CMK_ConvertMigration_rsp),
/* (2626) */ BC_INT32,
/* Variable-length field: outData */
/* (2627) */ BC_FIELD_KIND_VARIABLE,
/* (2628) */ OFFSETOF_TWO_BYTES(outData, TPM_CMK_ConvertMigration_rsp),
/* (2630) */ 0,
/* (2631) */ BC_INT8,
/* Record: TPM_CreateMaintenanceArchive_rqu */
/* (2632) */ BC_RECORD,
/* (2633) */ 1,
/* Field: generateRandom */
/* (2634) */ BC_FIELD_KIND_NORMAL,
/* (2635) */ OFFSETOF_TWO_BYTES(generateRandom, TPM_CreateMaintenanceArchive_rqu),
/* (2637) */ BC_INT8,
/* Record: TPM_CreateMaintenanceArchive_rsp */
/* (2638) */ BC_RECORD,
/* (2639) */ 4,
/* Field: randomSize */
/* (2640) */ BC_FIELD_KIND_NORMAL,
/* (2641) */ OFFSETOF_TWO_BYTES(randomSize, TPM_CreateMaintenanceArchive_rsp),
/* (2643) */ BC_INT32,
/* Variable-length field: random */
/* (2644) */ BC_FIELD_KIND_VARIABLE,
/* (2645) */ OFFSETOF_TWO_BYTES(random, TPM_CreateMaintenanceArchive_rsp),
/* (2647) */ 0,
/* (2648) */ BC_INT8,
/* Field: archiveSize */
/* (2649) */ BC_FIELD_KIND_NORMAL,
/* (2650) */ OFFSETOF_TWO_BYTES(archiveSize, TPM_CreateMaintenanceArchive_rsp),
/* (2652) */ BC_INT32,
/* Variable-length field: archive */
/* (2653) */ BC_FIELD_KIND_VARIABLE,
/* (2654) */ OFFSETOF_TWO_BYTES(archive, TPM_CreateMaintenanceArchive_rsp),
/* (2656) */ 2,
/* (2657) */ BC_INT8,
/* Record: TPM_LoadMaintenanceArchive_rqu */
/* (2658) */ BC_RECORD,
/* (2659) */ 2,
/* Field: archiveSize */
/* (2660) */ BC_FIELD_KIND_NORMAL,
/* (2661) */ OFFSETOF_TWO_BYTES(archiveSize, TPM_LoadMaintenanceArchive_rqu),
/* (2663) */ BC_INT32,
/* Variable-length field: archive */
/* (2664) */ BC_FIELD_KIND_VARIABLE,
/* (2665) */ OFFSETOF_TWO_BYTES(archive, TPM_LoadMaintenanceArchive_rqu),
/* (2667) */ 0,
/* (2668) */ BC_INT8,
/* Record: TPM_LoadManuMaintPub_rqu */
/* (2669) */ BC_RECORD,
/* (2670) */ 2,
/* Field: antiReplay */
/* (2671) */ BC_FIELD_KIND_NORMAL,
/* (2672) */ OFFSETOF_TWO_BYTES(antiReplay, TPM_LoadManuMaintPub_rqu),
/* (2674) */ BC_REF,
/* (2675) varint: 42 */ 42,
/* Field: pubKey */
/* (2676) */ BC_FIELD_KIND_NORMAL,
/* (2677) */ OFFSETOF_TWO_BYTES(pubKey, TPM_LoadManuMaintPub_rqu),
/* (2679) */ BC_REF,
/* (2680) varint: 624 */ 132, 112,
/* Record: TPM_LoadManuMaintPub_rsp */
/* (2682) */ BC_RECORD,
/* (2683) */ 1,
/* Field: checksum */
/* (2684) */ BC_FIELD_KIND_NORMAL,
/* (2685) */ OFFSETOF_TWO_BYTES(checksum, TPM_LoadManuMaintPub_rsp),
/* (2687) */ BC_REF,
/* (2688) varint: 36 */ 36,
/* Record: TPM_ReadManuMaintPub_rqu */
/* (2689) */ BC_RECORD,
/* (2690) */ 1,
/* Field: antiReplay */
/* (2691) */ BC_FIELD_KIND_NORMAL,
/* (2692) */ OFFSETOF_TWO_BYTES(antiReplay, TPM_ReadManuMaintPub_rqu),
/* (2694) */ BC_REF,
/* (2695) varint: 42 */ 42,
/* Record: TPM_ReadManuMaintPub_rsp */
/* (2696) */ BC_RECORD,
/* (2697) */ 1,
/* Field: checksum */
/* (2698) */ BC_FIELD_KIND_NORMAL,
/* (2699) */ OFFSETOF_TWO_BYTES(checksum, TPM_ReadManuMaintPub_rsp),
/* (2701) */ BC_REF,
/* (2702) varint: 36 */ 36,
/* Record: TPM_SHA1Start_rsp */
/* (2703) */ BC_RECORD,
/* (2704) */ 1,
/* Field: maxNumBytes */
/* (2705) */ BC_FIELD_KIND_NORMAL,
/* (2706) */ OFFSETOF_TWO_BYTES(maxNumBytes, TPM_SHA1Start_rsp),
/* (2708) */ BC_INT32,
/* Record: TPM_SHA1Update_rqu */
/* (2709) */ BC_RECORD,
/* (2710) */ 2,
/* Field: numBytes */
/* (2711) */ BC_FIELD_KIND_NORMAL,
/* (2712) */ OFFSETOF_TWO_BYTES(numBytes, TPM_SHA1Update_rqu),
/* (2714) */ BC_INT32,
/* Variable-length field: hashData */
/* (2715) */ BC_FIELD_KIND_VARIABLE,
/* (2716) */ OFFSETOF_TWO_BYTES(hashData, TPM_SHA1Update_rqu),
/* (2718) */ 0,
/* (2719) */ BC_INT8,
/* Record: TPM_SHA1Complete_rqu */
/* (2720) */ BC_RECORD,
/* (2721) */ 2,
/* Field: hashDataSize */
/* (2722) */ BC_FIELD_KIND_NORMAL,
/* (2723) */ OFFSETOF_TWO_BYTES(hashDataSize, TPM_SHA1Complete_rqu),
/* (2725) */ BC_INT32,
/* Variable-length field: hashData */
/* (2726) */ BC_FIELD_KIND_VARIABLE,
/* (2727) */ OFFSETOF_TWO_BYTES(hashData, TPM_SHA1Complete_rqu),
/* (2729) */ 0,
/* (2730) */ BC_INT8,
/* Record: TPM_SHA1Complete_rsp */
/* (2731) */ BC_RECORD,
/* (2732) */ 1,
/* Field: hashValue */
/* (2733) */ BC_FIELD_KIND_NORMAL,
/* (2734) */ OFFSETOF_TWO_BYTES(hashValue, TPM_SHA1Complete_rsp),
/* (2736) */ BC_REF,
/* (2737) varint: 36 */ 36,
/* Record: TPM_SHA1CompleteExtend_rqu */
/* (2738) */ BC_RECORD,
/* (2739) */ 3,
/* Field: pcrNum */
/* (2740) */ BC_FIELD_KIND_NORMAL,
/* (2741) */ OFFSETOF_TWO_BYTES(pcrNum, TPM_SHA1CompleteExtend_rqu),
/* (2743) */ BC_INT32,
/* Field: hashDataSize */
/* (2744) */ BC_FIELD_KIND_NORMAL,
/* (2745) */ OFFSETOF_TWO_BYTES(hashDataSize, TPM_SHA1CompleteExtend_rqu),
/* (2747) */ BC_INT32,
/* Variable-length field: hashData */
/* (2748) */ BC_FIELD_KIND_VARIABLE,
/* (2749) */ OFFSETOF_TWO_BYTES(hashData, TPM_SHA1CompleteExtend_rqu),
/* (2751) */ 1,
/* (2752) */ BC_INT8,
/* Record: TPM_SHA1CompleteExtend_rsp */
/* (2753) */ BC_RECORD,
/* (2754) */ 2,
/* Field: hashValue */
/* (2755) */ BC_FIELD_KIND_NORMAL,
/* (2756) */ OFFSETOF_TWO_BYTES(hashValue, TPM_SHA1CompleteExtend_rsp),
/* (2758) */ BC_REF,
/* (2759) varint: 36 */ 36,
/* Field: outDigest */
/* (2760) */ BC_FIELD_KIND_NORMAL,
/* (2761) */ OFFSETOF_TWO_BYTES(outDigest, TPM_SHA1CompleteExtend_rsp),
/* (2763) */ BC_REF,
/* (2764) varint: 36 */ 36,
/* Record: TPM_Sign_rqu */
/* (2765) */ BC_RECORD,
/* (2766) */ 3,
/* Field: keyHandle */
/* (2767) */ BC_FIELD_KIND_NORMAL,
/* (2768) */ OFFSETOF_TWO_BYTES(keyHandle, TPM_Sign_rqu),
/* (2770) */ BC_INT32,
/* Field: areaToSignSize */
/* (2771) */ BC_FIELD_KIND_NORMAL,
/* (2772) */ OFFSETOF_TWO_BYTES(areaToSignSize, TPM_Sign_rqu),
/* (2774) */ BC_INT32,
/* Variable-length field: areaToSign */
/* (2775) */ BC_FIELD_KIND_VARIABLE,
/* (2776) */ OFFSETOF_TWO_BYTES(areaToSign, TPM_Sign_rqu),
/* (2778) */ 1,
/* (2779) */ BC_INT8,
/* Record: TPM_Sign_rsp */
/* (2780) */ BC_RECORD,
/* (2781) */ 2,
/* Field: sigSize */
/* (2782) */ BC_FIELD_KIND_NORMAL,
/* (2783) */ OFFSETOF_TWO_BYTES(sigSize, TPM_Sign_rsp),
/* (2785) */ BC_INT32,
/* Variable-length field: sig */
/* (2786) */ BC_FIELD_KIND_VARIABLE,
/* (2787) */ OFFSETOF_TWO_BYTES(sig, TPM_Sign_rsp),
/* (2789) */ 0,
/* (2790) */ BC_INT8,
/* Record: TPM_GetRandom_rqu */
/* (2791) */ BC_RECORD,
/* (2792) */ 1,
/* Field: bytesRequested */
/* (2793) */ BC_FIELD_KIND_NORMAL,
/* (2794) */ OFFSETOF_TWO_BYTES(bytesRequested, TPM_GetRandom_rqu),
/* (2796) */ BC_INT32,
/* Record: TPM_GetRandom_rsp */
/* (2797) */ BC_RECORD,
/* (2798) */ 2,
/* Field: randomBytesSize */
/* (2799) */ BC_FIELD_KIND_NORMAL,
/* (2800) */ OFFSETOF_TWO_BYTES(randomBytesSize, TPM_GetRandom_rsp),
/* (2802) */ BC_INT32,
/* Variable-length field: randomBytes */
/* (2803) */ BC_FIELD_KIND_VARIABLE,
/* (2804) */ OFFSETOF_TWO_BYTES(randomBytes, TPM_GetRandom_rsp),
/* (2806) */ 0,
/* (2807) */ BC_INT8,
/* Record: TPM_StirRandom_rqu */
/* (2808) */ BC_RECORD,
/* (2809) */ 2,
/* Field: dataSize */
/* (2810) */ BC_FIELD_KIND_NORMAL,
/* (2811) */ OFFSETOF_TWO_BYTES(dataSize, TPM_StirRandom_rqu),
/* (2813) */ BC_INT32,
/* Variable-length field: inData */
/* (2814) */ BC_FIELD_KIND_VARIABLE,
/* (2815) */ OFFSETOF_TWO_BYTES(inData, TPM_StirRandom_rqu),
/* (2817) */ 0,
/* (2818) */ BC_INT8,
/* Record: TPM_CertifyKey_rqu */
/* (2819) */ BC_RECORD,
/* (2820) */ 3,
/* Field: certHandle */
/* (2821) */ BC_FIELD_KIND_NORMAL,
/* (2822) */ OFFSETOF_TWO_BYTES(certHandle, TPM_CertifyKey_rqu),
/* (2824) */ BC_INT32,
/* Field: keyHandle */
/* (2825) */ BC_FIELD_KIND_NORMAL,
/* (2826) */ OFFSETOF_TWO_BYTES(keyHandle, TPM_CertifyKey_rqu),
/* (2828) */ BC_INT32,
/* Field: antiReplay */
/* (2829) */ BC_FIELD_KIND_NORMAL,
/* (2830) */ OFFSETOF_TWO_BYTES(antiReplay, TPM_CertifyKey_rqu),
/* (2832) */ BC_REF,
/* (2833) varint: 42 */ 42,
/* Record: TPM_CertifyKey_rsp */
/* (2834) */ BC_RECORD,
/* (2835) */ 4,
/* Field: certifyInfo */
/* (2836) */ BC_FIELD_KIND_NORMAL,
/* (2837) */ OFFSETOF_TWO_BYTES(certifyInfo, TPM_CertifyKey_rsp),
/* (2839) */ BC_REF,
/* (2840) varint: 819 */ 134, 51,
/* Field: or */
/* (2842) */ BC_FIELD_KIND_NORMAL,
/* (2843) */ OFFSETOF_TWO_BYTES(or, TPM_CertifyKey_rsp),
/* (2845) */ BC_REF,
/* (2846) varint: 819 */ 134, 51,
/* Field: outDataSize */
/* (2848) */ BC_FIELD_KIND_NORMAL,
/* (2849) */ OFFSETOF_TWO_BYTES(outDataSize, TPM_CertifyKey_rsp),
/* (2851) */ BC_INT32,
/* Variable-length field: outData */
/* (2852) */ BC_FIELD_KIND_VARIABLE,
/* (2853) */ OFFSETOF_TWO_BYTES(outData, TPM_CertifyKey_rsp),
/* (2855) */ 2,
/* (2856) */ BC_INT8,
/* Record: TPM_CertifyKey2_rqu */
/* (2857) */ BC_RECORD,
/* (2858) */ 4,
/* Field: keyHandle */
/* (2859) */ BC_FIELD_KIND_NORMAL,
/* (2860) */ OFFSETOF_TWO_BYTES(keyHandle, TPM_CertifyKey2_rqu),
/* (2862) */ BC_INT32,
/* Field: certHandle */
/* (2863) */ BC_FIELD_KIND_NORMAL,
/* (2864) */ OFFSETOF_TWO_BYTES(certHandle, TPM_CertifyKey2_rqu),
/* (2866) */ BC_INT32,
/* Field: migrationPubDigest */
/* (2867) */ BC_FIELD_KIND_NORMAL,
/* (2868) */ OFFSETOF_TWO_BYTES(migrationPubDigest, TPM_CertifyKey2_rqu),
/* (2870) */ BC_REF,
/* (2871) varint: 36 */ 36,
/* Field: antiReplay */
/* (2872) */ BC_FIELD_KIND_NORMAL,
/* (2873) */ OFFSETOF_TWO_BYTES(antiReplay, TPM_CertifyKey2_rqu),
/* (2875) */ BC_REF,
/* (2876) varint: 42 */ 42,
/* Record: TPM_CertifyKey2_rsp */
/* (2877) */ BC_RECORD,
/* (2878) */ 4,
/* Field: certifyInfo */
/* (2879) */ BC_FIELD_KIND_NORMAL,
/* (2880) */ OFFSETOF_TWO_BYTES(certifyInfo, TPM_CertifyKey2_rsp),
/* (2882) */ BC_REF,
/* (2883) varint: 867 */ 134, 99,
/* Field: relative */
/* (2885) */ BC_FIELD_KIND_NORMAL,
/* (2886) */ OFFSETOF_TWO_BYTES(relative, TPM_CertifyKey2_rsp),
/* (2888) */ BC_REF,
/* (2889) varint: 867 */ 134, 99,
/* Field: outDataSize */
/* (2891) */ BC_FIELD_KIND_NORMAL,
/* (2892) */ OFFSETOF_TWO_BYTES(outDataSize, TPM_CertifyKey2_rsp),
/* (2894) */ BC_INT32,
/* Variable-length field: outData */
/* (2895) */ BC_FIELD_KIND_VARIABLE,
/* (2896) */ OFFSETOF_TWO_BYTES(outData, TPM_CertifyKey2_rsp),
/* (2898) */ 2,
/* (2899) */ BC_INT8,
/* Record: TPM_CreateEndorsementKeyPair_rqu */
/* (2900) */ BC_RECORD,
/* (2901) */ 2,
/* Field: antiReplay */
/* (2902) */ BC_FIELD_KIND_NORMAL,
/* (2903) */ OFFSETOF_TWO_BYTES(antiReplay, TPM_CreateEndorsementKeyPair_rqu),
/* (2905) */ BC_REF,
/* (2906) varint: 42 */ 42,
/* Field: keyInfo */
/* (2907) */ BC_FIELD_KIND_NORMAL,
/* (2908) */ OFFSETOF_TWO_BYTES(keyInfo, TPM_CreateEndorsementKeyPair_rqu),
/* (2910) */ BC_REF,
/* (2911) varint: 552 */ 132, 40,
/* Record: TPM_CreateEndorsementKeyPair_rsp */
/* (2913) */ BC_RECORD,
/* (2914) */ 2,
/* Field: pubEndorsementKey */
/* (2915) */ BC_FIELD_KIND_NORMAL,
/* (2916) */ OFFSETOF_TWO_BYTES(pubEndorsementKey, TPM_CreateEndorsementKeyPair_rsp),
/* (2918) */ BC_REF,
/* (2919) varint: 624 */ 132, 112,
/* Field: checksum */
/* (2921) */ BC_FIELD_KIND_NORMAL,
/* (2922) */ OFFSETOF_TWO_BYTES(checksum, TPM_CreateEndorsementKeyPair_rsp),
/* (2924) */ BC_REF,
/* (2925) varint: 36 */ 36,
/* Record: TPM_CreateRevocableEK_rqu */
/* (2926) */ BC_RECORD,
/* (2927) */ 4,
/* Field: antiReplay */
/* (2928) */ BC_FIELD_KIND_NORMAL,
/* (2929) */ OFFSETOF_TWO_BYTES(antiReplay, TPM_CreateRevocableEK_rqu),
/* (2931) */ BC_REF,
/* (2932) varint: 42 */ 42,
/* Field: keyInfo */
/* (2933) */ BC_FIELD_KIND_NORMAL,
/* (2934) */ OFFSETOF_TWO_BYTES(keyInfo, TPM_CreateRevocableEK_rqu),
/* (2936) */ BC_REF,
/* (2937) varint: 552 */ 132, 40,
/* Field: generateReset */
/* (2939) */ BC_FIELD_KIND_NORMAL,
/* (2940) */ OFFSETOF_TWO_BYTES(generateReset, TPM_CreateRevocableEK_rqu),
/* (2942) */ BC_INT8,
/* Field: inputEKreset */
/* (2943) */ BC_FIELD_KIND_NORMAL,
/* (2944) */ OFFSETOF_TWO_BYTES(inputEKreset, TPM_CreateRevocableEK_rqu),
/* (2946) */ BC_REF,
/* (2947) varint: 42 */ 42,
/* Record: TPM_CreateRevocableEK_rsp */
/* (2948) */ BC_RECORD,
/* (2949) */ 3,
/* Field: pubEndorsementKey */
/* (2950) */ BC_FIELD_KIND_NORMAL,
/* (2951) */ OFFSETOF_TWO_BYTES(pubEndorsementKey, TPM_CreateRevocableEK_rsp),
/* (2953) */ BC_REF,
/* (2954) varint: 624 */ 132, 112,
/* Field: checksum */
/* (2956) */ BC_FIELD_KIND_NORMAL,
/* (2957) */ OFFSETOF_TWO_BYTES(checksum, TPM_CreateRevocableEK_rsp),
/* (2959) */ BC_REF,
/* (2960) varint: 36 */ 36,
/* Field: outputEKreset */
/* (2961) */ BC_FIELD_KIND_NORMAL,
/* (2962) */ OFFSETOF_TWO_BYTES(outputEKreset, TPM_CreateRevocableEK_rsp),
/* (2964) */ BC_REF,
/* (2965) varint: 42 */ 42,
/* Record: TPM_RevokeTrust_rqu */
/* (2966) */ BC_RECORD,
/* (2967) */ 1,
/* Field: EKReset */
/* (2968) */ BC_FIELD_KIND_NORMAL,
/* (2969) */ OFFSETOF_TWO_BYTES(EKReset, TPM_RevokeTrust_rqu),
/* (2971) */ BC_REF,
/* (2972) varint: 42 */ 42,
/* Record: TPM_ReadPubek_rqu */
/* (2973) */ BC_RECORD,
/* (2974) */ 1,
/* Field: antiReplay */
/* (2975) */ BC_FIELD_KIND_NORMAL,
/* (2976) */ OFFSETOF_TWO_BYTES(antiReplay, TPM_ReadPubek_rqu),
/* (2978) */ BC_REF,
/* (2979) varint: 42 */ 42,
/* Record: TPM_ReadPubek_rsp */
/* (2980) */ BC_RECORD,
/* (2981) */ 2,
/* Field: pubEndorsementKey */
/* (2982) */ BC_FIELD_KIND_NORMAL,
/* (2983) */ OFFSETOF_TWO_BYTES(pubEndorsementKey, TPM_ReadPubek_rsp),
/* (2985) */ BC_REF,
/* (2986) varint: 624 */ 132, 112,
/* Field: checksum */
/* (2988) */ BC_FIELD_KIND_NORMAL,
/* (2989) */ OFFSETOF_TWO_BYTES(checksum, TPM_ReadPubek_rsp),
/* (2991) */ BC_REF,
/* (2992) varint: 36 */ 36,
/* Record: TPM_OwnerReadInternalPub_rqu */
/* (2993) */ BC_RECORD,
/* (2994) */ 1,
/* Field: keyHandle */
/* (2995) */ BC_FIELD_KIND_NORMAL,
/* (2996) */ OFFSETOF_TWO_BYTES(keyHandle, TPM_OwnerReadInternalPub_rqu),
/* (2998) */ BC_INT32,
/* Record: TPM_OwnerReadInternalPub_rsp */
/* (2999) */ BC_RECORD,
/* (3000) */ 1,
/* Field: publicPortion */
/* (3001) */ BC_FIELD_KIND_NORMAL,
/* (3002) */ OFFSETOF_TWO_BYTES(publicPortion, TPM_OwnerReadInternalPub_rsp),
/* (3004) */ BC_REF,
/* (3005) varint: 624 */ 132, 112,
/* Record: TPM_MakeIdentity_rqu */
/* (3007) */ BC_RECORD,
/* (3008) */ 3,
/* Field: identityAuth */
/* (3009) */ BC_FIELD_KIND_NORMAL,
/* (3010) */ OFFSETOF_TWO_BYTES(identityAuth, TPM_MakeIdentity_rqu),
/* (3012) */ BC_REF,
/* (3013) varint: 48 */ 48,
/* Field: labelPrivCADigest */
/* (3014) */ BC_FIELD_KIND_NORMAL,
/* (3015) */ OFFSETOF_TWO_BYTES(labelPrivCADigest, TPM_MakeIdentity_rqu),
/* (3017) */ BC_REF,
/* (3018) varint: 36 */ 36,
/* Field: idKeyParams */
/* (3019) */ BC_FIELD_KIND_NORMAL,
/* (3020) */ OFFSETOF_TWO_BYTES(idKeyParams, TPM_MakeIdentity_rqu),
/* (3022) */ BC_REF,
/* (3023) varint: 676 */ 133, 36,
/* Record: TPM_MakeIdentity_rsp */
/* (3025) */ BC_RECORD,
/* (3026) */ 3,
/* Field: idKey */
/* (3027) */ BC_FIELD_KIND_NORMAL,
/* (3028) */ OFFSETOF_TWO_BYTES(idKey, TPM_MakeIdentity_rsp),
/* (3030) */ BC_REF,
/* (3031) varint: 676 */ 133, 36,
/* Field: identityBindingSize */
/* (3033) */ BC_FIELD_KIND_NORMAL,
/* (3034) */ OFFSETOF_TWO_BYTES(identityBindingSize, TPM_MakeIdentity_rsp),
/* (3036) */ BC_INT32,
/* Variable-length field: identityBinding */
/* (3037) */ BC_FIELD_KIND_VARIABLE,
/* (3038) */ OFFSETOF_TWO_BYTES(identityBinding, TPM_MakeIdentity_rsp),
/* (3040) */ 1,
/* (3041) */ BC_INT8,
/* Record: TPM_ActivateIdentity_rqu */
/* (3042) */ BC_RECORD,
/* (3043) */ 3,
/* Field: idKeyHandle */
/* (3044) */ BC_FIELD_KIND_NORMAL,
/* (3045) */ OFFSETOF_TWO_BYTES(idKeyHandle, TPM_ActivateIdentity_rqu),
/* (3047) */ BC_INT32,
/* Field: blobSize */
/* (3048) */ BC_FIELD_KIND_NORMAL,
/* (3049) */ OFFSETOF_TWO_BYTES(blobSize, TPM_ActivateIdentity_rqu),
/* (3051) */ BC_INT32,
/* Variable-length field: blob */
/* (3052) */ BC_FIELD_KIND_VARIABLE,
/* (3053) */ OFFSETOF_TWO_BYTES(blob, TPM_ActivateIdentity_rqu),
/* (3055) */ 1,
/* (3056) */ BC_INT8,
/* Record: TPM_ActivateIdentity_rsp */
/* (3057) */ BC_RECORD,
/* (3058) */ 1,
/* Field: symmetricKey */
/* (3059) */ BC_FIELD_KIND_NORMAL,
/* (3060) */ OFFSETOF_TWO_BYTES(symmetricKey, TPM_ActivateIdentity_rsp),
/* (3062) */ BC_REF,
/* (3063) varint: 517 */ 132, 5,
/* Record: TPM_Extend_rqu */
/* (3065) */ BC_RECORD,
/* (3066) */ 2,
/* Field: pcrNum */
/* (3067) */ BC_FIELD_KIND_NORMAL,
/* (3068) */ OFFSETOF_TWO_BYTES(pcrNum, TPM_Extend_rqu),
/* (3070) */ BC_INT32,
/* Field: inDigest */
/* (3071) */ BC_FIELD_KIND_NORMAL,
/* (3072) */ OFFSETOF_TWO_BYTES(inDigest, TPM_Extend_rqu),
/* (3074) */ BC_REF,
/* (3075) varint: 36 */ 36,
/* Record: TPM_Extend_rsp */
/* (3076) */ BC_RECORD,
/* (3077) */ 1,
/* Field: outDigest */
/* (3078) */ BC_FIELD_KIND_NORMAL,
/* (3079) */ OFFSETOF_TWO_BYTES(outDigest, TPM_Extend_rsp),
/* (3081) */ BC_REF,
/* (3082) varint: 36 */ 36,
/* Record: TPM_PCRRead_rqu */
/* (3083) */ BC_RECORD,
/* (3084) */ 1,
/* Field: pcrIndex */
/* (3085) */ BC_FIELD_KIND_NORMAL,
/* (3086) */ OFFSETOF_TWO_BYTES(pcrIndex, TPM_PCRRead_rqu),
/* (3088) */ BC_INT32,
/* Record: TPM_PCRRead_rsp */
/* (3089) */ BC_RECORD,
/* (3090) */ 1,
/* Field: outDigest */
/* (3091) */ BC_FIELD_KIND_NORMAL,
/* (3092) */ OFFSETOF_TWO_BYTES(outDigest, TPM_PCRRead_rsp),
/* (3094) */ BC_REF,
/* (3095) varint: 36 */ 36,
/* Record: TPM_Quote_rqu */
/* (3096) */ BC_RECORD,
/* (3097) */ 3,
/* Field: keyHandle */
/* (3098) */ BC_FIELD_KIND_NORMAL,
/* (3099) */ OFFSETOF_TWO_BYTES(keyHandle, TPM_Quote_rqu),
/* (3101) */ BC_INT32,
/* Field: externalData */
/* (3102) */ BC_FIELD_KIND_NORMAL,
/* (3103) */ OFFSETOF_TWO_BYTES(externalData, TPM_Quote_rqu),
/* (3105) */ BC_REF,
/* (3106) varint: 42 */ 42,
/* Field: targetPCR */
/* (3107) */ BC_FIELD_KIND_NORMAL,
/* (3108) */ OFFSETOF_TWO_BYTES(targetPCR, TPM_Quote_rqu),
/* (3110) */ BC_REF,
/* (3111) varint: 320 */ 130, 64,
/* Record: TPM_Quote_rsp */
/* (3113) */ BC_RECORD,
/* (3114) */ 3,
/* Field: pcrData */
/* (3115) */ BC_FIELD_KIND_NORMAL,
/* (3116) */ OFFSETOF_TWO_BYTES(pcrData, TPM_Quote_rsp),
/* (3118) */ BC_REF,
/* (3119) varint: 331 */ 130, 75,
/* Field: sigSize */
/* (3121) */ BC_FIELD_KIND_NORMAL,
/* (3122) */ OFFSETOF_TWO_BYTES(sigSize, TPM_Quote_rsp),
/* (3124) */ BC_INT32,
/* Variable-length field: sig */
/* (3125) */ BC_FIELD_KIND_VARIABLE,
/* (3126) */ OFFSETOF_TWO_BYTES(sig, TPM_Quote_rsp),
/* (3128) */ 1,
/* (3129) */ BC_INT8,
/* Record: TPM_PCR_Reset_rqu */
/* (3130) */ BC_RECORD,
/* (3131) */ 1,
/* Field: pcrSelection */
/* (3132) */ BC_FIELD_KIND_NORMAL,
/* (3133) */ OFFSETOF_TWO_BYTES(pcrSelection, TPM_PCR_Reset_rqu),
/* (3135) */ BC_REF,
/* (3136) varint: 320 */ 130, 64,
/* Record: TPM_Quote2_rqu */
/* (3138) */ BC_RECORD,
/* (3139) */ 4,
/* Field: keyHandle */
/* (3140) */ BC_FIELD_KIND_NORMAL,
/* (3141) */ OFFSETOF_TWO_BYTES(keyHandle, TPM_Quote2_rqu),
/* (3143) */ BC_INT32,
/* Field: externalData */
/* (3144) */ BC_FIELD_KIND_NORMAL,
/* (3145) */ OFFSETOF_TWO_BYTES(externalData, TPM_Quote2_rqu),
/* (3147) */ BC_REF,
/* (3148) varint: 42 */ 42,
/* Field: targetPCR */
/* (3149) */ BC_FIELD_KIND_NORMAL,
/* (3150) */ OFFSETOF_TWO_BYTES(targetPCR, TPM_Quote2_rqu),
/* (3152) */ BC_REF,
/* (3153) varint: 320 */ 130, 64,
/* Field: addVersion */
/* (3155) */ BC_FIELD_KIND_NORMAL,
/* (3156) */ OFFSETOF_TWO_BYTES(addVersion, TPM_Quote2_rqu),
/* (3158) */ BC_INT8,
/* Record: TPM_Quote2_rsp */
/* (3159) */ BC_RECORD,
/* (3160) */ 5,
/* Field: pcrData */
/* (3161) */ BC_FIELD_KIND_NORMAL,
/* (3162) */ OFFSETOF_TWO_BYTES(pcrData, TPM_Quote2_rsp),
/* (3164) */ BC_REF,
/* (3165) varint: 403 */ 131, 19,
/* Field: versionInfoSize */
/* (3167) */ BC_FIELD_KIND_NORMAL,
/* (3168) */ OFFSETOF_TWO_BYTES(versionInfoSize, TPM_Quote2_rsp),
/* (3170) */ BC_INT32,
/* Field: versionInfo */
/* (3171) */ BC_FIELD_KIND_NORMAL,
/* (3172) */ OFFSETOF_TWO_BYTES(versionInfo, TPM_Quote2_rsp),
/* (3174) */ BC_REF,
/* (3175) varint: 1632 */ 140, 96,
/* Field: sigSize */
/* (3177) */ BC_FIELD_KIND_NORMAL,
/* (3178) */ OFFSETOF_TWO_BYTES(sigSize, TPM_Quote2_rsp),
/* (3180) */ BC_INT32,
/* Variable-length field: sig */
/* (3181) */ BC_FIELD_KIND_VARIABLE,
/* (3182) */ OFFSETOF_TWO_BYTES(sig, TPM_Quote2_rsp),
/* (3184) */ 3,
/* (3185) */ BC_INT8,
/* Record: TPM_ChangeAuth_rqu */
/* (3186) */ BC_RECORD,
/* (3187) */ 6,
/* Field: parentHandle */
/* (3188) */ BC_FIELD_KIND_NORMAL,
/* (3189) */ OFFSETOF_TWO_BYTES(parentHandle, TPM_ChangeAuth_rqu),
/* (3191) */ BC_INT32,
/* Field: protocolID */
/* (3192) */ BC_FIELD_KIND_NORMAL,
/* (3193) */ OFFSETOF_TWO_BYTES(protocolID, TPM_ChangeAuth_rqu),
/* (3195) */ BC_INT16,
/* Field: newAuth */
/* (3196) */ BC_FIELD_KIND_NORMAL,
/* (3197) */ OFFSETOF_TWO_BYTES(newAuth, TPM_ChangeAuth_rqu),
/* (3199) */ BC_REF,
/* (3200) varint: 48 */ 48,
/* Field: entityType */
/* (3201) */ BC_FIELD_KIND_NORMAL,
/* (3202) */ OFFSETOF_TWO_BYTES(entityType, TPM_ChangeAuth_rqu),
/* (3204) */ BC_INT16,
/* Field: encDataSize */
/* (3205) */ BC_FIELD_KIND_NORMAL,
/* (3206) */ OFFSETOF_TWO_BYTES(encDataSize, TPM_ChangeAuth_rqu),
/* (3208) */ BC_INT32,
/* Variable-length field: encData */
/* (3209) */ BC_FIELD_KIND_VARIABLE,
/* (3210) */ OFFSETOF_TWO_BYTES(encData, TPM_ChangeAuth_rqu),
/* (3212) */ 4,
/* (3213) */ BC_INT8,
/* Record: TPM_ChangeAuth_rsp */
/* (3214) */ BC_RECORD,
/* (3215) */ 2,
/* Field: outDataSize */
/* (3216) */ BC_FIELD_KIND_NORMAL,
/* (3217) */ OFFSETOF_TWO_BYTES(outDataSize, TPM_ChangeAuth_rsp),
/* (3219) */ BC_INT32,
/* Variable-length field: outData */
/* (3220) */ BC_FIELD_KIND_VARIABLE,
/* (3221) */ OFFSETOF_TWO_BYTES(outData, TPM_ChangeAuth_rsp),
/* (3223) */ 0,
/* (3224) */ BC_INT8,
/* Record: TPM_ChangeAuthOwner_rqu */
/* (3225) */ BC_RECORD,
/* (3226) */ 3,
/* Field: protocolID */
/* (3227) */ BC_FIELD_KIND_NORMAL,
/* (3228) */ OFFSETOF_TWO_BYTES(protocolID, TPM_ChangeAuthOwner_rqu),
/* (3230) */ BC_INT16,
/* Field: newAuth */
/* (3231) */ BC_FIELD_KIND_NORMAL,
/* (3232) */ OFFSETOF_TWO_BYTES(newAuth, TPM_ChangeAuthOwner_rqu),
/* (3234) */ BC_REF,
/* (3235) varint: 48 */ 48,
/* Field: entityType */
/* (3236) */ BC_FIELD_KIND_NORMAL,
/* (3237) */ OFFSETOF_TWO_BYTES(entityType, TPM_ChangeAuthOwner_rqu),
/* (3239) */ BC_INT16,
/* Record: TPM_OIAP_rsp */
/* (3240) */ BC_RECORD,
/* (3241) */ 2,
/* Field: authHandle */
/* (3242) */ BC_FIELD_KIND_NORMAL,
/* (3243) */ OFFSETOF_TWO_BYTES(authHandle, TPM_OIAP_rsp),
/* (3245) */ BC_INT32,
/* Field: nonceEven */
/* (3246) */ BC_FIELD_KIND_NORMAL,
/* (3247) */ OFFSETOF_TWO_BYTES(nonceEven, TPM_OIAP_rsp),
/* (3249) */ BC_REF,
/* (3250) varint: 42 */ 42,
/* Record: TPM_OSAP_rqu */
/* (3251) */ BC_RECORD,
/* (3252) */ 3,
/* Field: entityType */
/* (3253) */ BC_FIELD_KIND_NORMAL,
/* (3254) */ OFFSETOF_TWO_BYTES(entityType, TPM_OSAP_rqu),
/* (3256) */ BC_INT16,
/* Field: entityValue */
/* (3257) */ BC_FIELD_KIND_NORMAL,
/* (3258) */ OFFSETOF_TWO_BYTES(entityValue, TPM_OSAP_rqu),
/* (3260) */ BC_INT32,
/* Field: nonceOddOSAP */
/* (3261) */ BC_FIELD_KIND_NORMAL,
/* (3262) */ OFFSETOF_TWO_BYTES(nonceOddOSAP, TPM_OSAP_rqu),
/* (3264) */ BC_REF,
/* (3265) varint: 42 */ 42,
/* Record: TPM_OSAP_rsp */
/* (3266) */ BC_RECORD,
/* (3267) */ 3,
/* Field: authHandle */
/* (3268) */ BC_FIELD_KIND_NORMAL,
/* (3269) */ OFFSETOF_TWO_BYTES(authHandle, TPM_OSAP_rsp),
/* (3271) */ BC_INT32,
/* Field: nonceEven */
/* (3272) */ BC_FIELD_KIND_NORMAL,
/* (3273) */ OFFSETOF_TWO_BYTES(nonceEven, TPM_OSAP_rsp),
/* (3275) */ BC_REF,
/* (3276) varint: 42 */ 42,
/* Field: nonceEvenOSAP */
/* (3277) */ BC_FIELD_KIND_NORMAL,
/* (3278) */ OFFSETOF_TWO_BYTES(nonceEvenOSAP, TPM_OSAP_rsp),
/* (3280) */ BC_REF,
/* (3281) varint: 42 */ 42,
/* Record: TPM_DSAP_rqu */
/* (3282) */ BC_RECORD,
/* (3283) */ 5,
/* Field: entityType */
/* (3284) */ BC_FIELD_KIND_NORMAL,
/* (3285) */ OFFSETOF_TWO_BYTES(entityType, TPM_DSAP_rqu),
/* (3287) */ BC_INT16,
/* Field: keyHandle */
/* (3288) */ BC_FIELD_KIND_NORMAL,
/* (3289) */ OFFSETOF_TWO_BYTES(keyHandle, TPM_DSAP_rqu),
/* (3291) */ BC_INT32,
/* Field: nonceOddDSAP */
/* (3292) */ BC_FIELD_KIND_NORMAL,
/* (3293) */ OFFSETOF_TWO_BYTES(nonceOddDSAP, TPM_DSAP_rqu),
/* (3295) */ BC_REF,
/* (3296) varint: 42 */ 42,
/* Field: entityValueSize */
/* (3297) */ BC_FIELD_KIND_NORMAL,
/* (3298) */ OFFSETOF_TWO_BYTES(entityValueSize, TPM_DSAP_rqu),
/* (3300) */ BC_INT32,
/* Variable-length field: entityValue */
/* (3301) */ BC_FIELD_KIND_VARIABLE,
/* (3302) */ OFFSETOF_TWO_BYTES(entityValue, TPM_DSAP_rqu),
/* (3304) */ 3,
/* (3305) */ BC_INT8,
/* Record: TPM_DSAP_rsp */
/* (3306) */ BC_RECORD,
/* (3307) */ 3,
/* Field: authHandle */
/* (3308) */ BC_FIELD_KIND_NORMAL,
/* (3309) */ OFFSETOF_TWO_BYTES(authHandle, TPM_DSAP_rsp),
/* (3311) */ BC_INT32,
/* Field: nonceEven */
/* (3312) */ BC_FIELD_KIND_NORMAL,
/* (3313) */ OFFSETOF_TWO_BYTES(nonceEven, TPM_DSAP_rsp),
/* (3315) */ BC_REF,
/* (3316) varint: 42 */ 42,
/* Field: nonceEvenDSAP */
/* (3317) */ BC_FIELD_KIND_NORMAL,
/* (3318) */ OFFSETOF_TWO_BYTES(nonceEvenDSAP, TPM_DSAP_rsp),
/* (3320) */ BC_REF,
/* (3321) varint: 42 */ 42,
/* Record: TPM_SetOwnerPointer_rqu */
/* (3322) */ BC_RECORD,
/* (3323) */ 2,
/* Field: entityType */
/* (3324) */ BC_FIELD_KIND_NORMAL,
/* (3325) */ OFFSETOF_TWO_BYTES(entityType, TPM_SetOwnerPointer_rqu),
/* (3327) */ BC_INT16,
/* Field: entityValue */
/* (3328) */ BC_FIELD_KIND_NORMAL,
/* (3329) */ OFFSETOF_TWO_BYTES(entityValue, TPM_SetOwnerPointer_rqu),
/* (3331) */ BC_INT32,
/* Record: TPM_Delegate_Manage_rqu */
/* (3332) */ BC_RECORD,
/* (3333) */ 4,
/* Field: familyID */
/* (3334) */ BC_FIELD_KIND_NORMAL,
/* (3335) */ OFFSETOF_TWO_BYTES(familyID, TPM_Delegate_Manage_rqu),
/* (3337) */ BC_INT32,
/* Field: opCode */
/* (3338) */ BC_FIELD_KIND_NORMAL,
/* (3339) */ OFFSETOF_TWO_BYTES(opCode, TPM_Delegate_Manage_rqu),
/* (3341) */ BC_INT32,
/* Field: opDataSize */
/* (3342) */ BC_FIELD_KIND_NORMAL,
/* (3343) */ OFFSETOF_TWO_BYTES(opDataSize, TPM_Delegate_Manage_rqu),
/* (3345) */ BC_INT32,
/* Variable-length field: opData */
/* (3346) */ BC_FIELD_KIND_VARIABLE,
/* (3347) */ OFFSETOF_TWO_BYTES(opData, TPM_Delegate_Manage_rqu),
/* (3349) */ 2,
/* (3350) */ BC_INT8,
/* Record: TPM_Delegate_Manage_rsp */
/* (3351) */ BC_RECORD,
/* (3352) */ 2,
/* Field: retDataSize */
/* (3353) */ BC_FIELD_KIND_NORMAL,
/* (3354) */ OFFSETOF_TWO_BYTES(retDataSize, TPM_Delegate_Manage_rsp),
/* (3356) */ BC_INT32,
/* Variable-length field: retData */
/* (3357) */ BC_FIELD_KIND_VARIABLE,
/* (3358) */ OFFSETOF_TWO_BYTES(retData, TPM_Delegate_Manage_rsp),
/* (3360) */ 0,
/* (3361) */ BC_INT8,
/* Record: TPM_Delegate_CreateKeyDelegation_rqu */
/* (3362) */ BC_RECORD,
/* (3363) */ 3,
/* Field: keyHandle */
/* (3364) */ BC_FIELD_KIND_NORMAL,
/* (3365) */ OFFSETOF_TWO_BYTES(keyHandle, TPM_Delegate_CreateKeyDelegation_rqu),
/* (3367) */ BC_INT32,
/* Field: publicInfo */
/* (3368) */ BC_FIELD_KIND_NORMAL,
/* (3369) */ OFFSETOF_TWO_BYTES(publicInfo, TPM_Delegate_CreateKeyDelegation_rqu),
/* (3371) */ BC_REF,
/* (3372) varint: 1497 */ 139, 89,
/* Field: delAuth */
/* (3374) */ BC_FIELD_KIND_NORMAL,
/* (3375) */ OFFSETOF_TWO_BYTES(delAuth, TPM_Delegate_CreateKeyDelegation_rqu),
/* (3377) */ BC_REF,
/* (3378) varint: 48 */ 48,
/* Record: TPM_Delegate_CreateKeyDelegation_rsp */
/* (3379) */ BC_RECORD,
/* (3380) */ 2,
/* Field: blobSize */
/* (3381) */ BC_FIELD_KIND_NORMAL,
/* (3382) */ OFFSETOF_TWO_BYTES(blobSize, TPM_Delegate_CreateKeyDelegation_rsp),
/* (3384) */ BC_INT32,
/* Field: blob */
/* (3385) */ BC_FIELD_KIND_NORMAL,
/* (3386) */ OFFSETOF_TWO_BYTES(blob, TPM_Delegate_CreateKeyDelegation_rsp),
/* (3388) */ BC_REF,
/* (3389) varint: 1592 */ 140, 56,
/* Record: TPM_Delegate_CreateOwnerDelegation_rqu */
/* (3391) */ BC_RECORD,
/* (3392) */ 3,
/* Field: increment */
/* (3393) */ BC_FIELD_KIND_NORMAL,
/* (3394) */ OFFSETOF_TWO_BYTES(increment, TPM_Delegate_CreateOwnerDelegation_rqu),
/* (3396) */ BC_INT8,
/* Field: publicInfo */
/* (3397) */ BC_FIELD_KIND_NORMAL,
/* (3398) */ OFFSETOF_TWO_BYTES(publicInfo, TPM_Delegate_CreateOwnerDelegation_rqu),
/* (3400) */ BC_REF,
/* (3401) varint: 1497 */ 139, 89,
/* Field: delAuth */
/* (3403) */ BC_FIELD_KIND_NORMAL,
/* (3404) */ OFFSETOF_TWO_BYTES(delAuth, TPM_Delegate_CreateOwnerDelegation_rqu),
/* (3406) */ BC_REF,
/* (3407) varint: 48 */ 48,
/* Record: TPM_Delegate_CreateOwnerDelegation_rsp */
/* (3408) */ BC_RECORD,
/* (3409) */ 2,
/* Field: blobSize */
/* (3410) */ BC_FIELD_KIND_NORMAL,
/* (3411) */ OFFSETOF_TWO_BYTES(blobSize, TPM_Delegate_CreateOwnerDelegation_rsp),
/* (3413) */ BC_INT32,
/* Field: blob */
/* (3414) */ BC_FIELD_KIND_NORMAL,
/* (3415) */ OFFSETOF_TWO_BYTES(blob, TPM_Delegate_CreateOwnerDelegation_rsp),
/* (3417) */ BC_REF,
/* (3418) varint: 1557 */ 140, 21,
/* Record: TPM_Delegate_LoadOwnerDelegation_rqu */
/* (3420) */ BC_RECORD,
/* (3421) */ 3,
/* Field: index */
/* (3422) */ BC_FIELD_KIND_NORMAL,
/* (3423) */ OFFSETOF_TWO_BYTES(index, TPM_Delegate_LoadOwnerDelegation_rqu),
/* (3425) */ BC_INT32,
/* Field: blobSize */
/* (3426) */ BC_FIELD_KIND_NORMAL,
/* (3427) */ OFFSETOF_TWO_BYTES(blobSize, TPM_Delegate_LoadOwnerDelegation_rqu),
/* (3429) */ BC_INT32,
/* Field: blob */
/* (3430) */ BC_FIELD_KIND_NORMAL,
/* (3431) */ OFFSETOF_TWO_BYTES(blob, TPM_Delegate_LoadOwnerDelegation_rqu),
/* (3433) */ BC_REF,
/* (3434) varint: 1557 */ 140, 21,
/* Record: TPM_Delegate_ReadTable_rsp */
/* (3436) */ BC_RECORD,
/* (3437) */ 4,
/* Field: familyTableSize */
/* (3438) */ BC_FIELD_KIND_NORMAL,
/* (3439) */ OFFSETOF_TWO_BYTES(familyTableSize, TPM_Delegate_ReadTable_rsp),
/* (3441) */ BC_INT32,
/* Variable-length field: familyTable */
/* (3442) */ BC_FIELD_KIND_VARIABLE,
/* (3443) */ OFFSETOF_TWO_BYTES(familyTable, TPM_Delegate_ReadTable_rsp),
/* (3445) */ 0,
/* (3446) */ BC_INT8,
/* Field: delegateTableSize */
/* (3447) */ BC_FIELD_KIND_NORMAL,
/* (3448) */ OFFSETOF_TWO_BYTES(delegateTableSize, TPM_Delegate_ReadTable_rsp),
/* (3450) */ BC_INT32,
/* Variable-length field: delegateTable */
/* (3451) */ BC_FIELD_KIND_VARIABLE,
/* (3452) */ OFFSETOF_TWO_BYTES(delegateTable, TPM_Delegate_ReadTable_rsp),
/* (3454) */ 2,
/* (3455) */ BC_INT8,
/* Record: TPM_Delegate_UpdateVerification_rqu */
/* (3456) */ BC_RECORD,
/* (3457) */ 3,
/* Field: inputSize */
/* (3458) */ BC_FIELD_KIND_NORMAL,
/* (3459) */ OFFSETOF_TWO_BYTES(inputSize, TPM_Delegate_UpdateVerification_rqu),
/* (3461) */ BC_INT32,
/* Field: inputData */
/* (3462) */ BC_FIELD_KIND_NORMAL,
/* (3463) */ OFFSETOF_TWO_BYTES(inputData, TPM_Delegate_UpdateVerification_rqu),
/* (3465) */ BC_INT8,
/* Field: or */
/* (3466) */ BC_FIELD_KIND_NORMAL,
/* (3467) */ OFFSETOF_TWO_BYTES(or, TPM_Delegate_UpdateVerification_rqu),
/* (3469) */ BC_REF,
/* (3470) varint: 1592 */ 140, 56,
/* Record: TPM_Delegate_UpdateVerification_rsp */
/* (3472) */ BC_RECORD,
/* (3473) */ 3,
/* Field: outputSize */
/* (3474) */ BC_FIELD_KIND_NORMAL,
/* (3475) */ OFFSETOF_TWO_BYTES(outputSize, TPM_Delegate_UpdateVerification_rsp),
/* (3477) */ BC_INT32,
/* Field: outputData */
/* (3478) */ BC_FIELD_KIND_NORMAL,
/* (3479) */ OFFSETOF_TWO_BYTES(outputData, TPM_Delegate_UpdateVerification_rsp),
/* (3481) */ BC_INT8,
/* Field: or */
/* (3482) */ BC_FIELD_KIND_NORMAL,
/* (3483) */ OFFSETOF_TWO_BYTES(or, TPM_Delegate_UpdateVerification_rsp),
/* (3485) */ BC_REF,
/* (3486) varint: 1592 */ 140, 56,
/* Record: TPM_Delegate_VerifyDelegation_rqu */
/* (3488) */ BC_RECORD,
/* (3489) */ 3,
/* Field: delegationSize */
/* (3490) */ BC_FIELD_KIND_NORMAL,
/* (3491) */ OFFSETOF_TWO_BYTES(delegationSize, TPM_Delegate_VerifyDelegation_rqu),
/* (3493) */ BC_INT32,
/* Variable-length field: delegation */
/* (3494) */ BC_FIELD_KIND_VARIABLE,
/* (3495) */ OFFSETOF_TWO_BYTES(delegation, TPM_Delegate_VerifyDelegation_rqu),
/* (3497) */ 0,
/* (3498) */ BC_INT8,
/* Field: or */
/* (3499) */ BC_FIELD_KIND_NORMAL,
/* (3500) */ OFFSETOF_TWO_BYTES(or, TPM_Delegate_VerifyDelegation_rqu),
/* (3502) */ BC_REF,
/* (3503) varint: 1592 */ 140, 56,
/* Record: TPM_NV_DefineSpace_rqu */
/* (3505) */ BC_RECORD,
/* (3506) */ 2,
/* Field: pubInfo */
/* (3507) */ BC_FIELD_KIND_NORMAL,
/* (3508) */ OFFSETOF_TWO_BYTES(pubInfo, TPM_NV_DefineSpace_rqu),
/* (3510) */ BC_REF,
/* (3511) varint: 1399 */ 138, 119,
/* Field: encAuth */
/* (3513) */ BC_FIELD_KIND_NORMAL,
/* (3514) */ OFFSETOF_TWO_BYTES(encAuth, TPM_NV_DefineSpace_rqu),
/* (3516) */ BC_REF,
/* (3517) varint: 48 */ 48,
/* Record: TPM_NV_WriteValue_rqu */
/* (3518) */ BC_RECORD,
/* (3519) */ 4,
/* Field: nvIndex */
/* (3520) */ BC_FIELD_KIND_NORMAL,
/* (3521) */ OFFSETOF_TWO_BYTES(nvIndex, TPM_NV_WriteValue_rqu),
/* (3523) */ BC_INT32,
/* Field: offset */
/* (3524) */ BC_FIELD_KIND_NORMAL,
/* (3525) */ OFFSETOF_TWO_BYTES(offset, TPM_NV_WriteValue_rqu),
/* (3527) */ BC_INT32,
/* Field: dataSize */
/* (3528) */ BC_FIELD_KIND_NORMAL,
/* (3529) */ OFFSETOF_TWO_BYTES(dataSize, TPM_NV_WriteValue_rqu),
/* (3531) */ BC_INT32,
/* Variable-length field: data */
/* (3532) */ BC_FIELD_KIND_VARIABLE,
/* (3533) */ OFFSETOF_TWO_BYTES(data, TPM_NV_WriteValue_rqu),
/* (3535) */ 2,
/* (3536) */ BC_INT8,
/* Record: TPM_NV_WriteValueAuth_rqu */
/* (3537) */ BC_RECORD,
/* (3538) */ 4,
/* Field: nvIndex */
/* (3539) */ BC_FIELD_KIND_NORMAL,
/* (3540) */ OFFSETOF_TWO_BYTES(nvIndex, TPM_NV_WriteValueAuth_rqu),
/* (3542) */ BC_INT32,
/* Field: offset */
/* (3543) */ BC_FIELD_KIND_NORMAL,
/* (3544) */ OFFSETOF_TWO_BYTES(offset, TPM_NV_WriteValueAuth_rqu),
/* (3546) */ BC_INT32,
/* Field: dataSize */
/* (3547) */ BC_FIELD_KIND_NORMAL,
/* (3548) */ OFFSETOF_TWO_BYTES(dataSize, TPM_NV_WriteValueAuth_rqu),
/* (3550) */ BC_INT32,
/* Field: data */
/* (3551) */ BC_FIELD_KIND_NORMAL,
/* (3552) */ OFFSETOF_TWO_BYTES(data, TPM_NV_WriteValueAuth_rqu),
/* (3554) */ BC_INT8,
/* Record: TPM_NV_ReadValue_rqu */
/* (3555) */ BC_RECORD,
/* (3556) */ 3,
/* Field: nvIndex */
/* (3557) */ BC_FIELD_KIND_NORMAL,
/* (3558) */ OFFSETOF_TWO_BYTES(nvIndex, TPM_NV_ReadValue_rqu),
/* (3560) */ BC_INT32,
/* Field: offset */
/* (3561) */ BC_FIELD_KIND_NORMAL,
/* (3562) */ OFFSETOF_TWO_BYTES(offset, TPM_NV_ReadValue_rqu),
/* (3564) */ BC_INT32,
/* Field: dataSize */
/* (3565) */ BC_FIELD_KIND_NORMAL,
/* (3566) */ OFFSETOF_TWO_BYTES(dataSize, TPM_NV_ReadValue_rqu),
/* (3568) */ BC_INT32,
/* Record: TPM_NV_ReadValue_rsp */
/* (3569) */ BC_RECORD,
/* (3570) */ 2,
/* Field: dataSize */
/* (3571) */ BC_FIELD_KIND_NORMAL,
/* (3572) */ OFFSETOF_TWO_BYTES(dataSize, TPM_NV_ReadValue_rsp),
/* (3574) */ BC_INT32,
/* Variable-length field: data */
/* (3575) */ BC_FIELD_KIND_VARIABLE,
/* (3576) */ OFFSETOF_TWO_BYTES(data, TPM_NV_ReadValue_rsp),
/* (3578) */ 0,
/* (3579) */ BC_INT8,
/* Record: TPM_NV_ReadValueAuth_rqu */
/* (3580) */ BC_RECORD,
/* (3581) */ 2,
/* Field: nvIndex */
/* (3582) */ BC_FIELD_KIND_NORMAL,
/* (3583) */ OFFSETOF_TWO_BYTES(nvIndex, TPM_NV_ReadValueAuth_rqu),
/* (3585) */ BC_INT32,
/* Field: dataSize */
/* (3586) */ BC_FIELD_KIND_NORMAL,
/* (3587) */ OFFSETOF_TWO_BYTES(dataSize, TPM_NV_ReadValueAuth_rqu),
/* (3589) */ BC_INT32,
/* Record: TPM_NV_ReadValueAuth_rsp */
/* (3590) */ BC_RECORD,
/* (3591) */ 2,
/* Field: dataSize */
/* (3592) */ BC_FIELD_KIND_NORMAL,
/* (3593) */ OFFSETOF_TWO_BYTES(dataSize, TPM_NV_ReadValueAuth_rsp),
/* (3595) */ BC_INT32,
/* Variable-length field: data */
/* (3596) */ BC_FIELD_KIND_VARIABLE,
/* (3597) */ OFFSETOF_TWO_BYTES(data, TPM_NV_ReadValueAuth_rsp),
/* (3599) */ 0,
/* (3600) */ BC_INT8,
/* Record: TPM_KeyControlOwner_rqu */
/* (3601) */ BC_RECORD,
/* (3602) */ 4,
/* Field: keyHandle */
/* (3603) */ BC_FIELD_KIND_NORMAL,
/* (3604) */ OFFSETOF_TWO_BYTES(keyHandle, TPM_KeyControlOwner_rqu),
/* (3606) */ BC_INT32,
/* Field: pubKey */
/* (3607) */ BC_FIELD_KIND_NORMAL,
/* (3608) */ OFFSETOF_TWO_BYTES(pubKey, TPM_KeyControlOwner_rqu),
/* (3610) */ BC_REF,
/* (3611) varint: 624 */ 132, 112,
/* Field: bitName */
/* (3613) */ BC_FIELD_KIND_NORMAL,
/* (3614) */ OFFSETOF_TWO_BYTES(bitName, TPM_KeyControlOwner_rqu),
/* (3616) */ BC_INT32,
/* Field: bitValue */
/* (3617) */ BC_FIELD_KIND_NORMAL,
/* (3618) */ OFFSETOF_TWO_BYTES(bitValue, TPM_KeyControlOwner_rqu),
/* (3620) */ BC_INT8,
/* Record: TPM_SaveContext_rqu */
/* (3621) */ BC_RECORD,
/* (3622) */ 4,
/* Field: handle */
/* (3623) */ BC_FIELD_KIND_NORMAL,
/* (3624) */ OFFSETOF_TWO_BYTES(handle, TPM_SaveContext_rqu),
/* (3626) */ BC_INT32,
/* Field: resourceType */
/* (3627) */ BC_FIELD_KIND_NORMAL,
/* (3628) */ OFFSETOF_TWO_BYTES(resourceType, TPM_SaveContext_rqu),
/* (3630) */ BC_INT32,
/* Array field: label */
/* (3631) */ BC_ARRAY,
/* (3632) */ TWO_BYTES_INT(16),
/* (3634) */ BC_INT8,
/* Field: tag */
/* (3635) */ BC_FIELD_KIND_NORMAL,
/* (3636) */ OFFSETOF_TWO_BYTES(tag, TPM_SaveContext_rqu),
/* (3638) */ BC_INT16,
/* Record: TPM_SaveContext_rsp */
/* (3639) */ BC_RECORD,
/* (3640) */ 1,
/* Field: contextBlob */
/* (3641) */ BC_FIELD_KIND_NORMAL,
/* (3642) */ OFFSETOF_TWO_BYTES(contextBlob, TPM_SaveContext_rsp),
/* (3644) */ BC_REF,
/* (3645) varint: 1324 */ 138, 44,
/* Record: TPM_LoadContext_rqu */
/* (3647) */ BC_RECORD,
/* (3648) */ 4,
/* Field: entityHandle */
/* (3649) */ BC_FIELD_KIND_NORMAL,
/* (3650) */ OFFSETOF_TWO_BYTES(entityHandle, TPM_LoadContext_rqu),
/* (3652) */ BC_INT32,
/* Field: keepHandle */
/* (3653) */ BC_FIELD_KIND_NORMAL,
/* (3654) */ OFFSETOF_TWO_BYTES(keepHandle, TPM_LoadContext_rqu),
/* (3656) */ BC_INT8,
/* Field: contextSize */
/* (3657) */ BC_FIELD_KIND_NORMAL,
/* (3658) */ OFFSETOF_TWO_BYTES(contextSize, TPM_LoadContext_rqu),
/* (3660) */ BC_INT32,
/* Field: contextBlob */
/* (3661) */ BC_FIELD_KIND_NORMAL,
/* (3662) */ OFFSETOF_TWO_BYTES(contextBlob, TPM_LoadContext_rqu),
/* (3664) */ BC_REF,
/* (3665) varint: 1324 */ 138, 44,
/* Record: TPM_LoadContext_rsp */
/* (3667) */ BC_RECORD,
/* (3668) */ 1,
/* Field: handle */
/* (3669) */ BC_FIELD_KIND_NORMAL,
/* (3670) */ OFFSETOF_TWO_BYTES(handle, TPM_LoadContext_rsp),
/* (3672) */ BC_INT32,
/* Record: TPM_FlushSpecific_rqu */
/* (3673) */ BC_RECORD,
/* (3674) */ 2,
/* Field: handle */
/* (3675) */ BC_FIELD_KIND_NORMAL,
/* (3676) */ OFFSETOF_TWO_BYTES(handle, TPM_FlushSpecific_rqu),
/* (3678) */ BC_INT32,
/* Field: resourceType */
/* (3679) */ BC_FIELD_KIND_NORMAL,
/* (3680) */ OFFSETOF_TWO_BYTES(resourceType, TPM_FlushSpecific_rqu),
/* (3682) */ BC_INT32,
/* Record: TPM_GetTicks_rsp */
/* (3683) */ BC_RECORD,
/* (3684) */ 1,
/* Field: currentTime */
/* (3685) */ BC_FIELD_KIND_NORMAL,
/* (3686) */ OFFSETOF_TWO_BYTES(currentTime, TPM_GetTicks_rsp),
/* (3688) */ BC_REF,
/* (3689) varint: 1168 */ 137, 16,
/* Record: TPM_TickStampBlob_rqu */
/* (3691) */ BC_RECORD,
/* (3692) */ 3,
/* Field: keyHandle */
/* (3693) */ BC_FIELD_KIND_NORMAL,
/* (3694) */ OFFSETOF_TWO_BYTES(keyHandle, TPM_TickStampBlob_rqu),
/* (3696) */ BC_INT32,
/* Field: antiReplay */
/* (3697) */ BC_FIELD_KIND_NORMAL,
/* (3698) */ OFFSETOF_TWO_BYTES(antiReplay, TPM_TickStampBlob_rqu),
/* (3700) */ BC_REF,
/* (3701) varint: 42 */ 42,
/* Field: digestToStamp */
/* (3702) */ BC_FIELD_KIND_NORMAL,
/* (3703) */ OFFSETOF_TWO_BYTES(digestToStamp, TPM_TickStampBlob_rqu),
/* (3705) */ BC_REF,
/* (3706) varint: 36 */ 36,
/* Record: TPM_TickStampBlob_rsp */
/* (3707) */ BC_RECORD,
/* (3708) */ 3,
/* Field: currentTicks */
/* (3709) */ BC_FIELD_KIND_NORMAL,
/* (3710) */ OFFSETOF_TWO_BYTES(currentTicks, TPM_TickStampBlob_rsp),
/* (3712) */ BC_REF,
/* (3713) varint: 1168 */ 137, 16,
/* Field: sigSize */
/* (3715) */ BC_FIELD_KIND_NORMAL,
/* (3716) */ OFFSETOF_TWO_BYTES(sigSize, TPM_TickStampBlob_rsp),
/* (3718) */ BC_INT32,
/* Variable-length field: sig */
/* (3719) */ BC_FIELD_KIND_VARIABLE,
/* (3720) */ OFFSETOF_TWO_BYTES(sig, TPM_TickStampBlob_rsp),
/* (3722) */ 1,
/* (3723) */ BC_INT8,
/* Record: TPM_EstablishTransport_rqu */
/* (3724) */ BC_RECORD,
/* (3725) */ 4,
/* Field: encHandle */
/* (3726) */ BC_FIELD_KIND_NORMAL,
/* (3727) */ OFFSETOF_TWO_BYTES(encHandle, TPM_EstablishTransport_rqu),
/* (3729) */ BC_INT32,
/* Field: transPublic */
/* (3730) */ BC_FIELD_KIND_NORMAL,
/* (3731) */ OFFSETOF_TWO_BYTES(transPublic, TPM_EstablishTransport_rqu),
/* (3733) */ BC_REF,
/* (3734) varint: 1187 */ 137, 35,
/* Field: secretSize */
/* (3736) */ BC_FIELD_KIND_NORMAL,
/* (3737) */ OFFSETOF_TWO_BYTES(secretSize, TPM_EstablishTransport_rqu),
/* (3739) */ BC_INT32,
/* Variable-length field: secret */
/* (3740) */ BC_FIELD_KIND_VARIABLE,
/* (3741) */ OFFSETOF_TWO_BYTES(secret, TPM_EstablishTransport_rqu),
/* (3743) */ 2,
/* (3744) */ BC_INT8,
/* Record: TPM_EstablishTransport_rsp */
/* (3745) */ BC_RECORD,
/* (3746) */ 4,
/* Field: transHandle */
/* (3747) */ BC_FIELD_KIND_NORMAL,
/* (3748) */ OFFSETOF_TWO_BYTES(transHandle, TPM_EstablishTransport_rsp),
/* (3750) */ BC_INT32,
/* Field: locality */
/* (3751) */ BC_FIELD_KIND_NORMAL,
/* (3752) */ OFFSETOF_TWO_BYTES(locality, TPM_EstablishTransport_rsp),
/* (3754) */ BC_INT32,
/* Field: currentTicks */
/* (3755) */ BC_FIELD_KIND_NORMAL,
/* (3756) */ OFFSETOF_TWO_BYTES(currentTicks, TPM_EstablishTransport_rsp),
/* (3758) */ BC_REF,
/* (3759) varint: 1168 */ 137, 16,
/* Field: transNonceEven */
/* (3761) */ BC_FIELD_KIND_NORMAL,
/* (3762) */ OFFSETOF_TWO_BYTES(transNonceEven, TPM_EstablishTransport_rsp),
/* (3764) */ BC_REF,
/* (3765) varint: 42 */ 42,
/* Record: TPM_ExecuteTransport_rqu */
/* (3766) */ BC_RECORD,
/* (3767) */ 2,
/* Field: wrappedCmdSize */
/* (3768) */ BC_FIELD_KIND_NORMAL,
/* (3769) */ OFFSETOF_TWO_BYTES(wrappedCmdSize, TPM_ExecuteTransport_rqu),
/* (3771) */ BC_INT32,
/* Variable-length field: wrappedCmd */
/* (3772) */ BC_FIELD_KIND_VARIABLE,
/* (3773) */ OFFSETOF_TWO_BYTES(wrappedCmd, TPM_ExecuteTransport_rqu),
/* (3775) */ 0,
/* (3776) */ BC_INT8,
/* Record: TPM_ExecuteTransport_rsp */
/* (3777) */ BC_RECORD,
/* (3778) */ 4,
/* Field: currentTicks */
/* (3779) */ BC_FIELD_KIND_NORMAL,
/* (3780) */ OFFSETOF_TWO_BYTES(currentTicks, TPM_ExecuteTransport_rsp),
/* (3782) */ BC_INT64,
/* Field: locality */
/* (3783) */ BC_FIELD_KIND_NORMAL,
/* (3784) */ OFFSETOF_TWO_BYTES(locality, TPM_ExecuteTransport_rsp),
/* (3786) */ BC_INT32,
/* Field: wrappedRspSize */
/* (3787) */ BC_FIELD_KIND_NORMAL,
/* (3788) */ OFFSETOF_TWO_BYTES(wrappedRspSize, TPM_ExecuteTransport_rsp),
/* (3790) */ BC_INT32,
/* Variable-length field: wrappedRsp */
/* (3791) */ BC_FIELD_KIND_VARIABLE,
/* (3792) */ OFFSETOF_TWO_BYTES(wrappedRsp, TPM_ExecuteTransport_rsp),
/* (3794) */ 2,
/* (3795) */ BC_INT8,
/* Record: TPM_ReleaseTransportSigned_rqu */
/* (3796) */ BC_RECORD,
/* (3797) */ 2,
/* Field: keyHandle */
/* (3798) */ BC_FIELD_KIND_NORMAL,
/* (3799) */ OFFSETOF_TWO_BYTES(keyHandle, TPM_ReleaseTransportSigned_rqu),
/* (3801) */ BC_INT32,
/* Field: antiReplay */
/* (3802) */ BC_FIELD_KIND_NORMAL,
/* (3803) */ OFFSETOF_TWO_BYTES(antiReplay, TPM_ReleaseTransportSigned_rqu),
/* (3805) */ BC_REF,
/* (3806) varint: 42 */ 42,
/* Record: TPM_ReleaseTransportSigned_rsp */
/* (3807) */ BC_RECORD,
/* (3808) */ 4,
/* Field: locality */
/* (3809) */ BC_FIELD_KIND_NORMAL,
/* (3810) */ OFFSETOF_TWO_BYTES(locality, TPM_ReleaseTransportSigned_rsp),
/* (3812) */ BC_INT32,
/* Field: currentTicks */
/* (3813) */ BC_FIELD_KIND_NORMAL,
/* (3814) */ OFFSETOF_TWO_BYTES(currentTicks, TPM_ReleaseTransportSigned_rsp),
/* (3816) */ BC_REF,
/* (3817) varint: 1168 */ 137, 16,
/* Field: signSize */
/* (3819) */ BC_FIELD_KIND_NORMAL,
/* (3820) */ OFFSETOF_TWO_BYTES(signSize, TPM_ReleaseTransportSigned_rsp),
/* (3822) */ BC_INT32,
/* Variable-length field: signature */
/* (3823) */ BC_FIELD_KIND_VARIABLE,
/* (3824) */ OFFSETOF_TWO_BYTES(signature, TPM_ReleaseTransportSigned_rsp),
/* (3826) */ 2,
/* (3827) */ BC_INT8,
/* Record: TPM_CreateCounter_rqu */
/* (3828) */ BC_RECORD,
/* (3829) */ 2,
/* Field: encAuth */
/* (3830) */ BC_FIELD_KIND_NORMAL,
/* (3831) */ OFFSETOF_TWO_BYTES(encAuth, TPM_CreateCounter_rqu),
/* (3833) */ BC_REF,
/* (3834) varint: 48 */ 48,
/* Field: label */
/* (3835) */ BC_FIELD_KIND_NORMAL,
/* (3836) */ OFFSETOF_TWO_BYTES(label, TPM_CreateCounter_rqu),
/* (3838) */ BC_INT8,
/* Record: TPM_CreateCounter_rsp */
/* (3839) */ BC_RECORD,
/* (3840) */ 2,
/* Field: countID */
/* (3841) */ BC_FIELD_KIND_NORMAL,
/* (3842) */ OFFSETOF_TWO_BYTES(countID, TPM_CreateCounter_rsp),
/* (3844) */ BC_INT32,
/* Field: counterValue */
/* (3845) */ BC_FIELD_KIND_NORMAL,
/* (3846) */ OFFSETOF_TWO_BYTES(counterValue, TPM_CreateCounter_rsp),
/* (3848) */ BC_REF,
/* (3849) varint: 66 */ 66,
/* Record: TPM_IncrementCounter_rqu */
/* (3850) */ BC_RECORD,
/* (3851) */ 1,
/* Field: countID */
/* (3852) */ BC_FIELD_KIND_NORMAL,
/* (3853) */ OFFSETOF_TWO_BYTES(countID, TPM_IncrementCounter_rqu),
/* (3855) */ BC_INT32,
/* Record: TPM_IncrementCounter_rsp */
/* (3856) */ BC_RECORD,
/* (3857) */ 1,
/* Field: count */
/* (3858) */ BC_FIELD_KIND_NORMAL,
/* (3859) */ OFFSETOF_TWO_BYTES(count, TPM_IncrementCounter_rsp),
/* (3861) */ BC_REF,
/* (3862) varint: 66 */ 66,
/* Record: TPM_ReadCounter_rqu */
/* (3863) */ BC_RECORD,
/* (3864) */ 1,
/* Field: countID */
/* (3865) */ BC_FIELD_KIND_NORMAL,
/* (3866) */ OFFSETOF_TWO_BYTES(countID, TPM_ReadCounter_rqu),
/* (3868) */ BC_INT32,
/* Record: TPM_ReadCounter_rsp */
/* (3869) */ BC_RECORD,
/* (3870) */ 1,
/* Field: count */
/* (3871) */ BC_FIELD_KIND_NORMAL,
/* (3872) */ OFFSETOF_TWO_BYTES(count, TPM_ReadCounter_rsp),
/* (3874) */ BC_REF,
/* (3875) varint: 66 */ 66,
/* Record: TPM_ReleaseCounter_rqu */
/* (3876) */ BC_RECORD,
/* (3877) */ 1,
/* Field: countID */
/* (3878) */ BC_FIELD_KIND_NORMAL,
/* (3879) */ OFFSETOF_TWO_BYTES(countID, TPM_ReleaseCounter_rqu),
/* (3881) */ BC_INT32,
/* Record: TPM_ReleaseCounterOwner_rqu */
/* (3882) */ BC_RECORD,
/* (3883) */ 1,
/* Field: countID */
/* (3884) */ BC_FIELD_KIND_NORMAL,
/* (3885) */ OFFSETOF_TWO_BYTES(countID, TPM_ReleaseCounterOwner_rqu),
/* (3887) */ BC_INT32,
/* Record: TPM_DAA_Join_rqu */
/* (3888) */ BC_RECORD,
/* (3889) */ 6,
/* Field: handle */
/* (3890) */ BC_FIELD_KIND_NORMAL,
/* (3891) */ OFFSETOF_TWO_BYTES(handle, TPM_DAA_Join_rqu),
/* (3893) */ BC_INT32,
/* Field: stage */
/* (3894) */ BC_FIELD_KIND_NORMAL,
/* (3895) */ OFFSETOF_TWO_BYTES(stage, TPM_DAA_Join_rqu),
/* (3897) */ BC_INT8,
/* Field: inputSize0 */
/* (3898) */ BC_FIELD_KIND_NORMAL,
/* (3899) */ OFFSETOF_TWO_BYTES(inputSize0, TPM_DAA_Join_rqu),
/* (3901) */ BC_INT32,
/* Variable-length field: inputData0 */
/* (3902) */ BC_FIELD_KIND_VARIABLE,
/* (3903) */ OFFSETOF_TWO_BYTES(inputData0, TPM_DAA_Join_rqu),
/* (3905) */ 2,
/* (3906) */ BC_INT8,
/* Field: inputSize1 */
/* (3907) */ BC_FIELD_KIND_NORMAL,
/* (3908) */ OFFSETOF_TWO_BYTES(inputSize1, TPM_DAA_Join_rqu),
/* (3910) */ BC_INT32,
/* Variable-length field: inputData1 */
/* (3911) */ BC_FIELD_KIND_VARIABLE,
/* (3912) */ OFFSETOF_TWO_BYTES(inputData1, TPM_DAA_Join_rqu),
/* (3914) */ 4,
/* (3915) */ BC_INT8,
/* Record: TPM_DAA_Join_rsp */
/* (3916) */ BC_RECORD,
/* (3917) */ 2,
/* Field: outputSize */
/* (3918) */ BC_FIELD_KIND_NORMAL,
/* (3919) */ OFFSETOF_TWO_BYTES(outputSize, TPM_DAA_Join_rsp),
/* (3921) */ BC_INT32,
/* Variable-length field: outputData */
/* (3922) */ BC_FIELD_KIND_VARIABLE,
/* (3923) */ OFFSETOF_TWO_BYTES(outputData, TPM_DAA_Join_rsp),
/* (3925) */ 0,
/* (3926) */ BC_INT8,
/* Record: TPM_DAA_Sign_rqu */
/* (3927) */ BC_RECORD,
/* (3928) */ 6,
/* Field: handle */
/* (3929) */ BC_FIELD_KIND_NORMAL,
/* (3930) */ OFFSETOF_TWO_BYTES(handle, TPM_DAA_Sign_rqu),
/* (3932) */ BC_INT32,
/* Field: stage */
/* (3933) */ BC_FIELD_KIND_NORMAL,
/* (3934) */ OFFSETOF_TWO_BYTES(stage, TPM_DAA_Sign_rqu),
/* (3936) */ BC_INT8,
/* Field: inputSize0 */
/* (3937) */ BC_FIELD_KIND_NORMAL,
/* (3938) */ OFFSETOF_TWO_BYTES(inputSize0, TPM_DAA_Sign_rqu),
/* (3940) */ BC_INT32,
/* Variable-length field: inputData0 */
/* (3941) */ BC_FIELD_KIND_VARIABLE,
/* (3942) */ OFFSETOF_TWO_BYTES(inputData0, TPM_DAA_Sign_rqu),
/* (3944) */ 2,
/* (3945) */ BC_INT8,
/* Field: inputSize1 */
/* (3946) */ BC_FIELD_KIND_NORMAL,
/* (3947) */ OFFSETOF_TWO_BYTES(inputSize1, TPM_DAA_Sign_rqu),
/* (3949) */ BC_INT32,
/* Variable-length field: inputData1 */
/* (3950) */ BC_FIELD_KIND_VARIABLE,
/* (3951) */ OFFSETOF_TWO_BYTES(inputData1, TPM_DAA_Sign_rqu),
/* (3953) */ 4,
/* (3954) */ BC_INT8,
/* Record: TPM_DAA_Sign_rsp */
/* (3955) */ BC_RECORD,
/* (3956) */ 2,
/* Field: outputSize */
/* (3957) */ BC_FIELD_KIND_NORMAL,
/* (3958) */ OFFSETOF_TWO_BYTES(outputSize, TPM_DAA_Sign_rsp),
/* (3960) */ BC_INT32,
/* Variable-length field: outputData */
/* (3961) */ BC_FIELD_KIND_VARIABLE,
/* (3962) */ OFFSETOF_TWO_BYTES(outputData, TPM_DAA_Sign_rsp),
/* (3964) */ 0,
/* (3965) */ BC_INT8,
/* Record: TPM_EvictKey_rqu */
/* (3966) */ BC_RECORD,
/* (3967) */ 1,
/* Field: evictHandle */
/* (3968) */ BC_FIELD_KIND_NORMAL,
/* (3969) */ OFFSETOF_TWO_BYTES(evictHandle, TPM_EvictKey_rqu),
/* (3971) */ BC_INT32,
/* Record: TPM_Terminate_Handle_rqu */
/* (3972) */ BC_RECORD,
/* (3973) */ 1,
/* Field: handle */
/* (3974) */ BC_FIELD_KIND_NORMAL,
/* (3975) */ OFFSETOF_TWO_BYTES(handle, TPM_Terminate_Handle_rqu),
/* (3977) */ BC_INT32,
/* Record: TPM_SaveKeyContext_rqu */
/* (3978) */ BC_RECORD,
/* (3979) */ 1,
/* Field: keyHandle */
/* (3980) */ BC_FIELD_KIND_NORMAL,
/* (3981) */ OFFSETOF_TWO_BYTES(keyHandle, TPM_SaveKeyContext_rqu),
/* (3983) */ BC_INT32,
/* Record: TPM_SaveKeyContext_rsp */
/* (3984) */ BC_RECORD,
/* (3985) */ 2,
/* Field: keyContextSize */
/* (3986) */ BC_FIELD_KIND_NORMAL,
/* (3987) */ OFFSETOF_TWO_BYTES(keyContextSize, TPM_SaveKeyContext_rsp),
/* (3989) */ BC_INT32,
/* Variable-length field: keyContextBlob */
/* (3990) */ BC_FIELD_KIND_VARIABLE,
/* (3991) */ OFFSETOF_TWO_BYTES(keyContextBlob, TPM_SaveKeyContext_rsp),
/* (3993) */ 0,
/* (3994) */ BC_INT8,
/* Record: TPM_LoadKeyContext_rqu */
/* (3995) */ BC_RECORD,
/* (3996) */ 2,
/* Field: keyContextSize */
/* (3997) */ BC_FIELD_KIND_NORMAL,
/* (3998) */ OFFSETOF_TWO_BYTES(keyContextSize, TPM_LoadKeyContext_rqu),
/* (4000) */ BC_INT32,
/* Variable-length field: keyContextBlob */
/* (4001) */ BC_FIELD_KIND_VARIABLE,
/* (4002) */ OFFSETOF_TWO_BYTES(keyContextBlob, TPM_LoadKeyContext_rqu),
/* (4004) */ 0,
/* (4005) */ BC_INT8,
/* Record: TPM_LoadKeyContext_rsp */
/* (4006) */ BC_RECORD,
/* (4007) */ 1,
/* Field: keyHandle */
/* (4008) */ BC_FIELD_KIND_NORMAL,
/* (4009) */ OFFSETOF_TWO_BYTES(keyHandle, TPM_LoadKeyContext_rsp),
/* (4011) */ BC_INT32,
/* Record: TPM_SaveAuthContext_rqu */
/* (4012) */ BC_RECORD,
/* (4013) */ 1,
/* Field: authHandle */
/* (4014) */ BC_FIELD_KIND_NORMAL,
/* (4015) */ OFFSETOF_TWO_BYTES(authHandle, TPM_SaveAuthContext_rqu),
/* (4017) */ BC_INT32,
/* Record: TPM_SaveAuthContext_rsp */
/* (4018) */ BC_RECORD,
/* (4019) */ 2,
/* Field: authContextSize */
/* (4020) */ BC_FIELD_KIND_NORMAL,
/* (4021) */ OFFSETOF_TWO_BYTES(authContextSize, TPM_SaveAuthContext_rsp),
/* (4023) */ BC_INT32,
/* Variable-length field: authContextBlob */
/* (4024) */ BC_FIELD_KIND_VARIABLE,
/* (4025) */ OFFSETOF_TWO_BYTES(authContextBlob, TPM_SaveAuthContext_rsp),
/* (4027) */ 0,
/* (4028) */ BC_INT8,
/* Record: TPM_LoadAuthContext_rqu */
/* (4029) */ BC_RECORD,
/* (4030) */ 2,
/* Field: authContextSize */
/* (4031) */ BC_FIELD_KIND_NORMAL,
/* (4032) */ OFFSETOF_TWO_BYTES(authContextSize, TPM_LoadAuthContext_rqu),
/* (4034) */ BC_INT32,
/* Variable-length field: authContextBlob */
/* (4035) */ BC_FIELD_KIND_VARIABLE,
/* (4036) */ OFFSETOF_TWO_BYTES(authContextBlob, TPM_LoadAuthContext_rqu),
/* (4038) */ 0,
/* (4039) */ BC_INT8,
/* Record: TPM_LoadAuthContext_rsp */
/* (4040) */ BC_RECORD,
/* (4041) */ 1,
/* Field: authHandle */
/* (4042) */ BC_FIELD_KIND_NORMAL,
/* (4043) */ OFFSETOF_TWO_BYTES(authHandle, TPM_LoadAuthContext_rsp),
/* (4045) */ BC_INT32,
/* Record: TPM_DirWriteAuth_rqu */
/* (4046) */ BC_RECORD,
/* (4047) */ 2,
/* Field: dirIndex */
/* (4048) */ BC_FIELD_KIND_NORMAL,
/* (4049) */ OFFSETOF_TWO_BYTES(dirIndex, TPM_DirWriteAuth_rqu),
/* (4051) */ BC_INT32,
/* Field: newContents */
/* (4052) */ BC_FIELD_KIND_NORMAL,
/* (4053) */ OFFSETOF_TWO_BYTES(newContents, TPM_DirWriteAuth_rqu),
/* (4055) */ BC_REF,
/* (4056) varint: 36 */ 36,
/* Record: TPM_DirRead_rqu */
/* (4057) */ BC_RECORD,
/* (4058) */ 1,
/* Field: dirIndex */
/* (4059) */ BC_FIELD_KIND_NORMAL,
/* (4060) */ OFFSETOF_TWO_BYTES(dirIndex, TPM_DirRead_rqu),
/* (4062) */ BC_INT32,
/* Record: TPM_DirRead_rsp */
/* (4063) */ BC_RECORD,
/* (4064) */ 1,
/* Field: dirContents */
/* (4065) */ BC_FIELD_KIND_NORMAL,
/* (4066) */ OFFSETOF_TWO_BYTES(dirContents, TPM_DirRead_rsp),
/* (4068) */ BC_REF,
/* (4069) varint: 36 */ 36,
/* Record: TPM_ChangeAuthAsymStart_rqu */
/* (4070) */ BC_RECORD,
/* (4071) */ 3,
/* Field: idHandle */
/* (4072) */ BC_FIELD_KIND_NORMAL,
/* (4073) */ OFFSETOF_TWO_BYTES(idHandle, TPM_ChangeAuthAsymStart_rqu),
/* (4075) */ BC_INT32,
/* Field: antiReplay */
/* (4076) */ BC_FIELD_KIND_NORMAL,
/* (4077) */ OFFSETOF_TWO_BYTES(antiReplay, TPM_ChangeAuthAsymStart_rqu),
/* (4079) */ BC_REF,
/* (4080) varint: 42 */ 42,
/* Field: tempKey */
/* (4081) */ BC_FIELD_KIND_NORMAL,
/* (4082) */ OFFSETOF_TWO_BYTES(tempKey, TPM_ChangeAuthAsymStart_rqu),
/* (4084) */ BC_REF,
/* (4085) varint: 552 */ 132, 40,
/* Record: TPM_ChangeAuthAsymStart_rsp */
/* (4087) */ BC_RECORD,
/* (4088) */ 5,
/* Field: certifyInfo */
/* (4089) */ BC_FIELD_KIND_NORMAL,
/* (4090) */ OFFSETOF_TWO_BYTES(certifyInfo, TPM_ChangeAuthAsymStart_rsp),
/* (4092) */ BC_REF,
/* (4093) varint: 819 */ 134, 51,
/* Field: sigSize */
/* (4095) */ BC_FIELD_KIND_NORMAL,
/* (4096) */ OFFSETOF_TWO_BYTES(sigSize, TPM_ChangeAuthAsymStart_rsp),
/* (4098) */ BC_INT32,
/* Variable-length field: sig */
/* (4099) */ BC_FIELD_KIND_VARIABLE,
/* (4100) */ OFFSETOF_TWO_BYTES(sig, TPM_ChangeAuthAsymStart_rsp),
/* (4102) */ 1,
/* (4103) */ BC_INT8,
/* Field: ephHandle */
/* (4104) */ BC_FIELD_KIND_NORMAL,
/* (4105) */ OFFSETOF_TWO_BYTES(ephHandle, TPM_ChangeAuthAsymStart_rsp),
/* (4107) */ BC_INT32,
/* Field: tempKey */
/* (4108) */ BC_FIELD_KIND_NORMAL,
/* (4109) */ OFFSETOF_TWO_BYTES(tempKey, TPM_ChangeAuthAsymStart_rsp),
/* (4111) */ BC_REF,
/* (4112) varint: 676 */ 133, 36,
/* Record: TPM_ChangeAuthAsymFinish_rqu */
/* (4114) */ BC_RECORD,
/* (4115) */ 8,
/* Field: parentHandle */
/* (4116) */ BC_FIELD_KIND_NORMAL,
/* (4117) */ OFFSETOF_TWO_BYTES(parentHandle, TPM_ChangeAuthAsymFinish_rqu),
/* (4119) */ BC_INT32,
/* Field: ephHandle */
/* (4120) */ BC_FIELD_KIND_NORMAL,
/* (4121) */ OFFSETOF_TWO_BYTES(ephHandle, TPM_ChangeAuthAsymFinish_rqu),
/* (4123) */ BC_INT32,
/* Field: entityType */
/* (4124) */ BC_FIELD_KIND_NORMAL,
/* (4125) */ OFFSETOF_TWO_BYTES(entityType, TPM_ChangeAuthAsymFinish_rqu),
/* (4127) */ BC_INT16,
/* Field: newAuthLink */
/* (4128) */ BC_FIELD_KIND_NORMAL,
/* (4129) */ OFFSETOF_TWO_BYTES(newAuthLink, TPM_ChangeAuthAsymFinish_rqu),
/* (4131) */ BC_REF,
/* (4132) varint: 36 */ 36,
/* Field: newAuthSize */
/* (4133) */ BC_FIELD_KIND_NORMAL,
/* (4134) */ OFFSETOF_TWO_BYTES(newAuthSize, TPM_ChangeAuthAsymFinish_rqu),
/* (4136) */ BC_INT32,
/* Variable-length field: encNewAuth */
/* (4137) */ BC_FIELD_KIND_VARIABLE,
/* (4138) */ OFFSETOF_TWO_BYTES(encNewAuth, TPM_ChangeAuthAsymFinish_rqu),
/* (4140) */ 4,
/* (4141) */ BC_INT8,
/* Field: encDataSize */
/* (4142) */ BC_FIELD_KIND_NORMAL,
/* (4143) */ OFFSETOF_TWO_BYTES(encDataSize, TPM_ChangeAuthAsymFinish_rqu),
/* (4145) */ BC_INT32,
/* Variable-length field: encData */
/* (4146) */ BC_FIELD_KIND_VARIABLE,
/* (4147) */ OFFSETOF_TWO_BYTES(encData, TPM_ChangeAuthAsymFinish_rqu),
/* (4149) */ 6,
/* (4150) */ BC_INT8,
/* Record: TPM_ChangeAuthAsymFinish_rsp */
/* (4151) */ BC_RECORD,
/* (4152) */ 4,
/* Field: outDataSize */
/* (4153) */ BC_FIELD_KIND_NORMAL,
/* (4154) */ OFFSETOF_TWO_BYTES(outDataSize, TPM_ChangeAuthAsymFinish_rsp),
/* (4156) */ BC_INT32,
/* Variable-length field: outData */
/* (4157) */ BC_FIELD_KIND_VARIABLE,
/* (4158) */ OFFSETOF_TWO_BYTES(outData, TPM_ChangeAuthAsymFinish_rsp),
/* (4160) */ 0,
/* (4161) */ BC_INT8,
/* Field: saltNonce */
/* (4162) */ BC_FIELD_KIND_NORMAL,
/* (4163) */ OFFSETOF_TWO_BYTES(saltNonce, TPM_ChangeAuthAsymFinish_rsp),
/* (4165) */ BC_REF,
/* (4166) varint: 42 */ 42,
/* Field: changeProof */
/* (4167) */ BC_FIELD_KIND_NORMAL,
/* (4168) */ OFFSETOF_TWO_BYTES(changeProof, TPM_ChangeAuthAsymFinish_rsp),
/* (4170) */ BC_REF,
/* (4171) varint: 36 */ 36,
/* Record: TPM_OwnerReadPubek_rsp */
/* (4172) */ BC_RECORD,
/* (4173) */ 1,
/* Field: pubEndorsementKey */
/* (4174) */ BC_FIELD_KIND_NORMAL,
/* (4175) */ OFFSETOF_TWO_BYTES(pubEndorsementKey, TPM_OwnerReadPubek_rsp),
/* (4177) */ BC_REF,
/* (4178) varint: 624 */ 132, 112,
/* Record: TPM_LoadKey_rqu */
/* (4180) */ BC_RECORD,
/* (4181) */ 2,
/* Field: parentHandle */
/* (4182) */ BC_FIELD_KIND_NORMAL,
/* (4183) */ OFFSETOF_TWO_BYTES(parentHandle, TPM_LoadKey_rqu),
/* (4185) */ BC_INT32,
/* Field: inKey */
/* (4186) */ BC_FIELD_KIND_NORMAL,
/* (4187) */ OFFSETOF_TWO_BYTES(inKey, TPM_LoadKey_rqu),
/* (4189) */ BC_REF,
/* (4190) varint: 676 */ 133, 36,
/* Record: TPM_LoadKey_rsp */
/* (4192) */ BC_RECORD,
/* (4193) */ 1,
/* Field: inkeyHandle */
/* (4194) */ BC_FIELD_KIND_NORMAL,
/* (4195) */ OFFSETOF_TWO_BYTES(inkeyHandle, TPM_LoadKey_rsp),
/* (4197) */ BC_INT32,
/* Record: TPM_GetOrdinalAuditStatus_rqu */
/* (4198) */ BC_RECORD,
/* (4199) */ 1,
/* Field: ordinalToQuery */
/* (4200) */ BC_FIELD_KIND_NORMAL,
/* (4201) */ OFFSETOF_TWO_BYTES(ordinalToQuery, TPM_GetOrdinalAuditStatus_rqu),
/* (4203) */ BC_INT32,
/* Record: TPM_GetOrdinalAuditStatus_rsp */
/* (4204) */ BC_RECORD,
/* (4205) */ 1,
/* Field: State */
/* (4206) */ BC_FIELD_KIND_NORMAL,
/* (4207) */ OFFSETOF_TWO_BYTES(State, TPM_GetOrdinalAuditStatus_rsp),
/* (4209) */ BC_INT8,
};
