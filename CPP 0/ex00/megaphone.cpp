/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsohler <lsohler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 13:46:29 by lsohler           #+#    #+#             */
/*   Updated: 2023/11/22 15:30:35 by lsohler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>
#include <string>
#include <string.h>

std::string	mega(char *str)
{
	for (size_t i = 0; i < strlen(str);){
		str[i] = std::toupper(str[i]); i++;}
	return (std::string(str));
}

int	main(int ac, char **argv)
{
	if (ac == 1)
		std::cout << "Veuillez commencer les modules CPP";
	if (ac > 1)
		for (int i = 1; i < ac;){
			std::cout << " " << mega(argv[i]); i++;}
	std::cout << std::endl;
	return (0);
}