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

int main() {
	Point	a(-4.1,2.7);
	Point	b(0.8,0.7);
	Point	c(-3.4,-1.1);
	Point	p(-2.1,1.1);
	
	testBSP(a, b, c, p);

	Point	a2(0,0);
	Point	b2(10,0);
	Point	c2(5,6);
	Point	p2(5,-0.1);
	
	testBSP(a2, b2, c2, p2);

	Point	a3(-4.1f,2.7f);
	Point	b3(0.8f,0.7f);
	Point	c3(-3.4f,-1.1f);
	Point	p3(-2.1f,1.1f);
	
	testBSP(b3, a3, c3, p3);

return 0;
}
