#ifndef RBT_ITERATOR_HPP
#define RBT_ITERATOR_HPP

#include <functional>
#include "RBT.hpp"
#include "../iteratorTags.hpp"

namespace ft
{
	template< class T, class Comp = std::less<T> >
	class rbt_iterator
	{
		public:
			typedef T									value_type;
			typedef T*									pointer;
			typedef T&									reference;
			typedef Comp								comp;

			typedef typename ft::RBT<value_type, comp>	tree_type;
			typedef tree_type*							tree_ptr;
			typedef tree_type&							tree_ref;
			typedef typename tree_type::nodeptr			nodeptr;

			typedef bidirectional_iterator_tag			iterator_category;

		private:
			tree_ref	_tree;
			nodeptr		_node;

		public:
			rbt_iterator(rbt_iterator const &x) :  _tree(x._tree), _node(x._node) {}
			rbt_iterator(tree_ref tr, nodeptr node) : _tree(tr), _node(node) {}

			~rbt_iterator(void) {}

			rbt_iterator	&operator=(rbt_iterator const &rhs)
			{
				if (this != &rhs)
				{
					_tree = rhs._tree;
					_node = rhs._node;
				}
				return (*this);
			}

			tree_ref	getTree(void) const { return (_tree); }
			nodeptr		getNode(void) const { return (_node); }

			bool	operator==(rbt_iterator const &rhs) const { return (_node == rhs._node); }
			bool	operator!=(rbt_iterator const &rhs) const { return (!(*this == rhs)); }

			reference	operator*(void) const { return (_node->key); }
			pointer		operator->(void) const { return (&(_node->key)); }

			rbt_iterator	&operator++(void)
			{
				_node = _tree.successor(_node);
				return (*this);
			}
			rbt_iterator	operator++(int)
			{
				rbt_iterator	tmp = *this;

				operator++();
				return (tmp);
			}

			rbt_iterator	operator--(void)
			{
				_node = _tree.predecessor(_node);
				return (*this);
			}
			rbt_iterator	&operator--(int)
			{
				rbt_iterator	tmp = *this;

				operator--();
				return (tmp);
			}
	};
};

#endif
