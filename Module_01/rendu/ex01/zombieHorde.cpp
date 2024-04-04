/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 17:40:26 by yzaoui            #+#    #+#             */
/*   Updated: 2024/04/04 15:41:07 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Zombie.hpp"

Zombie*	zombieHorde(int N, std::string name)
{
	if (N <= 0)
		return NULL;

	Zombie* horde = new Zombie[N];
	for (int i = 0; i < N; i++)
		horde[i].setName(name);
	return horde;
}

void	delete_zombieHorde(Zombie *hordeZombie)
{
	if (!hordeZombie)
		return ;
	delete[] hordeZombie;
}
