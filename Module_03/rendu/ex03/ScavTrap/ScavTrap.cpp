/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 01:13:59 by yzaoui            #+#    #+#             */
/*   Updated: 2024/04/11 16:40:52 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	std::cout << "* " << CYAN << this->_name << " Evolue as ScavTrap ." << NOCOLOR << "* " << std::endl;
	
	this->_name = "ScavTrap";
	this->_hp = 100;
	this->_stamina = 50;
	this->_damage = 20;
	this->_quote = "";
	this->_guard = false;
}

ScavTrap::ScavTrap(std::string name)
{
	std::cout << "* " << CYAN << this->_name << " Evolue as ScavTrap." << NOCOLOR << "* "<< std::endl;

	this->_name = name;
	this->_hp = 100;
	this->_stamina = 50;
	this->_damage = 20;
	this->_quote = "";
	this->_guard = false;
}

ScavTrap::~ScavTrap()
{
	std::cout << "* ScavTrap " << RED << this->_name << " start to be destroyed." << NOCOLOR << "* " << std::endl;
}


ScavTrap	&ScavTrap::operator=(ScavTrap const &src)
{
	if (this != &src)
	{
		this->_name = src._name;
		this->_hp = src._hp;
		this->_stamina = src._stamina;
		this->_damage = src._damage;
		this->_guard = src._guard;
	}
	std::cout << "* " << MAGENTA << this->_name << " COPY " << NOCOLOR;
	std::cout << YELLOW << this->_name << NOCOLOR << "* " << std::endl;

	return (*this);
}

void	ScavTrap::takeDamage(unsigned int amount)
{
	if (this->_guard)
		std::cout << YELLOW << this->_name << NOCOLOR << " IS ON GUARD MODE HE DONT TAKE DAMAGE!!* " << std::endl;
	else
		this->ClapTrap::takeDamage(amount);
	this->_guard = false;
}

void ScavTrap::guardGate(void)
{
	if (this->_stamina < 10)
	{
		std::cout << RED << this->_name << NOCOLOR << " dont have enough stamina for activate GUARD MODE ...* " << std::endl;
		return ;
	}
	if (this->_guard)
		std::cout << YELLOW << this->_name << NOCOLOR << " is already on guard mode !!* " << std::endl;
	else
		std::cout << MAGENTA << this->_name << NOCOLOR << " ACTIVATE GUARD MODE !!* " << std::endl;
	this->_guard = true;
	this->_stamina -= 10;
}

void	ScavTrap::showData(void) const
{
	std::cout << "--------------------------------" << std::endl;
	std::cout << "Adresse = " << this << std::endl;
	std::cout << "name = " << this->_name << std::endl;
	std::cout << "quote = \"" << this->_quote << "\"" << std::endl;
	std::cout << "hp = " << this->_hp << std::endl;
	std::cout << "stamina = " << this->_stamina << std::endl;
	std::cout << "damage = " << this->_damage << std::endl;
	std::cout << "guard = " << (this->_guard?"TRUE":"FALSE") << std::endl;
	std::cout << "--------------------------------" << std::endl;
}
