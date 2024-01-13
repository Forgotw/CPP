/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsohler <lsohler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 13:31:38 by lsohler           #+#    #+#             */
/*   Updated: 2024/01/13 15:09:27 by lsohler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type): _Type(type) {
	std::cout << "Weapon constructor called for: " << type << std::endl;
}

Weapon::~Weapon(void) {
	std::cout << "Weapon destructor called for: " << this->_Type << std::endl;
}

const std::string&	Weapon::getType(void) {
	return (this->_Type);
}

void	Weapon::setType(std::string type) {
	this->_Type = type;
}
