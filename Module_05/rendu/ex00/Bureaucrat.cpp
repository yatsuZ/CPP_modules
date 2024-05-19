/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 17:24:03 by yzaoui            #+#    #+#             */
/*   Updated: 2024/05/20 00:13:25 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Bureaucrat.hpp"

void	Bureaucrat::_verif(void) const
{
	if (this->_grade > 150)
		throw GradeTooLowException();
	else if (this->_grade < 1)
		throw GradeTooHighException();
}

Bureaucrat::Bureaucrat(): _name("default_name"), _grade(150)
{
	std::cout << GREEN << "Constructor Bureaucrat call" << NOCOLOR << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name), _grade(150)
{
	// faire une exeception pour le grade
	std::cout << BLUE << "Constructor Parametric Bureaucrat call" << NOCOLOR << std::endl;
	try
	{
		this->_grade = grade;
		this->_verif();
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << this->_grade << " " << e.what() << NOCOLOR << std::endl;
		this->_grade = 150;
	}
}

Bureaucrat::Bureaucrat(Bureaucrat const &src)
{
	*this = src;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << MAGENTA << "Destructor Bureaucrat call" << NOCOLOR << std::endl;
}

Bureaucrat	&Bureaucrat::operator=(Bureaucrat const &src)
{
	if (this != &src)
		this->_grade = src._grade;
	return (*this);
}

const std::string	Bureaucrat::getName(void) const
{
	return (this->_name);
}

int	Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

void	Bureaucrat::showData(void) const
{
	std::cout << "----------------------" << std::endl;
	std::cout << "_name = " << this->getName() << std::endl;
	std::cout << "_grade = " << this->getGrade() << std::endl;
	std::cout << "----------------------" << std::endl;
}

void	Bureaucrat::setGrade(const int newGrade)
{
	int	sauvegarde = this->_grade;
	try
	{
		this->_grade = newGrade;
		this->_verif();
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << this->_grade << " " << e.what() << NOCOLOR << std::endl;
		this->_grade = sauvegarde;
	}
}

void	Bureaucrat::upGrade(void)
{
	this->setGrade(this->getGrade() - 1);
}

void	Bureaucrat::downGrade(void)
{
	this->setGrade(this->getGrade() + 1);
}

std::ostream	&operator<<( std::ostream & o, Bureaucrat const & rhs)
{
	o << YELLOW << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << "." << NOCOLOR;
	return o;
}