/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsohler <lsohler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 11:18:44 by lsohler@stu       #+#    #+#             */
/*   Updated: 2024/02/02 18:00:32 by lsohler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	this->_guardSate = 0;
	this->_HitPoints = _HP;
	this->_EenergyPoints = _EP;
	this->_AttackDamage = _AD;
	std::cout << "ScavTrap: Constructor called." << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& copy) {
	_Name = copy.getName();
	_HitPoints = copy.getHP();
	_EenergyPoints = copy.getEP();
	_AttackDamage = copy.getAD();
	_guardSate = copy.getGS();
	std::cout << "ScavTrap: Copy constructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& affectation) {
	if (this != &affectation) {
		_Name = affectation.getName();
		_HitPoints = affectation.getHP();
		_EenergyPoints = affectation.getEP();
		_AttackDamage = affectation.getAD();
		_guardSate = affectation.getGS();
	}
	std::cout << "ScavTrap: Copy assignment operator called" << std::endl;
	return *this;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap: Destructor called." << std::endl;
}

void	ScavTrap::attack(const std::string& target) {
	std::cout << this->_Name << " attacks VIOLENTLY " << target << ", causing " << this->_AttackDamage << " points of damage!" << std::endl;
}

void	ScavTrap::guardGate(void) {
	this->_guardSate = (this->_guardSate == 0) ? 1 : 0;
	if (this->_guardSate)
		std::cout << this->_Name << " is now guarding the gate." << std::endl;
	if (!this->_guardSate)
		std::cout << this->_Name << " has stopped guarding the gate." << std::endl;
}

std::string	ScavTrap::getName(void) const {
	return (_Name);
}

unsigned int	ScavTrap::getHP(void) const {
	return (_HitPoints);
}

unsigned int	ScavTrap::getEP(void) const {
	return (_EenergyPoints);

}

unsigned int	ScavTrap::getAD(void) const {
	return (_AttackDamage);
}

unsigned int	ScavTrap::getGS(void) const {
	return (_guardSate);
}
