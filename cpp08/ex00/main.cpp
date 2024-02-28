#include "easyfind.hpp"
#include <list>
#include <vector>

int main() {
	{
		std::cout << "TEST 1 LIST<INT>\n";
		std::list<int> array;

		for (int i = 0; i <= 100; ++i)
			array.push_back(i);
		easyfind(array, 1000);
		easyfind(array, 1);
		easyfind(array, 2000);
		easyfind(array, 42);
		easyfind(array, 22);
		easyfind(array, 132);
	}
	std::cout << "\n";
	{
		std::cout << "TEST 2 VECTOR<INT>\n";
		std::vector<int> vector;

		for (int i = 0; i <= 10000; ++i)
			vector.push_back(i);
		easyfind(vector, 1);
		easyfind(vector, 2);
		easyfind(vector, 42);
		easyfind(vector, 10001);
		easyfind(vector, 20000);
		easyfind(vector, 42000);
	}
}
