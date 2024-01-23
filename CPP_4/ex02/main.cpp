/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsohler <lsohler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 12:31:13 by lsohler           #+#    #+#             */
/*   Updated: 2024/01/23 17:44:43 by lsohler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main() {
	std::srand(std::time(0));
	Animal	*C = new Cat();
	Animal	*D = new Dog();
	// Cat		C;
	// Dog		D;

	// std::cout << std::endl;
	// A.makeSound();
	std::cout << std::endl;
	std::cout << BOLD RED "-------Testing Abstract Sound and Ideas------" RESET << std::endl;
	C->makeSound();
	((Cat *) C)->getBrain().think();
	// C.makeSound();
	// C.getBrain().think();
	std::cout << std::endl;
	D->makeSound();
	((Dog *) D)->getBrain().think();
	((Dog *) D)->getBrain().resetIdeas();
	((Dog *) D)->getBrain().think();

	std::cout << std::endl;
	std::cout << BOLD RED "-------Testing deep copy with brain idea------" RESET << std::endl;
	Dog *D2 = new Dog();
	std::cout << BOLD WHITE "D2:" RESET << std::endl;
	D2->getBrain().think();
	D2->getBrain().resetIdeas();
	D2->getBrain().think();
	std::cout << BOLD WHITE "D3:" RESET << std::endl;
	Dog *D3 = new Dog(*D2);
	D3->getBrain().think();
	delete D2;
	delete D3;
	// D.makeSound();
	// D.getBrain().think();

	std::cout << std::endl;
	std::cout << BOLD RED "-------Testing Abstract Type------" RESET << std::endl;
	// std::cout << "Type: " << A.getType() << std::endl;
	std::cout << "Type: " << C->getType() << std::endl;
	std::cout << "Type: " << D->getType() << std::endl;
	// std::cout << "Type: " << C.getType() << std::endl;
	// std::cout << "Type: " << D.getType() << std::endl;

	std::cout << std::endl;
	delete C;
	delete D;

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << BOLD RED "-------Testing Array------" RESET << std::endl;
	Animal *array[10];
	for (int i = 0; i < 5; i++) {
		array[i] = new Dog();
	}
	for (int i = 5; i < 10; i++) {
		array[i] = new Cat();
	}
	std::cout << std::endl;
	std::cout << std::endl;
	for (int i = 0; i < 10; i++) {
		std::cout << "Type: " << array[i]->getType() << std::endl;
		array[i]->makeSound();
	}
	std::cout << std::endl;
	std::cout << std::endl;
	for (int i = 0; i < 10; i++) {
		delete array[i];
	}
}
// int main()
// {
// const Dog* j = new Dog();
// const Cat* i = new Cat();
// const Dog* k = new Dog();
// //const Animal l(j);
// delete j;
// //std::cout << l.getType() << std::endl;
// //l.makeSound();
// //const Animal lol = new Animal(); // ne fonctionne pas (Animal est abstraite / purement virtuelle donc non instanciable)
// const Dog r(*k);
// const Cat s(*i);
// delete k; //should not create a leak
// delete i;
// Animal *array[50];
// (void)array;

// return 0;
// }
// int main() {
//     Animal *array[10];

//     // Initialisation des premiers 10 éléments avec des objets de type Dog
//     for (int i = 0; i < 10; i++) {
//         array[i] = new Dog();
//     }
// 	// array[0] = new Dog();
// 	// array[0]->makeSound();
//     // Utilisation des objets du tableau
//     for (int i = 0; i < 10; i++) {
//         array[i]->makeSound();
//     }

//     // Libération de la mémoire allouée dynamiquement
//     for (int i = 0; i < 10; i++) {
//         delete array[i];
//     }
//     return 0;
// }
