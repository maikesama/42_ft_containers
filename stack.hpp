#ifndef STACK_HPP
#define STACK_HPP

#include "vector.hpp"

namespace ft
{
	template < class T, class Container = ft::vector<T> >
	class stack
	{
		public :
		typedef T value_type;
		typedef Container container_type;
		typedef size_t size_type;

		explicit stack (const container_type& ctnr = container_type()) : cont(ctnr) {}

		bool empty() const { return cont.empty(); }

		size_type size() const { return cont.size(); }

		value_type& top() { return cont.back(); }

		const value_type& top() const { return cont.back(); }

		void push (const value_type& val) { cont.push_back( val ); }

		void pop() { cont.pop_back(); }

		template <class Tn, class ContainerN>
		friend bool operator== (const stack<Tn,ContainerN>& lhs, const stack<Tn,ContainerN>& rhs);

		template <class Tn, class ContainerN>
  		friend bool operator!= (const stack<Tn,ContainerN>& lhs, const stack<Tn,ContainerN>& rhs);

		template <class Tn, class ContainerN>
  		friend bool operator< (const stack<Tn,ContainerN>& lhs, const stack<Tn,ContainerN>& rhs);

		template <class Tn, class ContainerN>
  		friend bool operator> (const stack<Tn,ContainerN>& lhs, const stack<Tn,ContainerN>& rhs);

		template <class Tn, class ContainerN>
  		friend bool operator<= (const stack<Tn,ContainerN>& lhs, const stack<Tn,ContainerN>& rhs);

		template <class Tn, class ContainerN>
  		friend bool operator>= (const stack<Tn,ContainerN>& lhs, const stack<Tn,ContainerN>& rhs);

		private:
			container_type cont;

	};

	template <class T, class Container>
	bool operator== (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		if (lhs.cont == rhs.cont)
			return true;
		return false;
	}

	template <class T, class Container>
  	bool operator!= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		if (lhs.cont != rhs.cont)
			return true;
		return false;
	}

	template <class T, class Container>
  	bool operator< (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		if (lhs.cont < rhs.cont)
			return true;
		return false;
	}

	template <class T, class Container>
  	bool operator> (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		if (lhs.cont > rhs.cont)
			return true;
		return false;
	}

	template <class T, class Container>
  	bool operator<= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		if (lhs.cont <= rhs.cont)
			return true;
		return false;
	}

	template <class T, class Container>
  	bool operator>= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		if (lhs.cont >= rhs.cont)
			return true;
		return false;
	}

}


#endif