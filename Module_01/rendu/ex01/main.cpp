/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 16:14:53 by yzaoui            #+#    #+#             */
/*   Updated: 2024/04/04 15:31:58 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Zombie.hpp"

int	main(void)
{
	int	N_Clonne = 1;
	Zombie	z_originel("Orignel Z");
	Zombie	*hordZ = zombieHorde(N_Clonne, "CLONNE Z");

	for (int i = 0; i < N_Clonne; i++)
		hordZ[i].announce();
	z_originel.announce();
	delete_zombieHorde(hordZ);
}
