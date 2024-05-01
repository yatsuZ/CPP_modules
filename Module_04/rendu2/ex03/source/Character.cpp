/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 20:59:26 by yzaoui            #+#    #+#             */
/*   Updated: 2024/05/01 13:12:45 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/Character.hpp"

Character::Character(): _name("<UNKNOW>")
{
	std::cout << "A character named \"" << _name << "\" was created\n";
	for(int i = 0; i < 4; i++)
		this->_inventaire[i] = NULL;
}

Character::Character(std::string name): _name(name)
{
	std::cout << "A character named \"" << _name << "\" was created\n";
	for(int i = 0; i < 4; i++)
		this->_inventaire[i] = NULL;
}

Character::Character(Character const &src)
{
	*this = src;
}

Character	&Character::operator=(Character const &src)
{
	if (this != &src)
	{
		this->_name = src._name;
		for(int i = 0; i < 4; i++)
		{
			delete this->_inventaire[i];
			this->_inventaire[i] = src._inventaire[i];
		}
	}
	return (*this);
}

Character::~Character()
{
	for(int i = 0; i < 4; i++)
		delete this->_inventaire[i];
}

/////

std::string const &Character::getName() const
{
	return (this->_name);
}

void Character::equip(AMateria* m)
{
	for (size_t i = 0; i < 4; i++)
	{
		if (this->_inventaire[i] == NULL)
		{
			this->_inventaire[i] = m->clone();
			return ;
		}
	}
}

void Character::unequip(int idx)
{
	if (idx >= 0 && idx < 4)
		this->_inventaire[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx >= 0 && idx < 4 && this->_inventaire[idx])
		this->_inventaire[idx]->use(target);
}

