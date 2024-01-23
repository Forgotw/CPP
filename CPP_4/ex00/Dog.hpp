/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsohler <lsohler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 11:56:22 by lsohler           #+#    #+#             */
/*   Updated: 2024/01/23 12:50:12 by lsohler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

/*
**==========================
**		Includes
**==========================
*/
#include "Animal.hpp"


class Dog : public Animal {

	private:

	public:
		Dog();
		Dog(Dog const &other);
		~Dog();

		Dog &operator=(Dog const &other);
		void makeSound(void);

};
