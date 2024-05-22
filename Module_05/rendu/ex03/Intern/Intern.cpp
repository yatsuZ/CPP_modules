/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 16:14:55 by yzaoui            #+#    #+#             */
/*   Updated: 2024/05/22 19:54:13 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Intern.hpp"

Intern::Intern()
{
}

Intern::Intern(Intern const &src)
{
	*this = src;
}

Intern	&Intern::operator=(Intern const &src)
{
	(void)	src;
	return (*this);
}

Intern::~Intern()
{
}

static Form	*createFormPresidential(std::string target)
{
	return (new PresidentialPardonForm(target));
}

static Form	*createFormRobotomy(std::string target)
{
	return (new RobotomyRequestForm(target));
}

static Form	*createFormShrubbery(std::string target)
{
	return (new ShrubberyCreationForm(target));
}

Form	*Intern::makeForm(const std::string name, const std::string target)
{
	static Form* (*AllInit[3])(const std::string) = {createFormRobotomy, createFormShrubbery, createFormPresidential};
	static const std::string	AllName[3] = {"robotomy request", "shrubbery creation", "presidential pardon"};

	for (size_t i = 0; i < AllName->length(); i++)
	{
		if (AllName[i] == name)
		{
			Form	*res = AllInit[i](target);
			std::cout << "Intern creates " << std::endl << *res << std::endl;
			return (res);
		}
	}
	// Throw a exception
	throw	Intern::DontFindForm(name);
}
