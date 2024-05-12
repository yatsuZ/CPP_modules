/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 00:29:45 by yzaoui            #+#    #+#             */
/*   Updated: 2024/05/12 17:14:40 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class A {};
class B {};

class C {

public:
				C( A const & _) {return;}
	explicit	C( B const & _) {return;}
};

void	f( C const & _)
{
	return ;
}

int	main(void)
{
	f( A());// OK
	// f( B());// Non car doit etre explecite
	return 0;
}
