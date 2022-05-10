#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <memory>
#include <stdexcept>

#include <iostream>

namespace	ft
{
	template< class T, class Allocator = std::allocator<T> >
	class vector
	{
	public:
		typedef T											value_type;
		typedef	Allocator									allocator_type;
		typedef typename allocator_type::reference			reference;
		typedef typename allocator_type::const_reference	const_reference;
		typedef typename allocator_type::pointer			pointer;
		typedef typename allocator_type::const_pointer		const_pointer;
		typedef typename allocator_type::difference_type	difference_type;
		typedef	typename allocator_type::size_type			size_type;

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
					_ptr(_alloc.allocate(1)),
					_capacity(1),
					_size(0)
		{
			_alloc.construct(_ptr, value_type());
		}

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

		// COPY
		vector(vector const &x) :
				_alloc(x._alloc),
				_ptr(_alloc.allocate(x._capacity)),
				_capacity(x.capacity()),
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


			/* MODIFIERS */

		void	push_back(value_type const &val)
		{
			if (_size == _capacity)
				reserve(_size * 2);
			_alloc.construct(_ptr + _size, val);
			_size++;
		}
		void	pop_back(void)
		{
			if (_size == 0)
				return ;
			_alloc.destroy(_ptr + (_size - 1));
			_size--;
		}
		void	clear(void)
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
