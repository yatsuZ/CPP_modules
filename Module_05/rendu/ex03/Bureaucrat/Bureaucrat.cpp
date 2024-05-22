/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 17:24:03 by yzaoui            #+#    #+#             */
/*   Updated: 2024/05/22 19:54:55 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../Form/Form.hpp"

void	Bureaucrat::_verif(void) const
{
	int	value = this->getGrade();
	if (value > LOWEST)
	{
		std::cout << value << std::endl;
		throw GradeTooLowException(this->getName());
	}
	else if (value < HIGHEST)
		throw GradeTooHighException(this->getName());
}

Bureaucrat::Bureaucrat(): _name("default_name"), _grade(150)
{
	std::cout << GREEN << "Constructor Bureaucrat call" << NOCOLOR << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name), _grade(150)
{
	// faire une exeception pour le grade
	std::cout << BLUE << "Constructor Parametric Bureaucrat call" << NOCOLOR << std::endl;
	this->_grade = grade;
	this->_verif();
}

Bureaucrat::Bureaucrat(Bureaucrat const &src): _name(src.getName()), _grade(src.getGrade())
{
	// std::cout << WHITE << "Constructor Copy Bureaucrat call" << NOCOLOR << std::endl;
	*this = src;
}

Bureaucrat::~Bureaucrat()
{
	// std::cout << MAGENTA << "Destructor Bureaucrat call" << NOCOLOR << std::endl;
}

Bureaucrat	&Bureaucrat::operator=(Bureaucrat const &src)
{
	if (this != &src)
	{
		this->_grade = src._grade;
	}
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
	this->_grade = newGrade;
	this->_verif();
}

void	Bureaucrat::upGrade(void)
{
	this->_grade--;
	this->_verif();
}

void	Bureaucrat::downGrade(void)
{
	this->_grade++;
	this->_verif();
}

void	Bureaucrat::signForm(Form &document)
{
	try
	{
		document.beSigned(*this);
		std::cout << *this << WHITE << " signed " << NOCOLOR << std::endl << document << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << *this << RED << " couldn’t sign " << NOCOLOR << std::endl << document << " " << RED << e.what() << NOCOLOR << std::endl;
		return ;
	}
}

void	Bureaucrat::executeForm(Form const & form)
{
	try
	{
		form.execute(*this);
		if (form.getSigned())
			std::cout << *this << GREEN << " EXECUTE " << NOCOLOR << std::endl << form << std::endl;
		else
			std::cout << *this << RED << " CAN'T EXECUTE " << NOCOLOR << std::endl << form << " Because it's not signed...."<< std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << *this << RED << " couldn’t EXECUTE " << NOCOLOR << std::endl << form << " " << RED << e.what() << NOCOLOR << std::endl;
	}
}

std::ostream	&operator<<( std::ostream & o, Bureaucrat const & rhs)
{
	o << YELLOW << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << "." << NOCOLOR;
	return o;
}
