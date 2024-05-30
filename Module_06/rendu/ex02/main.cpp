/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 17:51:14 by yzaoui            #+#    #+#             */
/*   Updated: 2024/05/30 14:01:03 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "folowingFunction.hpp"

int	main(void)
{
	Base	*stockage;
	Base	*ptr_null = NULL;
	identify(*(ptr_null));
	std::cout << "------------" << std::endl;
	// connaitre le type de stockage  sans include type info en c++98
	for (size_t i = 0; i < 10; i++)
	{
		stockage = generate();
		identify(stockage);
		identify(*stockage);
		std::cout << " ------------" << std::endl;
		delete stockage;
		stockage = NULL;
	}
	return (0);
}