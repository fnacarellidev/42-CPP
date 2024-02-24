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


int main(int argc, char **argv) {
	if (!validParams(argc, argv))
		return 1;
}
