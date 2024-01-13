/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsohler <lsohler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 12:30:00 by lsohler           #+#    #+#             */
/*   Updated: 2024/01/13 13:08:07 by lsohler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(int ac, char **av) {
	if (ac < 2)
		return 1;
	int size = atoi(av[1]);
	if (size <= 0 || size > 50)
		return 1;
	Zombie *horde = zombieHorde(size, "george");
	for (int i = 0; i < size; i++) {
		horde[i].announce();
	}
	if (ac == 3 && atoi(av[2]) == 1) {
		std::cout << "\033[1;33mAdding number to zombie\033[0m" << std::endl;
		for (int i = 0; i < size; i++) {
			horde[i].setName("GeorgeThe \033[1;32m" + std::to_string(i) + "\033[0m");
			horde[i].announce();
		}
	}
	delete [] horde;
}
