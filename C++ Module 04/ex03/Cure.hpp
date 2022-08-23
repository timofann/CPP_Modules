#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria {

public:
	Cure(void);
	Cure(const Cure &copy);
	~Cure(void);
	Cure    &operator=(const Cure &other);
	Cure    *clone(void) const;
	void    use(ICharacter &target) const;
};

#endif
