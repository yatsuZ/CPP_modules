/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 15:27:32 by yzaoui            #+#    #+#             */
/*   Updated: 2024/04/08 02:12:23 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int	main(void)
{
	Point	a(3, 3), b(6, 2), c(1, 5), p(1, 5);

	showBsp10x10(a, b, c, p);
	if (bsp(a, b, c, p))
		std::cout << BLUE << "Le point P est dans l'aire du triangle." << NOCOLOR << std::endl;
	else
		std::cout << MAGENTA << "Le point P N'est PAS dans l'aire du triangle." << NOCOLOR << std::endl;
	return 0;
}


// NEtoyer le code