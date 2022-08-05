#ifndef HARL_H
#define HARL_H

#include <string>

typedef void (*PFunc)(void);

typedef struct s_pair {
  	std::string	f_name;
    PFunc		*handler;
}	t_pair;

class Harl {
 public:
  Harl(void);
  ~Harl(void);
	void	complain(std::string level);

 private:
  	t_pair	pairs[4];
	void			debug(void);
	void			info(void);
	void			warning(void);
	void			error(void);
};

#endif
