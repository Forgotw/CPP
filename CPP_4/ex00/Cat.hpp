#pragma once

/*
**==========================
**		Includes
**==========================
*/


class Cat
{
	private:

	public:
		Cat();
		Cat(Cat const &other);
		~Cat();

		Cat &operator=(Cat const &other);

};
