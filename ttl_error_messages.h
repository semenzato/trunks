/* Copyright (c) 2011 The Chromium OS Authors. All rights reserved.
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef TRUNKS_TTL_ERROR_MESSAGES_H
#define TRUNKS_TTL_ERROR_MESSAGES_H

#include <stdint.h>

typedef struct ttl_error_info {
  const char* name;
  uint32_t code;
  const char* description;
} ttl_error_info;

const ttl_error_info* TtlGetErrorInfo(uint32_t error_code);

#endif  /* TRUNKS_TTL_ERROR_MESSAGES_H */
