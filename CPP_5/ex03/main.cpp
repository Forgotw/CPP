/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsohler <lsohler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 13:36:42 by lsohler           #+#    #+#             */
/*   Updated: 2024/02/24 15:21:53 by lsohler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"
#include "Colors.h"

int main(void) {
	printSeparator("John 1", BOLD RED);
	try {
		Bureaucrat	john("John", 1);
		Intern		afrigger;
		AForm*		presidential = afrigger.makeForm("presidential pardon", "Alieu");
		AForm*		robotomy = afrigger.makeForm("robotomy request", "Alieu");
		AForm*		shrubbery = afrigger.makeForm("shrubbery creation", "Alieu");
		AForm*		wrongform = afrigger.makeForm("wrong form", "Alieu");
		john.signForm(*presidential);
		john.executeForm(*presidential);
		john.signForm(*robotomy);
		john.executeForm(*robotomy);
		john.signForm(*shrubbery);
		john.executeForm(*shrubbery);
		john.signForm(*wrongform);
		john.executeForm(*wrongform);
		delete presidential;
		delete robotomy;
		delete shrubbery;
	}
	catch (Bureaucrat::GradeTooLowException &e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
}
// int main(void) {
// 	printSeparator("GRADE ", BOLD MAGENTA);
// 	std::cout << "ShrubberyCreationForm: Required grades: sign 145, exec 137" << std::endl;
// 	std::cout << "RobotomyRequestForm: Required grades: sign 72, exec 45" << std::endl;
// 	std::cout << "PresidentialPardonForm: Required grades: sign 25, exec 5" << std::endl;
// 	endline(3);


// 	printSeparator("John 175", BOLD RED);
// 	try {
// 		Bureaucrat	john("John", 175);
// 		ShrubberyCreationForm	FormA("Shrubbery1"); // Required grades: sign 145, exec 137
// 		RobotomyRequestForm		FormB("Robotomy"); // Required grades: sign 72, exec 45
// 		PresidentialPardonForm	FormC("Presidential"); // Required grades: sign 25, exec 5
// 		john.signForm(FormA);
// 		john.executeForm(FormA);
// 		john.signForm(FormB);
// 		john.executeForm(FormB);
// 		john.signForm(FormC);
// 		john.executeForm(FormC);
// 	}
// 	catch (Bureaucrat::GradeTooLowException &e) {
// 		std::cerr << "Error: " << e.what() << std::endl;
// 	}
// 	endline(3);


// 	printSeparator("John 145", BOLD BLUE);
// 	try {
// 		Bureaucrat	john("John", 145);
// 		ShrubberyCreationForm	FormA("Shrubbery1"); // Required grades: sign 145, exec 137
// 		RobotomyRequestForm		FormB("Robotomy"); // Required grades: sign 72, exec 45
// 		PresidentialPardonForm	FormC("Presidential"); // Required grades: sign 25, exec 5
// 		john.signForm(FormA);
// 		john.executeForm(FormA);
// 		john.signForm(FormB);
// 		john.executeForm(FormB);
// 		john.signForm(FormC);
// 		john.executeForm(FormC);
// 	}
// 	catch (Bureaucrat::GradeTooLowException &e) {
// 		std::cerr << "Error: " << e.what() << std::endl;
// 	}
// 	endline(3);


// 	printSeparator("John 45", BOLD GREEN);
// 	try {
// 		Bureaucrat	john("John", 45);
// 		// std::cout << ++john << std::endl;
// 		ShrubberyCreationForm	FormA("Shrubbery2"); // Required grades: sign 145, exec 137
// 		RobotomyRequestForm		FormB("Robotomy"); // Required grades: sign 72, exec 45
// 		PresidentialPardonForm	FormC("Presidential"); // Required grades: sign 25, exec 5
// 		john.signForm(FormA);
// 		john.executeForm(FormA);
// 		john.signForm(FormB);
// 		john.executeForm(FormB);
// 		john.signForm(FormC);
// 		john.executeForm(FormC);
// 	}
// 	catch (Bureaucrat::GradeTooLowException &e) {
// 		std::cerr << "Error: " << e.what() << std::endl;
// 	}
// 	endline(3);


// 	printSeparator("John 5", BOLD YELLOW);
// 	try {
// 		Bureaucrat	john("John", 5);
// 		// std::cout << ++john << std::endl;
// 		ShrubberyCreationForm	FormA("Shrubbery3"); // Required grades: sign 145, exec 137
// 		RobotomyRequestForm		FormB("Robotomy"); // Required grades: sign 72, exec 45
// 		PresidentialPardonForm	FormC("Presidential"); // Required grades: sign 25, exec 5
// 		john.signForm(FormA);
// 		john.executeForm(FormA);
// 		john.signForm(FormB);
// 		john.executeForm(FormB);
// 		john.signForm(FormC);
// 		john.executeForm(FormC);
// 	}
// 	catch (Bureaucrat::GradeTooLowException &e) {
// 		std::cerr << "Error: " << e.what() << std::endl;
// 	}
// }

