#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::~ShrubberyCreationForm() {
#ifdef DEBUG
	std::cout << "[SHRUBBERYCREATIONFORM] Default destructor called" << std::endl;
#endif
}

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("Shrubbery Form", 145, 137), _target("Default") {
#ifdef DEBUG
	std::cout << "[SHRUBBERYCREATIONFORM] Default constructor called" << std::endl;
#endif
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): AForm("Shrubbery Form", 145, 137), _target(target) {
#ifdef DEBUG
	std::cout << "[SHRUBBERYCREATIONFORM] Named constructor called" << std::endl;
#endif
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &obj) : AForm("Shrubbery Form", 145, 137)
{
#ifdef DEBUG
	std::cout << "[SHRUBBERYCREATIONFORM] Copy constructor called" << std::endl;
#endif
	if (this != &obj)
		*this = obj;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &copy)
{
	if (this != &copy)
		_target = copy._target;
	return (*this);
}

void ShrubberyCreationForm::execute(Bureaucrat const &bureaucrat) const {
	std::string filename = _target + "_shrubbery";

	if (!this->isSigned()) throw(AForm::FormNotSigned());
	else if (bureaucrat.getGrade() > this->getGradeToExecute()) throw(AForm::GradeTooLowException());
	std::ofstream file(filename.c_str());
	file << "      /\\      " << std::endl;
	file << "     /\\*\\     " << std::endl;
	file << "    /\\O\\*\\    " << std::endl;
	file << "   /*\\/\\/*\\   " << std::endl;
	file << "  /\\O\\/\\*\\/\\  " << std::endl;
	file << " /\\*\\/\\*\\/\\/\\ " << std::endl;
	file << "/\\O\\/\\/*\\/\\O/\\" << std::endl;
	file << "      ||      " << std::endl;
	file << "      ||      " << std::endl;
	file << "      ||      " << std::endl;
	file.close();
}
