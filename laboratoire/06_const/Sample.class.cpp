/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sample.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 21:57:09 by yzaoui            #+#    #+#             */
/*   Updated: 2024/03/24 22:40:02 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Sample.class.h"

Sample::Sample(float const f) : pi(f), qd(42) {
	std::cout << "Constructor called" << std::endl;

	return;
}

Sample::~Sample(void) {
	std::cout << "Destructor called" << std::endl;
	return;
}

void	Sample::bar(void) const
{
	std::cout << "this->pi = " << this->pi << std::endl;
	// this->qd = -1; // ERROR !! car j'ai mis const !!!
	std::cout << "this->qd = " << this->qd << std::endl;
	return;
}