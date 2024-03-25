/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sample2.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 21:57:09 by yzaoui            #+#    #+#             */
/*   Updated: 2024/03/25 01:32:28 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Sample1.class.h"

Sample1::Sample1(char p1, int p2, float p3 ): a1(p1), a2(p2), a3(p3) {
	std::cout << "Constructor called" << std::endl;
	std::cout << "this->a1 =" << this->a1 << std::endl;
	std::cout << "this->a2 =" << this->a2 << std::endl;
	std::cout << "this->a3 =" << this->a3 << std::endl;
	return;
}

Sample1::~Sample1(void) {
	std::cout << "Destructor called" << std::endl;
	return;
}
