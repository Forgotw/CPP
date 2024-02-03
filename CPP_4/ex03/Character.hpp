/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsohler <lsohler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 18:54:44 by lsohler           #+#    #+#             */
/*   Updated: 2024/02/02 14:44:06 by lsohler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

/*
**==========================
**		Includes
**==========================
*/
#include "Materia.hpp"

class ICharacter {
	public:
	virtual ~ICharacter(void) {}
	virtual std::string const & getName(void) const = 0;
	virtual void equip(AMateria* m) = 0;
	virtual void unequip(int idx) = 0;
	virtual void use(int idx, ICharacter& target) = 0;
};

class Character : public ICharacter {
	private:
		std::string	_name;
		AMateria*	_materiaList[4];

	public:
		Character(void);
		Character(std::string const &name);
		Character(Character const &other);
		~Character(void);

		Character &operator=(Character const &other);
		std::string const & getName(void) const;
		AMateria* getCharacterMateria(int i) const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
};
