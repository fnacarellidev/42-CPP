#include "Brain.hpp"
#include <algorithm>

Brain::~Brain() { std::cout << "[BRAIN] Destructor called" << std::endl; }

Brain::Brain() { std::cout << "[BRAIN] Default constructor called" << std::endl; }

Brain::Brain(const Brain &copy) {
	std::cout << "[BRAIN] Copy constructor called" << std::endl;
	if (this != &copy)
		*this = copy;
}

Brain	&Brain::operator=(const Brain &copy) {
	if (this != &copy) {
		std::copy(copy.ideas->begin(), copy.ideas->end(), ideas);
	}
	return *this;
}
