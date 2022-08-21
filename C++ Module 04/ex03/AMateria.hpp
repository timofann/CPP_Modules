#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <string>

class AMateria {
protected:
	std::string type_;
public:
	AMateria(std::string const &type);
	AMateria(const AMateria &copy);
	virtual             ~AMateria(void);
	AMateria            &operator=(const AMateria &other);
	std::string const   &getType() const; //Returns the materia type
	virtual AMateria    *clone() const = 0;
	virtual void        use(ICharacter &target);
};

#endif
