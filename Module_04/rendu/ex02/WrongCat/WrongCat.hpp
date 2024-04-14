/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 17:26:21 by yzaoui            #+#    #+#             */
/*   Updated: 2024/04/13 19:25:09 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include "./../WrongAnimal/WrongAnimal.hpp"

class WrongCat: public WrongAnimal
{
public:
	WrongCat();
	WrongCat(WrongCat const &src);

	// Destructeur
	~WrongCat();

	// Opperateur
	WrongCat	&operator=(WrongCat const &src);

/////////////////////

	void	makeSound(void) const;
};


#endif