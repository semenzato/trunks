// Copyright (c) 2013 The Chromium OS Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef TRUNKS_TSS_CONTEXT_MANAGER_H_
#define TRUNKS_TSS_CONTEXT_MANAGER_H_

#include <map>
#include <tr1/memory>
#include <base/basictypes.h>

#include "tss/tss_typedef.h"
#include "tss/tss_error.h"

namespace trunks {

// Manages generic contexts in Trunks.
template <class T>
class ContextManager {
 public:
  ContextManager() : last_handle_(0) {}
  virtual ~ContextManager() {
    CloseAllContexts();
  }

  // Creates a new context with the corresponding handle.
  // Returns TSS_SUCCESS on successful Context object creation, handle
  //  assignment and writing the handle to |context_handle|.
  virtual TSS_RESULT OpenContext(TSS_HCONTEXT* context_handle) {
    last_handle_++;
    T* context = new T(last_handle_);
    std::tr1::shared_ptr<T> context_ptr(context);
    contexts_[last_handle_] = context_ptr;
    *context_handle = last_handle_;
    return TSS_SUCCESS;
  }

  // Closes a context referenced by the handle (if possible) and releases all
  //  the resources assigned to that context.
  // Returns TSS_SUCCESS if |context_handle| is a valid context handle and the
  //  corresponding TspContext is deleted.
  // Returns TSS_E_INVALID_HANDLE if |context_handle| is not a valid context
  //  handle.
  virtual TSS_RESULT CloseContext(TSS_HCONTEXT context_handle) {
      std::tr1::shared_ptr<T> context = GetContext(context_handle);
      if (!context)
        return TSS_E_INVALID_HANDLE;
      contexts_.erase(context_handle);
      return TSS_SUCCESS;
  }

  // Closes all contexts currently maintained by the context manager.
  virtual void CloseAllContexts() {
    contexts_.clear();
  }

  // Gets the pointer for a context object given the context handle.
  // Returns a valid shared_ptr to the Context object if |context_handle|
  //  is valid.
  // Returns a blank shared_ptr if |context_handle| is invalid.
  virtual std::tr1::shared_ptr<T> GetContext(TSS_HCONTEXT context_handle) {
    if (contexts_.count(context_handle) == 1)
      return contexts_[context_handle];
    return std::tr1::shared_ptr<T>();
  }

  // Gets the total count of contexts currently maintained by this context
  //  manager.
  virtual UINT32 GetNumContexts() {
    return contexts_.size();
  }

 private:
  // The counter for context handles.
  TSS_HCONTEXT last_handle_;

  // A map that maps all context handles to context objects.
  std::map<TSS_HCONTEXT, std::tr1::shared_ptr<T> > contexts_;

  DISALLOW_COPY_AND_ASSIGN(ContextManager);
};

}  // namespace trunks

#endif  // TRUNKS_TSS_CONTEXT_MANAGER_H_
