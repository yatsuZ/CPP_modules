/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 16:14:53 by yzaoui            #+#    #+#             */
/*   Updated: 2024/04/08 12:55:05 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Zombie/Zombie.hpp"

int	main(void)
{
	Zombie	z_originel("Orignel Z");

	randomChump("Random chump");

	Zombie	*tmp = (newZombie("PTR 1 Z"));
	if (!tmp)
		return (1);
	Zombie	z_ptr = *tmp;

	Zombie	*z_pointeur2 = newZombie("Pointeur2 Z");
	if (!z_pointeur2)
		return (delete tmp, 1);

	z_originel.announce();
	z_ptr.announce();
	z_pointeur2->announce();

	delete tmp;
	delete z_pointeur2;
}


