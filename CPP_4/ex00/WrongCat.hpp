#pragma once

/*
**==========================
**		Includes
**==========================
*/


class WrongCat
{
	private:

	public:
		WrongCat();
		WrongCat(WrongCat const &other);
		~WrongCat();

		WrongCat &operator=(WrongCat const &other);

};
