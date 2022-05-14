#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <memory>
#include <stdexcept>
#include "vectorIterator.hpp"
#include "isIntegral.hpp"
#include "enableIf.hpp"

#include <iostream>
#include <vector>

namespace	ft
{
	template< class T, class Allocator = std::allocator<T> >
	class vector
	{
	public:
		typedef T											value_type;
		typedef Allocator									allocator_type;
		typedef typename allocator_type::reference			reference;
		typedef typename allocator_type::const_reference	const_reference;
		typedef typename allocator_type::pointer			pointer;
		typedef typename allocator_type::const_pointer		const_pointer;
		typedef typename allocator_type::difference_type	difference_type;
		typedef typename allocator_type::size_type			size_type;

		typedef typename std::vector<T>::iterator			iterator;
		typedef typename std::vector<T>::const_iterator		const_iterator;
		typedef typename std::vector<T>::reverse_iterator	reverse_iterator;
		typedef typename std::vector<T>::const_reverse_iterator	const_reverse_iterator;

	private:
		allocator_type	_alloc;
		pointer			_ptr;
		size_type		_capacity;
		size_type		_size;

	public:

			/* CONSTRUCTORS & DESTRUCTOR */

		// DEFAULT
		explicit vector(const allocator_type &alloc = allocator_type()) :
					_alloc(alloc),
					_ptr(NULL),
					_capacity(0),
					_size(0)
		{}

		// FILL
		explicit vector(size_type n, const value_type &val = value_type(), const allocator_type &alloc = allocator_type()) :
				_alloc(alloc),
				_ptr(_alloc.allocate(n)),
				_capacity(n),
				_size(n)
		{
			for (size_type i = 0; i < n; i++)
				_alloc.construct(_ptr + i, val);
		}

		// RANGE
		template<class InputIterator>
		vector(InputIterator first, InputIterator last, allocator_type const &alloc = allocator_type(), typename ft::enable_if< !ft::is_integral< InputIterator >::value >::type * = 0) :
				_alloc(alloc)
		{
			size_type		n = 0;

			for (InputIterator tmp = first; tmp != last; tmp++)
				n++;
			_size = n;
			_capacity = n;
			_ptr = _alloc.allocate(n);
			for (size_type i = 0; i < n; i++)
			{
				_alloc.construct(_ptr + i, *first);
				first++;
			}
		}

		// COPY
		vector(vector const &x) :
				_alloc(x._alloc),
				_ptr(_alloc.allocate(x._size)),
				_capacity(x.size()),
				_size(x.size())
		{
			for (size_type i = 0; i < x.size(); i++)
				_alloc.construct(_ptr + i, *(x._ptr + i));
		}

		// DESTRUCTOR
		~vector(void)
		{
			for (size_type i = 0; i < _size; i++)
				_alloc.destroy(_ptr + i);
			_alloc.deallocate(_ptr, _capacity);
		}

		vector	&operator=(vector const &rhs)
		{
			if (this != &rhs)
			{
				this->clear();
				_alloc.deallocate(_ptr, _capacity);
				_ptr = _alloc.allocate(rhs.capacity());
				_size = rhs.size();
				_capacity = rhs.capacity();
				for (size_type i = 0; i < rhs._size; i++)
					_alloc.construct(_ptr + i, *(rhs._ptr + i));
			}
			return (*this);
		}


			/* ITERATORS */

		iterator				begin(void)			{ return (iterator(_ptr)); }
		const_iterator			begin(void) const	{ return (iterator(_ptr)); }

		iterator				end(void)			{ return (iterator(_ptr + _size)); }
		const_iterator			end(void) const		{ return (iterator(_ptr + _size)); }

		reverse_iterator		rbegin(void)		{ return (reverse_iterator(this->end())); }
		const_reverse_iterator	rbegin(void) const	{ return (reverse_iterator(this->end())); }

		reverse_iterator		rend(void)			{ return (reverse_iterator(iterator(this->begin()))); }
		const_reverse_iterator	rend(void) const	{ return (reverse_iterator(iterator(this->begin()))); }

			/* CAPACITY */

		size_type		size(void) const		{ return (_size); }
		size_type		max_size(void) const	{ return (_alloc.max_size()); }
		void			resize(size_type n, value_type val = value_type())
		{
			if (n < _size)
			{
				for (size_type i = n; i < _size; i++)
					_alloc.destroy(_ptr + i);
			}
			if (n > _size)
			{
				if (n > _capacity)
					reserve(n);
				for (size_type i = _size; i < n; i++)
					_alloc.construct(_ptr + i, val);
			}
			_size = n;
		}
		size_type		capacity(void) const	{ return (_capacity); }
		bool			empty(void) const		{ return (_size == 0); }
		void			reserve(size_type n)
		{
			pointer	tmp;

			if (n > max_size())
				throw (std::length_error("Length error: ft::vector: reserve request is too large"));
			if (n <= _capacity)
				return ;
			tmp = _ptr;
			_ptr = _alloc.allocate(n);
			for (size_type i = 0; i < _size; i++)
			{
				_alloc.construct(_ptr + i, *(tmp + i));
				_alloc.destroy(tmp + i);
			}
			_alloc.deallocate(tmp, _capacity);
			_capacity = n;
		}


			/* ELEMENT ACCESS */

		reference		operator[](size_type n)			{ return (*(_ptr + n)); }
		const_reference operator[](size_type n) const	{ return (*(_ptr + n)) ; }

		reference		at(size_type n)
		{
			if (n >= _size)
				throw(std::out_of_range("ft::vector: Out of Range error"));
			return (*(_ptr + n));
		}
		const_reference	at(size_type n) const
		{
			if (n >= _size)
				throw(std::out_of_range("ft::vector: Out of Range error"));
			return (*(_ptr + n));
		}

		reference		front(void)			{ return (*_ptr); }
		const_reference	front(void) const	{ return (*_ptr); }

		reference		back(void)			{ return (*(_ptr + (_size - 1))); }
		const_reference	back(void) const	{ return (*(_ptr + (_size - 1))); }

			/* MODIFIERS */

		// RANGE
		template<class InputIterator>
		void		assign(InputIterator first, InputIterator last, typename ft::enable_if< !ft::is_integral< InputIterator >::value >::type * = 0)
		{
			size_type	n = 0;

			for (InputIterator tmp = first; tmp != last; tmp++)
				n++;
			if (n > _capacity)
				reserve(n);
			for (size_type i = 0; i < n; i++)
			{
				_alloc.construct(_ptr + i, *first);
				first++;
			}
			_size = n;
		}

		// FILL
		void		assign(size_type n, value_type const &val)
		{
			if (n > _capacity)
				reserve(n);
			for (size_type i = 0; i < n; i++)
				_alloc.construct(_ptr + i, val);
			_size = n;
		}

		void		push_back(value_type const &val)
		{
			if (_capacity == 0)
				reserve(1);
			else if (_size == _capacity)
				reserve(_size * 2);
			_alloc.construct(_ptr + _size, val);
			_size++;
		}

		void		pop_back(void)
		{
			if (_size == 0)
				return ;
			_alloc.destroy(_ptr + (_size - 1));
			_size--;
		}

		// SINGLE ELEMENT
		iterator	insert(iterator position, value_type const &val)
		{
			size_type	pos = 0;

			for(iterator it = begin(); it != position; it++)
				pos++;
			if (_capacity == 0)
			{
				push_back(val);
				return (iterator(_ptr));
			}
			else if (_size == _capacity)
				reserve(_size * 2);
			for (size_type i = _size; i >= pos; i--)
			{
				if (i == pos)
				{
					_alloc.destroy(_ptr + i);
					_alloc.construct(_ptr + i, val);
				}
				else
				{
					_alloc.construct(_ptr + i, *(_ptr + (i - 1)));
					_alloc.destroy(_ptr + (i - 1));
				}
			}
			_size++;
			return (iterator(_ptr + pos));
		}

		// FILL
		void		insert(iterator position, size_type n, value_type const &val)
		{
			size_type	start = 0;
			size_type	end = 0;

			for (iterator it = begin(); it != position; it++)
				start++;
			end = start + n;
			if (capacity() == 0)
				reserve(1);
			else if ((_size + n) > capacity())
			{
				if (max_size() - _size >= _size && n <= _size)
					reserve(_size * 2);
				else
					reserve(_size + n);
			}
			for (size_type i = (_size + n) - 1; i >= start; i--)
			{
				if (i < end)
				{
					_alloc.destroy(_ptr + i);
					_alloc.construct(_ptr + i, val);
				}
				else
				{
					_alloc.construct(_ptr + i, *(_ptr + (i - n)));
					_alloc.destroy(_ptr + (i - n));
				}
			}
			_size += n;
		}

		iterator	erase(iterator position)
		{
			for (iterator tmp = position; tmp + 1 != end(); tmp ++)
				*tmp = *(tmp + 1);
			_size--;
			return (iterator(position));
		}

		iterator	erase(iterator first, iterator last)
		{
			size_type	n = 0;
			iterator	ret = first;

			for (iterator tmp = first; tmp != last; tmp++)
			{
				n++;
				_size--;
			}
			for (size_type i = 0; i < _size - n; i++)
			{
				*first = *last;
				first++;
				last++;
			}
			return (iterator(ret));
		}

		void		clear(void)
		{
			for (size_type i = 0; i < _size; i++)
				_alloc.destroy(_ptr + i);
			_size = 0;
		}


			/* ALLOCATOR */

		allocator_type	get_allocator(void) const { return (_alloc); }
	};
}



#endif
