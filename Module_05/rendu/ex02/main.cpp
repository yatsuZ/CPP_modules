/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 17:23:19 by yzaoui            #+#    #+#             */
/*   Updated: 2024/05/28 16:12:25 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./AForm/PresidentialPardonForm/PresidentialPardonForm.hpp"
#include "./AForm/RobotomyRequestForm/RobotomyRequestForm.hpp"
#include "./AForm/ShrubberyCreationForm/ShrubberyCreationForm.hpp"

void	testPresidentialPardonForm(Bureaucrat &signateur, Bureaucrat &executeur)
{
	PresidentialPardonForm	Form("MR.President");
	Form.beSigned(signateur);
	signateur.signForm(Form);
	executeur.executeForm(Form);
}

void	testRobotomyRequestForm(Bureaucrat &signateur, Bureaucrat &executeur)
{
	// REF A DOCTOR WHO
	RobotomyRequestForm	Form("CYBERMAN");
	Form.beSigned(signateur);
	executeur.executeForm(Form);
}

void	testShrubberyCreationForm(Bureaucrat &signateur, Bureaucrat &executeur)
{
	ShrubberyCreationForm	Form("tree");
	Form.beSigned(signateur);
	executeur.executeForm(Form);
}

int	main(void)
{
	Bureaucrat Signateur("Signateur", 1);
	Bureaucrat Executeur("Executeur", 1);

	testPresidentialPardonForm(Signateur, Executeur);
	std::cout << std::endl << "----------------------" << std::endl << std::endl;
	testRobotomyRequestForm(Signateur, Executeur);
	std::cout << std::endl << "----------------------" << std::endl << std::endl;
	testShrubberyCreationForm(Signateur, Executeur);

	return (0);
}