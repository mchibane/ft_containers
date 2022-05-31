#include "tests.hpp"

void	copy_contruct(void)
{
	NS::vector<int>	vec;
	size_t			max_num;

	std::cout << "======> COPY CONSTRUCT <======" << std::endl << std::endl;
	max_num = (rand() % 25) + 1;
	for (size_t i = 0; i < max_num; i++)
		vec.push_back(rand() % 100);
	std::cout << "------[ VEC ]------" << std::endl;
	print_vec(vec);
	{
		NS::vector<int>	vec2(vec);
		std::cout << "------[ VEC 2 (COPY) ]------" << std::endl;
		print_vec(vec2);
	}
	std::cout << "=============================" << std::endl << std::endl << std::endl;
}

void	assignation(void)
{
	NS::vector<int>	vec;
	NS::vector<int>	vec2;
	size_t			max_num;

	max_num = (rand() % 25) + 1;
	std::cout << "======> ASSIGNATION <=====" << std::endl << std::endl;
	for (size_t i = 0; i < 42; i++)
		vec.push_back(rand() % 100);
	for (size_t i = 0; i < max_num; i++)
		vec2.push_back(rand() % 100);
	std::cout << "------[ VEC ]------" << std::endl;
	print_vec(vec);
	std::cout << "------[ VEC 2 ]------" << std::endl;
	print_vec(vec2);
	std::cout << "vec2 = vec" << std::endl;
	vec2 = vec;
	std::cout << "------[ VEC 2 ]------" << std::endl;
	print_vec(vec2);
	std::cout << "=============================" << std::endl << std::endl << std::endl;
}

void	iterators(void)
{
	NS::vector<int>				vec;
	NS::vector<int>::iterator	it;
	NS::vector<int>::iterator	ite;
	size_t						max_num;

	std::cout << "======> ITERATORS <======" << std::endl << std::endl;
	max_num = rand() % (22 + 1 - 10) + 10;
	for (size_t i = 0; i < max_num; i++)
		vec.push_back(rand() % 100);
	std::cout << "------[ VEC ]------" << std::endl;
	print_vec(vec);
	it = vec.begin() + 3;
	ite = vec.end() - 5;
	std::cout << "vec.begin()\t\t: " << *vec.begin() << std::endl;
	std::cout << "vec.end() - 1\t\t: " << *(vec.end() - 1) << std::endl;
	std::cout << "it = vec.begin() + 3\t: " << *it << std::endl;
	std::cout << "it++\t\t\t: " << *it++ << std::endl;
	++it;
	std::cout << "++it\t\t\t: " << *it << std::endl;
	it--;
	std::cout << "it--\t\t\t: " << *it << std::endl;
	--it;
	std::cout << "--it\t\t\t: " << *it << std::endl;
	++(++(++it))++;
	std::cout << "++(++(++it))++\t\t: " << *it << std::endl;
	--(--it)--;
	std::cout << "--(--it)--\t\t: " << *it << std::endl;
	std::cout << "ite = end() - 5\t\t: " << *ite << std::endl;
	std::cout << std::boolalpha;
	std::cout << "ite == it\t\t: " << (ite == it) << std::endl;
	std::cout << "ite != it\t\t: " << (ite != it) << std::endl;
	std::cout << "ite > it\t\t: " << (ite > it) << std::endl;
	std::cout << "ite < it\t\t: " << (ite < it) << std::endl;
	std::cout << "ite >= it\t\t: " << (ite >= it) << std::endl;
	std::cout << "ite <= it\t\t: " << (ite <= it) << std::endl;
	std::cout << "=============================" << std::endl << std::endl << std::endl;
}

void	capacity(void)
{
	NS::vector<std::string>	vec;
	size_t					max_num;

	std::cout << "======> CAPACITY <======" << std::endl;
	max_num = rand() % (22 + 1 - 10) + 10;
	for (size_t i = 0; i < max_num; i++)
		vec.push_back(rand_str_gen());
	std::cout << "------[ VEC ]------" << std::endl;
	print_vec(vec);
}

int	main(void)
{
	srand(time(NULL));
	// #ifdef __FT__
	// std::cout << "============> FT <============" << std::endl;
	// #else
	// std::cout << "============> STL <============" << std::endl;
	// #endif

	copy_contruct();
	assignation();
	iterators();
	capacity();
	return (0);
}
