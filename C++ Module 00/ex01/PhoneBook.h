#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.h"
#include <string>

class PhoneBook {

public:
	size_t			id;
	size_t			records_cnt;
	Contact			records[8];
	static size_t	id_counter;
	PhoneBook(void);
	~PhoneBook(void);

	void	printInfo(void);
	void	add(void);
	void	search(void);
};

#endif
