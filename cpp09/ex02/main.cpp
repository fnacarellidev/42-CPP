#include "PmergeMe.hpp"

bool lessThanMaxInt(const std::string str)
{
	long int n;
	std::stringstream ss(str);

	ss >> n;
	return n > std::numeric_limits<int>::max() ? false : true;
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

int main(int argc, char **argv) {
	std::vector<unsigned int> vec;

	if (!validParams(argc, argv))
		return 1;
	for (int i = 1; argv[i]; ++i) {
		vec.push_back(std::atoi(argv[i]));
	}
	if (isSorted(vec)) {
		std::cout << "Already sorted\n";
		return 0;
	}
	std::clock_t	vectorStart = clock();
	PmergeMe::mergeInsertionSort(vec);
	std::clock_t	vectorEnd = clock();
	double vectorTime = double(vectorEnd - vectorStart) / CLOCKS_PER_SEC * 1e3;

	std::cout << "Time to process a range of " << vec.size() << " elements with std::vector : " << std::fixed << std::setprecision(3) << vectorTime << "ms\n";
}
