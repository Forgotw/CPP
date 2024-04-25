/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsohler <lsohler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:38:34 by lsohler           #+#    #+#             */
/*   Updated: 2024/02/05 13:14:30 by lsohler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Materia.hpp"
#include "Ice.hpp"
#include "Colors.h"

Ice::Ice() : AMateria("ice") {
	constructionMsg(ICE DEFCONS, MSGMODE);
}

Ice::Ice(Ice const &other) : AMateria(other) {
	constructionMsg(ICE COPYCONS, MSGMODE);
}

Ice::~Ice() {
	constructionMsg(ICE DEFDES, MSGMODE);
}

Ice& Ice::operator=(Ice const &other) {
	if (this != &other) {
		_type = other._type;
	}
	constructionMsg(ICE OPECONS, MSGMODE);
	return(*this);
}

AMateria*	Ice::clone(void) const {
	return (new Ice(*this));
}

void		Ice::use(ICharacter &target) {
	std::cout << ICE1 << BOLD WHITE << target.getName() << RESET << ICE2 << std::endl;
}
