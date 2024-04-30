/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 16:48:50 by yzaoui            #+#    #+#             */
/*   Updated: 2024/04/13 17:27:36 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include "../Animal/Animal.hpp"

class Cat: public Animal
{
public:
	Cat();
	Cat(Cat const &src);

	// Destructeur
	~Cat();

	// Opperateur
	Cat	&operator=(Cat const &src);

/////////////////////

	void	makeSound(void) const;
};


#endif