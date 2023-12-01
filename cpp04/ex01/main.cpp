#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main() {
	Dog		*new_doggo = new Dog();
	/* Animal **animals = new Animal*[100]; */

	/* for (int i = 0; i < 50; ++i) */
	/* 	animals[i] = new Cat(); */
	/* for (int i = 50; i < 100; ++i) */
	/* 	animals[i] = new Dog(); */

	/* for (int i = 0; i < 100; ++i) { */
	/* 	std::cout << animals[i]->getType() << std::endl; */
	/* 	delete animals[i]; */
	/* } */

	new_doggo->setIdea(0, "chimkem numgets");
	std::cout << new_doggo->getIdea(0) << std::endl;
	delete new_doggo;
	return (0);
}
