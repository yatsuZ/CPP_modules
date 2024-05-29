/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   C.hpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 17:08:44 by yzaoui            #+#    #+#             */
/*   Updated: 2024/05/29 18:28:06 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef C_HPP
# define C_HPP

#include "./../Base.hpp"

class C: public Base
{
public:
	C();
	~C();
};

C::C()
{
	std::cout << BLUE << "C create" << NOCOLOR << std::endl;
}

C::~C()
{
}

#endif