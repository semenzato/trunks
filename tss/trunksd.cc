// Copyright (c) 2013 The Chromium OS Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include <base/at_exit.h>
#include <base/command_line.h>
#include <base/logging.h>
#include <base/memory/scoped_ptr.h>
#include <base/message_loop.h>
#include <chromeos/syslog_logging.h>
#include <dbus-c++/dbus.h>
#include <dbus-c++/glib-integration.h>

#include "trunks_dbus_constants.h"
#include "trunks_dbus_service.h"

int main(int argc, char** argv) {
  CommandLine::Init(argc, argv);
  chromeos::InitLog(chromeos::kLogToSyslog | chromeos::kLogToStderr);
  base::AtExitManager exit_manager;

  // Setup a dbus dispatcher which plugs into the glib main loop.
  scoped_ptr<DBus::Glib::BusDispatcher> dispatcher(
      new DBus::Glib::BusDispatcher());
  DBus::default_dispatcher = dispatcher.get();
  dispatcher->attach(NULL);

  // Setup the trunks dbus service.
  DBus::Connection connection(DBus::Connection::SystemBus());
  connection.request_name(trunks::kTrunksDbusServiceName);
  trunks::TrunksDbusService service(connection,
                                    DBus::Path(trunks::kTrunksDbusServicePath));

  // Run a UI message loop.  This type of loop is integrated with glib so all we
  // need to do is run this loop and |dispatcher| will work correctly.
  MessageLoopForUI message_loop;
  MessageLoop::current()->Run();
  return 0;
}
