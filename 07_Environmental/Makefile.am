CFLAGS=-Wall -O0 -g
GENERATES=../test-driver ../*.m4 ../*.cache  ../compile  ../*.in  ../configure  ../*~  ../depcomp  ../install-sh ../missing ../build

bin_PROGRAMS=rhasher

rhasher_SOURCES=src/rhasher.c

TESTS = sha1_file.sh md5_file.sh

sha1_file.sh:
	echo 'echo "asdf" > test' >> $@
	echo 'sha1sum test | cut -d " " -f 1 > true_res' >> $@
	echo 'echo "SHA1 test" | ./rhasher > my_res' >> $@
	echo 'tail -1 my_res > my_res1' >> $@
	echo 'cmp true_res my_res1' >> $@
	chmod +x $@

md5_file.sh:
	echo 'echo "asdf" > test' >> $@
	echo 'md5sum test | cut -d " " -f 1 > true_res' >> $@
	echo 'echo "MD5 test" | ./rhasher > my_res' >> $@
	echo 'tail -1 my_res > my_res1' >> $@
	echo 'cmp true_res my_res1' >> $@
	chmod +x $@

clean:
	rm -rf ${GENERATES}
