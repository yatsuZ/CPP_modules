/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 18:48:57 by yzaoui            #+#    #+#             */
/*   Updated: 2024/04/04 18:11:45 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./HumanB.hpp"

HumanB::HumanB(std::string name): _weaponType(NULL), _name(name)
{
}

HumanB::~HumanB()
{
}

void	HumanB::setWeapon(Weapon &weapon)
{
	this->_weaponType = &weapon;
}
void	HumanB::attack(void) const
{
	if (!this->_weaponType)
		std::cout << this->_name << " can't attack.";
	else
		std::cout << this->_name << " attacks with their " << this->_weaponType->getType();
	std::cout << std::endl;
}
