/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsohler <lsohler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 10:41:10 by lsohler           #+#    #+#             */
/*   Updated: 2024/01/13 12:29:23 by lsohler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name) {
	this->_Name = name;
	std::cout << "Zombie Constructor: " << "<" << this->_Name << ">" << std::endl;
	return;
}

Zombie::Zombie(void) {
	this->_Name = "null";
	std::cout << "Zombie Constructor: " << "<" << this->_Name << ">" << std::endl;
	return;
}

Zombie::~Zombie(void) {
	std::cout << "Zombie Destructor: " << "<" << this->_Name << ">" << std::endl;
}

void	Zombie::announce(void) {
	std::cout << this->_Name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::setName(std::string name) {
	this->_Name = name;
}
