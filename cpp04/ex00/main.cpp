#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"
#include "WrongAnimal.hpp"

int main() {
	{
		std::cout << "SUBJECT TEST" << std::endl;
		const Animal	*meta = new Animal();
		const Animal	*j = new Dog();
		const Animal	*i = new Cat();

		std::cout << "\n\n";
		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		i->makeSound();
		j->makeSound();
		meta->makeSound();	
		std::cout << "\n\n";

		delete meta;
		delete j;
		delete i;
	}
	std::cout << "\n\n";
	{
		std::cout << "TEST 0" << std::endl;
		Cat kitty;
		Animal *animal = &kitty;

		std::cout << "\n\n";
		animal->makeSound();
		std::cout << "\n\n";
	}
	std::cout << "\n\n";
	{
		std::cout << "TEST 0" << std::endl;
		WrongCat wrongCat;
		WrongAnimal *wrongAnimal = &wrongCat;

		std::cout << "\n\n";
		wrongAnimal->makeSound();
		std::cout << "\n\n";
	}
	return (0);

}
