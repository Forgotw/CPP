/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsohler <lsohler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 13:34:31 by lsohler           #+#    #+#             */
/*   Updated: 2024/03/05 16:19:01 by lsohler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#pragma once

/*
**==========================
**		Includes
**==========================
*/
#include <iostream>
#include <string>
#include <limits>
#include <iomanip>
#include <sstream>
#include <cstdlib>
#include <cstring>

class ScalarConverter {

	private:
	ScalarConverter();
	~ScalarConverter();

	public:
	static void converter(const std::string& str);
};
