/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsohler <lsohler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 17:32:19 by lsohler           #+#    #+#             */
/*   Updated: 2024/01/15 17:22:40 by lsohler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/*-----------Constructor / Destructor-----------*/
Fixed::Fixed(void) {
	this->_Value = 0;
	// std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& copy) {
	// std::cout << "Copy constructor called" << std::endl;
	this->setRawBits(copy.getRawBits());
}

Fixed& Fixed::operator=(const Fixed& affectation) {
	// std::cout << "Copy assignment operator called" << std::endl;
	if (this != &affectation) {
		this->_Value = affectation.getRawBits();
	}
	return *this;
}

Fixed::Fixed(const int n) {
	this->_Value = (n << this->_Bits);
	// std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float f) {
	this->_Value = std::roundf(f * (1 << this->_Bits));
	// std::cout << "Float constructor called" << std::endl;
}

Fixed::~Fixed(void) {
	// std::cout << "Destructor called" << std::endl;
}
/*------------------------------------------------*/

/*-----------------Class Functions----------------*/
int	Fixed::getRawBits(void) const {
	// std::cout << "getRawBits member function called" << std::endl;
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
/*-------------------------*/

/*---Comparison Operators--*/
bool Fixed::operator>(const Fixed& obj) const {
	return (this->_Value > obj.getRawBits());
}

bool Fixed::operator<(const Fixed& obj) const {
	return (this->_Value < obj.getRawBits());
	// (void)obj;
	// return (0);
}

bool Fixed::operator>=(const Fixed& obj) const {
	return (this->_Value >= obj.getRawBits());
}

bool Fixed::operator<=(const Fixed& obj) const {
	return (this->_Value <= obj.getRawBits());
}

bool Fixed::operator==(const Fixed& obj) const {
	return (this->_Value == obj.getRawBits());
}

bool Fixed::operator!=(const Fixed& obj) const {
	return (this->_Value != obj.getRawBits());
}
/*-------------------------*/

/*---Operations Operators--*/
Fixed Fixed::operator-(const Fixed& obj) const {
	return Fixed(this->toFloat() - obj.toFloat());
}

Fixed Fixed::operator-() const {
	return (Fixed(0) - *this);
}

Fixed Fixed::operator+(const Fixed& obj) const {
	return Fixed(this->toFloat() + obj.toFloat());
}

Fixed Fixed::operator*(const Fixed& obj) const {
	return Fixed(this->toFloat() * obj.toFloat());
}

Fixed Fixed::operator/(const Fixed& obj) const {
	if (obj._Value == 0) {
		std::cout << "THE ANSWER IS 42" << std::endl;
		return Fixed(42);
	}
	return Fixed(this->toFloat() / obj.toFloat());
}

Fixed Fixed::operator^(const Fixed& obj) const {
	if (obj.toInt() == 0)
		return Fixed(1);
	Fixed	temp(this->toFloat());
	Fixed	pow(obj.toInt());
	for (int i = 1; i < obj.toInt(); i++) {
		temp = temp * this->toFloat();
	}
	return (temp);
}

Fixed Fixed::pow(const Fixed& obj) const {
	if (obj.toInt() == 0)
		return Fixed(1);
	Fixed	temp(this->toFloat());
	Fixed	pow(obj.toInt());
	for (int i = 1; i < obj.toInt(); i++) {
		temp = temp * this->toFloat();
	}
	return (temp);
}

/*-------------------------*/

/*---Iterations Operators--*/
Fixed& Fixed::operator++() { // Opérateur de pré-incrémentation (++x)
	++this->_Value;
	return *this;
}

Fixed Fixed::operator++(int) { // Opérateur de post-incrémentation (x++)
	Fixed	temp(*this);
	++this->_Value;
	return temp;
}

Fixed& Fixed::operator--() { // Opérateur de pré-décrémentation (--x)
	--this->_Value;
	return *this;
}

Fixed Fixed::operator--(int) { // Opérateur de post-décrémentation (x--)
	Fixed	temp(*this);
	--this->_Value;
	return temp;
}
/*-------------------------*/
/*------------------------------------------------*/
/*------------------MAX MIN-----------------------*/
	// Fonction membre statique min pour deux références sur des nombres à virgule fixe
Fixed& Fixed::min(Fixed& a, Fixed& b) {
	return (a < b) ? a : b;
}
	// Fonction membre statique min pour deux références sur des nombres à virgule fixe constants
const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
	return (a < b) ? a : b;
}

	// Fonction membre statique max pour deux références sur des nombres à virgule fixe
Fixed& Fixed::max(Fixed& a, Fixed& b) {
	return (a > b) ? a : b;
}

	// Fonction membre statique max pour deux références sur des nombres à virgule fixe constants
const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
	return (a > b) ? a : b;
}
/*------------------------------------------------*/
