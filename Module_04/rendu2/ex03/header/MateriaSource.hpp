/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 21:41:13 by yzaoui            #+#    #+#             */
/*   Updated: 2024/04/30 16:29:27 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include "./IMateriaSource.hpp"
#include "./AMateria.hpp"

class MateriaSource: public IMateriaSource
{
private:
	AMateria	*(_inventaire[4]);
public:
	MateriaSource();
	~MateriaSource();
	MateriaSource(MateriaSource const &src);
	MateriaSource	&operator=(MateriaSource const &src);

	void learnMateria(AMateria* newMateria);
	AMateria* createMateria(std::string const & type);
};

#endif