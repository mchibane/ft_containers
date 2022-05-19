#ifndef RBT_HPP
#define RBT_HPP

#include <functional>
#include <memory>

#include <iostream>

#define BLACK false
#define RED true

namespace ft
{
	template<class T>
	struct	RBT_node
	{
		bool			color;
		T				key;
		struct RBT_node	*right;
		struct RBT_node	*left;
		struct RBT_node	*p;

		RBT_node(void) : color (RED), key(T()), right(NULL), left(NULL), p(NULL) {}
		RBT_node(T const &x) : color (RED), key(x), right(NULL), left(NULL), p(NULL) {}
	};

	template< class T, class Comp = std::less<T>, class Alloc = std::allocator<T> >
	class RBT
	{
		public:
			typedef T														value_type;
			typedef typename Alloc::template rebind<RBT_node < T > >::other	allocator_type;
			typedef struct RBT_node<T>*										nodeptr;
			typedef Comp													comp;

		private:
			allocator_type	_alloc;
			nodeptr			_root;
			nodeptr			_sentinel;
			comp			_comp;

		public:
			explicit RBT(allocator_type const &alloc = allocator_type()) :
						_alloc(alloc),
						_root(NULL),
						_sentinel(_alloc.allocate(1)),
						_comp(comp())
			{
				_alloc.construct(_sentinel, RBT_node<value_type>());
				_sentinel->color = BLACK;
				_sentinel->p = NULL;
				_sentinel->right = NULL;
				_sentinel->left = NULL;
				_root = _sentinel;
			}

			~RBT(void)
			{
				while (_root != _sentinel)
					treeDelete(_root);
				_alloc.destroy(_sentinel);
				_alloc.deallocate(_sentinel, 1);
			}

			bool	empty(void)
			{
				return (_root == _sentinel);
			}

			void	insert(value_type const &val)
			{
				nodeptr	tmp = newNode(val);
				insertNode(tmp);
			}

			void	printTree(void)
			{
				if (_root)
					printHelper(_root, "", true);
			}

				void	print_search(value_type const &val)
				{
					nodeptr	tmp = search(val, _root);

					std::cout << "SEARCHING " << val << " : ";

					if (tmp == _sentinel)
						std::cout << "Value Not Found" << std::endl;
					else
						std::cout << "Value Found : " << tmp->key << std::endl;
				}

			nodeptr	search(value_type const &val, nodeptr x)
			{
				nodeptr	tmp = x;

				if (empty())
					return (_sentinel);
				while (tmp != _sentinel && !equal(tmp->key, val))
				{
					if (_comp(val, tmp->key))
						tmp = tmp->left;
					else
						tmp = tmp->right;
				}
				return (tmp);
			}

				void	print_min(void)
				{
					nodeptr	tmp = minimum(_root);

					if (tmp != _sentinel)
						std::cout << "MINIMUM IS : " << tmp->key << std::endl;
					else
						std::cout << "MINIMUM: ERROR" << std::endl;
				}

			nodeptr	minimum(nodeptr x)
			{
				nodeptr	tmp = x;

				if (empty())
					return (_sentinel);
				while (tmp->left != _sentinel)
					tmp = tmp->left;
				return (tmp);
			}

				void	print_max(void)
				{
					nodeptr	tmp = maximum(_root);

					if (tmp != _sentinel)
						std::cout << "MAXIMUM IS : " << tmp->key << std::endl;
					else
						std::cout << "MAXIMUM: ERROR" << std::endl;
				}

			nodeptr	maximum(nodeptr x)
			{
				nodeptr	tmp = x;

				if (empty())
					return (_sentinel);
				while (tmp->right != _sentinel)
					tmp = tmp->right;
				return (tmp);
			}

			void	valDelete(value_type const &val)
			{
				nodeptr	to_del = search(val, _root);

				if (to_del != _sentinel)
					treeDelete(to_del);
			}

			void	treeDelete(nodeptr x)
			{
				nodeptr	tmp;

				if (x->left == _sentinel)
					transplant(x, x->right);
				else if (x->right == _sentinel)
					transplant(x, x->left);
				else
				{
					tmp = minimum(x->right);

					if (tmp->p != x)
					{
						transplant(tmp, tmp->right);
						tmp->right = x->right;
						tmp->right->p = tmp;
					}
					transplant(x, tmp);
					tmp->left = x->left;
					tmp->left->p = tmp;
				}
				_alloc.destroy(x);
				_alloc.deallocate(x, 1);
			}

			void	transplant(nodeptr x, nodeptr y)
			{
				if (x->p == _sentinel)
					_root = y;
				else if (x == x->p->left)
					x->p->left = y;
				else
					x->p->right = y;
				if (y != _sentinel)
					y->p = x->p;
			}

				void	print_succ_pred(value_type const &val)
				{
					nodeptr	to_seek = search(val, _root);
					nodeptr	pred;
					nodeptr	succ;

					std::cout << "PREDECESSOR AND SUCCESSOR ->" << val << "<-" << std::endl;
					if (to_seek == _sentinel)
					{
						std::cout << "Value not found, could not find predecessor or successor" << std::endl << std::endl;
						return ;
					}
					pred = predecessor(to_seek);
					succ = successor(to_seek);
					if (pred != _sentinel)
						std::cout << "Predecessor of (" << to_seek->key << ") is : (" << pred->key << ")" << std::endl;
					else
						std::cout << to_seek->key << " has no predecessor" << std::endl;
					if (succ != _sentinel)
						std::cout << "Successor of (" << to_seek->key << ") is : (" << succ->key << ")" << std::endl;
					else
						std::cout << to_seek->key << " has no successor" << std::endl;
					std::cout << std::endl;
				}

			nodeptr	successor(nodeptr x)
			{
				nodeptr	tmp = x;
				nodeptr	y;

				if (tmp->right != _sentinel)
					return (minimum(tmp->right));
				y = tmp->p;
				while (y != _sentinel && tmp == y->right)
				{
					tmp = y;
					y = y->p;
				}
				return (y);
			}

			nodeptr	predecessor(nodeptr x)
			{
				nodeptr	tmp = x;
				nodeptr	y;

				if (tmp->left != _sentinel)
					return (minimum(tmp->left));
				y = tmp->p;
				while (y != _sentinel && tmp == y->left)
				{
					tmp = y;
					y = y->p;
				}
				return (y);
			}

			/* HELPERS FUNCTIONS FOR RBT OPERATIONS */
			private:

				/* INSERTION */

			void	insertNode(nodeptr &n)
			{
				nodeptr	y = _sentinel;
				nodeptr	x = _root;

				while (x != _sentinel)
				{
					y = x;
					if (_comp(n->key, x->key))
						x = x->left;
					else
						x = x->right;
				}
				n->p = y;
				if (y == _sentinel)
					_root = n;
				else if (_comp(n->key, y->key))
					y->left = n;
				else
					y->right = n;
			}

			nodeptr	newNode(value_type const &val)
			{
				nodeptr	ret;

				ret = _alloc.allocate(1);
				_alloc.construct(ret, val);
				ret->left = _sentinel;
				ret->right = _sentinel;
				ret->p = _sentinel;
				return (ret);
			}


				/* PRINT */

			void	printHelper(nodeptr root, std::string indent, bool last)
			{
				if (root != _sentinel)
				{
					std::cout << indent;
					if (last)
					{
						std::cout << "R----";
						indent += "   ";
					}
					else
					{
						std::cout << "L----";
						indent += "|  ";
					}
					std::string color = root->color ? "RED" : "BLACK";
					std::cout << root->key << "("<< color << ")" << std::endl;
					printHelper(root->left, indent, false);
					printHelper(root->right, indent, true);
				}
			}

				/* EQUALITY */

			bool	equal(value_type const &x, value_type const &y)
			{
				return (!_comp(x, y) && !_comp(y, x));
			}

	}; // class RBT
}; // namespace ft

#endif
