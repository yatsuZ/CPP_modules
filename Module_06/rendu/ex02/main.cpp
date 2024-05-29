/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 17:51:14 by yzaoui            #+#    #+#             */
/*   Updated: 2024/05/29 20:47:19 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "folowingFunction.hpp"

int	main(void)
{
	Base	*stockage = generate();
	Base	*ptr_null = NULL;
	// connaitre le type de stockage  sans include type info en c++98
	identify(stockage);
	identify(*(ptr_null));
	identify(*stockage);
	return (0);
}