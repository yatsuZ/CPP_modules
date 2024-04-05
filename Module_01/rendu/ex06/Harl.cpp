/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 03:04:05 by yzaoui            #+#    #+#             */
/*   Updated: 2024/04/05 14:43:21 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
}

Harl::~Harl()
{
}

void Harl::_debug() {
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger." << std::endl;
	std::cout << "I really do !" << std::endl;
}

void Harl::_info() {
	std::cout << "I cannot believe adding extra bacon costs more money." << std::endl;
	std::cout << "You didn’t put enough bacon in my burger ! If you did, I wouldn’t be asking for more !" << std::endl;
}

void Harl::_warning() {
	std::cout << "I think I deserve to have some extra bacon for free." << std::endl;
	std::cout << "I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::_error() {
	std::cout << "This is unacceptable ! I want to speak to the manager now." << std::endl;
}

void	Harl::complain(std::string level)
{
	int	choice = -1;
	const static std::string	tabStr[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (int i = 0; i < 4 && choice == -1; i++)
	{
		if (level == tabStr[i])
			choice = i;
	}
	switch (choice)
	{
	case -1:
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
		return;
	case 0:
		this->_litelFt(tabStr[choice++], &Harl::_debug);
	case 1:
		this->_litelFt(tabStr[choice++], &Harl::_info);
	case 2:
		this->_litelFt(tabStr[choice++], &Harl::_warning);
	case 3:
		this->_litelFt(tabStr[choice++], &Harl::_error);
	}
}

void	Harl::_litelFt(std::string level, void (Harl::*ft) (void))
{
	std::cout << "[ "<< level <<" ]" << std::endl;
	(this->*ft)();
	std::cout << std::endl;
}