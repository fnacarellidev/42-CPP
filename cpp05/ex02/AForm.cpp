#include "AForm.hpp"

AForm::~AForm() {
#ifdef DEBUG
	std::cout << "[FORM] Default destructor called" << std::endl;
#endif
}

AForm::AForm():
	_name("DEFAULT"),
	_gradeToSign(150),
	_gradeToExecute(150),
	_signed(false)
{
#ifdef DEBUG
	std::cout << "[FORM] Default constructor called" << std::endl;
#endif
}

AForm::AForm(std::string name, unsigned int gradeToSign, unsigned int gradeToExecute, bool isSigned):
	_name(name),
	_gradeToSign(gradeToSign),
	_gradeToExecute(gradeToExecute),
	_signed(isSigned)
{
#ifdef DEBUG
	std::cout << "[FORM] Named constructor called" << std::endl;
#endif
	if (_gradeToSign < 1 || _gradeToExecute < 1)
		throw GradeTooHighException();
	else if (_gradeToSign > 150 || _gradeToExecute > 150)
		throw GradeTooLowException();
};

AForm::AForm(const AForm &copy):
	_name(""),
	_gradeToSign(0),
	_gradeToExecute(0),
	_signed(true)
{
#ifdef DEBUG
	std::cout << "[FORM] Copy constructor called" << std::endl;
#endif
	if (this != &copy)
		*this = copy;
}

AForm &AForm::operator=(const AForm &copy) {
	if (this != &copy)
		_signed = copy._signed;
	return *this;
}

void AForm::beSigned(const Bureaucrat &bureaucrat) {
	bureaucrat.getGrade() > _gradeToSign ? throw (AForm::GradeTooLowException()) : _signed = true;
}

std::string AForm::getName() const { return _name; }

unsigned int AForm::getGradeToSign() const { return _gradeToSign; }

unsigned int AForm::getGradeToExecute() const { return _gradeToExecute; }

bool AForm::isSigned() const { return _signed; }

std::ostream &operator<<(std::ostream& os, const AForm &form) {
	os <<
		"[FORM] Name: " << form.getName() <<
		", grade to sign: " << form.getGradeToSign() <<
		", grade to execute: " << form.getGradeToExecute() <<
		", signed? " << std::boolalpha << (bool)form.isSigned() << std::endl;
	return os;
}

const char* AForm::GradeTooHighException::what() const throw() {
	return ("[FORM] Grade too high!");
}

const char* AForm::GradeTooLowException::what() const throw() {
	return ("[FORM] Grade too low!");
}

const char *AForm::FormNotSigned::what() const throw() {
	return ("[FORM] Form not signed!");
}
