#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout << "[PRESIDENTIALPARDONFORM] Default destructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(): AForm("Presidential form", 25, 5), _target("Default") {
	std::cout << "[PRESIDENTIALPARDONFORM] Default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target): AForm("Presidential form", 25, 5), _target(target) {
	std::cout << "[PRESIDENTIALPARDONFORM] Named constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &obj) : AForm("Presidential form", 25, 5)
{
	std::cout << "[PRESIDENTIALPARDONFORM] Copy constructor called" << std::endl;
	if (this != &obj)
		*this = obj;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &copy)
{
	if (this != &copy)
		_target = copy._target;
	return (*this);
}

void PresidentialPardonForm::execute(Bureaucrat const &bureaucrat) const {
	if (!this->isSigned()) throw(AForm::FormNotSigned());
	else if (bureaucrat.getGrade() > this->getGradeToExecute()) throw(AForm::GradeTooLowException());

	bureaucrat.executeForm(*this);
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
