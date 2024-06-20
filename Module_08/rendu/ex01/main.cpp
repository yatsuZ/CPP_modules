/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 12:49:20 by yzaoui            #+#    #+#             */
/*   Updated: 2024/06/20 20:00:24 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Span/Span.hpp"

void	ft_test00(void)
{
	std::cout << YELLOW "My test normal with max and min int" NOCOLOR << std::endl;
	Span	test(3);

	test.addNumber(std::numeric_limits<int>::min());
	test.addNumber(std::numeric_limits<int>::max());
	test.addNumber(10);
	try
	{
		test.addNumber(0);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	test.showSpan();

	try
	{
		std::cout << "shortestSpan = " << test.shortestSpan() << std::endl;
		std::cout << "longestSpan = " << test.longestSpan() << std::endl;
		std::cout << "-----------------" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void	ft_test01(void)
{
	std::cout << YELLOW "Test of subject" NOCOLOR << std::endl;
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	sp.showSpan();

	try
	{
		std::cout << "shortestSpan = " << sp.shortestSpan() << std::endl;
		std::cout << "longestSpan = " << sp.longestSpan() << std::endl;
		std::cout << "-----------------" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void	ft_test02(void)
{
	unsigned int size = std::numeric_limits<int>::max();
	std::cout << YELLOW "Test with "<< size << " value in Span" NOCOLOR << std::endl;
	try
	{
		Span bcp(size);
		srand(time(NULL));
		for (unsigned int i = 0; i < size; i++)
		{
			const int value = rand();
			bcp.addNumber(value);
		}
		std::cout << "shortestSpan = " << bcp.shortestSpan() << std::endl;
		std::cout << "longestSpan = " << bcp.longestSpan() << std::endl;
		std::cout << "-----------------" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void	ft_test03(void)
{
	std::cout << YELLOW "Test with one call of init number in Span" NOCOLOR << std::endl;

	static const int arr[] = {87, 0, 1, 12, 9, -1, 10000};
	std::vector<int> numbers (arr, arr + sizeof(arr) / sizeof(arr[0]) );
	Span allnumber(7);
	allnumber.addNumbers(numbers);
	allnumber.showSpan();
	try
	{
		std::cout << "shortestSpan = " << allnumber.shortestSpan() << std::endl;
		std::cout << "longestSpan = " << allnumber.longestSpan() << std::endl;
		std::cout << "-----------------" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}


int main(int argc, char **argv)
{
	static void (*ft[4])(void) = {ft_test00, ft_test01, ft_test02, ft_test03};
	static std::string selection[4] = {"0", "1", "2", "3"};


	if (argc == 1)
	{
		std::cout << MAGENTA "You can choose a function test with a number between 0 and 3 in parametre" NOCOLOR << std::endl;
	}
	for (int select = 1; select < argc; select++)
	{
		for (int i = 0; i < 4; i++)
		{
			if (std::string(argv[select]) == selection[i])
			{
				try
				{
					std::cout << BLUE "FT_TEST0" << i << " Va etre executer : "<< NOCOLOR << std::endl;
					ft[i]();
				}
				catch(const std::exception& e)
				{
					std::cerr << e.what() << '\n';
				}
			}
		}
	}
	return 0;
}
