#include <vector>
#include <iostream>
#include "vector.hpp"
#include "stack.hpp"
#include <vector>

int main()
{

	
	ft::vector<int> myv;
	
	for (int i = 0; i < 10; i++) myv.push_back(i);

	//ft::vector<int> copy;
	
	
	
	 ft::vector<int>::iterator it = myv.begin();
	// copy.insert(it, 7, 6);
	it++;
	it++;
	myv.erase(it, myv.end());
	myv.push_back(1);
	for (unsigned long int i = 0; i < myv.size(); i++)
		std::cout << myv[i] << std::endl;

	// ft::vector<int>::reverse_iterator rit = myv.rbegin();

	// if (myv <= mv) std::cout << "min" << std::endl;
	// if (myv >= mv) std::cout << "greater" << std::endl;

	
	// for (; rit != myv.rend(); rit++)
	// 	std::cout << *rit << std::endl;


	// for (ft::vector<int>::iterator it = mv.begin(); it != mv.end(); it++)
	// 	std::cout << *it << " ";

	// for (unsigned long int i = 0; i < myv.size(); i++)
	// 	std::cout << myv[i] << " ";
	// std::cout << std::endl;
	// for (unsigned long int i = 0; i < mv.size(); i++)
	// 	std::cout << mv[i] << " ";
	// std::cout << std::endl;

	return 0;
}