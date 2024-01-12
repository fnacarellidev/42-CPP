#pragma once
#include <stack>

template <typename T>
class MutantStack: public std::stack<T> {
	public:
		typedef typename std::stack<T>::container_type::iterator StackIterator;

		~MutantStack() {}
		MutantStack() {}
		MutantStack(const MutantStack &copy) {
			if (this != &copy)
				*this = copy;
		}
		MutantStack &operator=(const MutantStack &copy) {
			if (this != &copy)
				std::stack<T>::operator=(copy);
			return *this;
		}
		StackIterator begin() {
			return this->c.begin();
		}
		StackIterator end() {
			return this->c.end();
		}
};
