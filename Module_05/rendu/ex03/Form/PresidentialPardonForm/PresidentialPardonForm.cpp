/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 15:00:21 by yzaoui            #+#    #+#             */
/*   Updated: 2024/05/22 19:50:31 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): Form::Form("PresidentialPardonForm", PRESIDENT_SIGN, PRESIDENT_EXEC), _target("UNKNOW")
{
}

PresidentialPardonForm::PresidentialPardonForm(const std::string target): Form::Form("PresidentialPardonForm", PRESIDENT_SIGN, PRESIDENT_EXEC), _target(target)
{
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &src): Form::Form("PresidentialPardonForm", PRESIDENT_SIGN, PRESIDENT_EXEC), _target(src.getTarget())
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
{
	double	delai = 1;
	sleep(delai);
	std::cout << "Zaphod Beeblebrox: " << MAGENTA << "Hello it's me MR PRESIDENT..." << NOCOLOR << std::endl;
	sleep(delai);
	std::cout << "Zaphod Beeblebrox: " << MAGENTA << "I saw the contract and I think someone deserves an apology So" << NOCOLOR << std::endl;
	sleep(delai);
	std::cout << "Zaphod Beeblebrox: " << GREEN << this->getTarget();
	std::cout.flush();
	sleep(delai);
	std::cout << " ARE";
	std::cout.flush();
	sleep(delai);
	std::cout << " excused ";
	std::cout.flush();
	sleep(delai);
	std::cout << "❤️";
	std::cout.flush();
	sleep(delai);
	std::cout << "❤️"<< NOCOLOR << std::endl;
	std::cout.flush();
	sleep(delai);
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
		nameWidth = ("| Name du Form : " + rhs.getName()).length();
		nameWidth += nameWidth % 2;
	}
	int signedWidth = 14;

	ss	<< std::endl;
	drawLigneTab(ss, nameWidth, signedWidth);
	ss	<< std::endl;

	ss	<< std::left << std::setw(nameWidth + signedWidth) << ("| Target : " + rhs.getTarget())
		<< "|" << std::endl;

	o << ss.str();

	o << static_cast<const Form &>(rhs);

	return o;
}
