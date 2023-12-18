#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::~Intern() {
	std::cout << "[INTERN] Default destructor called" << std::endl;
}

Intern::Intern() {
	std::cout << "[BUREAUCRAT] Default constructor called" << std::endl;
}

Intern::Intern(const Intern &copy) {
	std::cout << "[BUREAUCRAT] Copy constructor called" << std::endl;
	if (this != &copy)
		*this = copy;
}

Intern &Intern::operator=(const Intern &copy) {
	(void) copy;
	return *this;
}

static AForm *makePresidentialPardonForm(std::string target)
{
	return (new PresidentialPardonForm(target));
}

static AForm *makeRobotomyRequestForm(std::string target)
{
	return (new RobotomyRequestForm(target));
}

static AForm *makeShrubberyCreationForm(std::string target)
{
	return (new ShrubberyCreationForm(target));
}

AForm* Intern::makeForm(std::string formName, std::string formTarget) {
	AForm		*(*funcs[])(std::string) = { makePresidentialPardonForm, makeRobotomyRequestForm, makeShrubberyCreationForm };
	std::string	validForms[] = { "presidential pardon", "robotomy request", "shrubbery creation" };

	for (int i = 0; i < 3; ++i)
		if (formName == validForms[i]) {
			std::cout << "Intern creates " << formName << std::endl;
			return funcs[i](formTarget);
		}
	std::cout << "There's no such " << formName << " form :(" << std::endl;
	return NULL;
}
