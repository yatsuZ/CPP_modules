/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 17:23:19 by yzaoui            #+#    #+#             */
/*   Updated: 2024/05/22 20:01:29 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Intern/Intern.hpp"

void	testForm(Bureaucrat &sigateur, Bureaucrat &executeur, Form *contract)
{
	sigateur.signForm(*contract);
	executeur.executeForm(*contract);
	delete	contract;
}

void	test1(void)
{
	Intern		someRandomIntern;
	Bureaucrat Signateur("Signateur", 1);
	Bureaucrat Executeur("Executeur", 25);

	testForm(Signateur, Executeur, someRandomIntern.makeForm("presidential pardon", "Gracieur"));
	std::cout << std::endl << "----------------------" << std::endl << std::endl;
	testForm(Signateur, Executeur, someRandomIntern.makeForm("robotomy request", "Bender"));
	std::cout << std::endl << "----------------------" << std::endl << std::endl;
	testForm(Signateur, Executeur, someRandomIntern.makeForm("shrubbery creation", "Gaya"));
	try
	{
		testForm(Signateur, Executeur, someRandomIntern.makeForm("IDK", "Crash"));
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void	test0(void)
{
	Intern someRandomIntern;
	Form* rrf;
	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	delete rrf;
	(void) rrf;
}

// Probleme avec AForm et Form pour sadapter aux exemple...

int	main(void)
{
	test0();
	test1();
	return (0);
}