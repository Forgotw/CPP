/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsohler <lsohler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 15:44:00 by lsohler           #+#    #+#             */
/*   Updated: 2024/01/14 15:32:31 by lsohler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replace.hpp"

int	main(int ac, char **av) {
	if (ac != 4) {
		std::cout << "Correct usage is: ./Replace <filename> <stringFind> <stringReplace>" << std::endl;
		return 1;
	}
	Replace	replaceClass;
	replaceClass.replaceInNewFile(av[1], av[2], av[3]);
	return 0;
}
