#include "Zombie.hpp"

int main() {
	Zombie*	hordeFabin = zombieHorde(10, "Fabin");
	Zombie* hordeDefault = zombieHorde(5, "Foo");
	
	for (int i = 0; i < 10; ++i) { hordeFabin[i].announce(); }
	delete[] hordeFabin;
	for (int i = 0; i < 5; ++i) { hordeDefault[i].announce(); }
	delete[] hordeDefault;
	return 0;
}
