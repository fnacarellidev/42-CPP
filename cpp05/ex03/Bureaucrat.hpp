#pragma once
#include <iostream>
#include "AForm.hpp"

class AForm;

class Bureaucrat {
	private:
		const std::string _name;
		unsigned int _grade;
		static const unsigned int HIGH_GRADE = 1;
		static const unsigned int LOW_GRADE = 150;
	public:
		~Bureaucrat();
		Bureaucrat();
		Bureaucrat(std::string name, unsigned int grade);
		Bureaucrat(const Bureaucrat &copy);
		Bureaucrat &operator=(const Bureaucrat &copy);
		void signForm(AForm &form) const;
		void executeForm(AForm const &form) const;
		std::string		getName() const;
		unsigned int	getGrade() const;
		void			addGrade();
		void			subtractGrade();
		friend std::ostream& operator<<(std::ostream& os, const Bureaucrat &bureaucrat);
		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
};
