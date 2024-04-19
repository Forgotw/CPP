/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsohler <lsohler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 13:36:42 by lsohler           #+#    #+#             */
/*   Updated: 2024/02/10 17:40:03 by lsohler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "Colors.h"


int main(void) {
	try {
		Bureaucrat john("John", 150);
		std::cout << john << std::endl;
		std::cout << ++john << std::endl;
		std::cout << john << std::endl;
		std::cout << john++ << std::endl;
		std::cout << john << std::endl;
		std::cout << --john << std::endl;
		std::cout << --john << std::endl;
		std::cout << --john << std::endl;
		std::cout << --john << std::endl;
		std::cout << john << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException &e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	endline(3);


	try {
		Bureaucrat	john("John", 74);
		Form		FormA("Formulaire A", 73, 1);
		std::cout << FormA << std::endl;
		FormA.beSigned(john);
	}
	catch (Form::GradeTooLowException &e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	endline(3);

	try {
		Bureaucrat	john("John", 74);
		std::cout << ++john << std::endl;
		Form		FormA("Formulaire A", 73, 1);
		FormA.beSigned(john);
	}
	catch (Form::GradeTooLowException &e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
}

