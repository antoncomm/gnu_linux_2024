#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.71])
AC_INIT([Guess the five-letter word], [0.00], [uga@buga], [Wordle])
AM_INIT_AUTOMAKE([foreign])
DX_INIT_DOXYGEN([Wordle])
AM_GNU_GETTEXT([external])
AM_GNU_GETTEXT_REQUIRE_VERSION(0.21)
AC_CONFIG_SRCDIR([src/wordle.c])
AC_CONFIG_HEADERS([config.h])
AC_SUBST(GETTEXT_PACKAGE, "$PACKAGE")
ALL_LINGUAS="ru"

# Checks for programs.
AC_PROG_CC
IT_PROG_INTLTOOL

# Checks for libraries.
# FIXME: Replace 'main' with a function in '-lncurses':
AC_CHECK_LIB([ncursesw], [main])
PKG_CHECK_MODULES([CHECK],[check])

# Checks for header files.
AC_CHECK_HEADERS([libintl.h])

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.
AC_CHECK_FUNCS([setlocale])

AC_CONFIG_FILES([Makefile src/Makefile tests/Makefile po/Makefile.in Doxyfile])
AC_OUTPUT
