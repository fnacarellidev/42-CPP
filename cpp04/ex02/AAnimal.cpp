#include "AAnimal.hpp"

AAnimal::~AAnimal() { std::cout << "[AANIMAL] Destructor called" << std::endl; }

AAnimal::AAnimal() : type("Base class animal") {
	std::cout << "[AANIMAL] Default constructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal &copy) {
	std::cout << "[AANIMAL] Copy constructor called" << std::endl;
	if (this != &copy)
		*this = copy;
}

AAnimal &AAnimal::operator=(const AAnimal &copy) {
	if (this != &copy)
		type = copy.type;
	return *this;
}

std::string	AAnimal::getType() const { return this->type; }
