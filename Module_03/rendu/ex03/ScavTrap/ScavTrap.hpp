/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 01:23:09 by yzaoui            #+#    #+#             */
/*   Updated: 2024/04/12 14:45:34 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "../ClapTrap/ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
protected:
	bool	_guard;
	void	_initSomeState(void);
public:
	ScavTrap();
	ScavTrap(std::string name);
	ScavTrap	&operator=(ScavTrap const &src);
	void	takeDamage(unsigned int amount);
	~ScavTrap();
	
	void guardGate(void);
	void	showData(void) const;
};




#endif