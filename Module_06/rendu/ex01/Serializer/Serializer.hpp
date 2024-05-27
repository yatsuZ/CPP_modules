/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 22:31:44 by yzaoui            #+#    #+#             */
/*   Updated: 2024/05/27 21:46:59 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include <iostream>
#include <stdint.h>

#define NOCOLOR "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"
#define PURPLE "\033[35m"

class Data;

class Serializer
{
private://classe canonique
	Serializer();
	Serializer(Serializer const &src);
	~Serializer();
	Serializer	&operator=(Serializer const &src);
public:
	static uintptr_t	serialize(Data *ptr);// convertie un ptr en ptr int unsigned
	static Data			*deserialize(uintptr_t raw);// fais linverse

};

#endif