#ifndef ITERATORS_HPP
#define ITERATORS_HPP

namespace ft
{

	class random_access_iterator_tag { };
    class bidirectional_iterator_tag { };
    class forward_iterator_tag { };
    class input_iterator_tag { };
    class output_iterator_tag { };

	template< class Iterator >
	class iterator_traits
	{

		public :
		typedef typename Iterator::difference_type difference_type;
		typedef typename Iterator::value_type value_type;
		typedef typename Iterator::pointer pointer;
		typedef typename Iterator::reference reference;
		typedef typename Iterator::iterator_category iterator_category;
	};

	template< class T >
	class iterator_traits< T* >
	{
		typedef ptrdiff_t difference_type;
		typedef T value_type;
		typedef T* pointer;
		typedef T& reference;
		typedef random_access_iterator_tag iterator_category;
	};

	template< class T >
	class iterator_traits< const T* >
	{
		typedef ptrdiff_t difference_type;
		typedef T value_type;
		typedef const T* pointer;
		typedef const T& reference;
		typedef random_access_iterator_tag iterator_category;
	};

	template<class InputIterator>
        typename ft::iterator_traits<InputIterator>::difference_type
            distance (InputIterator first, InputIterator last)
        {
            typename ft::iterator_traits<InputIterator>::difference_type rtn = 0;
            while (first != last)
            {
                first++;
                rtn++;
            }
            return (rtn);
        }

	template <class Category, class T, class Distance = ptrdiff_t,
        class Pointer = T*, class Reference = T&>
        class iterator
        {
            public:
                typedef T           value_type;
                typedef Distance    difference_type;
                typedef Pointer     pointer;
                typedef Reference   reference;
                typedef Category    iterator_category;
        };

	template <typename T>
        class random_access_iterator : ft::iterator<ft::random_access_iterator_tag, T>
        {
            public:
			
                typedef typename ft::iterator<ft::random_access_iterator_tag, T>::iterator_category     iterator_category;
                
                typedef typename ft::iterator<ft::random_access_iterator_tag, T>::value_type            value_type;
                
                typedef typename ft::iterator<ft::random_access_iterator_tag, T>::difference_type       difference_type;
                
                typedef T*               pointer;
                
                typedef T&             reference;
                
                random_access_iterator(void) : _elem(nullptr) {}

                random_access_iterator(pointer elem) : _elem(elem) {}

                random_access_iterator(const random_access_iterator& op) : _elem(op._elem) {}

                random_access_iterator &operator=(const random_access_iterator& op)
                {
                    if (this == &op)
		                return (*this);
                    this->_elem = op._elem;
                    return (*this);
                }

                virtual ~random_access_iterator() {}

                pointer base() const { return (this->_elem); }

                reference operator*(void) const { return (*_elem); }

                pointer operator->(void) { return &(this->operator*()); }

                random_access_iterator& operator++(void)
                {
                    _elem++;
                    return (*this);
                }

                random_access_iterator operator++(int)
                {
                    random_access_iterator rtn(*this);
                    operator++();
                    return (rtn);
                }

                random_access_iterator& operator--(void)
                {
                    _elem--;
                    return (*this);
                }

                random_access_iterator operator--(int)
                {
                    random_access_iterator rtn(*this);
                    operator--();
                    return (rtn);
                }

                random_access_iterator operator+(difference_type n) const { return (_elem + n); }

                random_access_iterator operator-(difference_type n) const { return (_elem - n); }

                random_access_iterator& operator+=(difference_type n)
                {
                    _elem += n;
                    return (*this);
                }

                random_access_iterator& operator-=(difference_type n)
                {
                    _elem -= n;
                    return (*this);
                }

                reference operator[](difference_type n) { return (*(operator+(n))); }

                // operator random_access_iterator<const T> () const
                // { return (random_access_iterator<const T>(this->_elem)); }

                private:
                    pointer _elem;
        };

	template <typename T>
	typename ft::random_access_iterator<T>::difference_type
	operator==(const ft::random_access_iterator<T> lhs,
			const ft::random_access_iterator<T> rhs)
	{
		return (lhs.base() == rhs.base());
	}

	/* For iterator == const_iterator */
	template<typename T_L, typename T_R>
	typename ft::random_access_iterator<T_L>::difference_type
	operator==(const ft::random_access_iterator<T_L> lhs,
			const ft::random_access_iterator<T_R> rhs)
	{
		return (lhs.base() == rhs.base());
	}

	template <typename T>
    typename ft::random_access_iterator<T>::difference_type
    operator!=(const ft::random_access_iterator<T> lhs,
              const ft::random_access_iterator<T> rhs)
    {
        return (lhs.base() != rhs.base());
    }

    /* For iterator != const_iterator */
    template<typename T_L, typename T_R>
    typename ft::random_access_iterator<T_L>::difference_type
    operator!=(const ft::random_access_iterator<T_L> lhs,
              const ft::random_access_iterator<T_R> rhs)
    {
        return (lhs.base() != rhs.base());
    }

	template <typename T>
    typename ft::random_access_iterator<T>::difference_type
    operator<(const ft::random_access_iterator<T> lhs,
              const ft::random_access_iterator<T> rhs)
    {
        return (lhs.base() < rhs.base());
    }

    /* For iterator < const_iterator */
    template<typename T_L, typename T_R>
    typename ft::random_access_iterator<T_L>::difference_type
    operator<(const ft::random_access_iterator<T_L> lhs,
              const ft::random_access_iterator<T_R> rhs)
    {
        return (lhs.base() < rhs.base());
    }

    template <typename T>
    typename ft::random_access_iterator<T>::difference_type
    operator>(const ft::random_access_iterator<T> lhs,
              const ft::random_access_iterator<T> rhs)
    {
        return (lhs.base() > rhs.base());
    }

    /* For iterator > const_iterator */
    template<typename T_L,
             typename T_R>
    typename ft::random_access_iterator<T_L>::difference_type
    operator>(const ft::random_access_iterator<T_L> lhs,
              const ft::random_access_iterator<T_R> rhs)
    {
        return (lhs.base() > rhs.base());
    }

    template <typename T>
    typename ft::random_access_iterator<T>::difference_type
    operator<=(const ft::random_access_iterator<T> lhs,
              const ft::random_access_iterator<T> rhs)
    {
        return (lhs.base() <= rhs.base());
    }

    /* For iterator <= const_iterator */
    template<typename T_L, typename T_R>
    typename ft::random_access_iterator<T_L>::difference_type
    operator<=(const ft::random_access_iterator<T_L> lhs,
              const ft::random_access_iterator<T_R> rhs)
    {
        return (lhs.base() <= rhs.base());
    }

    template <typename T>
    typename ft::random_access_iterator<T>::difference_type
    operator>=(const ft::random_access_iterator<T> lhs,
              const ft::random_access_iterator<T> rhs)
    {
        return (lhs.base() >= rhs.base());
    }

    /* For iterator >= const_iterator */
    template<typename T_L,
             typename T_R>
    typename ft::random_access_iterator<T_L>::difference_type
    operator>=(const ft::random_access_iterator<T_L> lhs,
              const ft::random_access_iterator<T_R> rhs)
    {
        return (lhs.base() >= rhs.base());
    }

    template<typename T>
    ft::random_access_iterator<T> operator+(
        typename ft::random_access_iterator<T>::difference_type n,
        typename ft::random_access_iterator<T>& rai)
        {
            return (&(*rai) + n);
        }

    template <typename T>
    typename ft::random_access_iterator<T>::difference_type
    operator-(const ft::random_access_iterator<T> lhs,
              const ft::random_access_iterator<T> rhs)
    {
        return (lhs.base() - rhs.base());
    }

    /* For iterator - const_iterator */
    template<typename T_L, typename T_R>
    typename ft::random_access_iterator<T_L>::difference_type
    operator-(const ft::random_access_iterator<T_L> lhs,
              const ft::random_access_iterator<T_R> rhs)
    {
        return (lhs.base() - rhs.base());
    }



	/* Reverse Iterator */
	template <class Iterator>
    class reverse_iterator
    {
        public:

            typedef Iterator    iterator_type;

            typedef typename ft::iterator_traits<Iterator>::iterator_category iterator_category;

            typedef typename ft::iterator_traits<Iterator>::value_type      value_type;

            typedef typename ft::iterator_traits<Iterator>::difference_type     difference_type;

            typedef typename ft::iterator_traits<Iterator>::pointer     pointer;

            typedef typename ft::iterator_traits<Iterator>::reference   reference;
            
            reverse_iterator() : _elem() {}

            explicit reverse_iterator (iterator_type it) : _elem(it) {}

            template <class Iter>
            reverse_iterator (const reverse_iterator<Iter>& rev_it) : _elem(rev_it.base()) {}

            virtual ~reverse_iterator() {}

            iterator_type base() const
            { return (_elem); }

            reference operator*() const
            {
                iterator_type tmp = _elem;
                return (*(--tmp));
				//return *_elem;
            }

            reverse_iterator operator+ (difference_type n) const { return (reverse_iterator(_elem - n)); }

            reverse_iterator& operator++()
            {
                --_elem;
                return (*this);
            }

            reverse_iterator operator++(int)
            {
                reverse_iterator tmp = *this;
                ++(*this);
                return (tmp);
            }

            reverse_iterator& operator+= (difference_type n)
            {
                _elem -= n;
                return (*this);
            }

            reverse_iterator operator- (difference_type n) const { return (reverse_iterator(_elem + n)); }

            reverse_iterator& operator--()
            {
                ++_elem;
                return (*this);
            }

            reverse_iterator operator--(int)
            {
                reverse_iterator tmp = *this;
                --(*this);
                return (tmp);
            }

            reverse_iterator& operator-= (difference_type n)
            {
                _elem += n;
                return (*this);
            }

            pointer operator->() const { return &(operator*()); }

            reference operator[] (difference_type n) const { return (this->base()[-n - 1]); }

        private:
            iterator_type     _elem;
    };

    template <class Iterator>
        bool operator== (const reverse_iterator<Iterator>& lhs,
                        const reverse_iterator<Iterator>& rhs) { return (lhs.base() == rhs.base()); }

    /* For reverser_iterator == const_reverse_iterator */
    template <class Iterator_L, class Iterator_R>
        bool operator== (const reverse_iterator<Iterator_L>& lhs,
                        const reverse_iterator<Iterator_R>& rhs) { return (lhs.base() == rhs.base()); }

    template <class Iterator>
        bool operator!= (const reverse_iterator<Iterator>& lhs,
                        const reverse_iterator<Iterator>& rhs) { return (lhs.base() != rhs.base()); }

    /* For reverser_iterator != const_reverse_iterator */
    template <class Iterator_L, class Iterator_R>
        bool operator!= (const reverse_iterator<Iterator_L>& lhs,
                        const reverse_iterator<Iterator_R>& rhs) { return (lhs.base() != rhs.base()); }

    template <class Iterator>
        bool operator<  (const reverse_iterator<Iterator>& lhs,
                        const reverse_iterator<Iterator>& rhs) { return (lhs.base() > rhs.base()); }

    /* For reverser_iterator < const_reverse_iterator */
    template <class Iterator_L, class Iterator_R>
        bool operator< (const reverse_iterator<Iterator_L>& lhs,
                        const reverse_iterator<Iterator_R>& rhs) { return (lhs.base() > rhs.base()); }

    template <class Iterator>
        bool operator<= (const reverse_iterator<Iterator>& lhs,
                        const reverse_iterator<Iterator>& rhs) { return (lhs.base() >= rhs.base()); }

    /* For reverser_iterator <= const_reverse_iterator */
    template <class Iterator_L, class Iterator_R>
        bool operator<= (const reverse_iterator<Iterator_L>& lhs,
                        const reverse_iterator<Iterator_R>& rhs) { return (lhs.base() >= rhs.base()); }

    template <class Iterator>
        bool operator> (const reverse_iterator<Iterator>& lhs,
                        const reverse_iterator<Iterator>& rhs) { return (lhs.base() < rhs.bash()); }

    /* For reverser_iterator > const_reverse_iterator */
    template <class Iterator_L, class Iterator_R>
        bool operator> (const reverse_iterator<Iterator_L>& lhs,
                        const reverse_iterator<Iterator_R>& rhs) { return (lhs.base() < rhs.base()); }

    template <class Iterator>
        bool operator>= (const reverse_iterator<Iterator>& lhs,
                        const reverse_iterator<Iterator>& rhs) { return (lhs.base() <= rhs.base()); }

    /* For reverser_iterator >= const_reverse_iterator */
    template <class Iterator_L, class Iterator_R>
        bool operator>= (const reverse_iterator<Iterator_L>& lhs,
                        const reverse_iterator<Iterator_R>& rhs) { return (lhs.base() <= rhs.base()); }

    template <class Iterator>
        reverse_iterator<Iterator> operator+ (
            typename reverse_iterator<Iterator>::difference_type n,
            const reverse_iterator<Iterator>& rev_it) { return (rev_it + n); }

    template <class Iterator>
        typename reverse_iterator<Iterator>::difference_type operator- (
            const reverse_iterator<Iterator>& lhs,
            const reverse_iterator<Iterator>& rhs) { return (lhs.base() - rhs.base()); }

    /* For reverser_iterator - const_reverse_iterator */
    template <class Iterator_L, class Iterator_R>
        bool operator- (const reverse_iterator<Iterator_L>& lhs,
                        const reverse_iterator<Iterator_R>& rhs) { return (lhs.base() - rhs.base()); }


}


#endif