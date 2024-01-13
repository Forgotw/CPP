/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsohler <lsohler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 13:31:45 by lsohler           #+#    #+#             */
/*   Updated: 2024/01/13 14:33:57 by lsohler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

#include <iostream>
#include <string>
#include <Weapon.hpp>

class HumanA {

public:

	HumanA(std::string name, Weapon &weapon);
	HumanA(void);
	~HumanA(void);
	void	attack(void);

private:
	std::string	_Name;
	Weapon		&_Weapon;

};


#endif
