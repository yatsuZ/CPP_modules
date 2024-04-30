/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 17:14:07 by yzaoui            #+#    #+#             */
/*   Updated: 2024/04/13 19:09:38 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Dog.hpp"

Dog::Dog()
{
	this->_type = "Dog";
	std::cout << BLUE << "Constructor Dog call" << NOCOLOR << std::endl;
	this->_thoughts = new (Brain);
}

Dog::~Dog()
{
	delete this->_thoughts;
	std::cout << BLUE << "Destructor Dog call" << NOCOLOR << std::endl;
}

Dog::Dog(Dog const &src)
{
	*this = src;
}

Dog	&Dog::operator=(Dog const &src)
{
	if (this != &src)
	{
		this->_type = src._type;
		delete this->_thoughts;
		this->_thoughts = new Brain(*src._thoughts);
	}
	return (*this);
}

void	Dog::makeSound(void) const
{
	std::cout << this->getType() << ": Ouaf Ouaf Ouaf !!!" << std::endl;
}

void	Dog::showData(void) const
{
	this->showType();
	this->_thoughts->showData();
}

void	Dog::setThoughts(std::string newThoughts[100])
{
	this->_thoughts->setIdea(newThoughts);
}

