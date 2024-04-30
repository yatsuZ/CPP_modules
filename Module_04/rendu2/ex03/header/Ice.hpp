/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 20:46:59 by yzaoui            #+#    #+#             */
/*   Updated: 2024/04/30 16:13:40 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

#include "../include.hpp"


#include "./AMateria.hpp"

class Ice: public AMateria
{
public:
	Ice();
	~Ice();
	Ice(Ice const &src);
	Ice	&operator=(Ice const &src);


	AMateria* clone() const;
	void use(ICharacter& target);
};

#endif