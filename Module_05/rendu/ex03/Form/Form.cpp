/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 19:41:51 by yzaoui            #+#    #+#             */
/*   Updated: 2024/05/22 19:43:13 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Form.hpp"

Form::Form(void): _name("DefaultName"), _signed(false), _gradeSigned(150), _gradeExecuted(1)
{
	// std::cout << GREEN << "Constructor Form call" << NOCOLOR << std::endl;
}

Form::Form(Form const &src):_name(src.getName()), _signed(src.getSigned()), _gradeSigned(src.getGradeSigned()), _gradeExecuted(src.getGradeExecuted())
{
	// std::cout << WHITE << "Constructor Copy Form call" << NOCOLOR << std::endl;
	*this = src;
}

Form				&Form::operator=(Form const &src)
{
	if (this != &src)
		this->_signed = src.getSigned();
	return (*this);
}

Form::~Form()
{
	// std::cout << MAGENTA << "Destructor Form call" << NOCOLOR << std::endl;
}


Form::Form(std::string name, int gradeSigned, int radeExecuted): _name(name), _signed(false), _gradeSigned(gradeSigned), _gradeExecuted(radeExecuted)
{
	// faire une exeception pour le grade
	// std::cout << BLUE << "Constructor Parametric Form call" << NOCOLOR << std::endl;
	this->_verifs();
}

/////////////////////////////////////////

int	Form::_verifExecuted(void) const
{
	if (this->_gradeExecuted > LOWEST)
		return (1);
	else if (this->_gradeExecuted < HIGHEST)
		return (2);
	return (0);
}

int	Form::_verifSigned(void) const
{
	if (this->_gradeSigned > LOWEST)
		return (1);
	else if (this->_gradeSigned < HIGHEST)
		return (2);
	return (0);
}

void	Form::_verifs(void) const
{
	int	var_executed = this->_verifExecuted();
	int	var_signed = this->_verifSigned();
	if (var_executed == 1 || var_signed == 1)
		throw Form::GradeTooLowException(this->getName());
	if (var_executed == 2 || var_signed == 2)
		throw Form::GradeTooHighException(this->getName());
}

const std::string	Form::getName(void) const
{
	return (this->_name);
}

bool				Form::getSigned(void) const
{
	return (this->_signed);
}

int			Form::getGradeSigned(void) const
{
	return (this->_gradeSigned);
}

int			Form::getGradeExecuted(void) const
{
	return (this->_gradeExecuted);
}

//////////////////////////////////////////////////////

void	Form::_signedTrue(void)
{
	this->_signed = true;
}

void	Form::beSigned(Bureaucrat signer)
{
	if (signer.getGrade() > this->getGradeSigned())
		throw Form::GradeTooLowException(signer.getName());
	else
		this->_signedTrue();
}

void	Form::execute(Bureaucrat const & executor) const
{
	
	if (executor.getGrade() > this->getGradeExecuted())
		throw Form::GradeTooLowException(executor.getName());
	if (this->getSigned())
		this->actionExecute();
}

void	drawLigneTab(std::stringstream &ss, int firstColone, int secondColone)
{

	ss	<< "+" << std::string(firstColone - 1, '-');
	ss	<< "+" << std::string(secondColone - 1, '-') << "+";
}

std::ostream & operator<<(std::ostream & o, Form const & rhs)
{
	std::stringstream ss;

	// Définir les largeurs de colonnes
	int nameWidth = 50;
	if (("| Name du Form : " + rhs.getName()).length() > static_cast<size_t>(nameWidth))
	{
		nameWidth = ("| Name du Form : " + rhs.getName()).length();
		nameWidth += nameWidth % 2;
	}
	int signedWidth = 14;
	int gradeWidth = nameWidth / 2;

	drawLigneTab(ss, nameWidth, signedWidth);
	ss	<< std::endl;

	// Entête du tableau
	ss	<< std::left << std::setw(nameWidth) << ("| Name du Form : " + rhs.getName())
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