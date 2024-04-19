/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsohler <lsohler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 17:05:37 by lsohler           #+#    #+#             */
/*   Updated: 2024/02/15 14:24:17 by lsohler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "AForm.hpp"
#include "Bureaucrat.hpp"


AForm::AForm(void) : _name("Default"), _signed(0), _signGrade(1) ,_readGrade(1) {
	constructionMsg(AFORM DEFCONS, MSGMODE);
}

AForm::AForm(std::string name, const int signGrade, const int readGrade) : _name(name), _signed(0), _signGrade(signGrade) , _readGrade(readGrade) {
	CheckBoundaries(signGrade, 1, 150);
	CheckBoundaries(readGrade, 1, 150);
	constructionMsg(AFORM DEFCONS, MSGMODE);
}

AForm::AForm(AForm const &other) : _name(other.getName()), _signed(other.getSigned()) , _signGrade(other.getSignGrade()), _readGrade(other.getReadGrade()){
	constructionMsg(AFORM COPYCONS, MSGMODE);
}

AForm::~AForm() {
	constructionMsg(AFORM DEFDES, MSGMODE);
}

AForm& AForm::operator=(AForm const &other) {
	if (this != &other) {
		// *this = AForm(other);
	}
	constructionMsg(AFORM OPECONS, MSGMODE);
	return(*this);
}

bool	AForm::CheckBoundaries(int value, int min, int max) {
	if (min == 2 && value < min) {
		throw(AForm::GradeTooHighException());
		return (false);
	}
	else if (max == 149 && value > max) {
		throw(AForm::GradeTooLowException());
		return (false);
	}
	else if (min == 1 && max == 150) {
		if (value < min) {
			throw(AForm::GradeTooHighException());
			return (false);
		}
		else if (value > max) {
			throw(AForm::GradeTooLowException());
			return (false);
		}
	}
	return (true);
}

int	AForm::getSignGrade(void) const {
	return (_signGrade);
}

int	AForm::getReadGrade(void) const {
	return (_readGrade);
}

bool	AForm::getSigned(void) const {
	return (_signed);
}

const std::string	AForm::getName(void) const {
	return (_name);
}

void	AForm::beSigned(const Bureaucrat &obj) {

	if (obj.getGrade() <= _signGrade) {
		_signed = true;
	}
	else {
		throw (AForm::GradeTooLowException());
	}
}

std::ostream& operator<<(std::ostream& os, const AForm &obj) {
	os << obj.getName() << ", requires a sign grade of " << obj.getSignGrade() << " and a read grade of " << obj.getReadGrade();
	return os;
}

void	AForm::execute(const Bureaucrat &obj) const {
	if ( this->getSigned() == false )
		throw AForm::NotSignedException();
	else if (obj.getGrade() > this->getReadGrade()) {
		throw AForm::GradeTooLowException();
	}
	else
		executeConcrete();
}
