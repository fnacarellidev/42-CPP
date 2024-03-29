#include "PmergeMe.hpp"

bool	hasDuplicateNumber(std::vector<unsigned int> &vec)
{
	std::vector<unsigned int>	sorted(vec);
	std::sort(sorted.begin(), sorted.end());
	std::vector<unsigned int>::iterator	curr = sorted.begin();
	std::vector<unsigned int>::iterator	next = sorted.begin() + 1;

	while (next != sorted.end())
	{
		if (*curr == *next)
			return (true);
		curr++;
		next++;
	}
	return (false);
}

bool lessThanMaxInt(const std::string str)
{
	long int n;
	std::stringstream ss(str);

	ss >> n;
	return (n == 0 || n > std::numeric_limits<int>::max()) ? false : true;
}

bool isPositiveNumber(std::string str)
{
	std::string::iterator it = str.begin();

	if (*it == '-')
		return false;
	if (*it == '+' && str.length() > 1)
		it++;
	while (it != str.end() && isdigit(*it))
		it++;
	return (!str.empty() && it == str.end());
}

bool validParams(int argc, char **argv) {
	if (argc < 2)
		return false;
	for (int i = 1; argv[i]; ++i) {
		if (!isPositiveNumber(argv[i]) || !lessThanMaxInt(argv[i]))
			return false;
	}
	return true;
}

bool isSorted(std::vector<unsigned int> vec) {
	std::vector<unsigned int> sorted = vec;

	std::sort(sorted.begin(), sorted.end());
	return sorted == vec;
}

void testVector(std::vector<unsigned int> vec) {
	std::clock_t	vectorStart = clock();
	PmergeMe::mergeInsertionSort(vec);
	std::clock_t	vectorEnd = clock();
	double vectorTime = double(vectorEnd - vectorStart) / CLOCKS_PER_SEC * 1e3;

	std::cout << "Time to process a range of " << vec.size() << " elements with std::vector : " << std::fixed << std::setprecision(3) << vectorTime << "ms\n";
}

void testDeque(std::deque<unsigned int> deque) {
	std::clock_t	dequeStart = clock();
	PmergeMe::mergeInsertionSort(deque);
	std::clock_t	dequeEnd = clock();
	double dequeTime = double(dequeEnd - dequeStart) / CLOCKS_PER_SEC * 1e3;

	std::cout << "Time to process a range of " << deque.size() << " elements with std::deque : " << std::fixed << std::setprecision(3) << dequeTime << "ms\n";
}

int main(int argc, char **argv) {
	std::vector<unsigned int> vec;
	std::deque<unsigned int> deque;

	if (!validParams(argc, argv)) {
		std::cout << "Error\n";
		return 1;
	}

	for (int i = 1; argv[i]; ++i) {
		vec.push_back(std::atoi(argv[i]));
		deque.push_back(std::atoi(argv[i]));
	}
	if (hasDuplicateNumber(vec)) {
		std::cout << "Shouldn't have duplicate numbers\n";
		return 1;
	}
	else if (isSorted(vec)) {
		std::cout << "Already sorted\n";
		return 0;
	}

	testVector(vec);
	testDeque(deque);
}
