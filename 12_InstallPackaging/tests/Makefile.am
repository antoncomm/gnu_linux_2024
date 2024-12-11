TESTS = upstream
check_PROGRAMS = upstream

.ts.c:
	checkmk $< > $@

AM_CFLAGS = -I$(top_srcdir)/src @CHECK_CFLAGS@
LDADD = @CHECK_LIBS@
