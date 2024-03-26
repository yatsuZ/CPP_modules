/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   poly1.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:28:42 by yzaoui            #+#    #+#             */
/*   Updated: 2024/03/26 15:47:20 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

class Character
{
public:
	virtual void	sayHello(std::string const & target);// Le mot clée virutal permet de rendre la fonction dynamaic 
};

class Warrior : public Character
{
public:
	virtual void	sayHello(std::string const & target);
};

class Cat
{
	//[...]
};

void	Character::sayHello(std::string const & target)
{
	std::cout << "Hello " << target << " !" << std::endl;
}

void	Warrior::sayHello(std::string const & target)
{
	std::cout << "F*** off " << target << " I don't like you !" << std::endl;
}

int	main()
{
	//This is OK, obviously, Warrior Is a Warrior
	Warrior	*a= new Warrior();

	//This is aldo OK because Warrior IS a Character
	Character	*b = new Warrior();

	//This is not legit
	//Warrior	*c = new	Character();
	//Character	*d = new Cat();

	a->sayHello("student");
	b->sayHello("student");// si virtuel va chercher la fonction dynamic
	return (0);
}