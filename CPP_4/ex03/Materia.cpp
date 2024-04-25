/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Materia.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsohler <lsohler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 18:25:15 by lsohler           #+#    #+#             */
/*   Updated: 2024/02/05 11:11:38 by lsohler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Materia.hpp"
#include "Colors.h"

AMateria::AMateria() {
	this->_type = "NoType";
	constructionMsg(AMATERIA DEFCONS, MSGMODE);
}

AMateria::AMateria(std::string const &type) {
	this->_type = type;
	constructionMsg(AMATERIA DEFCONS, MSGMODE);
}

AMateria::AMateria(AMateria const &other) {
	this->_type = other.getType();
	constructionMsg(AMATERIA COPYCONS, MSGMODE);
}

AMateria::~AMateria() {
	constructionMsg(AMATERIA DEFDES, MSGMODE);
}

AMateria &AMateria::operator=(AMateria const &other) {
	if (this != &other) {
		*this = other;
	}
	constructionMsg(AMATERIA OPECONS, MSGMODE);
	return(*this);
}

std::string const & AMateria::getType() const {
	return (_type);
}

void AMateria::use(ICharacter& target) {
	(void)target;
	std::cout << VIRTUALSPELL << std::endl;
}
