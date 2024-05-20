/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 17:23:19 by yzaoui            #+#    #+#             */
/*   Updated: 2024/05/20 19:41:52 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Bureaucrat.hpp"

void	upUpDown(Bureaucrat &test)
{
	try
	{
		test.upGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << NOCOLOR << std::endl;
	}
	try
	{
		test.upGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << NOCOLOR << std::endl;
	}
	try
	{
		test.downGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << NOCOLOR << std::endl;
	}
}

void	downDownUp(Bureaucrat &test)
{
	try
	{
		test.downGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << NOCOLOR << std::endl;
	}
	try
	{
		test.downGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << NOCOLOR << std::endl;
	}
	try
	{
		test.upGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << NOCOLOR << std::endl;
	}
}

Bureaucrat	ft_test_00(void)
{
	Bureaucrat Idk;
	try
	{
		Bureaucrat Idk("Idk", -10);
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << NOCOLOR << std::endl;
	}
	return (Idk);
}

void	ft_test_01(Bureaucrat First, Bureaucrat Last, Bureaucrat Idk)
{
	upUpDown(First);
	upUpDown(Last);
	upUpDown(Idk);
}

void	ft_test_02(Bureaucrat First, Bureaucrat Last, Bureaucrat Idk)
{
	downDownUp(First);
	downDownUp(Last);
	downDownUp(Idk);
}

void	ft_test_03(void)
{
	Bureaucrat	First("First", 1);
	Bureaucrat	Last("Last", 150);
	Bureaucrat	Idk = ft_test_00();
	std::cout << First << std::endl << Last << std::endl << Idk << std::endl;
	
	ft_test_01(First, Last, Idk);
	std::cout << First << std::endl << Last << std::endl << Idk << std::endl;
	
	ft_test_02(First, Last, Idk);
	std::cout << First << std::endl << Last << std::endl << Idk << std::endl;
}

void	ft_test_04(void)
{
	Bureaucrat	truc01;
	Bureaucrat	truc02("Truc02", 75);
	Bureaucrat	truc03(truc02);
	try
	{
		truc03.setGrade(-150);
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << NOCOLOR << std::endl;
	}
	
	std::cout << truc01 << std::endl;
	std::cout << truc02 << std::endl;
	std::cout << truc03 << std::endl;
}

int	main(void)
{
	// ft_test_03();
	ft_test_04();
	return (0);
}