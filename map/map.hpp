#ifndef MAP_HPP
#define MAP_HPP

#include <functional>
#include <cstddef>
#include "../pair.hpp"
#include "rbt_iterator.hpp"
#include "rbt_const_iterator.hpp"
#include "RBT.hpp"

#include <iostream>

namespace ft
{
	template< class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator< ft::pair<const Key, T> > >
	class map
	{
		public:
			typedef Key												key_type;
			typedef T												mapped_type;
			typedef typename ft::pair<const key_type, mapped_type>	value_type;
			typedef std::size_t										size_type;
			typedef std::ptrdiff_t									difference_type;
			typedef Compare											key_compare;
			typedef Alloc											allocator_type;
			typedef typename allocator_type::reference				reference;
			typedef typename allocator_type::const_reference		const_reference;
			typedef typename allocator_type::pointer				pointer;
			typedef typename allocator_type::const_pointer			const_pointer;

			class value_compare : public std::binary_function<value_type, value_type, bool>
			{
				friend class map;
				protected:
					Compare	comp;

					value_compare(Compare c) : comp(c) {}
				public:
					typedef bool		result_type;
					typedef value_type	first_argument_type;
					typedef value_type	second_argument_type;
					value_compare() : comp() {}
					bool	operator()(value_type const &x, value_type const &y) const { return (comp(x.first, y.first)); }
			}; // class value_compare

			typedef typename ft::rbt_iterator<value_type, value_compare>			iterator;
			typedef typename ft::rbt_const_iterator<value_type, value_compare>		const_iterator;

		protected:
			allocator_type										_alloc;
			RBT< value_type, value_compare, allocator_type >	_tree;
			size_type											_size;
			key_compare											_comp;

		public:
			explicit map(key_compare const &comp = key_compare(), allocator_type const &alloc = allocator_type()) :
					_alloc(alloc),
					_tree(RBT<value_type, value_compare, allocator_type>()),
					_size(0),
					_comp(comp) {}

			~map(void) {}

			void	insert(value_type const &x) { _tree.insert(x); }

			iterator		begin(void) { return (iterator(_tree, _tree.minimum(_tree.root()))); }
			const_iterator	begin(void) const { return (const_iterator(_tree, _tree.minimum(_tree.root()))); }

			iterator		end(void) { return (iterator(_tree, _tree.sentinel())); }
			const_iterator	end(void) const { return (const_iterator(_tree, _tree.sentinel())); }

	}; // class map
}; //namespace ft

#endif
