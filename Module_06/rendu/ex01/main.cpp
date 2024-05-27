/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 13:41:07 by yzaoui            #+#    #+#             */
/*   Updated: 2024/05/28 00:23:24 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Data/Data.hpp"
#include "./Serializer/Serializer.hpp"
#include <stdint.h>
#include <typeinfo>


int	main(void)
{
// donnée + son type
	std::string var = "string";
	typedef std::string TypeOfVAR;

/// je stock dans data * void puis je verifie que je peut recuperer le contenue

	Data		test(var);

	TypeOfVAR	Value = (test).getValue<TypeOfVAR>();
	std::cout << "stockage data = " << Value << std::endl;

////////////////////////////////////////////////////////// je mets sous format de pointeur

	Data		*test_ptr = &test;
	std::cout << "test ptr = " << test_ptr << std::endl;

// ////////////////////////////////////////////////////////// je serialize

	uintptr_t serialize = Serializer::serialize(test_ptr);
	std::cout << "serialize = " << serialize << std::endl;

////////////////////////////////////////////////////////// je deserialize a partir uintptr_t

	Data	*deserialize = Serializer::deserialize(serialize);
	std::cout << "deserialize = " << deserialize << std::endl;

////////////////////////////////////////////////////////// je re affiche ma donné

	Value = (*deserialize).getValue<TypeOfVAR>();
	std::cout << "stockage data = " << Value << std::endl;

	return (0);
}
