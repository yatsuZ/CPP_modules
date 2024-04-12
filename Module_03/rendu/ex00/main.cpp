/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 02:25:04 by yzaoui            #+#    #+#             */
/*   Updated: 2024/04/12 15:37:07 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ClapTrap/ClapTrap.hpp"


// Fonction teste Tout ce qui sagit pour le canonique
void	testCanonique(void)
{
	std::cout << "Test de la conicitée :" << std::endl;

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

void	stupidBotAttack(ClapTrap &stupid)
{
	unsigned int	delai = 750000;
	for (size_t i = 0; i < 20; i++)
	{
		stupid.attack("\"un caillioux\"");
		usleep(delai);
		if (i == 6)
		{
			std::cout << std::endl << GREEN << "<Createur>" << NOCOLOR << ": Non mais c'est bon arrete sa devien ridicule ..."<< std::endl;
			std::cout << "\t\t\tTu va bientot avoir plus d'energie et tu risque de te blesser." << std::endl << std::endl;
			sleep(3);
			std::cout << "*" << stupid.getName() << " thought process* : ";
			for (size_t j = 0; j < 5; j++)
			{
				std::cout << ".";
				std::cout.flush();
				sleep(1);
			}
			std::cout << std::endl;
			delai = 80000;
		}
		if (i > 15)
			std::cout << GREEN << "<Createur>" << NOCOLOR << ": STOP !!"<< std::endl;
	}

}

// Fonction qui teste ce que le sujet ma demande dimplementer
void	testSubject(void)
{
	std::cout << "Test de ce que le sujet demande :" << std::endl;
	ClapTrap stupid("STUPID BOT");

	std::cout << CYAN << "Voici ces information : " << NOCOLOR << std::endl;
	stupid.showData();
	stupid.setQuote("Je detecte un caillioux. JE DETESTE LA ROCHE!!!! a l'attaque!!! >:(");
	std::cout << GREEN << "<Createur>" << NOCOLOR << ": Je vais te donner un peut plus de point de vie daccord :)" << std::endl;
	stupid.setStamina(21);
	std::cout << GREEN << "<Createur>" << NOCOLOR << ": A present va rependre la paix." << std::endl;
	sleep(3);
	stupid.useQuote();
	sleep(2);
	stupidBotAttack(stupid);
	stupid.takeDamage(9);
	std::cout << GREEN << "<Createur>" << NOCOLOR << ": Imbecile !!!!! tu t'es blesser puff... Laisse moi regarder tes state" << std::endl;
	sleep(1);
	stupid.showData();
	std::cout << GREEN << "<Createur>" << NOCOLOR << ": OULALALALA il te reste 1 point de vie utilise ton toon stamina pour te soignier" << std::endl;
	sleep(5);
	while (stupid.haveStamina())
	{
		stupid.beRepaired(1);
		usleep(500000);
	}	
	stupid.beRepaired(1);
	std::cout << GREEN << "<Createur>" << NOCOLOR << ":Il ne te reste plus denergie tu ne peux plus iren faire pour te punir je vais te detruire" << std::endl;
	sleep(2);
	std::cout << "Dis moi combien";
	std::cout.flush();
	sleep(1);
	std::cout << " FONT ";
	std::cout.flush();
	sleep(1);
	std::cout << "0";
	std::cout.flush();
	sleep(1);
	std::cout << "/";
	std::cout.flush();
	sleep(1);
	std::cout << "0" << std::endl;
	std::cout.flush();
	sleep(3);
}

//////////////////////////////////////////
int	main(int argc, char **argv)
{
	if (argc > 1 && "canon" == (std::string)argv[1])
		testCanonique();
	else if (argc > 1 && "stupid" == (std::string)argv[1])
		testSubject();
	else
	{
		std::cout << "Faire le test manuellement, ou metre en arguament \"stupid\"" << std::endl;
	}
	return (0);
}
