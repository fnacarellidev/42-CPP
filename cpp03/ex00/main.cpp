#include "ClapTrap.hpp"

int main() {
	ClapTrap standard;
	ClapTrap fabin("fabin");
	ClapTrap rand(fabin);

	fabin.attack("random");
}
