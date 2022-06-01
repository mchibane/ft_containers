#ifndef TESTS_HPP
#define TESTS_HPP

# ifndef __FT__
#  define NS std
# else
#  define NS ft
# endif

/* VECTOR */
#include "../vector/vector.hpp"
#include <vector>

/* STACK */
#include "../stack/stack.hpp"
#include <stack>

/* MAP */
#include "../map/map.hpp"
#include <map>

/* SET */
#include "../set/set.hpp"
#include <set>

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <list>

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
	std::cout << std::boolalpha << "EMPTY		: " << m.empty() << std::endl;
	for (typename NS::map<T, U>::const_iterator it = m.begin(); it != m.end(); it++)
	{
		std::cout << "[" << i << "]\tKey : [" << it->first << "]\t| Value : " << it->second <<  std::endl;
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

template<class T>
void	print_list(std::list<T> const &lst)
{
	std::cout << "List Content : " << std::endl;
	for (typename std::list<T>::const_iterator it = lst.begin(); it != lst.end(); it++)
		std::cout << *it << std::endl;
	std::cout << std::endl;
}
template<class T, class U>
void	print_list(std::list<NS::pair<T, U> > const &lst)
{
	std::cout << "List Content : " << std::endl;
	for (typename std::list<NS::pair<T, U> >::const_iterator it = lst.begin(); it != lst.end(); it++)
		std::cout << "first : " << it->first << "\tsecond : " << it->second << std::endl;
	std::cout << std::endl;
}

#endif
