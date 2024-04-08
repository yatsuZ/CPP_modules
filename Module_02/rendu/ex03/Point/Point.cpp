/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 02:23:16 by yzaoui            #+#    #+#             */
/*   Updated: 2024/04/08 19:46:39 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

//////// |--Constructeur

Point::Point(void): _x(0), _y(0)
{
}
Point::Point(Point const & src)
{
	*this = src;
}
Point::Point(const float x, const float y): _x(x), _y(y)
{
}
Point::Point(const Fixed x, const Fixed y): _x(x), _y(y)
{
}

Fixed get_input_Fixed(std::string msg)
{
	float	input;
	std::string	yellow = "\033[33m";
	std::string	no_color = "\033[0m";

	std::cout << yellow << msg << no_color;
	
	std::cin >> input;
	std::cout << no_color;
	return (input);
}

Point::Point(int dimension)
{
	dimension = abs(dimension);
	
	dimension = (dimension > 100)? 100 : dimension;

	std::cout << MAGENTA << "min 0, max " << dimension << ", you can put a Float" << NOCOLOR << std::endl;
	this->_x = get_input_Fixed("X= ");
	if (this->_x < 0 || this->_x > dimension)
	{
		std::cout << RED << "RETRY!!" << std::endl << MAGENTA << "min 0, max " << dimension << ", you can put a Float" << NOCOLOR << std::endl;
		this->_x = get_input_Fixed("X= ");
	}
	std::cout << MAGENTA << "min 0, max " << dimension << ", you can put a Float" << NOCOLOR << std::endl;
	this->_y = get_input_Fixed("Y= ");
	if (this->_y < 0 || this->_y > dimension)
	{
		std::cout << RED << "RETRY!!" << std::endl << MAGENTA << "min 0, max " << dimension << ", you can put a Float" << NOCOLOR << std::endl;
		this->_y = get_input_Fixed("Y= ");
	}
}

//////// |--- Destructeur

Point::~Point()
{
}

//////// |--- Comparaison

// Operrateur

Point	&Point::operator=(Point const & rf)
{
	this->_x = rf._x;
	this->_y = rf._y;
	return (*this);
}
bool	Point::operator==(Point const & rf)
{
	return (this->_x == rf.getX() && this->_y == rf.getY());
}

bool	Point::close(Point const & rf) const
{
	if (this->getX() == rf.getX() && this->_y == rf.getY())
		return (true);
	return (this->_x.toInt() == rf.getX().toInt() && this->_y.toInt() == rf.getY().toInt());
}

//////// |--- Geteur

Point	Point::get(void)const
{
	return (*this);
}

Fixed	Point::getX(void)const
{
	return (this->_x);
}

Fixed	Point::getY(void)const
{
	return (this->_y);
}

//////// |--- Seteur

void	Point::set(const Fixed &newX, const Fixed &newY)
{
	this->_x = newX;
	this->_y = newY;
}

void	Point::setX(Fixed newX)
{
	this->_x = newX;
}

void	Point::setY(Fixed newY)
{
	this->_y = newY;
}

//////// |--- Affichage

void	Point::show(void) const
{
	std::cout << "this->_x = " << this->_x;
	std::cout << "\t| this->_y = " << this->_y << std::endl;
}

std::ostream & operator<<( std::ostream & o, Point const & rf)
{
	o << "(" << rf.getX() << ", " << rf.getY() << ")";
	return o;

}

// IMPORTANT CALCULE
// determinant permet [.. explication]
Fixed	Point::det(Point const &a, Point const &b, Point const &c)
{
	Fixed	acX = (a.getX() - c.getX());
	Fixed	bcY = (b.getY() - c.getY());
	Fixed	bcX = (b.getX() - c.getX());
	Fixed	acY = (a.getY() - c.getY());

	return ((acX * bcY) - (bcX * acY));
}
