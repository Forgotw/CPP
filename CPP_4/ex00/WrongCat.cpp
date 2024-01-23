/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsohler <lsohler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 11:56:30 by lsohler           #+#    #+#             */
/*   Updated: 2024/01/23 13:14:22 by lsohler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() {
	this->type = "WrongCat";
	std::cout << "WrongCat: Default Constructor called." << std::endl;
}

WrongCat::WrongCat(WrongCat const &other) {
	this->type = other.getType();
	std::cout << "WrongCat: Copy Constructor called." << std::endl;
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat: Default Destructor called." << std::endl;

}

WrongCat &WrongCat::operator=(WrongCat const &other) {
	std::cout << "WrongCat: Operator Constructor called." << std::endl;
	if (this != &other) {
		this->type = other.getType();
	}
	return(*this);
}

void	WrongCat::makeSound(void) {
	std::cout << "Wrong cat noise" << std::endl;
}
