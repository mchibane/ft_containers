#include "vector.hpp"
#include <vector>
#include <memory>
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <limits>

using namespace ft;

template<class T>
void print_vec(vector<T> vec)
{
	for (size_t i = 0; i < vec.size(); i++)
		std::cout << i + 1 << " " << vec[i] << std::endl;
}

int	main()
{
	{
		vector<int> vec(42);


			vec.reserve(vec.max_size() + 1);

	}
	return (0);
}
