#include "MutantStack.hpp"
#include <iostream>

int main() {
	MutantStack<int> test;

	test.push(10);
	test.push(20);
	test.push(30);
	MutantStack<int>::StackIterator end = test.end();

	for (MutantStack<int>::StackIterator begin = test.begin(); begin != end; ++begin)
		std::cout << *begin << '\n';
}
