/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 02:27:16 by yzaoui            #+#    #+#             */
/*   Updated: 2024/04/11 21:24:39 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./FragTrap.hpp"

FragTrap::FragTrap(void)
{
	std::cout << "* " << GREEN << this->_name << " Evolue as FragTrap ." << NOCOLOR << "* " << std::endl;
	
	this->_name = "FragTrap";
	this->_stamina = 100;
	this->_quote = "";
	this->_initSomeState();
}
FragTrap::FragTrap(std::string name)
{
	this->_name = name;
	std::cout << "* " << GREEN << this->_name << " Evolue as FragTrap ." << NOCOLOR << "* " << std::endl;
	
	this->_stamina = 100;
	this->_quote = "";
	this->_initSomeState();
}
FragTrap	&FragTrap::operator=(FragTrap const &src)
{
	if (this != &src)
	{
		this->_name = src._name;
		this->_hp = src._hp;
		this->_stamina = src._stamina;
		this->_damage = src._damage;
	}
	std::cout << "* " << MAGENTA << this->_name << " COPY " << NOCOLOR;
	std::cout << YELLOW << this->_name << NOCOLOR << "* " << std::endl;

	return (*this);

}

FragTrap::~FragTrap()
{
	std::cout << "* FragTrap " << RED << this->_name << " start to be destroyed." << NOCOLOR << "* " << std::endl;
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "* " << BLUE << this->_name << NOCOLOR << " want to do a high five!" << "* " << std::endl;
	std::cout << RED << "3" << NOCOLOR << std::endl;
	sleep(3);
	std::cout << MAGENTA << "2" << NOCOLOR << std::endl;
	sleep(3);
	std::cout << GREEN << "1" << NOCOLOR << std::endl;
	sleep(3);
	std::cout << YELLOW << "HIGH FIVE FRIENDS !!" << NOCOLOR << std::endl;
	sleep(3);
}

void	FragTrap::_initSomeState(void)
{
	this->_hp = 100;
	this->_damage = 30;
}
