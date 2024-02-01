#include "Dog.hpp"

Dog::~Dog() {
	std::cout << "[DOG] Destructor called" << std::endl;
	delete _brain;
}

Dog::Dog() : Animal() {
	std::cout << "[DOG] Default constructor called" << std::endl;
	type = "Dog";
	_brain = new Brain();
}

Dog::Dog(const Dog &copy) : Animal(copy) {
	std::cout << "[DOG] Copy constructor called" << std::endl;
	_brain = NULL;
	if (this != &copy)
		*this = copy;
}

Dog	&Dog::operator=(const Dog &copy) {
	if (this != &copy) {
		type = copy.type;
		if (_brain) delete _brain;
		_brain = new Brain(*copy._brain);
	}
	return *this;
}

void	Dog::makeSound() const { std::cout << "[DOG] Woof" << std::endl; }

std::string	Dog::getIdea(size_t i) { return _brain->ideas[i]; }

void	Dog::setIdea(size_t i, std::string idea) {
	if (i < 100) _brain->ideas[i] = idea;
}
