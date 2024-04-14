/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 20:44:50 by yzaoui            #+#    #+#             */
/*   Updated: 2024/04/14 00:07:32 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP


#include "./../../header.hpp"
#include "./../../All_Character/ICharacter.hpp"

class AMateria
{
protected:
	std::string	_type;
public:
	AMateria();
	AMateria(AMateria const &src);

	virtual ~AMateria() = 0;

	AMateria	&operator=(AMateria const &src);

	AMateria(std::string const & type);


	std::string const & getType() const; //Returns the materia type
	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target) = 0;
};


#endif