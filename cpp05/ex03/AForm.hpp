#pragma once
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
	private:
		const std::string _name;
		const unsigned int _gradeToSign;
		const unsigned int _gradeToExecute;
		bool _signed;
	public:
		virtual ~AForm();
		AForm();
		AForm(std::string name, unsigned int gradeToSign, unsigned int gradeToExecute, bool isSigned = false);
		AForm(const AForm &copy);
		AForm &operator=(const AForm &copy);
		void beSigned(const Bureaucrat &bureaucrat);
		friend std::ostream& operator<<(std::ostream& os, const AForm &form);
		std::string getName() const;
		unsigned int getGradeToSign() const;
		unsigned int getGradeToExecute() const;
		bool isSigned() const;
		virtual void execute(Bureaucrat const &bureaucrat) const = 0;
		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		class FormNotSigned : public std::exception {
			public:
				virtual const char* what() const throw();
		};
};
