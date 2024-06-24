/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 19:31:04 by yzaoui            #+#    #+#             */
/*   Updated: 2024/06/24 19:29:51 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(void):
_Expression(std::string()),
_contenaire(std::stack<long>())
{
}

static bool	isNumber(char c)
{
	return (c >= '0' && c <= '9');
}

static bool	isALegitCharacter(char c)
{
	if (isNumber(c))
		return false;
	else if (c == '*' || c == '/' || c == '-' || c == '+')
		return false;
	return true;
}

// doit verifier qu'il que de nombre compris entre 0 et 9 et des expression +-*/
// et tout les index paire des espace
void	RPN::_verifExpression(void) const
{
	size_t	j = 0;
	for (std::string::const_iterator i = this->_Expression.begin(); i != this->_Expression.end(); i++, j++)
	{
		if (!(j % 2) && isALegitCharacter(*i))
			throw std::invalid_argument(std::string("\'") + *i + std::string("\' n\'est pas légitime dans l'expression polonaise."));
		else if (j % 2 && *i != ' ')
		{
			if (isNumber(*i))
			{
				i--;
				if (*i == '-')
					throw std::invalid_argument("Le sujet ne précise pas s'il faut prendre en compte les nombres négatifs en entrée, donc par défaut, c'est non. >:(");
				i++;
			}
			throw std::invalid_argument(std::string("\'") + *i + std::string("\' doit être un espace."));
		}
	}
}

RPN::RPN(int argc, char **argv):
_Expression(""),
_contenaire(std::stack<long>())
{
	if (argc != 2)
		throw std::invalid_argument("Il faut exactement un argument.");
	this->_Expression = argv[1];
	this->_verifExpression();
}

RPN::RPN(const RPN &src):
_Expression(src._Expression),
_contenaire(std::stack<long>())
{
}

RPN &RPN::operator=(const RPN &src)
{
	if (this != &src)
	{
		this->_contenaire = std::stack<long>();
		this->_Expression = src._Expression;
	}
	return (*this);
}

RPN::~RPN(void)
{
}

void	RPN::showContenaire(void) const
{
	const std::string space = "\t\t\t\t";
	std::stack<long>	tmp = this->_contenaire;
	for (;!tmp.empty(); tmp.pop())
	{
		if (tmp.top() < -9)
			std::cout << space + "|" << tmp.top() << "|" << std::endl;
		else if (tmp.top() >= 10 || tmp.top() < 0)
			std::cout << space + "| " << tmp.top() << "|" << std::endl;
		else
			std::cout << space + "| " << tmp.top() << " |" << std::endl;
	}
	std::cout << space + "|___|" << std::endl;
	std::cout << "----------------------------" << std::endl;
}

void	RPN::show(bool all) const
{
	std::cout << GREEN "--- RPN INFO ----" NOCOLOR << std::endl;
	std::cout << "Expression = " << this->_Expression << std::endl;
	if (all)
	{
		std::cout << "_contenaire = " << std::endl;
		this->showContenaire();
	}
}

void	RPN::_adition(void)
{
	long	a = this->_contenaire.top();
	this->_contenaire.pop();
	long	b = this->_contenaire.top();
	this->_contenaire.pop();
	long	res = a + b;
	this->_contenaire.push(res);
}

void	RPN::_soustraction(void)
{
	long	a = this->_contenaire.top();
	this->_contenaire.pop();
	long	b = this->_contenaire.top();
	this->_contenaire.pop();
	long	res = b - a;
	this->_contenaire.push(res);
}

void	RPN::_multiplcation(void)
{
	long	a = this->_contenaire.top();
	this->_contenaire.pop();
	long	b = this->_contenaire.top();
	this->_contenaire.pop();
	long	res = a * b;
	this->_contenaire.push(res);
}

void	RPN::_division(void)
{
	long	a = this->_contenaire.top();
	this->_contenaire.pop();
	long	b = this->_contenaire.top();
	this->_contenaire.pop();
	if (a == 0)
		throw std::runtime_error("Impossible de diviser par zéro.");
	long	res = b / a;
	this->_contenaire.push(res);
}

void	RPN::exec(void)
{
	size_t	j = 0;
	for (std::string::const_iterator i = this->_Expression.begin(); i != this->_Expression.end(); i++, j++)
	{
		if (!(j % 2))
		{
			if (isNumber(*i))
				this->_contenaire.push(static_cast<int>(*i) - '0');
			else if (this->_contenaire.size() < 2)
				throw std::runtime_error("Impossible de prendre un opérateur s'il n'y a pas déjà deux valeurs.");
			else
			{
				if (*i == '+') this->_adition();
				else if (*i == '-') this->_soustraction();
				else if (*i == '*') this->_multiplcation();
				else if (*i == '/') this->_division();
			}
			// std::cout << "Loop : " << j << std::endl;
			// this->showContenaire();
		}
	}
	std::cout << this->_contenaire.top() << std::endl;// resultat
}
