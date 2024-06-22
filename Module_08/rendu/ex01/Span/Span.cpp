/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 16:59:35 by yzaoui            #+#    #+#             */
/*   Updated: 2024/06/22 15:59:52 by yzaoui           ###   ########.fr       */
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

Span::Span(): _n(0), _contenair(std::list<int>()), _place(this->_n)
{
	// std::cout << "Constructeur Span : Default " << std::endl;
}

Span::Span(unsigned int n): _n(n), _contenair(std::list<int>()), _place(this->_n)
{
	// std::cout << GREEN "Constructeur Span :" NOCOLOR " Parametric, n = " << n << std::endl;
	if (this->_n == 0)
		return ;
}

std::list<int>	Span::getContenair(void) const
{
	return (this->_contenair);
}

Span	&Span::operator=(const Span &src)
{
	if (this != &src)
	{
		this->setN(src.getN());
		this->_place = src.getPlace();
		this->_contenair = src.getContenair();
	}
	return (*this);
}

Span::Span(const Span &src): _n(0), _contenair(), _place(0)
{
	// std::cout << CYAN "Constructeur Span : By copy" NOCOLOR << std::endl;
	*this = src;
}

Span::~Span()
{
	// std::cout << YELLOW "Destructeur Span " NOCOLOR << std::endl;
}

void			Span::showSpan(void) const
{
	std::cout << "Span have " << this->getPlace() << " place available and contain : " << std::endl;
	std::size_t i = 0;
	for (std::list<int>::const_iterator it = this->_contenair.begin(); it != this->_contenair.end(); ++it, i++)
	{
		std::cout << "Span[" << i << "] = " <<  *it << std::endl;
	}
	std::cout << "-----------------------" << std::endl;
}

////////////////////////////////////////

//verifie pour le cas de int max et int min
long				Span::shortestSpan(void) const
{
	if (this->getN() < 2)
		throw Span::ToShort(" for find the shortest Span.");

	try
	{
		long	res = std::numeric_limits<int>::max();
		long diff = res;
		std::list<int>::const_iterator it = this->_contenair.begin();
		for (; it != this->_contenair.end(); ++it)
		{
			std::list<int>::const_iterator it2 = it;
			for (; it2 != this->_contenair.end(); ++it2)
			{
				if (it2 != it)
				{
					diff = std::max(*it, *it2) - std::min(*it, *it2);
					// std::cout << diff << std::endl;
					if (diff < res)
						res = diff;
				}
			}
		}
		return (res);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (-1);
}

long				Span::longestSpan(void) const
{
	if (this->getN() < 2)
		throw Span::ToShort(" for find the longest Span.");

	try
	{
		int	max = *(std::max_element(this->_contenair.begin(), this->_contenair.end()));
		int	min = *(std::min_element(this->_contenair.begin(), this->_contenair.end()));
		// std::cout << "max = " << max << std::endl << "min =" << min << std::endl;
		long	res = max - min;
		return (res);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (-1);
}

void				Span::addNumber(const int nbr)
{
	if (this->getN() == 0 || this->getPlace() == 0)
		throw Span::NoMorePlace() ;
	
	this->_place--;
	this->_contenair.push_back(nbr);
}


