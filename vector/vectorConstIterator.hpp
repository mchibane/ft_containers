#ifndef VECTOR_CONST_IT_HPP
#define VECTOR_CONST_IT_HPP

// #include "../iteratorTags.hpp"
#include "vector.hpp"
#include "vectorIterator.hpp"
#include <cstddef>
#include <iterator>

namespace ft
{
	template<class T>
	class vectorIterator;

	template<class T>
	class vectorConstIterator
	{
		public:
			typedef const T						value_type;
			typedef const T*					pointer;
			typedef const T&					reference;
			typedef std::ptrdiff_t				difference_type;
			typedef std::random_access_iterator_tag	iterator_category;

		protected:
			pointer	_ptr;

		public:
			vectorConstIterator(void) : _ptr(NULL) {}
			vectorConstIterator(vectorConstIterator const &x) : _ptr(x.getPtr()) {}
			vectorConstIterator(pointer const &ptr) : _ptr(ptr) {}
			vectorConstIterator(ft::vectorIterator<T> const &x) : _ptr(x.getPtr()) {}
			vectorConstIterator	&operator=(vectorConstIterator const &x)
			{
				if (this != &x)
					_ptr = x._ptr;
				return (*this);
			}
			~vectorConstIterator(void) {}

			pointer	getPtr(void) const { return (_ptr); }


			// template<class I>
			bool	operator==(vectorConstIterator<T> const &rhs) const { return (_ptr == rhs.getPtr()); }
			// template<class I>
			bool	operator!=(vectorConstIterator<T> const &rhs) const  { return (!(*this == rhs)); }

			reference	operator*(void) const	{ return (*_ptr); }
			pointer		operator->(void) const	{ return (_ptr); }

			vectorConstIterator	&operator++(void)
			{
				_ptr++;
				return (*this);
			}
			vectorConstIterator	operator++(int)
			{
				return (vectorConstIterator(_ptr++));
			}

			vectorConstIterator	&operator--(void)
			{
				_ptr--;
				return (*this);
			}
			vectorConstIterator	operator--(int)
			{
				return (vectorConstIterator(_ptr--));
			}

			vectorConstIterator	operator+(difference_type n) const
			{
				return (vectorConstIterator(_ptr + n));
			}
			friend vectorConstIterator	operator+(difference_type n, vectorConstIterator const &x)
			{
				return (x.getPtr() + n);
			}

			vectorConstIterator	operator-(difference_type n) const
			{
				return (vectorConstIterator(_ptr - n));
			}
			friend difference_type		operator-(vectorConstIterator const &lhs, vectorConstIterator const &rhs)
			{
				return (lhs.getPtr() - rhs.getPtr());
			}


			// template<class I>
			bool	operator<(vectorConstIterator<T> const &rhs) const
			{
				return (_ptr < rhs.getPtr());
			}
			// template<class I>
			bool	operator>(vectorConstIterator<T> const &rhs) const
			{
				return (rhs < *this);
			}
			// template<class I>
			bool	operator<=(vectorConstIterator<T> const &rhs) const
			{
				return (!(rhs < *this));
			}
			// template<class I>
			bool	operator>=(vectorConstIterator<T> const &rhs) const
			{
				return (!(*this < rhs));
			}


			vectorConstIterator	&operator+=(difference_type const &n)
			{
				_ptr += n;
				return (*this);
			}
			vectorConstIterator	&operator-=(difference_type const &n)
			{
				_ptr -= n;
				return (*this);
			}


			reference	operator[](difference_type const &n) const
			{
				return (_ptr[n]);
			}
	}; // class vectorConstIterator


	/*******************/
	/* NON MEMBER FCTS */
	/*******************/

		/* RELATIONAL OPERATORS */

	template<typename T, typename U>
	bool	operator==( vectorConstIterator<T> const &lhs, vectorConstIterator<U> const &rhs)
	{
		return (lhs.getPtr() == rhs.getPtr());
	}

	template<typename T, typename U>
	bool	operator!=( vectorConstIterator<T> const &lhs, vectorConstIterator<U> const &rhs)
	{
		return (lhs.getPtr() != rhs.getPtr());
	}

	template<typename T, typename U>
	bool operator<( vectorConstIterator<T> const &lhs, vectorConstIterator<U> const &rhs)
	{
		return (lhs.getPtr() < rhs.getPtr());
	}

	template<typename T, typename U>
	bool operator<=( vectorConstIterator<T> const &lhs, vectorConstIterator<U> const &rhs)
	{
		return (lhs.getPtr() <= rhs.getPtr());
	}

	template<typename T, typename U>
	bool	operator>( vectorConstIterator<T> const &lhs, vectorConstIterator<U> const &rhs)
	{
		return (lhs.getPtr() > rhs.getPtr());
	}

	template<typename T, typename U>
	bool	operator>=( vectorConstIterator<T> const &lhs, vectorConstIterator<U> const &rhs)
	{
		return (lhs.getPtr() >= rhs.getPtr());
	}
}; // namespace ft

#endif
