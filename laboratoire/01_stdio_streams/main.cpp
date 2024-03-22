/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 17:59:33 by yzaoui            #+#    #+#             */
/*   Updated: 2024/03/22 18:12:17 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<iostream>

int	main(void)
{
	char	buff[512];

	std::cout << "Hello World !" << std::endl;

	std::cout << "Input a word: ";
	std::cin >> buff;
	std::cout << "You entered : [" << buff << "]" << std::endl;
	
	return (0);
}