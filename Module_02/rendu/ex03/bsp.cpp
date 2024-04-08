/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 02:33:08 by yzaoui            #+#    #+#             */
/*   Updated: 2024/04/08 19:56:11 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Point/Point.hpp"

///////////////  AFFICHAGE

void	draw01(Point index, Point newA, Point newB, Point newC, Point newP)
{
	int	x = index.getX().toInt();
	int	y = index.getY().toInt();

	if (y < 10 && x == 0)
		std::cout << y << "|";
	else if (x == 0)
		std::cout << " |";
	if (index.close(newP))
		std::cout << RED << "P" << NOCOLOR;
	else if (index.close(newA) || index.close(newB) || index.close(newC))
		std::cout << GREEN << "X" << NOCOLOR;
	else
		std::cout << " ";
}

void	draw02(Point index, Point a, Point b, Point c)
{
	int	x = index.getX().toInt();
	int	y = index.getY().toInt();


	if (y < 10 && x == 0)
		std::cout << y << "|";
	else if (x == 0)
		std::cout << " |";
	if (index.close(a) || index.close(b) || index.close(c))
		std::cout << RED << "O" << NOCOLOR;
	else if (!(a == b && b == c) && bsp(a, b, c, index))
		std::cout << GREEN << "X" << NOCOLOR;
	else
		std::cout << " ";
}

static void	showFourPoint(Point const a, Point const b, Point const c, Point const point)
{
	std::cout << "A = ";
	a.show();
	std::cout << "B = ";
	b.show();
	std::cout << "C = ";
	c.show();
	std::cout << "P = ";
	point.show();
}

static void	putAxeX(int dimension)
{
	std::cout << " L";
	for (int x = 0; x < dimension; x++)
		std::cout << "_";
	std::cout << std::endl << "  ";
	for (int x = 0; x < 10; x++)
		std::cout << x;
	std::cout << std::endl;
}

////////////////////////////////////////////////////////////////////////////////////

// BSP

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	// std::cout << "------------" << std::endl;
	// std::cout << "A = " << a << std::endl;
	// std::cout << "B = " << b << std::endl;
	// std::cout << "C = " << c << std::endl;
	// std::cout << "P = " << point << std::endl;
	// std::cout << "------------" << std::endl;

	Fixed vecteur_abp = a.det(point, a, b);
	Fixed vecteur_bcp = b.det(point, b, c);
	Fixed vecteur_cap = c.det(point, c, a);

	// std::cout << "vecteur_abp = " << vecteur_abp << std::endl;
	// std::cout << "vecteur_bcp = " << vecteur_bcp << std::endl;
	// std::cout << "vecteur_cap = " << vecteur_cap << std::endl;
	// std::cout << "------------" << std::endl;

	if (vecteur_abp >= 0 && vecteur_bcp >= 0 && vecteur_cap >= 0)
		return (true);
	else if (vecteur_abp <= 0 && vecteur_bcp <= 0 && vecteur_cap <= 0)
		return (true);
	return (false);
}

// Fonction sympa ;)

//Mets a lechelle de dimension positive character et place les 3 points
void	showBsp(int dimension, Point const newA, Point const newB, Point const newC, Point const newP)
{
	dimension = abs(dimension);
	Point index;

	showFourPoint(newA, newB, newC, newP);
	for (int y = dimension - 1; y >= 0; y--)
	{
		index.setY(y);
		for (int x = 0; x < dimension; x++)
		{
			index.setX(x);
			draw01(index, newA, newB, newC, newP);
		}
		std::cout << std::endl;
	}
	putAxeX(dimension);
}

void	drawTriangle(int dimension, Point const a, Point const b, Point const c)
{
	dimension = abs(dimension);
	Point index;
	for (int y = dimension - 1; y >= 0; y--)
	{
		index.setY(y);
		for (int x = 0; x < dimension; x++)
		{
			index.setX(x);
			draw02(index, a, b, c);
		}
		std::cout << std::endl;
	}
	putAxeX(dimension);
}
