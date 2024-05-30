/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 17:08:47 by yzaoui            #+#    #+#             */
/*   Updated: 2024/05/30 20:08:17 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

#include <exception>
#include <iostream>

template<typename T>
void	swap(T &a, T &b)
{
	try
	{
		T	c;

		c = a;
		a = b;
		b = c;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

template<typename T>
T	min(T a, T b)
{
	try
	{
		return (a < b ? a : b);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (a);
}

template<typename T>
T	max(T a, T b)
{
	try
	{
		return (a > b ? a : b);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (a);
}


#endif