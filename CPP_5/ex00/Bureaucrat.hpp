/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsohler <lsohler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 12:45:35 by lsohler           #+#    #+#             */
/*   Updated: 2024/02/09 17:08:19 by lsohler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

/*
**==========================
**		Includes
**==========================
*/
#include "Colors.h"

class Bureaucrat {

	private:
		const std::string	_name;
		int			_grade;
		bool		CheckBoundaries(int value, int min, int max);

	public:
		Bureaucrat(void);
		Bureaucrat(std::string _name, int grade);
		Bureaucrat(Bureaucrat const &copy);
		~Bureaucrat(void);

		Bureaucrat& operator=(Bureaucrat const &copy);
		Bureaucrat&	operator++();
		Bureaucrat	operator++(int);
		Bureaucrat&	operator--();
		Bureaucrat	operator--(int);

		std::string	getName(void) const;
		int			getGrade(void) const;
		void		setGrade(const int &grade);

		class GradeTooHighException : public std::exception {
			public : virtual const char* what() const throw() {
				return ("GradeTooHigh");
			}
		};

		class GradeTooLowException : public std::exception {
			public : virtual const char* what() const throw() {
				return ("GradeTooLow");
			}
		};
};

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& obj);
