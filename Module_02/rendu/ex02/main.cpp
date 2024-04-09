/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 15:27:32 by yzaoui            #+#    #+#             */
/*   Updated: 2024/04/09 15:00:42 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Fixed.hpp"

void afficherEnBinaire(Fixed nombre) {
	int tailleEnBits = sizeof(int) * 8;

	for (int i = tailleEnBits - 1; i >= 0; --i) {
		int bit = (nombre.getRawBits() >> i) & 1;
		std::cout << bit;
	}
	std::cout << std::endl;
}
/*
int	main( void ) {
	Fixed		a(5.05f * 2);
	Fixed		b(2.0f);
	// Fixed const	b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << b << std::endl;
	// std::cout << ++a << std::endl;
	// std::cout << a << std::endl;
	// std::cout << a++ << std::endl;
	// std::cout << a << std::endl;
	// std::cout << b << std::endl;
	// std::cout << Fixed::max( a, b ) << std::endl;

	return 0;
}
*/

int	main(void)
{
	
	Fixed	a(5);
	Fixed	b(10.05f);
	Fixed	c(3);
	Fixed	minus(Fixed( 26 ) - Fixed( 1.5f ));
	Fixed	mult(Fixed( 3 ) * Fixed( 2 ));
	Fixed	divid(Fixed( 42) / Fixed( 2 ));
	Fixed	plus(Fixed( 5.05f ) + Fixed( 2 ));

	std::cout << MAGENTA << "Valleur de depart: " << NOCOLOR << std::endl;

	std::cout << "a = " << a << std::endl;
	std::cout << "b = " << b << std::endl;
	std::cout << "c = " << c << std::endl;
	std::cout << "minus = " << minus << std::endl;
	std::cout << "mult = " << mult << std::endl;
	std::cout << "divid = " << divid << std::endl;
	std::cout << "plus = " << plus << std::endl;

	std::cout << std::endl;

	std::cout << MAGENTA << "operateurs de comparaison: " << NOCOLOR << std::endl;
	std::cout << "2 > 5 -> " << ((b > a)? "True" : "False") << std::endl;
	std::cout << "5 > 2 -> " << ((Fixed(a) > Fixed(b))? "True" : "False") << std::endl;
	std::cout << "5 >= 5-> " << ((a >= a)? "True" : "False") << std::endl;
	std::cout << "5 <= 2-> " << ((a <= b)? "True" : "False") << std::endl;

	std::cout << std::endl;
	
	std::cout << MAGENTA << "operateurs arithmetiques: " << NOCOLOR << std::endl;
	std::cout << "    3 * 2 = " << mult << std::endl;
	std::cout << "   42 / 2 = " << divid << std::endl;
	std::cout << "5.05f + 2 = " << plus << std::endl;
	std::cout << "3.02f - 2 = " << minus << std::endl;

	std::cout << std::endl;
	std::cout << MAGENTA << "operateurs incrémentation / décrementation: " << NOCOLOR << std::endl;
	std::cout << YELLOW << "pré incrémentation : " << NOCOLOR << std::endl;
	std::cout << "c=" << c << " | ++c = " << ++c << " | c=" << c << std::endl; 
	std::cout << "c=" << c << " | --c = " << --c << " | c=" << c << std::endl; 

	std::cout << std::endl << YELLOW << "post incrementation : " << NOCOLOR << std::endl;
	std::cout << "c= " << c << " | c++ = " << c++ << " | c= " << c << std::endl; 
	std::cout << "c= " << c << " | c-- = " << c-- << " | c= " << c << std::endl; 

	std::cout << std::endl;
	std::cout << "a(5) != b(2) -> " << (a != b) << std::endl;
	a = b;
	std::cout << "now a=b, a != b ? -> " << (a != b) << std::endl;

	std::cout << std::endl << RED << "BONNUS heheh, OPERATION EFFECTRUER : " << NOCOLOR << std::endl;

	std::cout << a << " += " << b << " -= " << c << " *= " << minus << " /= " << mult << " = " << plus << std::endl;
	std::cout << std::endl;
	std::cout << "a += b -= c *= minus /= mult = plus" << std::endl;
	a += b -= c *= minus /= mult = plus;
	std::cout << std::endl;
	std::cout << "plus = " << plus << std::endl;
	std::cout << "mult = " << mult << std::endl;
	std::cout << "minus = " << minus << std::endl;
	std::cout << "c = " << c << std::endl;
	std::cout << "b = " << b << std::endl;
	std::cout << "a = " << a << std::endl;
	std::cout << std::endl;
	std::cout << "-a = " << -a << std::endl;

}
