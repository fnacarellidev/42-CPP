#include "Zombie.hpp"

int main(void) {
	Zombie*	zombieFabin = newZombie("Fabin");
	Zombie*	zombieReinan = newZombie("Reinan");
	Zombie*	zombieVini = newZombie("Vini");

	zombieVini->announce();
	zombieFabin->announce();
	zombieReinan->announce();
	randomChump("Foo");
	randomChump("Bar");
	randomChump("Unnamed");
	delete zombieFabin;
	delete zombieReinan;
	delete zombieVini;
	return 0;
}
