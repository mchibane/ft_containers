#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <memory>

#include <iostream>

namespace	ft
{
	template< class T, class Allocator = std::allocator<T> >
	class vector
	{
	private:
		typedef T											value_type;
		typedef	Allocator									allocator_type;
		typedef typename allocator_type::reference			reference;
		typedef typename allocator_type::const_reference	const_reference;
		typedef typename allocator_type::pointer			pointer;
		typedef typename allocator_type::const_pointer		const_pointer;
		typedef typename allocator_type::difference_type	difference_type;
		typedef	typename allocator_type::size_type			size_type;

		allocator_type	_alloc;
		pointer			_ptr;
		const_pointer	_const_ptr;
		reference		_ref;
		const_reference	_const_ref;
		difference_type	_diff_type;
		size_type		_capacity;
		size_type		_size;

	public:

		/* CONSTRUCTORS & DESTRUCTOR */

		explicit vector(const allocator_type &alloc = allocator_type()) :
					_alloc(alloc),
					_ptr(_alloc.allocate(0)),
					_const_ptr(_ptr),
					_ref(*_ptr),
					_const_ref(_ref),
					_capacity(0),
					_size(0)
		{
			_alloc.construct(_ptr, 0);
		}

		explicit vector(size_type n, const value_type &val = value_type(), const allocator_type &alloc = allocator_type()) :
				_alloc(alloc),
				_ptr(_alloc.allocate(n)),
				_const_ptr(_ptr),
				_ref(*_ptr),
				_const_ref(_ref),
				_capacity(n),
				_size(n)
		{
			for (size_type i = 0; i < n; i++)
				_alloc.construct(_ptr + i, val);
		}

		~vector(void)
		{
			_alloc.deallocate(_ptr, _capacity);
		}


		/* CAPACITY */

		size_type		size(void) const { return (_size); }
		size_type		max_size(void) const { return (_alloc.max_size()); }
		size_type		capacity(void) const { return (_capacity); }
		bool			empty(void) const { return (_size == 0); }


		/* ELEMENT ACCESS */

		reference		operator[](size_type n)			{ return (*(_ptr + n)); }
		const_reference operator[](size_type n) const	{ return (*(_const_ptr + n)) ; }


		/* MODIFIERS */

		void	pop_back(void) {_alloc.destroy(_ptr + _size); _size--; }


		/* ALLOCATOR */

		allocator_type	get_allocator(void) const { return (_alloc); }
	};
}



#endif
