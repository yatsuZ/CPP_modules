/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 18:48:21 by yzaoui            #+#    #+#             */
/*   Updated: 2024/04/04 18:10:30 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Weapon.hpp"

Weapon::Weapon(std::string type): _type(type)
{
}

Weapon::~Weapon()
{
}

void	Weapon::setType(std::string type)
{
	this->_type = type;
}

const std::string& Weapon::getType(void)
{
	return (this->_type);
}