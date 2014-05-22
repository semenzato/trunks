// Copyright (c) 2013 The Chromium OS Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include <base/command_line.h>
#include <base/logging.h>
#include <chromeos/syslog_logging.h>

#include "trunks_dbus_client.h"

int main(int argc, char** argv) {
  CommandLine::Init(argc, argv);
  chromeos::InitLog(chromeos::kLogToSyslog | chromeos::kLogToStderr);
  trunks::TrunksDbusClient client;
  if (!client.Connect())
    return 1;
  client.Ping();
  return 0;
}
