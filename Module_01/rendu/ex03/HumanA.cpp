/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 18:48:46 by yzaoui            #+#    #+#             */
/*   Updated: 2024/04/04 17:59:35 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weponT): _weaponType(weponT), _name(name)
{
}

HumanA::~HumanA()
{
}

void	HumanA::attack(void) const
{
	std::cout << this->_name << " attacks with their " << this->_weaponType.getType();
	std::cout << std::endl;
}
