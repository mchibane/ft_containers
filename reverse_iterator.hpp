#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP

#include "iteratorTraits.hpp"
#include "vector.hpp"

namespace ft
{
	template<class Iterator>
	class reverse_iterator
	{
	public:
		typedef Iterator								iterator_type;
		typedef typename ft::iterator_traits<Iterator>	traits;
		typedef typename traits::iterator_category		iterator_category;
		typedef typename traits::value_type				value_type;
		typedef typename traits::difference_type		difference_type;
		typedef typename traits::pointer				pointer;
		typedef typename traits::reference				reference;

	private:
		Iterator	_base;

	public:

			/* CONSTRUCTORS AND DESTRUCTORS */

		reverse_iterator(void) : _base(Iterator()) {}
		explicit reverse_iterator(iterator_type it) : _base(it) {}

		template<class Iter>
		reverse_iterator(const reverse_iterator<Iter> &rev_it) : _base(rev_it.base()) {}

		iterator_type	base(void) const { return (_base); }

			/* DEREFERENCE */

		reference	operator*(void) const { Iterator tmp = _base; return (*(--tmp)); }
		pointer		operator->(void) const { return (&operator*()); }


			/* INCREMENTATION */

		reverse_iterator	&operator++(void) { --_base; return (*this); }
		reverse_iterator	operator++(int)
		{
			reverse_iterator	tmp = *this;
			++(*this);
			return (tmp);
		}

		reverse_iterator	&operator--(void) { ++_base; return (*this); }
		reverse_iterator	operator--(int)
		{
			reverse_iterator	tmp = *this;
			--(*this);
			return (tmp);
		}


			/* ELEMENT ACCESS */

		reference	operator[](difference_type n) const
		{
			return (base()[-n - 1]);
		}


			/* COMPOUND ASSIGNMENT */

		reverse_iterator	&operator+=(difference_type n)
		{
			_base -= n;
			return (*this);
		}

		reverse_iterator	&operator-=(difference_type n)
		{
			_base += n;
			return (*this);
		}


			/* ARITHMETICS */

		reverse_iterator	operator+(difference_type n) const
		{
			return (reverse_iterator(_base - n));
		}
		reverse_iterator	operator-(difference_type n) const
		{
			return (reverse_iterator(_base + n));
		}
	}; // class


	/*******************/
	/* NON MEMBER FCTS */
	/*******************/

		/* RELATIONAL OPERATORS */

	template<class T, class U>
	bool	operator==(reverse_iterator<T> const &lhs, reverse_iterator<U> const &rhs)
	{
		return (lhs.base() == rhs.base());
	}

	template<class T, class U>
	bool	operator!=(reverse_iterator<T> const &lhs, reverse_iterator<U> const &rhs)
	{
		return (lhs.base() != rhs.base());
	}

	template<class T, class U>
	bool	operator<(reverse_iterator<T> const &lhs, reverse_iterator<U> const &rhs)
	{
		return (lhs.base() > rhs.base());
	}

	template<class T, class U>
	bool	operator<=(reverse_iterator<T> const &lhs, reverse_iterator<U> const &rhs)
	{
		return (lhs.base() >= rhs.base());
	}

	template<class T, class U>
	bool	operator>(reverse_iterator<T> const &lhs, reverse_iterator<U> const &rhs)
	{
		return (lhs.base() < rhs.base());
	}

	template<class T, class U>
	bool	operator>=(reverse_iterator<T> const &lhs, reverse_iterator<U> const &rhs)
	{
		return (lhs.base() <= rhs.base());
	}


		/* ARITHMETICS */

	template<class Iterator>
	reverse_iterator<Iterator>	operator+(typename reverse_iterator<Iterator>::difference_type n, reverse_iterator<Iterator> const &rev_it)
	{
		return (reverse_iterator<Iterator>(rev_it.base() - n));
	}

	template <class Iterator, class Iterator2>
	typename reverse_iterator<Iterator>::difference_type operator- (reverse_iterator<Iterator> const &lhs, reverse_iterator<Iterator2> const &rhs)
	{
		return (rhs.base() - lhs.base());
	}

}; // namespace ft

#endif
