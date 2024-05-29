/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   A.hpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 17:07:48 by yzaoui            #+#    #+#             */
/*   Updated: 2024/05/29 18:28:11 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef A_HPP
# define A_HPP

#include "./../Base.hpp"

class A: public Base
{
public:
	A();
	~A();
};

A::A()
{
	std::cout << YELLOW << "A create" << NOCOLOR << std::endl;
}

A::~A()
{
}

#endif