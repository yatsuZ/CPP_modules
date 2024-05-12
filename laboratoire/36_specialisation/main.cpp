/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 00:29:45 by yzaoui            #+#    #+#             */
/*   Updated: 2024/05/13 00:20:59 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Pair.class.hpp"

int	main(void)
{
	Pair<int, int>		p1(4, 2);
	Pair< std::string, float>	p2(std::string("Pi"), 3.14f);
	Pair<float, bool>			p3(4.2f, true);
	Pair<bool, bool>			p4(true, false);

	std::cout << p1 << std::endl;
	std::cout << p2 << std::endl;
	std::cout << p3 << std::endl;
	std::cout << p4 << std::endl;

}