#ifndef STACK_HPP
#define STACK_HPP

#include "vector/vector.hpp"
#include <stdint.h>

namespace ft
{
	template< class T, class Container = ft::vector<T> >
	class stack
	{
	public:
		typedef T			value_type;
		typedef Container	container_type;
		typedef size_t		size_type;

	private:
		Container	_data;

	public:

		/* CONSTRUCTOR */

		explicit	stack(container_type const &ctnr = container_type()) : _data(ctnr) {}


		/* MEMBER FUNCTS */

		bool		empty(void) const { return (_data.empty()); }

		size_type	size(void) const { return (_data.size()); }

		value_type			&top(void) { return (_data.back()); }
		value_type const	&top(void) const { return (_data.back()); }

		void	push(value_type const &val) { _data.push_back(val); }

		void	pop(void) { _data.pop_back(); }

		friend bool	operator==(stack<T, Container> const &lhs, stack<T, Container> const &rhs) { return (lhs._data == rhs._data); }
		friend bool	operator!=(stack<T, Container> const &lhs, stack<T, Container> const &rhs) { return (lhs._data != rhs._data); }
		friend bool	operator<(stack<T, Container> const &lhs, stack<T, Container> const &rhs) { return (lhs._data < rhs._data); }
		friend bool	operator<=(stack<T, Container> const &lhs, stack<T, Container> const &rhs) { return (lhs._data <= rhs._data); }
		friend bool	operator>(stack<T, Container> const &lhs, stack<T, Container> const &rhs) { return (lhs._data > rhs._data); }
		friend bool	operator>=(stack<T, Container> const &lhs, stack<T, Container> const &rhs) { return (lhs._data >= rhs._data); }

	}; // class stack

}; // namespace ft

#endif
