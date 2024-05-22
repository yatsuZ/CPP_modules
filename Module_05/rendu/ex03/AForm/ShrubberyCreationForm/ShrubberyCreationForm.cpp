/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 14:59:07 by yzaoui            #+#    #+#             */
/*   Updated: 2024/05/22 16:04:54 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(): AForm::AForm("ShrubberyCreationForm", SHRUBBERY_SIGN, SHRUBBERY_EXEC), _target("UNKNOW")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target): AForm::AForm("ShrubberyCreationForm", SHRUBBERY_SIGN, SHRUBBERY_EXEC), _target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &src): AForm::AForm("ShrubberyCreationForm", SHRUBBERY_SIGN, SHRUBBERY_EXEC), _target(src.getTarget())
{
	*this = src;
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(ShrubberyCreationForm const &src)
{
	(void)	src;
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

static void printTree(std::ofstream &outfile)
{
	const int width = 16;
	const int trunkHeight = 2;
	std::srand(std::time(0));
	bool pileFace = std::rand() % 2;

	for (int i = 0; i < width / 2; ++i) 
	{
		if (pileFace)
			outfile << std::string(width / 2 - i, ' ') << std::string(2 * i, '/') << "\\\\" << std::endl;
		else
			outfile << std::string(width / 2 - i, ' ') << "//" << std::string(2 * i, ' ') << "\\\\" << std::endl;
	}

	for (int i = 0; i < trunkHeight; ++i) {
		outfile << std::string(width / 2, ' ') << "|||" << std::endl;
	}
}

// cree un fichier target + "_shrubbery" et faire un arbre en ASCII
void	ShrubberyCreationForm::actionExecute() const
{
	std::string		nameFile((this->getTarget() + "_shrubbery"));
	std::ofstream	shrubbery(nameFile.c_str());
	printTree(shrubbery);
}

const std::string	ShrubberyCreationForm::getTarget(void) const
{
	return (this->_target);
}

std::ostream & operator<<(std::ostream & o, ShrubberyCreationForm const & rhs)
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
