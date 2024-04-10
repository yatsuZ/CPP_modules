/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 02:25:04 by yzaoui            #+#    #+#             */
/*   Updated: 2024/04/10 02:25:53 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ScavTrap/ScavTrap.hpp"


int	main(void)
{
	std::cout << "Faire le test manuellement:" << std::endl;
	ScavTrap bender("bender");
	ScavTrap Dallek("Dallek");

	bender.guardGate();
	while (bender.haveHP() && bender.haveStamina() && Dallek.haveHP() && Dallek.haveHP())
	{
		Dallek.attack(bender.getName());
		bender.takeDamage(Dallek.getDammage());
		bender.guardGate();
		bender.attack(bender.getName());
		Dallek.takeDamage(bender.getDammage());
		std::cout << "|----" << std::endl;
	}
	bender.showData();
	Dallek.showData();
	return (0);
}
