/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 02:23:16 by yzaoui            #+#    #+#             */
/*   Updated: 2024/04/08 01:50:57 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void): _x(0), _y(0)
{
}

Point::Point(Point const & src)
{
	*this = src;
}

Point	&Point::operator=(Point const & rf)
{
	this->_x = rf._x;
	this->_y = rf._y;
	return (*this);
}

Point::~Point()
{
}

Point::Point(const float x, const float y): _x(x), _y(y)
{
}
Point::Point(const Fixed x, const Fixed y): _x(x), _y(y)
{
}

Point	Point::echelle(float newDimensionX, float newDimensionY) const
{
	float	newX, newY;

	if (this->_x == 0)
		newX = 0;
	else
		newX = newDimensionX / this->_x.toFloat();
	if (this->_y == 0)
		newY = 0;
	else
		newY = newDimensionY / this->_y.toFloat();

	return (Point(newX, newY));
}

Point	Point::echelle(int newDimension) const
{
	return (this->echelle(newDimension, newDimension));
}

bool	Point::operator==(Point const & rf)
{
	return (this->_x == rf.getX() && this->_y == rf.getY());
}

bool	Point::close(Point const & rf) const
{
	return (this->_x.toInt() == rf.getX().toInt() && this->_y.toInt() == rf.getY().toInt());
}

Fixed	Point::getX(void)const
{
	return (this->_x);
}

Fixed	Point::getY(void)const
{
	return (this->_y);
}

void	Point::setX(Fixed newX)
{
	this->_x = newX;
}

void	Point::setY(Fixed newY)
{
	this->_y = newY;
}

void	Point::show(void) const
{
	std::cout << "this->_x = " << this->_x;
	std::cout << "\t| this->_y = " << this->_y << std::endl;
}

// Produit scalaire permet 
Fixed	Point::produitScalaire(const Point &rf) const
{
	Fixed	x = this->getX() * rf.getX();
	Fixed	y = this->getY() * rf.getY();
	std::cout << std::endl;
	std::cout << this->getX() << " * " << rf.getX() << " = " << x << std::endl;
	std::cout << this->getY() << " * " << rf.getY() << " = " << y << std::endl;
	std::cout << std::endl;
	return (x + y);
}

// Opérateur de soustraction pour obtenir le vecteur entre deux points
// Les cordderne du 2iem point moin le premier
Point	Point::operator-(const Point &rf) const
{
	Fixed	newX = rf.getX() - this->getX();
	Fixed	newY = rf.getY() - this->getY();

	return Point(newX, newY);
}

Fixed	Point::sign(Point const &p1, Point const &p2, Point const &p3)
{
	Fixed	p13X = (p1.getX() - p3.getX());
	Fixed	p23Y = (p2.getY() - p3.getY());
	Fixed	p23X = (p2.getX() - p3.getX());
	Fixed	p13Y = (p1.getY() - p3.getY());

	return ((p13X * p23Y) - (p23X * p13Y));
}

std::ostream & operator<<( std::ostream & o, Point const & rf)
{
	o << "(" << rf.getX() << ", " << rf.getY() << ")";
	return o;

}
