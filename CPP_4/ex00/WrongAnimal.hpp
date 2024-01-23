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
		~WrongAnimal();

		std::string	getType(void) const;
		virtual void makeSound(void);
		WrongAnimal &operator=(WrongAnimal const &other);

};
