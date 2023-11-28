#include "FlagTrap.hpp"

FlagTrap::~FlagTrap() { std::cout << "[FLAG TRAP] Destructor called" << std::endl; }

FlagTrap::FlagTrap() : ClapTrap() {
	std::cout << "[FLAG TRAP] Default constructor called" << std::endl;
	_name = "Default Flag Trap";
	_hp = 100;
	_sp = 100;
	_ad = 30;
}

FlagTrap::FlagTrap(std::string name) : ClapTrap(name) {
	std::cout << "[FLAG TRAP] Named constructor called" << std::endl;
	_name = name;
	_hp = 100;
	_sp = 100;
	_ad = 30;
}

FlagTrap::FlagTrap(const FlagTrap &copy) : ClapTrap(copy) {
	std::cout << "[FLAG TRAP] Copy constructor called" << std::endl;
	if (this != &copy)
		*this = copy;
}

FlagTrap	&FlagTrap::operator= (const FlagTrap &copy) {
	if (this != &copy) {
		_name = copy._name;
		_hp = copy._hp;
		_sp = copy._sp;
		_ad = copy._ad;
	}
	return *this;
}

void	FlagTrap::highFivesGuys(void) {
	std::cout << "High five request made with success" << std::endl;
}
