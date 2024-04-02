/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 19:34:46 by yzaoui            #+#    #+#             */
/*   Updated: 2024/04/02 02:00:03 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(): _end(true), _i(0)
{
}

PhoneBook::~PhoneBook()
{
}

void	PhoneBook::_exit()
{
	this->_end = false;
}

void	PhoneBook::_search()
{
	int			i;
	std::string	input;
	std::string cyan = "\033[36m";
	std::string no_color = "\033[0m";
	std::string magenta = "\033[35m";
	
	std::cout << magenta << "|";
	put_the_right_lenght("INDEX");
	put_the_right_lenght("FIRST NAME");
	put_the_right_lenght("LAST NAME");
	put_the_right_lenght("NICK NAME");
	std::cout << std::endl;

	for (size_t j = 0; j < 8; j++)
	{
		std::cout << cyan << "|";
		put_the_right_lenght(j);
		this->_repertoir[j].show_names();
		std::cout << std::endl << no_color;
	}
	while (!(input[0] >= '0' && input[0] <= '7'))
		input = get_input("Choose a INDEX: ");
	i = input[0] - '0';
	this->_repertoir[i].show_class();
}

void	PhoneBook::_add()
{
	this->_repertoir[this->_i].set_all();
	this->_i = (this->_i + 1) % 8;
}

void	PhoneBook::simulation()
{
	std::string	str;
	std::string no_color = "\033[0m";
	std::string red = "\033[31m";

	while (this->_end)
	{
		str = get_input("ADD, SEARCH or EXIT: ");
		if (str == "ADD")
			this->_add();
		else if (str == "SEARCH")
			this->_search();
		else if (str == "EXIT")
			this->_exit();
		else
			std::cout << red << "... pls choose one off this input :" << no_color << std::endl;
	}
}

