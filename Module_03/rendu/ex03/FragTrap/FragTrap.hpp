/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 02:27:23 by yzaoui            #+#    #+#             */
/*   Updated: 2024/04/11 21:22:51 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ScavTrap/ScavTrap.hpp"

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

class FragTrap: virtual public ClapTrap
{
protected:
	void	_initSomeState(void);
public:
	FragTrap();
	FragTrap(std::string name);
	FragTrap	&operator=(FragTrap const &src);

	~FragTrap();
	
	void highFivesGuys(void);
};

#endif