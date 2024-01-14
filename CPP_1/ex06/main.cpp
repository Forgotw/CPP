/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsohler <lsohler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 15:49:19 by lsohler           #+#    #+#             */
/*   Updated: 2024/01/14 16:56:56 by lsohler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"


int	main(int ac, char **av) {
	if (ac != 2) {
		std::cout << "Harl has nothing to say." << std::endl;
		return 1;
	}
	Harl harl;

	harl.complain(av[1]);
	return 0;
}
