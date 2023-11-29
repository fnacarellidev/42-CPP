#include "Dog.hpp"

Dog::~Dog() { std::cout << "[DOG] Destructor called" << std::endl; }

Dog::Dog() : Animal() {
	std::cout << "[DOG] Default constructor called" << std::endl;
	type = "Dog";
}

Dog::Dog(const Dog &copy) : Animal(copy) {
	std::cout << "[DOG] Copy constructor called" << std::endl;
	if (this != &copy)
		*this = copy;
}

Dog	&Dog::operator=(const Dog &copy) {
	if (this != &copy) {
		type = copy.type;
	}
	return *this;
}

void	Dog::makeSound() const { std::cout << "[DOG] Woof" << std::endl; }
