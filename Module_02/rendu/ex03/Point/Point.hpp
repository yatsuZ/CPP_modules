/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 02:24:23 by yzaoui            #+#    #+#             */
/*   Updated: 2024/04/08 18:50:31 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

#include "./../Fixed/Fixed.hpp"

class Point
{
private:
	Fixed	_x;
	Fixed	_y;
public:
	// |-- Constructeur
	Point(void);
	Point(Point const & src);
	Point(const float x, const float y);
	Point(const Fixed x, const Fixed y);

	Point(int dimension);
	// |-- Destructeur
	~Point();

	// |-- Comparaison + operator

	Point	&operator=(Point const & rf);
	bool	operator==(Point const & rf);
	bool	close(Point const & rf) const;

	// |--- Geteur

	Point	get(void) const;
	Fixed	getX(void) const;
	Fixed	getY(void) const;

	// |--- Seteur

	void	set(const Fixed &newX, const Fixed &newY);
	void	setX(Fixed newx);
	void	setY(Fixed newy);

	// |--- Affichage

	void	show(void) const;

	// |--- Calcule du determinant

	static Fixed	det(Point const &p1, Point const &p2, Point const &p3);
};

bool	bsp( Point const a, Point const b, Point const c, Point const point);
void	showBsp(int dimension, Point const newA, Point const newB, Point const newC, Point const newP);
void	drawTriangle(int dimension, Point const a, Point const b, Point const c);

// |--- Affichage
std::ostream & operator<<( std::ostream & o, Point const & rf);

#endif