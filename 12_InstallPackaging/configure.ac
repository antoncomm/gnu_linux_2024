#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.71])
AC_INIT([Guess the five-letter word], [0.00], [uga@buga], [Wordle])
AM_INIT_AUTOMAKE([foreign])
AC_CONFIG_SRCDIR([src/wordle.c])
AC_CONFIG_HEADERS([config.h])

# Checks for programs.
AC_PROG_CC

# Checks for libraries.
# FIXME: Replace 'main' with a function in '-lncurses':
AC_CHECK_LIB([ncurses], [main])
PKG_CHECK_MODULES([CHECK],[check])

# Checks for header files.

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.

AC_CONFIG_FILES([Makefile src/Makefile tests/Makefile])
AC_OUTPUT
