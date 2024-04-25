/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsohler <lsohler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 18:53:32 by lsohler           #+#    #+#             */
/*   Updated: 2024/02/05 13:14:18 by lsohler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "Colors.h"

Character::Character(void) {
	this->_name = "NoName";
	for (int i = 0; i < 4; i++) {
		_materiaList[i] = nullptr;
	}
	constructionMsg(CHARACTER DEFCONS, MSGMODE);
}

Character::Character(std::string const &name) {
	this->_name = name;
	for (int i = 0; i < 4; i++) {
		_materiaList[i] = nullptr;
	}
	constructionMsg(CHARACTER DEFCONS, MSGMODE);
}

Character::Character(Character const &other) {
	this->_name = other.getName();
	for (int i = 0; i < 4; i++) {
		_materiaList[i] = other.getCharacterMateria(i);
	}
	constructionMsg(CHARACTER COPYCONS, MSGMODE);
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
	constructionMsg(CHARACTER OPECONS, MSGMODE);
	return(*this);
}

Character::~Character(void) {
	for (int i = 0; i < 4; i++) {
		if (_materiaList[i] != nullptr){
			delete _materiaList[i];
		}
	}
	constructionMsg(CHARACTER DEFDES, MSGMODE);
}

std::string const &	Character::getName(void) const {
	return (_name);
}

AMateria*	Character::getCharacterMateria(int i) const {
	return (_materiaList[i]);
}

void	Character::equip(AMateria* m) {
	for (int i = 0; i < 4; i++) {
		if (this->_materiaList[i] == nullptr) {
			this->_materiaList[i] = m;
			std::cout << CHARACTER BOLD WHITE << this->getName() << ": " <<  BOLD GREEN << m->getType() << " " << RESET EQUIPED CYAN << i << RESET << std::endl; 
			return ;
		}
	}
	std::cout << CHARACTER INVENTORYFULL << std::endl;
	delete m;
}

void	Character::unequip(int idx) {
	if (idx < 4 && _materiaList[idx] != nullptr) {
		delete _materiaList[idx];
		_materiaList[idx] = nullptr;
		std::cout << BOLD WHITE << this->getName() << ": " << RESET DROP << std::endl;
	}
	
}

void	Character::use(int idx, ICharacter& target) {
	std::cout << BOLD WHITE << this->getName() << RESET << ": ";
	if (idx <= 3 && _materiaList[idx] != nullptr) {
		_materiaList[idx]->use(target);
	}
	else {
		std::cout << NOSPELL CYAN << idx <<  RESET << std::endl;
	}
}
