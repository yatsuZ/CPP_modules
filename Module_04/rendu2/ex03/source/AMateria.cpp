/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 20:45:40 by yzaoui            #+#    #+#             */
/*   Updated: 2024/04/30 17:01:35 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/AMateria.hpp"
#include "./../header/Character.hpp"

AMateria::AMateria(void)
{
}

AMateria::~AMateria(void)
{
}

AMateria::AMateria(std::string const & type): _type(type)
{
}

std::string const & AMateria::getType() const
{
	return (this->_type);
}

AMateria::AMateria(AMateria const &src)
{
	*this = src;
}

AMateria	&AMateria::operator=(AMateria const &src)
{
	if (this != &src)
		this->_type = src._type;
	return (*this);
}

void AMateria::use(ICharacter& target)
{
	std::cout << YELLOW << "* use " << target.getName() << " *" << NOCOLOR << std::endl;
}
