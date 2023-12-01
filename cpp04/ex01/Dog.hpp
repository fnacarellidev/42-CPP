#pragma once
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
	public:
		Dog();
		Dog(const Dog &copy);
		~Dog();
		Dog &operator=(const Dog &copy);
		void	makeSound() const;
		void		setIdea(size_t i, std::string idea);
		std::string	getIdea(size_t i);;
	private:
		Brain	*_brain;
};
