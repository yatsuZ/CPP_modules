/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 17:54:21 by yzaoui            #+#    #+#             */
/*   Updated: 2024/03/29 18:55:39 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./import.h"

char	*get_input(char *msg)
{
	char	*input = NULL;
	char	*yellow = "\033[33m";
	char	*green = "\033[32m";
	char	*no_color = "\033[0m";

	std::cout << yellow << msg << green;
	std::cin >> input;
	std::cout << no_color << std::endl;
	return (input);
}
// else if (color == MAGENTA)
// 	printf("\033[35m");
// else if (color == CYAN)
// 	printf("\033[36m");
// else if (color == BLANC)
// 	printf("\033[37m");

int	is_good_name(char *str)
{
	unsigned long	i;

	if (!str)
		return (1);
	i = 0;
	while (str[i])
	{
		if ((str[i] < 'A' || str[i] > 'Z') && (str[i] < 'a' || str[i] > 'a'))
			return (1);
		i++;
	}
	return (!(str[0] >= 'A' && str[0] <= 'Z'));
}

int	is_a_legit_number_phone(char *str)
{
	unsigned long	i;

	if (!str)
		return (1);
	i = 0;
	while (str[i])
	{
		if (str[i] > '9' || str[i] < '0')
			return (1);
		i++;
	}
	return (i != 10);
}