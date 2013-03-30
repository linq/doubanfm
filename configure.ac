#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([doubanfm], [1.0], [fancylinq@163.com])
AC_CONFIG_SRCDIR([src/douban.c])
AM_INIT_AUTOMAKE([readme-alpha])
AC_CONFIG_HEADERS([config.h])
AM_INIT_AUTOMAKE([foreign -Wall -Werror])

# Checks for programs.
AC_PROG_CC
AM_PROG_CC_C_O

# Checks for libraries.
AM_PATH_CHECK()
AC_PROG_RANLIB

# Checks for header files.
AC_CHECK_HEADERS([stdlib.h string.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_TYPE_OFF_T
AC_TYPE_SIZE_T

# Checks for library functions.
AC_FUNC_MALLOC
AC_FUNC_REALLOC
AC_CHECK_FUNCS([strstr])

AC_CONFIG_FILES([Makefile
           doc/Makefile
           lib/Makefile
           po/Makefile
           man/Makefile
           src/Makefile
           tests/Makefile])

AC_OUTPUT
