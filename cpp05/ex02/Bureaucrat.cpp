#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::~Bureaucrat() {
#ifdef DEBUG
	std::cout << "[BUREAUCRAT] Default destructor called" << std::endl;
#endif
}

Bureaucrat::Bureaucrat() : _name("DEFAULT"), _grade(150) {
#ifdef DEBUG
	std::cout << "[BUREAUCRAT] Default constructor called" << std::endl;
#endif
}

Bureaucrat::Bureaucrat(std::string name, unsigned int grade) : _name(name), _grade(grade) {
#ifdef DEBUG
	std::cout << "[BUREAUCRAT] Constructor with parameters called" << std::endl;
#endif
	if (_grade < HIGH_GRADE)
		throw GradeTooHighException();
	else if (_grade > LOW_GRADE)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) {
#ifdef DEBUG
	std::cout << "[BUREAUCRAT] Copy constructor called" << std::endl;
#endif
	if (this != &copy)
		*this = copy;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &copy) {
	if (this != &copy) {
		this->~Bureaucrat();
		new (this) Bureaucrat(copy._name, copy._grade);
	}
	return *this;
}

std::string	Bureaucrat::getName() const { return _name; }

unsigned int Bureaucrat::getGrade() const { return _grade; }

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return ("Grade too high!");
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return ("Grade too low!");
}

void	Bureaucrat::addGrade() { 
	_grade--;
	if (_grade < HIGH_GRADE)
		throw GradeTooHighException();
}

void	Bureaucrat::subtractGrade() {
	_grade++;
	if (_grade > LOW_GRADE)
		throw GradeTooLowException();
}

void Bureaucrat::signForm(AForm &form) const {
	try {
		form.beSigned(*this);
		std::cout << this->getName() << " signed " << form.getName() << std::endl;
	} catch (std::exception &e) {
		std::cout << this->getName() << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
	}
}

void Bureaucrat::executeForm(AForm const &form) const {
	try {
		form.execute(*this);
		std::cout << _name << " executed " << form.getName() << std::endl;
	} catch (std::exception &e) {
		std::cout << _name << " couldn't execute " << form.getName() << " because " << e.what() << std::endl;
	}
}

std::ostream &operator<<(std::ostream& os, const Bureaucrat &bureaucrat) {
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << std::endl;
	return os;
}
