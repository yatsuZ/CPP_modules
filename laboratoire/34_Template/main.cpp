/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 00:29:45 by yzaoui            #+#    #+#             */
/*   Updated: 2024/05/12 18:06:03 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

template< typename T>
T const &	max(T const & x, T const & y)
{
	return ( x>=y ? x : y);
}

int	foo(int x)
{
	std::cout << "Long computing time" << std::endl;
	return x;
}

int	main(void)
{
	int	a = 21;
	int b = 42;

	std::cout << "Max of " << a << " and " << b << " is ";
	std::cout << max<int>(a, b) << std::endl;// explicite
	
	std::cout << "Max of " << a << " and " << b << " is ";
	std::cout << max(a, b) << std::endl;     // Implicite
	
	
	float c = -1.7f;
	float d = 4.2f;

	std::cout << "Max of " << c << " and " << d << " is ";
	std::cout << max<float>(c, d) << std::endl;// explicite
	
	std::cout << "Max of " << a << " and " << b << " is ";
	std::cout << max(d, c) << std::endl;     // Implicite

	char e = 'a';
	char f = 'z';

	std::cout << "Max of " << e << " and " << f << " is ";
	std::cout << max<char>(e, f) << std::endl;// explicite
	
	std::cout << "Max of " << e << " and " << f << " is ";
	std::cout << max(e, f) << std::endl;     // Implicite

	int	ret = max<int>(foo(a), foo(b));
	std::cout << "Max of " << a << " and " << b << " is ";
	std::cout << ret << std::endl;     // Implicite
}