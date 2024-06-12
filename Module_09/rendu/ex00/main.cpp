/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 12:49:20 by yzaoui            #+#    #+#             */
/*   Updated: 2024/06/12 21:23:50 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./BitcoinExchange/BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if (argc > 1)
		std::cout << "fichier d'input : " << argv[1] << std::endl;
	else
		std::cout << "Error: could not open file." << std::endl;
	return 0;
}
