#include "easyfind.hpp"
#include <list>

int main() {
	{
		std::cout << "TEST 1" << '\n';
		std::list<int> array;

		for (int i = 0; i <= 100; ++i)
			array.push_back(i);
		::easyfind(array, 1000);
		::easyfind(array, 1);
		::easyfind(array, 2000);
		::easyfind(array, 42);
		::easyfind(array, 22);
		::easyfind(array, 132);
	}
}
