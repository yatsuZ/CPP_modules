/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   folowingFunction.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 20:43:28 by yzaoui            #+#    #+#             */
/*   Updated: 2024/05/30 13:59:53 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Base/A/A.hpp"
#include "./Base/B/B.hpp"
#include "./Base/C/C.hpp"
#include "folowingFunction.hpp"

int	generateARandom(int range)
{
	return (std::rand() % range);
}

static Base	*createA(void)
{
	return (new A());
}

static Base	*createB(void)
{
	return (new B());
}

static Base	*createC(void)
{
	return (new C());
}

Base	*generate(void)
{
	static Base* (*AllInit[3])(void) = {createA, createB, createC};
	return (AllInit[generateARandom(3)]());
}

void	identify(Base *p)
{
	if (dynamic_cast<A*>(p))
		std::cout << YELLOW << "point p is a Type: A";
	else if (dynamic_cast<B*>(p))
		std::cout << GREEN << "point p is a Type: B";
	else if (dynamic_cast<C*>(p))
		std::cout << BLUE << "point p is a Type: C";
	else
		std::cout << RED << "Unknown type";
	std::cout << NOCOLOR << std::endl;
}

void	identify(Base &p)
{
	try
	{
		A	&crash_test = dynamic_cast<A&>(p);
		(void)	crash_test;
		std::cout << YELLOW << "point p is a Type: A";
		std::cout << NOCOLOR << std::endl;
		return ;
	}
	catch(const std::exception& e)
	{
	}
	try
	{
		B	&crash_test = dynamic_cast<B&>(p);
		(void)	crash_test;
		std::cout << GREEN << "point p is a Type: B";
		std::cout << NOCOLOR << std::endl;
		return ;
	}
	catch(const std::exception& e)
	{
	}
	try
	{
		C	&crash_test = dynamic_cast<C&>(p);
		(void)	crash_test;
		std::cout << BLUE << "point p is a Type: C";
		std::cout << NOCOLOR << std::endl;
		return ;
	}
	catch(const std::exception& e)
	{
	}
	std::cout << MAGENTA << "Unknown type";
	std::cout << NOCOLOR << std::endl;
}
