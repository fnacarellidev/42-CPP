#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int main() {
	{
		std::cout << "TEST 0\n";
		Bureaucrat				ceo("ceo", 1);
		ShrubberyCreationForm	shrub("shrub");
		RobotomyRequestForm		robotomy("robotomy");
		PresidentialPardonForm	presidential("presidential");

		std::cout << ceo << std::endl;

		ceo.signForm(shrub);
		ceo.signForm(robotomy);
		ceo.signForm(presidential);
		std::cout << std::endl;
		std::cout << shrub << std::endl;
		std::cout << robotomy << std::endl;
		std::cout << presidential << std::endl;
		std::cout << std::endl;
		ceo.executeForm(shrub);
		std::cout << std::endl;
		ceo.executeForm(robotomy);
		std::cout << std::endl;
		ceo.executeForm(presidential);
	}
	{
		std::cout << "TEST 1\n";
		
		Bureaucrat				ceo("ceo", 1);
		Bureaucrat				intern("intern", 150);
		ShrubberyCreationForm	shrub("shrub");
		RobotomyRequestForm		robotomy("robotomy");
		PresidentialPardonForm	presidential("presidential");

		std::cout << ceo << std::endl;
		std::cout << intern << std::endl;
		std::cout << std::endl;

		intern.executeForm(shrub);
		intern.executeForm(robotomy);
		intern.executeForm(presidential);
		std::cout << std::endl;
		intern.signForm(shrub);
		intern.signForm(robotomy);
		intern.signForm(presidential);
		std::cout << std::endl;
		intern.executeForm(shrub);
		intern.executeForm(robotomy);
		intern.executeForm(presidential);
		std::cout << std::endl;
		ceo.signForm(shrub);
		ceo.signForm(robotomy);
		ceo.signForm(presidential);
		std::cout << std::endl;
		intern.executeForm(shrub);
		intern.executeForm(robotomy);
		intern.executeForm(presidential);
	}
	return 0;
}
