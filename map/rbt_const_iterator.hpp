#ifndef RBT_CONST_IT_HPP
#define RBT_CONST_IT_HPP

#include <functional>
#include "RBT.hpp"
// #include "../iteratorTags.hpp"
#include "rbt_iterator.hpp"
#include <iterator>

namespace ft
{
	template<class T, class Comp = std::less<T> >
	class rbt_const_iterator
	{
		public:
			typedef const T						value_type;
			typedef const T*					pointer;
			typedef const T&					reference;
			typedef Comp						comp;

			typedef typename ft::RBT<T, comp> const	tree_type;
			typedef typename tree_type::nodeptr	nodeptr;

			typedef std::bidirectional_iterator_tag	iterator_category;
			typedef ptrdiff_t					difference_type;

		private:
			nodeptr	_root;
			nodeptr	_sentinel;
			nodeptr	_node;

		public:
			rbt_const_iterator(void) : _root(NULL), _sentinel(NULL), _node(NULL) {}
			rbt_const_iterator(rbt_const_iterator const &x) : _root(x._root), _sentinel(x._sentinel), _node(x._node) {}
			rbt_const_iterator(ft::rbt_iterator<T, Comp> const &x) : _root(x.getRoot()), _sentinel(x.getSenti()), _node(x.getNode()) {}
			rbt_const_iterator(nodeptr const r, nodeptr const tr, nodeptr const node) : _root(r), _sentinel(tr), _node(node) {}

			~rbt_const_iterator(void) {}

			rbt_const_iterator	&operator=(rbt_const_iterator const &rhs)
			{
				if (this != &rhs)
				{
					_root = rhs._root;
					_sentinel = rhs._sentinel;
					_node = rhs._node;
				}
				return (*this);
			}

			nodeptr	getSenti(void) const { return (_sentinel); }
			nodeptr	getRoot(void) const { return (_root); }
			nodeptr	getNode(void) const { return (_node); }

			bool	operator==(rbt_const_iterator const &rhs) const { return (_node == rhs._node); }
			bool	operator!=(rbt_const_iterator const &rhs) const { return (!(*this == rhs)); }

			reference	operator*(void) const { return (_node->key); }
			pointer		operator->(void) const { return (&(_node->key)); }

			rbt_const_iterator	&operator++(void)
			{
				nodeptr	tmp;

				if (_node->right != _sentinel)
				{
					_node = _node->right;
					while (_node->left != _sentinel)
					{
						_node = _node->left;
					}
					return (*this);
				}
				tmp = _node->p;
				while (tmp != _sentinel && _node == tmp->right)
				{
					_node = tmp;
					tmp = tmp->p;
				}
				_node = tmp;
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
				nodeptr	tmp;

				if (_node == _sentinel)
				{
					_node = _root;
					while (_node->right != _sentinel)
						_node = _node->right;
					return (*this);
				}
				if (_node->left != _sentinel)
				{
					_node = _node->left;
					while (_node->right != _sentinel)
						_node = _node->right;
					return (*this);
				}
				tmp = _node->p;
				while (tmp != _sentinel && _node == tmp->left)
				{
					_node = tmp;
					tmp = tmp->p;
				}
				_node = tmp;
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
