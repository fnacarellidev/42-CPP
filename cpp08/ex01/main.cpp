#include "Span.hpp"

int main() {
	Span sp(20);
	std::vector<int> x;

	x.push_back(10);
	x.push_back(12);
	x.push_back(32);
	x.push_back(40);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	sp.addNumber(x.begin(), x.end());

	std::cout << sp.shortestSpan() << '\n';
	std::cout << sp.longestSpan() << '\n';

	return 0;
}
