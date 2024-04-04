/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 18:49:26 by yzaoui            #+#    #+#             */
/*   Updated: 2024/04/04 17:59:58 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "./Weapon.hpp"

class HumanA
{
private:
	Weapon		&_weaponType;
	std::string	_name;
public:
	void	attack(void) const;
	HumanA(std::string name, Weapon &weponT);
	~HumanA();
};

#endif