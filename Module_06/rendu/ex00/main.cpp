/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 13:41:07 by yzaoui            #+#    #+#             */
/*   Updated: 2024/05/27 15:51:04 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ScalarConverter/ScalarConverter.hpp"


void	testInt(void)
{
	ScalarConverter::convert("9223372036854775807");
	ScalarConverter::convert("-9223372036854775807");
// + max + 1
	ScalarConverter::convert("2147483648");
// - max - 1
	ScalarConverter::convert("-2147483649");
// + max
	ScalarConverter::convert("2147483647");
// - max
	ScalarConverter::convert("-2147483648");
// + random number
	ScalarConverter::convert("75321");
// - random number
	ScalarConverter::convert("-75321");
// 0
	ScalarConverter::convert("0");
}

void	testFloat(void)
{
// + random number
	ScalarConverter::convert("4.2");
// - random number
	ScalarConverter::convert("-4.2");
// 0
	ScalarConverter::convert("0");
// +inff
	ScalarConverter::convert("+inff");
// -inff
	ScalarConverter::convert("-inf");
// nanf
	ScalarConverter::convert("nanf");
}

void	testChar(void)
{
	std::string str;
	for (char c = 0; c < std::numeric_limits<char>::max(); c++)
	{
		str = c;
		ScalarConverter::convert(static_cast<std::string const>(str));
	}
}

void	testAllInt(void)
{
	std::string str;
	for (int i = std::numeric_limits<int>::min(); i < std::numeric_limits<int>::max(); i++)
	{
		std::ostringstream oss;
		oss << i;
		str = oss.str();
		ScalarConverter::convert(static_cast<std::string const>(str));
	}
}

void	testDouble(void)
{
	ScalarConverter::convert("1.123456789012345");
	ScalarConverter::convert("0.5");
	ScalarConverter::convert("12.25");
	ScalarConverter::convert("17.125");
	ScalarConverter::convert("-900.5");
	ScalarConverter::convert("-0.2594123587");
	ScalarConverter::convert("-645.125");
	ScalarConverter::convert("+inf");
	ScalarConverter::convert("-inf");
	ScalarConverter::convert("nan");
}

int	main(int argc, char **argv)
{
	try
	{
		if (argc > 1)
			ScalarConverter::convert(argv[1]);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	// testInt();
	// testChar();
	// testFloat();
	// testDouble();
	// testAllInt();
	return (0);
}
