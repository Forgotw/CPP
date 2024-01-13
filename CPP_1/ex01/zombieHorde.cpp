/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsohler <lsohler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 12:23:30 by lsohler           #+#    #+#             */
/*   Updated: 2024/01/13 13:03:24 by lsohler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie	*zombieHorde(int n, std::string name) {
	Zombie *horde = new Zombie[n];
	for (int i = 0; i < n; i++) {
		horde[i].setName(name);
	}
	return horde;
}
