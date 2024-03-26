/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 18:34:52 by yzaoui            #+#    #+#             */
/*   Updated: 2024/03/25 23:33:23 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Sample.class.hpp"

int	main()
{
	Sample	instance;

	instance.bar(500);
	instance.bar('A');
	instance.bar((float)3.14);
	instance.bar(instance);
	return 0;
}