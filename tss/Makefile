# Copyright (c) 2013 The Chromium OS Authors. All rights reserved.
# Use of this source code is governed by a BSD-style license that can be
# found in the LICENSE file.
#
# Top-level Makefile for trunks.
#

# Pull in chromium os defaults
PWD ?= $(CURDIR)
OUT ?= $(PWD)/build-opt-local

include common.mk

PLATFORM = chromeos

PKG_CONFIG ?= pkg-config
DBUSXX_XML2CPP = dbusxx-xml2cpp
INSTALL ?= install
INSTALL_DATA = $(INSTALL) -m 0644
LIB_DIR ?= /usr/lib

BASE_VER ?= 180609
PC_DEPS = dbus-c++-1 libchrome-$(BASE_VER) libchromeos-$(BASE_VER)
PC_CFLAGS := $(shell $(PKG_CONFIG) --cflags $(PC_DEPS))
PC_LIBS := $(shell $(PKG_CONFIG) --libs $(PC_DEPS))

CXXFLAGS += -I$(OUT) -I$(SRC)/include $(PC_CFLAGS) -DNDEBUG
LDLIBS += $(PC_LIBS)

# Generated Headers
trunks_dbus_proxy_generated.h: $(SRC)/trunks_dbus_interface.xml
	$(DBUSXX_XML2CPP) $< --proxy=$@
clean: CLEAN(trunks_dbus_proxy_generated.h)

trunks_dbus_adaptor_generated.h: $(SRC)/trunks_dbus_interface.xml
	$(DBUSXX_XML2CPP) $< --adaptor=$@
clean: CLEAN(trunks_dbus_adaptor_generated.h)

trunks_dbus_service.o.depends \
trunksd.o.depends : trunks_dbus_adaptor_generated.h

trunks_dbus_client.o.depends : trunks_dbus_proxy_generated.h

# Common Files
COMMON_OBJS = resource_manager.o \
              result.o result_constants.o \
              trunks_dbus_constants.o

# Trunks Library
libtrunks_OBJS = $(COMMON_OBJS) tspi.o trunks_dbus_client.o\
                 tsp.o tsp_context.o
CXX_LIBRARY(libtrunks.so): $(libtrunks_OBJS)
clean: CLEAN(libtrunks.so)
all: CXX_LIBRARY(libtrunks.so)

# Trunks Daemon
tpm_OBJS = tpm.o tpm_constants.o tpm_message.o
trunksd_OBJS = $(COMMON_OBJS) $(tpm_OBJS) tcs.o trunksd.o trunks_dbus_service.o
CXX_BINARY(trunksd): $(trunksd_OBJS)
clean: CLEAN(trunksd)
all: CXX_BINARY(trunksd)

# Trunks Client
trunks_client_OBJS = $(COMMON_OBJS) $(libtrunks_OBJS) trunks_client.o \
                     trunks_dbus_client.o
CXX_BINARY(trunks_client): $(trunks_client_OBJS)
clean: CLEAN(trunks_client)
all: CXX_BINARY(trunks_client)

# Unit Tests
test_OBJS = $(COMMON_OBJS) result_test.o context_manager_test.o \
            resource_manager_test.o \
            $(libtrunks_OBJS) tsp_context_test.o \
            tspi_test.o \
            $(tpm_OBJS) tpm_message_test.o \
            testrunner.o
test_LIBS = $(shell gmock-config --libs) $(shell gtest-config --libs)
CXX_BINARY(trunks_unittest): $(test_OBJS)
CXX_BINARY(trunks_unittest): LDLIBS += $(test_LIBS)
clean: CLEAN(trunks_unittest)
tests: TEST(CXX_BINARY(trunks_unittest))
