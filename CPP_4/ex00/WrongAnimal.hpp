#pragma once

/*
**==========================
**		Includes
**==========================
*/


class WrongAnimal
{
	private:

	public:
		WrongAnimal();
		WrongAnimal(WrongAnimal const &other);
		~WrongAnimal();

		WrongAnimal &operator=(WrongAnimal const &other);

};
