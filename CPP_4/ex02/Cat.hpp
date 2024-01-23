/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsohler <lsohler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 11:56:16 by lsohler           #+#    #+#             */
/*   Updated: 2024/01/23 17:09:54 by lsohler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

/*
**==========================
**		Includes
**==========================
*/
#include "Animal.hpp"
#include "Brain.hpp"


class Cat : public Animal {

	private:
		Brain*	catBrain;

	public:
		Cat();
		Cat(Cat const &other);
		~Cat();

		Cat &operator=(Cat const &other);
		void makeSound(void) const;
		Brain&	getBrain(void) const;
};
