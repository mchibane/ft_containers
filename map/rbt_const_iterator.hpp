#ifndef RBT_CONST_IT_HPP
#define RBT_CONST_IT_HPP

#include <functional>
#include "RBT.hpp"
#include "../iteratorTags.hpp"
#include "rbt_iterator.hpp"

namespace ft
{
	// template< class T, class Comp = std::less<T> >
	// class rbt_iterator;

	template<class T, class Comp = std::less<T> >
	class rbt_const_iterator
	{
		public:
			typedef const T								value_type;
			typedef const T*							pointer;
			typedef const T&							reference;
			typedef Comp								comp;

			typedef typename ft::RBT<T, comp>	tree_type;
			typedef tree_type*							tree_ptr;
			typedef tree_type&							tree_ref;
			typedef typename tree_type::nodeptr			nodeptr;

			typedef bidirectional_iterator_tag			iterator_category;

		private:
			tree_ref	_tree;
			nodeptr		_node;

		public:
			rbt_const_iterator(rbt_const_iterator const &x) : _tree(x._tree), _node(x._node) {}
			rbt_const_iterator(ft::rbt_iterator<T, Comp> const &x) : _tree(x.getTree()), _node(x.getNode()) {}
			rbt_const_iterator(tree_ref tr, nodeptr node) : _tree(tr), _node(node) {}

			~rbt_const_iterator(void) {}

			rbt_const_iterator	&operator=(rbt_const_iterator const &rhs)
			{
				if (this != &rhs)
				{
					_tree = rhs._tree;
					_node = rhs._node;
				}
				return (*this);
			}

			bool	operator==(rbt_const_iterator const &rhs) const { return (_node == rhs._node); }
			bool	operator!=(rbt_const_iterator const &rhs) const { return (!(*this == rhs)); }

			reference	operator*(void) const { return (_node->key); }
			pointer		operator->(void) const { return (&(_node->key)); }

			rbt_const_iterator	&operator++(void)
			{
				_node = _tree.successor(_node);
				return (*this);
			}
			rbt_const_iterator	operator++(int)
			{
				rbt_const_iterator	tmp = *this;

				operator++();
				return (tmp);
			}

			rbt_const_iterator	&operator--(void)
			{
				_node = _tree.predecessor(_node);
				return (*this);
			}
			rbt_const_iterator	operator--(int)
			{
				rbt_const_iterator	tmp = *this;

				operator--();
				return (tmp);
			}
	}; // class rbt_const_iterator
}; // namespace ft

#endif
