#!/bin/bash
set -e
compiler="clang++ -fsanitize=address"
$compiler -g -Wall -pedantic test_insert.cpp -o testinsert
$compiler -g -Wall -pedantic test_merge.cpp -o testmerge
$compiler -g -Wall -pedantic test_tim.cpp -o testtim -DTIMSORT=1

if [ "$1" = "test" ]
then
	set -x
	./testinsert
	./testmerge
	./testtim
fi
