/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 17:25:51 by yzaoui            #+#    #+#             */
/*   Updated: 2024/04/13 17:28:46 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./WrongCat.hpp"

WrongCat::WrongCat()
{
	this->_type = "WrongCat";
	std::cout << MAGENTA << "Constructor WrongCat call" << NOCOLOR << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << MAGENTA << "Destructor WrongCat call" << NOCOLOR << std::endl;
}

WrongCat::WrongCat(WrongCat const &src)
{
	*this = src;
}

WrongCat	&WrongCat::operator=(WrongCat const &src)
{
	if (this != &src)
		this->_type = src._type;
	return (*this);
}

void	WrongCat::makeSound(void) const
{
	std::cout << this->getType() << ": Miaouuuuuuuuuuuuuuuuu UWU" << std::endl;
}