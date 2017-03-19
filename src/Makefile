include ../common.mak

INCLUDEPATHS = -I../setBfreak_overdrive/ -I../setBfreak_whirl  -I../setBfreak_reverb -I../setBfreak_conv

override CFLAGS += $(INCLUDEPATHS)
override CFLAGS += -DSHAREDIR="\"$(sharedir)\""
LOADLIBES = -lm -lpthread

BXCC=$(CC)

OBJS= \
	midi.o \
	midi_aseq.o \
	state.o \
	vibrato.o \
	tonegen.o \
	program.o \
	pgmParser.o \
	cfgParser.o \
	main.o \
	midnam.o \
	memstream.o \
	../setBfreak_reverb/reverb.c \
	../setBfreak_whirl/eqcomp.c \
	../setBfreak_whirl/whirl.c \
	../setBfreak_overdrive/overdrive.c

HEADERS = \
	cfgParser.h \
	global_inst.h \
	main.h \
	midi.h \
	midi_aseq.h \
	midi_types.h \
	pgmParser.h \
	program.h \
	vibrato.h \
	tonegen.h \
	defaultpgm.h \
	memstream.h \
	../setBfreak_reverb/reverb.h \
	../setBfreak_whirl/eqcomp.h \
	../setBfreak_whirl/whirl.h \
	../setBfreak_overdrive/overdrive.h


ifeq ($(shell pkg-config --exists jack || echo no), no)
  $(error "JACK is required - install libjack-dev or libjack-jackd2-dev")
endif

ifeq ($(shell pkg-config --exists alsa && echo yes)$(ENABLE_ALSA), yesyes)
  override CFLAGS+=-DHAVE_ASEQ `pkg-config --cflags alsa`
  LOADLIBES+=`pkg-config --libs alsa`
endif


override CFLAGS+=`pkg-config --cflags jack`

ifeq ($(USEWEAKJACK),1)
  override CFLAGS+=-DUSE_WEAK_JACK -I$(RW)
  LOADLIBES+=-ldl
  WEAKJACK=$(RW)weakjack/weak_libjack.c
else
  LOADLIBES+=`pkg-config --libs jack`
endif

ifeq ($(shell pkg-config --exists sndfile \
	&& test -f /usr/include/zita-convolver.h -o -f /usr/local/include/zita-convolver.h \
	&& echo yes), $(ENABLE_CONVOLUTION))
  override CFLAGS+= -DHAVE_ZITACONVOLVE `pkg-config --cflags sndfile`
  LOADLIBES+=-lzita-convolver `pkg-config --libs sndfile`
  OBJS+=../setBfreak_conv/convolution.o
  HEADERS+=../setBfreak_conv/convolution.h
  BXCC=$(CXX)
endif

all: setBfree$(EXE_EXT)

setBfree$(EXE_EXT): $(HEADERS) $(OBJS)
	$(BXCC) $(CPPFLAGS) $(CFLAGS) \
		-o $(@) $(OBJS) $(WEAKJACK) \
		$(LDFLAGS) $(LOADLIBES)

programd: program.c pgmParser.c program.h pgmParser.h main.h
	$(CC) $(CPPFLAGS) $(CFLAGS) $(LDFLAGS) -Wall \
		-DPRG_MAIN \
		-o $(@) program.c pgmParser.c

configd: cfgParser.c main.h
	$(CC) $(CPPFLAGS) $(CFLAGS) $(LDFLAGS) -Wall \
		-DCFG_MAIN \
		-o $(@) cfgParser.c

program: programd ../pgm/default.pgm
	$(info re-generating default program include-file)
	./programd ../pgm/default.pgm > defaultpgm.h

program.o: defaultpgm.h

# override .o in parent dirs -- needed for parallel builds

../setBfreak_reverb/reverb.o: ../setBfreak_reverb/reverb.[ch]
	+$(MAKE) -C ../setBfreak_reverb reverb.o

../setBfreak_whirl/eqcomp.o: ../setBfreak_whirl/eqcomp.[ch]
	+$(MAKE) -C ../setBfreak_whirl eqcomp.o

../setBfreak_whirl/whirl.o: ../setBfreak_whirl/whirl.[ch]
	+$(MAKE) -C ../setBfreak_whirl whirl.o

../setBfreak_overdrive/overdrive.o: \
  ../setBfreak_overdrive/filterTools.[ch] \
  ../setBfreak_overdrive/overdrive.h \
  ../setBfreak_overdrive/overmaker.[ch] \
  ../setBfreak_overdrive/overmakerdefs.h \
  ../setBfreak_overdrive/ovt_biased.[ch]
	+$(MAKE) -C ../setBfreak_overdrive overdrive.o

../setBfreak_conv/convolution.o: ../setBfreak_conv/convolution.cc ../setBfreak_conv/convolution.h
	+$(MAKE) -C ../setBfreak_conv convolution.o

clean:
	rm -f *.o core *.log *~ setBfree$(EXE_EXT) configd programd

install: setBfree
	install -d $(DESTDIR)$(bindir)
	install -m755 setBfree $(DESTDIR)$(bindir)
	install -d $(DESTDIR)$(sharedir)/cfg
	install -d $(DESTDIR)$(sharedir)/pgm
	install -m644 ../cfg/*.cfg $(DESTDIR)$(sharedir)/cfg
	install -m644 ../pgm/*.pgm $(DESTDIR)$(sharedir)/pgm

uninstall:
	rm -f $(DESTDIR)$(bindir)/setBfree
	rm -f $(DESTDIR)$(sharedir)/cfg/*
	rm -f $(DESTDIR)$(sharedir)/pgm/*
	-rmdir $(DESTDIR)$(bindir)
	-rmdir $(DESTDIR)$(sharedir)/cfg
	-rmdir $(DESTDIR)$(sharedir)/pgm
	-rmdir $(DESTDIR)$(sharedir)

.PHONY: clean all install uninstall program
