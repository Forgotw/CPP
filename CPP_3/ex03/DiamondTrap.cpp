/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsohler <lsohler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 14:22:41 by lsohler           #+#    #+#             */
/*   Updated: 2024/02/03 11:32:25 by lsohler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) : ClapTrap ("Default_clap_name"), ScavTrap("Default_scav_name"), FragTrap("Default_frag_name") {
	this->_HitPoints = FragTrap::_HP;
	this->_EenergyPoints = ScavTrap::_EP;
	this->_AttackDamage = FragTrap::_AD;
	this->_Name = "Default_diamond";
	std::cout << "DiamondTrap Constructor called." << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap (name + "_clap_name"), ScavTrap(name), FragTrap(name) {
	this->_HitPoints = FragTrap::_HP;
	this->_EenergyPoints = ScavTrap::_EP;
	this->_AttackDamage = FragTrap::_AD;
	this->_Name = name;
	std::cout << "DiamondTrap Constructor called." << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& copy) : ClapTrap(this->ClapTrap::_Name), ScavTrap(copy.getName()), FragTrap(copy.getName()) {
	this->_Name = copy.getName();
	this->_HitPoints = copy.getHP();
	this->_EenergyPoints = copy.getEP();
	this->_AttackDamage = copy.getAD();
	this->_Name = copy.getName();
	std::cout << "DiamondTrap: Copy constructor called" << std::endl;
}


DiamondTrap& DiamondTrap::operator=(const DiamondTrap& affectation) {
	if (this != &affectation) {
		_Name = affectation.getName();
		_HitPoints = affectation.getHP();
		_EenergyPoints = affectation.getEP();
		_AttackDamage = affectation.getAD();
	}
	std::cout << "DiamondTrap: Copy assignment operator called" << std::endl;
	return *this;
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

std::string	DiamondTrap::getName(void) const {
	return (_Name);
}

unsigned int	DiamondTrap::getHP(void) const {
	return (_HitPoints);
}

unsigned int	DiamondTrap::getEP(void) const {
	return (_EenergyPoints);

}

unsigned int	DiamondTrap::getAD(void) const {
	return (_AttackDamage);
}
