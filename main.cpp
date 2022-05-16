#include <vector>
#include <iostream>
#include "vector.hpp"

int main()
{

	ft::vector<int> myv;
	for (int i = 1; i < 10; i++) myv.push_back(i);

	myv.pop_back();

	std::cout << myv.front() << std::endl;
	std::cout << myv.back() << std::endl;
	for (int i = 0; i < myv.size(); i++)
		std::cout << myv[i] << " ";

	return 0;
}