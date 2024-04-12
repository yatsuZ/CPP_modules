/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 02:25:04 by yzaoui            #+#    #+#             */
/*   Updated: 2024/04/12 15:33:15 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./DiamondTrap/DiamondTrap.hpp"

void	test(void)
{
	std::string narateur = (std::string)GREEN + "<DOCTOR WHO>" + (std::string)NOCOLOR;
	std::cout << "Faire le test manuellement:" << std::endl;

	DiamondTrap dalek((std::string)RED+"<Dalek>"+ (std::string)NOCOLOR);
	DiamondTrap cyberman((std::string)BLUE+"<Cyber MAN>"+ (std::string)NOCOLOR);
	cyberman.setQuote("You will be upgraded");
	dalek.setQuote("EXTERMINER EXTERMINER EXTERMINER !!!!!");

	// dalek.showData();
	// dalek.whoAmI();
	std::cout << narateur << ": OH!.. un cyberman et un dalek se rencontre !" << std::endl << std::endl;
	std::cout << dalek.getName() << ": Identifier vous !!" << std::endl;
	std::cout << cyberman.getName() << ": " << std::endl;
	cyberman.whoAmI();
	std::cout << std::endl;
	std::cout << cyberman.getName() << ": A present montrez nous vo statistique !! " << std::endl;
	std::cout << dalek.getName() << ": " << std::endl;
	dalek.showData();
	std::cout << std::endl;
	cyberman.useQuote();
	dalek.useQuote();
	std::cout << std::endl;

	cyberman.highFivesGuys();
	cyberman.guardGate();
	while (cyberman.haveHP() && cyberman.haveStamina() && dalek.haveHP() && dalek.haveHP())
	{
		dalek.attack(cyberman.getName());
		cyberman.takeDamage(dalek.getDammage());
		cyberman.guardGate();
		cyberman.attack(cyberman.getName());
		dalek.takeDamage(cyberman.getDammage());
		std::cout << "|----" << std::endl;
	}
	dalek.showData();
	cyberman.showData();
}

int	main(void)
{
	test();
	return (0);
}
