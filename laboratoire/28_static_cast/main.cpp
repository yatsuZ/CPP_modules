/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 00:29:45 by yzaoui            #+#    #+#             */
/*   Updated: 2024/05/07 00:13:30 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



int	exemple1(void)
{
	int		a = 42;

	double	b = a;
	// int		c = b;
	int		d = static_cast<int>(b); // caster en c++

	return 0;
}

#include <iostream>

class Parent	{};
class Child1: public Parent {};
class Child2: public Parent {};

class Unrelated				{};

int	exemple2(void)
{
	Child1		a;

	Parent *	b = &a;
	// Child1 *	c = b;
	Child2 *	d = static_cast<Child2 *>(b);
	// Unrelated *	e = static_cast<Unrelated *>(&a);

	return 0;
}

int	main(void)
{
	exemple1();
	exemple2();
	return (0);
}