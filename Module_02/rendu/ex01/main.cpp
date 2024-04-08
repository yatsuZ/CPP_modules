/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 15:27:32 by yzaoui            #+#    #+#             */
/*   Updated: 2024/04/07 21:15:36 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Fixed.hpp"


// UTILE DEBEUG

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

int binaryStringToInt(const std::string& binaryString) {
	int result = 0;
	int exponent = binaryString.size() - 1;

	for (size_t i = 0; i < binaryString.size(); ++i) {
		if (binaryString[i] == '1') {
			if (exponent > 30 && (result > (std::numeric_limits<int>::max() >> 1))) {
				std::cerr << "Débordement positif détecté !" << std::endl;
				return std::numeric_limits<int>::max();
			}
			if (exponent > 30 && (result < (std::numeric_limits<int>::min() >> 1))) {
				std::cerr << "Débordement négatif détecté !" << std::endl;
				return std::numeric_limits<int>::min();
			}
			result += 1 << exponent;
		}
		exponent--;
	}
	return result;
}

////////////////////////

int	main( void ) {
	Fixed	a;
	Fixed const b(__FLT_MAX__);
	Fixed const c(-8388608);
	Fixed const d(8388607);
	Fixed const e( 5.05f );

	a = Fixed( 42.42f );

	std::cout << "a is " << CYAN << a << NOCOLOR << std::endl;
	std::cout << "b is " << CYAN << b << NOCOLOR << std::endl;
	std::cout << "c is " << CYAN << c << NOCOLOR << std::endl;
	std::cout << "d is " << CYAN << d << NOCOLOR << std::endl;
	std::cout << "e is " << CYAN << e << NOCOLOR << std::endl;

	std::cout << "|-----------------------------------------|" << std::endl;

	std::cout << "a is " << CYAN << a.toInt() << NOCOLOR << " as integer" << std::endl;
	std::cout << "b is " << CYAN << b.toInt() << NOCOLOR << " as integer" << std::endl;
	std::cout << "c is " << CYAN << c.toInt() << NOCOLOR << " as integer" << std::endl;
	std::cout << "d is " << CYAN << d.toInt() << NOCOLOR << " as integer" << std::endl;
	std::cout << "e is " << CYAN << e.toInt() << NOCOLOR << " as integer" << std::endl;

	std::cout << "|-----------------------------------------|" << std::endl;


	std::cout << "a is " << CYAN << a.toFloat() << NOCOLOR << " as floater" << std::endl;
	std::cout << "b is " << CYAN << b.toFloat() << NOCOLOR << " as floater" << std::endl;
	std::cout << "c is " << CYAN << c.toFloat() << NOCOLOR << " as floater" << std::endl;
	std::cout << "d is " << CYAN << d.toFloat() << NOCOLOR << " as floater" << std::endl;
	std::cout << "e is " << CYAN << e.toFloat() << NOCOLOR << " as integer" << std::endl;

	std::cout << "|-----------------------------------------|" << std::endl;

	// afficherEnBinaire(c);
	// afficherEnBinaire(c.toInt());
	// afficherEnBinaire(c);
	// afficherEnBinaire(c.toFloat());
	// afficherEnBinaire(c);
	// std::cout << std::endl << binaryStringToInt("0000000011111111111111111111111")<< std::endl;
	// std::cout << std::endl << binaryStringToInt("11111111100000000000000000000000")<< std::endl;
	// std::cout << std::endl << binaryStringToInt("11111111110000000000000000000000")<< std::endl;
	return 0;
}

