/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsohler <lsohler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 14:32:49 by lsohler           #+#    #+#             */
/*   Updated: 2024/02/16 12:14:26 by lsohler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

/*
**==========================
**		Includes
**==========================
*/
#include "Colors.h"
#include "AForm.hpp"

class AForm;

class Intern {

	private:

	public:
	Intern();
	Intern(const Intern &other);
	~Intern();
	Intern&	operator=(Intern const &other);

	AForm*	makeForm(std::string request, std::string target);
};
