/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsohler <lsohler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 11:12:16 by lsohler@stu       #+#    #+#             */
/*   Updated: 2024/01/22 16:55:11 by lsohler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public virtual ClapTrap {

public:

	ScavTrap(std::string name);
	~ScavTrap(void);
	void attack(const std::string& target);
	void guardGate(void);

protected:

	static const unsigned int	_HP = 100;
	static const unsigned int	_EP = 50;
	static const unsigned int	_AD = 20;

private:

	unsigned int	_guardSate;

};

#endif
