// Copyright (c) 2013 The Chromium OS Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef TRUNKS_TSS_RESOURCE_MANAGER_H_
#define TRUNKS_TSS_RESOURCE_MANAGER_H_

#include <map>

#include <base/basictypes.h>

#include "tss/tss_error.h"
#include "tss/tss_typedef.h"

namespace trunks {

// Defines a resource manager for contexts for Trunks.
class ResourceManager {
 public:
  ResourceManager();
  virtual ~ResourceManager();

  // Allocates memory and associates it to this context.
  // Returns a non-null pointer to a byte array of size |size|.
  virtual BYTE* AllocateMemory(UINT32 size);

  // Frees memory associated with this context.
  // If |memory| is NULL:
  //  - Returns TSS_SUCCESS upon freeing of all memory associated with this
  //     context.
  // Else:
  //  - Returns TSS_SUCCESS if |memory| is a valid memory handle, and is
  //     associated with this context.
  //  - Returns TSS_E_INVALID_RESOURCE if |memory| is not a valid memory
  //     handle.
  virtual TSS_RESULT FreeMemory(BYTE* memory);

 private:
  // A map that keeps track of all the memory allocations in this context,
  // along with their sizes.
  std::map<BYTE*, UINT32> allocated_memory_;

  DISALLOW_COPY_AND_ASSIGN(ResourceManager);
};

}  // namespace trunks

#endif  // TRUNKS_TSS_RESOURCE_MANAGER_H_
