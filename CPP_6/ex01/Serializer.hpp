/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsohler <lsohler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 15:26:58 by lsohler           #+#    #+#             */
/*   Updated: 2024/02/25 15:37:15 by lsohler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

/*
**==========================
**		Includes
**==========================
*/
#include <iostream>
#include <cstdint>
#include "data.h"

class Serializer
{
	private:
		Serializer();

	public:
		~Serializer();
		static uintptr_t serialize(Data *ptr);
		static Data* deserialize(uintptr_t raw);

};
