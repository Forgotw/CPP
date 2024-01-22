/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsohler@student.42.fr <lsohler>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 09:22:01 by lsohler@stu       #+#    #+#             */
/*   Updated: 2024/01/19 11:06:16 by lsohler@stu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : _Name("DefaultClapTrap"), _HitPoints(10), _EenergyPoints(0), _AttackDamage(0) {
	std::cout << "ClapTrap: Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name, unsigned int hp, unsigned int ep, unsigned int ad) : _Name(name), _HitPoints(hp), _EenergyPoints(ep), _AttackDamage(ad) {
	std::cout << "ClapTrap: Constructor called" << std::endl;
}

// ClapTrap::ClapTrap(const ClapTrap& copy) {
// 	std::cout << "ClapTrap: Copy constructor called" << std::endl;
// }

// ClapTrap& ClapTrap::operator=(const ClapTrap& affectation) {
// 	std::cout << "ClapTrap: Copy assignment operator called" << std::endl;
// 	return *this;
// }

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
	std::cout << this->_Name << " repairing " << amount << ". Current HP: " << this->_HitPoints << "." << std::endl;
}
