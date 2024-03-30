/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 22:09:59 by yzaoui            #+#    #+#             */
/*   Updated: 2024/03/30 13:56:23 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./PhoneBook.hpp"

int	main(void)
{
	Contact	test;

	test.show_class();
	test.set_first_name();
	test.set_last_name();
	test.set_nickname();
	test.set_phone_number();
	test.set_dark_secret();
	test.show_class();
	return (0);
}


