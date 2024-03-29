/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 17:03:13 by yzaoui            #+#    #+#             */
/*   Updated: 2024/03/29 18:50:16 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

class Contact
{
private:
	char	*_first_name;
	char	*_last_name;
	char	*_nickname;
	char	*_phone_number;
	char	*_dark_secret;
public:
	Contact();
	Contact(char *fn, char *ln, char *nm, char *pn, char *ds);
	~Contact();

//  Les ft get
	char	*get_first_name(void) const;
	char	*get_last_name(void) const;
	char	*get_nickname(void) const;
	char	*get_phone_number(void) const;
	char	*get_dark_secret(void) const;
//  Les ft set
	void	set_first_name(void);
	void	set_last_name(void);
	void	set_nickname(void);
	void	set_phone_number(void);
	void	set_dark_secret(void);
//  Les ft de debeug
	void	show_class(void) const;
};

// Les constructeur destructeur

Contact::Contact(void)
{
	this->_first_name = NULL;
	this->_last_name = NULL;
	this->_nickname = NULL;
	this->_phone_number = NULL;
	this->_dark_secret = NULL;
}

Contact::Contact(char *fn, char *ln, char *nm, char *pn, char *ds): _first_name(fn), _last_name(ln), _nickname(nm), _phone_number(pn), _dark_secret(ds)
{
}

Contact::~Contact(void)
{
}

/// Les ft get
char*	Contact::get_first_name(void) const
{
	return (this->_first_name);
}

char*	Contact::get_last_name(void) const
{
	return (this->_last_name);
}

char*	Contact::get_nickname(void) const
{
	return (this->_nickname);
}

char*	Contact::get_phone_number(void) const
{
	return (this->_phone_number);
}

char*	Contact::get_dark_secret(void) const
{
	return (this->_dark_secret);
}

// Les ft set

void	Contact::set_first_name(void)
{
	char	*str;

	str = get_input("First Name: ");
	while (is_good_name(str))
	{
		std::cout << "\033[31mNo valid Name for technologie of 80\033[0m" << std::endl;
		str = get_input("RETRY! First Name: ");
	}
	this->_first_name = str;
}

void	Contact::set_last_name(void)
{
	char	*str;

	str = get_input("Last Name: ");
	while (is_good_name(str))
	{
		std::cout << "\033[31mNo valid Name for technologie of 80\033[0m" << std::endl;
		str = get_input("RETRY! Last Name: ");
	}
	this->_last_name = str;
}

void	Contact::set_nickname(void)
{
	char	*str;

	str = get_input("Nick Name: ");
	this->_nickname = str;
}

void	Contact::set_phone_number(void)
{
	char	*str;

	str = get_input("Phone Number: ");
	while (is_good_name(str))
	{
		std::cout << "\033[31mNo valPhone Number.\033[0m" << std::endl;
		str = get_input("RETRY! Phone Number: ");
	}
	this->_phone_number = str;
}

void	Contact::set_dark_secret(void)
{
	char	*str;

	str = get_input("msg: ");
	this->_dark_secret = str;
}

// debug

void	Contact::show_class(void) const
{
	char	*blue;
	char	*no_color;

	blue = "\033[34m";
	no_color = "\033[0m";
	std::cout << blue << "First Name\t=" << this->get_first_name() << std::endl;
	std::cout << "Last Name\t=" << this->get_last_name() << std::endl;
	std::cout << "Nick Name\t=" << this->get_nickname() << std::endl;
	std::cout << "Phone Number\t=" << this->get_phone_number() << std::endl;
	std::cout << "Dark Secret\t=" << this->get_dark_secret() << no_color << std::endl;
}
