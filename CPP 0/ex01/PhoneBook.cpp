/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsohler <lsohler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 15:40:52 by lsohler           #+#    #+#             */
/*   Updated: 2023/12/01 17:08:00 by lsohler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void){
	std::cout << "My Awesome PhoneBook" << std::endl;
	std::cout << "--------------------" << std::endl;
	std::cout << "  -ADD : Enregistrer un nouveau contact" << std::endl;
	std::cout << "  -SEARCH : Affiche le contact demandé" << std::endl;
	std::cout << "    -ADDR : Enregistrer un nouveau contact random" << std::endl;
	std::cout << "    -FILLR : Enregistrer 8 nouveau contact random" << std::endl;
	std::cout << "  -EXIT : Le programme quitte et les contacts sont perdus à jamais !" << std::endl;
	std::cout << "Toute autre entrée est ignorée." << std::endl;
	std::cout << "--------------------" << std::endl;
	this->index = 0;
	std::srand(static_cast<unsigned>(std::time(0)));
	return;
}

PhoneBook::~PhoneBook(void) {
	std::cout << "My Awesome PhoneBook Out" << std::endl;
	return;
}

int	PhoneBook::PrintColumn(void) {
	if (this->index == 0) {
		std::cout << "PhoneBook empty" << std::endl;
		return (1);
	}
	std::cout << " ---------- ---------- ---------- ----------" << std::endl;
	for (int i = 0; i < this->index && i <= 7; i++){
		this->_contact[i].ViewShort(i);
	}
	std::cout << " ---------- ---------- ---------- ----------" << std::endl;
	return (0);
}

void	PhoneBook::Add(void) {
	_contact[this->index % 8].ContactSetup();
	this->index++;
	std::cout << "Nouveau contact enregistré" << std::endl;
}

void	PhoneBook::AddRandom(void) {
	_contact[this->index % 8].RandomContactSetup();
	this->index++;
	std::cout << "Nouveau contact Random enregistré" << std::endl;
}

void	PhoneBook::FillRandom(void) {
	for (int i = 0; i < 8; i++)
		AddRandom(); 
}

void	PhoneBook::Search(void) {
	std::string	input;

	if (PrintColumn())
		return ;
	std::cout << "Index: ";
	std::cin >> input;
	char	*end;
	int	index = std::strtol(input.c_str(), &end, 10);
	if (*end == '\0' && (index >= 0 && index <= 7) && index < this->index) {
		_contact[index].ViewFull(index);
	}
	else {
		std::cout << "Index not valid" << std::endl;
	}
}

void	PhoneBook::Read(void) {
	std::string	input = "";

	while (input.compare("EXIT")){
		if (!input.compare("ADD"))
			Add();
		else if (!input.compare("SEARCH"))
			Search();
		else if (!input.compare("ADDR"))
			AddRandom();
		else if (!input.compare("FILLR"))
			FillRandom();
		std::cin >> input;
	}
}
