#! /bin/bash

rm -rf *.out ft_main stl_main
c++ -Wall -Wextra -Werror -D__FT__ --std=c++98 -g3 -Itests/ -Imap/ -Ivector/ -Istack/ -Iset/ -o ft_main tests/set_tests.cpp tests/utils.cpp
c++ -Wall -Wextra -Werror --std=c++98 -g3 -Itests/ -Imap/ -Ivector/ -Istack/ -Iset/ -o stl_main tests/set_tests.cpp tests/utils.cpp

valgrind ./ft_main 1>ft.out 2>ft.err.out
valgrind ./stl_main 1>stl.out 2>stl.err.out

diff -ys ft.out stl.out
