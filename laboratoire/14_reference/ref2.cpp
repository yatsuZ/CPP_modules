/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ref2.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 03:11:21 by yzaoui            #+#    #+#             */
/*   Updated: 2024/03/25 03:17:16 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

void	byPtr(std::string *str){ *str += " and ponies";}
void	byConstPtr(std::string const *str){ std::cout << *str << std::endl;}

void	byRef(std::string &str){ str += " and Ponies";}
void	byConstRef(std::string const &str){ std::cout << str << std::endl;}


int	main()
{
	std::string str = "i like buttuerflies";

	std::cout << str << std::endl;
	byPtr(&str);
	byConstPtr(&str);

	str = "i like otters";
	std::cout << str << std::endl;
	byRef(str);
	byConstRef(str);

	return (0);
}