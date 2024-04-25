/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsohler <lsohler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 11:56:19 by lsohler           #+#    #+#             */
/*   Updated: 2024/02/05 16:36:03 by lsohler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : dogBrain(nullptr) {
	this->type = "Dog";
	this->dogBrain = new Brain();
	std::cout << "Dog: Default Constructor called." << std::endl;
}

Dog::Dog(Dog const &other) : dogBrain(nullptr) {
	this->type = other.getType();
	this->dogBrain = new Brain();
	for (int i = 0; i < 100; i++) {
		this->dogBrain->setIdeas(other.getBrain().getIdeas(i), i);
	}
	std::cout << "Dog: Copy Constructor called." << std::endl;
}

Dog::~Dog() {
	delete this->dogBrain;
	std::cout << "Dog: Default Destructor called." << std::endl;

}

Dog &Dog::operator=(Dog const &other) {
	std::cout << "Dog: Operator Constructor called." << std::endl;
	if (this != &other) {
		this->type = other.getType();
		if (this->dogBrain)
			delete this->dogBrain;
		this->dogBrain = new Brain();
		for (int i = 0; i < 100; i++) {
			this->dogBrain->setIdeas(other.getBrain().getIdeas(i), i);
		}
	}
	return(*this);
}

void	Dog::makeSound() {
	std::cout << "Wouf" << std::endl;
}

Brain&	Dog::getBrain(void) const {
	return (*this->dogBrain);
}
