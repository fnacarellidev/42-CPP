#pragma once
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
	private:
		const std::string _name;
		const unsigned int _gradeToSign;
		const unsigned int _gradeToExecute;
		bool _signed;
	public:
		~Form();
		Form();
		Form(std::string name, unsigned int gradeToSign, unsigned int gradeToExecute, bool isSigned = false);
		Form(const Form &copy);
		Form &operator=(const Form &copy);
		void beSigned(Bureaucrat bureaucrat);
		std::string getName() const;
		unsigned int getGradeToSign() const;
		unsigned int getGradeToExecute() const;
		bool isSigned() const;
		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream& os, const Form &form);
