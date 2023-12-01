/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsohler <lsohler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 16:13:47 by lsohler           #+#    #+#             */
/*   Updated: 2023/12/01 17:07:34 by lsohler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void) {

	// std::cout << "Contact Constructor Called" << std::endl;
	return;
}

Contact::~Contact(void) {

	// std::cout << "Contact Destructor Called" << std::endl;
	return;
}

std::string	Contact::CheckInfo(std::string Msg, std::string Input, int Mode) {
	if (!Input.size() || (Mode == 1 && Input.size() >= 10)) {
		std::cout << "Invalid try again" << std::endl;
		return (AddInfo(Msg, Mode));
	}
	else
		return (Input);
}

std::string Contact::AddInfo(std::string Msg, int Mode) {
	std::string Input;

	std::cout << Msg;
	if (std::cin.good() || !std::cin.eof()) {
		Input.clear();
		while(Input.empty())
			std::getline(std::cin, Input);
		if (!std::cin.fail())
			return CheckInfo(Msg, Input, Mode);
	}
	std::cin.clear();
	return ("Error");
}

void	Contact::ContactSetup(void) {
	Contact::FirstName = AddInfo("First Name: ", 0);
	Contact::LastName = AddInfo("Last Name: ", 0);
	Contact::SurName = AddInfo("Surname:", 0);
	Contact::PhoneNumber = AddInfo("Phone Number: ", 1);
	Contact::DarkestSecret = AddInfo("Darkest Secret: ", 0);
}

std::string generateRandomString(int length, char *base) {
	int	charactersCount = sizeof(base) - 1;

	std::string result;
	for (int i = 0; i < length; ++i) {
		result += base[std::rand() % charactersCount];
	}
	return result;
}

void	Contact::RandomContactSetup(void) {
	char alpha[] = "abcdefgABCDEFG";
	char num[] = "0123456789";
	char secret[] = "xyzXYZ";

	Contact::FirstName = generateRandomString(8, alpha);
	Contact::LastName = generateRandomString(12, alpha);
	Contact::SurName = generateRandomString(4, alpha);
	Contact::PhoneNumber = generateRandomString(10, num);
	Contact::DarkestSecret = generateRandomString(20, secret);
}

std::string	StringLen(std::string str) {
	if (str.length() > 10)
		return (str.substr(0, 9) + ".");
	return (str);
}

void	Contact::ViewShort(int index) {
	std::cout << "|" << std::setw(10) << index;
	std::cout << "|" << std::setw(10) << StringLen(this->FirstName);
	std::cout << "|" << std::setw(10) << StringLen(this->LastName);
	std::cout << "|" << std::setw(10) << StringLen(this->SurName);
	std::cout << "|" << std::endl;
}

void	Contact::ViewFull(int index) {
	std::cout << "Index: " << index << std::endl;
	std::cout << "First Name: " << this->FirstName << std::endl;
	std::cout << "Last Name: " << this->LastName << std::endl;
	std::cout << "SurName: " << this->SurName << std::endl;
	std::cout << "Phone Number: " << this->PhoneNumber << std::endl;
	std::cout << "Darkest Secret: " << this->DarkestSecret << std::endl;
}
