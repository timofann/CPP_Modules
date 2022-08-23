#include "MateriaSource.hpp"
#include <string>
#include <iostream>

MateriaSource::MateriaSource(void) {
	std::cout << "\033[3;37mMateriaSource "
	          << "constructor called"
	          << "\033[0m" << std::endl;
	for (int i = 0; i < INVENTORY_SIZE; ++i) {
		(this->inventory)[i] = nullptr;
	}
}

MateriaSource::MateriaSource(const MateriaSource &copy) {
	std::cout << "\033[3;37mMateriaSource "
	          << "copy constructor called"
	          << "\033[0m" << std::endl;
	for (int i = 0; i < INVENTORY_SIZE; ++i) {
		if ((copy.inventory)[i] == nullptr)
			(this->inventory)[i] = nullptr;
		else
			(this->inventory)[i] = (copy.inventory)[i]->clone();
	}
}

MateriaSource::~MateriaSource(void) {
	std::cout << "\033[3;37mMateriaSource "
	          << "destructor called"
	          << "\033[0m" << std::endl;
	for (int i = 0; i < INVENTORY_SIZE; ++i)
		delete (this->inventory)[i];
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other) {
	std::cout << "\033[3;37mMateriaSource "
	          << "This code will never be running!"
	          << "\033[0m" << std::endl;
	if (this == &other)
		return *this;
	for (int i = 0; i < INVENTORY_SIZE; ++i) {
		if ((other.inventory)[i] == nullptr)
			(this->inventory)[i] = nullptr;
		else
			(this->inventory)[i] = (other.inventory)[i]->clone();
	}
	return *this;
}

void MateriaSource::learnMateria(AMateria *materia) {
	for (int i = 0; i < INVENTORY_SIZE; ++i)
		if ((this->inventory)[i] == nullptr) {
			(this->inventory)[i] = materia->clone();
			break;
		}
	delete materia;
}

AMateria *MateriaSource::createMateria(std::string const &type) {
	for (int i = 0; i < INVENTORY_SIZE; ++i)
		if ((this->inventory)[i] != nullptr
			&& (this->inventory)[i]->getType() == type) {
			return (this->inventory)[i]->clone();
		}
	return nullptr;
}
