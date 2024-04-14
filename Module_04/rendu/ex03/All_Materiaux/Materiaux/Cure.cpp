/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 20:48:44 by yzaoui            #+#    #+#             */
/*   Updated: 2024/04/13 20:49:20 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure()
{
	this->_type = "cure";
}

Cure::~Cure()
{
}

AMateria* Cure::clone(void) const
{
	Cure *newCure = new Cure();
	return (newCure);
}

Cure::Cure(Cure const &src)
{
	*this = src;
}

Cure	&Cure::operator=(Cure const &src)
{
	if (this != &src)
		this->_type = src._type;
	return (*this);
}

void Cure::use(ICharacter& target)
{
	std::cout << YELLOW << "* heals " << target.getName() << "’s wounds *" << NOCOLOR << std::endl;
}
