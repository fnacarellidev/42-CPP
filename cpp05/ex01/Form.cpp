#include "Form.hpp"

Form::~Form() {
#ifdef DEBUG
	std::cout << "[FORM] Default destructor called" << std::endl;
#endif
}

Form::Form():
	_name("DEFAULT"),
	_gradeToSign(150),
	_gradeToExecute(150),
	_signed(false)
{
#ifdef DEBUG
	std::cout << "[FORM] Default constructor called" << std::endl;
#endif
}

Form::Form(std::string name, unsigned int gradeToSign, unsigned int gradeToExecute, bool isSigned):
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

Form::Form(const Form &copy):
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

Form &Form::operator=(const Form &copy) {
	if (this != &copy) {
		this->~Form();
		new (this) Form(copy._name, copy._gradeToSign, copy._gradeToExecute, copy._signed);
	}
	return *this;
}

void Form::beSigned(Bureaucrat bureaucrat) {
	bureaucrat.getGrade() > _gradeToSign ? throw (Form::GradeTooLowException()) : _signed = true;
}

std::string Form::getName() const { return _name; }

unsigned int Form::getGradeToSign() const { return _gradeToSign; }

unsigned int Form::getGradeToExecute() const { return _gradeToExecute; }

bool Form::isSigned() const { return _signed; }

std::ostream &operator<<(std::ostream& os, const Form &form) {
	os <<
		"[FORM] Name: " << form.getName() <<
		", grade to sign: " << form.getGradeToSign() <<
		", grade to execute: " << form.getGradeToExecute() <<
		", signed? " << std::boolalpha << (bool)form.isSigned() << std::endl;
	return os;
}

const char* Form::GradeTooHighException::what() const throw() {
	return ("[FORM] Grade too high!");
}

const char* Form::GradeTooLowException::what() const throw() {
	return ("[FORM] Grade too low!");
}

