/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 19:01:59 by yzaoui            #+#    #+#             */
/*   Updated: 2024/05/30 22:32:21 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

#include <string>
#include <iostream>

#define NOCOLOR "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"

template<typename T>
void	iter(T *tab, size_t lenght, void (*f)(T))
{
	if (!tab)
		return ;
	try
	{
		for (size_t i = 0; i < lenght; i++)
		{
			f(tab[i]);
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
};

template<typename T>
void	iter(T *tab, size_t lenght, void (*f)(T&))
{
	if (!tab)
		return ;
	try
	{
		for (size_t i = 0; i < lenght; i++)
			f(tab[i]);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
};

template<typename T>
void	iter(T **tab, size_t lenght, void (*f)(T))
{
	if (!tab)
		return ;
	try
	{
		iter(*tab, lenght, f);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
};

template<typename T>
void	Show(const T var)
{
	try
	{
		std::cout << var << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
};

#endif