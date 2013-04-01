noinst_LIBRARIES = libcommon.a

CFILES =\
  http.c \
	douban.c \
	json.c \
	common.c 

HFILES =\
  http.h \
	douban.h \
	json.h \
	common.h 

libcommon_a_SOURCES = $(HFILES) $(CFILES)
libcommon_a_CFLAGS = -I $(top_builddir)/lib/
libcommon_a_LIBADD = $(top_builddir)/lib/libcjson.a

bin_PROGRAMS = doubanfm
LIBS=-lcurl -lm
doubanfm_SOURCES = doubanfm.c
doubanfm_LDADD = libcommon.a $(top_builddir)/lib/libcjson.a 
doubanfm_CFLAGS = -I $(top_builddir)/lib/
