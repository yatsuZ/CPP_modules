/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 21:51:26 by yzaoui            #+#    #+#             */
/*   Updated: 2024/06/11 19:28:07 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_TPP
# define MUTANTSTACK_TPP

#include "MutantStack.hpp"

template <typename T, typename Container>
MutantStack<T, Container>::MutantStack(void): _c(Container())
{
	// std::cout << GREEN "MutantStack Constructor" NOCOLOR << std::endl;
}

template <typename T, typename Container>
MutantStack<T, Container>::MutantStack(const MutantStack &src)
{
	*this = src;
}

template <typename T, typename Container>
MutantStack<T, Container>::MutantStack(const container_type &src): _c(src)
{
}

template <typename T, typename Container>
MutantStack<T, Container>& MutantStack<T, Container>::operator=(const MutantStack& src)
{
	if (this != &src)
		this->_c = src._c;
	return *this;
}


template <typename T, typename Container>
MutantStack<T, Container>::~MutantStack(void)
{
	// std::cout << RED "MutantStack Destructor" NOCOLOR << std::endl;
}

////////////////////////////////////////////////////////////////////////////

template <typename T, typename Container>
bool 		MutantStack<T, Container>::empty() const
{
	try
	{
		return (this->_c.empty());
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		throw MethodeContainerException("empty()");
	}
	return (true);
}

template <typename T, typename Container>
typename MutantStack<T, Container>::size_type	MutantStack<T, Container>::size(void) const
{
	if (this->empty())
		return (0);
	try
	{
		return (this->_c.size());
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		throw MethodeContainerException("size()");
	}
	return (true);
}

template <typename T, typename Container>
typename MutantStack<T, Container>::value_type& MutantStack<T, Container>::top(void)
{
	// if (this->empty())
	// 	throw EmptyContainerException();
	try
	{
		return this->_c.back();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		throw MethodeContainerException("back()");
	}
}

template <typename T, typename Container>
const typename MutantStack<T, Container>::value_type& MutantStack<T, Container>::top(void) const
{
	// if (this->empty())
	// 	throw EmptyContainerException();
	try
	{
		return this->_c.back();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		throw MethodeContainerException("back()");
	}
}

template <typename T, typename Container>
void	MutantStack<T, Container>::push_back(const value_type& __x)
{
	this->push(__x);
}

template <typename T, typename Container>
void	MutantStack<T, Container>::push(const value_type& __x)
{
	try
	{
		this->_c.push_back(__x);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		throw MethodeContainerException("push_back()");
	}
}

template <typename T, typename Container>
void	MutantStack<T, Container>::pop(void)
{
	try
	{
		if (this->empty() == false)
			this->_c.pop_back();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		throw MethodeContainerException("pop_back()");
	}
}

#endif