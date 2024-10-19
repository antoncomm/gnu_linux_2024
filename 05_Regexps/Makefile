.PHONY:	clean	test CmpWithSed ErrorEsub1 ErrorEsub2 ErrorEsub3 

GENERATES=esub true_* res_*
TRASH=*.o *~ 
CFLAGS = -Wall -Werror -O3

all:	esub

esub:	esub.c

CmpWithSed:	esub
	echo 'asdf' | sed -E 's/sd/ds/' > true_1.out
	./esub 'sd' 'ds' 'asdf' > res_1.out
	cmp true_1.out res_1.out
	@printf '\n' 

	echo 'abba babba' | sed -E 's/(bba)/<\1>/' > true_2.out
	./esub '(bba)' '<\1>' 'abba babba' > res_2.out
	cmp true_2.out res_2.out
	@printf '\n' 
	
	echo 'abba babba' | sed -E 's/(bba)( b)/<1\1><2\2>/' > true_3.out
	./esub '(bba)( b)' '<1\1><2\2>' 'abba babba' > res_3.out
	cmp true_3.out res_3.out
	@printf '\n' 
	
	echo 'abba babba' | sed -E 's/(bba)( b)/<1\1><2\\2>/' > true_4.out
	./esub '(bba)( b)' '<1\1><2\\2>' 'abba babba' > res_4.out
	cmp true_4.out res_4.out
	@printf '\n' 
	
	echo 'abba babba' | sed -E 's/(bba)( b)/<1\1><2\\\2>/' > true_5.out
	./esub '(bba)( b)' '<1\1><2\\\2>' 'abba babba' > res_5.out
	cmp true_5.out res_5.out
	@printf '\n' 
	
ErrorEsub1:	esub
	if ./esub '(bba)' '<2\2>' 'abba babba'; then \
		printf 'Succeeded\n\n'; \
	else \
		printf 'Error\n\n'; \
	fi

ErrorEsub2:	esub
	if ./esub '(bba' '<2\2>' 'abba babba'; then \
		printf 'Succeeded\n\n'; \
	else \
		printf 'Error\n\n'; \
	fi

ErrorEsub3:	esub
	if ./esub '(bba' '<2\2>'; then \
		printf 'Succeeded\n\n'; \
	else \
		printf 'Error\n\n'; \
	fi

test:	CmpWithSed ErrorEsub1 ErrorEsub2 ErrorEsub3 

clean:
	rm -f $(GENERATES) $(TRASH)
