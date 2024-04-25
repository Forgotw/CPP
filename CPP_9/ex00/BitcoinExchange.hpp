/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsohler <lsohler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 16:41:31 by lsohler           #+#    #+#             */
/*   Updated: 2024/04/24 19:21:09 by lsohler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <map>
#include <string>


class BitcoinExchange {
	private:
		std::map<std::string, float>	_exchangeRates;
		void	readExchangeRates(void);
		void	displayData(void);
		bool	isValidDate(const std::string& date);
		float	isValidValue(const std::string& value);
		void	searchValue(const std::string& valueStr, float value);
	public:
		BitcoinExchange();
		BitcoinExchange(BitcoinExchange const &other);
		~BitcoinExchange();
		BitcoinExchange	&operator=(BitcoinExchange const &other);
		void	newInput(char *av);
		
};
