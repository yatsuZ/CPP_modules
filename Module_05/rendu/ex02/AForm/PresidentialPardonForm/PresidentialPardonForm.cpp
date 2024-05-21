/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 15:00:21 by yzaoui            #+#    #+#             */
/*   Updated: 2024/05/21 19:41:10 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): AForm::AForm("PresidentialPardonForm", SIGN, EXEC), _target("UNKNOW")
{
}

PresidentialPardonForm::PresidentialPardonForm(const std::string target): AForm::AForm("PresidentialPardonForm", SIGN, EXEC), _target(target)
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

void	PresidentialPardonForm::beSigned(Bureaucrat signer)
{
	const int	gradeOfSigner = signer.getGrade();
	const int	minimalGradeForSigne = this->getGradeSigned();
	const int	maximalGradeForSigne = this->getGradeExecuted();
	
	if (gradeOfSigner > minimalGradeForSigne)
		throw GradeTooLowException(signer.getName());
	if (gradeOfSigner > maximalGradeForSigne)
		std::cout << "Je ne sais pas quoi faire ??" << std::endl;// ???????????
}

const std::string	PresidentialPardonForm::getTarget(void) const
{
	return (this->_target);
}

std::ostream & operator<<(std::ostream & o, PresidentialPardonForm const & rhs)
{
	std::stringstream ss;

	int nameWidth = 50;
	if (("| Name du AForm : " + rhs.getName()).length() > static_cast<size_t>(nameWidth))
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
