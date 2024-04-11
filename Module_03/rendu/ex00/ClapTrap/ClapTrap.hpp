/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 02:25:30 by yzaoui            #+#    #+#             */
/*   Updated: 2024/04/11 16:08:13 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>
#include <string>
#include <cmath>
#include <unistd.h>

#define NOCOLOR "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"
#define PURPLE "\033[35m"

class ClapTrap
{
private:

	std::string	_name;
	int			_hp;
	int			_stamina;
	int			_damage;
	std::string	_quote;

public:
// FORME CANONIQUE

	// Constructeur
	ClapTrap();
	ClapTrap(ClapTrap const &src);

	// Destructeur
	~ClapTrap();

	// Opperateur
	ClapTrap	&operator=(ClapTrap const &src);

// FIN FORME CANONIQUE
	ClapTrap(std::string name);
	void	takeDamage(unsigned int amount);
	void	attack(const std::string &target);
	void	beRepaired(unsigned int amount);
// BONUS
	void	attack(ClapTrap &target);
	ClapTrap(std::string name, int hp, int stamina, int damage, std::string quote);
	void	useQuote(void) const;
	void	setQuote(std::string newQuote);
	bool	haveHP(void) const;
	bool	haveStamina(void) const;
	void	showData(void) const;
	void	setStamina(int newStamina);
	std::string	getName(void)const;
};

#endif