/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsohler <lsohler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 13:31:42 by lsohler           #+#    #+#             */
/*   Updated: 2024/01/13 15:09:01 by lsohler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name): _Name(name), _Weapon(NULL) {
	std::cout << "Human B constructor called" << std::endl;
}

HumanB::~HumanB(void) {
	std::cout << "Human B destructor called" << std::endl;
}

void	HumanB::attack() {
	if (_Weapon)
		std::cout << this->_Name << " attack with " << this->_Weapon->getType() << std::endl;
	else
		std::cout << this->_Name << " cannot attack without weapon" << std::endl;
}

void	HumanB::setWeapon(Weapon &weapon) {
	this->_Weapon = &weapon;
}
