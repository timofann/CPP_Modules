#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "AMateria.hpp"
#include "IMateriaSource.hpp"

#define INVENTORY_SIZE 4

class MateriaSource : public IMateriaSource {

private:
	AMateria        *inventory[INVENTORY_SIZE];

public:
	MateriaSource(void);
	MateriaSource(const MateriaSource &copy);
	~MateriaSource(void);
	MateriaSource   &operator=(const MateriaSource &other);
	void            learnMateria(AMateria *materia);
	AMateria        *createMateria(std::string const &type);
};

#endif
