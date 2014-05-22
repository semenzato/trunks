/* Copyright (c) 2011 The Chromium OS Authors. All rights reserved.
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 *
 * Linux-specific access to the TPM.
 */

#include <errno.h>
#include <fcntl.h>
#include <stdarg.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#include "trunks_internal.h"

#define TPM_DEVICE_PATH "/dev/tpm0"

/* The file descriptor for the TPM device.
 */
static int tpm_fd = -1;

void TtlError(const char *format, ...) {
  va_list ap;
  va_start(ap, format);
  fprintf(stderr, "ERROR: ");
  vfprintf(stderr, format, ap);
  va_end(ap);
  fprintf(stderr, "\n");
  exit(1);
}


#ifdef TESTING
uint8_t TtlTestCommandBuffer[4096];
#endif


/* Executes a command on the TPM.
 */
uint32_t TtlExecute(uint8_t* buffer, uint32_t cmd_len, uint32_t buf_len,
                    uint32_t* read_bytes) {
#ifdef TESTING
  memcpy(TtlTestCommandBuffer, buffer, cmd_len);
#else
  if (cmd_len > TPM_MAX_COMMAND_LENGTH) {
    TtlError("invalid command length %d for command 0x%x", cmd_len, buffer[9]);
  } else if (tpm_fd < 0) {
    TtlError("the TPM device was not opened");
  } else {
    int n = write(tpm_fd, buffer, cmd_len);
    if (n != cmd_len) {
      TtlError("write failure to TPM device: %s", strerror(errno));
    }
    n = read(tpm_fd, buffer, buf_len);
    if (n == 0) {
      TtlError("null read from TPM device");
    } else if (n < 0) {
      TtlError("read failure from TPM device: %s", strerror(errno));
    }
    *read_bytes = n;
  }
#endif
  return TPM_SUCCESS;
}


uint32_t TtlCloseDevice(void) {
  if (tpm_fd != -1) {
    close(tpm_fd);
    tpm_fd = -1;
  }
  return 0;
}


uint32_t TtlOpenDevice(void) {
  char* device_path;

  if (tpm_fd >= 0)
    return 0;  /* Already open */

  device_path = getenv("TPM_DEVICE_PATH");
  if (device_path == NULL) {
    device_path = TPM_DEVICE_PATH;
  }

  tpm_fd = open(device_path, O_RDWR);
  if (tpm_fd < 0) {
    TtlError("TPM: Cannot open TPM device %s: %s",
             device_path, strerror(errno));
  }

  return 0;
}
