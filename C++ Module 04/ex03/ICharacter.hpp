#ifndef ICHARACTER_HPP
#define ICHARACTER_HPP

#include "general.hpp"
#include "AMateria.hpp"
#include <string>

class ICharacter {
public:
	virtual                     ~ICharacter(void) {}
	virtual std::string const   &getName(void) const = 0;
	virtual void                equip(AMateria *materia) = 0;
	virtual void                unequip(int idx) = 0;
	virtual void                use(int idx, ICharacter &target) const = 0;
};

#endif
