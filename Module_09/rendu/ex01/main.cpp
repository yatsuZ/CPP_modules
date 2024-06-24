/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 12:49:20 by yzaoui            #+#    #+#             */
/*   Updated: 2024/06/24 16:40:59 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./RPN_source/RPN.hpp"

int main(int argc, char **argv)
{
	try
	{
		RPN	test(argc, argv);

		test.exec();
	}
	catch(const std::exception& e)
	{
		std::cout << "Error : " << e.what() << std::endl;
	}
	return 0;
}
