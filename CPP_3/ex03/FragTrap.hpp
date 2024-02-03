/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsohler <lsohler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 11:12:16 by lsohler@stu       #+#    #+#             */
/*   Updated: 2024/02/02 17:58:31 by lsohler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public virtual ClapTrap {

public:
	FragTrap(void);
	FragTrap(std::string name);
	FragTrap(const FragTrap& copy);
	FragTrap& operator=(const FragTrap& assignation);
	~FragTrap(void);
	void	highFivesGuys(void);

	std::string		getName(void) const ;
	unsigned int	getHP(void) const ;
	unsigned int	getEP(void) const ;
	unsigned int	getAD(void) const ;

protected:

	static const unsigned int	_HP = 100;
	static const unsigned int	_EP = 100;
	static const unsigned int	_AD = 30;

private:


};

#endif
