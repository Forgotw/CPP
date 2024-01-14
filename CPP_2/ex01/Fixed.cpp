/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsohler <lsohler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 17:32:19 by lsohler           #+#    #+#             */
/*   Updated: 2024/01/14 19:50:27 by lsohler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/*-----------Constructor / Destructor-----------*/
Fixed::Fixed(void) {
	this->_Value = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& copy) {
	std::cout << "Copy constructor called" << std::endl;
	this->setRawBits(copy.getRawBits());
}

Fixed& Fixed::operator=(const Fixed& affectation) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &affectation) {
		this->_Value = affectation.getRawBits();
	}
	return *this;
}

Fixed::Fixed(const int n) {
	this->_Value = (n << this->_Bits);
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float f) {
	this->_Value = std::roundf(f * (1 << this->_Bits));
	std::cout << "Float constructor called" << std::endl;
}

Fixed::~Fixed(void) {
	std::cout << "Destructor called" << std::endl;
}
/*------------------------------------------------*/

/*-----------------Class Functions----------------*/
int	Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return this->_Value;
}

void	Fixed::setRawBits(int const raw) {
	this->_Value = raw;
}

int	Fixed::toInt(void) const {
	return (_Value >> _Bits);
}

float	Fixed::toFloat(void) const {
	return static_cast<float>(_Value) / (1 << _Bits);
}
/*------------------------------------------------*/

/*------------------------------------------------*/
/*------------------Operators---------------------*/
/*------------------------------------------------*/

/*---Stream Operators------*/
std::ostream& operator<<(std::ostream& os, const Fixed& obj) {
	os << obj.toFloat();
	return os;
}
/*------------------------------------------------*/
