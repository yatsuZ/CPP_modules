/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 18:34:52 by yzaoui            #+#    #+#             */
/*   Updated: 2024/03/24 22:22:46 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Sample1.class.h"
#include "./Sample2.class.h"

int	main()
{
	std::cout << "Sample 1 :" << std::endl;
	Sample1	instance1('c', 1, 2.3);
	std::cout << "Sample 2 :" << std::endl;
	Sample2	instance2('a', 0, 3.14);

	return 0;
}