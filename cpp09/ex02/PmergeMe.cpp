#include "PmergeMe.hpp"

PmergeMe::~PmergeMe() {
#ifdef DEBUG
	std::cout << Default destructor called\n;
#endif
}

PmergeMe::PmergeMe() {
#ifdef DEBUG
	std::cout << Default constructor called\n;
#endif
}

PmergeMe::PmergeMe(const PmergeMe &copy) {
#ifdef DEBUG
	std::cout << Copy destructor called\n;
#endif
	if (this != &copy)
		*this = copy;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& copy) {
	(void) copy;
	return *this;
}
