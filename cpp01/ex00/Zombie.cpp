#include "Zombie.hpp"

Zombie::Zombie() {
	this->name = "Foo";
}

Zombie::Zombie(std::string name) {
	this->name = name;
}

void	Zombie::announce() {
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::~Zombie() {
	std::cout << this->name << ": Deallocated" << std::endl;
}
