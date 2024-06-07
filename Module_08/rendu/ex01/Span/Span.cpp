/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 16:59:35 by yzaoui            #+#    #+#             */
/*   Updated: 2024/06/07 14:42:17 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

unsigned int	Span::getN(void) const
{
	return (this->_n);
}

unsigned int	Span::getPlace(void) const
{
	return (this->_place);
}

void	Span::setN(int n)
{
	this->_n = n;
}

Span::Span(): _n(0), _contenair(NULL), _place(this->_n)
{
	std::cout << "Constructeur Span : Default " << std::endl;
}

Span::Span(int n): _n(n), _contenair(NULL), _place(this->_n)
{
	std::cout << "Constructeur Span : Parametric, n = " << n << std::endl;
	if (this->_n == 0)
		return ;
	this->_contenair = new int[this->getN()];
	for (unsigned int i = 0; i < this->_n; i++)
	{
		this->_contenair[i] = int();
	}
}

int				*Span::getContenair(void) const
{
	return (this->_contenair);
}

Span	&Span::operator=(const Span &src)
{
	if (this != &src)
	{
		delete[] this->_contenair;
		this->setN(src.getN());
		this->_place = src.getPlace();
		if (this->getN() == 0 || src.getContenair() == NULL)
		{
			this->_contenair = NULL;
			return (*this);
		}
		this->_contenair = new int[this->getN()];
		for (unsigned int i = 0; i < this->_n; i++)
		{
			this->_contenair[i] = src.getContenair()[i];
		}
	}
	return (*this);
}

Span::Span(const Span &src)
{
	std::cout << "Constructeur Span : By copy" << std::endl;
	*this = src;
}

Span::~Span()
{
	std::cout << "Destructeur Span " << std::endl;
}

void			Span::showSpan(void) const
{
	for (unsigned int i = 0; i < this->getN(); i++)
	{
		std::cout << "Span[" << i << "] = " << this->getContenair()[i] << std::endl;
	}
}
