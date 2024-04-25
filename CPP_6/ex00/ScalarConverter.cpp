/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsohler <lsohler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 13:34:12 by lsohler           #+#    #+#             */
/*   Updated: 2024/02/25 14:36:34 by lsohler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void) {
}

ScalarConverter::~ScalarConverter(void) {
}

std::string floatLookUp[] = {
	"+inff",
	"-inff",
	"nanf"
};

std::string doubleLookUp[] = {
	"+inf",
	"-inf",
	"nan"
};

// static bool	intOverFlow(int d, std::string str) {
// 	if ()
// }

// static bool	floatOverFlow(float f, std::string str) {


// }
// static bool	doubleOverFlow(double lf, std::string str) {

// }
/*
**=================================
**		isValidFunctions
**=================================
*/
static bool isValidChar(char *c, std::string str) {
	if (str.length() == 3 && str[0] == '\'' && str[2] == '\'') {
		*c = str[1];
		return true;
	}
	else if (str.length() == 1 && !std::isdigit(*c)) {
		*c = str[0];
		return true;
	}
	return false;
}

static bool isValidInt(int *d, std::string str) {
	char *endptr;
	long l;

	l = strtol(str.c_str(), &endptr, 10);
	if (*endptr == '\0' && l >= INT_MIN && l <= INT_MAX) {
		*d = l;
		return true;
	}
	return false;
}

static bool isValidFloat(float *f, std::string str) {
	char *endptr;
	double lf;

	lf = strtod(str.c_str(), &endptr);
	if (endptr[0] == 'f' && endptr[1] == '\0'
		&& (lf >= -std::numeric_limits<float>::max() && lf <= std::numeric_limits<float>::max())) {
		*f = static_cast<float>(lf);
		return true;
	}
	return false;
}

static bool isValidDouble(double *lf, std::string str) {
	char *endptr;

	*lf = strtod(str.c_str(), &endptr);
	if (*endptr == '\0')
		return true;
	return false;
}

/*
**=================================
**		edgeCases
**=================================
*/
static bool	edgeFloat(std::string str) {
	for (int i = 0; i < 3; i++) {
		if (str == floatLookUp[i]) {
			std::cout << "EDGE CASE FLOAT" << std::endl;
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: " << str << std::endl;
			std::cout << "double: impossible" << std::endl;
			return 1;
		}
	}
	return 0;
}

static bool	edgeDouble(std::string str) {
	for (int i = 0; i < 3; i++) {
		if (str == doubleLookUp[i]) {
			std::cout << "EDGE CASE DOUBLE" << std::endl;
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: impossible" << std::endl;
			std::cout << "double: " << str << std::endl;
			return 1;
		}
	}
	return 0;
}

/*
**=================================
**		literalConvert
**=================================
*/
static void	literalChar(char c) {
	std::cout << "CHAR LITERAL" << std::endl;
	if (isprint(c))
		std::cout << "char: '" << c << "'" << std::endl;
	else
		std::cout << "char: Non displayble" << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << static_cast<float>(c) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(c) << std::endl;
}

static void	literalFloat(float f) {
	std::cout << "FLOAT LITERAL" << std::endl;
	int	d = static_cast<int>(f);
	if (d >= 0 && d <= 127 && isprint(d))
		std::cout << "char: '" << static_cast<char>(f) << "'" << std::endl;
	else if (d >= 0 && d <= 127)
		std::cout << "char: Non displayble" << std::endl;
	else
		std::cout << "char: Impossible" << std::endl;
	if (f >= std::numeric_limits<int>::min() && f <= std::numeric_limits<int>::max())
		std::cout << "int: " << static_cast<int>(f) << std::endl;
	else
		std::cout << "int: Impossible" << std::endl;
	std::cout << "float: " << f << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(f) << std::endl;
}

static void	literalDouble(double lf) {
	std::cout << "DOUBLE LITERAL" << std::endl;
	int	d = static_cast<int>(lf);
	if (d >= 0 && d <= 127 && isprint(d))
		std::cout << "char: '" << static_cast<char>(lf) << "'" << std::endl;
	else if (d >= 0 && d <= 127)
		std::cout << "char: Non displayble" << std::endl;
	else
		std::cout << "char: Impossible" << std::endl;
	if (lf >= std::numeric_limits<int>::min() && lf <= std::numeric_limits<int>::max())
		std::cout << "int: " << static_cast<int>(lf) << std::endl;
	else
		std::cout << "int: Impossible(Overflow)" << std::endl;
	if (lf >= -std::numeric_limits<float>::max() && lf <= std::numeric_limits<float>::max())
		std::cout << "float: " << static_cast<float>(lf) << "f" << std::endl;
	else
		std::cout << "float: Impossible(Overflow)" << std::endl;
	std::cout << "double: " << lf << std::endl;
}

static void	literalInt(int d) {
	std::cout << "INT LITERAL" << std::endl;
	if (d >= 0 && d <= 127 && isprint(d))
		std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;
	else if (d >= 0 && d <= 127)
		std::cout << "char: Non displayble" << std::endl;
	else
		std::cout << "char: Impossible" << std::endl;
	std::cout << "int: " << d << std::endl;
	std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(d) << std::endl;
}

/*
**=================================
**		Converter
**=================================
*/
void	ScalarConverter::converter(const std::string &str) {
	char	c;
	int		d;
	float	f;
	double	lf;

	std::cout << std::fixed << std::setprecision(2);
	if (isValidChar(&c, str))
		literalChar(c);
	else if (isValidInt(&d, str))
		literalInt(d);
	else if (isValidFloat(&f, str))
		literalFloat(f);
	else if (isValidDouble(&lf, str))
		literalDouble(lf);
	else if (edgeFloat(str) || edgeDouble(str)){
	}
	else
		throw "No conversion possible for: " + str;
}

// void	ScalarConverter::converter(const std::string& str) {
// 	char	c;
// 	int		d;
// 	float	f;
// 	double	lf;

// 	std::cout << std::fixed << std::setprecision(10);
// 	if (str.length() == 3
// 			&& str[0] == '\''
// 			&& str[2] == '\'') {
// 		c = str[1];
// 		literalChar(c);
// 	}
// 	else if (std::sscanf(str.c_str(), "%f", &f) == 1 
// 				&& str.length() >= 3
// 				&& str.find(".") != std::string::npos 
// 				&& str.find("f") != std::string::npos) {
// 		literalFloat(f);
// 	}
// 	else if (std::sscanf(str.c_str(), "%lf", &lf) == 1
// 				&& str.length() >= 3
// 				&& str.find(".") != std::string::npos) {
// 		literalDouble(lf);
// 	}
// 	else if (std::sscanf(str.c_str(), "%d", &d) == 1) {
// 		literalInt(d);
// 	}
// 	else {
// 		edgeFloat(str) || edgeDouble(str);
// 	}
// }

// void	ScalarConverter::converter(const std::string& str) {
// 	char	c;
// 	int		d;
// 	float	f;
// 	double	lf;
// 	std::istringstream iss(str);

// 	std::cout << std::fixed << std::setprecision(5);
// 	if (str.length() == 3
// 			&& str[0] == '\''
// 			&& str[2] == '\'') {
// 		c = str[1];
// 		literalChar(c);
// 	}
// 	else if (!(iss >> f).fail()) {
// 		literalFloat(f);
// 	}
// 	else if (!(iss >> lf).fail()) {
// 		literalDouble(lf);
// 	}
// 	else if (!(iss >> d).fail()) {
// 		literalInt(d);
// 	}
// 	else {
// 		edgeFloat(str) || edgeDouble(str);
// 	}
// }
