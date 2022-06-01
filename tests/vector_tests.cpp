#include "tests.hpp"
#include <list>

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
	NS::vector<std::string>	empt;
	size_t					max_num;

	std::cout << "======> CAPACITY <======" << std::endl;
	max_num = rand() % (22 + 1 - 10) + 10;
	for (size_t i = 0; i < max_num; i++)
		vec.push_back(rand_str_gen());
	std::cout << "------[ VEC ]------" << std::endl;
	print_vec(vec);
	std::cout << "------[ RESERVE 50 ]------" << std::endl;
	vec.reserve(50);
	print_vec(vec);
	std::cout << "------[ RESIZE 10 ]------" << std::endl;
	vec.resize(10);
	print_vec(vec);
	std::cout << "------[ RESIZE 42 ]------" << std::endl;
	vec.resize(42);
	print_vec(vec);
	std::cout << "------[ RESIZE 2000 ]------" << std::endl;
	vec.resize(2000);
	print_vec(vec);
	std::cout << "------[ EMPTY ]------" << std::endl;
	std::cout << std::boolalpha;
	std::cout << "vec empty ?\t: " << vec.empty() << std::endl;
	std::cout << "vec2 empty ?\t: " << empt.empty() << std::endl;
	std::cout << "=============================" << std::endl << std::endl << std::endl;
}

void	elem_access(void)
{
	NS::vector<std::string>	vec;
	size_t					max_num;

	std::cout << "======> ELEMENT ACCES <======" << std::endl;
	max_num = rand() % (25 + 1 - 10) + 10;
	for (size_t i = 0; i < max_num; i++)
		vec.push_back(rand_str_gen());
	std::cout << "------[ VEC using operator[] ]------" << std::endl;
	for (size_t i = 0; i < vec.size(); i++)
		std::cout << "[" << i << "]\t" << vec[i] << std::endl;
	std::cout << std::endl;
	std::cout << "------[ VEC using at() ]------" << std::endl;
	for (size_t i = 0; i < vec.size(); i++)
		std::cout << "at(" << i << ")\t" << vec.at(i) << std::endl;
	std::cout << std::endl;
	std::cout << "------[ OUT OF BOUNDS ]------" << std::endl;
	try
	{
		std::cout << vec.at(99);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	std::cout << std::endl;
	std::cout << "------[ BACK & FRONT ]------" << std::endl;
	std::cout << "vec.front()\t: " << vec.front() << std::endl;
	std::cout << "vec.back()\t: " << vec.back() << std::endl;
	std::cout << "=============================" << std::endl << std::endl << std::endl;
}

void	assign(void)
{
	NS::vector<std::string>	vec;
	std::list<std::string>	lst;
	size_t					max_num;

	std::cout << "======> ASSIGN <======" << std::endl;
	max_num = rand() % (22 + 1 - 5) + 5;
	for (size_t i = 0; i < max_num; i++)
		lst.push_back(rand_str_gen());
	print_list(lst);
	std::cout << "------[ Range ]------" << std::endl;
	vec.assign(lst.begin(), lst.end());
	print_vec(vec);
	std::cout << "------[ Fill ]------" << std::endl;
	vec.assign(12, "fill");
	print_vec(vec);
	std::cout << "=============================" << std::endl << std::endl << std::endl;
}

void	push_pop(void)
{
	NS::vector<std::string>	vec;
	size_t					max_num;

	std::cout << "======> PUSH & POP BACK <======" << std::endl;
	max_num = rand() % (42 + 1 - 12) + 12;
	for (size_t i = 0; i < max_num; i++)
		vec.push_back(rand_str_gen());
	std::cout << "------[ Push back ]------" << std::endl;
	print_vec(vec);
	std::cout << "------[ Pop back * 7 ]------" << std::endl;
	for (size_t i = 0; i < 7; i++)
		vec.pop_back();
	print_vec(vec);
	std::cout << "------[ Push back * 2 ]------" << std::endl;
	for (size_t i = 0; i < 2; i++)
		vec.push_back(rand_str_gen());
	print_vec(vec);
	std::cout << "=============================" << std::endl << std::endl << std::endl;
}

void	ins_erase(void)
{
	NS::vector<std::string>	vec(5, "init");
	std::list<std::string>	lst;
	size_t					max_num;

	std::cout << "======> INSERT <======" << std::endl;
	max_num = rand() % (12 + 1 - 5) + 5;
	for (size_t i = 0; i < max_num; i++)
		lst.push_back(rand_str_gen());
	std::cout << "------[ Initial Vector ]------" << std::endl;
	print_vec(vec);
	std::cout << "------[ Initial List ]------" << std::endl;
	print_list(lst);
	std::cout << "------[ Single Element (@vec.begin() + 2) ]------" << std::endl;
	vec.insert(vec.begin() + 2, "SINGLE ELEM");
	print_vec(vec);
	std::cout << "------[ Fill (@vec.begin() + 4) ]------" << std::endl;
	vec.insert(vec.begin() + 4, 5, "FILL");
	print_vec(vec);
	std::cout << "------[ Range (@vec.begin() + 1) ]------" << std::endl;
	vec.insert(vec.begin() + 1, lst.begin(), lst.end());
	print_vec(vec);
	std::cout << std::endl;
	std::cout << "======> ERASE <======" << std::endl;
	std::cout << "------[ Single Element (@vec.begin() + 8) ]------" << std::endl;
	vec.erase(vec.begin() + 8);
	print_vec(vec);
	std::cout << "------[ Range (vec.begin() + 2, vec.end() - 5) ]------" << std::endl;
	vec.erase(vec.begin() + 2, vec.end() - 5);
	print_vec(vec);
	std::cout << "------[ Range (begin(), end()) ]------" << std::endl;
	vec.erase(vec.begin(), vec.end());
	print_vec(vec);
	std::cout << "=============================" << std::endl << std::endl << std::endl;
}

int	main(void)
{
	// srand(time(NULL));
	// #ifdef __FT__
	// std::cout << "============> FT <============" << std::endl;
	// #else
	// std::cout << "============> STL <============" << std::endl;
	// #endif

	// copy_contruct();
	// assignation();
	// iterators();
	// capacity();
	// elem_access();
	// assign();
	// push_pop();
	ins_erase();
	return (0);
}
