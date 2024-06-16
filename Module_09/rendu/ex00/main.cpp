/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 12:49:20 by yzaoui            #+#    #+#             */
/*   Updated: 2024/06/17 00:41:03 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./BitcoinExchange/BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	try
	{
		BitcoinExchange DataFileBitcoin(argc, argv);

		DataFileBitcoin.exec();
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " RED << e.what() << NOCOLOR << '\n';
	}
	return 0;
}
