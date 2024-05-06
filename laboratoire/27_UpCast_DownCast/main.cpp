/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 00:29:45 by yzaoui            #+#    #+#             */
/*   Updated: 2024/05/06 23:12:48 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Parent	{};
class Child1: public Parent {};
class Child2: public Parent {};

int	main(void)
{
	Child1		a;

	Parent *	b = &a;
	Parent *	c = (Parent *) &a;

	Parent *	d = &a;
	// Child1 *	e = d;
	Child1 *	e = (Child1 *) d;
	Child2 *	f = (Child2 *) d;

	return 0;
}