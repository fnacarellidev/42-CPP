#include "MutantStack.hpp"
#include <iostream>

int main() {
	{
		std::cout << "TEST 1 DEFAULT ITERATOR\n";
		MutantStack<int> test;

		test.push(10);
		test.push(20);
		test.push(30);
		MutantStack<int>::iterator end = test.end();

		for (MutantStack<int>::iterator it = test.begin(); it != end; ++it)
			std::cout << *it << '\n';
	}
	std::cout << "\n";
	{
		std::cout << "TEST 2 REVERSE ITERATOR\n";
		MutantStack<int> test;

		for (int i = 0; i < 10; ++i)
			test.push(i);
		MutantStack<int>::reverse_iterator end = test.rend();

		for (MutantStack<int>::reverse_iterator it = test.rbegin(); it != end; ++it)
			std::cout << *it << '\n';

		std::cout << "\n";
		std::cout << "TEST 3 REVERSE ITERATOR WITH COPY\n";
		MutantStack<int> test2 = test;

		MutantStack<int>::reverse_iterator test2end = test2.rend();

		for (MutantStack<int>::reverse_iterator it = test2.rbegin(); it != test2end; ++it)
			std::cout << *it << '\n';
	}
}
