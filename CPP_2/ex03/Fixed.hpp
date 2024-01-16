/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsohler <lsohler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 17:31:31 by lsohler           #+#    #+#             */
/*   Updated: 2024/01/15 17:22:20 by lsohler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <string>
#include <cmath>

class Fixed {

public:

	Fixed(void);
	Fixed(const Fixed& copy);
	Fixed& operator=(const Fixed& assignation);
	Fixed(const int n);
	Fixed(const float f);
	~Fixed(void);
	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	int		toInt(void) const;
	float	toFloat(void) const;
	Fixed	pow(const Fixed& obj) const;

/*---Iterations Operators--*/
// Ces opérateurs sont définis de manière à diminuer la valeur du nombre à virgule fixe d'une
// unité infiniment petite, souvent notée comme ϵ (epsilon), telle que 1 + ϵ est toujours supérieur à 1.
	Fixed&	operator++(); // Opérateur de pré-incrémentation (++x)
	Fixed	operator++(int); // Opérateur de post-incrémentation (x++)
	Fixed&	operator--(); // Opérateur de pré-décrémentation (--x)
	Fixed	operator--(int); // Opérateur de post-décrémentation (x--)

/*---Operations Operators--*/
	Fixed	operator-(const Fixed& obj) const;
	Fixed	operator+(const Fixed& obj) const;
	Fixed	operator*(const Fixed& obj) const;
	Fixed	operator/(const Fixed& obj) const;
	Fixed	operator^(const Fixed& obj) const;

	Fixed	operator-() const;

/*---Comparison Operators--*/
	bool	operator>(const Fixed& obj) const;
	bool	operator<(const Fixed& obj) const;
	bool	operator>=(const Fixed& obj) const;
	bool	operator<=(const Fixed& obj) const;
	bool	operator==(const Fixed& obj) const;
	bool	operator!=(const Fixed& obj) const;
/*---MIN MAX---*/
static Fixed&		min(Fixed& a, Fixed& b);
static const Fixed&	min(const Fixed& a, const Fixed& b);
static Fixed&		max(Fixed& a, Fixed& b);
static const Fixed&	max(const Fixed& a, const Fixed& b);

private:
	int					_Value;
	static const int	_Bits = 8;

};
/*---Stream Operators------*/
std::ostream& operator<<(std::ostream& os, const Fixed& obj) ;

#endif
