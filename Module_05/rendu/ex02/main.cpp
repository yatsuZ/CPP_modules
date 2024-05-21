/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 17:23:19 by yzaoui            #+#    #+#             */
/*   Updated: 2024/05/22 01:35:31 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./AForm/PresidentialPardonForm/PresidentialPardonForm.hpp"
#include "./AForm/RobotomyRequestForm/RobotomyRequestForm.hpp"
#include "./AForm/ShrubberyCreationForm/ShrubberyCreationForm.hpp"


int	main(void)
{
	std::cout << "Faire PresidentialPardonForm et le pimpe" << std::endl;
	PresidentialPardonForm	test("MR.President");
	std::cout << "Faire RobotomyRequestForm" << std::endl;
	std::cout << "Faire ShrubberyCreationForm" << std::endl;

	std::cout << test << std::endl;
	return (0);
}