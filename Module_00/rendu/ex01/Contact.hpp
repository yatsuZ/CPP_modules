/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 16:31:56 by yzaoui            #+#    #+#             */
/*   Updated: 2024/03/30 01:18:43 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include "./import.h"

class Contact
{
private:
	std::string	_first_name;
	std::string	_last_name;
	std::string	_nickname;
	std::string	_phone_number;
	std::string	_dark_secret;
public:
	Contact();
	Contact(std::string fn, std::string ln, std::string nm, std::string pn, std::string ds);
	~Contact();

//  Les ft get
	std::string	get_first_name(void) const;
	std::string	get_last_name(void) const;
	std::string	get_nickname(void) const;
	std::string	get_phone_number(void) const;
	std::string	get_dark_secret(void) const;
//  Les ft set
	void	set_first_name(void);
	void	set_last_name(void);
	void	set_nickname(void);
	void	set_phone_number(void);
	void	set_dark_secret(void);
//  Les ft de debeug
	void	show_class(void) const;
};

#endif