/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsohler <lsohler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 12:45:35 by lsohler           #+#    #+#             */
/*   Updated: 2024/02/05 11:07:11 by lsohler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

/*
**==========================
**		Includes
**==========================
*/
#include "Materia.hpp"

class Ice : public  AMateria {

	public:
		Ice(void);
		Ice(Ice const &copy);
		~Ice(void);
		Ice& operator=(Ice const &copy);

		virtual AMateria*	clone(void) const;
		void				use(ICharacter &target);
};
