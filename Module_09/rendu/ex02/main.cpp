/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 12:49:20 by yzaoui            #+#    #+#             */
/*   Updated: 2024/06/26 01:30:58 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./PmergeMe_source/PmergeMe.hpp"

int main(int argc, char **argv)
{
	try
	{
		PmergeMe	test(argc, argv);
		test.exec(true);
	}
	catch(const std::exception& e)
	{
		std::cout << "Error : " << e.what() << std::endl;
	}
	return 0;
}
//shuf -i 1-2147483647 -n 5 | tr "\n" " "