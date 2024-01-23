/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsohler <lsohler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 11:56:19 by lsohler           #+#    #+#             */
/*   Updated: 2024/01/23 14:38:59 by lsohler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() {
	this->type = "Dog";
	this->dogBrain = new Brain();
	std::cout << "Dog: Default Constructor called." << std::endl;
}

Dog::Dog(Dog const &other) {
	this->type = other.getType();
	this->dogBrain = new Brain();
	std::cout << "Dog: Copy Constructor called." << std::endl;
}

Dog::~Dog() {
	delete this->dogBrain;
	std::cout << "Dog: Default Destructor called." << std::endl;

}

Dog &Dog::operator=(Dog const &other) {
	std::cout << "Dog: Operator Constructor called." << std::endl;
	if (this != &other) {
		*this = other;
	}
	return(*this);
}

void	Dog::makeSound() {
	std::cout << "Wouf" << std::endl;
}

Brain&	Dog::getBrain(void) {
	return (*this->dogBrain);
}
