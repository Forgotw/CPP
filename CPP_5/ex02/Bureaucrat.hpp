/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsohler <lsohler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 12:45:35 by lsohler           #+#    #+#             */
/*   Updated: 2024/02/15 12:57:24 by lsohler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

/*
**==========================
**		Includes
**==========================
*/
#include "Colors.h"

class AForm;

class Bureaucrat {

	private:
		const std::string	_name;
		int					_grade;
		bool				CheckBoundaries(int value, int min, int max);

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
		void		setName(const std::string &name);
		void		setGrade(const int &grade);
		void		signForm(AForm &obj);
		void		executeForm(AForm const &form) const;
		class GradeTooHighException : public std::exception {
			public : virtual const char* what() const throw() {
				return ("Bureaucrat::GradeTooHigh");
			}
		};

		class GradeTooLowException : public std::exception {
			public : virtual const char* what() const throw() {
				return ("Bureaucrat::GradeTooLow");
			}
		};
};

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& obj);

#endif
