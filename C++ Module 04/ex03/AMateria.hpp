#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include "general.hpp"
#include "ICharacter.hpp"
#include <string>

class AMateria {
protected:
	std::string         type_;
public:
	AMateria(std::string const &type);
	AMateria(const AMateria &copy);
	virtual             ~AMateria(void);
	AMateria            &operator=(const AMateria &other);
	std::string const   &getType(void) const;
	virtual AMateria    *clone(void) const = 0;
	virtual void        use(ICharacter &target) const;
};

#endif
