/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsohler <lsohler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 18:30:06 by lsohler           #+#    #+#             */
/*   Updated: 2024/02/15 12:39:13 by lsohler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) : AForm() {
	constructionMsg(ROBOTOMYREQUESTFORM DEFCONS, MSGMODE);
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("RobotomyRequestForm", 72, 45), _target(target) {
	constructionMsg(ROBOTOMYREQUESTFORM DEFCONS, MSGMODE);
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &other) : AForm(other), _target(other._target) {
	constructionMsg(ROBOTOMYREQUESTFORM COPYCONS, MSGMODE);
}

RobotomyRequestForm::~RobotomyRequestForm() {
	constructionMsg(ROBOTOMYREQUESTFORM DEFDES, MSGMODE);
}

RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm const &other) {
	constructionMsg(ROBOTOMYREQUESTFORM OPECONS, MSGMODE);
	if (this != &other) {
		*this = RobotomyRequestForm(other);
	}
	return(*this);
}

void	RobotomyRequestForm::executeConcrete(void) const {
	static bool check = true;
	if (check) {
		std::cout << "BRrRrrRrrRRrrR " << _target << " has been robotomized" << std::endl;
	}
	else {
		std::cout << "The robotomy failed." << std::endl;
	}
	// check = !check;
	check = check ? false : true;
}
