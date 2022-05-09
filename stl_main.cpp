#include "vector.hpp"
#include <vector>
#include <memory>
#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

void print_vec(vector<int> vec)
{
	for (size_t i = 0; i < vec.size(); i++)
		std::cout << i + 1 << " " << vec[i] << std::endl;
}

int	main()
{
	{
		srand(time(NULL));
		vector<int> vec(2, 12);
		for(size_t i = 0; i < vec.size(); i++)
			vec[i] = rand() % 100;
		print_vec(vec);
	}
	return (0);
}
