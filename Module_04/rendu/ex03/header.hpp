/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 23:57:40 by yzaoui            #+#    #+#             */
/*   Updated: 2024/04/14 00:09:41 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_HPP
# define HEADER_HPP

#include <iostream>
#include <string.h>

#define NOCOLOR "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"
#define PURPLE "\033[35m"

#include "./All_Materiaux/IMateriaSource.hpp"
#include "./All_Materiaux/MateriaSource/MateriaSource.hpp"
#include "./All_Materiaux/AMateria/AMateria.hpp"
#include "./All_Materiaux/Materiaux/Ice.hpp"
#include "./All_Materiaux/Materiaux/Cure.hpp"
#include "./All_Character/Character/Character.hpp"
#include "./All_Character/ICharacter.hpp"

#endif