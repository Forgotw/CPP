/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsohler <lsohler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 12:49:56 by lsohler           #+#    #+#             */
/*   Updated: 2024/02/25 14:36:16 by lsohler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include "math.h"
#include <cstdio>

int main(int ac, char **av)
{
	try {
		if (ac == 2)
			ScalarConverter::converter(av[1]);
		else {
			std::string str = "42.42f";
			std::cout << "Input: " + str << std::endl;
			ScalarConverter::converter(str);
			std::cout << std::endl;
			
			str = "42.42";
			std::cout << "Input: " + str << std::endl;
			ScalarConverter::converter(str);
			std::cout << std::endl;

			str = "42";
			std::cout << "Input: " + str << std::endl;
			ScalarConverter::converter(str);
			std::cout << std::endl;

			str = "a";
			std::cout << "Input: " + str << std::endl;
			ScalarConverter::converter(str);
			std::cout << std::endl;

			str = "2147483648";
			std::cout << "Input: " + str << std::endl;
			ScalarConverter::converter(str);
			std::cout << std::endl;

			str = "-2147483649";
			std::cout << "Input: " + str << std::endl;
			ScalarConverter::converter(str);
			std::cout << std::endl;

			// std::stringstream ss;
			// ss << M_PI;
			// str = ss.str();
			// std::cout << "Input: " + str << std::endl;
			// ScalarConverter::converter(str);
			// std::cout << std::endl;

			// char buffer[50];
			// sprintf(buffer, "%lf", M_PI);
			// std::string str2(buffer);
			// str2 += "f";
			// std::cout << "Input: " + str2 << std::endl;
			// ScalarConverter::converter(str2);
			// std::cout << std::endl;
		}
	}
	catch (std::string errorMsg) {
		std::cerr << "Exception: " << errorMsg << std::endl;
	}
}

