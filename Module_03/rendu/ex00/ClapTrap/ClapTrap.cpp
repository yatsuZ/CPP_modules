/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 02:25:45 by yzaoui            #+#    #+#             */
/*   Updated: 2024/04/09 19:58:46 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

// Constructeur

ClapTrap::ClapTrap(): _name("Unnamed"), _hp(10), _stamina(10), _damage(0), _quote("")
{
	std::cout << "* " << GREEN << this->_name << " ClapTrap was built." << NOCOLOR << "* " << std::endl;
}

ClapTrap::ClapTrap(std::string name)
: _name(name), _hp(10), _stamina(10), _damage(0), _quote("")
{
	std::cout << "* " << GREEN << this->_name << " ClapTrap was built." << NOCOLOR << "* "<< std::endl;
}

ClapTrap::ClapTrap(std::string name, int hp, int stamina, int damage, std::string quote)
:_name(name), _hp(hp), _stamina(stamina), _damage(damage), _quote(quote)
{
	std::cout << "* " << GREEN << this->_name << " was creat with specifique stat!!." << NOCOLOR << "* " << std::endl;
}

// Destructeur

ClapTrap::~ClapTrap()
{
	std::cout << "* " << RED << this->_name << " was destroyed." << NOCOLOR << "* " << std::endl;
}

// Copy

ClapTrap::ClapTrap(ClapTrap const &src)
{
	*this = src;
	std::cout << "* " << MAGENTA << this->_name << " Clone to " << NOCOLOR;
	std::cout << YELLOW << this->_name << NOCOLOR << "* " << std::endl;
}

ClapTrap	&ClapTrap::operator=(ClapTrap const &src)
{
	if (this != &src)
	{
		this->_name = src._name;
		this->_hp = src._hp;
		this->_stamina = src._stamina;
		this->_damage = src._damage;
	}
	std::cout << "* " << MAGENTA << this->_name << " COPY " << NOCOLOR;
	std::cout << YELLOW << this->_name << NOCOLOR << "* " << std::endl;

	return (*this);
}

// FIN FORME CANONIQUE

void	ClapTrap::attack(const std::string &target)
{
	if (!this->haveHP())
	{
		std::cout << "*" << MAGENTA << "ClapTrap " << this->_name << " is broken have no HP" << NOCOLOR << "*" << std::endl;
		return ;
	}
	(this->_stamina > 0)? this->_stamina-- : this->_stamina;
	if (this->_stamina > 0)
		std::cout << "*" << MAGENTA << "ClapTrap " << this->_name << " try to attacks" << target << NOCOLOR << "*" << std::endl;
	else
		std::cout << "*" << MAGENTA << "ClapTrap " << this->_name << " do nothing have no stamina" << NOCOLOR << "*" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "*" << RED << "ClapTrap " << this->_name << " suffers " << amount << " deammage point" << NOCOLOR << "*" << std::endl;
	this->_hp -= amount;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	std::cout << "*" << GREEN << "ClapTrap " << this->_name << " was healed by " << amount << " HP" << NOCOLOR << "*" << std::endl;
	this->_hp += amount;
}

// BONNUS

void	ClapTrap::useQuote(void) const
{
	std::cout << this->_quote << std::endl;
}

void	ClapTrap::setQuote(std::string newQuote)
{
	this->_quote = newQuote;
}

bool	ClapTrap::haveHP(void) const
{
	return (this->_hp > 0);
}

void	ClapTrap::attack(ClapTrap &target)
{
	this->attack(target._name);
	if (!this->haveHP() || this->_stamina < 0)
		return ;
	(this->_stamina == 0)? this->_stamina-- : this->_stamina;
	if (this->_damage < 0)
	{
		target.beRepaired(abs(this->_damage));
		target._stamina++;
	}
	else
		target.takeDamage(this->_damage);
}

void	ClapTrap::showData(void) const
{
	std::cout << "--------------------------------" << std::endl;
	std::cout << "Adresse = " << this << std::endl;
	std::cout << "name = " << this->_name << std::endl;
	std::cout << "quote = \"" << this->_quote << "\"" << std::endl;
	std::cout << "hp = " << this->_hp << std::endl;
	std::cout << "stamina = " << this->_stamina << std::endl;
	std::cout << "damage = " << this->_damage << std::endl;
	std::cout << "--------------------------------" << std::endl;
}
