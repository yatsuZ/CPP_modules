/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 13:41:51 by yzaoui            #+#    #+#             */
/*   Updated: 2024/05/27 16:01:43 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
 #define SCALARCONVERTER_HPP

#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <cerrno>
#include <limits>
#include <iomanip>
#include <locale>


#define NOCOLOR "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"
#define PURPLE "\033[35m"

typedef enum e_type
{
	INT ,
	FLOAT ,
	CHAR ,
	DOUBLE
}	t_type;


class ScalarConverter
{
private://classe canonique
	ScalarConverter();
	ScalarConverter(ScalarConverter const &src);
	~ScalarConverter();
	ScalarConverter	&operator=(ScalarConverter const &src);
public:
	static	void	convert(const std::string &representation);
};

#endif