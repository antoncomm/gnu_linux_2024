.PHONY: clean test

GENERATES = prog prog-a prog-so liboutput_static.a liboutput.so
TRASH = *.o *~ o.*
RESULT_FILES = file_*
CFLAGS = -Wall -Werror -fPIC
ONE_ARG = abba
THREE_ARG = abba baab baba

all:	prog prog-a prog-so

.SECONDARY:	liboutput_static.a(fun.o const.o)

liboutput_static.a:	liboutput_static.a(fun.o const.o)

liboutput.so:	fun.o const.o
	$(CC) $^ -o $@ -shared

prog:	prog.o fun.o const.o

prog-a:	prog.o liboutput_static.a
	$(CC) $^ -o $@

prog-so:	prog.o liboutput.so
	$(CC) $^ -o $@

fun.o prog.o:  outlib.h

test:	prog prog-a prog-so
	./prog 2> file_zero_prog
	./prog-a 2> file_zero_prog-a
	LD_LIBRARY_PATH=`pwd` ./prog-so 2> file_zero_prog-so
	
	./prog $(ONE_ARG) 1> file_one_prog
	./prog-a $(ONE_ARG) 1> file_one_prog-a
	LD_LIBRARY_PATH=`pwd` ./prog-so $(ONE_ARG) 1> file_one_prog-so
	
	./prog $(THREE_ARG) 1> file_three_prog
	./prog-a $(THREE_ARG) 1> file_three_prog-a
	LD_LIBRARY_PATH=`pwd` ./prog-so $(THREE_ARG) 1> file_three_prog-so

	cmp file_one_prog file_one_prog-a
	cmp file_one_prog file_one_prog-so
	cmp file_one_prog-a file_one_prog-so
	
	cmp file_three_prog file_three_prog-a
	cmp file_three_prog file_three_prog-so
	cmp file_three_prog-a file_three_prog-so

	sed -r -e "s@./prog@@g" file_zero_prog > file_zero_prog1
	sed -r -e "s@./prog-a@@g" file_zero_prog-a > file_zero_prog-a1
	sed -r -e "s@./prog-so@@g" file_zero_prog-so > file_zero_prog-so1

	cmp file_zero_prog1 file_zero_prog-a1
	cmp file_zero_prog-a1 file_zero_prog-so1
	cmp file_zero_prog1 file_zero_prog-so1

clean:
	rm -f $(GENERATES) $(TRASH) $(RESULT_FILES)
