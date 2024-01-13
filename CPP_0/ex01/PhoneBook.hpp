/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsohler <lsohler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 16:27:25 by lsohler           #+#    #+#             */
/*   Updated: 2024/01/13 18:05:03 by lsohler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {

public:

	PhoneBook(void);
	~PhoneBook(void);
	void	Add(void);
	void	Search(void);
	void	Read(void);
	void	AddRandom(void);
	void	FillRandom(void);

private:

	Contact	_contact[8];
	int	PrintColumn(void);
	int		index;
};

#endif
