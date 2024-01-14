/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsohler <lsohler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 10:41:17 by lsohler           #+#    #+#             */
/*   Updated: 2024/01/14 14:31:07 by lsohler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void) {
	Zombie *z;

	z = newZombie("George Heap");
	z->announce();
	delete z;
	randomChump("George Stack");
	return (0);
}
