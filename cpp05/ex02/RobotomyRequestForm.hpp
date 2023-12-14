#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
	public:
		~RobotomyRequestForm();
		RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(const RobotomyRequestForm &copy);
		RobotomyRequestForm &operator=(const RobotomyRequestForm &copy);
		void execute(Bureaucrat const &buraucrat) const;
	private:
		std::string _target;
};
