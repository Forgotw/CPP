/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsohler <lsohler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 11:56:11 by lsohler           #+#    #+#             */
/*   Updated: 2024/02/02 12:32:36 by lsohler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() {
	this->type = "Cat";
	this->catBrain = new Brain();
	std::cout << CAT DEFCONS << std::endl;
}

Cat::Cat(Cat const &other) {
	this->type = other.getType();
	this->catBrain = new Brain();
	for (int i = 0; i < 100; i++) {
		this->catBrain->setIdeas(other.getBrain().getIdeas(i), i);
	}
	std::cout << CAT COPYCONS << std::endl;
}

Cat::~Cat() {
	delete this->catBrain;
	std::cout << CAT DEFDES << std::endl;

}

Cat &Cat::operator=(Cat const &other) {
	std::cout << CAT OPECONS << std::endl;
	if (this != &other) {
		this->type = other.getType();
		this->catBrain = new Brain();
		for (int i = 0; i < 100; i++) {
			this->catBrain->setIdeas(other.getBrain().getIdeas(i), i);
		}
	}
	return(*this);
}

void	Cat::makeSound() const {
	std::cout << "Miaou" << std::endl;
}

Brain&	Cat::getBrain(void) const {
	return (*this->catBrain);
}
