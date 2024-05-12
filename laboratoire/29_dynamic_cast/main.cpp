/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 00:29:45 by yzaoui            #+#    #+#             */
/*   Updated: 2024/05/12 16:39:36 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <typeinfo>
#include <exception>

#define BLEU "\x1B[34m"
#define JAUNE "\x1B[33m"
#define NOCOLOR "\x1B[0m"
#define VERT "\x1B[32m"
#define ROUGE "\x1B[31m"


class Parent	{ public: virtual ~Parent( void ) {}};
class Child1: public Parent {};
class Child2: public Parent {};

void	child1_to_child1(void)
{
	Child1	a;
	Parent	*b = &a;
	Child1	*c;
	try
	{
		c = dynamic_cast<Child1 *>(b);
	}
	catch(const std::bad_cast& bc)
	{
		c = NULL;
		std::cout << ROUGE << "Conversion is NOT OK: " << JAUNE << bc.what() << NOCOLOR << std::endl;
	}
	if (c == NULL)
		std::cout << ROUGE << "Conversion is NOT OK" << NOCOLOR << std::endl;
	else
		std::cout << BLEU << "Conversion is OK" << NOCOLOR << std::endl;

}

void	child1_to_child2(void)
{
	Child1	a;
	Parent	*b = &a;

	try
	{
		// reference ne peut pas etre null
		Child2 & d = dynamic_cast<Child2 &>(*b);// Child1 -> Parent	* -> Child2 & | ERROR
		std::cout << BLEU << "Conversion is OK" << NOCOLOR << std::endl;
	}
	catch(const std::bad_cast& bc)
	{
		std::cout << ROUGE << "Conversion is NOT OK: " << JAUNE << bc.what() << NOCOLOR << std::endl;
	}
}

int	main(void)
{
	child1_to_child1();
	child1_to_child2();
	return (0);
}