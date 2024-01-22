/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsohler <lsohler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 11:12:16 by lsohler@stu       #+#    #+#             */
/*   Updated: 2024/01/22 16:54:28 by lsohler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public virtual ClapTrap {

public:

	FragTrap(std::string name);
	~FragTrap(void);
	void	highFivesGuys(void);

protected:

	static const unsigned int	_HP = 100;
	static const unsigned int	_EP = 100;
	static const unsigned int	_AD = 30;

private:


};

#endif
