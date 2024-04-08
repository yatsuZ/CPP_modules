/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 16:15:11 by yzaoui            #+#    #+#             */
/*   Updated: 2024/04/07 17:43:56 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Zombie.hpp"


Zombie::Zombie()
{
	std::string	yellow = "\033[33m";
	std::string	no_color = "\033[0m";
	
	std::cout << yellow << "Constructeur by default : " << no_color;
	std::cout << "WHAT THATS ?";
	std::cout << std::endl;
}



Zombie::Zombie(std::string name): _name(name)
{
	std::string	no_color = "\033[0m";
	std::string magenta = "\033[35m";

	std::cout << magenta << "Constructeur parametric : " << no_color;
	std::cout << "* " << this->_name;
	std::cout << " comes out of the ground *";
	std::cout << std::endl;
}

Zombie::~Zombie()
{
	std::string	no_color = "\033[0m";
	std::string red = "\033[31m";

	std::cout << red << "Destructeur default     : " << no_color;
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

void	Zombie::setName(std::string name)
{
	this->_name = name;
}