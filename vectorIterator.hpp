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
		vectorIterator(pointer const &ptr) : _ptr(ptr) {}
		vectorIterator	&operator=(vectorIterator const &rhs)
		{
			if (this != &rhs)
				_ptr = rhs._ptr;
			return (*this);
		}
		~vectorIterator(void) {}

		template<typename I>
		operator vectorIterator<const I>(void)
		{
			return (vectorIterator<const I>(_ptr));
		}

			/* EQUIVALENCES */

		template<class I>
		bool	operator==(vectorIterator<I> const &rhs) { return (_ptr == rhs._ptr); }
		template<class I>
		bool	operator!=(vectorIterator<I> const &rhs) { return (!(*this == rhs)); }


			/* DEREFERENCE */

		reference			operator*(void) const	{return (*_ptr); }
		vectorIterator		operator->(void) const	{return (_ptr); }


			/* INCREMENTATION & DECREMENTATION */

		vectorIterator	&operator++(void)
		{
			_ptr++;
			return (*this);
		}
		vectorIterator	operator++(int)
		{
			return (vectorIterator(_ptr++));
		}

		vectorIterator	&operator--(void)
		{
			_ptr--;
			return (*this);
		}
		vectorIterator	operator--(int)
		{
			return (vectorIterator(_ptr--));
		}


			/* ARITHMETIC */

		vectorIterator	operator+(difference_type n) const
		{
			return (vectorIterator(_ptr + n));
		}

		vectorIterator	operator-(difference_type n) const
		{
			return (vectorIterator(_ptr - n));
		}
		difference_type	operator-(vectorIterator const &x) const
		{
			return (_ptr - x._ptr);
		}


			/* INEQUALITY */

		template<typename I>
		bool	operator<(vectorIterator<I> const &rhs)
		{
			return (_ptr < rhs._ptr);
		}
		template<typename I>
		bool	operator>(vectorIterator<I> const &rhs)
		{
			return (rhs < *this);
		}
		template<typename I>
		bool	operator<=(vectorIterator<I> const &rhs)
		{
			return (!(rhs < *this));
		}
		template<typename I>
		bool	operator>=(vectorIterator<I> const &rhs)
		{
			return (!(*this < rhs));
		}


			/* COMPOUND ASSIGNMENT */

		vectorIterator &operator+=(difference_type const &n)
		{
			_ptr += n;
			return (*this);
		}

		vectorIterator	&operator-=(difference_type const &n)
		{
			_ptr -= n;
			return (*this);
		}


		reference	operator[](difference_type const &n) const
		{
			return (_ptr[n]);
		}
	};
};

#endif
