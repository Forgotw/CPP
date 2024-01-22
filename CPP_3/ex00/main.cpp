/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsohler@student.42.fr <lsohler>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 10:47:11 by lsohler@stu       #+#    #+#             */
/*   Updated: 2024/01/19 11:02:50 by lsohler@stu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void) {
	ClapTrap	george("George", 10, 10, 0);
	ClapTrap	bill("Bill", 10000, 100, 5);

	george.attack("Bill");
	bill.takeDamage(0);
	bill.attack("George");
	george.takeDamage(5);
	george.beRepaired(5);
	bill.attack("George");
	george.takeDamage(5);
	george.beRepaired(5);
	bill.attack("George");
	george.takeDamage(5);
	george.beRepaired(5);
	bill.attack("George");
	george.takeDamage(5);
	george.beRepaired(5);
	bill.attack("George");
	george.takeDamage(5);
	george.beRepaired(5);
	return 0;
}
