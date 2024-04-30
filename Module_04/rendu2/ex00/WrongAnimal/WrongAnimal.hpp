/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 17:22:12 by yzaoui            #+#    #+#             */
/*   Updated: 2024/04/13 17:28:57 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include "./../Dog/Dog.hpp"

class WrongAnimal
{
protected:
	std::string	_type;
public:
	WrongAnimal();
	WrongAnimal(WrongAnimal const &src);

	// Destructeur
	~WrongAnimal();

	// Opperateur
	WrongAnimal	&operator=(WrongAnimal const &src);

/////////////////////

	void	 makeSound(void) const;

/////////////////////

	void		showType(void) const;
	std::string	getType(void) const;
};

#endif