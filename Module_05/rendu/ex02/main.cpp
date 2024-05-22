/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 17:23:19 by yzaoui            #+#    #+#             */
/*   Updated: 2024/05/22 17:52:15 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./AForm/PresidentialPardonForm/PresidentialPardonForm.hpp"
#include "./AForm/RobotomyRequestForm/RobotomyRequestForm.hpp"
#include "./AForm/ShrubberyCreationForm/ShrubberyCreationForm.hpp"

void	testPresidentialPardonForm(Bureaucrat &sigateur, Bureaucrat &executeur)
{
	PresidentialPardonForm	Form("MR.President");
	sigateur.signForm(Form);
	executeur.executeForm(Form);
}

void	testRobotomyRequestForm(Bureaucrat &sigateur, Bureaucrat &executeur)
{
	// REF A DOCTOR WHO
	RobotomyRequestForm	Form("CYBERMAN");
	sigateur.signForm(Form);
	executeur.executeForm(Form);
}

void	testShrubberyCreationForm(Bureaucrat &sigateur, Bureaucrat &executeur)
{
	ShrubberyCreationForm	Form("tree");
	sigateur.signForm(Form);
	executeur.executeForm(Form);
}

int	main(void)
{
	Bureaucrat Signateur("Signateur", 1);
	Bureaucrat Executeur("Executeur", 25);

	testPresidentialPardonForm(Signateur, Executeur);
	std::cout << std::endl << "----------------------" << std::endl << std::endl;
	testRobotomyRequestForm(Signateur, Executeur);
	std::cout << std::endl << "----------------------" << std::endl << std::endl;
	testShrubberyCreationForm(Signateur, Executeur);

	return (0);
}