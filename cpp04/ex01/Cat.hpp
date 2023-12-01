#pragma once
#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
	public:
		Cat();
		Cat(const Cat &copy);
		~Cat();
		Cat &operator=(const Cat &copy);
		void	makeSound() const;
		void		setIdea(size_t i, std::string idea);
		std::string	getIdea(size_t i);;
	private:
		Brain	*_brain;
};
