/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 15:46:26 by yzaoui            #+#    #+#             */
/*   Updated: 2024/04/04 16:02:29 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include <string>
#include <iomanip>

int	main(void)
{
	int	nbrOfSeparator = 39;
	std::string	zQuote = "HI THIS IS BRAIN";
	std::string	*stringPTR = &zQuote;
	std::string	&stringREF = zQuote;

	std::cout << "|" << std::setw(nbrOfSeparator) << std::setfill('-') << "|" << std::endl;
	std::cout << "Adresse de zQuote    = " << &zQuote << std::endl;
	std::cout << "Adresse de stringPTR = " << stringPTR << std::endl;
	std::cout << "Adresse de stringREF = " << &stringREF << std::endl;
	std::cout << "|" << std::setw(nbrOfSeparator) << std::setfill('-') << "|" << std::endl;
	std::cout << "Valeur de zQuote     = " << zQuote << std::endl;
	std::cout << "Valeur de stringPTR  = " << *stringPTR << std::endl;
	std::cout << "Valeur de stringREF  = " << stringREF << std::endl;
	std::cout << "|" << std::setw(nbrOfSeparator) << std::setfill('-') << "|" << std::endl;
}