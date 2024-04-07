/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 15:27:32 by yzaoui            #+#    #+#             */
/*   Updated: 2024/04/07 02:20:58 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Fixed.hpp"
#include <limits>
void afficherEnBinaire(int nombre) 
{
	int tailleEnBits = sizeof(int) * 8;

	for (int i = tailleEnBits - 1; i >= 0; --i) {
		int bit = (nombre >> i) & 1;
		std::cout << bit;
	}
	std::cout << std::endl;
}

void afficherEnBinaire(Fixed nombre) 
{
	afficherEnBinaire(nombre.getRawBits());
}

int	main( void ) {
	Fixed	a;
	Fixed const b(__FLT_MAX__);
	Fixed const c(-42.42f);
	Fixed const d( b );

	a = Fixed( 1234.4321f );

	std::cout << "a is\t" << a << std::endl;
	std::cout << "b is\t" << b << std::endl;
	std::cout << "c is\t" << c << std::endl;
	std::cout << "d is\t" << d << std::endl;

	std::cout << "|-----------------------------------------|" << std::endl;

	std::cout << "a is " << a.toInt() << "\tas integer" << std::endl;
	std::cout << "b is " << b.toInt() << " \tas integer" << std::endl;
	std::cout << "c is " << c.toInt() << " \tas integer" << std::endl;
	std::cout << "d is " << d.toInt() << " \tas integer" << std::endl;

	std::cout << "|-----------------------------------------|" << std::endl;


	std::cout << "a is " << a.toFloat() << "\tas floater" << std::endl;
	std::cout << "b is " << b.toFloat() << " \t\tas floater" << std::endl;
	std::cout << "c is " << c.toFloat() << "\t\tas floater" << std::endl;
	std::cout << "d is " << d.toFloat() << " \t\tas floater" << std::endl;

	std::cout << "|-----------------------------------------|" << std::endl;

	afficherEnBinaire(c);
	afficherEnBinaire(c.toInt());
	afficherEnBinaire(c);
	afficherEnBinaire(c.toFloat());
	afficherEnBinaire(c);
	afficherEnBinaire(-2147483647);

	return 0;
}
