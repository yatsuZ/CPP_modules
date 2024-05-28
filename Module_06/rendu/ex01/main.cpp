/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 13:41:07 by yzaoui            #+#    #+#             */
/*   Updated: 2024/05/28 17:13:37 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Data/Data.hpp"
#include "./Serializer/Serializer.hpp"
#include <stdint.h>


int	main(void)
{
	// Serializer	test;// Error ne peut pas linstancier
// donnée + son type
	std::string var = "string";
	typedef std::string TypeOfVAR;

/// je stock dans data * void puis je verifie que je peut recuperer le contenue

	Data		test(var);

	TypeOfVAR	Value = (test).getValue<TypeOfVAR>();
	std::cout << "value de data = " << Value << std::endl << "------------------------" << std::endl << std::endl;

////////////////////////////////////////////////////////// je mets sous format de pointeur

	Data		*test_ptr = &test;
	std::cout << "L'adresse de la varaible DATA = " << test_ptr << std::endl;
	std::cout << std::endl << "------------------------" << std::endl << std::endl;

// ////////////////////////////////////////////////////////// je serialize

	uintptr_t serialize = Serializer::serialize(test_ptr);
	std::cout << "Je serialize l'adresse = " << serialize << std::endl;
	std::cout << std::endl << "------------------------" << std::endl << std::endl;

////////////////////////////////////////////////////////// je deserialize a partir uintptr_t

	Data	*deserialize = Serializer::deserialize(serialize);
	std::cout << "Je deserialize l'uintptr_t = " << deserialize << std::endl;
	std::cout << std::endl << "------------------------" << std::endl << std::endl;

////////////////////////////////////////////////////////// je re affiche ma donné

	Value = (*deserialize).getValue<TypeOfVAR>();
	std::cout << "value du deserialize qui est un pointeur DATA" << std::endl;
	std::cout << "value = " << Value << std::endl << "------------------------" << std::endl << std::endl;

	return (0);
}
