/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsohler <lsohler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 18:47:23 by lsohler           #+#    #+#             */
/*   Updated: 2024/02/15 12:39:39 by lsohler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : AForm() {
	constructionMsg(PRESIDENTIALPARDONFORM DEFCONS, MSGMODE);
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : AForm("PresidentialPardonForm", 25, 5), _target(target) {
	constructionMsg(PRESIDENTIALPARDONFORM DEFCONS, MSGMODE);
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &other) : AForm(other), _target(other._target) {
	constructionMsg(PRESIDENTIALPARDONFORM COPYCONS, MSGMODE);
}

PresidentialPardonForm::~PresidentialPardonForm() {
	constructionMsg(PRESIDENTIALPARDONFORM DEFDES, MSGMODE);
}

PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm const &other) {
	constructionMsg(PRESIDENTIALPARDONFORM OPECONS, MSGMODE);
	if (this != &other) {
		*this = PresidentialPardonForm(other);
	}
	return(*this);
}

void	PresidentialPardonForm::executeConcrete(void) const {
	std::cout << _target << "has been pardoned by Zaphod Beeblebrox." << std::endl;
}
