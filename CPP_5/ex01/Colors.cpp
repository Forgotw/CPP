/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Colors.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsohler <lsohler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 11:51:01 by lsohler           #+#    #+#             */
/*   Updated: 2024/02/05 11:33:59 by lsohler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Colors.h"

void	constructionMsg(std::string msg, int mode) {
	if (mode == 1) {
		std::cout << msg << std::endl;
	}
}

void	endline(int	n) {
	for (int i = 0; i < n; i++) {
		std::cout << std::endl;
	}
}

void	printSeparator(std::string str, std::string color) {
	if (!str.empty()) {
		std::cout << color << "*----- " << str << " -----*" << RESET << std::endl;
	}
	else
		std::cout << color << "*--------------------*" << RESET << std::endl;
}
