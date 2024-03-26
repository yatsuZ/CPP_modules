/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   poly2.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:48:53 by yzaoui            #+#    #+#             */
/*   Updated: 2024/03/26 16:02:31 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

class ACharacter// Class abstrect, peut avoir des atribut
{
public:
	virtual void	attack(std::string const & target) = 0;
	void			sayHello(std::string const & target);
};

class Warrior : public ACharacter
{
public:
	virtual void	attack(std::string const & target) = 0;
};

void	ACharacter::sayHello(std::string const & target)
{
	std::cout<< "Hello " << target << " !" << std::endl;
}

void	Warrior::attack(std::string const & target)
{
	std::cout<< "*attacks " << target << " with a sword*" << std::endl;
}

class ICoffeMake// INterface
{
public:
	virtual void	fillWatterTank(IWaterSource * src) = 0;
	virtual ICoffe	*makeCoffee(std::string const & type);
};

int	main()
{
	ACharacter	*a = new Warrior();

	//Pas ok car ACharacter est abstrecte
	//ACharacter	*b = new ACharacter();
	
	a->sayHello("Students");
	a->attack("roger");
	return (0);
}



