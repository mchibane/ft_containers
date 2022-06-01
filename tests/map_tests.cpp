#include "tests.hpp"


void	constructors(void)
{
	std::list<NS::pair< int, std::string> >	lst;
	size_t									max_num;

	std::cout << "======> CONSTRUCTORS <======" << std::endl;
	max_num = rand() % (22 + 1 - 10) + 10;
	for (size_t i = 0; i < max_num; i++)
		lst.push_back(NS::make_pair(rand() % 100, rand_str_gen()));
	std::cout << "------[ Initial list ]------" << std::endl;
	print_list(lst);
	std::cout << "------[ Default Contructor ]------" << std::endl;
	NS::map<int, std::string>	m;
	print_map(m);
	std::cout << "------[ Map Range constructor ]------" << std::endl;
	NS::map<int, std::string>	m1(++(lst.begin()), --(--(lst.end())));
	print_map(m1);
	std::cout << "------[ Map Copy constructor ]------" << std::endl;
	{
		NS::map<int, std::string>	m2(m1);
		print_map(m2);
	}
	std::cout << "=============================" << std::endl << std::endl << std::endl;
}

void	assignation(void)
{
	NS::map<int, std::string>	m1;
	NS::map<int, std::string>	m2;
	size_t			max_num;

	max_num = (rand() % 25) + 1;
	std::cout << "======> ASSIGNATION <=====" << std::endl << std::endl;
	for (size_t i = 0; i < 42; i++)
		m1.insert(NS::make_pair(rand() % 100, rand_str_gen()));
	for (size_t i = 0; i < max_num; i++)
		m2.insert(NS::make_pair(rand() % 100, rand_str_gen()));
	std::cout << "------[ M1 ]------" << std::endl;
	print_map(m1);
	std::cout << "------[ M2 ]------" << std::endl;
	print_map(m2);
	std::cout << "m2 = m1" << std::endl;
	m2 = m1;
	std::cout << "------[ M2 ]------" << std::endl;
	print_map(m2);
	std::cout << "=============================" << std::endl << std::endl << std::endl;
}

void	iterators(void)
{
	NS::map<int, std::string>			m1;
	NS::map<int, std::string>::iterator	it;
	NS::map<int, std::string>::iterator	ite;
	size_t								max_num;

	std::cout << "======> ITERATORS <======" << std::endl << std::endl;
	max_num = rand() % (22 + 1 - 10) + 10;
	for (size_t i = 0; i < max_num; i++)
		m1.insert(NS::make_pair(rand() % 100, rand_str_gen()));
	std::cout << "------[ VEC ]------" << std::endl;
	print_map(m1);
	it = ++(++(++(m1.begin())));
	ite = --(--(m1.end()));
	std::cout << "map.begin()\t\t: " << (m1.begin())->first << " " << m1.begin()->second << std::endl;
	std::cout << "map.end() - 1\t\t: " << (--(m1.end()))->first << " " << (--(m1.end()))->second << std::endl;
	std::cout << "it = ++(++(++(m1.begin())))\t: " << it->first << " " << it->second << std::endl;
	it++;
	std::cout << "it++\t\t\t: " << it->first << " " << it->second << std::endl;
	++it;
	std::cout << "++it\t\t\t: " << it->first << " " << it->second  << std::endl;
	it--;
	std::cout << "it--\t\t\t: " << it->first << " " << it->second  << std::endl;
	--it;
	std::cout << "--it\t\t\t: " << it->first << " " << it->second  << std::endl;
	++(++(++it))++;
	std::cout << "++(++(++it))++\t\t: " << it->first << " " << it->second  << std::endl;
	--(--it)--;
	std::cout << "--(--it)--\t\t: " << it->first << " " << it->second  << std::endl;
	std::cout << "ite = --(--(m1.end()))\t\t: " << ite->first << " " << ite->second << std::endl;
	std::cout << std::boolalpha;
	std::cout << "ite == it\t\t: " << (ite == it) << std::endl;
	std::cout << "ite != it\t\t: " << (ite != it) << std::endl;
	std::cout << "=============================" << std::endl << std::endl << std::endl;
}

int	main(void)
{
	constructors();
	assignation();
	iterators();
	return (0);
}
