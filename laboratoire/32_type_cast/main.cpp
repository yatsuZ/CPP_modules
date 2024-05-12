/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 00:29:45 by yzaoui            #+#    #+#             */
/*   Updated: 2024/05/12 17:13:23 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Foo {

public:
	Foo (float const v) : _v(v) {}
	float getV(void) {return this->_v;}
	
	operator float() {return this->_v;}
	operator int() { return static_cast<int>(this->_v);}

private:
	float	_v;
};

int	main(void)
{
	Foo		a(420.024f);
	float	b = a;
	int		c = a;

	std::cout << a.getV() << std::endl;
	std::cout << b << std::endl;
	std::cout << c << std::endl;

	return 0;
}
