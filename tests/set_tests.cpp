#include "tests.hpp"

namespace ft_set
{
	void	construct(void)
	{
		NS::set<int>	s;
		std::list<int>	lst;
		size_t			max_num;

		std::cout << "======> CONSTRUCTORS <======" << std::endl << std::endl;
		max_num = (rand() % 25) + 1;
		for (size_t i = 0; i < max_num; i++)
		{
			lst.push_back(rand() % 1000);
			s.insert(rand() % 100);
		}
		std::cout << "------[ SET ]------" << std::endl;
		print_set(s);
		{
			NS::set<int>	s2(s);
			std::cout << "------[ SET 2 (COPY) ]------" << std::endl;
			print_set(s2);
		}
		NS::set<int>	range(lst.begin(), lst.end());
		std::cout << "------[ Range ]------" << std::endl;
		print_set(range);
		std::cout << "=============================" << std::endl << std::endl << std::endl;
	}

	void	assignation(void)
	{
		NS::set<int>	s;
		NS::set<int>	s2;
		size_t			max_num;

		max_num = (rand() % 25) + 1;
		std::cout << "======> ASSIGNATION <=====" << std::endl << std::endl;
		for (size_t i = 0; i < 42; i++)
			s.insert(rand() % 100);
		for (size_t i = 0; i < max_num; i++)
			s2.insert(rand() % 100);
		std::cout << "------[ S ]------" << std::endl;
		print_set(s);
		std::cout << "------[ S2 ]------" << std::endl;
		print_set(s2);
		std::cout << "s2 = s" << std::endl;
		s2 = s;
		std::cout << "------[ S2 ]------" << std::endl;
		print_set(s2);
		std::cout << "=============================" << std::endl << std::endl << std::endl;
	}

	void	iterators(void)
	{
		NS::set<int>			s;
		NS::set<int>::iterator	it;
		NS::set<int>::iterator	ite;
		size_t								max_num;

		std::cout << "======> ITERATORS <======" << std::endl << std::endl;
		max_num = rand() % (22 + 1 - 10) + 10;
		for (size_t i = 0; i < max_num; i++)
			s.insert(rand() % 100);
		std::cout << "------[ SET ]------" << std::endl;
		print_set(s);
		it = ++(++(++(s.begin())));
		ite = --(--(s.end()));
		std::cout << "set.begin()\t\t: " << *(s.begin()) << std::endl;
		std::cout << "set.end() - 1\t\t: " << *(--(s.end())) << std::endl;
		std::cout << "it = ++(++(++(s.begin())))\t: " << *it << std::endl;
		it++;
		std::cout << "it++\t\t\t: " << *it << std::endl;
		++it;
		std::cout << "++it\t\t\t: " << *it  << std::endl;
		it--;
		std::cout << "it--\t\t\t: " << *it  << std::endl;
		--it;
		std::cout << "--it\t\t\t: " << *it  << std::endl;
		++(++(++it))++;
		std::cout << "++(++(++it))++\t\t: " << *it  << std::endl;
		--(--it)--;
		std::cout << "--(--it)--\t\t: " << *it  << std::endl;
		std::cout << "ite = --(--(s.end()))\t\t: " << *ite << std::endl;
		std::cout << std::boolalpha;
		std::cout << "ite == it\t\t: " << (ite == it) << std::endl;
		std::cout << "ite != it\t\t: " << (ite != it) << std::endl;
		std::cout << "=============================" << std::endl << std::endl << std::endl;
	}

	void	ins_erase(void)
	{
		typedef NS::set<int>::iterator	s_it;

		NS::set<int>			s;
		NS::pair<s_it, bool>	pret;
		std::list<int>			lst;
		size_t					max_num;

		std::cout << "======> INSERT <======" << std::endl;
		max_num = rand() % (16 + 1 - 8) + 8;
		for (size_t i = 0; i < max_num; i++)
			lst.push_back(rand() % 100);
		std::cout << "------[ Single Element ]------" << std::endl;
		for (size_t i = 0; i < 12; i++)
		{
			pret = s.insert(i + 1);
			std::cout << "[ pret->first (it)] : " << *(pret.first) << std::endl;
			std::cout << std::boolalpha << "[ pret->second (bool) ] : " << pret.second << std::endl;
		}
		std::cout << std::endl;
		std::cout << "------[ Inserting new elems, same key ]------" << std::endl;
		for (size_t i = 5; i < 10; i++)
		{
			pret = s.insert(i + 1);
			std::cout << "[ pret->first (it)] : " << *(pret.first) << std::endl;
			std::cout << std::boolalpha << "[ pret->second (bool) ] : " << pret.second << std::endl;
		}
		std::cout << std::endl;
		std::cout << "------[ Set after single elem insert ]------" << std::endl;
		print_set(s);
		std::cout << "------[ Range ]------" << std::endl;
		std::cout << "------[ Initial list ]------" << std::endl;
		print_list(lst);
		std::cout << "------[ Inserting into set ]------" << std::endl;
		s.insert(lst.begin(), lst.end());
		print_set(s);
		std::cout << "======> ERASE <======" << std::endl;
		std::cout << "------[ Single element (iterator)]------" << std::endl;
		for (size_t i = 0; i < 5; i++)
			s.erase(--(s.end()));
		print_set(s);
		std::cout << "------[ Single element (key) ]------" << std::endl;
		for (size_t i = 4; i <= 10; i++)
			s.erase(i);
		print_set(s);
		std::cout << "------[ Range ]------" << std::endl;
		s.erase(--(--(--(--(s.end())))), --(s.end()));
		print_set(s);
		std::cout << "======> CLEAR <======" << std::endl;
		s.clear();
		print_set(s);
		std::cout << "=============================" << std::endl << std::endl << std::endl;
	}

	void	set_swap(void)
	{
		NS::set<int>	foo;
		NS::set<int>	bar;
		size_t			max_num;

		std::cout << "======> SWAP <======" << std::endl;
		max_num = rand() % (24 + 1 - 10) + 10;
		for (size_t i = 0; i < max_num; i++)
		{
			foo.insert(rand() % 100);
			if (i < 10)
				bar.insert(rand() % 42);
		}
		NS::set<int>::iterator	fooit1 = ++(++(++(++(foo.begin()))));
		NS::set<int>::iterator	fooit2 = --(--(foo.end()));
		NS::set<int>::iterator	barit1 = --(--(--(--(--(--(bar.end()))))));
		NS::set<int>::iterator	barit2 = --(bar.end());
		std::cout << "------[ Inital Sets ]------" << std::endl;
		std::cout << "      [ FOO ]      " << std::endl;
		print_set(foo);
		std::cout << "      [ BAR ]      " << std::endl;
		print_set(bar);
		std::cout << "------[ Pre-Swap iterators ]------" << std::endl;
		std::cout << "fooit1\t: " << *fooit1 << std::endl;
		std::cout << "fooit2\t: " << *fooit2 << std::endl;
		std::cout << "barit1\t: " << *barit1 << std::endl;
		std::cout << "barit2\t: " << *barit2 << std::endl;
		std::cout << std::endl;
		std::cout << "------[ Swap ]------" << std::endl;
		foo.swap(bar);
		std::cout << "      [ FOO ]      " << std::endl;
		print_set(foo);
		std::cout << "      [ BAR ]      " << std::endl;
		print_set(bar);
		std::cout << "------[ Iterator Validity ]------" << std::endl;
		std::cout << "fooit1\t: " << *fooit1 << std::endl;
		std::cout << "fooit2\t: " << *fooit2 << std::endl;
		std::cout << "barit1\t: " << *barit1 << std::endl;
		std::cout << "barit2\t: " << *barit2 << std::endl;
		std::cout << std::endl;
		std::cout << "------[ Non Member Swap ]------" << std::endl;
		std::swap(foo, bar);
		std::cout << "      [ FOO ]      " << std::endl;
		print_set(foo);
		std::cout << "      [ BAR ]      " << std::endl;
		print_set(bar);
		std::cout << "=============================" << std::endl << std::endl << std::endl;
	}

	void	set_find_count(void)
	{
		NS::set<int>	m;
		size_t						max_num;

		std::cout << "======> FIND <======" << std::endl;
		max_num = rand() % (34 + 1 - 12) + 12;
		for (size_t i = 0; i < max_num; i++)
			m.insert(rand() % 100);
		std::cout << "------[ Initial set ]------" << std::endl;
		print_set(m);
		std::cout << "------[ Find ]------" << std::endl;
		for (int i = 0; i < 100; i++)
			s_find(m, i);
		std::cout << std::endl;
		std::cout << "------[ Count ]------" << std::endl;
		for (int i = 0; i < 100; i++)
			s_count(m, i);
		std::cout << std::endl;
		std::cout << "=============================" << std::endl << std::endl << std::endl;
	}

	void	bounds_range(void)
	{
		typedef NS::set<int>::iterator	setit;
		NS::set<int>			s;
		setit					it;
		NS::pair<setit, setit>	eq;

		std::cout << "======> LOWER BOUND <======" << std::endl;
		for (size_t i = 0; i < 8; i++)
			s.insert(i * 3);
		std::cout << "------[ Initial Set ]------" << std::endl;
		print_set(s);
		std::cout << "------[ Lower Bound ]------" << std::endl;
		for (int i = 0; i < 24; i++)
		{
			it = s.lower_bound(i);
			if (it != s.end())
				std::cout << "[" << i << "]\tLower Bound : Key : " << *it << std::endl;
			else
				std::cout << "[" << i << "]\tLower Bound : set.end()" << std::endl;
		}
		std::cout << std::endl;
		std::cout << "------[ Upper Bound ]------" << std::endl;
		for (int i = 0; i < 24; i++)
		{
			it = s.upper_bound(i);
			if (it != s.end())
				std::cout << "[" << i << "]\tUpper Bound : Key : " << *it << std::endl;
			else
				std::cout << "[" << i << "]\tUpper Bound : set.end()" << std::endl;
		}
		std::cout << std::endl;
		std::cout << "------[ Equal Range ]------" << std::endl;
		for (int i = 0; i < 24; i++)
		{
			eq = s.equal_range(i);
			if (eq.first != s.end() && eq.second != s.end())
				std::cout << "[" << i << "]\tEqual Range : Eq.first(Key) : " << *(eq.first) << std::endl;
			else
				std::cout << "[" << i << "]\tRange == 0" << std::endl;
		}
		std::cout << std::endl;
		std::cout << "=============================" << std::endl << std::endl << std::endl;
	}
}
