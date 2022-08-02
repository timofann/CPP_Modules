#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class	Contact {

public:
	int 		index;
	std::string	first_name;
	std::string	last_name;
	std::string	nickname;
	std::string	phone_number;
	std::string	darkest_secret;
	Contact(void);
	Contact(std::string	_first_name,
			std::string	_last_name,
			std::string	_nickname,
			std::string	_phone_number,
			std::string	_darkest_secret);
	~Contact(void);

	void	printInfo(void);
};

#endif
