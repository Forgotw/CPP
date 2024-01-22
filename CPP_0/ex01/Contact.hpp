/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsohler <lsohler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 16:14:05 by lsohler           #+#    #+#             */
/*   Updated: 2024/01/16 12:19:18 by lsohler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <iomanip>
# include <cctype>
# include <string>

class Contact {

public:

	Contact(void);
	~Contact(void);
	void	ContactSetup(void);
	void	RandomContactSetup(void);
	void	ViewShort(int index);
	void	ViewFull(int index);

private:

	std::string	FirstName;
	std::string	LastName;
	std::string	SurName;
	std::string	PhoneNumber;
	std::string	DarkestSecret;
	std::string	CheckInfo(std::string Msg, std::string Input, int Mode);
	std::string AddInfo(std::string Msg, int Mode);
};

#endif
