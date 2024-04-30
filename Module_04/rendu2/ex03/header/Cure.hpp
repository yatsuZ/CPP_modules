/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 20:47:53 by yzaoui            #+#    #+#             */
/*   Updated: 2024/04/30 16:13:50 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

#include "../include.hpp"


#include "./AMateria.hpp"

class Cure: public AMateria
{
public:
	Cure();
	Cure(Cure const &src);
	Cure	&operator=(Cure const &src);

	~Cure();


	AMateria* clone() const;
	void use(ICharacter& target);

};


#endif