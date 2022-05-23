#ifndef MAP_HPP
#define MAP_HPP

#include <functional>
#include <cstddef>
#include "../pair.hpp"
#include "../reverse_iterator.hpp"
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
			typedef typename ft::reverse_iterator<iterator>							reverse_iterator;
			typedef typename ft::reverse_iterator<const_iterator>					const_reverse_iterator;

		protected:
			typedef typename ft::RBT< value_type, value_compare, allocator_type>	tree_type;
			typedef typename tree_type::nodeptr										nodeptr;

			allocator_type										_alloc;
			tree_type											_tree;
			size_type											_size;
			key_compare											_comp;

		public:

				/* CONSTRUCTORS & DESTRUCTORS */

			explicit map(key_compare const &comp = key_compare(), allocator_type const &alloc = allocator_type()) :
					_alloc(alloc),
					_tree(RBT<value_type, value_compare, allocator_type>()),
					_size(0),
					_comp(comp) {}

			template<class InputIterator>
			map(InputIterator first, InputIterator last, key_compare const &comp = key_compare(), allocator_type const &alloc = allocator_type()) :
					_alloc(alloc),
					_tree(tree_type()),
					_size(0),
					_comp(comp)
			{
				insert(first, last);
			}

			map(map const &x) :
					_alloc(x.get_allocator()),
					_tree(tree_type()),
					_size(0),
					_comp(x._comp)
			{
				insert(x.begin(), x.end());
			}

			~map(void) {}

			map	&operator=(map const &x)
			{
				if (this != &x)
				{
					clear();
					insert(x.begin(), x.end());
				}
				return (*this);
			}

				/* ITERATORS */

			iterator				begin(void)			{ return (iterator(&_tree, _tree.minimum(_tree.root()))); }
			const_iterator			begin(void) const	{ return (const_iterator(&_tree, _tree.minimum(_tree.root()))); }

			iterator				end(void)			{ return (iterator(&_tree, _tree.sentinel())); }
			const_iterator			end(void) const		{ return (const_iterator(&_tree, _tree.sentinel())); }

			reverse_iterator		rbegin(void)		{ return (reverse_iterator(end())); }
			const_reverse_iterator	rbegin(void) const	{ return (const_reverse_iterator(end())); }

			reverse_iterator		rend(void)			{ return (reverse_iterator(begin())); }
			const_reverse_iterator	rend(void) const	{ return (const_reverse_iterator(begin())); }


				/* CAPACITY */

			bool		empty(void) const { return (_tree.empty()); }
			size_type	size(void) const { return (_size); }
			size_type	max_size(void) const { return (_tree.max_size()); }


				/* ELEMENT ACCESS */

			mapped_type	&operator[](key_type const &k)
			{
				return ( ( *( ( insert( ft::make_pair( k, mapped_type() ) ) ).first ) ).second );
			}


				/* MODIFIERS */

			ft::pair<iterator, bool>	insert(value_type const &val)
			{
				nodeptr	to_search = _tree.search(val, _tree.root());

				if (to_search != _tree.sentinel())
					return (ft::make_pair<iterator, bool>(iterator(&_tree, to_search), false));
				_size++;
				return (ft::make_pair<iterator, bool>(iterator(&_tree, _tree.insert(val)), true));
			}

			iterator					insert(iterator position, value_type const &val)
			{
				nodeptr	to_search = _tree.search(val, _tree.root());

				(void)position;
				if (to_search != _tree.sentinel())
					return (iterator(&_tree, to_search));
				_size++;
				return (iterator(&_tree, _tree.insert(val)));
			}

			template<class InputIterator>
			void						insert(InputIterator first, InputIterator last)
			{
				while (first != last)
				{
					insert(*first);
					first++;
					_size++;
				}
			}

			void	clear(void)
			{
				_size = 0;
				_tree.clear();
			}


				/* ALLOCATOR */

			allocator_type	get_allocator(void) const { return (_alloc); }

	}; // class map
}; //namespace ft

#endif
