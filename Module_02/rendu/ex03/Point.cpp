/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 02:23:16 by yzaoui            #+#    #+#             */
/*   Updated: 2024/04/07 14:51:54 by yzaoui           ###   ########.fr       */
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
	// std::cout << "this->_x.toInt() = " << this->_x.toInt() << std::endl;
	// std::cout << "rf.getX().toInt() = " << rf.getX().toInt() << std::endl;
	// std::cout << std::endl;

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
	std::cout << " | this->_y = " << this->_y << std::endl;
}