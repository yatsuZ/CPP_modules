/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 14:59:49 by yzaoui            #+#    #+#             */
/*   Updated: 2024/05/22 19:50:38 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(): Form::Form("RobotomyRequestForm", ROBOT_SIGN, ROBOT_EXEC), _target("UNKNOW")
{
}

RobotomyRequestForm::RobotomyRequestForm(const std::string target): Form::Form("RobotomyRequestForm", ROBOT_SIGN, ROBOT_EXEC), _target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &src): Form::Form("RobotomyRequestForm", ROBOT_SIGN, ROBOT_EXEC), _target(src.getTarget())
{
	*this = src;
}

RobotomyRequestForm	&RobotomyRequestForm::operator=(RobotomyRequestForm const &src)
{
	(void)	src;
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

static void	drillingNoises(double delai)
{
	std::cout << YELLOW << "🤖BZZZZT VREEEEM " << NOCOLOR;
	std::cout.flush();
	sleep(delai);
	std::cout << YELLOW << "🤖ZZZRRR KRRRREEEK " << NOCOLOR;
	std::cout.flush();
	sleep(delai);
	std::cout << YELLOW << "🤖BZZZ WHIRRRR " << NOCOLOR;
	std::cout.flush();
	sleep(delai);
	std::cout << YELLOW << "🤖BIBIBIPPPPPPP BOUP " << NOCOLOR << std::endl;
	std::cout.flush();
	sleep(delai);

}

//Faire des bruit de rabo puis une chance sur affiche un message sinon un autre message 
void	RobotomyRequestForm::actionExecute() const
{
	double	delai = 1;
	drillingNoises(delai);
	std::srand(std::time(0));
	bool pileFace = std::rand() % 2;
	if (pileFace)
		std::cout << GREEN << this->getTarget() << " has been robotomized🤖." << NOCOLOR << std::endl;
	else
		std::cout << RED << this->getTarget() << " robotomized🤖 FAILED..." << NOCOLOR << std::endl;
	sleep(delai);
}

const std::string	RobotomyRequestForm::getTarget(void) const
{
	return (this->_target);
}

std::ostream & operator<<(std::ostream & o, RobotomyRequestForm const & rhs)
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
