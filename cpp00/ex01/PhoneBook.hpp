#pragma once
#include "Contacts.hpp"
#include <iostream>

class PhoneBook {

	private:
		int			contactsSaved;
		Contacts 	contacts[8];
	public:
		PhoneBook();
		int		getContactsSaved(void);
		void	addContact(void);
		void	printContacts(void);
		void	searchContact(void);
		void	printContactInfo(int idx);
};
