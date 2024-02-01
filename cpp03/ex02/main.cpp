#include "FragTrap.hpp"

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
	std::cout << "\n\n";
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
	std::cout << "\n\n";
	{
		std::cout << "TEST 2" << std::endl;
		FragTrap	destroyer("Destroyer");

		destroyer.attack("clock");
		destroyer.printInfo();
		destroyer.beRepaired(100);
		destroyer.printInfo();
		destroyer.takeDamage(50);
		destroyer.printInfo();
		destroyer.takeDamage(100);
		destroyer.printInfo();
		destroyer.highFivesGuys();
		destroyer.takeDamage(50);
		destroyer.printInfo();
		destroyer.highFivesGuys();
	}
	return (0);
}
