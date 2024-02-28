#pragma once
#include <stack>

template <typename T>
class MutantStack: public std::stack<T> {
	public:
		typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
		typedef typename std::stack<T>::container_type::iterator iterator;

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
		iterator begin() {
			return this->c.begin();
		}
		iterator end() {
			return this->c.end();
		}
		reverse_iterator rbegin() {
			return this->c.rbegin();
		}
		reverse_iterator rend() {
			return this->c.rend();
		}
};
