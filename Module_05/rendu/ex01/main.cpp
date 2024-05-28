/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 17:23:19 by yzaoui            #+#    #+#             */
/*   Updated: 2024/05/28 15:52:12 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Form/Form.hpp"

void	bureaucratSigneForm(Form &Contrat, Bureaucrat &Manager)
{
	try
	{
		Contrat.beSigned(Manager);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void	step01(Form &Contrat, Bureaucrat &Manager)
{
	std::cout << std::endl;
	bureaucratSigneForm(Contrat, Manager);
	Manager.signForm(Contrat);
}

void	step02(Form &Contrat, Bureaucrat &Manager)
{
	for (int i = Manager.getGrade(); i > Contrat.getGradeSigned(); i--)
	{
		std::cout << MAGENTA << Manager.getName() << " work hard for elevate this status." << std::endl;
		Manager.upGrade();
		std::cout << Manager << std::endl;
	}
	bureaucratSigneForm(Contrat, Manager);
	Manager.signForm(Contrat);
}

int	main(void)
{
	std::cout << "Faire des tests" << std::endl;
	Form Contrat("Contrat", 25, 50);
	Bureaucrat Manager("Manager", 51);

	step01(Contrat, Manager);
	step02(Contrat, Manager);


	return (0);
}