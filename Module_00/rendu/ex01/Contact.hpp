/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 16:31:56 by yzaoui            #+#    #+#             */
/*   Updated: 2024/03/29 17:48:51 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include "./import.h"
#include <string>

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

#endif