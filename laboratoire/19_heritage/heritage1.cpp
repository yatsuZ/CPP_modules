/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heritage1.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 14:50:18 by yzaoui            #+#    #+#             */
/*   Updated: 2024/03/26 14:54:08 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>

class Cat
{
private:
	int	_numberOfLegs;
public:
	Cat(void);
	Cat(Cat const &);
	Cat	&operator=(Cat const &);
	~Cat();

	void	run(int distance);

	void	scornSomeone(std::string const & target);
};

class Pony
{
private:
	int	_numberOfLegs;
public:
	Pony(void);
	Pony(Pony const &);
	Pony	&operator=(Pony const &);
	~Pony();

	void	run(int distance);

	void	doMagic(std::string const & target);
};
