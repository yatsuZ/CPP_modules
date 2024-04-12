/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 16:10:57 by yzaoui            #+#    #+#             */
/*   Updated: 2024/04/12 15:17:26 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void)
{
	std::cout << "* " << YELLOW << "SUPER FUSION as DiamondTrap ." << NOCOLOR << "* " << std::endl;
	
	this->_name = "DiamondTrap";
	this->ClapTrap::_name = this->_name + "_clap_name";
	this->FragTrap::_initSomeState();
	this->ScavTrap::_initSomeState();
}
DiamondTrap::DiamondTrap(std::string name)
{
	std::cout << "* " << YELLOW << "SUPER FUSION as DiamondTrap ." << NOCOLOR << "* " << std::endl;
	
	this->_name = name;
	this->ClapTrap::_name = this->_name + "_clap_name";
	this->FragTrap::_initSomeState();
	this->ScavTrap::_initSomeState();

}
DiamondTrap	&DiamondTrap::operator=(DiamondTrap const &src)
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

DiamondTrap::~DiamondTrap()
{
	std::cout << "* DiamondTrap " << RED << this->_name << " DEFUSION :(" << NOCOLOR << "* " << std::endl;
}

void DiamondTrap::whoAmI(void) const
{
	std::cout << "ClapTrap::name = " << this->ClapTrap::_name << std::endl;
	std::cout << "name = " << this->_name << std::endl;
}


void	DiamondTrap::showData(void) const
{
	std::cout << "--------------------------------" << std::endl;
	std::cout << "Adresse = " << this << std::endl;
	this->whoAmI();
	std::cout << "quote = \"" << this->_quote << "\"" << std::endl;
	std::cout << "hp = " << this->_hp << std::endl;
	std::cout << "stamina = " << this->_stamina << std::endl;
	std::cout << "damage = " << this->_damage << std::endl;
	std::cout << "guard = " << (this->_guard?"TRUE":"FALSE") << std::endl;
	std::cout << "--------------------------------" << std::endl;
}

void DiamondTrap::attack(std::string const &target)
{
	this->ScavTrap::attack(target);
}
