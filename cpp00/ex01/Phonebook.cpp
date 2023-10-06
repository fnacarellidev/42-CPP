#include "Phonebook.hpp"
#include "Prompt.hpp"

void	Phonebook::addContact(void) {
	std::string lastName;
	std::string nickname;
	std::string firstName;
	std::string phoneNumber;
	std::string darkestSecret;

	firstName = Prompt::readField("first name");
	lastName = Prompt::readField("last name");
	nickname = Prompt::readField("nickname");
	phoneNumber = Prompt::readField("phone number");
	darkestSecret = Prompt::readField("darkest secret");
	this->contacts[this->contactsSaved % 8].setLastName(lastName);
	this->contacts[this->contactsSaved % 8].setNickname(nickname);
	this->contacts[this->contactsSaved % 8].setFirstName(firstName);
	this->contacts[this->contactsSaved % 8].setPhoneNumber(phoneNumber);
	this->contacts[this->contactsSaved % 8].setDarkestSecret(darkestSecret);
	this->contactsSaved++;
}

void		Phonebook::printContacts(void) {
	Contacts	currentContact;

	for (int i = 0; i < this->contactsSaved % 8; ++i) {
		currentContact = this->contacts[i];
		Prompt::printTemplate(i);
		Prompt::printTemplate(currentContact.getFirstName());
		Prompt::printTemplate(currentContact.getLastName());
		Prompt::printTemplate(currentContact.getNickname());
		std::cout << '\n';
	}
}

void	Phonebook::searchContact(void) {
	int	index;

	this->printContacts();
	index = Prompt::readIndex();
	if (index < 0 || index >= (this->contactsSaved % 8)) {
		std::cout << "Index out of range\n";
		return ;
	}
	this->printContactInfo(index);
}

void	Phonebook::printContactInfo(int idx) {
	Contacts contact = this->contacts[idx];

	std::cout << contact.getFirstName() << std::endl;
	std::cout << contact.getLastName() << std::endl;
	std::cout << contact.getNickname() << std::endl;
	std::cout << contact.getPhoneNumber() << std::endl;
	std::cout << contact.getDarkestSecret() << std::endl;
}
