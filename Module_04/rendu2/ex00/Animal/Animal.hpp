/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 16:18:49 by yzaoui            #+#    #+#             */
/*   Updated: 2024/04/13 17:20:54 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>
#include <string.h>
#include <typeinfo>

#define NOCOLOR "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"
#define PURPLE "\033[35m"

class Animal
{
protected:
	std::string	_type;
public:
	Animal();
	Animal(Animal const &src);

	// Destructeur
	virtual ~Animal();

	// Opperateur
	Animal	&operator=(Animal const &src);

/////////////////////

	virtual void	 makeSound(void) const;

/////////////////////

	void		showType(void) const;
	std::string	getType(void) const;
};

#endif