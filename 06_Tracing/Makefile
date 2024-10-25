.PHONY:	clean test

GENERATES=move protect.so
TRASH=*.o *~ test_in test_out PROTECT_test_in
CFLAGS = -Wall -Werror -O0 -g

all:	move protect.so

move:	move.c

protect.so: protect.c
	cc -shared -o protect.so protect.c

test_preload: protect.so move
	echo "asdffr" > PROTECT_test_in
	LD_PRELOAD=`pwd`/protect.so ./move PROTECT_test_in test_out
	@printf "\n"

	echo "asdffr" > test_in
	LD_PRELOAD=`pwd`/protect.so ./move test_in test_out

test:	move
	echo "asdffr" > test_in
	strace -e openat -P test_in -e fault=openat ./move test_in test_out || test "$$?" = "2"
	test -f test_in
	@printf "\n"

	echo "asdffr" > test_in
	strace -e read -P test_in -e fault=read ./move test_in test_out || test "$$?" = "3"
	test -f test_in
	@printf "\n"

	echo "asdffr" > test_in
	strace -e close -P test_in -e fault=close ./move test_in test_out || test "$$?" = "5"
	test -f test_in
	@printf "\n"

	echo "asdffr" > test_in
	strace -e unlink -P test_in -e fault=unlink ./move test_in test_out || test "$$?" = "6"
	test -f test_out
	@printf "\n"

	echo "asdffr" > test_in
	strace -e openat -P test_out -e fault=openat ./move test_in test_out || test "$$?" = "2"
	test -f test_in
	@printf "\n"
	
	echo "asdffr" > test_in
	echo "afr" > test_out
	strace -e close -P test_out -e fault=close ./move test_in test_out || test "$$?" = "5"
	test -f test_in
	@printf "\n"

	echo "afr" > test_out
	echo "asdffr" > test_in
	strace -e write -P test_out -e fault=write ./move test_in test_out || test "$$?" = "5"
	test -f test_in
	@printf "\n"

	echo "asdffr" > test_in
	./move || test "$$?" = "1"
	test -f test_in
	@printf "\n"

clean:	
	rm -f $(GENERATES) $(TRASH)

