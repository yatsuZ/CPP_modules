/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 16:11:15 by yzaoui            #+#    #+#             */
/*   Updated: 2024/06/07 17:10:44 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
# define DATA_HPP

#include <iostream>
#include <stdint.h>
#include <string>

#define NOCOLOR "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"
#define PURPLE "\033[35m"

class Data
{
private:
	void	*_value;
public:
	Data(void);
	Data(Data const &src);
	~Data();
	Data	&operator=(Data const &src);

	template<typename T>
	T getValue() const;
	template<typename T> Data(T value);
};

template<typename T>// Les template doivent etre definie directement dans le header
Data::Data(T value)
{
	std::cout << GREEN << "value = " << value << NOCOLOR << std::endl;
	std::cout << MAGENTA << "value est stockée dans la classe Data sous un poiteur void. " << NOCOLOR << std::endl;
	this->_value = reinterpret_cast<void *>(&value);
}

template<typename T>
T Data::getValue() const {
	return *reinterpret_cast<T*>(_value);
}


#endif