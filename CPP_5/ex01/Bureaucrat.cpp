/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsohler <lsohler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:38:34 by lsohler           #+#    #+#             */
/*   Updated: 2024/02/27 10:36:53 by lsohler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat(void) : _name("Default"), _grade(150) {
	constructionMsg(BUREAUCRAT DEFCONS, MSGMODE);
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade) {
	CheckBoundaries(grade, 1, 150);
	constructionMsg(BUREAUCRAT DEFCONS, MSGMODE);
}

Bureaucrat::Bureaucrat(Bureaucrat const &other) : _name(other.getName()) , _grade(other.getGrade()) {
	constructionMsg(BUREAUCRAT COPYCONS, MSGMODE);
}

Bureaucrat::~Bureaucrat() {
	constructionMsg(BUREAUCRAT DEFDES, MSGMODE);
}

Bureaucrat& Bureaucrat::operator=(Bureaucrat const &other) {
	if (this != &other) {
		*this = Bureaucrat(other);
	}
	constructionMsg(BUREAUCRAT OPECONS, MSGMODE);
	return(*this);
}

std::string	Bureaucrat::getName(void) const {
	return (_name);
}

int			Bureaucrat::getGrade(void) const {
	return (_grade);
}

void		Bureaucrat::setGrade(const int &grade) {
	_grade = grade;
}

void		Bureaucrat::signForm(Form &obj) {
	try {
		obj.beSigned(*this);
		std::cout << _name << " signed " << obj.getName() << std::endl;
	}
	catch (Form::GradeTooLowException &e) {
		std::cerr << "Error: " << _name << " coulnd't sign " << obj.getName() << " because " << e.what() << std::endl;
	}
}

bool	Bureaucrat::CheckBoundaries(int value, int min, int max) {
	if (min == 2 && value < min) {
		throw(Bureaucrat::GradeTooHighException());
		return (false);
	}
	else if (max == 149 && value > max) {
		throw(Bureaucrat::GradeTooLowException());
		return (false);
	}
	else if (min == 1 && max == 150) {
		if (value < min) {
			throw(Bureaucrat::GradeTooHighException());
			return (false);
		}
		else if (value > max) {
			throw(Bureaucrat::GradeTooLowException());
			return (false);
		}
	}
	return (true);
}

/*---Stream Operators------*/
std::ostream& operator<<(std::ostream& os, const Bureaucrat &obj) {
	os << obj.getName() << ", bureaucrat grade " << obj.getGrade();
	return os;
}
/*-------------------------*/

/*---Iterations Operators--*/
Bureaucrat& Bureaucrat::operator++() { // Opérateur de pré-incrémentation (++x)
	if (CheckBoundaries(_grade, 2, 150)) {
		--this->_grade;
	}
	return *this;
}

Bureaucrat Bureaucrat::operator++(int) { // Opérateur de post-incrémentation (x++)
	Bureaucrat	temp(*this);
	if (CheckBoundaries(_grade, 2, 150)) {
		--this->_grade;
	}
	return temp;
}

Bureaucrat& Bureaucrat::operator--() { // Opérateur de pré-décrémentation (--x)
	if (CheckBoundaries(_grade, 1, 149)) {
		++this->_grade;
	}
	return *this;
}

Bureaucrat Bureaucrat::operator--(int) { // Opérateur de post-décrémentation (x--)
	Bureaucrat	temp(*this);
	if (CheckBoundaries(_grade, 1, 149)) {
		++this->_grade;
	}
	return temp;
}
/*-------------------------*/
