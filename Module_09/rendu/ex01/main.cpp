/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 12:49:20 by yzaoui            #+#    #+#             */
/*   Updated: 2024/06/22 19:36:47 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./RPN/RPN.hpp"

int main(int argc, char **argv)
{
	(void)	argc;
	(void)	argv;
	try
	{
		std::cout << "faire rpn." << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " RED << e.what() << NOCOLOR << '\n';
	}
	return 0;
}
