AM_CFLAGS=-D'LOCALEDIR="$(localedir)"'

bin_PROGRAMS=guesser
guesser_SOURCES=src/guesser.c

SUBDIRS = po

GENERATES = ../*.m4 ../*.guess ../*.rpath ../configure ../depcomp $\
			../m4 ../*~ ../missing ../install-sh ../ABOUT-NLS ../*.cache $\
			../compile ../*.in ../*.sub ../src/*~ ../build
PO_GENERATES = ../po/*.header ../po/Makefile.in.in ../po/*.pot ../po/*.header ../po/*.sin ../po/*.template ../po/*.sed ../po/Rules-quot ../po/*~
clean_generates:
	rm -rf ${PO_GENERATES}
	rm -rf ${GENERATES}
