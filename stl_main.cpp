#include "vector.hpp"
#include <vector>
#include <memory>
#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

template<class T>
void print_vec(vector<T> &vec)
{
	std::cout << "SIZE     : " << vec.size() << std::endl;
	std::cout << "MAX SIZE : " << vec.max_size() << std::endl;
	std::cout << "CAPACITY : " << vec.capacity() << std::endl;
	for (size_t i = 0; i < vec.size(); i++)
		std::cout << i + 1 << " " << vec[i] << std::endl;
	std::cout << std::endl;
}

int	main()
{
	{
		srand(time(NULL));
		vector<int> vec;
		vector<int> vec2;

		for (size_t i = 0; i < 42; i++)
		{
			vec.push_back(rand() % 100);
			std::cout << vec.capacity() << std::endl;
		}
		std::cout << std::endl;
		print_vec(vec);
		for (size_t i = 0; i < 20; i++)
			vec.pop_back();
		vec.resize(32);
		print_vec(vec);
	}
	return (0);
}
