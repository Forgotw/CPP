/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsohler <lsohler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 12:31:13 by lsohler           #+#    #+#             */
/*   Updated: 2024/02/09 14:51:59 by lsohler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main() {
	std::srand(std::time(0));
	Animal	A;
	Cat		C;
	Dog		D;

	std::cout << std::endl;
	A.makeSound();

	std::cout << std::endl;
	C.makeSound();
	C.getBrain().think();
	std::cout << std::endl;
	D.makeSound();
	D.getBrain().think();

	Dog dogCopy;

	dogCopy = D;
	dogCopy.makeSound();
	dogCopy.getBrain().think();

	std::cout << std::endl;
	std::cout << "Type: " << A.getType() << std::endl;
	std::cout << "Type: " << C.getType() << std::endl;
	std::cout << "Type: " << D.getType() << std::endl;

	std::cout << std::endl;
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j;//should not create a leak
	delete i;
}
