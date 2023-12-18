#include <iostream>
#include "AForm.hpp"

class Intern {
	public:
		Intern();
		~Intern();
		Intern(const Intern &copy);
		Intern &operator=(const Intern &copy);
		AForm* makeForm(std::string formName, std::string formTarget);
};
