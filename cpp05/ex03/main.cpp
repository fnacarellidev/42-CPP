#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main() {
	{
		std::cout << "TEST 0\n";
		Intern someRandomIntern;
		AForm* rrf;

		rrf = someRandomIntern.makeForm("robotomy request", "Bender"); 
		delete rrf;
		rrf = someRandomIntern.makeForm("shrubbery creation", "test2");
		delete rrf;
		rrf = someRandomIntern.makeForm("presidential pardon", "test3");
		delete rrf;
		rrf = someRandomIntern.makeForm("typo form", "42");
	}
	{
		Bureaucrat ceo = Bureaucrat("ceo", 1);
		AForm *shrub;
		AForm *robotomy;
		AForm *presidential;
		Intern intern;

		shrub = intern.makeForm("shrubbery creation", "shrub");
		robotomy = intern.makeForm("robotomy request", "robotomy");
		presidential = intern.makeForm("presidential pardon", "presidential");

		ceo.signForm(*shrub);
		ceo.signForm(*robotomy);
		ceo.signForm(*presidential);

		ceo.executeForm(*shrub);
		ceo.executeForm(*robotomy);
		ceo.executeForm(*presidential);

		delete shrub;
		delete robotomy;
		delete presidential;
	}
	return 0;
}
