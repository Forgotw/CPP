/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsohler <lsohler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 14:32:51 by lsohler           #+#    #+#             */
/*   Updated: 2024/02/24 15:14:46 by lsohler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern(void) {
	constructionMsg(INTERN DEFCONS, MSGMODE);
}

Intern::Intern(Intern const &other) {
	(void)other;
	constructionMsg(INTERN COPYCONS, MSGMODE);
}

Intern::~Intern() {
	constructionMsg(INTERN DEFDES, MSGMODE);
}

Intern& Intern::operator=(Intern const &other) {
	constructionMsg(INTERN OPECONS, MSGMODE);
	if (this != &other) {
		*this = Intern(other);
	}
	return(*this);
}

std::string	requests[3] = {
	"presidential pardon",
	"robotomy request",
	"shrubbery creation"
};

AForm*	Intern::makeForm(std::string request, std::string target) {
	for (int i = 0; i < 3; i++) {
		if (request == requests[i]) {
			std::cout << "Intern creates " + request << std::endl;
			switch(i) {
				case 0:	
					return new PresidentialPardonForm(target);
				case 1:
					return new RobotomyRequestForm(target);
				case 2:
					return new ShrubberyCreationForm(target);
				default:
					break;
			}
		}
	}
	std::cout << "Intern could not create " + request << std::endl;
	return nullptr;
}
