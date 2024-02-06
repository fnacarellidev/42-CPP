#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main() {
	{
		std::cout << "SUBJECT TEST\n";
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		delete j;
		delete i;
	}
	{
		std::cout << "TEST 0\n";
		Dog		*new_doggo = new Dog();
		Dog		*new_doggo2 = new Dog(*new_doggo);
		Animal **animals = new Animal*[100];

		for (int i = 0; i < 50; ++i)
			animals[i] = new Cat();
		for (int i = 50; i < 100; ++i)
			animals[i] = new Dog();

		for (int i = 0; i < 50; ++i) {
			if (animals[i]->getType() != "Cat")
				std::cout << "That's not a cat" << std::endl;
			delete animals[i];
		}

		for (int i = 50; i < 100; ++i) {
			if (animals[i]->getType() != "Dog")
				std::cout << "That's not a dog" << std::endl;
			delete animals[i];
		}

		new_doggo->setIdea(0, "chimkem numgets");
		std::cout << new_doggo->getIdea(0) << std::endl;
		std::cout << "TEST IF THE ADDRESSES ARE DIFFERENT\n";
		std::cout << (void*) new_doggo << std::endl;
		std::cout << (void*) new_doggo2 << std::endl;

		*new_doggo2 = *new_doggo;
		std::cout << new_doggo2->getIdea(0) << std::endl;

		delete new_doggo;
		delete new_doggo2;
		delete[] animals;
	}

	return (0);
}
