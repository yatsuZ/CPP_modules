/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 13:41:59 by yzaoui            #+#    #+#             */
/*   Updated: 2024/06/07 16:23:30 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ScalarConverter.hpp"

static double	stringToDouble(const std::string &representation)
{
	const char *cstr;
	if (representation != "+inf" && representation != "-inf" && representation.length() > 1 && representation[representation.length() - 1] == 'f')
		cstr = representation.substr(0, representation.length() - 1).c_str();
	else if (representation.length() == 1 && !(representation[0] >= '0' && representation[0] <= '9'))
		return	(static_cast<double>(static_cast<char>(representation[0])));
	else
		cstr = representation.c_str();
	errno = 0;
	char* endptr;
	double result = strtof(cstr, &endptr);
	if (errno == ERANGE || endptr == cstr || *endptr != '\0')
		throw std::invalid_argument("Fail Conversion Invalide input");
	return result;
}

static long	stringToLong(const std::string &representation, const float refFloat)
{
	const char *cstr = representation.c_str();
	errno = 0;
	char* endptr;
	if (representation.length() == 1)
		return (static_cast<long>(refFloat));
	long result = strtol(cstr, &endptr, 10);
	if (errno == ERANGE || endptr == cstr || *endptr != '\0')
		result = static_cast<long>(refFloat);
	errno = 0;
	return result;
}

static void	printChar(const char refChar, const long refLong)
{
	if ((refLong <= 31 && refLong >= 0) || (refLong > 176 && refLong <= 255) )
		std::cout << "CHAR = Can't display" << std::endl;
	else if (refLong < 0 || refLong > 255)
		std::cout << "CHAR = impossible" << std::endl;
	else
		std::cout << "CHAR = " << refChar << std::endl;
}

static void	printInt(const int refInt, const std::string &representation, const long refLong)
{
	if (representation == "nan" || representation == "nanf" || refLong > 2147483647 || refLong < -2147483648)
		std::cout << "INT = impossible" << std::endl;
	else
		std::cout << "INT = " << refInt << std::endl;
}

static void	printFloatAndFloat(const float refFloat, const double refDouble, const long refLong, const std::string &representation)
{
	if (representation == "+inf" || representation == "+inff")
	{
		if (representation == "+inf")
			std::cout << "FLOAT = +" << refFloat << "f" << std::endl;
		else
			std::cout << "FLOAT = +" << refFloat << "f" << std::endl;
		std::cout << "DOUBLE = +" << refDouble << std::endl;
	}
	else if (refDouble == refLong)
	{
		std::cout << "FLOAT = " << refFloat << ".0f" << std::endl;
		std::cout << "DOUBLE = " << refDouble << ".0" << std::endl;
	}
	else
	{
		std::cout << "FLOAT = " << refFloat << "f" << std::endl;
		std::cout << "DOUBLE = " << refDouble << std::endl;
	}
}


void	ScalarConverter::convert(const std::string &representation)
{
	std::cout << "Default : " << representation << std::endl;

	double refDouble = stringToDouble(representation);
	float refFloat = static_cast<float>(refDouble);
	long refLong =stringToLong(representation, refFloat);
	int refInt = static_cast<int>(refLong);
	char refChar = static_cast<char>(refInt);

	printChar(refChar, refLong);
	printInt(refInt, representation, refLong);
	printFloatAndFloat(refFloat, refDouble, refLong, representation);
	std::cout << "--------------------------" << std::endl;
}

/////////////////////////////////////////////////////////////////////////////

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(ScalarConverter const &src)
{
	*this = src;
}

ScalarConverter::~ScalarConverter()
{
	
}

ScalarConverter	&ScalarConverter::operator=(ScalarConverter const &src)
{
	(void)	src;
	return (*this);
}
