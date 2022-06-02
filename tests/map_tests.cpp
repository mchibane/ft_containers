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

void	elem_acces(void)
{
	NS::map<int, std::string>	m;
	size_t						max_num;

	std::cout << "======> ELEMENT ACCESS <======" << std::endl;
	max_num = rand() %(17 + 1 - 10) + 10;
	for (size_t i = 0; i < max_num; i++)
		m.insert(NS::make_pair(i + 1, rand_str_gen()));
	std::cout << "------[ Initial map ]------" << std::endl;
	print_map(m);
	std::cout << "------[ Element access (Read) ]------" << std::endl;
	for (size_t i = 0; i < 8; i++)
		std::cout << "Key : " << i + 1 << " Value : " << m[i + 1] << std::endl;
	std::cout << "------[ Inexistent Key ]------" << std::endl;
	std::cout << m[0] << " <-- m[0]" << std::endl;
	std::cout << m[22] <<" <---m[22]" << std::endl;
	print_map(m);
	std::cout << "------[ Assign value ]------" << std::endl;
	for (size_t i = 4; i < 9; i++)
		m[i] = "Assign to already existing value";
	for (size_t i = 45; i < 55; i++)
		m[i] = "Assign new value";
	print_map(m);
	std::cout << "=============================" << std::endl << std::endl << std::endl;
}

void	ins_erase(void)
{
	typedef NS::map<int, std::string>::iterator	m_it;

	NS::map<int, std::string>				m;
	NS::pair<m_it, bool>					pret;
	std::list<NS::pair<int, std::string> >	lst;
	size_t									max_num;

	std::cout << "======> INSERT <======" << std::endl;
	max_num = rand() % (16 + 1 - 8) + 8;
	for (size_t i = 0; i < max_num; i++)
		lst.push_back(NS::make_pair(rand() % 100, rand_str_gen()));
	std::cout << "------[ Single Element ]------" << std::endl;
	for (size_t i = 0; i < 12; i++)
	{
		pret = m.insert(NS::make_pair(i + 1, rand_str_gen()));
		std::cout << "[ pret->first (it)]-> first (key) : " << pret.first->first << "\tsecond (value) : " << pret.first->second << std::endl;
		std::cout << std::boolalpha << "[ pret->second (bool) ] : " << pret.second << std::endl;
	}
	std::cout << std::endl;
	std::cout << "------[ Inserting new elems, same key ]------" << std::endl;
	for (size_t i = 5; i < 10; i++)
	{
		pret = m.insert(NS::make_pair(i + 1, rand_str_gen()));
		std::cout << "[ pret->first (it)]-> first (key) : " << pret.first->first << "\tsecond (value) : " << pret.first->second << std::endl;
		std::cout << std::boolalpha << "[ pret->second (bool) ] : " << pret.second << std::endl;
	}
	std::cout << std::endl;
	std::cout << "------[ Map after single elem insert ]------" << std::endl;
	print_map(m);
	std::cout << "------[ Range ]------" << std::endl;
	std::cout << "------[ Initial list ]------" << std::endl;
	print_list(lst);
	std::cout << "------[ Inserting into map ]------" << std::endl;
	m.insert(lst.begin(), lst.end());
	print_map(m);
	std::cout << "======> ERASE <======" << std::endl;
	std::cout << "------[ Single element (iterator)]------" << std::endl;
	for (size_t i = 0; i < 5; i++)
		m.erase(--(m.end()));
	print_map(m);
	std::cout << "------[ Single element (key) ]------" << std::endl;
	for (size_t i = 4; i <= 10; i++)
		m.erase(i);
	print_map(m);
	std::cout << "------[ Range ]------" << std::endl;
	m.erase(--(--(--(--(m.end())))), --(m.end()));
	print_map(m);
	std::cout << "======> CLEAR <======" << std::endl;
	m.clear();
	print_map(m);
	std::cout << "=============================" << std::endl << std::endl << std::endl;
}

void	map_swap(void)
{
	typedef NS::map<int, std::string>::iterator	map_it;

	NS::map<int, std::string>	foo;
	NS::map<int, std::string>	bar;
	size_t						max_num;

	std::cout << "======> SWAP <======" << std::endl;
	max_num = rand() % (32 + 1 - 12) + 12;
	for (size_t i = 0; i < max_num; i++)
	{
		if (i < 10)
			foo.insert(NS::make_pair(rand() %100, rand_str_gen()));
		bar.insert(NS::make_pair(rand() % 1000, rand_str_gen()));
	}
	map_it	fooit1 = ++(++(++(++(foo.begin()))));
	map_it	fooit2 = --(--(foo.end()));
	map_it	barit1 = --(--(--(--(--(--(bar.end()))))));
	map_it	barit2 = --(bar.end());
	std::cout << "------[ Initial Maps ]------" << std::endl;
	std::cout << "      [ FOO ]      " << std::endl;
	print_map(foo);
	std::cout << "      [ BAR ]      " << std::endl;
	print_map(bar);
	std::cout << "------[ Pre-Swap iterators ]------" << std::endl;
	std::cout << "fooit1->first : " << fooit1->first << "\tfooit1->second : " << fooit1->second << std::endl;
	std::cout << "fooit2->first : " << fooit2->first << "\tfooit2->second : " << fooit2->second << std::endl;
	std::cout << "barit1->first : " << barit1->first << "\tbarit1->second : " << barit1->second << std::endl;
	std::cout << "barit2->first : " << barit2->first << "\tbarit2->second : " << barit2->second << std::endl;
	std::cout << std::endl;
	std::cout << "------[ Swap ]------" << std::endl;
	foo.swap(bar);
	std::cout << "      [ FOO ]      " << std::endl;
	print_map(foo);
	std::cout << "      [ BAR ]      " << std::endl;
	print_map(bar);
	std::cout << "------[ Iterator Validity ]------" << std::endl;
	std::cout << "fooit1->first : " << fooit1->first << "\tfooit1->second : " << fooit1->second << std::endl;
	std::cout << "fooit2->first : " << fooit2->first << "\tfooit2->second : " << fooit2->second << std::endl;
	std::cout << "barit1->first : " << barit1->first << "\tbarit1->second : " << barit1->second << std::endl;
	std::cout << "barit2->first : " << barit2->first << "\tbarit2->second : " << barit2->second << std::endl;
	std::cout << std::endl;
	std::cout << "------[ Non Member Swap ]------" << std::endl;
	std::swap(foo, bar);
	std::cout << "      [ FOO ]      " << std::endl;
	print_map(foo);
	std::cout << "      [ BAR ]      " << std::endl;
	print_map(bar);
	std::cout << "=============================" << std::endl << std::endl << std::endl;
}

void	map_find_count(void)
{
	NS::map<int, std::string>	m;
	size_t						max_num;

	std::cout << "======> FIND <======" << std::endl;
	max_num = rand() % (34 + 1 - 12) + 12;
	for (size_t i = 0; i < max_num; i++)
		m.insert(NS::make_pair(rand() % 100, rand_str_gen()));
	std::cout << "------[ Initial map ]------" << std::endl;
	print_map(m);
	std::cout << "------[ Find ]------" << std::endl;
	for (int i = 0; i < 100; i++)
		m_find(m, i);
	std::cout << "------[ Find (const) ]------" << std::endl;
	for (int i = 0; i < 100; i++)
		m_find_const(m, i);
	std::cout << "------[ Count ]------" << std::endl;
	for (int i = 0; i < 100; i++)
		m_count(m, i);
	std::cout << "=============================" << std::endl << std::endl << std::endl;
}

void	bounds_range(void)
{
	typedef NS::map<int, std::string>::iterator	mapit;
	NS::map<int, std::string>	m;
	mapit						it;
	NS::pair<mapit, mapit>		eq;

	std::cout << "======> LOWER BOUND <======" << std::endl;
	for (size_t i = 0; i < 8; i++)
		m.insert(NS::make_pair(i * 3, rand_str_gen()));
	std::cout << "------[ Initial Map ]------" << std::endl;
	print_map(m);
	std::cout << "------[ Lower Bound ]------" << std::endl;
	for (int i = 0; i < 24; i++)
	{
		it = m.lower_bound(i);
		if (it != m.end())
			std::cout << "[" << i << "]\tLower Bound : Key : " << it->first << "\tValue : " << it->second << std::endl;
		else
			std::cout << "[" << i << "]\tLower Bound : map.end()" << std::endl;
	}
	std::cout << std::endl;
	std::cout << "------[ Upper Bound ]------" << std::endl;
	for (int i = 0; i < 24; i++)
	{
		it = m.upper_bound(i);
		if (it != m.end())
			std::cout << "[" << i << "]\tUpper Bound : Key : " << it->first << "\tValue : " << it->second << std::endl;
		else
			std::cout << "[" << i << "]\tUpper Bound : map.end()" << std::endl;
	}
	std::cout << std::endl;
	std::cout << "------[ Equal Range ]------" << std::endl;
	for (int i = 0; i < 24; i++)
	{
		eq = m.equal_range(i);
		if (eq.first != m.end() && eq.second != m.end())
			std::cout << "[" << i << "]\tEqual Range : Eq.first(Key) : " << eq.first->first << " Eq.second(Key) : " << eq.second->first << std::endl;
		else
			std::cout << "[" << i << "]\tRange == 0" << std::endl;
	}
	std::cout << std::endl;
}

int	main(void)
{
	srand(42);
	constructors();
	assignation();
	iterators();
	elem_acces();
	ins_erase();
	map_swap();
	map_find_count();
	bounds_range();
	return (0);
}
