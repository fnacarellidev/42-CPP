#include "HumanA.hpp"

void	HumanA::attack() {
	if (this->_weapon.getType().empty())
		std::cout << this->_name << " does not have a weapon." << std::endl;
	else
		std::cout << this->_name << " attacks with their " << this->_weapon.getType() << std::endl;
}

HumanA::HumanA(std::string name, Weapon &weapon): _weapon(weapon) {
	this->_name = name;
}
