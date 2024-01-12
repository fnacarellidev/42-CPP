#pragma once
#include <cstdlib>
#include <vector>
#include <iostream>
#include <limits>
#include <algorithm>
#include <iterator>
#include <exception>

class Span {
	private:
		std::vector<int> _vec;
		size_t _slotsAvailable;
		Span();

	public:
		~Span();
		Span(size_t size);
		Span(const Span& copy);
		Span &operator=(const Span& copy);
		void addNumber(int num);
		template <typename it>
		void addNumber(it begin, it end) {
			for (it iterator = begin; iterator != end; ++iterator)
				addNumber(*iterator);
		};
		int shortestSpan();
		int longestSpan();
};
