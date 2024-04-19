/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsohler <lsohler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 17:06:11 by lsohler           #+#    #+#             */
/*   Updated: 2024/02/10 16:47:54 by lsohler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

/*
**==========================
**		Includes
**==========================
*/
#include "Colors.h"

class Bureaucrat;

class Form {

	private:
		const std::string	_name;
		bool				_signed;
		const int			_signGrade;
		const int			_readGrade;
		bool		CheckBoundaries(int value, int min, int max);

	public:
		Form(void);
		Form(std::string name, const int signGrade, const int readGrade);
		Form(Form const &copy);
		~Form(void);

		Form& operator=(Form const &copy);
		int			getSignGrade(void) const;
		int			getReadGrade(void) const;
		bool				getSigned(void) const;
		const std::string	getName(void) const;
		void				beSigned(const Bureaucrat &obj);

		class GradeTooHighException : public std::exception {
			public : virtual const char* what() const throw() {
				return ("Form::GradeTooHigh");
			}
		};

		class GradeTooLowException : public std::exception {
			public : virtual const char* what() const throw() {
				return ("Form::GradeTooLow");
			}
		};
};

std::ostream&	operator<<(std::ostream& os, const Form& obj) ;

#endif
