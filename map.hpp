#ifndef MAP_HPP
#define MAP_HPP

#include "utils.hpp"
#include "iterators.hpp"
#include "pair.hpp"
#include <memory>

namespace ft
{

	template < class Key, class T, class Compare = std::less< Key >, class Alloc = std::allocator< ft::pair < const Key, T > > >
	class map
	{
		typedef Key 											key_type;
		typedef T												mapped_type;
		typedef ft::pair < const Key, T >						value_type;
		typedef	Compare											key_compare;
		//typedef value_comp()									value_compare;
		typedef std::allocator< value_type >					allocator_type;
		typedef	typename allocator_type::reference				reference;
		typedef	typename allocator_type::const_reference		const_reference;
		typedef typename allocator_type::pointer				pointer;
		typedef typename allocator_type::const_pointer			const_pointer;
		// typedef	bidirectional_iterator							iterator;
		// const_iterator;
		// typedef	ft::reverse_iterator<iterator>					reverse_iterator;
		// typedef	ft::reverse_iterator<const_iterator>			const_reverse_iterator;
		typedef	ptrdiff_t										difference_type;
		typedef	size_t											size_type;


		private:
		allocator_type 	_alloc;
		key_compare		_comp;
		

	};
           
}

#endif