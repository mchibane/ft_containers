#! /bin/bash

c++ -Wall -Wextra -Werror -D__FT__ --std=c++98 -g3 -Itests/ -Imap/ -Ivector/ -Istack/ -Iset/ -o ft_main tests/vector_tests.cpp tests/utils.cpp
c++ -Wall -Wextra -Werror --std=c++98 -g3 -Itests/ -Imap/ -Ivector/ -Istack/ -Iset/ -o stl_main tests/vector_tests.cpp tests/utils.cpp

./ft_main >ft.out
./stl_main >stl.out

diff -ys ft.out stl.out
