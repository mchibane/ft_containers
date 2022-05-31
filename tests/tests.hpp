#ifndef TESTS_HPP
#define TESTS_HPP

# ifndef __FT__
#  define NS std
# else
#  define NS ft
# endif

/* VECTOR */
#include "../vector/vector.hpp"
#include "../vector/vectorIterator.hpp"
#include "../vector/vectorConstIterator.hpp"

#include <vector>

/* STACK */
#include "../stack/stack.hpp"

#include <stack>

/* MAP */
#include "../map/map.hpp"
#include "../map/RBT.hpp"
#include "../map/rbt_iterator.hpp"
#include "../map/rbt_const_iterator.hpp"

#include <map>

/* SET */
#include "../set/set.hpp"

#include <set>

#include <iostream>
#include <cstdlib>
#include <ctime>

char		rand_lo(void);
char		rand_up(void);
std::string	rand_str_gen(void);


template<class T>
void print_vec(NS::vector<T> const &vec)
{
	std::cout << "SIZE     : " << vec.size() << std::endl;
	std::cout << "MAX SIZE : " << vec.max_size() << std::endl;
	std::cout << "CAPACITY : " << vec.capacity() << std::endl;
	for (size_t i = 0; i < vec.size(); i++)
		std::cout << "[" << i << "]\t" << vec[i] << std::endl;
	std::cout << std::endl;
}

template<class T, class U>
void	print_map(NS::map<T, U> const &m)
{
	int i = 0;

	std::cout << "SIZE		: " << m.size() << std::endl;
	std::cout << "MAX SIZE	: " << m.max_size() << std::endl;
	for (typename NS::map<T, U>::const_iterator it = m.begin(); it != m.end(); it++)
	{
		std::cout << "[" << i << "] Key : [" << it->first << "]\t| Value : [" << it->second << "]" << std::endl;
		i++;
	}
	std::cout << std::endl;
}

template<class T>
void	print_stack(NS::stack<T> st)
{
	size_t	i = 0;

	while (!st.empty())
	{
		std::cout << "[" << i << "] : " << st.top() << std::endl;
		i++;
		st.pop();
	}
}

#endif
