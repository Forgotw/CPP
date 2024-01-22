/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsohler@student.42.fr <lsohler>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 11:18:44 by lsohler@stu       #+#    #+#             */
/*   Updated: 2024/01/19 11:43:50 by lsohler@stu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	this->_guardSate = 0;
	std::cout << "ScavTrap: Constructor called." << std::endl;
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
