/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 03:03:50 by yzaoui            #+#    #+#             */
/*   Updated: 2024/04/05 14:58:59 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Harl.hpp"

// bob.complain("wcpncvc");
// bob.complain("DEBUG");
// bob.complain("INFO");
// bob.complain("WARNING");
// bob.complain("ERROR");
int	main(int argc, char **argv)
{
	Harl bob;

	if (argc >= 2)
	{
		std::string	msg(argv[1]);
		bob.complain(msg);
	}
}