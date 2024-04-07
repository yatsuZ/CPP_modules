/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 02:23:16 by yzaoui            #+#    #+#             */
/*   Updated: 2024/04/07 02:31:14 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Point.hpp"

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
}

Point::~Point()
{
}

Point::Point(const float x, const float y): _x(x), _y(y)
{
}
