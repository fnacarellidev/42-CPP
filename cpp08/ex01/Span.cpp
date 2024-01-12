#include "Span.hpp"

Span::Span() {}

Span::~Span() { std::cout << "[SPAN] Destructor called" << '\n'; }

Span::Span(size_t size) {
	_slotsAvailable = size;
}

Span::Span(const Span& copy) {
	if (this != &copy)
		*this = copy;
}

Span& Span::operator=(const Span& copy) {
	if (this != &copy) {
		_slotsAvailable = copy._slotsAvailable;
		_vec = copy._vec;
	}
	return *this;
}

void Span::addNumber(int num) {
	if (_slotsAvailable == 0) throw std::exception();
	_slotsAvailable--;
	_vec.push_back(num);
}

int Span::shortestSpan() {
	if (_vec.end() - _vec.begin() < 2) throw std::exception();
	int minSpan = std::numeric_limits<int>::max();

	std::sort(_vec.begin(), _vec.end());
	for (std::vector<int>::iterator start = _vec.begin(); start < _vec.end() - 1; ++start) {
		int currSpan = *(start + 1) - *start;
		if (currSpan < minSpan)
			minSpan = currSpan;
	}

	return minSpan;
}

int Span::longestSpan() {
	if (_vec.end() - _vec.begin() < 2) throw std::exception();

	std::sort(_vec.begin(), _vec.end());
	return _vec.back() - _vec.front();
}
