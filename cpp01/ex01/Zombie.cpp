#include "Zombie.hpp"

Zombie::Zombie() {
	this->_name = "Foo";
}

Zombie::Zombie(std::string name) {
	this->_name = name;
}

void	Zombie::announce() {
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::~Zombie() {
	std::cout << this->_name << ": Deallocated" << std::endl;
}

void	Zombie::setName(std::string name) {
	this->_name = name;
}
