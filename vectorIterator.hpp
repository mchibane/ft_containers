#ifndef VECTOR_ITERATOR_HPP
#define VECTOR_ITERATOR_HPP

#include "iteratorTags.hpp"
#include <cstddef>

namespace ft
{
	template<class T>
	class vectorIterator
	{
	public:
		typedef T							value_type;
		typedef T*							pointer;
		typedef T&							reference;
		typedef std::ptrdiff_t				difference_type;
		typedef random_access_iterator_tag	iterator_category;

	private:
		pointer	_ptr;

	public:
			/* CONSTRUCTORS, DESTRUCTOR & COPY OPERATOR */

		vectorIterator(void) : _ptr(NULL) {}
		vectorIterator(vectorIterator const &x) : _ptr(x._ptr) {}
		vectorIterator	&operator=(vectorIterator const &rhs)
		{
			_ptr = rhs._ptr;
			return (*this);
		}
		~vectorIterator(void) {}


			/* EQUIVALENCES */

		template<class I>
		bool	operator==(vectorIterator<I> const &rhs) { return (_ptr == rhs._ptr); }
		template<class I>
		bool	operator!=(vectorIterator<I> const &rhs) { return (!(*this == rhs)); }


			/* DEREFERENCE */

		reference	operator*(void) const	{return (*_ptr); }
		vectorIterator		operator->(void) const	{return (_ptr); }


			/* INCREMENTATION */

		vectorIterator	&operator++(void)
		{
			_ptr++;
			return (*this);
		}
	};
};

#endif
