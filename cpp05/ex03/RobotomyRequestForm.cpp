#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << "[ROBOTOMYREQUESTFORM] Default destructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(): AForm("Robotomy form", 72, 45), _target("Default") {
	std::cout << "[ROBOTOMYREQUESTFORM] Default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm("Robotomy form", 72, 45), _target(target) {
	std::cout << "[ROBOTOMYREQUESTFORM] Named constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &obj) : AForm("Robotomy form", 72, 45)
{
	std::cout << "[ROBOTOMYREQUESTFORM] Copy constructor called" << std::endl;
	if (this != &obj)
		*this = obj;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &copy)
{
	if (this != &copy)
		_target = copy._target;
	return (*this);
}

void RobotomyRequestForm::execute(Bureaucrat const &bureaucrat) const {
	if (!this->isSigned()) throw(AForm::FormNotSigned());
	else if (bureaucrat.getGrade() > this->getGradeToExecute()) throw(AForm::GradeTooLowException());

	bureaucrat.executeForm(*this);
	std::cout << "*** DRILLING NOISES ***" << std::endl;
	std::cout << _target << " has been robotomized." << std::endl;
}
