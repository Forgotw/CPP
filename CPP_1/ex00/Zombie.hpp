/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsohler <lsohler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 10:41:07 by lsohler           #+#    #+#             */
/*   Updated: 2024/01/13 12:26:57 by lsohler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie {

public:

	Zombie(std::string name);
	Zombie(void);
	~Zombie(void);
	void	announce(void);

private:

	std::string	_Name;

};

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);

#endif
