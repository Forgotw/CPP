/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsohler <lsohler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 16:55:32 by lsohler           #+#    #+#             */
/*   Updated: 2024/04/23 12:05:47 by lsohler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int	main(int ac, char **av) {
	if (ac > 2) {
		// std::cout << "av: " << av << std::endl;
		// for (int i = 1; av[i]; i++) {
		// 	std::cout << av[i];
		// }
		// std::cout << std::endl;
		PmergeMe	pmergeme(av);
	}
}
