#pragma once
#include <iostream>
#include <sstream>
#include <limits>

class PmergeMe {
	private:
		~PmergeMe();
		PmergeMe();
		PmergeMe(const PmergeMe &copy);
		PmergeMe& operator=(const PmergeMe &copy);
};
