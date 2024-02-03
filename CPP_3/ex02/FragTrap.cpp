/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsohler <lsohler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 14:04:56 by lsohler           #+#    #+#             */
/*   Updated: 2024/02/02 17:53:38 by lsohler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap("Default Name") {
	this->_HitPoints = 100;
	this->_EenergyPoints = 30;
	this->_AttackDamage = 30;
	std::cout << "FragTrap: Default Constructor called." << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	this->_HitPoints = 100;
	this->_EenergyPoints = 30;
	this->_AttackDamage = 30;
	std::cout << "FragTrap: Constructor called." << std::endl;
}

FragTrap::FragTrap(const FragTrap& copy) {
	_Name = copy.getName();
	_HitPoints = copy.getHP();
	_EenergyPoints = copy.getEP();
	_AttackDamage = copy.getAD();
	std::cout << "FragTrap: Copy constructor called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& affectation) {
	if (this != &affectation) {
		_Name = affectation.getName();
		_HitPoints = affectation.getHP();
		_EenergyPoints = affectation.getEP();
		_AttackDamage = affectation.getAD();
	}
	std::cout << "FragTrap: Copy assignment operator called" << std::endl;
	return *this;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap: Destructor called." << std::endl;
}


void	FragTrap::highFivesGuys(void) {
	std::cout << this->_Name << " raise his robot hand to do a high five !" << std::endl;
	
}

std::string	FragTrap::getName(void) const {
	return (_Name);
}

unsigned int	FragTrap::getHP(void) const {
	return (_HitPoints);
}

unsigned int	FragTrap::getEP(void) const {
	return (_EenergyPoints);

}

unsigned int	FragTrap::getAD(void) const {
	return (_AttackDamage);
}
