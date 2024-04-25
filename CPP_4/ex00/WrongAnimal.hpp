#pragma once

/*
**==========================
**		Includes
**==========================
*/
#include "Animal.hpp"


class WrongAnimal {

	protected:
		std::string	type;

	public:
		WrongAnimal();
		WrongAnimal(WrongAnimal const &other);
		virtual ~WrongAnimal();

		std::string	getType(void) const;
		// void makeSound(void);
		virtual void makeSound(void);
		WrongAnimal &operator=(WrongAnimal const &other);

};
