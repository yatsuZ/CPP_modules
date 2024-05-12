/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 00:29:45 by yzaoui            #+#    #+#             */
/*   Updated: 2024/05/13 01:20:42 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <map>
#include <vector>
#include <list>


class IOperation;

int	test1(void)
{
	std::list<int>						lst1;
	std::map<std::string, IOperation*>	map1;
	std::vector<int>					v1;
	std::vector<int>					v2(42, 100);


	lst1.push_back(1);
	lst1.push_back(17);
	lst1.push_back(42);

	// map1["opA"] = new OperationA;
	// map1["opB"] = new OperationB;


	std::list<int>::const_iterator	it;
	std::list<int>::const_iterator	ite = lst1.end();

	for (it = lst1.begin(); it != ite; ++it)
		std::cout << *it << std::endl;
	
	return (0);
}

#include <algorithm>

void	displayInt(int i)
{
	std::cout << i << std::endl;
}

int	test2(void)
{
	std::list<int>	lst;

	lst.push_back(10);
	lst.push_back(23);
	lst.push_back(3);
	lst.push_back(17);
	lst.push_back(20);

	for_each(lst.begin(), lst.end(), displayInt);

	return (0);
}

int	main(void)
{
	test1();
	std::cout << "-----------------------" << std::endl;
	test2();
	return (0);
}