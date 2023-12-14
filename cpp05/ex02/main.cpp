#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main() {
	{
		ShrubberyCreationForm test1("okaoka");
		Bureaucrat		failsToExecute("rand", 144);

		failsToExecute.signForm(test1);
		try {
			test1.execute(failsToExecute);
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}
	{
		ShrubberyCreationForm test1("okaoka");
		Bureaucrat		succeedsToExecute("rand", 1);

		succeedsToExecute.signForm(test1);
		try {
			test1.execute(succeedsToExecute);
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}
	return 0;
}
