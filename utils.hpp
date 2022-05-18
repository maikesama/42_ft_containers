#ifndef UTILS_HPP
#define UTILS_HPP

namespace ft
{

	/* equal */
	template <class InputIterator1, class InputIterator2>
 	bool equal (InputIterator1 first1, InputIterator1 last1,
             		InputIterator2 first2)
	{
		while (first1 != last1)
		{
			if (*first1 != *first2)
				return false;
			first1++;
			first2++;
		}
		return true;
	}

	template <class InputIterator1, class InputIterator2, class BinaryPredicate>
	bool equal (InputIterator1 first1, InputIterator1 last1,
				InputIterator2 first2, BinaryPredicate pred)
	{
		while (first1 != last1)
		{
			if (pred(*first1, *first2) == false)
				return false;
			first1++;
			first2++;
		}
		return true;
	}

	/* lexicographical_compare */
	template <class InputIterator1, class InputIterator2>
  	bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1,
                                InputIterator2 first2, InputIterator2 last2)
	{
		while (first1 != last1)
		{
			if (first2 == last2 || *first2 < *first1)
				return false;
			else if (*first1 < *first2)
				return true;
			first1++;
			first2++;
		}
		if (first2 != last2)
			return true;
		return false;
	}

	template <class InputIterator1, class InputIterator2, class Compare>
  	bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1,
                                InputIterator2 first2, InputIterator2 last2,
                                Compare comp)
	{
		while (first1 != last1)
		{
			if (first2 == last2)
				return false;
			else if (comp(*first1, *first2))
				return true;
			first1++;
			first2++;
		}
		if (first2 != last2)
			return true;
		return false;
	}

	/* Distance between pointers */
	template < class InputIterator >
	int	distance(InputIterator start, InputIterator end)
	{
		int	dist = 0;
		for(; start != end; start++)
		{
			dist++;
		}
		return dist;
	}


	/* Our enable_if */
	template < bool Cond, class T > struct enable_if{};
	template < class T > struct enable_if< true, T > { typedef T type; };


	/* IsIntegral condition */
	template < bool isIntegral, typename T >
		struct is_integral_res {
			typedef T type;
			static const bool value = isIntegral;
		};

	// default case (false)
	template < typename >
		struct is_integral_type : public is_integral_res < false, bool > {};

	// case bool (true)
	template <>
		struct is_integral_type<bool> : public is_integral_res < true, bool > {};

	// case char (true)
	template <>
        struct is_integral_type<char> : public is_integral_res<true, char> {};

    // case signed char (true)
    template <>
        struct is_integral_type<signed char> : public is_integral_res<true, signed char> {};

    // case short int (true)
    template <>
        struct is_integral_type<short int> : public is_integral_res<true, short int> {};
    
    // case int (true)
    template <>
        struct is_integral_type<int> : public is_integral_res<true, int> {};

    // case long int (true)
    template <>
        struct is_integral_type<long int> : public is_integral_res<true, long int> {};

    // case long long int (true)
    template <>
        struct is_integral_type<long long int> : public is_integral_res<true, long long int> {};

    // case unsigned char (true)
    template <>
        struct is_integral_type<unsigned char> : public is_integral_res<true, unsigned char> {};

    // case unsigned short int (true)
    template <>
        struct is_integral_type<unsigned short int> : public is_integral_res<true, unsigned short int> {};

    // case unsigned int (true)
    template <>
        struct is_integral_type<unsigned int> : public is_integral_res<true, unsigned int> {};

    // case unsigned long int (true)
    template <>
        struct is_integral_type<unsigned long int> : public is_integral_res<true, unsigned long int> {};
    
    // case unsigned long long int (true)
    template <>
        struct is_integral_type<unsigned long long int> : public is_integral_res<true, unsigned long long int> {};

	// structure where the type will be verified
	template < typename T >
		struct is_integral : public is_integral_type<T> {}; 


}

#endif