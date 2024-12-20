/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsohler <lsohler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 11:56:11 by lsohler           #+#    #+#             */
/*   Updated: 2024/02/05 16:35:50 by lsohler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : catBrain(nullptr) {
	this->type = "Cat";
	this->catBrain = new Brain();
	std::cout << "Cat: Default Constructor called." << std::endl;
}

Cat::Cat(Cat const &other) : catBrain(nullptr)  {
	this->type = other.getType();
	this->catBrain = new Brain();
	for (int i = 0; i < 100; i++) {
		this->catBrain->setIdeas(other.getBrain().getIdeas(i), i);
	}
	std::cout << "Cat: Copy Constructor called." << std::endl;
}

Cat::~Cat() {
	delete this->catBrain;
	std::cout << "Cat: Default Destructor called." << std::endl;

}

Cat &Cat::operator=(Cat const &other) {
	std::cout << "Cat: Operator Constructor called." << std::endl;
	if (this != &other) {
		this->type = other.getType();
		if (this->catBrain)
			delete  this->catBrain;
		this->catBrain = new Brain();
		for (int i = 0; i < 100; i++) {
			this->catBrain->setIdeas(other.getBrain().getIdeas(i), i);
		}
	}
	return(*this);
}

void	Cat::makeSound() {
	std::cout << "Miaou" << std::endl;
}

Brain&	Cat::getBrain(void) const {
	return (*this->catBrain);
}
