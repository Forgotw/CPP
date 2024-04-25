/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsohler <lsohler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 11:56:11 by lsohler           #+#    #+#             */
/*   Updated: 2024/02/05 16:21:47 by lsohler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() {
	this->type = "Cat";
	std::cout << "Cat: Default Constructor called." << std::endl;
}

Cat::Cat(Cat const &other) {
	this->type = other.getType();
	std::cout << "Cat: Copy Constructor called." << std::endl;
}

Cat::~Cat() {
	std::cout << "Cat: Default Destructor called." << std::endl;

}

Cat &Cat::operator=(Cat const &other) {
	std::cout << "Cat: Operator Constructor called." << std::endl;
	if (this != &other) {
		this->type = other.getType();
	}
	return(*this);
}

void	Cat::makeSound() const {
	std::cout << "Miaou" << std::endl;
}
