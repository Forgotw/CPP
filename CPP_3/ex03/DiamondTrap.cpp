/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsohler <lsohler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 14:22:41 by lsohler           #+#    #+#             */
/*   Updated: 2024/01/22 16:56:58 by lsohler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name) : ClapTrap (name + "_clap_name"), ScavTrap(name), FragTrap(name) {
	this->_HitPoints = FragTrap::_HP;
	this->_EenergyPoints = ScavTrap::_EP;
	this->_AttackDamage = FragTrap::_AD;
	this->_Name = name;
	std::cout << "DiamondTrap Constructor called." << std::endl;
}

DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap: Destructor called." << std::endl;
}

void	DiamondTrap::whoAmI(void) {
	std::cout << this->_Name << "\n" << ClapTrap::_Name << "\n";
}

void	DiamondTrap::diamondStats(void) {
	std::cout << this->_Name << ": HP:" << this->_HitPoints << " EP:" << this->_EenergyPoints << " AD: " << this->_AttackDamage << std::endl;
}
