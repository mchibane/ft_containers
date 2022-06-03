#! /bin/bash

seed=$1
if  [ $# -eq 0 ]
	then
		seed=42;
fi

rm -rf tests/outfiles
rm -rf tests/stderr
make -s re
mkdir -p tests/outfiles
mkdir -p tests/stderr

valgrind ./tests/bin/ft_containers $seed 1>tests/outfiles/ft.out 2>tests/stderr/ft.err.out
valgrind ./tests/bin/std_containers $seed 1>tests/outfiles/std.out 2>tests/stderr/std.err.out

diff -ys tests/outfiles/ft.out tests/outfiles/std.out

echo ""
echo "Testing ft_containers speed ... Please stand-by"
echo ""

time ./tests/bin/ft_perf $seed

echo ""
echo "================================================"
echo ""
echo "Testing std_containers speed ... Please stand-by"
echo ""
time ./tests/bin/std_perf $seed

echo ""
echo "================================================"
echo ""
echo "Valgrind out :"
echo ""
cat ./tests/stderr/ft.err.out
