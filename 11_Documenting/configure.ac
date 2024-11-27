#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.71])
AC_INIT([The number guesser from 1 to 100], [0.0.1], [asdf], [Guesser])
AM_INIT_AUTOMAKE([foreign])
DX_INIT_DOXYGEN([guesser])
LT_INIT([disable-static])
AC_CONFIG_SRCDIR([src/guesser.c])
AC_CONFIG_HEADERS([config.h])

# Checks for programs.
AC_PROG_CC

# Checks for libraries.

# Checks for header files.
AC_CHECK_HEADERS([libintl.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_TYPE_SIZE_T

# Checks for library functions.

AC_CONFIG_FILES([Makefile
                 src/Makefile
				 Doxyfile])
AC_OUTPUT
