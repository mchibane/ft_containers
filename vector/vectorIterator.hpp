#ifndef VECTOR_ITERATOR_HPP
#define VECTOR_ITERATOR_HPP

#include "../iteratorTags.hpp"
#include "vector.hpp"
#include "vectorConstIterator.hpp"
#include <cstddef>

namespace ft
{
	template<class T>
	class vectorConstIterator;

	template<class T>
	class vectorIterator
	{
	public:
		typedef T							value_type;
		typedef T*							pointer;
		typedef T&							reference;
		typedef std::ptrdiff_t				difference_type;
		typedef random_access_iterator_tag	iterator_category;

	protected:
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

		pointer	getPtr(void) const { return (_ptr); }

		// template<typename I>
		// operator vectorIterator<const I>(void)
		// {
		// 	return (vectorIterator<const I>(_ptr));
		// }

			/* EQUIVALENCES */

		// template<class I>
		bool	operator==(ft::vectorConstIterator<T> const &rhs) { return (_ptr == rhs.getPtr()); }
		// template<class I>
		bool	operator!=(ft::vectorConstIterator<T> const &rhs) { return (!(*this == rhs)); }


			/* DEREFERENCE */

		reference	operator*(void) const	{return (*_ptr); }
		pointer		operator->(void) const	{return (_ptr); }


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
		friend vectorIterator	operator+(difference_type n, vectorIterator const &x)
		{
			return (x.getPtr() + n);
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

		// template<class I>
		bool	operator<(ft::vectorConstIterator<T> const &rhs) const
		{
			return (_ptr < rhs.getPtr());
		}
		// template<class I>
		bool	operator>(ft::vectorConstIterator<T> const &rhs) const
		{
			return (rhs < *this);
		}
		// template<class I>
		bool	operator<=(ft::vectorConstIterator<T> const &rhs) const
		{
			return (!(rhs < *this));
		}
		// template<class I>
		bool	operator>=(ft::vectorConstIterator<T> const &rhs) const
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
	}; // class


	/*******************/
	/* NON MEMBER FCTS */
	/*******************/

		/* RELATIONAL OPERATORS */

	template<typename T, typename U>
	bool	operator==( ft::vectorConstIterator<T> const &lhs, vectorIterator<U> const &rhs)
	{
		return (lhs.getPtr() == rhs.getPtr());
	}

	template<typename T, typename U>
	bool	operator!=( ft::vectorConstIterator<T> const &lhs, vectorIterator<U> const &rhs)
	{
		return (lhs.getPtr() != rhs.getPtr());
	}

	template<typename T, typename U>
	bool operator<( ft::vectorConstIterator<T> const &lhs, vectorIterator<U> const &rhs)
	{
		return (lhs.getPtr() < rhs.getPtr());
	}

	template<typename T, typename U>
	bool operator<=( ft::vectorConstIterator<T> const &lhs, vectorIterator<U> const &rhs)
	{
		return (lhs.getPtr() <= rhs.getPtr());
	}

	template<typename T, typename U>
	bool	operator>( ft::vectorConstIterator<T> const &lhs, vectorIterator<U> const &rhs)
	{
		return (lhs.getPtr() > rhs.getPtr());
	}

	template<typename T, typename U>
	bool	operator>=( ft::vectorConstIterator<T> const &lhs, vectorIterator<U> const &rhs)
	{
		return (lhs.getPtr() >= rhs.getPtr());
	}


}; //namespace ft

#endif
