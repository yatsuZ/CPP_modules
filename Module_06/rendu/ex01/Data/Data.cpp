/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 16:13:38 by yzaoui            #+#    #+#             */
/*   Updated: 2024/05/28 00:17:27 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data(void)
{
	this->_value = NULL;
}

Data::Data(Data const &src)
{
	*this = src;
}

Data::~Data()
{
	
}

Data	&Data::operator=(Data const &src)
{
	if (this != &src)
	{
		this->_value = src._value;
	}
	return (*this);
}

