#pragma once
#include <iostream>

class ClapTrap {
	protected:
		std::string	_name;
		int			_hp;
		int			_sp;
		int			_ad;
	public:
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap &copy);
		ClapTrap & operator= (const ClapTrap &copy);
		~ClapTrap();
		void	attack(const std::string &target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
		void	printInfo();
};
