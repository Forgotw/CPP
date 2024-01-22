#pragma once

/*
**==========================
**		Includes
**==========================
*/


class Dog
{
	private:

	public:
		Dog();
		Dog(Dog const &other);
		~Dog();

		Dog &operator=(Dog const &other);

};
