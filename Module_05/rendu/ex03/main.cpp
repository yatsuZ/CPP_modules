/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 17:23:19 by yzaoui            #+#    #+#             */
/*   Updated: 2024/05/22 19:07:21 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Intern/Intern.hpp"

void	testAForm(Bureaucrat &sigateur, Bureaucrat &executeur, AForm *Form)
{
	sigateur.signForm(*Form);
	executeur.executeForm(*Form);
}

void	test1(void)
{
	Intern		someRandomIntern;
	Bureaucrat Signateur("Signateur", 1);
	Bureaucrat Executeur("Executeur", 25);

	testAForm(Signateur, Executeur, someRandomIntern.makeForm("presidential pardon", "Gracieur"));
	std::cout << std::endl << "----------------------" << std::endl << std::endl;
	testAForm(Signateur, Executeur, someRandomIntern.makeForm("robotomy request", "Bender"));
	std::cout << std::endl << "----------------------" << std::endl << std::endl;
	testAForm(Signateur, Executeur, someRandomIntern.makeForm("shrubbery creation", "Gaya"));
	try
	{
		testAForm(Signateur, Executeur, someRandomIntern.makeForm("IDK", "Crash"));
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void	test0(void)
{
	Intern someRandomIntern;
	AForm* rrf;
	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	(void) rrf;
}

int	main(void)
{
	test0();
	test1();
	return (0);
}