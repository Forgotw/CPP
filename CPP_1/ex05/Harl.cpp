/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsohler <lsohler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 15:48:56 by lsohler           #+#    #+#             */
/*   Updated: 2024/01/14 16:47:45 by lsohler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(void) {
	_debugLevel[0] = "DEBUG";
	_debugMessage[0] = "• DEBUG level: Debug messages contain contextual information. They are mostly used for problem diagnosis.";
	_debugFunctions[0] = &Harl::debug;
	_debugLevel[1] = "INFO";
	_debugMessage[1] = "• INFO level: These messages contain extensive information. They are helpful for tracing program execution in a production environment.";
	_debugFunctions[1] = &Harl::info;
	_debugLevel[2] = "WARNING";
	_debugMessage[2] = "• WARNING level: Warning messages indicate a potential issue in the system. However, it can be handled or ignored.";
	_debugFunctions[2] = &Harl::warning;
	_debugLevel[3] = "ERROR";
	_debugMessage[3] = "• ERROR level: These messages indicate an unrecoverable error has occurred. This is usually a critical issue that requires manual intervention.";
	_debugFunctions[3] = &Harl::error;
}

Harl::~Harl(void) {
}

void Harl::debug(void) {
	std::cout << _debugMessage[0] << std::endl;
}

void Harl::info(void) {
	std::cout << _debugMessage[1] << std::endl;
}
void Harl::warning(void) {
	std::cout << _debugMessage[2] << std::endl;
}

void Harl::error(void) {
	std::cout << _debugMessage[3] << std::endl;
}


void Harl::complain(std::string level) {
	for (int i = 0; i < 4; i++){
		if (level == _debugLevel[i]) {
			(this->*_debugFunctions[i])();
			return ;
		}
	}
	std::cout << "Harl has nothing to say." << std::endl;
}
