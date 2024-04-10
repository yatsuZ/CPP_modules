/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 02:25:04 by yzaoui            #+#    #+#             */
/*   Updated: 2024/04/10 02:47:26 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./FragTrap/FragTrap.hpp"


int	main(void)
{
	std::cout << "Faire le test manuellement:" << std::endl;
	FragTrap bMAX("bMAX");
	FragTrap WALLE("WALLE");

	bMAX.highFivesGuys();
	while (bMAX.haveHP() && bMAX.haveStamina() && WALLE.haveHP() && WALLE.haveHP())
	{
		WALLE.attack(bMAX.getName());
		bMAX.takeDamage(WALLE.getDammage());
		bMAX.attack(bMAX.getName());
		WALLE.takeDamage(bMAX.getDammage());
		std::cout << "|----" << std::endl;
	}
	WALLE.highFivesGuys();
	bMAX.showData();
	WALLE.showData();
	return (0);
}
