/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 16:15:19 by yzaoui            #+#    #+#             */
/*   Updated: 2024/04/03 18:32:06 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <ostream>
#include <string>

class Zombie
{
private:
	std::string	_name;
public:
	Zombie(std::string name);
	Zombie();
	~Zombie();
	void	announce(void) const;
};

Zombie*	zombieHorde(int N, std::string name);
void	delete_zombieHorde(Zombie *hordeZombie);

#endif