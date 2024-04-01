/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 17:03:13 by yzaoui            #+#    #+#             */
/*   Updated: 2024/04/01 03:16:48 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

// Les constructeur destructeur

Contact::Contact(void)
{
	this->_first_name = "";
	this->_last_name = "";
	this->_nickname = "";
	this->_phone_number = "";
	this->_dark_secret = "";
}

Contact::Contact(std::string fn, std::string ln, std::string nm, std::string pn, std::string ds): _first_name(fn), _last_name(ln), _nickname(nm), _phone_number(pn), _dark_secret(ds)
{
}

Contact::~Contact(void)
{
}

/// Les ft get
std::string	Contact::get_first_name(void) const
{
	return (this->_first_name);
}

std::string	Contact::get_last_name(void) const
{
	return (this->_last_name);
}

std::string	Contact::get_nickname(void) const
{
	return (this->_nickname);
}

std::string	Contact::get_phone_number(void) const
{
	return (this->_phone_number);
}

std::string	Contact::get_dark_secret(void) const
{
	return (this->_dark_secret);
}

// Les ft set

void	Contact::set_first_name(void)
{
	std::string	str;

	str = get_input("First Name: ");
	while (is_good_name(str) || str.empty())
	{
		std::cout << "\033[31mNo legit Name\033[0m" << std::endl;
		str = get_input("RETRY! First Name: ");
	}
	this->_first_name = str;
}

void	Contact::set_last_name(void)
{
	std::string	str;

	str = get_input("Last Name: ");
	while (is_good_name(str) || str.empty())
	{
		std::cout << "\033[31mNo legit Name\033[0m" << std::endl;
		str = get_input("RETRY! Last Name: ");
	}
	this->_last_name = str;
}

void	Contact::set_nickname(void)
{
	std::string	str;

	str = get_input("Nick Name: ");
	while (str.empty())
	{
		std::cout << "\033[31mCan not be empty...\033[0m" << std::endl;
		str = get_input("Retry Nick Name: ");
	}
	this->_nickname = str;
}

void	Contact::set_phone_number(void)
{
	std::string	str;

	str = get_input("Phone Number: ");
	while (is_a_legit_number_phone(str) || str.empty())
	{
		std::cout << "\033[31mNo valid Phone Number.\033[0m" << std::endl;
		str = get_input("RETRY! Phone Number: ");
	}
	this->_phone_number = str;
}

void	Contact::set_dark_secret(void)
{
	std::string	str;

	str = get_input("Dark Secret: ");
	while (str.empty())
	{
		std::cout << "\033[31mCan not be empty...\033[0m" << std::endl;
		str = get_input("Dark Secret: ");
	}
	this->_dark_secret = str;
}

// debug

void	Contact::show_class(void) const
{
	std::string blue;
	std::string no_color;

	blue = "\033[34m";
	no_color = "\033[0m";
	std::cout << blue << "FirstName\t= " << this->get_first_name() << std::endl;
	std::cout << "LastName\t= " << this->get_last_name() << std::endl;
	std::cout << "NickName\t= " << this->get_nickname() << std::endl;
	std::cout << "PhoneNumber\t= " << this->get_phone_number() << std::endl;
	std::cout << "DarkSecret\t= " << this->get_dark_secret() << no_color << std::endl;
}
