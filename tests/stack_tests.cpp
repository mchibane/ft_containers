#include "tests.hpp"

namespace ft_stack
{
	void	constructor(void)
	{
		NS::stack<int>	st;
		NS::stack<int>	st2;

		std::cout << "======> CONSTRUCTORS <======" << std::endl;
		for (size_t i = 0; i < 12; i++)
			st.push(i * 2);
		st2 = st;
		NS::stack<int>	st3(st);
		std::cout << "------[ Default Stacks ]------" << std::endl;
		print_stack(st);
		print_stack(st2);
		print_stack(st3);
		std::cout << "------[ Deque Stacks ]-------" << std::endl;

		NS::stack<int, std::deque<int> >	ds;
		NS::stack<int, std::deque<int> >	ds2;
		for (size_t i = 0; i < 22; i++)
			ds.push(rand() % 100);
		ds2 = ds;
		print_stack(ds);
		print_stack(ds2);
		std::cout << "------[ List Stack ]------" << std::endl;
		NS::stack<std::string, std::list<std::string> >	ls;
		NS::stack<std::string, std::list<std::string> >	ls2;
		for (size_t i = 0; i < 9; i++)
			ls.push(rand_str_gen());
		ls2 = ls;
		print_stack(ls);
		print_stack(ls2);
		std::cout << "=============================" << std::endl << std::endl << std::endl;
	}

	void	push_pop(void)
	{
		NS::stack<std::string>	st;
		size_t					max_num;

		std::cout << "======> PUSH POP TOP <======" << std::endl;
		max_num = rand() % (12 + 1 - 5) + 5;
		for (size_t i = 0; i < max_num; i++)
			st.push(rand_str_gen());
		std::cout << "------[ Initial Stack ]------" << std::endl;
		print_stack(st);
		std::cout << "------[ Push * 7 ]------" << std::endl;
		for (size_t i = 0; i < 7; i++)
			st.push(rand_str_gen());
		print_stack(st);
		std::cout << "------[ Pop * 9 ]------" << std::endl;
		for (size_t i = 0; i < 9; i++)
			st.pop();
		print_stack(st);
		std::cout << "------[ Top ]------"  << std::endl;
		std::cout << "Filled stack : " << st.top() << std::endl << std::endl;
		std::cout << "------[ Empty ]------" << std::endl;
		NS::stack<int>	emp;
		print_stack(emp);
		std::cout << "=============================" << std::endl << std::endl << std::endl;
	}
}
