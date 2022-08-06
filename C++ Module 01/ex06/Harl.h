#ifndef HARL_H
#define HARL_H

#include <string>

class Harl;

typedef struct s_pair {
  	std::string	m_name;
  	void (Harl::*member)(void);
}	t_pair;

class Harl {

public:
  Harl(std::string complain_lvl);
  ~Harl(void);
  void	complain(std::string level);

 private:
    t_pair	pairs[4];
	size_t	_complain_lvl;
	void	debug(void);
	void	info(void);
	void	warning(void);
	void	error(void);
};

#endif
