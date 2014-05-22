/* Copyright (c) 2011 The Chromium OS Authors. All rights reserved.
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 *
 * Trunks internal function and type definitions.
 */

#ifndef TRUNKS_TRUNKS_INTERNAL_H_
#define TRUNKS_TRUNKS_INTERNAL_H_

#include <stdint.h>
#include "g_tpm_structures.h"
#include "ttl_marshal.h"
#include "ttl_authorization.h"

/* The number of fields of a TPM structure must fit in a byte. */
#define TTL_RECORD_FIELDS_MAX 255

#define TTLDEBUG(args) do { } while (0)
#define assert(condition) do { if (!(condition)) { \
    TtlError("assertion " # condition " failed");  \
    } } while (0)

#define RETURN_ON_FAILURE(tpm_call) do {        \
  uint32_t _result_ = tpm_call;                 \
  if (_result_ != TPM_SUCCESS) return _result_; \
} while (0)

/* Bytecodes.  See ttl_interpret.c for bytecode definitions. */

enum {
  /* type descriptors */
  BC_INT64 = 8,  /* don't start at 0 */
  BC_INT32 = 9,
  BC_INT16 = 10,
  BC_INT8 = 11,
  BC_RECORD = 12,
  BC_ARRAY = 13,
  BC_REF = 14,

  /* field descriptors */
  BC_FIELD_KIND_NORMAL = 15,
  BC_FIELD_KIND_VARIABLE = 16,
  BC_ARRAYFIELD = 17,
};

/* Variable-length integers for bytecodes.  The MSB is a continuation bit, the
 * other 7 bits are a hecataicosaoctal digit (pardon my Greek).  When the MSB
 * is 1, there are other less significant bytes following this one.  E.g.: {
 * 0x81, 0x02 } = 128 + 2 = 130 */

#define BC_VLINT_CONTINUED 0x80
#define BC_VLINT_MASK      0x7f

/* Returns the offset of FIELD in STRUCT. */
#define OFFSETOF(field, struct) \
  (((uint8_t *) &((struct *) 0)->field) - (uint8_t *) 0)

/* Expands X as two bytes (MSB first) for use in a byte array initializer, with
 * 0 <= X <= 65535 (not checked) */
#define TWO_BYTES_INT(x) x / 256, x % 256

/* Produces two bytes containing the offset of FIELD in STRUCT for use in a
 * byte array initializer (MSB first) */
#define OFFSETOF_TWO_BYTES(field, struct) TWO_BYTES_INT(OFFSETOF(field, struct))

/* Array containing all byte codes. */
extern uint8_t StructureByteCodes[];

/* Outputs an error message and quits. */
void TtlError(const char* format, ...);

/* Opens the TPM device.  Returns TPM_SUCCESS or an error code. */
uint32_t TtlOpenDevice(void);

/* Sends a request datagram to the TPM and receives a response. */
uint32_t TtlExecute(uint8_t* buffer, const uint32_t cmd_len,
                    const uint32_t buf_len, uint32_t* read_bytes);

/* Executes a TPM command */
uint32_t TtlRunCommand(uint32_t command_ordinal,
                       int rqu_index, int rsp_index,
                       void* rqu_struct, void* rsp_struct,
                       void* auth1, void* auth2,
                       uint8_t* buffer, const uint32_t buffer_size);


/* Returns a bytecode address given a bytecode index. */
static inline uint8_t* ByteCodeIndexToAddress(int i) {
  return &StructureByteCodes[i];
}

/* Marshals a TPM structure.  CODEP is a bytecode passed by reference and advanced to the end of the code for the structure.  CURSOR is a pointer to the outgoing buffer, also advanced after marshalling the data.  FROM is a pointer */
void TtlMarshal(uint8_t** codep, uint8_t** cursor, void* from);

/* Unmarshals a TPM structure. */
void TtlUnmarshal(uint8_t** codep, uint8_t** cursor, void* to);

/* Computes the size of a TPM structure. */
int TtlSizeCalc(uint8_t** codep, void* data);


#ifdef TESTING
extern uint8_t TtlTestCommandBuffer[];
#endif

#endif  /* TRUNKS_TRUNKS_INTERNAL_H_ */
