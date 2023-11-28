#pragma once
#include "ScavTrap.hpp"

class FlagTrap : public ClapTrap {
	public:
		FlagTrap();
		FlagTrap(std::string name);
		FlagTrap(const FlagTrap &copy);
		FlagTrap & operator=(const FlagTrap &copy);
		~FlagTrap();
		void	highFivesGuys();
};
