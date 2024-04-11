/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 16:10:57 by yzaoui            #+#    #+#             */
/*   Updated: 2024/04/11 16:53:07 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void)
{
	std::cout << "* " << YELLOW << this->_name << " SUPER FUSION as DiamondTrap ." << NOCOLOR << "* " << std::endl;
	
	this->_name = "DiamondTrap";
	this->ClapTrap::_name = this->_name + "_clap_name";
	this->FragTrap::_hp = \\;
	// this->_stamina = 100;
	// this->_damage = 30;
	// this->_quote = "";
}
DiamondTrap::DiamondTrap(std::string name)
{
	this->_name = name;
	std::cout << "* " << YELLOW << this->_name << " SUPER FUSION as DiamondTrap ." << NOCOLOR << "* " << std::endl;
	
	// this->_hp = 100;
	// this->_stamina = 100;
	// this->_damage = 30;
	// this->_quote = "";

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