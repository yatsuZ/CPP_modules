/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 16:15:11 by yzaoui            #+#    #+#             */
/*   Updated: 2024/04/07 18:22:14 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Zombie.hpp"

Zombie::Zombie(std::string name): _name(name)
{
	std::cout << YELLOW << "* " << this->_name;
	std::cout << " comes out of the ground *" << NOCOLOR;
	std::cout << std::endl;
}

Zombie::~Zombie()
{
	std::cout << RED << "* " << this->_name;
	std::cout << " was exorcised by plants *" << NOCOLOR;
	std::cout << std::endl;
}

void	Zombie::announce(void) const
{
	std::cout << MAGENTA << this->_name;
	std::cout << ": BraiiiiiiinnnzzzZ...";
	std::cout << NOCOLOR << std::endl;
}