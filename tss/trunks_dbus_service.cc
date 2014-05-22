// Copyright (c) 2013 The Chromium OS Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "trunks_dbus_service.h"

#include <base/logging.h>

namespace trunks {

TrunksDbusService::TrunksDbusService(DBus::Connection& connection,
                                     const DBus::Path& path)
  : DBus::ObjectAdaptor(connection, path) {
}

TrunksDbusService::~TrunksDbusService() {
}

void TrunksDbusService::Ping(::DBus::Error &error) {
  LOG(INFO) << "Trunks: Ping";
}

}  // namespace trunks
