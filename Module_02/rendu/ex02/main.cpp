/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 15:27:32 by yzaoui            #+#    #+#             */
/*   Updated: 2024/04/07 02:04:00 by yzaoui           ###   ########.fr       */
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

int	main( void ) {
	Fixed		a;
	Fixed const	b(2147483647);

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a + 1 << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;

	return 0;
}
