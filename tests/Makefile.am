TESTS = check_http
check_PROGRAMS = check_http
LIBS=-lcurl -lm
check_http_SOURCES = check_http.c $(top_builddir)/src/http.c $(top_builddir)/src/http.h
check_http_CFLAGS = -I $(top_builddir)/lib/ -I $(top_builddir)/src/ @CHECK_CFLAGS@
check_http_LDADD = $(top_builddir)/lib/libcjson.a @CHECK_LIBS@
