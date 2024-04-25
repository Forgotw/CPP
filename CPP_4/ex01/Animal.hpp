/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsohler <lsohler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 17:48:51 by lsohler           #+#    #+#             */
/*   Updated: 2024/02/05 16:33:45 by lsohler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

/*
**==========================
**		Include
**==========================
*/
#include <iostream>
#include <string>

class Animal {

	protected:
		std::string	type;

	public:
		Animal();
		Animal(Animal const &other);
		virtual ~Animal();
		Animal &operator=(Animal const &other);

		std::string	getType(void) const;
		virtual void makeSound(void);

};
