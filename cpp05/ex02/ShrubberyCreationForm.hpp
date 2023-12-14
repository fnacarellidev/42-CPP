#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm {
	public:
		~ShrubberyCreationForm();
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm &copy);
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &copy);
		void execute(Bureaucrat const &buraucrat) const;
	private:
		std::string _target;
};
