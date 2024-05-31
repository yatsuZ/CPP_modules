/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 23:31:31 by yzaoui            #+#    #+#             */
/*   Updated: 2024/05/31 20:48:18 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>
#include <exception>
#include <stdexcept>

template<typename T>
class Array {
private:
	T				*_tab;
	unsigned int	_size;
public:
	Array();
	
	Array(unsigned int n);
	
	Array(Array const &src);
	
	~Array();

	unsigned int	size(void) const;

	T	*getTab(void);
	T& operator[](unsigned int index);
	const T& operator[](unsigned int index) const;

	Array<T>	&operator=(Array<T> const &src);
};

template<typename T>
Array<T>::Array(void)
{
	std::cout << "Array constructor default" << std::endl;
	this->_size = 0;
	this->_tab = NULL;
};

template<typename T>
Array<T>::Array(unsigned int n)
{
	try
	{
		this->_size = n;
		this->_tab = new T[n];
		for (unsigned int i = 0; i < n; i++)
		{
			this->_tab[i] = T();
		}
		return ;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	this->_size = 0;
	this->_tab = NULL;
};

template<typename T>
Array<T>::~Array()
{
	try
	{
		delete[] this->_tab;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
};

template<typename T>
unsigned int	Array<T>::size(void) const
{
	return (this->_size);
};

template<typename T>
T	*Array<T>::getTab(void)
{
	return (this->_tab);
};

template<typename T>
T	&Array<T>::operator[](unsigned int index) {
	if (index >= this->_size)
		throw std::out_of_range("Index out of range");
	return _tab[index];
};

template<typename T>
const T	&Array<T>::operator[](unsigned int index) const {
	if (index >= this->_size)
		throw std::out_of_range("Index out of range");
	return _tab[index];
};

template<typename T>
Array<T>::Array(Array const &src)
{
	this->_size = 0;
	this->_tab = NULL;
	*this = src;
};

template<typename T>
Array<T>	&Array<T>::operator=(Array<T> const &src)
{
	try
	{
		delete[] this->_tab;
		this->_size = src.size();
		this->_tab = new T[this->_size];
		for (unsigned int i = 0; i < this->_size; i++)
		{
			this->_tab[i] = src[i];// Je ne veux pas une copy de reference je veux juste copuer la valeur
		}
		return (*this);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (*this);
}

///////////////////////////////////////////////////////////////////

template<typename T>
void	Show(const T var)
{
	try
	{
		std::cout << var << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
};

template<typename T>
void	iter(T *tab, size_t lenght, void (*f)(T&))
{
	if (!tab)
		return ;
	try
	{
		for (size_t i = 0; i < lenght; i++)
			f(tab[i]);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
};

#endif