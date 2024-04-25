/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsohler <lsohler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:38:36 by lsohler           #+#    #+#             */
/*   Updated: 2024/02/05 13:16:02 by lsohler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Materia.hpp"
#include "Cure.hpp"
#include "Colors.h"

Cure::Cure() : AMateria("cure") {
	constructionMsg(CURE DEFCONS, MSGMODE);
}

Cure::Cure(Cure const &other) : AMateria(other) {
	constructionMsg(CURE COPYCONS, MSGMODE);
}

Cure::~Cure() {
	constructionMsg(CURE DEFDES, MSGMODE);
}

Cure& Cure::operator=(Cure const &other) {
	if (this != &other) {
		_type = other._type;
	}
	constructionMsg(CURE OPECONS, MSGMODE);
	return(*this);
}

AMateria*	Cure::clone(void) const {
	return (new Cure(*this));
}

void		Cure::use(ICharacter &target) {
	std::cout << CURE1 << BOLD WHITE << target.getName() << RESET << CURE2 << std::endl;
}
