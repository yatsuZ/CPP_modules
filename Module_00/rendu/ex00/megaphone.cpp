/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 22:08:55 by yzaoui            #+#    #+#             */
/*   Updated: 2024/03/30 01:15:10 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

void	ft_magaphone(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		str[i] = std::toupper(str[i]);
		i++;
	}
}

int main(int argc, char **argv)
{
	int i;

	i = 1;
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	while (i < argc)
	{
		ft_magaphone(argv[i]);
		std::cout << argv[i];
		i++;
	}
	std::cout << std::endl;
	return (0);
}