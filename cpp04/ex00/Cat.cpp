#include "Cat.hpp"

Cat::~Cat() { std::cout << "[CAT] Destructor called" << std::endl; }

Cat::Cat() : Animal() {
	std::cout << "[CAT] Default constructor called" << std::endl;
	type = "Cat";
}

Cat::Cat(const Cat &copy) : Animal(copy) {
	std::cout << "[CAT] Copy constructor called" << std::endl;
	if (this != &copy)
		*this = copy;
}

Cat	&Cat::operator=(const Cat &copy) {
	if (this != &copy) {
		type = copy.type;
	}
	return *this;
}

void	Cat::makeSound() const { std::cout << "[CAT] Meow" << std::endl; }
