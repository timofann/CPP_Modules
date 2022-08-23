#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"
#include <string>

class Character : public ICharacter {

#define INVENTORY_SIZE 4

private:
	Character(void);
	std::string         name_;
	AMateria            *inventory[INVENTORY_SIZE];

public:
	Character(const std::string &name);
	Character(const Character &copy);
	~Character(void);
	Character           &operator=(const Character &other);
	std::string const   &getName(void) const;
	void                equip(AMateria *materia);
	void                unequip(int idx);
	void                use(int idx, ICharacter &target) const;
};


#endif
