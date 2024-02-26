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

std::vector<std::pair<unsigned int, unsigned int> > createPairs(PmergeMe *mergeMe) {
	std::vector<unsigned int> vec = mergeMe->getNumsVec();
	std::vector<std::pair<unsigned int, unsigned int> > vecPairs;

	for (std::vector<unsigned int>::iterator it = vec.begin(); it != vec.end(); it += 2) {
		if (*it > *(it + 1))
			vecPairs.push_back(std::pair<unsigned int, unsigned int>(*it, *(it + 1)));
		else
			vecPairs.push_back(std::pair<unsigned int, unsigned int>(*(it + 1), *it));
	}

	return vecPairs;
}

void	_sortPairs(std::vector<std::pair<unsigned int, unsigned int> > &pairs, size_t size) {
	if (size <= 1) return ;

	std::vector<std::pair<unsigned int, unsigned int> >::iterator mid = pairs.begin() + (size / 2);
	std::vector<std::pair<unsigned int, unsigned int> > left(pairs.begin(), mid);
	std::vector<std::pair<unsigned int, unsigned int> > right(mid, pairs.end());
	size_t	vecIdx = 0;
	size_t	leftIdx = 0;
	size_t	rightIdx = 0;

	_sortPairs(left, left.size());
	_sortPairs(right, right.size());

	while (leftIdx < left.size() && rightIdx < right.size()) {
		if (left[leftIdx].first <= right[rightIdx].first) {
			pairs[vecIdx] = left[leftIdx];
			leftIdx++;
		}
		else {
			pairs[vecIdx] = right[rightIdx];
			rightIdx++;
		}
		vecIdx++;
	}

	for (; leftIdx < left.size(); ++leftIdx)
		pairs[vecIdx++] = left[leftIdx];
	for (; rightIdx < right.size(); ++rightIdx)
		pairs[vecIdx++] = right[rightIdx];
}

void PmergeMe::logVec(std::vector<std::pair<unsigned int, unsigned int> > vecPairs) {
	for (std::vector<std::pair<unsigned int, unsigned int> >::iterator it = vecPairs.begin(); it != vecPairs.end(); ++it) {
		std::cout << it->first << ", " << it->second << std::endl;
	}
}

void PmergeMe::mergeInsertionSort() {
	bool foundStraggler = _numsVec.size() % 2 != 0;
	unsigned int straggler;

	if (foundStraggler) {
		straggler = _numsVec.back();
		_numsVec.pop_back();
	}

	std::vector<std::pair<unsigned int, unsigned int> > vecPairs = createPairs(this);

	_sortPairs(vecPairs, vecPairs.size());

	std::vector<unsigned int> sorted;
	std::vector<unsigned int> pendent;

	for (std::vector<std::pair<unsigned int, unsigned int> >::iterator it = vecPairs.begin(); it != vecPairs.end(); ++it) {
		sorted.push_back(it->first);
		pendent.push_back(it->second);
	}
	if (foundStraggler)
		pendent.push_back(straggler);
	sorted.insert(sorted.begin(), pendent[0]);
}

std::vector<unsigned int> PmergeMe::getNumsVec() {
	return _numsVec;
}
