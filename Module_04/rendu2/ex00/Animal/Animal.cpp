/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 16:18:22 by yzaoui            #+#    #+#             */
/*   Updated: 2024/04/13 16:52:25 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(): _type("Animal")
{
	std::cout << GREEN << "Constructor Animal call" << NOCOLOR << std::endl;
}

Animal::~Animal()
{
	std::cout << GREEN << "Destructor Animal call" << NOCOLOR << std::endl;
}

Animal::Animal(Animal const &src)
{
	*this = src;
}

Animal	&Animal::operator=(Animal const &src)
{
	if (this != &src)
		this->_type = src._type;
	return (*this);
}

void	Animal::showType(void) const
{
	std::cout << "----------------------" << std::endl;
	std::cout << "adresse = " << this << std::endl;
	std::cout << "type = " << this->_type << std::endl;
	std::cout << "----------------------" << std::endl;
}

std::string	Animal::getType(void) const
{
	return (this->_type);
}

void	Animal::makeSound(void) const
{
	std::cout << this->getType() << ": ????" << std::endl;
}
