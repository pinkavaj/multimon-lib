DEBUG		=n
OS		=$(shell uname)
MACH		=$(shell uname -m)

CFLAGS		=-Wall -Wstrict-prototypes -I/usr/X11R6/include -I../include
ifeq ($(OS),SunOS)
ifeq ($(DEBUG),y)
CFLAGS		+=-g -O -DSUN_AUDIO -DARCH_SPARC
else
CFLAGS		+=-O3 -DSUN_AUDIO -DARCH_SPARC
endif
LDFLAGSX	=-lX11 -L/usr/X11R6/lib -R/usr/X11R6/lib -lsocket -lnsl
else
ifeq ($(MACH),x86_64)
ifeq ($(DEBUG),y)
CFLAGS          +=-g -O -DARCH_X86_64
else
CFLAGS          +=-O3 -DARCH_X86_64
endif
LDFLAGSX        =-lX11 -L/usr/X11R6/lib64
else
ifeq ($(DEBUG),y)
CFLAGS		+=-g -O -march=i486 -mtune=pentium4 -falign-loops=2 -falign-jumps=2 \
		  -malign-functions=2 -DARCH_I386
else
CFLAGS		+=-O3 -march=i486 -mtune=pentium4 -falign-loops=2 -falign-jumps=2 \
		  -falign-functions=2 -DARCH_I386
endif
LDFLAGSX	=-lX11 -L/usr/X11R6/lib
endif
endif


BINDIR	=../build

AS86		=as86 -0 -a
LD86		=ld86 -0

AS		=as
LD		=ld
LDFLAGS		=-lm
HOSTCC		=gcc
CC		=gcc
MAKE		=make
CPP		=$(CC) -E
AR		=ar
STRIP		=strip
MKDIR		=mkdir

SRC_L1		=demod_afsk12.c demod_afsk24.c demod_afsk24_2.c
SRC_L1		+=demod_hapn48.c demod_fsk96.c
SRC_L1		+=demod_poc5.c demod_poc12.c demod_poc24.c
SRC_L1		+=demod_dtmf.c demod_zvei.c demod_display.c
SRC_L2		=hdlc.c pocsag.c
SRC_APP		=unixinput.c costabf.c xdisplay.c
SRC_GEN		=gen.c gen_dtmf.c gen_sin.c gen_zvei.c gen_hdlc.c costabi.c

OBJ_L1		=$(SRC_L1:%.c=$(BINDIR)/%.o)
OBJ_L2		=$(SRC_L2:%.c=$(BINDIR)/%.o)
OBJ_MISC	=$(SRC_APP:%.c=$(BINDIR)/%.o)
OBJ_GEN		=$(SRC_GEN:%.c=$(BINDIR)/%.o)

all:		$(BINDIR) $(BINDIR)/gen $(BINDIR)/libmultimon.so $(BINDIR)/multimon

$(BINDIR)/gen:		$(OBJ_GEN)
			$(CC) $^ $(LDFLAGS) -o $@

$(BINDIR)/libmultimon.so:	$(OBJ_L1) $(OBJ_L2)
	$(CC) -shared -Wl,-soname,$($@:$(BINDIR)/%=%) $(LDFLAGS) -o $@ $^
	# TODO

$(BINDIR)/multimon:	$(BINDIR)/libmultimon.a
			$(CC) $^ $(LDFLAGS) $(LDFLAGSX) -o $@

$(BINDIR)/libmultimon.a:	$(OBJ_L1) $(OBJ_L2) $(OBJ_MISC)
	$(AR) rcs $@ $^

$(BINDIR)/%.s:	%.c
		$(CC) $(CFLAGS) -S -o $@ $<

$(BINDIR)/%.o:	$(BINDIR)/%.s
		$(AS) -c -o $@ $<

$(BINDIR)/%.o:	%.c
		$(CC) $(CFLAGS) -c -o $@ $<

$(BINDIR):	$(BUILDDIR)
		$(MKDIR) $(BINDIR)

$(BINDIR)/mkcostab:	$(BINDIR)/mkcostab.o
			$(CC) $^ $(LDFLAGS) -o $@

costabi.c costabf.c:	$(BINDIR)/mkcostab
			$(BINDIR)/mkcostab

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

ifeq ($(BINDIR)/.depend,$(wildcard $(BINDIR)/.depend))
include $(BINDIR)/.depend
endif
