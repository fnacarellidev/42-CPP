#include "ScavTrap.hpp"

int main() {
	{
		std::cout << "TEST 0" << std::endl;
		ClapTrap defaultClap;

		defaultClap.attack("clock");
		defaultClap.beRepaired(10);
		defaultClap.printInfo();
		defaultClap.beRepaired(10);
		defaultClap.beRepaired(10);
		defaultClap.printInfo();
		defaultClap.takeDamage(40);
		defaultClap.printInfo();
		defaultClap.takeDamage(40);
	}
	{
		std::cout << "TEST 1" << std::endl;
		ScavTrap	riny("fabin");

		riny.attack("clock");
		riny.guardGate();
		riny.printInfo();
		riny.beRepaired(50);
		riny.printInfo();
		riny.takeDamage(50);
		riny.printInfo();
		riny.takeDamage(100);
		riny.printInfo();
		riny.guardGate();
	}
	return (0);
}
