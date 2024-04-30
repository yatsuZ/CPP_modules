/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 17:13:56 by yzaoui            #+#    #+#             */
/*   Updated: 2024/04/13 18:10:30 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "../Cat/Cat.hpp"

class Dog: public Animal
{
private:
	Brain	*_thoughts;
public:
	Dog();
	Dog(Dog const &src);

	// Destructeur
	~Dog();

	// Opperateur
	Dog	&operator=(Dog const &src);

/////////////////////

	void	makeSound(void) const;
	void	showData(void) const;
	void	setThoughts(std::string newThoughts[100]);
};


#endif