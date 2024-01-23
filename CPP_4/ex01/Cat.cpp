/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsohler <lsohler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 11:56:11 by lsohler           #+#    #+#             */
/*   Updated: 2024/01/23 14:36:23 by lsohler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() {
	this->type = "Cat";
	this->catBrain = new Brain();
	std::cout << "Cat: Default Constructor called." << std::endl;
}

Cat::Cat(Cat const &other) {
	this->type = other.getType();
	this->catBrain = new Brain();
	std::cout << "Cat: Copy Constructor called." << std::endl;
}

Cat::~Cat() {
	delete this->catBrain;
	std::cout << "Cat: Default Destructor called." << std::endl;

}

Cat &Cat::operator=(Cat const &other) {
	std::cout << "Cat: Operator Constructor called." << std::endl;
	if (this != &other) {
		*this = other;
	}
	return(*this);
}

void	Cat::makeSound() {
	std::cout << "Miaou" << std::endl;
}

Brain&	Cat::getBrain(void) {
	return (*this->catBrain);
}
