/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 15:27:32 by yzaoui            #+#    #+#             */
/*   Updated: 2024/04/07 14:33:37 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

void afficherEnBinaire(Fixed nombre) {
	int tailleEnBits = sizeof(int) * 8;

	for (int i = tailleEnBits - 1; i >= 0; --i) {
		int bit = (nombre.getRawBits() >> i) & 1;
		std::cout << bit;
	}
	std::cout << std::endl;
}

int	main( void )
{
	Point	a, b, c, p;

	showBsp(a, b, c, p);
	return 0;
}
