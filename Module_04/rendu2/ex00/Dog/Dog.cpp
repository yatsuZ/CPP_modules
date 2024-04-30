/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 17:14:07 by yzaoui            #+#    #+#             */
/*   Updated: 2024/04/13 17:16:53 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Dog.hpp"

Dog::Dog()
{
	this->_type = "Dog";
	std::cout << BLUE << "Constructor Dog call" << NOCOLOR << std::endl;
}

Dog::~Dog()
{
	std::cout << BLUE << "Destructor Dog call" << NOCOLOR << std::endl;
}

Dog::Dog(Dog const &src)
{
	*this = src;
}

Dog	&Dog::operator=(Dog const &src)
{
	if (this != &src)
		this->_type = src._type;
	return (*this);
}

void	Dog::makeSound(void) const
{
	std::cout << this->getType() << ": Ouaf Ouaf Ouaf !!!" << std::endl;
}