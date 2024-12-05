.PHONY: clean

LDLIBS = -lncurses
GENERATES = *_dict.txt wordle 
TRASH = *.o *~ o.*


all:	wordle dictionary

dictionary:	generate_dictionary.py
	python3 $^

clean:
	rm -rf $(TRASH) $(GENERATES)
