/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsohler <lsohler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 11:56:19 by lsohler           #+#    #+#             */
/*   Updated: 2024/01/23 17:18:51 by lsohler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() {
	this->type = "Dog";
	this->dogBrain = new Brain();
	std::cout << DOG DEFCONS << std::endl;
}

Dog::Dog(Dog const &other) {
	this->type = other.getType();
	this->dogBrain = new Brain();
	for (int i = 0; i < 100; i++) {
		this->dogBrain->setIdeas(other.getBrain().getIdeas(i), i);
	}
	std::cout << DOG COPYCONS << std::endl;
}

Dog::~Dog() {
	delete this->dogBrain;
	std::cout << DOG DEFDES << std::endl;

}

Dog &Dog::operator=(Dog const &other) {
	std::cout << DOG OPECONS << std::endl;
	if (this != &other) {
		// this->type = other.getType();
		// this->dogBrain = new Brain();
		*this = other;
	}
	return(*this);
}

void	Dog::makeSound() const {
	std::cout << "Wouf" << std::endl;
}

Brain&	Dog::getBrain(void) const {
	return (*this->dogBrain);
}
