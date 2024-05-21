/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 15:00:21 by yzaoui            #+#    #+#             */
/*   Updated: 2024/05/22 01:35:19 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): AForm::AForm("PresidentialPardonForm", SIGN, EXEC), _target("UNKNOW")
{
}

PresidentialPardonForm::PresidentialPardonForm(const std::string target): AForm::AForm("PresidentialPardonForm", SIGN, EXEC), _target(target + "_shrubbery")
{
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &src): AForm::AForm("PresidentialPardonForm", SIGN, EXEC), _target(src.getTarget())
{
	*this = src;
}

PresidentialPardonForm	&PresidentialPardonForm::operator=(PresidentialPardonForm const &src)
{
	(void)	src;
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

//Informe que <target> a été graciée par Zaphod Beeblebrox
void	PresidentialPardonForm::actionExecute() const
{// avec des sleep pimpe
	std::cout << GREEN << "The target " << this->getTarget() << " has been pardoned by Zaphod Beeblebrox." << NOCOLOR << std::endl;
}

const std::string	PresidentialPardonForm::getTarget(void) const
{
	return (this->_target);
}

std::ostream & operator<<(std::ostream & o, PresidentialPardonForm const & rhs)
{
	std::stringstream ss;

	int nameWidth = 50;
	if (("| Target file : " + rhs.getName()).length() > static_cast<size_t>(nameWidth))
	{
		nameWidth = ("| Name du AForm : " + rhs.getName()).length();
		nameWidth += nameWidth % 2;
	}
	int signedWidth = 14;

	ss	<< std::endl;
	drawLigneTab(ss, nameWidth, signedWidth);
	ss	<< std::endl;

	ss	<< std::left << std::setw(nameWidth + signedWidth) << ("| Target : " + rhs.getTarget())
		<< "|" << std::endl;

	o << ss.str();

	o << static_cast<const AForm &>(rhs);

	return o;
}
