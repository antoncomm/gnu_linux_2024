#!/bin/sh

tmp="`hexdump -C | while read A B; do echo "$B"; done | while IFS='|' read A B; do echo "$A"; done`"
points=""
x=0
y=0

for val in ${tmp}
do 
	points="${x};${y};${val} ${points}"
	x=$(($x + 1))
	if test ${val} = "0a"; then
		x=0
		y=$(($y + 1))
	fi
done

shuf_points="`shuf -e ${points}`"

tput clear

for pinfo in ${shuf_points}
do
	if test $1; then	
		sleep $1
	fi
	info=(${pinfo//;/ })
	tput cup ${info[1]} ${info[0]} 
	printf "\x${info[2]}"
done

tput cup $y 0

