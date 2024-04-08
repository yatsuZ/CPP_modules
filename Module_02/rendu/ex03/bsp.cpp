/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 02:33:08 by yzaoui            #+#    #+#             */
/*   Updated: 2024/04/08 01:55:55 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	std::cout << "------------" << std::endl;
	std::cout << "A = " << a << std::endl;
	std::cout << "B = " << b << std::endl;
	std::cout << "C = " << c << std::endl;
	std::cout << "P = " << point << std::endl;
	std::cout << "------------" << std::endl;

	// // Vecteur du triangle
	// Point	AB = a - b;
	// Point	BC = b - c;
	// Point	CA = c - a;

	// std::cout << "AB = " << AB << std::endl;
	// std::cout << "BC = " << BC << std::endl;
	// std::cout << "CA = " << CA << std::endl;
	// std::cout << "------------" << std::endl;

	// // Vecteur de Pavec les poitns du triangle
	// Point	AP = a - point;
	// Point	BP = b - point;
	// Point	CP = c - point;

	// std::cout << "AP = " << AP << std::endl;
	// std::cout << "BP = " << BP << std::endl;
	// std::cout << "CP = " << CP << std::endl;
	// std::cout << "------------" << std::endl;

	// // Produit des vecteur
	// Fixed vecteur_abp = AB.produitScalaire(AP);
	// Fixed vecteur_bcp = BC.produitScalaire(BP);
	// Fixed vecteur_cap = CA.produitScalaire(CP);

	// std::cout << "vecteur_abp = " << vecteur_abp << std::endl;
	// std::cout << "vecteur_bcp = " << vecteur_bcp << std::endl;
	// std::cout << "vecteur_cap = " << vecteur_cap << std::endl;
	// std::cout << "------------" << std::endl;

	Fixed vecteur_abp = a.sign(point, a, b);
	Fixed vecteur_bcp = b.sign(point, b, c);
	Fixed vecteur_cap = c.sign(point, c, a);

	std::cout << "vecteur_abp = " << vecteur_abp << std::endl;
	std::cout << "vecteur_bcp = " << vecteur_bcp << std::endl;
	std::cout << "vecteur_cap = " << vecteur_cap << std::endl;
	std::cout << "------------" << std::endl;


	if (vecteur_abp >= 0 && vecteur_bcp >= 0 && vecteur_cap >= 0)
		return (true);
	else if (vecteur_abp <= 0 && vecteur_bcp <= 0 && vecteur_cap <= 0)
		return (true);
	return (false);
}

void	draw(int newDimension, Point index, Point newA, Point newB, Point newC, Point newP)
{
	(void) newDimension;
	(void) newA;
	(void) newB;
	(void) newC;
	(void) newP;
	int	x = index.getX().toInt();
	int	y = index.getY().toInt();

	if (x == 0)
		std::cout << y << "|";
	if (index.close(newP))
		std::cout << RED << "P" << NOCOLOR;
	else if (index.close(newA) || index.close(newB) || index.close(newC))
		std::cout << GREEN << "X" << NOCOLOR;
	else
		std::cout << " ";
}

void	showFourPoint(Point const a, Point const b, Point const c, Point const point)
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

//Mets a lechelle de 10x10 positive character et place les 3 points
void	showBsp10x10(Point const newA, Point const newB, Point const newC, Point const newP)
{
	int	newDimension = 10;
	Point index;

	showFourPoint(newA, newB, newC, newP);
	for (int y = newDimension - 1; y >= 0; y--)
	{
		index.setY(y);
		for (int x = 0; x < newDimension; x++)
		{
			index.setX(x);
			draw(newDimension, index, newA, newB, newC, newP);
		}
		std::cout << std::endl;
	}
	std::cout << " L";
	for (int x = 0; x < newDimension; x++)
		std::cout << "_";
	std::cout << std::endl << "  ";
	for (int x = 0; x < newDimension; x++)
		std::cout << x;
	std::cout << std::endl;

}
