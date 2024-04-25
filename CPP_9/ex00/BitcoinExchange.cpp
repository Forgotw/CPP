/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsohler <lsohler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 16:44:26 by lsohler           #+#    #+#             */
/*   Updated: 2024/04/25 14:01:17 by lsohler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <fstream>
#include <sstream>
#include <algorithm>


BitcoinExchange::BitcoinExchange(void) {
	readExchangeRates();
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &other) {
	*this = other;
}

BitcoinExchange	&BitcoinExchange::operator=(BitcoinExchange const &other) {
	if (this != &other) {
		_exchangeRates = other._exchangeRates;
	}
	return *this;
}

BitcoinExchange::~BitcoinExchange() {

}



void BitcoinExchange::readExchangeRates(void) {
	std::ifstream file("data.csv");
	if (!file.is_open()) {
		std::cerr << "Error: opening file." << std::endl;
		exit(1);
	}

	std::string line;
	std::getline(file, line);

	while (std::getline(file, line)) {
		std::stringstream ss(line);
		std::string dateStr, rateStr;
		
		std::getline(ss, dateStr, ',');
		std::getline(ss, rateStr, ',');

		float rate = std::atof(rateStr.c_str());
		_exchangeRates[dateStr] = rate;
	}

	file.close();
}

bool	BitcoinExchange::isValidDate(const std::string& date) {
	if (date.length() != 10) {
		return false;
	}
	if (date[4] != '-' || date[7] != '-') {
		return false;
	}
	for (int i = 0; i < 10; ++i) {
		if (i != 4 && i != 7 && !isdigit(date[i])) {
			return false;
		}
	}
	int year = atoi(date.substr(0, 4).c_str());
	int month = atoi(date.substr(5, 2).c_str());
	int day = atoi(date.substr(8, 2).c_str());
	if (year < 2008 || year > 2024 || month < 1 || month > 12 || day < 1 || day > 31) {
		return false;
	}
	if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) {
		return false;
	}
	if (month == 2) {
		if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0 && year % 100 == 0)) {
			if (day > 29) {
				return false;
			}
		} else {
			if (day > 28) {
				return false;
			}
		}
	}
	return true;
}

float	BitcoinExchange::isValidValue(const std::string& valueStr) {
	try {
		float value = std::stof(valueStr);
		if (value <= 0) {
			std::cerr << "Error: not a positive number: " << value << std::endl;
			return -1;
		} else if (value > 1000) {
			std::cerr << "Error: too large a number: " << value << std::endl;
			return -1;
		}
		return value;
	} catch (std::exception& e) {
		std::cerr << "Error: " << e.what() << " Bad input: " << valueStr << std::endl;
	}
	return -1;
}

void	BitcoinExchange::searchValue(const std::string& dateStr, float value) {
	std::map<std::string, float>::iterator it = _exchangeRates.lower_bound(dateStr);
	std::cout << dateStr << " => " << value << " = " << value * it->second << std::endl;
}

void	BitcoinExchange::newInput(char *av) {
	std::string fileName(av);
	if (fileName.length() < 4 || fileName.substr(fileName.length() - 4) != ".txt") {
		std::cerr << "Error: Bad file extension." << std::endl;
		exit(1);
	}
	std::ifstream file(av);
	if (!file.is_open()) {
		std::cerr << "Error: opening file." << std::endl;
		exit(1);
	}

	std::string line;
	std::getline(file, line);
	while (std::getline(file, line)) {
		std::stringstream ss(line);
		std::string dateStr, valueStr;
		
		if (line.find('|') != std::string::npos) {
			std::getline(ss, dateStr, '|');
			std::getline(ss, valueStr, '\n');
			dateStr.erase(remove_if(dateStr.begin(), dateStr.end(), isspace), dateStr.end());
			valueStr.erase(remove_if(valueStr.begin(), valueStr.end(), isspace), valueStr.end());
			// std::cout << "Ligne: " << line << std::endl;
			// std::cout << "Data:" << dateStr << " " << valueStr << std::endl;
			float value;
			if (isValidDate(dateStr) && (value = isValidValue(valueStr)) > 0) {
				searchValue(dateStr, value);
			}
		} else {
			std::cerr << "Error: bad input => " << line << std::endl;
		}
	}
}

/*-----------Display--------------*/
void	BitcoinExchange::displayData(void) {
	for (std::map<std::string, float>::iterator it = _exchangeRates.begin(); it != _exchangeRates.end(); it++) {
		std::cout << it->first << "," << it->second << std::endl;
	}
}
