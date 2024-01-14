/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsohler <lsohler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 17:31:31 by lsohler           #+#    #+#             */
/*   Updated: 2024/01/14 18:17:50 by lsohler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <string>

class Fixed {

public:

	Fixed(void);
	Fixed(const Fixed& copy);
	Fixed& operator=(const Fixed& assignation);
	~Fixed(void);
	int		getRawBits(void) const;
	void	setRawBits(int const raw);

private:
	int					_Int;
	static const int	_IntConstStatic = 8;

};


#endif
