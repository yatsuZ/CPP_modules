/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 16:59:35 by yzaoui            #+#    #+#             */
/*   Updated: 2024/06/04 17:21:58 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int	Span::getN(void) const
{
	return (this->_n);
}
void	Span::setN(const int n)
{
	this->_n = n;
}

Span::Span(): _n(0)
{
	std::cout << "Constructeur Span : Default " << std::endl;
}

Span::Span(int n): _n(n)
{
	std::cout << "Constructeur Span : Parametric, n = " << n << std::endl;
}

Span	&Span::operator=(const Span &src)
{
	if (this != &src)
	{
		this->setN(src.getN());
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

