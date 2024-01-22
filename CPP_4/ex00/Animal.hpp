/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsohler <lsohler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 17:48:51 by lsohler           #+#    #+#             */
/*   Updated: 2024/01/22 17:48:59 by lsohler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

/*
**==========================
**		Includes
**==========================
*/


class Animal
{
	private:

	public:
		Animal();
		Animal(Animal const &other);
		~Animal();

		Animal &operator=(Animal const &other);

};
