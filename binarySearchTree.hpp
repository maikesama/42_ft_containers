#ifndef BINARYSEARCHTREE_HPP
#define BINARYSEARCHTREE_HPP

#include "iterators.hpp"
#include "pair.hpp"
#include <memory>

namespace ft
{
	template < class T >
	class node
	{
		public:

			typedef T   value_type;

			value_type	value;
			node* 		parent;
			node* 		left;
			node* 		right;

			node(): value(), left(nullptr), right(nullptr), parent(nullptr) {}

			node (node* parent = nullptr, node* left = nullptr, node* right = nullptr) :
				value(),parent(parent),left(left),right(right) {}

			node(const value_type& val, node* parent = nullptr, node* left = nullptr, node* right = nullptr) :
				value(val),parent(parent),left(left),right(right) {}

			node (const node& nd) : value(nd.value), parent(nd.parent), left(nd.left), right(nd.right) {}

			virtual ~node() {}

			node &operator=(const node& nd)
            {
                if (nd == *this)
                    return (*this);
                
                this->value = nd.value;
                this->parent = nd.parent;
                this->left = nd.left;
                this->right = nd.right;
                
                return (*this);
            }

			bool operator==(const node& nd)
            {
                if (value == nd.value)
                    return (true);
                return (false);
            }

	};

	template <class T, class Compare = std::less<T>, class Node = ft::node<T>,
			class Type_Alloc = std::allocator<T>, class Node_Alloc = std::allocator<Node> >
	class BST
	{
		public :

			typedef BST  self;

			typedef self&   self_reference;
			
			typedef T   value_type;

			typedef Node node_type;

			typedef Node *  node_pointer;
			
			typedef Node_Alloc  node_alloc;

			typedef ft::BST_iterator<Node, Compare> iterator;

			typedef ft::BST_const_iterator<Node, Compare> const_iterator;
			
			typedef size_t size_type;

			BST (const node_alloc& node_alloc_init = node_alloc())
			:
				_node_alloc(node_alloc_init)
			{
				_last_node = _node_alloc.allocate(1);
				_node_alloc.construct(_last_node, Node(_last_node, _last_node, _last_node));
			}

			~BST ()
			{
				_node_alloc.destroy(_last_node);
				_node_alloc.deallocate(_last_node, 1);	
			}

			ft::pair<iterator, bool> insertPair(value_type to_insert)
			{
				Node * new_node = _node_alloc.allocate(1);
				Node * prev_node = _last_node;
				Node * start_node = _last_node->parent;

				// side == false = left; side == true = right;
				bool side = true;

				while (start_node != _last_node)
				{
					int curkey = start_node->value.first;
					if (curkey == to_insert.first)
						return (ft::make_pair(iterator(start_node, _last_node), false));
					prev_node = start_node;
					if (to_insert.first > curkey)
					{
						side = true;
						start_node = start_node->right;
					}
					else
					{
						side = false;
						start_node = start_node->left;
					}
				}
				_node_alloc.construct(new_node, Node(to_insert, prev_node, _last_node, _last_node));
				
				if (prev_node == _last_node)
					_last_node->parent = new_node;
				else if (side == true)
					prev_node->right = new_node;
				else
					prev_node->left = new_node;
				
				_last_node->left = _BST_get_lower_node(_last_node->parent);
				_last_node->right = _BST_get_higher_node(_last_node->parent);
				_last_node->value.first += 1;
				return (ft::make_pair(iterator(new_node, _last_node), true));
			}

			void removeByKey(value_type to_remove)
			{ _removeByKey(_last_node->parent, to_remove); }

			node_pointer searchByKey(value_type to_remove)
			{
				node_pointer node = _last_node->parent;

				while (node != _last_node)
				{
					if (node->value.first == to_remove.first)
						return (node);
					if (node->value.first > to_remove.first)
						node = node->left;
					else
						node = node->right;
				}
				return (node);
			}

			void swap(self& x)
			{
				if (&x == this)
					return ;
				
				node_pointer save = this->_last_node;
				this->_last_node = x._last_node;
				x._last_node = save;
			}

			size_type max_size() const
			{ return (node_alloc().max_size()); }

			// last_node parent = root of tree, last_node right = last node, last_node left = first node
			node_pointer    _last_node;
			node_alloc      _node_alloc;

		private :

			node_pointer _BST_get_lower_node(node_pointer root)
			{
				while (root != _last_node && root->left != _last_node)
					root = root->left;
				return (root);
			}

			node_pointer _BST_get_higher_node(node_pointer root)
			{
				while (root != _last_node && root->right != _last_node)
					root = root->right;
				return (root);
			}

			void _replaceNodeInParent(node_pointer node, node_pointer new_node)
			{
				if (node->parent != _last_node)
				{
					if (_last_node->parent == node)
						_last_node->parent = new_node;

					if (node == node->parent->left)
						node->parent->left = new_node;
					else
						node->parent->right = new_node;
				}
				else
					_last_node->parent = new_node;

				_last_node->left = _BST_get_lower_node(_last_node->parent);
				_last_node->right = _BST_get_higher_node(_last_node->parent);
				_last_node->value.first -= 1;
				
				new_node->parent = node->parent;
				
				_node_alloc.destroy(node);
				_node_alloc.deallocate(node, 1);
			}

			void _replaceDoubleChildren(node_pointer& to_remove, node_pointer new_node)
			{
				if (new_node->parent != _last_node)
				{
					if (new_node->parent != to_remove)
						new_node->parent->left = new_node->right;
				}
				
				new_node->parent = to_remove->parent;
				if (to_remove->left != new_node)
					new_node->left = to_remove->left;
				if (to_remove->right != new_node)
					new_node->right = to_remove->right;

				if (to_remove->parent != _last_node)
				{
					if (to_remove->parent->left == to_remove)
						to_remove->parent->left = new_node;
					else if (to_remove->parent->right == to_remove)
						to_remove->parent->right = new_node;
				}
				else
					_last_node->parent = new_node;
					
				if (to_remove->left != _last_node && to_remove->left != new_node)
					to_remove->left->parent = new_node;
				if (to_remove->right != _last_node && to_remove->right != new_node)
					to_remove->right->parent = new_node;

				if (to_remove->parent != _last_node)
				{
					to_remove->left = _last_node;
					to_remove->right = _last_node;
					to_remove->parent = new_node;
				}

				_last_node->left = _BST_get_lower_node(_last_node->parent);
				_last_node->right = _BST_get_higher_node(_last_node->parent);
				_last_node->value.first -= 1;

				_node_alloc.destroy(to_remove);
				_node_alloc.deallocate(to_remove, 1);
			}

			void _removeByKey(node_pointer node, value_type to_remove)
			{
				if (to_remove.first < node->value.first)
				{
					_removeByKey(node->left, to_remove);
					return ;
				}

				if (to_remove.first > node->value.first)
				{
					_removeByKey(node->right, to_remove);
					return ;
				}

				if (node->left != _last_node && node->right != _last_node)
				{
					node_pointer successor = _BST_get_lower_node(node->right);
					_replaceDoubleChildren(node, successor);
					return ;
				}
				else if (node->left != _last_node)
					_replaceNodeInParent(node, node->left);
				else if (node->right != _last_node)
					_replaceNodeInParent(node, node->right);
				else
					_replaceNodeInParent(node, _last_node);
			}
	};
}


#endif