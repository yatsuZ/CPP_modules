/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 17:23:19 by yzaoui            #+#    #+#             */
/*   Updated: 2024/05/20 00:20:11 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Bureaucrat.hpp"

void	upUpDown(Bureaucrat &test)
{
	test.upGrade();
	test.upGrade();
	test.downGrade();
}

void	downDownUp(Bureaucrat &test)
{
	test.downGrade();
	test.downGrade();
	test.upGrade();
}

int	main(void)
{
	Bureaucrat	First("First", 1);
	Bureaucrat	Last("Last", 150);
	Bureaucrat	Idk("Idk", -10);

	std::cout << First << std::endl << Last << std::endl << Idk << std::endl;
	upUpDown(First);
	upUpDown(Last);
	upUpDown(Idk);
	std::cout << First << std::endl << Last << std::endl << Idk << std::endl;
	downDownUp(First);
	downDownUp(Last);
	downDownUp(Idk);
	std::cout << First << std::endl << Last << std::endl << Idk << std::endl;
	return (0);
}