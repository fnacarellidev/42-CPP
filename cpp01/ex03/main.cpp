#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"

int main() {
	{
		std::cout << "TEST 0" << std::endl;
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
		club.setType("");
		bob.attack();
	}
	{
		std::cout << "TEST 1" << std::endl;
		Weapon club = Weapon("crude spiked club");
		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
		club.setType("");
		jim.attack();
	}
	{
		std::cout << "TEST 2" << std::endl;
		Weapon	sword = Weapon("Long Sword");
		HumanA	bob("Bob", sword);
		bob.attack();
		sword.setType("Large sword");
		bob.attack();

		Weapon	bow = Weapon("Short Bow");
		HumanB	jim("Jim");
		jim.setWeapon(bow);
		jim.attack();
		bow.setType("Long Bow");
		jim.attack();
	}
	return 0;
}
