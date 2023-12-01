#include "Cat.hpp"

Cat::~Cat() {
	std::cout << "[CAT] Destructor called" << std::endl;
	delete _brain;
}

Cat::Cat() : Animal() {
	std::cout << "[CAT] Default constructor called" << std::endl;
	type = "Cat";
	_brain = new Brain();
}

Cat::Cat(const Cat &copy) : Animal(copy) {
	std::cout << "[CAT] Copy constructor called" << std::endl;
	if (this != &copy)
		*this = copy;
}

Cat	&Cat::operator=(const Cat &copy) {
	if (this != &copy) {
		type = copy.type;
		_brain = copy._brain;
	}
	return *this;
}

void	Cat::makeSound() const { std::cout << "[CAT] Meow" << std::endl; }

std::string	Cat::getIdea(size_t i) { return _brain->ideas[i]; }

void	Cat::setIdea(size_t i, std::string idea) {
	if (i < _brain->ideas->size()) _brain->ideas[i] = idea;
}
