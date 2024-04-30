/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 19:33:12 by yzaoui            #+#    #+#             */
/*   Updated: 2024/04/30 17:03:48 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/Character.hpp"
#include "header/Cure.hpp"
#include "header/Ice.hpp"
#include "header/ICharacter.hpp"
#include "header/IMateriaSource.hpp"
#include "header/MateriaSource.hpp"

#include "include.hpp"

int main(void)
{
	IMateriaSource* src = new MateriaSource();

	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");
	AMateria* tmp;

	tmp = src->createMateria("ice");

	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;

	return 0;
}

///Res :
//$> clang++ -W -Wall -Werror *.cpp
//$> ./a.out | cat -e
//* shoots an ice bolt at bob *$
//* heals bob's wounds *$