#include "ClapTrap.hpp"

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

	return 0;
}
