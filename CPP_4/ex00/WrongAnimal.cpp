/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsohler <lsohler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 11:56:24 by lsohler           #+#    #+#             */
/*   Updated: 2024/01/23 13:14:12 by lsohler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() {
	this->type = "WrongNoType";
	std::cout << "WrongAnimal: Default Constructor called." << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const &other) {
	this->type = other.getType();
	std::cout << "WrongAnimal: Copy Constructor called." << std::endl;
}

WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal: Default Destructor called." << std::endl;

}

WrongAnimal &WrongAnimal::operator=(WrongAnimal const &other) {
	std::cout << "WrongAnimal: Operator Constructor called." << std::endl;
	if (this != &other) {
		this->type = other.getType();
	}
	return(*this);
}

std::string WrongAnimal::getType(void) const {
	return (this->type);
}

void	WrongAnimal::makeSound(void) {
	std::cout << "Wrong animal noise" << std::endl;
}
