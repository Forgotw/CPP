/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsohler <lsohler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 14:04:56 by lsohler           #+#    #+#             */
/*   Updated: 2024/01/22 14:13:23 by lsohler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	this->_HitPoints = 100;
	this->_EenergyPoints = 30;
	this->_AttackDamage = 30;
	std::cout << "FragTrap: Constructor called." << std::endl;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap: Destructor called." << std::endl;
}


void	FragTrap::highFivesGuys(void) {
	std::cout << this->_Name << " raise his robot hand to do a high five !" << std::endl;
	
}
