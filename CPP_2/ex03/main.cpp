/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsohler <lsohler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 17:32:52 by lsohler           #+#    #+#             */
/*   Updated: 2024/01/22 11:26:52 by lsohler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <cstdlib>


void	testBSP(Point a, Point b, Point c, Point p) {
	std::cout << "a: " << a << std::endl;
	std::cout << "b: " << b << std::endl;
	std::cout << "c: " << c << std::endl;
	std::cout << "p: " << p << std::endl;
	if (bsp(a, b, c, p) == true) {
		std::cout << "Le point est dans le triangle" << std::endl;
	}
	else
		std::cout << "Le point n'est pas dans le triangle" << std::endl;
}

//https://www.geogebra.org/geometry/ce3k677n

int main() {
	Point	A(-4.1,2.7);
	Point	B(0.8,0.7);
	Point	C(-3.4,-1.1);
	Point	D(-2.1,1.1);
	
	testBSP(A, B, C, D);

	Point	E(4,2);
	Point	F(8,6);
	Point	G(10,0);
	Point	H(8,3);
	Point	I(12,3);
	Point	J(9,3);
	Point	L(6.21,4);

	//P(x,y) = ((Ax + Bx) / 2), ((Ay + By) / 2)

	testBSP(E, F, G, H);
	testBSP(E, F, G, I);
	testBSP(E, F, G, J);
	testBSP(E, F, G, L);

	// Point	a3(-4.1f,2.7f);
	// Point	b3(0.8f,0.7f);
	// Point	c3(-3.4f,-1.1f);
	// Point	p3(-2.1f,1.1f);
	
	// testBSP(b3, a3, c3, p3);

return 0;
}
