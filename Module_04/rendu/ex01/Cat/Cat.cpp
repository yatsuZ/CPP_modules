/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 16:48:52 by yzaoui            #+#    #+#             */
/*   Updated: 2024/04/13 19:03:03 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Cat.hpp"

Cat::Cat()
{
	this->_type = "Cat";
	std::cout << YELLOW << "Constructor Cat call" << NOCOLOR << std::endl;
	this->_thoughts = new (Brain);
}

Cat::~Cat()
{
	delete this->_thoughts;
	std::cout << YELLOW << "Destructor Cat call" << NOCOLOR << std::endl;
}

Cat::Cat(Cat const &src)
{
	*this = src;
}

Cat	&Cat::operator=(Cat const &src)
{
	if (this != &src)
	{
		this->_type = src._type;
		this->_thoughts = src._thoughts;
	}
	return (*this);
}

void	Cat::makeSound(void) const
{
	std::cout << this->getType() << ": Miaouuuuuuuuuuuuuuuuu UWU" << std::endl;
}

void	Cat::showData(void) const
{
	this->showType();
	this->_thoughts->showData();
}

void	Cat::setThoughts(std::string newThoughts[100])
{
	this->_thoughts->setIdea(newThoughts);
}

