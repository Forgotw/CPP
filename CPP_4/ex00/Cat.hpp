/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsohler <lsohler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 11:56:16 by lsohler           #+#    #+#             */
/*   Updated: 2024/01/23 12:48:26 by lsohler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

/*
**==========================
**		Includes
**==========================
*/
#include "Animal.hpp"


class Cat : public Animal {

	private:

	public:
		Cat();
		Cat(Cat const &other);
		~Cat();

		Cat &operator=(Cat const &other);
		void makeSound(void);
};
