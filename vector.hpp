#ifndef VECTOR_HPP
#define VECTOR_HPP

#include "utils.hpp"
#include "iterators.hpp"
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
			typedef ft::random_access_iterator<value_type>               iterator;

			// /*
			// ** A random access iterator to const value_type
			// ** That can read element stored.
			// */
			typedef ft::random_access_iterator<const value_type>            const_iterator;
			
			// /*
			// ** ft::reverse_iterator<iterator>
			// ** That can read or modify any element in a reversed vector.
			// ** Used to iterate through the vector in reverse.
			// */
			typedef ft::reverse_iterator<iterator>             reverse_iterator;

			// /*
			// ** ft::reverse_iterator<const_iterator>
			// ** That can read any element in a reversed the vector.
			// ** Can't be used to modify, used to iterate through the
			// ** the vector in reverse.
			// */
			typedef ft::reverse_iterator<const_iterator>       const_reverse_iterator;

			/*
			** An unsigned integral type that can represent any
			** non-negative value of difference_type
			** Usually the same as size_t.
			*/
			typedef typename allocator_type::size_type          size_type;


			// Constructors :
			explicit vector(const allocator_type& alloc = allocator_type()) :
			_alloc(alloc), start(nullptr), _end(nullptr), _size(0), _capacity(0) {}

			explicit vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) :
			_alloc(alloc), start(nullptr), _end(nullptr), _size(n), _capacity(n)
			{
				sizecheck( n );
				start = _alloc.allocate( n );
				_end = start;
				while (n--)
				{
					_alloc.construct(_end, val);
					_end++;
				}
				_end--;
			}

			template < class InputIterator >
			vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(),
					typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = nullptr) :
			_alloc(alloc), start(nullptr), _end(nullptr)
			{
				size_type n = ft::distance(first, last);
				sizecheck( n );
				start = _alloc.allocate( n );
				_size = n;
				_capacity = n;
				_end = start;
				while (n--)
				{
					_alloc.construct(_end, *first);
					first++;
					_end++;
				}
				_end--;
			}
			
			vector(const vector& x) { *this = x; }

			// Operators :

			const vector & operator=(const vector& x)
			{
				_alloc = x._alloc;
				_size = x._size;
				_capacity = x._capacity;
				start = this->_alloc.allocate( _capacity );
				_end = start;
				for( pointer temp = x.start; temp != x._end; temp++)
				{
					
					_alloc.construct(_end, *temp);
					_end++;
				}
				_alloc.construct(_end, *x._end);
				return *this;
			}

			// Destructor :

				~vector()
				{
					for (; _size > 0; _size--)
					{
						_alloc.destroy(_end);
						_end--;
					}
					_alloc.deallocate(start, _capacity);
				}

			//Element access :

			reference	operator[](size_type pos)
			{
				pointer temp = this->start;
				while (pos--)
				{
					temp++;
				}
				return *temp;
			}

			const_reference	operator[](size_type pos) const
			{
				pointer temp = this->start;
				while (pos--)
				{
					temp++;
				}
				return *temp;
			}

			reference at( size_type pos )
			{
				try
				{
					if ( pos >= _size )
						throw std::exception();
				}
				catch(const std::exception& e)
				{
					std::cerr << "Error : Out of Range" << '\n';
					exit(1);
				}
				pointer temp = this->start;
				while (pos--)
				{
					temp++;
				}
				return *temp;
			}

			const_reference at( size_type pos ) const
			{
				try
				{
					if ( pos >= _size )
						throw std::exception();
				}
				catch(const std::exception& e)
				{
					std::cerr << "Error : Out of Range" << '\n';
					exit(1);
				}
				pointer temp = this->start;
				while (pos--)
				{
					temp++;
				}
				return *temp;
			}

			reference front() { return *start; }

			const_reference front() const {	return *start; }

			reference back () { return *_end; }

			const_reference back () const { return *_end; }

			// Iterators :
			iterator	begin()
			{
				iterator it = start;
				return it;
			}

			const_iterator begin() const
			{
				const_iterator it = start;
				return it;
			}

			iterator	end()
			{
				if (this->empty())
					return (this->begin());
				return (_end + 1);
			}

			const_iterator end() const
			{
				if (this->empty())
					return (this->begin());
				return (_end + 1);
			}

			reverse_iterator rbegin()
			{
				return (reverse_iterator(end()));
			}

			const_reverse_iterator rbegin() const
			{
				return (reverse_iterator(end()));
			}

			reverse_iterator rend()
			{
				return (reverse_iterator(start));
			}

			const_reverse_iterator rend() const
			{
				return (reverse_iterator(start));
			}

			// Capacity functions :

			size_type size() const { return _size; }

			size_type max_size() const { return _maxsize; }

			size_type capacity() const { return _capacity; }

			bool empty() const 
			{ 
				if (_size == 0)
					return true;
				return false;
			}

			void	reserve( size_type n )
			{
				sizecheck( n );
				if ( n <= _capacity )
					return ;
				else
				{
					allocator_type temp;
					pointer newstart, new_end;
					newstart = temp.allocate(n);
					new_end = vcopy(temp, newstart, start, _end);
					vclean(_alloc, start, _end);
					_capacity = n;
					start = newstart;
					_end = new_end;
					_alloc = temp;
				}
			}

			void	resize( size_type n, value_type val = value_type() )
			{
				sizecheck( n );
				if ( n > _size )
				{
					if ( n > _capacity)
						reserve( n );
					while (_size < n)
					{
						_size++;
						_end++;
						_alloc.construct(_end, val);
					}
				}
				else if ( n == _size )
					return ;
				else if ( n < _size )
				{
					while ( _size > n )
					{
						_alloc.destroy(_end);
						_end--;
						_size--;
					}
				}
			}

			// Modifiers :

			template <class InputIterator>
			void	assign(InputIterator first, InputIterator last,
					typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = nullptr)
			{
				for (; _size > 0; _size--)
					_alloc.destroy(_end--);
				_alloc.destroy(_end);
				while (first != last)
				{
					push_back(*first);
					first++;
				}
			}

			void	assign( size_type n, const value_type& val )
			{
				sizecheck( n );
				for (; _size > 0; _size--)
					_alloc.destroy(_end--);
				_alloc.destroy(_end);
				while (n--)
					push_back(val);
			}

			void	clear()
			{ 
				for (; _size > 0; _size--)
					_alloc.destroy(_end--);
				_alloc.destroy(_end);
			}

			void	swap( vector& x)
			{
				allocator_type temp;
				pointer tmpstart;
				pointer tmp_end;
				size_type tmpcapacity;
				size_type tmpsize;

				tmpcapacity = x._capacity;
				tmpsize = x._size;
				temp = x._alloc;
				tmpstart = x.start;
				tmp_end = x._end;
				
				x._capacity = _capacity;
				x._size = _size;
				x._alloc = _alloc;
				x.start = start;
				x._end = _end;

				_capacity = tmpcapacity;
				_size = tmpsize;
				_alloc = temp;
				start = tmpstart;
				_end = tmp_end;
			}


			void	push_back( const value_type& val )
			{
				if ( _size >= _capacity )
				{
					if (_capacity == 0)
					{
						start = _alloc.allocate(1);
						_end = start;
						_capacity = 1;
						_size = 1;
						_alloc.construct(_end, val);
						return ;
					}
					else
						reserve( _capacity * 2 );
				}
				_end++;
				_size++;
				_alloc.construct(_end, val);
			}

			void	pop_back()
			{
				if (empty() == false)
				{
					_alloc.destroy(_end);
					_end--;
					_size--;
				}
			}

			// Allocator :

			allocator_type get_allocator() const { return _alloc; }



		private :
			allocator_type _alloc;
			pointer	start;
			pointer _end;
			size_type _size;
			size_type _capacity;
			static const size_type _maxsize = 4611686018427387903;
			
			//Utils :
			pointer	vcopy(allocator_type newv, pointer newstart, pointer start, pointer _end)
			{		
				while (start != _end)
				{
					newv.construct(newstart, *start);
					newstart++;
					start++;
				}
				newv.construct(newstart, *start);
				return newstart;
			}

			void	sizecheck( size_type n)
			{
				try
				{
					if ( n > 4611686018427387903 )
						throw std::exception();
				}
				catch(const std::exception& e)
				{
					exit(1);
				}
			}

			void	vclean(allocator_type v, pointer start, pointer _end)
			{
				while (_end != start)
				{
					v.destroy(_end);
					_end--;
				}
				v.deallocate(start, _capacity);
			}


	};

	template< class T, class Alloc >
	bool	operator==(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs)
	{
		if (lhs.size() != rhs.size())
			return false;
		for(unsigned long int i = 0; i < lhs.size(); i++)
			if (lhs[i] != rhs[i])
				return false;
		return true;
	}

	template< class T, class Alloc >
	bool	operator!=(const vector< T, Alloc >& lhs, const vector<T, Alloc>& rhs)
	{
		if ((lhs == rhs) == false)
			return true;
		return false;
	}

	template< class T, class Alloc >
	bool	operator<(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs)
	{
		unsigned long int i = 0;
		for (; i < lhs.size() && i < rhs.size(); i++)
			if (lhs[i] < rhs[i])
				return true;
		if (i == lhs.size() && i < rhs.size())
			return true;
		return false;
	}

	template< class T, class Alloc >
	bool	operator>(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs)
	{
		unsigned long int i = 0;
		for (; i < lhs.size() && i < rhs.size(); i++)
			if (lhs[i] > rhs[i])
				return true;
		if (i == rhs.size() && i < lhs.size())
			return true;
		return false;
	}

	template< class T, class Alloc >
	bool	operator>=(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs)
	{
		if (lhs > rhs)
			return true;
		else if (lhs == rhs)
			return true;
		return false;
	}

	template< class T, class Alloc >
	bool	operator<=(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs)
	{
		if (lhs < rhs)
			return true;
		else if (lhs == rhs)
			return true;
		return false;
	}

	template< class T, class Alloc >
	void	swap(vector<T, Alloc>& x, vector<T, Alloc>& y)
	{
		vector<T, Alloc> swap = x;
		x = y;
		y = swap;
	}
}

#endif