/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   B.hpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 17:07:58 by yzaoui            #+#    #+#             */
/*   Updated: 2024/05/29 18:28:03 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef B_HPP
# define B_HPP

#include "./../Base.hpp"

class B: public Base
{
public:
	B();
	~B();
};

B::B()
{
	std::cout << GREEN << "B create" << NOCOLOR << std::endl;
}

B::~B()
{
}

#endif