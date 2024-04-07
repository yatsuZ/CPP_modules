/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 02:24:23 by yzaoui            #+#    #+#             */
/*   Updated: 2024/04/07 14:48:56 by yzaoui           ###   ########.fr       */
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
	Point	echelle(int newDimension) const;
	Point	echelle(float newDimensionX, float newDimensionY) const;

	Fixed	getX(void) const;
	Fixed	getY(void) const;

	void	setX(Fixed newx);
	void	setY(Fixed newy);


	bool	operator==(Point const & rf);
	bool	close(Point const & rf) const;

	void	show(void) const;
};

bool	bsp( Point const a, Point const b, Point const c, Point const point);
void	showBsp( Point const a, Point const b, Point const c, Point const point);

#endif