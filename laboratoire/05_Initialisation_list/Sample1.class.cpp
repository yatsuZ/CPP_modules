/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sample1.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 21:57:09 by yzaoui            #+#    #+#             */
/*   Updated: 2024/03/25 01:26:29 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Sample1.class.h"

Sample1::Sample1(char p1, int p2, float p3 ) {
	std::cout << "Constructor called" << std::endl;

	this->a1 = p1;
	std::cout << "this->a1 =" << this->a1 << std::endl;

	this->a2 = p2;
	std::cout << "this->a2 =" << this->a2 << std::endl;

	this->a3 = p3;
	std::cout << "this->a3 =" << this->a3 << std::endl;

	return;
}

Sample1::~Sample1(void) {
	std::cout << "Destructor called" << std::endl;
	return;
}
