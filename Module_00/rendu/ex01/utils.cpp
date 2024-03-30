/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 17:54:21 by yzaoui            #+#    #+#             */
/*   Updated: 2024/03/30 02:08:10 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./import.h"

std::string get_input(std::string msg)
{
	std::string	input;
	std::string	yellow = "\033[33m";
	std::string	green = "\033[32m";
	std::string	no_color = "\033[0m";

	std::cout << yellow << msg << green;
	std::getline(std::cin, input);
	std::cout << no_color;
	if (input.empty())
	{
		input = "NULL";
		std::cout << std::endl;
	}
	return (input);
}
// else if (color == MAGENTA)
// 	printf("\033[35m");
// else if (color == CYAN)
// 	printf("\033[36m");
// else if (color == BLANC)
// 	printf("\033[37m");

int	is_good_name(std::string str)
{
	unsigned long	i;

	i = 0;
	while (str[i])
	{
		if (!(str[i] >= 'A' && str[i] <= 'Z') || !(str[i] >= 'a' && str[i] <= 'z'))
			return (1);
		i++;
	}
	return (!(str[0] >= 'A' && str[0] <= 'Z'));
}

int	is_a_legit_number_phone(std::string str)
{
	unsigned long	i;

	i = 0;
	while (str[i])
	{
		if (str[i] > '9' || str[i] < '0' || i > 10)
			return (1);
		i++;
	}
	return (i != 10);
}