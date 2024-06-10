/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 21:51:26 by yzaoui            #+#    #+#             */
/*   Updated: 2024/06/10 21:59:37 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_TPP
#define MUTANTSTACK_TPP

#include "MutantStack.hpp"

template<typename T>
MutantStack<T>::MutantStack(void)
{
	std::cout << GREEN "MutantStack Constructor" NOCOLOR << std::endl;
}

template<typename T>
MutantStack<T>::~MutantStack(void)
{
	std::cout << RED "MutantStack Destructor" NOCOLOR << std::endl;
}

#endif