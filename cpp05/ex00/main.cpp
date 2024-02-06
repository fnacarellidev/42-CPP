#include "Bureaucrat.hpp"

int main() {
	try {
		std::cout << "TEST 0 ATTEMPT TO CREATE A BUREAUCRAT WITH INVALID GRADE (151)\n";
		Bureaucrat first("fabin", 151);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	try {
		std::cout << "TEST 1 ATTEMPT TO CREATE A BUREAUCRAT WITH INVALID GRADE (0)\n";
		Bureaucrat first("fabin", 0);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	try {
		std::cout << "TEST 2 INCREMENT GRADE\n";
		Bureaucrat first("fabin", 1);
		first.addGrade();
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	try {
		std::cout << "TEST 3 DECREMENT GRADE\n";
		Bureaucrat first("fabin", 150);
		first.subtractGrade();
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
