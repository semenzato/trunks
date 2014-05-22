// Copyright (c) 2013 The Chromium OS Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef TRUNKS_DBUS_CLIENT_H_
#define TRUNKS_DBUS_CLIENT_H_

#include <base/basictypes.h>
#include <base/memory/scoped_ptr.h>

namespace trunks {

class Proxy;

// TrunksDbusClient is a client for the trunks dbus service.  It forwards calls
// to a dbus-c++ generated proxy.
class TrunksDbusClient {
 public:
  TrunksDbusClient();
  virtual ~TrunksDbusClient();

  virtual bool Connect();
  virtual bool Ping();

 private:
  bool WaitForService();

  scoped_ptr<Proxy> proxy_;

  DISALLOW_COPY_AND_ASSIGN(TrunksDbusClient);
};

}  // namespace trunks

#endif  // TRUNKS_DBUS_CLIENT_H_
