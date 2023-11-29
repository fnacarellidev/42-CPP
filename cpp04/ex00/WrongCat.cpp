#include "WrongCat.hpp"

WrongCat::~WrongCat() { std::cout << "[WRONG CAT] Destructor called" << std::endl; }

WrongCat::WrongCat() : WrongAnimal() {
	std::cout << "[WRONG CAT] Default constructor called" << std::endl;
	type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &copy) : WrongAnimal(copy) {
	std::cout << "[WRONG CAT] Copy constructor called" << std::endl;
	if (this != &copy)
		*this = copy;
}

WrongCat	&WrongCat::operator=(const WrongCat &copy) {
	if (this != &copy) {
		type = copy.type;
	}
	return *this;
}

void	WrongCat::makeSound() const { std::cout << "[WRONG CAT] Meow" << std::endl; }
