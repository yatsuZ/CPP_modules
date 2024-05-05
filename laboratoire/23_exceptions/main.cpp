/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 22:05:33 by yzaoui            #+#    #+#             */
/*   Updated: 2024/05/05 23:09:13 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdexcept>
#include <iostream>
#include <iomanip>

#define BLEU "\x1B[34m"
#define JAUNE "\x1B[33m"
#define NOCOLOR "\x1B[0m"
#define VERT "\x1B[32m"
#define ROUGE "\x1B[31m"

	class PEBKACException : public std::exception
	{
		public :
			virtual const char* what() const throw(/*peut envoye des info*/)
			{
				return ("Problem exists between keyboard and chair de PEBKACException");
			}
	};


int getInput()
{
	int nombre;
	std::cout << "Veuillez entrer un nombre : ";
	std::cin >> nombre;
	return (nombre);
}

// Fonction pour afficher un tableau avec les valeurs en bleu et les index en jaune
void showTab(int tableau[], int taille)
{
	// Afficher les valeurs du tableau en bleu
	std::cout << BLEU << "VALUE :"; // Couleur bleue

	for (int i = 0; i < taille; ++i)
	{
		std::cout << std::setw(5) << tableau[i]; // Espacement de 5 caractères entre les valeurs
	}
	std::cout << NOCOLOR << std::endl; // Réinitialiser la couleur à la valeur par défaut

	// Afficher les index du tableau en jaune
	std::cout << JAUNE << "INDEX :"; // Couleur jaune
	for (int i = 0; i < taille; ++i)
	{
		std::cout << std::setw(5) << i; // Espacement de 5 caractères entre les index
	}
	std::cout << NOCOLOR << std::endl; // Réinitialiser la couleur à la valeur par défaut
}


void	test1()
{
	try
	{
		const int taille = 5;
		// Créer un tableau avec 5 éléments
		int tableau[taille] = {12, 24, 23, 74, 55};

		showTab(tableau, taille);
		int indice = getInput(); // Indice qui dépasse la taille du tableau


		// Vérifier si l'indice est valide
		if (indice >= 0 && indice < taille) // Vérifier si l'indice est dans la plage valide du tableau
		{
			std::cout << VERT << "Valeur à l'indice " << JAUNE << indice << NOCOLOR << " : " << BLEU << tableau[indice] << NOCOLOR << std::endl;
		}
		else
		{
			throw std::out_of_range("Indice hors limite"); // Lancer une exception si l'indice est hors limite
		}
	}
	catch(const std::exception& e)
	{
		// Gérer l'erreur ici, par exemple, afficher un message d'erreur
		std::cerr << ROUGE << "Erreur : " << e.what() << NOCOLOR << std::endl;
	}
}

void	test2()
{
	const int taille = 5;
	int tableau[taille] = {12, 24, 23, 74, 55};
	showTab(tableau, taille);
	int indice = getInput();
	if (tableau && indice >= 0 && indice < taille)
		std::cout << VERT << "Valeur à l'indice " << JAUNE << indice << NOCOLOR << " : " << BLEU << tableau[indice] << NOCOLOR << std::endl;
	else if (indice < 0)
		throw PEBKACException();
	else
		throw std::out_of_range("Indice hors limite"); // Lancer une exception si l'indice est hors limite
}

void	test3()
{
	try
	{
		test2();
	}
	catch (std::exception& e)
	{
		std::cerr << ROUGE << "Erreur : " << e.what() << NOCOLOR << std::endl;
	}
}

void	test4()
{
	try
	{
		test2();
	}
	catch (PEBKACException& e)
	{
		std::cerr << "Erreur : " << ROUGE << e.what() << NOCOLOR << std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr << "Erreur : " << ROUGE << e.what() << NOCOLOR << std::endl;
	}
}

int main (void)
{
	test4();
	return (0);
}