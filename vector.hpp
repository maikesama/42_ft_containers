#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <memory>

namespace ft
{
	
	template < class T, class Alloc = std::allocator<T> > class vector
	{
		public :
			/*
			** The first template parameter (T)
			*/
			typedef T                                           value_type;

			/*
			** The second template parameter (Alloc)
			*/
			typedef Alloc                                       allocator_type;

			/*
			** allocator_type::reference
			** A type provides a reference to an element stored in
			** a vector.
			** For the default allocator is a reference to value_type
			** (value_type&)
			*/
			typedef typename allocator_type::reference          reference;

			/*
			** allocator_type::const_reference
			** Type that give a reference to a const element stored.
			** Usefull to read and perform const operator.
			** A type const_reference can't be used to modify the value
			** of an element.
			** For the default allocator is a const reference to value_type
			** (const value_type&)
			*/
			typedef typename allocator_type::const_reference    const_reference;
			
			/*
			** allocator_type::pointer
			** Type that give a pointer to an element stored.
			** A type pointer can be used to modify the value of
			** an element.
			** For the default allocator is a pointer to value_type
			** (value_type*)
			*/
			typedef typename allocator_type::pointer            pointer;

			/*
			** allocator_type::const_pointer
			** Type that give a const pointer to an element stored.
			** Can't be used to modify the value of an element.
			** An iterator is prefered to access to an element.
			** For the default allocator is a const pointer to value_type
			** (const value_type*)
			*/
			typedef typename allocator_type::const_pointer      const_pointer;

			// /*
			// ** A random access iterator to value_type
			// ** That can read or modify any element stored.
			// ** Convertible to const_iterator;
			// */
			// typedef ft::random_access_iterator<value_type>               iterator;

			// /*
			// ** A random access iterator to const value_type
			// ** That can read element stored.
			// */
			// typedef ft::random_access_iterator<const value_type>            const_iterator;
			
			// /*
			// ** ft::reverse_iterator<iterator>
			// ** That can read or modify any element in a reversed vector.
			// ** Used to iterate through the vector in reverse.
			// */
			// typedef ft::reverse_iterator<iterator>             reverse_iterator;

			// /*
			// ** ft::reverse_iterator<const_iterator>
			// ** That can read any element in a reversed the vector.
			// ** Can't be used to modify, used to iterate through the
			// ** the vector in reverse.
			// */
			// typedef ft::reverse_iterator<const_iterator>       const_reverse_iterator;

			/*
			** An unsigned integral type that can represent any
			** non-negative value of difference_type
			** Usually the same as size_t.
			*/
			typedef typename allocator_type::size_type          size_type;


			// Constructors :
			explicit vector(const allocator_type& alloc = allocator_type()) :
			_alloc(alloc), end(nullptr), start(nullptr), capacity(0), size(0) {}

			explicit vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) :
			_alloc(alloc), end(nullptr), start(nullptr), capacity(n), size(n)
			{
				start = _alloc.allocate( n );
				end = start;
				while (n--)
				{
					_alloc.construct(end, val);
					end++;
				}
			}

			template < class InputIterator >
			vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type()) :
			_alloc(alloc), end(nullptr), start(nullptr)
			{
				start = _alloc.allocate( last - first );
				end = start;
				for (InputIterator it = first; it != last; it++)
				{
					_alloc.construct(end, *it);
					end++;
				}
			}


		private :
			T* array;
			allocator_type _alloc;
			pointer	start;
			pointer end;
			unsigned long int size;
			unsigned long int capacity;
			static const unsigned long int max_size = 4611686018427387903;

	};
}

#endif