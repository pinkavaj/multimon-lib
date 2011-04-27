
ROOT		=.

include		$(ROOT)/config.in

BINDIR		:=$(ROOT)/$(BINDIR)

SRC_GEN		=gen.c
SRC_MULTIMON	=multimon.c demod_display.c xdisplay.c

OBJ_GEN		=$(SRC_GEN:%.c=$(BINDIR)/%.o)
OBJ_MULTIMON	=$(SRC_MULTIMON:%.c=$(BINDIR)/%.o)

LIB_GEN		=$(BINDIR)/libmultimon.a
LIB_MULTIMON	=$(BINDIR)/libmultimon.a

all:		$(BINDIR) multimon gen

$(BINDIR):
	$(MKDIR) $(BINDIR)

gen:		$(OBJ_GEN) $(LIB_GEN)
	$(CC) $^ $(LDFLAGS) $(CFLAGS) -o $@

multimon:	$(OBJ_MULTIMON) $(LIB_MULTIMON)
	$(CC) $^ $(LDFLAGS) $(LDFLAGSX) -o $@

$(BINDIR)/libmultimon.a:
	$(MAKE) -C lib

$(BINDIR)/%.o:	%.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	$(RM) -f core `find . -name '*.[oas]' -print`
	$(RM) -f core `find . -name 'core' -print`
	$(RM) -f core costabi.c costabf.c *~ multimon.tar.bz2
	$(RM) -rf $(BINDIR)

depend dep:	$(BINDIR) costabi.c costabf.c
	$(CPP) -M $(CFLAGS) $(SRC_APP) $(SRC_L1) $(SRC_L2) $(SRC_GEN) mkcostab.c > $(BINDIR)/.depend

dist:
	tar cjf multimon.tar.bz2 COPYING Makefile filter.h filter-i386.h gen.h multimon.h \
			$(SRC_APP) $(SRC_L1) $(SRC_L2) $(SRC_GEN) mkcostab.c

install: all
	$(MAKE) -C lib install
	install gen $(PREFIX)/bin
	install multimon $(PREFIX)/bin

ifeq ($(BINDIR)/.depend,$(wildcard $(BINDIR)/.depend))
include $(BINDIR)/.depend
endif

