/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsohler <lsohler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 12:45:20 by lsohler           #+#    #+#             */
/*   Updated: 2024/02/05 11:05:54 by lsohler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

/*
**==========================
**		Includes
**==========================
*/
#include "Materia.hpp"

class Cure : public  AMateria {

	public:
		Cure(void);
		Cure(Cure const &copy);
		~Cure(void);
		Cure& operator=(Cure const &copy);

		virtual AMateria*	clone(void) const;
		void				use(ICharacter &target);
};
