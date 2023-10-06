#include "Phonebook.hpp"

int main(void) {
	std::string	prompt;
	Phonebook	phonebook;
	
	while (true) {
		std::cout << "Do you wish to ADD, SEARCH or EXIT?" << std::endl;
		if (!std::getline(std::cin, prompt))
			break ;
		if (prompt == "ADD") { phonebook.addContact(); }
		else if (prompt == "SEARCH") { phonebook.searchContact(); }
		else if (prompt == "EXIT") { break ; }
	};
	return 0;
}
