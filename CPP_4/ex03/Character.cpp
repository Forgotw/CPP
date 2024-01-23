/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsohler <lsohler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 18:53:32 by lsohler           #+#    #+#             */
/*   Updated: 2024/01/23 19:45:26 by lsohler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "Colors.h"
#include <iostream>

Character::Character() {
	this->_name = "NoName";
	for (int i = 0; i < 4; ++i) {
		_materiaList[i] = nullptr;
	}
	std::cout << CHARACTER DEFCONS << std::endl;
}

Character::Character(std::string const &name) {
	this->_name = name;
	for (int i = 0; i < 4; ++i) {
		_materiaList[i] = nullptr;
	}
	std::cout << CHARACTER DEFCONS << std::endl;
}

Character::Character(Character const &other) {
	std::cout << CHARACTER COPYCONS << std::endl;
}

Character::~Character(void) {
	std::cout << CHARACTER DEFDES << std::endl;

}

Character &Character::operator=(Character const &other) {
	std::cout << CHARACTER OPECONS << std::endl;
	if (this != &other) {

	}
	return(*this);
}

std::string const &	Character::getName(void) const {

}

void	Character::equip(AMateria* m) {

}

void	Character::unequip(int idx) {

}

void	Character::use(int idx, ICharacter& target) {

}
