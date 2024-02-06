#include "Bureaucrat.hpp"

Bureaucrat::~Bureaucrat() { std::cout << "[BUREAUCRAT] Default destructor called" << std::endl; }

Bureaucrat::Bureaucrat() : _name("DEFAULT"), _grade(150) { std::cout << "[BUREAUCRAT] Default constructor called" << std::endl; }

Bureaucrat::Bureaucrat(std::string name, unsigned int grade) : _name(name), _grade(grade) {
	std::cout << "[BUREAUCRAT] Constructor with parameters called" << std::endl;
	if (_grade < HIGH_GRADE)
		throw GradeTooHighException();
	else if (_grade > LOW_GRADE)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) {
	std::cout << "[BUREAUCRAT] Copy constructor called" << std::endl;
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

std::ostream &operator<<(std::ostream& os, const Bureaucrat &bureaucrat) {
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << std::endl;
	return os;
}
