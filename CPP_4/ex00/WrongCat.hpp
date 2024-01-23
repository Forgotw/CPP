/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsohler <lsohler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 11:56:33 by lsohler           #+#    #+#             */
/*   Updated: 2024/01/23 13:11:06 by lsohler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

/*
**==========================
**		Includes
**==========================
*/
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {

	private:

	public:
		WrongCat();
		WrongCat(WrongCat const &other);
		~WrongCat();

		void makeSound(void);
		WrongCat &operator=(WrongCat const &other);

};
