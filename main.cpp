#include <vector>
#include <iostream>
#include "vector.hpp"

int main()
{
	std::vector<int> v2;
	v2.push_back(1);
	v2.push_back(2);
	v2.push_back(3);
	std::vector<int> v(v2.begin(), v2.end());

	ft::vector<int> v1(v2.begin(), v2.end());

	std::cout << v.capacity() << std::endl;
	// v.push_back(7);
	// std::cout << v.capacity() << std::endl;

	return 0;
}