/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 15:27:32 by yzaoui            #+#    #+#             */
/*   Updated: 2024/04/08 19:56:33 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Point/Point.hpp"

void	testBSP(Point a, Point b, Point c, Point p)
{
	std::cout << "------------" << std::endl;
	std::cout << "A = " << a << std::endl;
	std::cout << "B = " << b << std::endl;
	std::cout << "C = " << c << std::endl;
	std::cout << "P = " << p << std::endl;
	std::cout << "------------" << std::endl;
	if (bsp(a, b, c, p))
		std::cout << BLUE << "Le point P est dans l'aire du triangle." << NOCOLOR << std::endl;
	else
		std::cout << MAGENTA << "Le point P N'est PAS dans l'aire du triangle." << NOCOLOR << std::endl;
}

int	main(int argc, char **argv)
{
	if (argc == 1)
	{
		Point	a(-3.51, 5.48), b(3.89, -0.54), c(-3.87, -3.2), p1(1.27, 1.34), p2(1.81,1.42);
		testBSP(a, b, c, p1);
		testBSP(a, b, c, p2);
		return 0;
	}
	int	Dimension = atoi(argv[1]);
	Point	a(Dimension), b(Dimension), c(Dimension);
	// Point	a(0, 0), b(10, 10), c(0, 5);

	drawTriangle(Dimension, a, b, c);
	std::cout << "------------" << std::endl;
	std::cout << "A = " << a << std::endl;
	std::cout << "B = " << b << std::endl;
	std::cout << "C = " << c << std::endl;
	std::cout << "------------" << std::endl;

	return 0;
}


