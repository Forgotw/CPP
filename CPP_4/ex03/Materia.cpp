/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Materia.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsohler <lsohler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 18:25:15 by lsohler           #+#    #+#             */
/*   Updated: 2024/01/23 18:53:12 by lsohler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Materia.hpp"
#include "Colors.h"
#include <iostream>

AMateria::AMateria() {
	this->_type = "NoType";
	std::cout << AMATERIA DEFCONS << std::endl;
}

AMateria::AMateria(std::string const &type) {
	this->_type = type;
	std::cout << AMATERIA DEFCONS << std::endl;
}

AMateria::AMateria(AMateria const &other) {
	std::cout << AMATERIA COPYCONS << std::endl;
}

AMateria::~AMateria() {
	std::cout << AMATERIA DEFDES << std::endl;

}

AMateria &AMateria::operator=(AMateria const &other) {
	std::cout << AMATERIA OPECONS << std::endl;
	if (this != &other) {

	}
	return(*this);
}
