/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 00:48:33 by yzaoui            #+#    #+#             */
/*   Updated: 2024/03/26 01:21:18 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Integer.class.hpp"

int	main() {
	Integer	x(30);
	Integer	y(10);
	Integer	z(0);

	std::cout << "-------------------" << std::endl << std::endl;
	std::cout << "Value of x : " << x << std::endl;
	std::cout << "Value of y : " << y << std::endl;
	y = Integer( 12 );
	std::cout << "Value of y : " << y << std::endl;
	std::cout << "-------------------" << std::endl << std::endl;

	std::cout << "Value of z : " << z << std::endl;
	z = x + y;
	std::cout << "Value of z : " << z << std::endl;
	std::cout << "-------------------" << std::endl << std::endl;

	return (0);
}