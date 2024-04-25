/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsohler <lsohler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 15:28:06 by lsohler           #+#    #+#             */
/*   Updated: 2024/04/24 18:47:19 by lsohler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int ac, char **av) {
	if (ac == 2) {
		RPN::calc(av[1]);
	} else {
		std::cout << "Usage: ./RPN <Inverted Polish mathematical expression>\n";
	}
	return 0;
}
