TESTS = upstream
check_PROGRAMS = upstream

.ts.c:
	checkmk $< > $@

AM_CFLAGS = -I../$(top_builddir)/src @CHECK_CFLAGS@
LDADD = @CHECK_LIBS@
