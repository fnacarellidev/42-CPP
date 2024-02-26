#include "PmergeMe.hpp"

int jacobsthal(int n) {
	if (n <= 1) return n;
	return (jacobsthal(n - 1) + 2 * jacobsthal(n - 2));
}

std::vector<int> getJacobsthalInsertionSequence(size_t size) {
	int	next;
	int	jacobsthalIterator = 2;
	std::vector<int> insertionSequence;

	if (size < 1)
		return insertionSequence;

	next = jacobsthal(jacobsthalIterator++);
    insertionSequence.push_back(next);
	while (insertionSequence.size() < size) {
		next = jacobsthal(jacobsthalIterator);
		if (next >= static_cast<int>(size))
			next = size;
		while (insertionSequence.size() < size && next > 0) {
			insertionSequence.push_back(next);
			if (std::find(insertionSequence.begin(), insertionSequence.end(), next - 1) != insertionSequence.end())
				break;
			next--;
		}
		jacobsthalIterator++;
	}

	return insertionSequence;
}

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

std::vector<std::pair<unsigned int, unsigned int> > createPairs(std::vector<unsigned int> vec) {
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

void	insertionLookup(std::vector<unsigned int> &sorted, std::vector<unsigned int> pendent, size_t index) {
	for (std::vector<unsigned int>::iterator it = sorted.begin(); it != sorted.end(); ++it) {
		if (pendent[index] > *it && (it + 1 == sorted.end() || pendent[index] < *(it + 1))) {
			sorted.insert(it + 1, pendent[index]);
			break;
		}
	}
}

void PmergeMe::mergeInsertionSort(std::vector<unsigned int> vec) {
	std::vector<unsigned int> sorted;
	std::vector<unsigned int> pendent;
	bool foundStraggler = vec.size() % 2 != 0;
	unsigned int straggler;

	if (foundStraggler) {
		straggler = vec.back();
		vec.pop_back();
	}

	std::vector<std::pair<unsigned int, unsigned int> > vecPairs = createPairs(vec);

	_sortPairs(vecPairs, vecPairs.size());

	for (std::vector<std::pair<unsigned int, unsigned int> >::iterator it = vecPairs.begin(); it != vecPairs.end(); ++it) {
		sorted.push_back(it->first);
		pendent.push_back(it->second);
	}

	if (foundStraggler)
		pendent.push_back(straggler);
	sorted.insert(sorted.begin(), pendent[0]);
	std::vector<int> insertionSequence = getJacobsthalInsertionSequence(pendent.size() - 1);

	if (insertionSequence.size()) {
		for (std::vector<int>::iterator it = insertionSequence.begin(); it != insertionSequence.end(); ++it) {
			if (pendent[*it] < sorted.front())
				sorted.insert(sorted.begin(), pendent[*it]);
			else
				insertionLookup(sorted, pendent, *it);
		}
	}
}
