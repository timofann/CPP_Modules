#include "AMateria.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include <string>
#include <iostream>

Character::Character(void) : name_("empty_name") {
	std::cout << "\033[3;35mCharacter \033[3;37m"
	          << "constructor called"
	          << "\033[0m" << std::endl;
	for (int i = 0; i < INVENTORY_SIZE; ++i)
		(this->inventory)[i] = nullptr;
}

Character::Character(const std::string &name) : name_(name) {
	std::cout << "\033[3;35mCharacter \033[3;37m"
	          << "constructor called"
	          << "\033[0m" << std::endl;
	for (int i = 0; i < INVENTORY_SIZE; ++i)
		(this->inventory)[i] = nullptr;
}

Character::Character(const Character &copy) : name_(copy.name_) {
	std::cout << "\033[3;35mCharacter \033[3;37m"
	          << "copy constructor called"
	          << "\033[0m" << std::endl;
	for (int i = 0; i < INVENTORY_SIZE; ++i) {
		delete (this->inventory)[i];
		(this->inventory)[i] = (copy.inventory)[i]->clone();
	}
}

Character::~Character(void) {
	std::cout << "\033[3;35mCharacter \033[3;37m"
	          << "destructor called"
	          << "\033[0m" << std::endl;
	for (int i = 0; i < INVENTORY_SIZE; ++i)
		delete (this->inventory)[i];
}

Character &Character::operator=(const Character &other) {
	std::cout << "\033[3;35mCharacter \033[3;37m"
	          << "copy assignment operator called"
	          << "\033[0m" << std::endl;
	if (this == &other)
		return *this;
	this->name_ = other.name_;
	for (int i = 0; i < INVENTORY_SIZE; ++i) {
		delete (this->inventory)[i];
		(this->inventory)[i] = (other.inventory)[i]->clone();
	}
	return *this;
}

std::string const &Character::getName(void) const {
	return this->name_;
}

void Character::equip(AMateria* materia) {
	for (int i = 0; i < INVENTORY_SIZE; ++i) {
		if ((this->inventory)[i] == nullptr) {
			(this->inventory)[i] = materia;
			break;
		}
	}
}

void Character::unequip(int idx) {
	if (idx >= 0 && idx < INVENTORY_SIZE)
		(this->inventory)[idx] = nullptr;
}

void Character::use(int idx, ICharacter& target) const {
	if (idx >= 0 && idx < INVENTORY_SIZE && ((this->inventory)[idx])) {
		((this->inventory)[idx])->use(target);
	}
}
