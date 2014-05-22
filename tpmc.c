/* Copyright (c) 2011 The Chromium OS Authors. All rights reserved.
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 *
 * TPM command utility.  Runs simple TPM commands.  Mostly useful when physical
 * presence has not been locked.
 *
 * The exit code is 0 for success, the TPM error code for TPM errors, and 255
 * for other errors.
 */

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>

#include "g_tpm_commands.h"
#include "trunks.h"
#include "trunks_tpm.h"

#define OTHER_ERROR 255

/* A command record contains a command long and short name, the description of
 * the command (printed by "tpmc help") and a pointer to the function that
 * implements the command.
 */
typedef struct command_record {
  const char* name;
  const char* abbr;
  const char* description;
  uint32_t (*handler)(void);
} command_record;

/* Set in main, consumed by handler functions below.  We use global variables
 * so we can also choose to call Ttl*() functions directly; they don't take
 * argv/argc.
 */
int nargs;
char** args;

/* Converts a string in the form 0x[0-9a-f]+ to a 32-bit value.  Returns 0 for
 * success, non-zero for failure.
 */
int HexStringToUint32(const char* string, uint32_t* value) {
  char tail[1];
  /* strtoul is not as good because it silently ignores trailing garbage */
  char* format = strncmp(string, "0x", 2) ? "%8x%1s" : "0x%8x%1s";
  int n = sscanf(string, format, value, tail);
  return n != 1;
}

/* Converts a string in the form [0-9a-f]+ to an 8-bit value.  Returns 0 for
 * success, non-zero for failure.
 */
int HexStringToUint8(const char* string, uint8_t* value) {
  char* end;
  uint32_t large_value = strtoul(string, &end, 16);
  if (*end != '\0' || large_value > 0xff) {
    return 1;
  }
  *value = large_value;
  return 0;
}

/* TPM error check and reporting.  Returns 0 if |result| is 0 (TPM_SUCCESS).
 * Otherwise looks up a TPM error in the error table and prints the error if
 * found.
 */
uint32_t ErrorCheck(uint32_t result, const char* cmd) {
  if (result != 0) {
    fprintf(stderr, "command \"%s\" failed with code 0x%x\n", cmd, result);
    const ttl_error_info* error_info = TtlGetErrorInfo(result);
    if (error_info != NULL) {
      fprintf(stderr, "%s\n%s\n", error_info->name, error_info->description);
    } else {
      fprintf(stderr, "the TPM error code is unknown to this program\n");
    }
  }
  return result;
}

const struct {
  const char* name;
  uint32_t bit;
} nv_permission_table[] = {
  { "ppwrite",        TPM_NV_PER_PPWRITE      },
  { "ownerwrite",     TPM_NV_PER_OWNERWRITE   },
  { "authwrite",      TPM_NV_PER_AUTHWRITE    },
  { "writeall",       TPM_NV_PER_WRITEALL     },
  { "writedefine",    TPM_NV_PER_WRITEDEFINE  },
  { "write_stclear",  TPM_NV_PER_WRITE_STCLEAR},
  { "globallock",     TPM_NV_PER_GLOBALLOCK   },
  { "ppread",         TPM_NV_PER_PPREAD       },
  { "ownerread",      TPM_NV_PER_OWNERREAD    },
  { "authread",       TPM_NV_PER_AUTHREAD     },
  { "read_stclear",   TPM_NV_PER_READ_STCLEAR },
};

const int n_nv_permissions =
    sizeof(nv_permission_table) / sizeof(nv_permission_table[0]);

/* Parses a set of permissions.  This is either the string "none" or a set of
 * permission identifiers separated by commas (for instance: "ppread,ppwrite").
 * Returns the bitwise union of the permission bits of those identifiers, or 0
 * for "none".
 */
static uint32_t ParseNvPermissions(const char* arg) {
  int i;
  char name[256];
  uint32_t perms = 0;
  const char* p = arg;

  if (strlen(arg) + 1 >= sizeof(name)) {
    fprintf(stderr, "NV space permissions string is too long\n");
    goto bad_perms;
  }

  for (;;) {
    char comma = '\0';
    int count;
    int found;

    name[0] = '\0';
    sscanf(p, "%[^,]%c%n", name, &comma, &count);

    if (strcmp(name, "none") == 0) {
      if (comma == ',' || perms != 0) {
        goto bad_perms;
      }
      return 0;
    }

    found = 0;
    for (i = 0; i < n_nv_permissions; i++) {
      if (strcmp(nv_permission_table[i].name, name) == 0) {
        perms |= nv_permission_table[i].bit;
        found = 1;
      }
    }
    if (!found) {
      goto bad_perms;
    }

    if (comma == ',') {
      p += count;
    } else {
      break;
    }
  }

  return perms;

 bad_perms:
  fprintf(stderr, "invalid NV space permissions: %s\n", arg);
  fprintf(stderr, "expecting \"none\" or one or more permission types "
          "separated by commas\nvalid types are:\n");
  for (i = 0; i < n_nv_permissions; i++) {
    fprintf(stderr, "%s\n", nv_permission_table[i].name);
  }
  exit(OTHER_ERROR);
}

static void PrintNvPermissions(uint32_t permissions) {
  int i;
  int more = 0;

  if (permissions == 0) {
    printf("none");
    return;
  }

  for (i = 0; i < n_nv_permissions; i++) {
    if (nv_permission_table[i].bit & permissions) {
      if (more) {
        printf(",");
      }
      printf("%s", nv_permission_table[i].name);
      more = 1;
    }
    permissions &= ~nv_permission_table[i].bit;
  }

  if (permissions) {
    printf(" + invalid permission bits 0x%x", permissions);
    exit(OTHER_ERROR);
  }
}


/* Handler functions.  These wouldn't exist if C had closures.
 */
static uint32_t HandlerGetFlags(void) {
  uint8_t disabled;
  uint8_t deactivated;
  uint8_t nvlocked;
  uint32_t result = TtlGetFlags(&disabled, &deactivated, &nvlocked);
  if (result == 0) {
    printf("disabled: %d\ndeactivated: %d\nnvlocked: %d\n",
           disabled, deactivated, nvlocked);
  }
  return result;
}

static uint32_t HandlerActivate(void) {
  return TtlSetDeactivated(0);
}

static uint32_t HandlerDeactivate(void) {
  return TtlSetDeactivated(1);
}

static uint32_t HandlerDefineSpace(void) {
  uint32_t index, size, perm;
  uint8_t own_pwd_hash[TPM_SHA1_160_HASH_LEN];
  if (nargs != 5 && nargs != 6) {
    fprintf(stderr, "usage: tpmc def <index> <size> <perm>"
            " [<owner password>]\n");
    exit(OTHER_ERROR);
  }
  if (HexStringToUint32(args[2], &index) != 0 ||
      HexStringToUint32(args[3], &size) != 0) {
    fprintf(stderr, "<index> and <size> must be 32-bit hex (0x[0-9a-f]+)\n");
    exit(OTHER_ERROR);
  }
  /* The <perm> argument can be either a hex value, or a set of comma-separated
   * permission identifiers. */
  if (HexStringToUint32(args[4], &perm) != 0) {
    perm = ParseNvPermissions(args[4]);
  }
  if (nargs == 6) {
    SHA1((uint8_t*)args[5], strlen(args[5]), own_pwd_hash);
  }
  return TtlDefineSpace(index, perm, size, nargs == 6 ? own_pwd_hash : NULL);
}

static uint32_t HandlerWrite(void) {
  uint32_t index, size;
  uint8_t value[TPM_MAX_COMMAND_LENGTH];
  char** byteargs;
  int i;
  if (nargs < 3) {
    fprintf(stderr, "usage: tpmc write <index> [<byte0> <byte1> ...]\n");
    exit(OTHER_ERROR);
  }
  if (HexStringToUint32(args[2], &index) != 0) {
    fprintf(stderr, "<index> must be 32-bit hex (0x[0-9a-f]+)\n");
    exit(OTHER_ERROR);
  }
  size = nargs - 3;
  if (size > sizeof(value)) {
    fprintf(stderr, "byte array too large\n");
    exit(OTHER_ERROR);
  }

  byteargs = args + 3;
  for (i = 0; i < size; i++) {
    if (HexStringToUint8(byteargs[i], &value[i]) != 0) {
      fprintf(stderr, "invalid byte %s, should be [0-9a-f][0-9a-f]?\n",
              byteargs[i]);
      exit(OTHER_ERROR);
    }
  }

  if (size == 0) {
    if (index == TPM_NV_INDEX_LOCK) {
      fprintf(stderr, "This would set the nvLocked bit. "
              "Use \"tpmc setnv\" instead.\n");
      exit(OTHER_ERROR);
    }
    printf("warning: zero-length write\n");
  } else {
    printf("writing %d byte%s\n", size, size > 1 ? "s" : "");
  }

  return TtlWrite(index, value, size);
}

static uint32_t HandlerRead(void) {
  uint32_t index, size;
  uint8_t value[4096];
  uint32_t result;
  int i;
  if (nargs != 4) {
    fprintf(stderr, "usage: tpmc read <index> <size>\n");
    exit(OTHER_ERROR);
  }
  if (HexStringToUint32(args[2], &index) != 0 ||
      HexStringToUint32(args[3], &size) != 0) {
    fprintf(stderr, "<index> and <size> must be 32-bit hex (0x[0-9a-f]+)\n");
    exit(OTHER_ERROR);
  }
  if (size > sizeof(value)) {
    fprintf(stderr, "size of read (0x%x) is too big\n", size);
    exit(OTHER_ERROR);
  }
  result = TtlRead(index, value, size);
  if (result == 0 && size > 0) {
    for (i = 0; i < size - 1; i++) {
      printf("%x ", value[i]);
    }
    printf("%x\n", value[i]);
  }
  return result;
}

static uint32_t HandlerGetPermissions(void) {
  uint32_t index, permissions, result;
  if (nargs != 3) {
    fprintf(stderr, "usage: tpmc getp <index>\n");
    exit(OTHER_ERROR);
  }
  if (HexStringToUint32(args[2], &index) != 0) {
    fprintf(stderr, "<index> must be 32-bit hex (0x[0-9a-f]+)\n");
    exit(OTHER_ERROR);
  }
  result = TtlGetPermissions(index, &permissions);
  if (result == 0) {
    printf("space 0x%x has permissions 0x%x (", index, permissions);
    PrintNvPermissions(permissions);
    printf(")\n");
  }
  return result;
}

static uint32_t HandlerGetPermanentFlags(void) {
  TPM_PERMANENT_FLAGS pflags;
  uint32_t result = TtlGetPermanentFlags(&pflags);
  if (result == 0) {
#define P(name) printf("%s %d\n", #name, pflags.name)
    P(disable);
    P(ownership);
    P(deactivated);
    P(readPubek);
    P(disableOwnerClear);
    P(allowMaintenance);
    P(physicalPresenceLifetimeLock);
    P(physicalPresenceHWEnable);
    P(physicalPresenceCMDEnable);
    P(CEKPUsed);
    P(TPMpost);
    P(TPMpostLock);
    P(FIPS);
    P(Operator);
    P(enableRevokeEK);
    P(nvLocked);
    P(readSRKPub);
    P(tpmEstablished);
    P(maintenanceDone);
#undef P
  }
  return result;
}

static uint32_t HandlerGetSTClearFlags(void) {
  TPM_STCLEAR_FLAGS vflags;
  uint32_t result = TtlGetSTClearFlags(&vflags);
  if (result == 0) {
#define P(name) printf("%s %d\n", #name, vflags.name)
  P(deactivated);
  P(disableForceClear);
  P(physicalPresence);
  P(physicalPresenceLock);
  P(bGlobalLock);
#undef P
  }
  return result;
}

static uint32_t HandlerTakeOwnership(void) {
  uint8_t owner_pwd_hash[TPM_SHA1_160_HASH_LEN];
  uint8_t srk_pwd_hash[TPM_SHA1_160_HASH_LEN];
  if (nargs != 4) {
    fprintf(stderr, "usage: tpmc own <owner password> <srk password>\n");
    exit(OTHER_ERROR);
  }
  SHA1((const uint8_t*)args[2], strlen(args[2]), owner_pwd_hash);
  SHA1((const uint8_t*)args[3], strlen(args[3]), srk_pwd_hash);
  return TtlTakeOwnership(owner_pwd_hash, srk_pwd_hash);
}

static uint32_t HandlerOwnerClear(void) {
  uint8_t owner_pwd_hash[TPM_SHA1_160_HASH_LEN];
  if (nargs != 3) {
    fprintf(stderr, "usage: tpmc oclear <owner password>\n");
    exit(OTHER_ERROR);
  }
  SHA1((const uint8_t*)args[2], strlen(args[2]), owner_pwd_hash);
  return TtlOwnerClear(owner_pwd_hash);
}

static uint32_t HandlerChangeOwnerPassword(void) {
  uint8_t old_pwd_hash[TPM_SHA1_160_HASH_LEN];
  uint8_t new_pwd_hash[TPM_SHA1_160_HASH_LEN];
  if (nargs != 4) {
    fprintf(stderr, "usage: tpmc chown "
            "<old owner password> <new owner password>\n");
    exit(OTHER_ERROR);
  }
  SHA1((const uint8_t*)args[2], strlen(args[2]), old_pwd_hash);
  SHA1((const uint8_t*)args[3], strlen(args[3]), new_pwd_hash);
  return TtlChangeAuthOwner(TPM_ET_OWNER, old_pwd_hash, new_pwd_hash);
}

static uint32_t HandlerChangeSRKPassword(void) {
  uint8_t old_pwd_hash[TPM_SHA1_160_HASH_LEN];
  uint8_t new_pwd_hash[TPM_SHA1_160_HASH_LEN];
  if (nargs != 4) {
    fprintf(stderr, "usage: tpmc chsrk "
            "<old srk password> <new srk password>\n");
    exit(OTHER_ERROR);
  }
  SHA1((const uint8_t*)args[2], strlen(args[2]), old_pwd_hash);
  SHA1((const uint8_t*)args[3], strlen(args[3]), new_pwd_hash);
  return TtlChangeAuthOwner(TPM_ET_SRK, old_pwd_hash, new_pwd_hash);
}

static uint32_t HandlerGetTestResult(void) {
  uint8_t test_result[TPM_MAX_COMMAND_LENGTH];
  uint32_t test_result_length;
  uint32_t result;
  int i;

  if (nargs != 2) {
    fprintf(stderr, "usage: tpmc gettest\n");
    exit(OTHER_ERROR);
  }

  result = TtlGetTestResult(&test_result_length, test_result);
  if (result != 0) {
    return result;
  } else {
    for (i = 0; i < test_result_length; i++) {
      printf("%02x", test_result[i]);
    }
    printf("\n");
  }
  return 0;
}

/* Table of TPM commands.
 */
command_record command_table[] = {
  { "activate", "act", "activate the TPM (needs PP, maybe reboot)",
    HandlerActivate },
  { "assertphysicalpresence", "ppon", "assert Physical Presence",
    TtlAssertPhysicalPresence },
  { "changeowner", "chown", "change owner password",
    HandlerChangeOwnerPassword },
  { "changesrk", "chsrk", "change srk password", HandlerChangeSRKPassword },
  { "clear", "clr", "clear the TPM owner (needs PP)", TtlForceClear },
  { "continueselftest", "ctest", "issue a ContinueSelfTest command",
    TtlContinueSelfTest },
  { "deactivate", "deact", "deactivate the TPM (needs PP, maybe reboot)",
    HandlerDeactivate },
  { "definespace", "def", "define a space (def <index> <size> <perm>)",
    HandlerDefineSpace },
  { "disable", "dis", "disable the TPM (needs PP)", TtlClearEnable },
  { "enable", "ena", "enable the TPM (needs PP)", TtlSetEnable },
  { "getflags", "getf", "read and print the value of selected flags",
    HandlerGetFlags },
  { "getpermanentflags", "getpf", "print all permanent flags",
    HandlerGetPermanentFlags },
  { "getpermissions", "getp", "print space permissions (getp <index>)",
    HandlerGetPermissions },
  { "getstclearflags", "getvf", "print all volatile (ST_CLEAR) flags",
    HandlerGetSTClearFlags },
  { "lockphysicalpresence", "pplock", "lock PP to current value until reboot",
    TtlLockPhysicalPresence },
  { "ownerclear", "oclear", "clear the TPM owner (oclear <password>)",
    HandlerOwnerClear },
  { "physicalpresencecmdenable", "ppcmd", "turn on software PP",
    TtlPhysicalPresenceCMDEnable },
  { "read", "read", "read from a space (read <index> <size>)",
    HandlerRead },
  { "resume", "res", "execute TPM_Startup(ST_STATE)", TtlResume },
  { "savestate", "save", "execute TPM_SaveState", TtlSaveState },
  { "selftestfull", "test", "issue a SelfTestFull command", TtlSelfTestFull },
  { "setbgloballock", "block", "set the bGlobalLock until reboot",
    TtlSetGlobalLock },
  { "setnvlocked", "setnv", "set the nvLocked flag IRREVERSIBLY",
    TtlSetNvLocked },
  { "startup", "sta", "issue a Startup command", TtlStartup },
  { "takeownership", "own", "take ownership of the TPM", HandlerTakeOwnership },
  { "write", "write", "write to a space (write <index> [<byte0> <byte1> ...])",
    HandlerWrite },
  { "gettestresult", "gettest", "print self test result (in hex)",
    HandlerGetTestResult },
};

static int n_commands = sizeof(command_table) / sizeof(command_table[0]);

#ifdef TESTING
void RunTest(void) {
  uint8_t bytes[] = { 0, TPM_TAG_RQU_COMMAND,
                      0, 0, 0, 12,
                      0, 0, 0, TPM_ORD_Startup,
                      0, TPM_ST_CLEAR };
  printf("Running Trunks test\n");
  (void) TtlStartup();
  if (memcmp(TtlTestCommandBuffer, bytes, sizeof(bytes)) != 0) {
    printf("Trunks test failed\n");
    exit(1);
  } else {
    printf("Trunks test succeeded\n");
    exit(0);
  }
}
#endif

int main_(int argc, char* argv[]) {
  if (argc < 2) {
    fprintf(stderr, "usage: %s <TPM command> [args]\n   or: %s help\n",
            argv[0], argv[0]);
    return OTHER_ERROR;
  } else {
    command_record* c;
    const char* cmd = argv[1];
    nargs = argc;
    args = argv;

    if (strcmp(cmd, "help") == 0) {
      printf("%26s %7s  %s\n\n", "command", "abbr.", "description");
      for (c = command_table; c < command_table + n_commands; c++) {
        printf("%26s %7s  %s\n", c->name, c->abbr, c->description);
      }
      return 0;
    }

    TtlInit();

    for (c = command_table; c < command_table + n_commands; c++) {
      if (strcmp(cmd, c->name) == 0 || strcmp(cmd, c->abbr) == 0) {
        return ErrorCheck(c->handler(), cmd);
      }
    }

    /* No command matched. */
    fprintf(stderr, "%s: unknown command: %s\n", argv[0], cmd);
    return OTHER_ERROR;
  }
}

int main(int argc, char* argv[]) {
#ifdef TESTING
    RunTest();
    return 0;
#else
    return main_(argc, argv);
#endif
}
