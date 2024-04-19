/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsohler <lsohler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 17:06:11 by lsohler           #+#    #+#             */
/*   Updated: 2024/02/16 12:53:45 by lsohler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

/*
**==========================
**		Includes
**==========================
*/
#include "Colors.h"

class Bureaucrat;

class AForm {

	private:
		const std::string	_name;
		bool				_signed;
		const int			_signGrade;
		const int			_readGrade;
		bool		CheckBoundaries(int value, int min, int max);

	public:
		AForm(void);
		AForm(std::string name, const int signGrade, const int readGrade);
		AForm(AForm const &other);
		virtual ~AForm(void);

		AForm& operator=(AForm const &copy);
		int					getSignGrade(void) const;
		int					getReadGrade(void) const;
		bool				getSigned(void) const;
		const std::string	getName(void) const;
		void				beSigned(const Bureaucrat &obj);
		void				execute(const Bureaucrat &obj) const;
		virtual void		executeConcrete(void) const = 0;

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
		class NotSignedException : public std::exception {
			public : virtual const char* what() const throw() {
				return ("Form::FormNotSigned");
			}
		};
		class AlreadySignedException : public std::exception {
			public : virtual const char* what() const throw() {
				return ("Form::FormAlreadySigned");
			}
		};
		class NullForm : public std::exception {
			public : virtual const char* what() const throw() {
				return ("Form::NullForm");
			}
		};
};

std::ostream&	operator<<(std::ostream& os, const AForm& obj) ;

#endif
