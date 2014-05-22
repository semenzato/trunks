// Copyright (c) 2013 The Chromium OS Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "resource_manager.h"

#include <string>

#include "result.h"

namespace trunks {

ResourceManager::ResourceManager() {}

ResourceManager::~ResourceManager() {
  FreeMemory(NULL);
}

BYTE* ResourceManager::AllocateMemory(UINT32 size) {
  BYTE* ptr = new BYTE[size];
  allocated_memory_[ptr] = size;
  return ptr;
}

TSS_RESULT ResourceManager::FreeMemory(BYTE* memory) {
  // If memory is NULL, free all the memories.
  if (memory == NULL) {
    std::map<BYTE*, UINT32>::iterator it;
    for (it = allocated_memory_.begin();
         it != allocated_memory_.end();
         it++) {
      BYTE* ptr = it->first;
      delete[] ptr;
    }
    allocated_memory_.clear();
    return TSS_SUCCESS;
  }
  // Else free the memory, iff allocated and belonging to this context.
  if (allocated_memory_.count(memory) == 1) {
    allocated_memory_.erase(memory);
    delete[] memory;
    return TSS_SUCCESS;
  }
  return TSS_E_INVALID_RESOURCE;
}

}  // namespace trunks
