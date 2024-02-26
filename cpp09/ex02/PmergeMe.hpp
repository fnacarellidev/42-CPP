#pragma once
#include <iostream>
#include <sstream>
#include <limits>
#include <vector>
#include <cstdlib>
#include <algorithm>

class PmergeMe {
	private:
		std::vector<unsigned int> _numsVec;

	public:
		~PmergeMe();
		PmergeMe(char **argv);
		PmergeMe(const PmergeMe &copy);
		PmergeMe& operator=(const PmergeMe &copy);
		std::vector<unsigned int> getNumsVec();
		void logVec(std::vector<std::pair<unsigned int, unsigned int> > vecPairs);
};
