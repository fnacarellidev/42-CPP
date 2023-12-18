#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main() {
	Intern someRandomIntern;
	AForm* rrf;
	
	rrf = someRandomIntern.makeForm("robotomy request", "Bender"); 
	delete rrf;
	rrf = someRandomIntern.makeForm("robotomy requesty", "Bender"); 
	rrf = someRandomIntern.makeForm("presidential pardon", "Bender"); 
	delete rrf;
	return 0;
}
