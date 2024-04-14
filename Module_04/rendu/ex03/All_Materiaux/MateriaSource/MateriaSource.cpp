/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 21:45:43 by yzaoui            #+#    #+#             */
/*   Updated: 2024/04/13 23:36:18 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for(int i = 0; i < 4; i++)
		this->_inventaire[i] = NULL;
}

MateriaSource::~MateriaSource()
{
	for(int i = 0; i < 4; i++)
	{
		delete this->_inventaire[i];
		this->_inventaire[i] = NULL;
	}
}

MateriaSource::MateriaSource(MateriaSource const &src)
{
	*this = src;
}

MateriaSource &MateriaSource::operator=(MateriaSource const &src)
{
	if (this != &src)
	{
		for(int i = 0; i < 4; i++)
		{
			if (this->_inventaire != NULL)
				delete this->_inventaire[i];
			this->_inventaire[i] = src._inventaire[i];
		}
	}
	return (*this);
}

void	MateriaSource::learnMateria(AMateria* newMateria)
{
	if (newMateria == NULL || this->_inventaire == NULL)
		return ;
	for (size_t i = 0; i < 4; i++)
	{
		if (this->_inventaire[i] == NULL)
		{
			this->_inventaire[i] = newMateria->clone();
			return ;
		}
	}
}

AMateria	*MateriaSource::createMateria(std::string const & type)
{
	if (this->_inventaire == NULL)
		return (NULL);
	for (size_t i = 0; i < 4; i++)
	{
		if (this->_inventaire[i]->getType() == type)
			return (this->_inventaire[i]->clone());
	}
	return (NULL);
}