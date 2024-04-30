/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 16:48:50 by yzaoui            #+#    #+#             */
/*   Updated: 2024/04/13 18:10:24 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include "../Brain/Brain.hpp"

class Cat: public Animal
{
private:
	Brain	*_thoughts;
public:
	Cat();
	Cat(Cat const &src);

	// Destructeur
	~Cat();

	// Opperateur
	Cat	&operator=(Cat const &src);

/////////////////////

	void	makeSound(void) const;
	void	showData(void) const;
	void	setThoughts(std::string newThoughts[100]);
};


#endif