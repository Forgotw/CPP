/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsohler <lsohler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 13:36:42 by lsohler           #+#    #+#             */
/*   Updated: 2024/02/10 11:59:23 by lsohler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Colors.h"

int main(void) {
	try {
		Bureaucrat john("John", 200);
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
	// catch (Bureaucrat::GradeTooLowException &e) {
	// 	std::cerr << "Error: " << e.what() << std::endl;
	// }
	endline(3);


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
	// catch (Bureaucrat::GradeTooLowException &e) {
	// 	std::cerr << "Error: " << e.what() << std::endl;
	// }
	endline(3);


	try {
		Bureaucrat karen("Karen", 4);
		std::cout << ++karen << std::endl;
		std::cout << ++karen << std::endl;
		std::cout << ++karen << std::endl;
		std::cout << ++karen << std::endl;
		std::cout << karen << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException &e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	// catch (Bureaucrat::GradeTooLowException &e) {
	// 	std::cerr << "Error: " << e.what() << std::endl;
	// }
	return (0);
}
