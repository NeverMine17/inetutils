# Generic make rules for inetutils
#
# Copyright (C) 1995, 1996 Free Software Foundation, Inc.
#
# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2, or (at your option)
# any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software
# Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
#

all:

install: $(INSTALL_TARGETS)
uninstall: -$(RM) -f $(INSTALL_TARGETS)

mostlyclean: clean
distclean: clean
	$(RM) -f Makefile $(DISTCLEAN)
maintainer-clean: distclean
	$(RM) -f $(MAINTCLEAN)

dist: $(DISTFILES)
	$(LINK_DISTFILES)

$(bindir)/%: % $(bindir)
	$(INSTALL_PROGRAM) $(INST_PROG_FLAGS) $(filter-out $(bindir),$<) $@
$(includedir)/%: % $(includedir)
	$(INSTALL_DATA) $(INST_DATA_FLAGS) $(filter-out $(includedir),$<) $@
$(includedir)/%: $(srcdir)/% $(includedir)
	$(INSTALL_DATA) $(INST_DATA_FLAGS) $(filter-out $(includedir),$<) $@
$(libdir)/%: % $(libdir)
	$(INSTALL_DATA) $(INST_DATA_FLAGS) $(filter-out $(libdir),$<) $@
$(sbindir)/%: % $(sbindir)
	$(INSTALL_PROGRAM) $(INST_PROG_FLAGS) $(filter-out $(sbindir),$<) $@
$(libexecdir)/%: % $(libexecdir)
	$(INSTALL_PROGRAM) $(INST_PROG_FLAGS) $(filter-out $(libexecdir),$<) $@
$(libexecdir)/in.%: % $(libexecdir)
	$(INSTALL_PROGRAM) $(INST_PROG_FLAGS) $(filter-out $(libexecdir),$<) $@
$(sysconfdir)/%: % $(sysconfdir)
	$(INSTALL_DATA) $(INST_DATA_FLAGS) $(filter-out $(sysconfdir),$<) $@
$(localstatedir)/%: % $(localstatedir)
	$(INSTALL_DATA) $(INST_DATA_FLAGS) $(filter-out $(localstatedir),$<) $@
$(sharedstatedir)/%: % $(sharedstatedir)
	$(INSTALL_DATA) $(INST_DATA_FLAGS) $(filter-out $(sharedstatedir),$<) $@
$(man1dir)/%: % $(man1dir)
	-$(INSTALL_DATA) $(INST_DATA_FLAGS) $(filter-out $(man1dir),$<) $@
$(man1dir)/%: $(srcdir)/% $(man1dir)
	-$(INSTALL_DATA) $(INST_DATA_FLAGS) $(filter-out $(man1dir),$<) $@
$(man5dir)/%: % $(man5dir)
	-$(INSTALL_DATA) $(INST_DATA_FLAGS) $(filter-out $(man5dir),$<) $@
$(man5dir)/%: $(srcdir)/% $(man5dir)
	-$(INSTALL_DATA) $(INST_DATA_FLAGS) $(filter-out $(man5dir),$<) $@
$(man8dir)/%: % $(man8dir)
	-$(INSTALL_DATA) $(INST_DATA_FLAGS) $(filter-out $(man8dir),$<) $@
$(man8dir)/%: $(srcdir)/% $(man8dir)
	-$(INSTALL_DATA) $(INST_DATA_FLAGS) $(filter-out $(man8dir),$<) $@

$(bindir) $(includedir) $(libdir) $(sbindir) $(libexecdir) $(sysconfdir) $(localstatedir) $(sharedstatedir) $(mandir) $(man1dir) $(man5dir) $(man8dir):
	@$(MKINSTDIRS) $@
