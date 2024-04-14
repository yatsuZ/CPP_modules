/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 17:38:23 by yzaoui            #+#    #+#             */
/*   Updated: 2024/04/13 18:01:00 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include "./../Animal/Animal.hpp"

class Brain
{
private:
	std::string	_idea[100];
public:
	Brain();
	Brain(Brain const &src);

	// Destructeur
	~Brain();

	// Opperateur
	Brain	&operator=(Brain const &src);
//
	void	showData(void) const;
	void	setIdea(std::string newIdea[100]);
	std::string	*getIdea(void);
};


#endif