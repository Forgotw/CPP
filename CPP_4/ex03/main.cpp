/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsohler <lsohler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:34:52 by lsohler           #+#    #+#             */
/*   Updated: 2024/02/05 16:48:06 by lsohler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Materia.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"
#include "Colors.h"

int main()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	endline(1);

	ICharacter* me = new Character("me");
	endline(1);

	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	endline(1);

	ICharacter* bob = new Character("bob");
	endline(1);

	me->use(0, *bob);
	me->use(1, *bob);
	delete bob;
	delete me;
	delete src;
	endline(3);



	printSeparator("Wizard", BOLD CYAN);
	ICharacter* Wizard = new Character("Wizard");
	IMateriaSource* Spellbook = new MateriaSource();
	Spellbook->learnMateria(new (Ice));
	Spellbook->learnMateria(new (Ice));
	Spellbook->learnMateria(new (Ice));
	Spellbook->learnMateria(new (Ice));
	Spellbook->learnMateria(new (Ice));
	tmp = Spellbook->createMateria("ice");
	Wizard->equip(tmp);
	tmp = Spellbook->createMateria("ice");
	Wizard->equip(tmp);
	tmp = Spellbook->createMateria("ice");
	Wizard->equip(tmp);
	tmp = Spellbook->createMateria("ice");
	Wizard->equip(tmp);
	tmp = Spellbook->createMateria("ice");
	Wizard->equip(tmp);
	// delete tmp;
	printSeparator("", BOLD CYAN);
	endline(1);

	printSeparator("Healer", BOLD MAGENTA);
	ICharacter* Healer = new Character("Healer");
	IMateriaSource* Healingbook = new MateriaSource();
	Healingbook->learnMateria(new (Cure));
	Healingbook->learnMateria(new (Cure));
	Healingbook->learnMateria(new (Cure));
	Healingbook->learnMateria(new (Cure));
	Healingbook->learnMateria(new (Cure));
	tmp = Healingbook->createMateria("cure");
	Healer->equip(tmp);
	tmp = Healingbook->createMateria("cure");
	Healer->equip(tmp);
	tmp = Healingbook->createMateria("cure");
	Healer->equip(tmp);
	tmp = Healingbook->createMateria("cure");
	Healer->equip(tmp);
	tmp = Healingbook->createMateria("cure");
	Healer->equip(tmp);
	// delete tmp;
	printSeparator("", BOLD MAGENTA);
	endline(3);


	printSeparator("Wizard", BOLD CYAN);
	for (int i = 0; i < 5; i++) {
		Wizard->use(i, *Healer);
	}
	for (int i = 0; i < 5; i++) {
		Wizard->unequip(i);
	}
	printSeparator("", BOLD CYAN);
	endline(1);

	printSeparator("Healer", BOLD MAGENTA);
	for (int i = 0; i < 5; i++) {
		Healer->use(i, *Healer);
	}
	for (int i = 0; i < 5; i++) {
		Healer->unequip(i);
	}
	printSeparator("", BOLD MAGENTA);
	delete Wizard;

	delete Spellbook;
	delete Healer;
	delete Healingbook;
	return 0;
	// IMateriaSource* src = new MateriaSource();
	// src->learnMateria(new Ice());
	// src->learnMateria(new Cure());
	// ICharacter* me = new Character("me");
	// AMateria* tmp;
	// tmp = src->createMateria("ice");
	// me->equip(tmp);
	// tmp = src->createMateria("cure");
	// me->equip(tmp);
	// ICharacter* bob = new Character("bob");
	// me->use(0, *bob);
	// me->use(1, *bob);
	// delete bob;
	// delete me;
	// delete src;
	// return 0;
}
