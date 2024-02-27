#pragma once
#include <iostream>
#include <sstream>
#include <limits>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <utility>
#include <list>
#include <ctime>
#include <iomanip>
#include <deque>

class PmergeMe {
	private:
		~PmergeMe();
		PmergeMe();
		PmergeMe(const PmergeMe &copy);
		PmergeMe& operator=(const PmergeMe &copy);

	public:
		static void mergeInsertionSort(std::vector<unsigned int> vec);
		static void mergeInsertionSort(std::deque<unsigned int> vec);
};
