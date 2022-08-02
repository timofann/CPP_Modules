#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class	Contact {

public:
	Contact(void);
	Contact(std::string	_first_name,
			std::string	_last_name,
			std::string	_nickname,
			std::string	_phone_number,
			std::string	_darkest_secret);
	~Contact(void);

	void	printInfo(void);
	std::string	getFirstName(void);
	std::string	getLastName(void);
	std::string	getNickname(void);
	std::string	getPhoneNumber(void);
	std::string	getDarkestSecret(void);
	void		setFirstName(std::string _first_name);
	void		setLastName(std::string _last_name);
	void		setNickname(std::string _nickname);
	void		setPhoneNumber(std::string _phone_number);
	void		setDarkestSecret(std::string _darkest_secret);

private:
	std::string	first_name;
	std::string	last_name;
	std::string	nickname;
	std::string	phone_number;
	std::string	darkest_secret;
};

#endif
