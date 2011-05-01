
ROOT		=..

include 	$(ROOT)/config.in

BINDIR		:=$(ROOT)/$(BINDIR)

SRC_L1		=demod_afsk12.c demod_afsk24.c demod_afsk24_2.c
SRC_L1		+=demod_hapn48.c demod_fsk96.c
SRC_L1		+=demod_dtmf.c demod_zvei.c
SRC_L2		=hdlc.c
SRC_MISC	=costabf.c filter.c debug.c
ifeq ($(MACH),i686)
SRC_MISC	+=filter-i386.c
endif
SRC_GEN		=gen_dtmf.c gen_sin.c gen_zvei.c gen_hdlc.c costabi.c

OBJ_L1		=$(SRC_L1:%.c=$(BINDIR)/%.o)
OBJ_L2		=$(SRC_L2:%.c=$(BINDIR)/%.o)
OBJ_MISC	=$(SRC_MISC:%.c=$(BINDIR)/%.o)
OBJ_GEN		=$(SRC_GEN:%.c=$(BINDIR)/%.o)

LIB_SO		=libmultimon.so.$(VER_MAJ).$(VER_MIN)

all:		$(BINDIR) $(BINDIR)/libmultimon.a $(BINDIR)/$(LIB_SO)

$(BINDIR):
	$(MKDIR) $(BINDIR)

$(BINDIR)/libmultimon.a:	$(OBJ_L1) $(OBJ_L2) $(OBJ_GEN) $(OBJ_MISC)
	$(AR) rcs $@ $^

$(BINDIR)/$(LIB_SO):	$(OBJ_L1) $(OBJ_L2) $(OBJ_GEN) $(OBJ_MISC)
	$(CC) -shared -Wl,-soname,$(LIB_SO:%.$(VER_MAJ).$(VER_MIN)=%) $(LDFLAGS) -o $@ $^

$(BINDIR)/%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

$(BINDIR)/mkcostab:	$(BINDIR)/mkcostab.o
	$(CC) $^ $(LDFLAGS) -o $@

costabi.c costabf.c:	$(BINDIR) $(BINDIR)/mkcostab
	$(BINDIR)/mkcostab

clean:
	$(RM) -f core `find . -name '*.[oas]' -print`
	$(RM) -f core `find . -name 'core' -print`
	$(RM) -f core costabi.c costabf.c *~ multimon.tar.bz2
	$(RM) -rf $(BINDIR)


depend dep:	$(BINDIR) costabi.c costabf.c
	$(CPP) -M $(CFLAGS) $(SRC_MISC) $(SRC_L1) $(SRC_L2) $(SRC_GEN) mkcostab.c > $(BINDIR)/.depend

dist:
	tar cjf multimon.tar.bz2 COPYING Makefile filter.h filter-i386.h gen.h multimon.h \
			$(SRC_MISC) $(SRC_L1) $(SRC_L2) $(SRC_GEN) mkcostab.c

install: all
	install $(BINDIR)/libmultimon.a $(PREFIX)/lib
	install $(BINDIR)/$(LIB_SO) $(PREFIX)/lib
	install $(ROOT)/include/multimon.h $(PREFIX)/include
	install $(ROOT)/include/multimon_gen.h $(PREFIX)/include

ifeq ($(BINDIR)/.depend,$(wildcard $(BINDIR)/.depend))
include $(BINDIR)/.depend
endif
