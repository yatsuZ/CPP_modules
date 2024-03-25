/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sample1.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 21:57:09 by yzaoui            #+#    #+#             */
/*   Updated: 2024/03/25 01:28:52 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Sample1.class.h"

Sample1::Sample1(void): foo(12) {
	std::cout << "Constructor called" << std::endl;

	this->bar();
	return;
}

Sample1::~Sample1(void) {
	std::cout << "Destructor Sample1 called" << std::endl;
	return;
}

void	Sample1::bar(void) const {
	std::cout << "Sample1 bar called" << std::endl;
	std::cout << "Sample1.foo = " << this->foo << std::endl;
}