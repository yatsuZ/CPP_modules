/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 19:29:32 by yzaoui            #+#    #+#             */
/*   Updated: 2024/04/13 19:11:30 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./WrongCat/WrongCat.hpp"

void	litel_test(void)
{
	Dog a;

	a.setThoughts((std::string[100]){"Manger", "Dormir", "Dormir", "Reproduire"});
	a.showData();
}

void	litel_test2(void)
{
	std::cout << std::endl << "Constructeur ------------------------" << std::endl << std::endl;
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << std::endl << "Deconstructeur ------------------------" << std::endl << std::endl;
	delete j;
	delete i;
}

void	test_subject(void)
{
	size_t	N = 100;
	Animal** animals = new Animal * [N];
	for (size_t i = 0; i < N; i++)
	{
		if (i < N / 2)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}
	for (size_t i = 0; i < N; i++)
	{
		delete animals[i];
		std::cout << std::endl;
	}
	delete [] animals;
}

void	test_copie_profonde(void)
{
	Dog a;
	Dog b;
	a.setThoughts((std::string[100]){"Manger", "Dormir", "Survivre"});
	a.showData();

	b = a;
	b.showData();
}

int	main(void)
{
	litel_test();
	// litel_test2();
	// test_subject();
	// test_copie_profonde();
	return (0);
}