/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 02:25:04 by yzaoui            #+#    #+#             */
/*   Updated: 2024/04/09 19:56:22 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ClapTrap/ClapTrap.hpp"


// Fonction teste Tout ce qui sagit pour le canonique
void	testCanonique(void)
{
	ClapTrap a;
	ClapTrap b(a);
	ClapTrap c = a;

	std::cout << "a = " << std::endl;
	a.showData();
	std::cout << "b = " << std::endl;
	b.showData();
	std::cout << "c = " << std::endl;
	c.showData();
}

// Fonction qui teste ce que le sujet ma demande dimplementer
void	testSubject(void)
{
	std::cout << "Faire un petit test" << std::endl;

}

// Scenario Faire une petite hisoire avec mes truc perso hihi
void	scenario(void)
{
	std::cout << "Faire un petit scenario" << std::endl;

}

int	main(void)
{
	testCanonique();
}
