/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 22:31:36 by yzaoui            #+#    #+#             */
/*   Updated: 2024/05/27 22:39:36 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Serializer.hpp"


Serializer::Serializer()
{
}
Serializer::Serializer(Serializer const &src)
{
	*this = src;
}
Serializer::~Serializer()
{
}
Serializer	&Serializer::operator=(Serializer const &src)
{
	(void)	src;
	return (*this);
}
// convertie un ptr en ptr int unsigned
uintptr_t	Serializer::serialize(Data *ptr)
{
	return(reinterpret_cast<uintptr_t>(ptr));
}
// fais linverse
Data	*Serializer::deserialize(uintptr_t raw)
{
	return(reinterpret_cast<Data *>(raw));
}
