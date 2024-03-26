/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heritage2.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 14:56:26 by yzaoui            #+#    #+#             */
/*   Updated: 2024/03/26 15:07:22 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>

class Animal
{
	int	_numberOfLegs;
public:
	Animal();
	Animal(Animal const &);
	Animal	&operator=(Animal const &);
	~Animal();

	void	run(int distance);
};

class Cat : public Animal
{
public:
	Cat(void);
	Cat(Cat const &);
	Cat	&operator=(Cat const &);
	~Cat();

	void	scornSomeone(std::string const & target);
};

class Pony : public Animal
{
public:
	Pony(void);
	Pony(Pony const &);
	Pony	&operator=(Pony const &);
	~Pony();

	void	doMagic(std::string const & target);
	void	run(int distance);
};

