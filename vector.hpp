#ifndef VECTOR_HPP
#define VECTOR_HPP

#include "utils.hpp"
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

			typedef typename std::ptrdiff_t		difference_type;

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
			_alloc(alloc), start(nullptr), end(nullptr), size(n), capacity(n)
			{
				try
				{
					if ( n > 4611686018427387903 )
						throw std::exception();
				}
				catch(const std::exception& e)
				{
				}
				start = _alloc.allocate( n );
				end = start;
				while (n--)
				{
					_alloc.construct(end, val);
					end++;
				}
			}

			template < class InputIterator >
			vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(),
					typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = nullptr) :
			_alloc(alloc), start(nullptr), end(nullptr)
			{
				size_type n = ft::distance(first, last);
				try
				{
					if ( n > 4611686018427387903 )
						throw std::exception();
				}
				catch(const std::exception& e)
				{
				}
				start = _alloc.allocate( n );
				size = n;
				capacity = n;
				end = start;
				while (n--)
				{
					_alloc.construct(end, *first);
					first++;
					end++;
				}
			}
			
			vector(const vector& x) :
			_alloc(x._alloc), start(nullptr), end(nullptr), size(x.size), capacity(x.capacity)
			{
				start = this->_alloc.allocate( capacity );
				end = start;
				for( pointer temp = x.start; temp != x.end; temp++)
				{
					_alloc.construct(end, *temp);
					end++;
				}
			}

			// Destructor :

				~vector()
				{
					for (; size > 0; size--)
					{
						_alloc.destroy(end);
						end--;
					}
					_alloc.deallocate(start, capacity);
				}

			// Operators :

			vector & operator=(const vector& x)
			{
				for (; size > 0; size--)
				{
					_alloc.destroy(end);
					end--;
				}
				_alloc.deallocate(start, capacity);
				_alloc = x._alloc;
				start = nullptr;
				end = nullptr;
				size = x.size;
				capacity = x.capacity;
				start = this->_alloc.allocate( capacity );
				end = start;
				for( pointer temp = x.start; temp != x.end; temp++)
				{
					_alloc.construct(end, *temp);
					end++;
				}
				return *this;
			}

			int &	operator[](int pos)
			{
				pointer temp = this->start;
				while (pos--)
				{
					temp++;
				}
				return *temp;
			}

			// Capacity functions :

			size_type size() const { return size; }

			size_type max_size() const { return max_size; }

			size_type capacity() const { return capacity; }

			bool empty() const 
			{ 
				if (size > 0)
					return true;
				return false;
			}

			//void	reserve( size_type n )

			//void	resize( size_type n )
			//void	resize( size_type n, value_type val = value_type() )




		private :
			allocator_type _alloc;
			pointer	start;
			pointer end;
			size_type size;
			size_type capacity;
			size_type max_size = 4611686018427387903;
			

	};

}

#endif