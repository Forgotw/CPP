/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsohler <lsohler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 13:31:40 by lsohler           #+#    #+#             */
/*   Updated: 2024/01/13 15:08:04 by lsohler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon): _Name(name), _Weapon(weapon) {
	std::cout << "Human A constructor called" << std::endl;
}

HumanA::~HumanA(void) {
	std::cout << "Human A destructor called" << std::endl;
}

void	HumanA::attack() {
	std::cout << this->_Name << " attack with " << this->_Weapon.getType() << std::endl;
}
