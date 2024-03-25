/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 18:34:52 by yzaoui            #+#    #+#             */
/*   Updated: 2024/03/25 02:17:06 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Sample.class.h"

void	f0( void ) {
	Sample instance;
	std::cout << "Number of instances : " << Sample::getNbInst() << std::endl;
	return;
}


void	f1( void ) {
	Sample instance;
	std::cout << "Number of instances : " << Sample::getNbInst() << std::endl;
	f0();

	return;
}

int	main()
{
	std::cout << "Number of instances : " << Sample::getNbInst() << std::endl;
	f1();
	std::cout << "Number of instances : " << Sample::getNbInst() << std::endl;
	return 0;
}