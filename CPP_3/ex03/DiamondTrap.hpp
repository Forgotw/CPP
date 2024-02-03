/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsohler <lsohler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 14:22:54 by lsohler           #+#    #+#             */
/*   Updated: 2024/02/02 18:25:48 by lsohler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef diamondtrap_hpp
# define diamondtrap_hpp

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {

public:

	DiamondTrap(void);
	DiamondTrap(const DiamondTrap& copy);
	DiamondTrap& operator=(const DiamondTrap& assignation);
	DiamondTrap(std::string name);
	~DiamondTrap(void);
	using	ScavTrap::attack;
	void	whoAmI(void);
	void	diamondStats(void);

	std::string		getName(void) const ;
	unsigned int	getHP(void) const ;
	unsigned int	getEP(void) const ;
	unsigned int	getAD(void) const ;

private:

	std::string	_Name;

};

#endif
