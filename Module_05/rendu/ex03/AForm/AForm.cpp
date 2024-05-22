/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 14:58:21 by yzaoui            #+#    #+#             */
/*   Updated: 2024/05/22 19:07:50 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./AForm.hpp"

AForm::AForm(void): _name("DefaultName"), _signed(false), _gradeSigned(150), _gradeExecuted(1)
{
	// std::cout << GREEN << "Constructor AForm call" << NOCOLOR << std::endl;
}

AForm::AForm(AForm const &src):_name(src.getName()), _signed(src.getSigned()), _gradeSigned(src.getGradeSigned()), _gradeExecuted(src.getGradeExecuted())
{
	// std::cout << WHITE << "Constructor Copy AForm call" << NOCOLOR << std::endl;
	*this = src;
}

AForm				&AForm::operator=(AForm const &src)
{
	if (this != &src)
		this->_signed = src.getSigned();
	return (*this);
}

AForm::~AForm()
{
	// std::cout << MAGENTA << "Destructor AForm call" << NOCOLOR << std::endl;
}


AForm::AForm(std::string name, int gradeSigned, int radeExecuted): _name(name), _signed(false), _gradeSigned(gradeSigned), _gradeExecuted(radeExecuted)
{
	// faire une exeception pour le grade
	// std::cout << BLUE << "Constructor Parametric AForm call" << NOCOLOR << std::endl;
	this->_verifs();
}

/////////////////////////////////////////

int	AForm::_verifExecuted(void) const
{
	if (this->_gradeExecuted > LOWEST)
		return (1);
	else if (this->_gradeExecuted < HIGHEST)
		return (2);
	return (0);
}

int	AForm::_verifSigned(void) const
{
	if (this->_gradeSigned > LOWEST)
		return (1);
	else if (this->_gradeSigned < HIGHEST)
		return (2);
	return (0);
}

void	AForm::_verifs(void) const
{
	int	var_executed = this->_verifExecuted();
	int	var_signed = this->_verifSigned();
	if (var_executed == 1 || var_signed == 1)
		throw AForm::GradeTooLowException(this->getName());
	if (var_executed == 2 || var_signed == 2)
		throw AForm::GradeTooHighException(this->getName());
}

const std::string	AForm::getName(void) const
{
	return (this->_name);
}

bool				AForm::getSigned(void) const
{
	return (this->_signed);
}

int			AForm::getGradeSigned(void) const
{
	return (this->_gradeSigned);
}

int			AForm::getGradeExecuted(void) const
{
	return (this->_gradeExecuted);
}

//////////////////////////////////////////////////////

void	AForm::_signedTrue(void)
{
	this->_signed = true;
}

void	AForm::beSigned(Bureaucrat signer)
{
	if (signer.getGrade() > this->getGradeSigned())
		throw AForm::GradeTooLowException(signer.getName());
	else
		this->_signedTrue();
}

void	AForm::execute(Bureaucrat const & executor) const
{
	
	if (executor.getGrade() > this->getGradeExecuted())
		throw AForm::GradeTooLowException(executor.getName());
	if (this->getSigned())
		this->actionExecute();
}

void	drawLigneTab(std::stringstream &ss, int firstColone, int secondColone)
{

	ss	<< "+" << std::string(firstColone - 1, '-');
	ss	<< "+" << std::string(secondColone - 1, '-') << "+";
}

std::ostream & operator<<(std::ostream & o, AForm const & rhs)
{
	std::stringstream ss;

	// Définir les largeurs de colonnes
	int nameWidth = 50;
	if (("| Name du AForm : " + rhs.getName()).length() > static_cast<size_t>(nameWidth))
	{
		nameWidth = ("| Name du AForm : " + rhs.getName()).length();
		nameWidth += nameWidth % 2;
	}
	int signedWidth = 14;
	int gradeWidth = nameWidth / 2;

	drawLigneTab(ss, nameWidth, signedWidth);
	ss	<< std::endl;

	// Entête du tableau
	ss	<< std::left << std::setw(nameWidth) << ("| Name du AForm : " + rhs.getName())
		<< std::setw(signedWidth) << "| Is Signed ? "
		<< "|" << std::endl;

	drawLigneTab(ss, nameWidth, signedWidth);
	ss	<< std::endl;

	// Ligne des titres de grade
	ss	<< std::setw(gradeWidth) << "| GradeSigned"
		<< std::setw(gradeWidth) << "| GradeExecuted"
		<< std::setw(signedWidth) << "|"
		<< "|" << std::endl;

	ss	<< "|" << std::string(gradeWidth - 1, '-')
		<< "|" << std::string(gradeWidth - 1, '-');
	int	dif = rhs.getSigned() ? std::string(GREEN).length() : std::string(RED).length();
	std::string signedStatus = rhs.getSigned() ? std::string(GREEN) + "Yes": std::string(RED) + "No";
	ss << "| " << std::setw(signedWidth + dif - 2) << std::left << ("    " + signedStatus)
		<< NOCOLOR << "|" << std::endl;

	// Ligne des valeurs de grade
	ss 	<< "| "<< std::setw(gradeWidth - 2) << rhs.getGradeSigned()
		<< "| "<< std::setw(gradeWidth - 2) << rhs.getGradeExecuted()
		<< std::setw(signedWidth) << "|"
		<< "|" << std::endl;

	drawLigneTab(ss, nameWidth, signedWidth);

	// Ajouter les lignes au flux de sortie
	o << ss.str() << " ";

	return o;
}