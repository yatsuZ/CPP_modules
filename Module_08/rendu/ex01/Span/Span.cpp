/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 16:59:35 by yzaoui            #+#    #+#             */
/*   Updated: 2024/06/20 20:09:23 by yzaoui           ###   ########.fr       */
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
	// std::cout << "Constructeur Span : Default " << std::endl;
}

Span::Span(int n): _n(n), _contenair(NULL), _place(this->_n)
{
	// std::cout << GREEN "Constructeur Span :" NOCOLOR " Parametric, n = " << n << std::endl;
	if (this->_n == 0)
		return ;
	try
	{
		this->_contenair = new int[this->getN()];
	}
	catch (const std::bad_alloc& e)
	{
		std::cerr << "Memory allocation failed: " << e.what() << '\n';
		throw;
	}

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
		if (this->getN() != 0)
			delete []this->_contenair;
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

Span::Span(const Span &src): _n(0), _contenair(NULL), _place(0)
{
	// std::cout << CYAN "Constructeur Span : By copy" NOCOLOR << std::endl;
	*this = src;
}

Span::~Span()
{
	delete []this->_contenair;
	// std::cout << YELLOW "Destructeur Span " NOCOLOR << std::endl;
}

void			Span::showSpan(void) const
{
	std::cout << "Span have " << this->getPlace() << " place available and contain : " << std::endl;
	for (unsigned int i = 0; i < this->getN(); i++)
	{
		std::cout << "Span[" << i << "] = " << this->getContenair()[i] << std::endl;
	}
	std::cout << "-----------------------" << std::endl;
}

////////////////////////////////////////

//verifie pour le cas de int max et int min
long				Span::shortestSpan(void) const
{
	if (this->getN() < 2)
		throw Span::ToShort(" for find the shortest Span.");
	Span	cpy = *this;

	std::sort(cpy._contenair, cpy._contenair + cpy.getN());
	long	res = std::numeric_limits<int>::max();
	for (unsigned int i = 1; i < cpy.getN(); ++i)
	{
		long diff = static_cast<long>(cpy._contenair[i]) - static_cast<long>(cpy._contenair[i-1]);
		if (diff < res)
			res = diff;
	}
	return (res);
}

long				Span::longestSpan(void) const
{
	if (this->getN() < 2)
		throw Span::ToShort(" for find the longest Span.");
	long	min = this->_contenair[0];
	long	max = this->_contenair[0];
	long	res;
	for (unsigned int i = 0; i < this->getN(); i++)
	{
		min = (min > this->_contenair[i] ? this->_contenair[i] : min);
		max = (max < this->_contenair[i] ? this->_contenair[i] : max);
	}
	res = max - min;
	return (res);
}

void				Span::addNumber(const int nbr)
{
	if (this->getN() == 0 || this->getPlace() == 0)
		throw Span::NoMorePlace() ;
	
	this->_place--;
	this->_contenair[this->_place] = nbr;
}

void			Span::addNumbers(const std::vector<int>& numbers)
{
	for (std::vector<int>::const_iterator it = numbers.begin(); it != numbers.end() && this->getPlace(); ++it)
	{
		this->addNumber(*it);
	}
}
