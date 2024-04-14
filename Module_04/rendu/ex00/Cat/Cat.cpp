/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 16:48:52 by yzaoui            #+#    #+#             */
/*   Updated: 2024/04/13 17:12:42 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Cat.hpp"

Cat::Cat()
{
	this->_type = "Cat";
	std::cout << YELLOW << "Constructor Cat call" << NOCOLOR << std::endl;
}

Cat::~Cat()
{
	std::cout << YELLOW << "Destructor Cat call" << NOCOLOR << std::endl;
}

Cat::Cat(Cat const &src)
{
	*this = src;
}

Cat	&Cat::operator=(Cat const &src)
{
	if (this != &src)
		this->_type = src._type;
	return (*this);
}

void	Cat::makeSound(void) const
{
	std::cout << this->getType() << ": Miaouuuuuuuuuuuuuuuuu UWU" << std::endl;
}