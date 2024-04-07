/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 02:33:08 by yzaoui            #+#    #+#             */
/*   Updated: 2024/04/07 15:15:49 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	(void) a;
	(void) b;
	(void) c;
	(void) point;

	return (true);
}

void	draw(int newDimension, Point index, Point newA, Point newB, Point newC, Point newP)
{
	(void) newA;
	(void) newB;
	(void) newC;
	(void) newP;
	int	x = index.getX().toInt();
	int	y = index.getY().toInt();

	if (x == 0)
		std::cout << y;
	else if (y == newDimension - 1)
		std::cout << x;
	if (y == newDimension && x == 0)
		std::cout << " ";
	// else if (index.close(newP))
	// 	std::cout << "P";
	// else if (index.close(newA) || index.close(newB) || index.close(newC))
	// 	std::cout << "X";
	else
		std::cout << " ";
}

//Mets a lecher de 10x10 character et place les 3 points
void	showBsp( Point const a, Point const b, Point const c, Point const point)
{
	int	newDimension = 10;
	Point newA = a.echelle(newDimension);
	Point newB = b.echelle(newDimension);
	Point newC = c.echelle(newDimension);
	Point newP = point.echelle(newDimension);
	(void) point;
	Point index;

	for (int y = newDimension - 1; y >= 0; y--)
	{
		index.setY(y);
		for (int x = 0; x < newDimension; x++)
		{
			index.setX(x);
			// index.show();
			draw(newDimension, index, newA, newB, newC, newP);
		}
		std::cout << std::endl;
	}
	// newA.show();
	// newB.show();
	// newC.show();
	// newP.show();
}
