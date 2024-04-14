/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 20:58:36 by yzaoui            #+#    #+#             */
/*   Updated: 2024/04/14 00:08:51 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "../../header.hpp"
#include "./../../All_Materiaux/AMateria/AMateria.hpp"

class Character : public ICharacter
{
private:
	std::string	_name;
	AMateria	*(_inventaire[4]);
public:
	Character();
	~Character();
	Character(Character const &src);
	Character	&operator=(Character const &src);
	Character(std::string name);
///
	std::string const & getName() const;
	void equip(AMateria* m);
	void unequip(int idx);
	void use(int idx, ICharacter& target);
};

#endif