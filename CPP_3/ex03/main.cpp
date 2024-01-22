/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsohler <lsohler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 10:47:11 by lsohler@stu       #+#    #+#             */
/*   Updated: 2024/01/22 16:43:00 by lsohler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int	main(void) {
	ClapTrap	george("George CLAP");
	ScavTrap	bill("Bill SCAV");
	FragTrap	henry("Henry FRAG");
	DiamondTrap	rihana("Rihana Diamond");

	george.displayInfo();
	bill.displayInfo();
	henry.displayInfo();
	rihana.displayInfo();
	rihana.highFivesGuys();
	rihana.guardGate();
	rihana.diamondStats();
	rihana.whoAmI();
	return 0;
}
