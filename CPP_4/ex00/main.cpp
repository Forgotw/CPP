/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsohler <lsohler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 12:31:13 by lsohler           #+#    #+#             */
/*   Updated: 2024/02/09 14:57:55 by lsohler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "WrongAnimal.hpp"


int main() {
	Animal	A;
	Cat		C;
	Dog		D;
	WrongAnimal	WA;
	WrongCat	WC;

	std::cout << std::endl;
	A.makeSound();
	C.makeSound();
	D.makeSound();
	WA.makeSound();
	WC.makeSound();

	std::cout << std::endl;
	std::cout << "Type: " << A.getType() << std::endl;
	std::cout << "Type: " << C.getType() << std::endl;
	std::cout << "Type: " << D.getType() << std::endl;
	std::cout << "Type: " << WA.getType() << std::endl;
	std::cout << "Type: " << WC.getType() << std::endl;

	std::cout << std::endl;

	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	 WrongAnimal *w = new WrongCat();

	std::cout << std::endl;

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	std::cout << w->getType() << " " << std::endl;

	std::cout << std::endl;

	
	meta->makeSound();
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	w->makeSound();

	std::cout << std::endl;
	delete meta;
	delete w;
	delete j;
	delete i;
}
