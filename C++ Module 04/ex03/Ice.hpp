#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria {

public:
	Ice(void);
	Ice(const Ice &copy);
    ~Ice(void);
	Ice     &operator=(const Ice &other);
	Ice     *clone(void) const;
	void    use(ICharacter &target) const;
};


#endif
