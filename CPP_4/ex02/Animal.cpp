/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsohler <lsohler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 17:48:47 by lsohler           #+#    #+#             */
/*   Updated: 2024/02/02 11:02:05 by lsohler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Colors.h"

Animal::Animal() {
	this->type = "NoType";
	std::cout << ANIMAL DEFCONS << std::endl;
}

Animal::Animal(Animal const &other) {
	this->type = other.getType();
	std::cout << ANIMAL COPYCONS << std::endl;
}

Animal::~Animal() {
	std::cout << ANIMAL DEFDES << std::endl;

}

Animal &Animal::operator=(Animal const &other) {
	std::cout << ANIMAL OPECONS << std::endl;
	if (this != &other) {
		this->type = other.getType();
	}
	return(*this);
}

std::string Animal::getType(void) const {
	return (this->type);
}
