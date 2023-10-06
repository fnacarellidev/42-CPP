#pragma once
#include "Contacts.hpp"
#include <iostream>

class Phonebook {

	private:
		int			contactsSaved;
		Contacts 	contacts[8];
	public:
		Phonebook(void) {
			contactsSaved = 0;
		};
		int		getContactsSaved(void);
		void	addContact(void);
		void	printContacts(void);
		void	searchContact(void);
		void	printContactInfo(int idx);
};
