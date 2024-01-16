/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsohler <lsohler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 17:36:32 by lsohler           #+#    #+#             */
/*   Updated: 2024/01/16 13:04:03 by lsohler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"
#include <cstdio>

/*-----------Constructor / Destructor-----------*/
Point::Point(void) : _x(0), _y(0) {
	// std::cout << "Default constructor called" << std::endl;
}

Point::Point(const Point& copy) : _x(copy._x), _y(copy._y) {
	// std::cout << "Copy constructor called" << std::endl;
}

Point::Point(const float& x, const float& y) : _x(x), _y(y) {
}

Point::~Point(void) {
	// std::cout << "Destructor called" << std::endl;
}

Point& Point::operator=(const Point& affectation) {
	// std::cout << "Copy assignment operator called" << std::endl;
	if (this != &affectation) {
		(Fixed)this->_x = affectation._x;
		(Fixed)this->_y = affectation._y;
	}
	return *this;
}

std::ostream& operator<<(std::ostream& os, const Point& obj) {
	os << "(" << (obj.getX()) << "," << (obj.getY()) << ")";
	return os;
}

Point Point::operator-(const Point& obj) const {
	return Point(Fixed(this->_x - obj._x).toFloat(), Fixed(this->_y - obj._y).toFloat());
}

Point Point::operator-() const {
	return Point((-this->_x).toFloat(),(-this->_y).toFloat());
}

Point Point::operator+(const Point& obj) const {
	return Point(Fixed(this->_x + obj._x).toFloat(), Fixed(this->_y + obj._y).toFloat());
}

Fixed Point::cross(const Point& obj) const {
	return Fixed((this->_x * obj._y) - (this->_y * obj._x));
}

Fixed Point::getX() const {
	return (this->_x);
}

Fixed Point::getY() const {
	return (this->_y);
}

Point Point::normal() const {
	return (Point(_y.toFloat(), -_x.toFloat()));
}

/*
   La fonction prend en paramètre le point et les sommets du triangle.
   Elle calcule l'aire du triangle donné (v1 v2 v3), puis les aires des trois triangles
   (pt v2 v3), (pt v1 v3), et (pt v1 v2). Si la somme de ces trois aires est supérieure
   à celle du premier, alors le point se trouve à l'extérieur du triangle.
*/
Fixed	triangleArea(Point const v1, Point const v2, Point const v3) {
	Fixed det = 0;
	det = ((v1.getX() - v3.getX()) * (v2.getY() - v3.getY())) - ((v2.getX() - v3.getX()) * (v1.getY() - v3.getY()));
	if (det < 0)
		det = -det;
	return (det / 2);
}

Fixed	sign(Point const v1, Point const v2, Point const v3) {
	return ((v1.getX() - v3.getX()) * (v2.getY() - v3.getY())) - ((v2.getX() - v3.getX()) * (v1.getY() - v3.getY()));
}

bool bsp( Point const a, Point const b, Point const c, Point const point) {
//	Point ab = b - a;
//	Point ac = c - a;
//	Point normal = ab.normal();

//	Point pa = a - point;
//	Point pb = b - point;
//	Point pc = c - point;
//

//	Fixed abpa = ab.cross(pa);
//	Fixed bcpb = ac.cross(pb);
//	Fixed capc = ab.cross(pc);
//	Fixed x = normal.getX();
//	Fixed y = normal.getY();
//

//	Fixed abpax = abpa * x;
//	Fixed abpay = abpa * y;
//	Fixed bcpbx = bcpb * x;
//	Fixed bcpby = bcpb * y;
//	Fixed capcx = capc * x;
//	Fixed capcy = capc * y;
//
//	if ((abpax + bcpbx + capcx >= 0) && (abpay + bcpby + capcy >= 0))
//		return true;
//	return false;
//	Fixed total = triangleArea(a, b, c);
	Fixed d1, d2, d3;
	bool has_neg, has_pos;

	d1 = sign(point, a, b);
	d2 = sign(point, b, c);
	d3 = sign(point, c, a);

	has_neg = (d1 < 0) || (d2 < 0) || (d3 < 0);
	has_pos = (d1 > 0) || (d2 > 0) || (d3 > 0);

	return !(has_neg && has_pos);

//	Fixed total = triangleArea(a, b, c);
//	Fixed pba = triangleArea(point, b, a);
//	Fixed pbc = triangleArea(point, b, c);
//	Fixed pac = triangleArea(point, c, a);
//
//	std::cout << "total: " << total << std::endl;
//	std::cout << "pba: " << pba << std::endl;
//	std::cout << "pbc: " << pbc << std::endl;
//	std::cout << "pac: " << pac << std::endl;
//	std::cout << "total calc: " << pba + pbc + pac << std::endl;
//
//	if (pba + pbc + pac > total)
//		return false;
//	else
//		return true;
}

/*
   Les coordonnées barycentriques (u, v, w) d'un point P par rapport à un triangle ABC sont définies comme suit :
   
   P = uA + vB + wC

   où u, v, w ≥ 0 et u + v + w = 1. Si u, v, w satisfont ces conditions, alors le point P est à l'intérieur du triangle ABC.

   Formule pour calculer les coordonnées barycentriques d'un point P(x, y) par rapport à un triangle ABC avec des sommets A(xA, yA), B(xB, yB) et C(xC, yC) :

   u = ((yB - yC)(x - xC) + (xC - xB)(y - yC)) / ((yB - yC)(xA - xC) + (xC - xB)(yA - yC))
   v = ((yC - yA)(x - xC) + (xA - xC)(y - yC)) / ((yB - yC)(xA - xC) + (xC - xB)(yA - yC))
   w = 1 - u - v

   Si u, v, w ≥ 0 et u + v + w = 1, alors le point P est à l'intérieur du triangle ABC.

   Notez que cette formule suppose que les points A, B, C et P sont définis dans un plan cartésien.

   Auteur : Votre Nom
   Date : Date de création
*/
//bool barycentrique(Point const a, Point const b, Point const c, Point const point)
