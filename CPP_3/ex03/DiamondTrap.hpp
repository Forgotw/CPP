/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsohler <lsohler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 14:22:54 by lsohler           #+#    #+#             */
/*   Updated: 2024/01/22 16:11:30 by lsohler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef diamondtrap_hpp
# define diamondtrap_hpp

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {

public:

	DiamondTrap(std::string name);
	~DiamondTrap(void);
	using	ScavTrap::attack;
	void	whoAmI(void);
	void	diamondStats(void);

private:

	std::string	_Name;

};

#endif
