#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {

	try {
		std::cout << "TEST 0 INVALID FORM EXEC\n";
		Form("Invalid00", 150, 151);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	try {
		std::cout << "TEST 1 INVALID FORM SIGN\n";
		Form("Invalid00", 151, 150);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	try {
		std::cout << "TEST 2 INVALID FORM EXEC\n";
		Form("Invalid00", 150, 0);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	try {
		std::cout << "TEST 3 INVALID FORM SIGN\n";
		Form("Invalid00", 0, 150);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	{
		std::cout << "TEST 4 BUREAUCRATS SIGNING FORMS\n";
		Bureaucrat	ceo = Bureaucrat("CEO", 1);
		Bureaucrat	intern = Bureaucrat("Intern", 150);
		Form		importantForm = Form("IMPORTANT FORM", 2, 2);

		ceo.signForm(importantForm);
		intern.signForm(importantForm);
	}

	return 0;
}
