/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 01:23:09 by yzaoui            #+#    #+#             */
/*   Updated: 2024/04/10 02:12:30 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "../ClapTrap/ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	private:
	bool	_guard;
public:
	ScavTrap();
	ScavTrap(std::string name);
	ScavTrap	&operator=(ScavTrap const &src);
	void	takeDamage(unsigned int amount);

	~ScavTrap();
	
	void guardGate(void);
};




#endif