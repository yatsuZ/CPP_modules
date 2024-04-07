/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 02:24:23 by yzaoui            #+#    #+#             */
/*   Updated: 2024/04/07 02:33:41 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

#include "./Fixed.hpp"

class Point
{
private:
	Fixed	_x;
	Fixed	_y;
public:
	Point(void);
	Point(Point const & src);
	Point	&operator=(Point const & rf);
	~Point();

	Point(const float x, const float y);
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif