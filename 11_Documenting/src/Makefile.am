CFLAGS  += -O3 -g3

lib_LTLIBRARIES = libguesser.la
bin_PROGRAMS = guesser

guesser_LDADD = libguesser.la

libguesser.c:	table.h

table.h:	generate_roman.py
	python3 $< > $@
