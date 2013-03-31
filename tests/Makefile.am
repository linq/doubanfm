TESTS = check_doubanfm
check_PROGRAMS = check_doubanfm
LIBS=-lcurl -lm
check_doubanfm_SOURCES = \
  check_doubanfm.h \
  check_doubanfm_main.c \
	check_json.c \
  check_http.c \
	$(top_builddir)/src/common.h \
	$(top_builddir)/src/common.c \
	$(top_builddir)/src/http.c \
	$(top_builddir)/src/http.h \
	$(top_builddir)/src/json.h \
	$(top_builddir)/src/json.c
check_doubanfm_CFLAGS = -I $(top_builddir)/lib/ -I $(top_builddir)/src/ @CHECK_CFLAGS@
check_doubanfm_LDADD = $(top_builddir)/lib/libcjson.a @CHECK_LIBS@
