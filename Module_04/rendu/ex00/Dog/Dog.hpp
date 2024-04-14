/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 17:13:56 by yzaoui            #+#    #+#             */
/*   Updated: 2024/04/13 17:15:28 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "../Cat/Cat.hpp"

class Dog: public Animal
{
public:
	Dog();
	Dog(Dog const &src);

	// Destructeur
	~Dog();

	// Opperateur
	Dog	&operator=(Dog const &src);

/////////////////////

	void	makeSound(void) const;
};


#endif