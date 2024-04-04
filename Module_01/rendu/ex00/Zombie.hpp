/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 16:15:19 by yzaoui            #+#    #+#             */
/*   Updated: 2024/04/03 17:31:32 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <ostream>
#include <string>
#include <iomanip>
#include <sstream>

class Zombie
{
private:
	std::string	_name;
public:
	Zombie(std::string name);
	~Zombie();
	void	announce(void) const;
};

Zombie*	newZombie( std::string name);
void	randomChump( std::string name);

#endif