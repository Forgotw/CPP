/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsohler <lsohler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 17:32:52 by lsohler           #+#    #+#             */
/*   Updated: 2024/01/15 17:26:22 by lsohler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"


int main( void ) {
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << "a     " << a << std::endl;
	std::cout << "++a   " << ++a << std::endl;
	std::cout << "a     " << a << std::endl;
	std::cout << "a++   " << a++ << std::endl;
	std::cout << "a     " << a << std::endl << std::endl;

	std::cout << "b     " << b << std::endl;
	std::cout << "maxab " << Fixed::max( a, b ) << std::endl << std::endl;

	Fixed c = b + a;
	std::cout << "Fixed c = b + a;" << std::endl;
	std::cout << "a     " << a << std::endl;
	std::cout << "b     " << b << std::endl;
	std::cout << "a + b " << a + b << std::endl;
	std::cout << "c     " << c << std::endl << std::endl;

	std::cout << "a = " << a << " | b = " << b << std::endl;
	std::cout << "bool a < b:  " << (a < b) << std::endl;
	std::cout << "bool a <= b:  " << (a <= b) << std::endl;
	std::cout << "bool a > b:  " << (a > b) << std::endl;
	std::cout << "bool a >= b:  " << (a >= b) << std::endl;
	std::cout << "bool a == (c = a): " << (a == (c = a)) << std::endl;
	std::cout << "bool a*10 000 > b: " << (a * 10000 > b) << std::endl << std::endl;

	std::cout << "b.toInt(): " << b.toInt() << std::endl;
	std::cout << "a.toInt(): " << a.toInt() << std::endl;
	std::cout << "a(int) < b(int):    " << (a.toInt() < b.toInt()) << std::endl << std::endl;

	if (a < b) {
		std::cout << "a(" << a << ")(" << a.toInt() << ")"
			<< " est plus petit que "
			<< "b(" << b << ")(" << b.toInt() << ")"
			<< std::endl << std::endl;
	}
	Fixed d(b.toInt() / 10);
	a = a.toInt() + 1;
	std::cout << "Fixed d(b.toInt() / 10);" << std::endl;
	std::cout << "d = " << d << std::endl;
	std::cout << "a = a.toInt() + 1 " << std::endl;
	std::cout << "a = " << a << std::endl;
	std::cout << "a(float) = " << a.toFloat() << std::endl;
	std::cout << "b(float) = " << a.toFloat() << std::endl << std::endl;

	Fixed	e(0.0f);
	// a / e;
	std::cout << "a / e = " << a / e << std::endl;
	std::cout << "e++ = " << e++ << std::endl;
	std::cout << "a / e = " << a / e << std::endl;
	std::cout << "a / --e = "<< a / --e << std::endl << std::endl;

	Fixed	f(2.25f);
	Fixed	y(6.78f);
	std::cout << "Fixed	f(2.25f);" << std::endl;
	std::cout << "Fixed	pow(6.78f);" << std::endl;
	std::cout << "f(int) = " << f.toInt() << std::endl;
	std::cout << "f(float) = " << f << std::endl;
	std::cout << "y(int) = " << y.toInt() << std::endl;
	std::cout << "y(float) = " << y.toFloat() << std::endl;
	std::cout << "f^y = " << (f^y) << std::endl;
	std::cout << "f.pow(y)" << f.pow(y) << std::endl << std::endl;

	Fixed	h = 8388607;
	std::cout << "Fixed	h = 8388607;" << std::endl;
	std::cout << "h(int) = " << h.toInt() << std::endl;
	std::cout << "h(float) = " << h.toFloat() << "\n\n";

	h = 42;
	std::cout << "h = 42" << std::endl;
	std::cout << "-h =   " << -h << std::endl;
	std::cout << "Fixed(0) - h = " << Fixed(0) - h << std::endl;
	return 0;
}
