#include "Animal.hpp"

Animal::~Animal() { std::cout << "[ANIMAL] Destructor called" << std::endl; }

Animal::Animal() : type("Base class animal") {
	std::cout << "[ANIMAL] Default constructor called" << std::endl;
}

Animal::Animal(const Animal &copy) {
	std::cout << "[ANIMAL] Copy constructor called" << std::endl;
	if (this != &copy)
		*this = copy;
}

Animal &Animal::operator=(const Animal &copy) {
	if (this != &copy)
		type = copy.type;
	return *this;
}

void	Animal::makeSound() const { std::cout << "[ANIMAL] Default sound" << std::endl; }

std::string	Animal::getType() const { return this->type; }
