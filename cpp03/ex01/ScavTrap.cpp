#include <iostream>
#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
	std::cout << "[SCAV TRAP] default constructor called" << std::endl;
	_name = "Default Scav Trap";
	_hp = 100;
	_sp = 50;
	_ad = 20;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	std::cout << "[SCAV TRAP] name: " << name << std::endl;
	_name = name;
	_hp = 100;
	_sp = 50;
	_ad = 20;
}

ScavTrap::ScavTrap(const ScavTrap &copy) : ClapTrap(copy) {
	std::cout << "[SCAV TRAP] Called copy constructor" << std::endl;
	if (this != &copy)
		*this = copy;
}

ScavTrap::~ScavTrap() {
	std::cout << "[SCAV TRAP] Destructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &copy) {
	if (this != &copy) {
		_name = copy._name;
		_hp = copy._hp;
		_sp = copy._sp;
		_ad = copy._ad;
	}
	return *this;
}

void ScavTrap::attack(const std::string &target) {
	if (_hp > 0 && _sp > 0) {
		_sp--;
		std::cout << "[SCAV TRAP] " << target << " took " << _ad << " point of damage! It was attacked by " << _name << std::endl;
	}
}

void	ScavTrap::guardGate() {
	if (_hp < 1) {
		std::cout << "[SCAV TRAP] " << _name << " can't enable guard gate mode, it has no hp left." << std::endl;
		return ;
	}
	std::cout << "Guard gate mode enabled for " << _name << std::endl;
}
