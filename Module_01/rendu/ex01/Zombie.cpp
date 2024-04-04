/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 16:15:11 by yzaoui            #+#    #+#             */
/*   Updated: 2024/04/03 18:35:11 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Zombie.hpp"


Zombie::Zombie()
{
	std::cout << "WHAT THATS ?";
	std::cout << std::endl;
}
Zombie::Zombie(std::string name): _name(name)
{
	std::cout << "* " << this->_name;
	std::cout << " comes out of the ground *";
	std::cout << std::endl;
}

Zombie::~Zombie()
{
	std::cout << "* " << this->_name;
	std::cout << " was exorcised by plants *";
	std::cout << std::endl;
}

void	Zombie::announce(void) const
{
	std::cout << this->_name;
	std::cout << ": BraiiiiiiinnnzzzZ...";
	std::cout << std::endl;
}