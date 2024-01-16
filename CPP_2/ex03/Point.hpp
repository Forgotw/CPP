/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsohler <lsohler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 17:36:42 by lsohler           #+#    #+#             */
/*   Updated: 2024/01/15 18:49:01 by lsohler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class Point {

public:

	Point(void);
	Point(const Point& copy);
	Point(const float& x, const float& y);
	Point& operator=(const Point& assignation);
	~Point(void);

	Fixed	cross(const Point& obj) const;
	Point	operator+(const Point& obj) const;
	Point	operator-(const Point& obj) const;
	Point	operator-() const;
	Point	normal() const;
	Fixed	getX() const;
	Fixed	getY() const;
	
private:

	const Fixed	_x;
	const Fixed	_y;
	
};

std::ostream& operator<<(std::ostream& os, const Point& obj) ;

Fixed	triangleArea(Point const v1, Point const v2, Point const v3);
bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif

