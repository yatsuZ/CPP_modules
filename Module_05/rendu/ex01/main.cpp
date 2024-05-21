/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 17:23:19 by yzaoui            #+#    #+#             */
/*   Updated: 2024/05/21 14:46:42 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Form/Form.hpp"

void	step01(Form &Contrat, Bureaucrat &Manager)
{
	std::cout << std::endl;
	Manager.bureaucratTryToSigneAForm(Contrat);
}

void	step02(Form &Contrat, Bureaucrat &Manager)
{
	std::cout << std::endl;
	Manager.setGrade(24);
	Manager.bureaucratTryToSigneAForm(Contrat);
}

void	step03(Form &Contrat, Bureaucrat &Manager)
{
	std::cout << std::endl;
	Manager.downGrade();
	Manager.downGrade();
	Manager.bureaucratTryToSigneAForm(Contrat);
}

int	main(void)
{
	std::cout << "Faire des tests" << std::endl;
	Form Contrat("Contrat", 50, 25);
	Bureaucrat Manager("Manager", 150);

	step01(Contrat, Manager);
	step02(Contrat, Manager);
	step03(Contrat, Manager);

	std::cout << Manager << std::endl;

	return (0);
}