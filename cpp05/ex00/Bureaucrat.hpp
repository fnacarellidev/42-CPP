#include <iostream>

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
		std::string		getName() const;
		unsigned int	getGrade() const;
		void			addGrade();
		void			subtractGrade();
		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat &bureaucrat);
