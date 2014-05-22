// Copyright (c) 2013 The Chromium OS Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include <base/at_exit.h>
#include <base/command_line.h>
#include <chromeos/syslog_logging.h>
#include <gmock/gmock.h>
#include <gtest/gtest.h>

int main(int argc, char** argv) {
  base::AtExitManager exit_manager;
  CommandLine::Init(argc, argv);
  chromeos::InitLog(chromeos::kLogToStderr);
  ::testing::InitGoogleMock(&argc, argv);
  return RUN_ALL_TESTS();
}
