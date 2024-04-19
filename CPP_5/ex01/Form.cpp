/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsohler <lsohler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 17:05:37 by lsohler           #+#    #+#             */
/*   Updated: 2024/02/27 10:37:17 by lsohler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Form.hpp"
#include "Bureaucrat.hpp"


Form::Form(void) : _name("Default"), _signed(0), _signGrade(1) ,_readGrade(1) {
	constructionMsg(FORM DEFCONS, MSGMODE);
}

Form::Form(std::string name, const int signGrade, const int readGrade) : _name(name), _signed(0), _signGrade(signGrade) , _readGrade(readGrade) {
	CheckBoundaries(signGrade, 1, 150);
	CheckBoundaries(readGrade, 1, 150);
	constructionMsg(FORM DEFCONS, MSGMODE);
}

Form::Form(Form const &other) : _name(other.getName()), _signed(other.getSigned()) , _signGrade(other.getSignGrade()), _readGrade(other.getReadGrade()){
	constructionMsg(FORM COPYCONS, MSGMODE);
}

Form::~Form() {
	constructionMsg(FORM DEFDES, MSGMODE);
}

Form& Form::operator=(Form const &other) {
	if (this != &other) {
		*this = Form(other);
	}
	constructionMsg(FORM OPECONS, MSGMODE);
	return(*this);
}

bool	Form::CheckBoundaries(int value, int min, int max) {
	if (min == 2 && value < min) {
		throw(Form::GradeTooHighException());
		return (false);
	}
	else if (max == 149 && value > max) {
		throw(Form::GradeTooLowException());
		return (false);
	}
	else if (min == 1 && max == 150) {
		if (value < min) {
			throw(Form::GradeTooHighException());
			return (false);
		}
		else if (value > max) {
			throw(Form::GradeTooLowException());
			return (false);
		}
	}
	return (true);
}

int	Form::getSignGrade(void) const {
	return (_signGrade);
}

int	Form::getReadGrade(void) const {
	return (_readGrade);
}

bool	Form::getSigned(void) const {
	return (_signed);
}

const std::string	Form::getName(void) const {
	return (_name);
}

void	Form::beSigned(const Bureaucrat &obj) {
	if (obj.getGrade() <= _signGrade) {
		_signed = true;
	}
	else {
		throw (Form::GradeTooLowException());
	}
}

std::ostream& operator<<(std::ostream& os, const Form &obj) {
	os << obj.getName() << ", requires a sign grade of " << obj.getSignGrade() << " and a read grade of " << obj.getReadGrade();
	return os;
}
