/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 12:49:20 by yzaoui            #+#    #+#             */
/*   Updated: 2024/06/25 19:29:50 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./PmergeMe_source/PmergeMe.hpp"

int main(int argc, char **argv)
{
	(void) argc;
	(void) argv;
	try
	{
		// std::cout << "Je dois stockée dans 2 conteneur different" << std::endl;
		// std::cout << "Ligne 1 montrée avant le trie" << std::endl;
		// std::cout << "Je vais devoir utilise merge-insert pour chaqun des deux." << std::endl;
		// std::cout << "Je dois pouvoir gérer au moins 3000 entiers différents." << std::endl;
		PmergeMe	test(argc, argv);

		test.exec();
	}
	catch(const std::exception& e)
	{
		std::cout << "Error : " << e.what() << std::endl;
	}
	return 0;
}
