AM_CFLAGS=-D'LOCALEDIR="$(localedir)"' -D'DATADIR="$(datadir)"'

bin_PROGRAMS = wordle
wordle_SOURCES =wordle.h wordle.c

BUILT_SOURCES = wordle.h

wordle.h:	en_dict.txt	

en_dict.txt:	generate_dictionary.py
	python3 $^	

install-data-local:	en_dict.txt
	mkdir -p ${datadir}
	mv $^ ${datadir}
