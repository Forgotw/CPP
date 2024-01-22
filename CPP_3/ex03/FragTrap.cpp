/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsohler <lsohler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 14:04:56 by lsohler           #+#    #+#             */
/*   Updated: 2024/01/22 16:54:43 by lsohler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	this->_HitPoints = _HP;
	this->_EenergyPoints = _EP;
	this->_AttackDamage = _AD;\
	std::cout << "FragTrap: Constructor called." << std::endl;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap: Destructor called." << std::endl;
}


void	FragTrap::highFivesGuys(void) {
	std::cout << this->_Name << " raise his robot hand to do a high five !" << std::endl;
	
}
