/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 20:49:00 by yzaoui            #+#    #+#             */
/*   Updated: 2024/04/13 21:42:41 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice()
{
	this->_type = "ice";
}

Ice::~Ice()
{
}

AMateria* Ice::clone(void) const
{
	Ice *newIce = new Ice();
	return (newIce);
}

Ice::Ice(Ice const &src)
{
	*this = src;
}

Ice	&Ice::operator=(Ice const &src)
{
	if (this != &src)
		this->_type = src._type;
	return (*this);
}

void Ice::use(ICharacter& target)
{
	std::cout << BLUE << "* shoots an ice bolt at " << target.getName() << "*" << NOCOLOR << std::endl;
}


