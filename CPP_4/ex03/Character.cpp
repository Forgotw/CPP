/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsohler <lsohler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 18:53:32 by lsohler           #+#    #+#             */
/*   Updated: 2024/02/02 14:44:03 by lsohler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "Colors.h"

Character::Character() {
	this->_name = "NoName";
	for (int i = 0; i < 4; i++) {
		_materiaList[i] = nullptr;
	}
	std::cout << CHARACTER DEFCONS << std::endl;
}

Character::Character(std::string const &name) {
	this->_name = name;
	for (int i = 0; i < 4; i++) {
		_materiaList[i] = nullptr;
	}
	std::cout << CHARACTER DEFCONS << std::endl;
}

Character::Character(Character const &other) {
	this->_name = other.getName();
	for (int i = 0; i < 4; i++) {
		_materiaList[i] = other.getCharacterMateria(i);
	}
	std::cout << CHARACTER COPYCONS << std::endl;
}

Character::~Character(void) {
	for (int i = 0; i < 4; i++) {
		if (_materiaList[i] != nullptr){
			delete _materiaList[i];
		}
	}
	std::cout << CHARACTER DEFDES << std::endl;

}

Character &Character::operator=(Character const &other) {
	if (this != &other) {
		_name = other.getName();
		for (int i = 0; i < 4; i++) {
			if (_materiaList[i] != nullptr){
				delete _materiaList[i];
			}
			_materiaList[i] = other.getCharacterMateria(i);
		}
	}
	std::cout << CHARACTER OPECONS << std::endl;
	return(*this);
}

std::string const &	Character::getName(void) const {
	return (_name);
}

//return * ou pas a avoir
AMateria*	Character::getCharacterMateria(int i) const {
	return (_materiaList[i]);
}

void	Character::equip(AMateria* m) {
	for (int i = 0; i < 4; i++) {
		if (this->_materiaList[i] == nullptr) {
			this->_materiaList[i] = m;
			std::cout << EQUIPED CYAN << i << RESET << std::endl; 
			return ;
		}
	}
	std::cout << INVENTORYFULL << std::endl;
}

void	Character::unequip(int idx) {
	_materiaList[idx] = nullptr;
	
}

void	Character::use(int idx, ICharacter& target) {
	if (_materiaList[idx] != nullptr) {
		_materiaList[idx]->use(target);
	}
	else {
		std::cout << NOSPELL CYAN << idx <<  RESET << std::endl;
	}
}
