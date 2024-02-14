#include "iter.hpp"

int main() {
	{
		int a[] = {1, 1, 2, 3, 5};

		::iter(a, 5, plusOne);
	}
	std::cout << "\n";
	{
		std::string strArr[] = {"fabo", "fambo", "test"};

		::iter(strArr, 3, logString);
	}
}
