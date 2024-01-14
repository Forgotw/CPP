/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsohler <lsohler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 17:31:31 by lsohler           #+#    #+#             */
/*   Updated: 2024/01/14 19:05:55 by lsohler          ###   ########.fr       */
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

private:
	int					_Value;
	static const int	_Bits = 8;

};

std::ostream& operator<<(std::ostream& os, const Fixed& obj) ;

#endif
