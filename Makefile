# Copyright (c) 2011 The Chromium OS Authors. All rights reserved.
# Use of this source code is governed by a BSD-style license that can be
# found in the LICENSE file.

CFLAGS = -Wall -Werror -g

CONVERTERS_H = \
        g_tpm_commands.h \
        g_tpm_structures.h \

CONVERTERS_C = \
        g_tpm_commands.c \
        g_tpm_structures.c \

CONVERTERS = $(CONVERTERS_H) $(CONVERTERS_C)

CSOURCES = \
	ttl_authorization.c \
	ttl_error_messages.c \
	ttl_commands.c \
	ttl_interpret.c \
	ttl_linux.c \
	ttl_marshal.c \
	tpmc.c \

HSOURCES = \
	trunks.h \
	trunks_tpm.h \
	trunks_internal.h \
	ttl_authorization.h \
	ttl_error_messages.h \
	ttl_marshal.h \

all: tss tpmc

clean:
	rm -rf *.o g_* tpmc ttl-test test/{structure,command}.{c,h}
	$(MAKE) -C tss clean

tests: tss_tests

.PHONY: tss

$(CONVERTERS): g_tpm.phony

g_tpm.phony: ttl_generator.py g_tpm_commands_structure.txt tss_tpm_h
	./ttl_generator.py
	touch g_tpm.phony

g_tpm_commands_structure.txt: ttl_commands_extractor.sh \
                              tpm_commands_specification.txt
	./ttl_commands_extractor.sh > g_tpm_commands_structure.txt

tpmc: $(CONVERTERS_C) $(CSOURCES) $(HSOURCES)
	$(CC) $(CFLAGS) $(CONVERTERS_C) $(CSOURCES) -o tpmc -lcrypto

ttl-test: $(CONVERTERS_C) $(CSOURCES) $(HSOURCES)
	$(CC) -DTESTING $(CFLAGS) $(CONVERTERS_C) $(CSOURCES) -o ttl-test \
		-lcrypto

tss:
	$(MAKE) -C tss

tss_tests:
	$(MAKE) -C tss tests
