#include "WrongAnimal.hpp"

WrongAnimal::~WrongAnimal() { std::cout << "[WRONG ANIMAL] Destructor called" << std::endl; }

WrongAnimal::WrongAnimal() : type("Base class animal") {
	std::cout << "[WRONG ANIMAL] Default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy) {
	std::cout << "[WRONG ANIMAL] Copy constructor called" << std::endl;
	if (this != &copy)
		*this = copy;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &copy) {
	if (this != &copy)
		type = copy.type;
	return *this;
}

void	WrongAnimal::makeSound() const { std::cout << "[WRONG ANIMAL] Default sound" << std::endl; }

std::string	WrongAnimal::getType() const { return this->type; }
