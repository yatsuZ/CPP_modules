/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 17:38:02 by yzaoui            #+#    #+#             */
/*   Updated: 2024/04/13 19:08:02 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Constructor Brain call" << std::endl;
}

Brain::~Brain()
{
	std::cout << "Destructor Brain call" << std::endl;
}

Brain::Brain(Brain const &src)
{
	*this = src;
}

Brain	&Brain::operator=(Brain const &src)
{
	if (this != &src)
	{
		for (size_t i = 0; i < 100; ++i)
			this->_idea[i] = src._idea[i];
	}
	return (*this);
}

////////

void	Brain::showData(void) const
{
	std::cout << "all idea [";
	for (size_t i = 0; i < 100; ++i)
		std::cout << " \""<< this->_idea[i] << "\"";
	std::cout << " ]" << std::endl;
}

void	Brain::setIdea(std::string newIdea[100])
{
	for (size_t i = 0; i < 100; ++i)
		this->_idea[i] = newIdea[i];
}

std::string	*Brain::getIdea(void)
{
	return (this->_idea);
}


