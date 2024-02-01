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
		ScavTrap	fabin("fabin");

		fabin.attack("clock");
		fabin.guardGate();
		fabin.printInfo();
		fabin.beRepaired(50);
		fabin.printInfo();
		fabin.takeDamage(50);
		fabin.printInfo();
		fabin.takeDamage(100);
		fabin.printInfo();
		fabin.guardGate();
	}
	return (0);
}
