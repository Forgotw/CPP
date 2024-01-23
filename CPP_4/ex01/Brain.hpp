/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsohler <lsohler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 13:17:01 by lsohler           #+#    #+#             */
/*   Updated: 2024/01/23 14:09:22 by lsohler          ###   ########.fr       */
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
#include <cstdlib>
#include <ctime>
#include "Colors.h"


class Brain {

	private:
		std::string	ideas[100];

	public:
		Brain();
		Brain(Brain const &other);
		~Brain();

		Brain	&operator=(Brain const &other);
		void	think(void);

};
