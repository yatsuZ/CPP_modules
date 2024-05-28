/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 17:23:19 by yzaoui            #+#    #+#             */
/*   Updated: 2024/05/28 16:21:28 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Intern/Intern.hpp"

void	testForm(Bureaucrat &signateur, Bureaucrat &executeur, Form *contract)
{
	// signateur.signForm(*contract);
	(*contract).beSigned(signateur);
	executeur.executeForm(*contract);
	delete	contract;
}

void	test1(void)
{
	Intern		someRandomIntern;
	Bureaucrat Signateur("Signateur", 1);
	Bureaucrat Executeur("Executeur", 5);

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