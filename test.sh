#! /bin/bash

rm -rf ./outfiles/*
c++ -Wall -Wextra -Werror --std=c++98 my_main.cpp -o my_main
c++ -Wall -Wextra -Werror --std=c++98 stl_main.cpp -o stl_main
valgrind ./stl_main > ./outfiles/stl.out 2>/dev/null
valgrind ./my_main > ./outfiles/my.out 2>/dev/null
diff ./outfiles/my.out ./outfiles/stl.out
rm -rf stl_main my_main
