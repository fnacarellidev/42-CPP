#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main() {
	// AAnimal abstractAnimal = Aanimal(); // won't compile

	{
		Dog		*new_doggo = new Dog();
		Dog		*new_doggo2 = new Dog(*new_doggo);
		AAnimal **animals = new AAnimal*[100];

		for (int i = 0; i < 50; ++i)
			animals[i] = new Cat();
		for (int i = 50; i < 100; ++i)
			animals[i] = new Dog();

		for (int i = 0; i < 100; ++i)
			delete animals[i];

		new_doggo->setIdea(0, "chimkem numgets");
		std::cout << new_doggo->getIdea(0) << std::endl;
		std::cout << (void*) new_doggo << std::endl;
		std::cout << (void*) new_doggo2 << std::endl;

		delete new_doggo;
		delete new_doggo2;
		delete[] animals;
	}
	return (0);
}
