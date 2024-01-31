#include "FragTrap.hpp"

FragTrap::~FragTrap() { std::cout << "[FRAG TRAP] Destructor called" << std::endl; }

FragTrap::FragTrap() : ClapTrap() {
	std::cout << "[FRAG TRAP] Default constructor called" << std::endl;
	_name = "Default Frag Trap";
	_hp = 100;
	_sp = 100;
	_ad = 30;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	std::cout << "[FRAG TRAP] Named constructor called" << std::endl;
	_name = name;
	_hp = 100;
	_sp = 100;
	_ad = 30;
}

FragTrap::FragTrap(const FragTrap &copy) : ClapTrap(copy) {
	std::cout << "[FRAG TRAP] Copy constructor called" << std::endl;
	if (this != &copy)
		*this = copy;
}

FragTrap	&FragTrap::operator= (const FragTrap &copy) {
	if (this != &copy) {
		_name = copy._name;
		_hp = copy._hp;
		_sp = copy._sp;
		_ad = copy._ad;
	}
	return *this;
}

void	FragTrap::highFivesGuys(void) {
	std::cout << "High five request made with success" << std::endl;
}
