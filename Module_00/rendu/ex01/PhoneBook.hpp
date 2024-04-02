/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 16:30:47 by yzaoui            #+#    #+#             */
/*   Updated: 2024/04/02 02:00:03 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "./Contact.hpp"

class PhoneBook
{
private:
	bool	_end;
	Contact	_repertoir[8];
	int		_i;
	void	_add(void);
	void	_search(void);
	void	_exit(void);
public:
	PhoneBook();
	~PhoneBook();
	void	simulation(void);
};


#endif