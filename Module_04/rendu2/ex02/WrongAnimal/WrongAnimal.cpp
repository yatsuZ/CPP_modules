/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 17:23:51 by yzaoui            #+#    #+#             */
/*   Updated: 2024/04/13 19:24:16 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./WrongAnimal.hpp"

WrongAnimal::WrongAnimal(): _type("WrongAnimal")
{
	std::cout << RED << "Constructor WrongAnimal call" << NOCOLOR << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << RED << "Destructor WrongAnimal call" << NOCOLOR << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const &src)
{
	*this = src;
}

WrongAnimal	&WrongAnimal::operator=(WrongAnimal const &src)
{
	if (this != &src)
		this->_type = src._type;
	return (*this);
}

void	WrongAnimal::showType(void) const
{
	std::cout << "----------------------" << std::endl;
	std::cout << "adresse = " << this << std::endl;
	std::cout << "type = " << this->_type << std::endl;
	std::cout << "----------------------" << std::endl;
}

std::string	WrongAnimal::getType(void) const
{
	return (this->_type);
}

void	WrongAnimal::makeSound(void) const
{
	std::cout << this->getType() << ": ????" << std::endl;
}
