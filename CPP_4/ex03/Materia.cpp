/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Materia.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsohler <lsohler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 18:25:15 by lsohler           #+#    #+#             */
/*   Updated: 2024/02/02 14:53:13 by lsohler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Materia.hpp"
#include "Colors.h"

AMateria::AMateria() {
	this->_type = "NoType";
	std::cout << AMATERIA DEFCONS << std::endl;
}

AMateria::AMateria(std::string const &type) {
	this->_type = type;
	std::cout << AMATERIA DEFCONS << std::endl;
}

AMateria::AMateria(AMateria const &other) {
	this->_type = other.getType();
	std::cout << AMATERIA COPYCONS << std::endl;
}

AMateria::~AMateria() {
	std::cout << AMATERIA DEFDES << std::endl;
}

AMateria &AMateria::operator=(AMateria const &other) {
	std::cout << AMATERIA OPECONS << std::endl;
	if (this != &other) {
		*this = other;
	}
	return(*this);
}

std::string const & AMateria::getType() const {
	return (_type);
}

// AMateria*	AMateria::clone() const {
// 	return (new this);
// }

// void AMateria::use(ICharacter& target) {
	
// }
