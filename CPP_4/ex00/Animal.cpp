/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsohler <lsohler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 17:48:47 by lsohler           #+#    #+#             */
/*   Updated: 2024/02/05 16:21:42 by lsohler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() {
	this->type = "NoType";
	std::cout << "Animal: Default Constructor called." << std::endl;
}

Animal::Animal(Animal const &other) {
	this->type = other.getType();
	std::cout << "Animal: Copy Constructor called." << std::endl;
}

Animal::~Animal() {
	std::cout << "Animal: Default Destructor called." << std::endl;

}

Animal &Animal::operator=(Animal const &other) {
	std::cout << "Animal: Operator Constructor called." << std::endl;
	if (this != &other) {
		this->type = other.getType();
	}
	return(*this);
}

std::string Animal::getType(void) const {
	return (this->type);
}

void	Animal::makeSound(void) const {
	std::cout << "Basic animal noise" << std::endl;
}
