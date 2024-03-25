/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sample.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 21:57:09 by yzaoui            #+#    #+#             */
/*   Updated: 2024/03/25 02:15:24 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Sample.class.h"

Sample::Sample( void ){
	std::cout << "Constructor called" << std::endl;
	Sample::_nbInst++;
	return;
}

Sample::~Sample(void) {
	std::cout << "Destructor called" << std::endl;
	Sample::_nbInst--;
	return;
}

int	Sample::getNbInst(void)
{
	return Sample::_nbInst;// pas this parceque cette ft est static donc non membre
}

int	Sample::_nbInst = 0;