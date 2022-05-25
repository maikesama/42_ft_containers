#include <vector>
#include <iostream>
#include "vector.hpp"
#include "stack.hpp"
#include "pair.hpp"
#include <vector>

int main()
{

	
	
	ft::pair<int, char> p1(7, 'a');

	ft::pair<int, char> p2 = ft::make_pair(8, 'M');
	
	if (p1 < p2)
		std::cout << "yup" << std::endl;
	else
		std::cout << "nope" << std::endl;

	// for (unsigned long int i = 0; i < copy.size(); i++)
	// 	std::cout << copy[i] << std::endl;

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