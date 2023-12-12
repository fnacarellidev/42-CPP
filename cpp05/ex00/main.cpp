#include "Bureaucrat.hpp"

int main() {
	try {
		Bureaucrat first("fabin", 151);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	Bureaucrat first("fabin", 3);
	Bureaucrat second;

	std::cout << first << std::endl;
	first.addGrade();
	std::cout << first << std::endl;
	first.subtractGrade();
	std::cout << first << std::endl;

	std::cout << second << std::endl;

	return 0;
}
