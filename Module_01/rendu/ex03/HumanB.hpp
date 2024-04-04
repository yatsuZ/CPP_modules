/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 18:51:51 by yzaoui            #+#    #+#             */
/*   Updated: 2024/04/04 18:11:01 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "./Weapon.hpp"

class HumanB
{
private:
	Weapon		*_weaponType;
	std::string	_name;
public:
	void	attack(void) const;
	void	setWeapon(Weapon &weapon);
	HumanB(std::string name);
	~HumanB();
};

#endif