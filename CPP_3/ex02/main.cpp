/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsohler <lsohler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 10:47:11 by lsohler@stu       #+#    #+#             */
/*   Updated: 2024/01/22 14:18:55 by lsohler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main(void) {
	ClapTrap	george("George CLAP");
	ScavTrap	bill("Bill SCAV");
	FragTrap	henry("Henry FRAG");

	george.displayInfo();
	bill.displayInfo();
	henry.displayInfo();
	henry.highFivesGuys();
	return 0;
}
