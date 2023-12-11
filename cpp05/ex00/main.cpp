#include "Bureaucrat.hpp"

int main() {
	try {
		Bureaucrat first("fabin", 151);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	Bureaucrat first("fabio", 150);

	std::cout << first << std::endl;
	first.addGrade();
	std::cout << first << std::endl;

	return 0;
}
