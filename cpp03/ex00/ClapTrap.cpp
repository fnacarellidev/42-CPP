#include "ClapTrap.hpp"
#include <string>

ClapTrap::~ClapTrap() { std::cout << "Destructor called" << std::endl; }

ClapTrap::ClapTrap() : _name ("Generic Clap Trap"), _hp (10), _sp (10), _ad (0) {
	std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hp(10), _sp(10), _ad(0) {
	std::cout << "Created clap trap with name " << _name << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy) {
	if (this != &copy)
		*this = copy;
	std::cout << "Copy constructor called" << std::endl;
}

ClapTrap	&ClapTrap::operator= (const ClapTrap &copy) {
	if (this != &copy) {
		_name = copy._name;
		_hp = copy._hp;
		_sp = copy._sp;
		_ad = copy._ad;
	}
	return *this;
}

void	ClapTrap::attack(const std::string &target) {
	if (_hp > 0 && _sp > 0) {
		_sp--;
		std::cout << target << " took " << _ad << " point of damage! It was attacked by " << _name << std::endl;
	}
}

void	ClapTrap::takeDamage(unsigned int amount) {
	if (_hp < 1) {
		std::cout << _name << " have no hit points left, thus it is dead." << std::endl;
		return ;
	}
	_hp -= amount;
	std::cout
		<< _name
		<< " took "
		<< amount
		<< (amount > 1 ? "points" : "point")
		<< " of damage!" <<
	std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (_hp < 1 || _sp < 1) {
		std::cout << _name << " can't repair itself, it has no health or energy points left!" << std::endl;
		return ;
	}
	_hp += amount;
	_sp--;
	std::cout
		<< _name
		<< " just healed itself by "
		<< amount
		<< (amount > 1 ? "points" : "point")
		<< " of health!" <<
	std::endl;
}
