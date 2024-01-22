/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsohler@student.42.fr <lsohler>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 10:47:11 by lsohler@stu       #+#    #+#             */
/*   Updated: 2024/01/19 11:52:28 by lsohler@stu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	main(void) {
	ClapTrap	george("George CLAP");
	ScavTrap	bill("Bill SCAV");

	bill.attack("George");
	george.takeDamage(20);
	george.beRepaired(20);
	george.beRepaired(20);
	george.beRepaired(20);
	george.beRepaired(20);
	george.beRepaired(20);
	std::cout << std::endl;
	bill.attack("George");
	george.takeDamage(20);
	bill.attack("George");
	george.takeDamage(20);
	bill.attack("George");
	george.takeDamage(20);
	bill.attack("George");
	george.takeDamage(20);
	bill.attack("George");
	george.takeDamage(20);
	bill.attack("George");
	george.takeDamage(20);
	std::cout << std::endl;
	bill.beRepaired(50);
	bill.guardGate();
	bill.guardGate();
	return 0;
}
