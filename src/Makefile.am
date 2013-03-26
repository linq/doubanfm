AUTOMAKE_OPTIONS = foreign
bin_PROGRAMS = douban
LIBS=-lcurl -lm
douban_SOURCES = http.h httpHelper.c douban.c douban.h json.h json.c
douban_LDADD = ../lib/libcjson.a
douban_CFLAGS = -I ../lib/
