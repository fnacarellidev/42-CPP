#include "PmergeMe.hpp"

PmergeMe::~PmergeMe() {
#ifdef DEBUG
	std::cout << Default destructor called\n;
#endif
}

PmergeMe::PmergeMe(char **argv) {
#ifdef DEBUG
	std::cout << Default constructor called\n;
#endif
	for (int i = 1; argv[i]; ++i) {
		_numsVec.push_back(std::atoi(argv[i]));
	}
}

PmergeMe::PmergeMe(const PmergeMe &copy) {
#ifdef DEBUG
	std::cout << Copy destructor called\n;
#endif
	if (this != &copy)
		*this = copy;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& copy) {
	if (this != &copy)
		_numsVec = copy._numsVec;
	return *this;
}

std::vector<unsigned int> PmergeMe::getNumsVec() {
	return _numsVec;
}
