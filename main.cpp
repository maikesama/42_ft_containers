#include <vector>
#include <iostream>
#include "vector.hpp"

int main()
{
	std::vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	ft::vector<int> myv(v.begin(), v.end());
	ft::vector<int> myv1 = myv;
	myv1 = myv;

	std::cout << myv[0] << std::endl;
	std::cout << myv1[0] << std::endl;
	std::cout << myv[1] << std::endl;
	std::cout << myv1[1] << std::endl;
	std::cout << myv[2] << std::endl;
	std::cout << myv1[2] << std::endl;

	return 0;
}