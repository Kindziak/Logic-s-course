#!/bin/bash

a=( 1 2 3 4 5 6 7 8 )
b=( -3 3 -6 7 -1 -9 -8 3 )
c=( 1 3 -9 -14 8 22 3 7 )
d=( 6 2 4 2 8 10 2 5 )
e=( 0 12 2 6 -2 -3 0 -2 )
f=( -3 -6 -2 7 9 12 -7 3 )
result=( 1 0 1 1 1 0 0 1 )

for ind in `seq 0 7`; do
	out=`'./'$1 ${a[$ind]} ${b[$ind]} ${c[$ind]} ${d[$ind]} ${e[$ind]} ${f[$ind]}` 
	if [ "$out" != "${result[$ind]}" ] then
		echo "Dane wejsciowe: " ${a[$ind]} ${b[$ind]} ${c[$ind]} ${d[$ind]} ${e[$ind]} ${f[$ind]}
		echo "Rezultat programu: " $out
		echo "Rezultat oczekiwany: " ${result[$ind]}
	fi
done
