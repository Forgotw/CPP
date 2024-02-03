/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsohler <lsohler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 09:22:01 by lsohler@stu       #+#    #+#             */
/*   Updated: 2024/02/02 17:45:09 by lsohler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : _Name("DefaultClapTrap"), _HitPoints(10), _EenergyPoints(0), _AttackDamage(0) {
	std::cout << "ClapTrap: Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _Name(name), _HitPoints(10), _EenergyPoints(0), _AttackDamage(0) {
	std::cout << "ClapTrap: Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name, unsigned int hp, unsigned int ep, unsigned int ad) : _Name(name), _HitPoints(hp), _EenergyPoints(ep), _AttackDamage(ad) {
	std::cout << "ClapTrap: Constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& copy) {
	_Name = copy.getName();
	_HitPoints = copy.getHP();
	_EenergyPoints = copy.getEP();
	_AttackDamage = copy.getAD();
	std::cout << "ClapTrap: Copy constructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& affectation) {
	if (this != &affectation) {
		_Name = affectation.getName();
		_HitPoints = affectation.getHP();
		_EenergyPoints = affectation.getEP();
		_AttackDamage = affectation.getAD();
	}
	std::cout << "ClapTrap: Copy assignment operator called" << std::endl;
	return *this;
}

ClapTrap::~ClapTrap(void) {
	std::cout << "ClapTrap: Destructor called" << std::endl;
}

void	ClapTrap::attack(const std::string& target) {
	std::cout << this->_Name << " attacks " << target << ", causing " << this->_AttackDamage << " points of damage!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount) {
	if (this->_HitPoints <= 0) {
		std::cout << this->_Name << " is already dead." << std::endl;
		return ;
	}
	this->_HitPoints -= amount;
	std::cout << this->_Name << " take " << amount << " damage." << std::endl;
	if (this->_HitPoints <= 0)
		std::cout << this->_Name << " is dead !" << std::endl;
	else
		std::cout << this->_Name << " current HP: " << this->_HitPoints << "." << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (this->_HitPoints <= 0) {
		std::cout << this->_Name << " is dead, cannot repair." << std::endl;
		return ;
	}
	if (amount > this->_EenergyPoints) {
		std::cout << this->_Name << " try to repair: " << amount << " but have: " << this->_EenergyPoints << " Energy." << std::endl;
		return ;
	}
	this->_HitPoints += amount;
	this->_EenergyPoints -= amount;
	std::cout << this->_Name << " repairing " << amount << ". Current HP: " << this->_HitPoints << "." << " Current EP:" << this->_EenergyPoints << "." << std::endl;
}

void	ClapTrap::displayInfo(void) {
	std::cout << this->_Name << ": HP:" << this->_HitPoints << " EP:" << this->_EenergyPoints << " AD: " << this->_AttackDamage << std::endl;
}

std::string	ClapTrap::getName(void) const {
	return (_Name);
}

unsigned int	ClapTrap::getHP(void) const {
	return (_HitPoints);
}

unsigned int	ClapTrap::getEP(void) const {
	return (_EenergyPoints);
}

unsigned int	ClapTrap::getAD(void) const {
	return (_AttackDamage);
}
