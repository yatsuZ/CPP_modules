/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sample2.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 21:57:09 by yzaoui            #+#    #+#             */
/*   Updated: 2024/03/25 01:29:55 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Sample2.class.h"

Sample2::Sample2(void): foo(12) {
	std::cout << "Constructor called" << std::endl;

	this->bar();
	return;
}

Sample2::~Sample2(void) {
	std::cout << "Destructor Sample2 called" << std::endl;
	return;
}

void	Sample2::bar(void) const {
	std::cout << "Sample2 bar called" << std::endl;
	std::cout << "Sample2.foo = " << this->foo << std::endl;
}