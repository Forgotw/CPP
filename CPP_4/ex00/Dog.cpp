/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsohler <lsohler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 11:56:19 by lsohler           #+#    #+#             */
/*   Updated: 2024/02/05 16:21:53 by lsohler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() {
	this->type = "Dog";
	std::cout << "Dog: Default Constructor called." << std::endl;
}

Dog::Dog(Dog const &other) {
	this->type = other.getType();
	std::cout << "Dog: Copy Constructor called." << std::endl;
}

Dog::~Dog() {
	std::cout << "Dog: Default Destructor called." << std::endl;

}

Dog &Dog::operator=(Dog const &other) {
	std::cout << "Dog: Operator Constructor called." << std::endl;
	if (this != &other) {
		this->type = other.getType();
	}
	return(*this);
}

void	Dog::makeSound() const {
	std::cout << "Wouf" << std::endl;
}
