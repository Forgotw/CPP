/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsohler <lsohler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 09:20:50 by lsohler@stu       #+#    #+#             */
/*   Updated: 2024/01/22 14:14:50 by lsohler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap {

public:

	ClapTrap(void);
	ClapTrap(std::string name);
	ClapTrap(std::string name, unsigned int hp, unsigned int ep, unsigned int ad);
	// ClapTrap(const ClapTrap& copy);
	// ClapTrap& operator=(const ClapTrap& assignation);
	~ClapTrap(void);
	void	attack(const std::string& target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
	void	displayInfo(void);


protected:

	std::string		_Name;
	unsigned int	_HitPoints;
	unsigned int	_EenergyPoints;
	unsigned int	_AttackDamage;

};


#endif
