.PHONY:	clean run

GENERATES=lab lab1 lab2 lab3 lab1.c lab2.c lab3.c
TRASH=*.o *~
CFLAGS = -Wall -Werror -O3

all: run

lab: lab.c

lab1:	first.patch
	patch -u -b lab.c < first.patch
	mv lab.c lab1.c
	mv lab.c.orig lab.c 
	cc lab1.c -o $@

lab2:	second.patch
	patch -u -b lab.c < second.patch
	mv lab.c lab2.c
	mv lab.c.orig lab.c 
	cc lab2.c -o $@

lab3:	third.patch
	patch -u -b lab.c < third.patch
	mv lab.c lab3.c
	mv lab.c.orig lab.c 
	cc lab3.c -o $@

run:	lab lab1 lab2 lab3
	./lab
	./lab1 4
	./lab2 ' @' 8
	./lab3 12 '.#' 6

clean:
	rm -rf $(GENERATES) $(TRASH)


