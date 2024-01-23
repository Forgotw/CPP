/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsohler <lsohler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 12:31:13 by lsohler           #+#    #+#             */
/*   Updated: 2024/01/23 13:13:53 by lsohler          ###   ########.fr       */
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
}
