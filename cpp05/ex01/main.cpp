#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
	{
		Form firstForm("fambio", 100, 100);
		Bureaucrat fabin("fabin", 1);

		fabin.signForm(firstForm);
		std::cout << firstForm << std::endl;
	}
	{
		Form firstForm("fambio", 151, 151);
	}

	return 0;
}
