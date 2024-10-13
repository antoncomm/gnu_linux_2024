.PHONY:	clean	test

GENERATES=range *.out
TRASH=*.o *~ 
CFLAGS = -Wall -Werror -O0 -g

all:	range

range:	range.c

test:	range
	gdb -x gdb_script_first | grep "@@@"| cut -c 4- > res_first.out
	cmp first_true res_first.out
	
	gdb -x gdb_script_second | grep "@@@"| cut -c 4- > res_second.out
	cmp second_true res_second.out

clean:
	rm -f $(GENERATES) $(TRASH)
