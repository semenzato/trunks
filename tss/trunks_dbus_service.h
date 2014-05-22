// Copyright (c) 2013 The Chromium OS Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef TRUNKS_DBUS_SERVICE_H_
#define TRUNKS_DBUS_SERVICE_H_

#include <base/basictypes.h>

#include "trunks_dbus_adaptor_generated.h"

namespace trunks {

// TrunksDbusService is the main dbus service for trunks.  It implements the
// dbus-c++ generated adaptor interface.
class TrunksDbusService : public org::chromium::Trunks_adaptor,
                          public DBus::ObjectAdaptor {
 public:
  TrunksDbusService(DBus::Connection& connection, const DBus::Path& path);
  virtual ~TrunksDbusService();

  virtual void Ping(::DBus::Error &error);

 private:
  DISALLOW_COPY_AND_ASSIGN(TrunksDbusService);
};

}  // namespace trunks

#endif  // TRUNKS_DBUS_SERVICE_H_
