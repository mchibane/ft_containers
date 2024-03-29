#ifndef SET_HPP
#define SET_HPP

#include <functional>
#include <cstddef>
#include "../map/map.hpp"
#include "../map/RBT.hpp"
#include "../map/rbt_iterator.hpp"
#include "../map/rbt_const_iterator.hpp"
#include "../reverse_iterator.hpp"
#include "../equal.hpp"
#include "../lexicographicalCompare.hpp"

namespace ft
{
	template< class T, class Compare = std::less<T>, class Alloc = std::allocator<T> >
	class set
	{
		public:
			typedef T																key_type;
			typedef T																value_type;
			typedef Compare															key_compare;
			typedef Compare															value_compare;
			typedef Alloc															allocator_type;
			typedef typename allocator_type::reference								reference;
			typedef typename allocator_type::const_reference						const_reference;
			typedef typename allocator_type::pointer								pointer;
			typedef typename allocator_type::const_pointer							const_pointer;
			typedef typename ft::rbt_const_iterator<T, key_compare>					iterator;
			typedef typename ft::rbt_const_iterator<T, key_compare>			const_iterator;
			typedef typename ft::reverse_iterator<iterator>							reverse_iterator;
			typedef typename ft::reverse_iterator<const_iterator>					const_reverse_iterator;
			typedef ptrdiff_t														difference_type;
			typedef size_t															size_type;

		private:
			typedef typename ft::RBT< value_type, value_compare, allocator_type >	tree_type;
			typedef typename tree_type::nodeptr										nodeptr;

			allocator_type	_alloc;
			tree_type		_tree;
			size_type		_size;
			key_compare		_comp;

		public:

				/* CONSTRUCTORS & DESTRUCTORS */

			// DEFAULT
			explicit set(key_compare const &comp = key_compare(), allocator_type const &alloc = allocator_type()) :
					_alloc(alloc),
					_tree(tree_type()),
					_size(0),
					_comp(comp)
			{}

			// RANGE
			template<class InputIterator>
			set(InputIterator first, InputIterator last, key_compare const &comp = key_compare(), allocator_type const &alloc = allocator_type()) :
					_alloc(alloc),
					_tree(tree_type()),
					_size(0),
					_comp(comp)
			{
				insert(first, last);
			}

			// COPY
			set(set const &x) :
					_alloc(x.get_allocator()),
					_tree(tree_type()),
					_size(0),
					_comp(x._comp)
			{
				insert(x.begin(), x.end());
			}

			~set(void) {}

			set	&operator=(set const &x)
			{
				if (this != &x)
				{
					clear();
					insert(x.begin(), x.end());
				}
				return (*this);
			}


				/* ITERATORS */

			iterator				begin(void)			{ return (iterator(_tree.root(), _tree.sentinel(), _tree.minimum(_tree.root()))); }
			const_iterator			begin(void) const	{ return (const_iterator(_tree.root(), _tree.sentinel(), _tree.minimum(_tree.root()))); }

			iterator				end(void)			{ return (iterator(_tree.root(), _tree.sentinel(), _tree.sentinel())); }
			const_iterator			end(void) const		{ return (const_iterator(_tree.root(), _tree.sentinel(), _tree.sentinel())); }

			reverse_iterator		rbegin(void)		{ return (reverse_iterator(end())); }
			const_reverse_iterator	rbegin(void) const	{ return (const_reverse_iterator(end())); }

			reverse_iterator		rend(void)			{ return (reverse_iterator(begin())); }
			const_reverse_iterator	rend(void) const	{ return (const_reverse_iterator(begin())); }


				/* CAPACITY */

			bool		empty(void) const { return (_tree.empty()); }
			size_type	size(void) const { return (_size); }
			size_type	max_size(void) const { return (_tree.max_size()); }


				/* MODIFIERS */

			// Single element
			ft::pair<iterator, bool>	insert(value_type const &val)
			{
				nodeptr	to_search = _tree.search(val, _tree.root());

				if (to_search != _tree.sentinel())
					return (ft::make_pair<iterator, bool>(iterator(_tree.root(), _tree.sentinel(), to_search), false));
				_size++;
				return (ft::make_pair<iterator, bool>(iterator(_tree.root(), _tree.sentinel(), _tree.insert(val)), true));
			}

			// With hint
			iterator					insert(iterator position, value_type const &val)
			{
				nodeptr	to_search = _tree.search(val, _tree.root());

				(void)position;
				if (to_search != _tree.sentinel())
					return (iterator(_tree.root(), _tree.sentinel(), to_search));
				_size++;
				return (iterator(_tree.root(), _tree.sentinel(), _tree.insert(val)));
			}

			// Range
			template<class InputIterator>
			void						insert(InputIterator first, InputIterator last)
			{
				while (first != last)
				{
					insert(*first);
					first++;
				}
			}

			void	erase(iterator position)
			{
				_tree.valDelete(*position);
				_size--;
			}

			size_type	erase(key_type const &k)
			{
				nodeptr		to_search = _tree.search(k, _tree.root());

				if (to_search != _tree.sentinel())
				{
					_tree.valDelete(k);
					_size--;
					return (1);
				}
				return (0);
			}

			void	erase(iterator first, iterator last)
			{
				while (first != last)
					erase(first++);
			}

			void	swap(set &x)
			{
				nodeptr		root = _tree.root();
				nodeptr		senti = _tree.sentinel();
				size_type	size_tmp = _size;
				key_compare	k_comp = _comp;

				_tree.setRoot(x._tree.root());
				_tree.setSentinel(x._tree.sentinel());
				_size = x.size();
				_comp = x._comp;

				x._tree.setRoot(root);
				x._tree.setSentinel(senti);
				x._size = size_tmp;
				x._comp = k_comp;
			}

			void	clear(void)
			{
				_size = 0;
				_tree.clear();
			}


				/* OBSERVERS */

			key_compare		key_comp(void) const { return (_comp); }

			value_compare	value_comp(void) const { return (_comp); }


				/* OPERATIONS */

			iterator		find(key_type const &k)
			{
				nodeptr		s = _tree.search(k, _tree.root());

				if (s != _tree.sentinel())
					return (iterator(_tree.root(), _tree.sentinel(), s));
				return (end());
			}

			const_iterator	find(key_type const &k) const
			{
				nodeptr		s = _tree.search(k, _tree.root());

				if (s != _tree.sentinel())
					return (const_iterator(_tree.root(), _tree.sentinel(), s));
				return (end());
			}

			size_type	count(key_type const &k) const
			{
				nodeptr		s = _tree.search(k, _tree.root());

				if (s != _tree.sentinel())
					return (1);
				return (0);
			}

			iterator		lower_bound(key_type const &k)
			{
				iterator	it = begin();
				while (_comp(*it, k) && it != end())
					it++;
				return (it);
			}
			const_iterator	lower_bound(key_type const &k) const
			{
				const_iterator	it = begin();
				while (_comp(*it, k) && it != end())
					it++;
				return (it);
			}

			iterator		upper_bound(key_type const &k)
			{
				iterator	it = begin();
				while (!_comp(k, *it) && it != end())
					it++;
				return (it);
			}
			const_iterator	upper_bound(key_type const &k) const
			{
				const_iterator	it = begin();
				while (!_comp(k, *it) && it != end())
					it++;
				return (it);
			}

			ft::pair<iterator, iterator>				equal_range(key_type const &k)
			{
				iterator	lo = lower_bound(k);
				iterator	up = upper_bound(k);
				return (ft::make_pair(lo, up));
			}
			ft::pair<const_iterator, const_iterator>	equal_range(key_type const &k) const
			{
				const_iterator	lo = lower_bound(k);
				const_iterator	up = upper_bound(k);
				return (ft::make_pair(lo, up));
			}
				/* ALLOCATOR */

			allocator_type	get_allocator(void) const { return (_alloc); }


	}; // class set

	/*******************/
	/* NON MEMBER FCTS */
	/*******************/

	/* SWAP */

	template<class T, class Compare, class Alloc>
	void	swap(ft::set<T, Compare, Alloc> &lhs, ft::set<T, Compare, Alloc> &rhs) { lhs.swap(rhs); }


	/* RELATIONAL OPERATORS */

	template<class T, class Compare, class Alloc>
	bool	operator==(ft::set<T, Compare, Alloc> const &lhs, ft::set<T, Compare, Alloc> const &rhs)
	{
		if (lhs.size() != rhs.size())
			return (false);
		return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
	}

	template<class T, class Compare, class Alloc>
	bool	operator<(ft::set<T, Compare, Alloc> const &lhs, ft::set<T, Compare, Alloc> const &rhs)
	{
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}

	template<class T, class Compare, class Alloc>
	bool	operator!=(ft::set<T, Compare, Alloc> const &lhs, ft::set<T, Compare, Alloc> const &rhs)
	{
		return (!(lhs == rhs));
	}

	template<class T, class Compare, class Alloc>
	bool	operator>(ft::set<T, Compare, Alloc> const &lhs, ft::set<T, Compare, Alloc> const &rhs)
	{
		return (rhs < lhs);
	}

	template<class T, class Compare, class Alloc>
	bool	operator<=(ft::set<T, Compare, Alloc> const &lhs, ft::set<T, Compare, Alloc> const &rhs)
	{
		return (!(rhs < lhs));
	}

	template<class T, class Compare, class Alloc>
	bool	operator>=(ft::set<T, Compare, Alloc> const &lhs, ft::set<T, Compare, Alloc> const &rhs)
	{
		return (!(lhs < rhs));
	}
}; // namespace ft

#endif
