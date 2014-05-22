// Copyright (c) 2013 The Chromium OS Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "trunks_dbus_client.h"

#include <string>

#include <base/logging.h>

#include "trunks_dbus_constants.h"
#include "trunks_dbus_proxy_generated.h"

namespace trunks {

// This class provides the link to the dbus-c++ generated proxy.
class Proxy : public org::chromium::Trunks_proxy,
              public DBus::ObjectProxy {
public:
  Proxy(DBus::Connection &connection,
        const char path[],
        const char service[]) : ObjectProxy(connection, path, service) {}
  virtual ~Proxy() {}

private:
  DISALLOW_COPY_AND_ASSIGN(Proxy);
};

TrunksDbusClient::TrunksDbusClient() {
}

TrunksDbusClient::~TrunksDbusClient() {
}

bool TrunksDbusClient::Connect() {
  const int kTimeoutMs = 120000;
  try {
    if (!DBus::default_dispatcher)
      DBus::default_dispatcher = new DBus::BusDispatcher();
    if (!proxy_.get()) {
      DBus::Connection connection = DBus::Connection::SystemBus();
      // Set the timeout to 2 minutes; some TPM operations can take long.  In
      // practice, calls have been noted to take more than 1 minute.
      connection.set_timeout(kTimeoutMs);
      proxy_.reset(new Proxy(connection,
                             kTrunksDbusServicePath,
                             kTrunksDbusServiceName));
    }
    if (!WaitForService())
      return false;
    LOG(INFO) << "Trunks client connected to " << kTrunksDbusServicePath;
    return true;
  } catch (DBus::Error err) {
    LOG(ERROR) << "DBus::Error - " << err.what();
  }
  return false;
}

bool TrunksDbusClient::Ping() {
  try {
    proxy_->Ping();
    return true;
  } catch (DBus::Error err) {
    LOG(ERROR) << "DBus::Error - " << err.what();
  }
  return false;
}

bool TrunksDbusClient::WaitForService() {
  const useconds_t kDelayOnFailureUs = 10000;  // 10ms.
  const int kMaxAttempts = 500;  // 5 seconds.
  std::string last_error_message;
  for (int i = 0; i < kMaxAttempts; ++i) {
    try {
      proxy_->Ping();
      return true;
    } catch (DBus::Error err) {
      last_error_message = err.what();
    }
    usleep(kDelayOnFailureUs);
  }
  LOG(ERROR) << "Trunks service is not available: " << last_error_message;
  return false;
}

}  // namespace trunks
