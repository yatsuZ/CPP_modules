/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 19:29:32 by yzaoui            #+#    #+#             */
/*   Updated: 2024/04/13 19:24:35 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./WrongCat/WrongCat.hpp"

void	test_subject(void)
{
	// const Animal* meta = new Animal();
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();

	// std::cout << meta->getType() << "" << std::endl;
	std::cout << dog->getType() << " " << std::endl;
	std::cout << cat->getType() << " " << std::endl;

	cat->makeSound(); //will output the cat sound!
	dog->makeSound();
	// meta->makeSound();

	delete dog;
	delete cat;
	// delete meta;

	// const WrongAnimal* wrongmeta = new WrongAnimal();
	const WrongAnimal* wrongcat = new WrongCat();
	
	// std::cout << wrongmeta->getType() << "" << std::endl;
	std::cout << wrongcat->getType() << " " << std::endl;

	// wrongmeta->makeSound();
	wrongcat->makeSound();

	// delete wrongmeta;
	delete wrongcat;

}

int	main(void)
{
	test_subject();
	// aFaire();
	// Animal a;
	// a.showType();
	// a.makeSound();
	return (0);
}