#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
	public:
		~PresidentialPardonForm();
		PresidentialPardonForm();
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(const PresidentialPardonForm &copy);
		PresidentialPardonForm &operator=(const PresidentialPardonForm &copy);
		void execute(Bureaucrat const &buraucrat) const;
	private:
		std::string _target;
};
