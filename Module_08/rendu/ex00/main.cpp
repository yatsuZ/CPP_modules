/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 12:49:20 by yzaoui            #+#    #+#             */
/*   Updated: 2024/06/22 15:14:40 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

void	ft_test_00(void)
{
	static const int arr[] = {1, 2, 3, 4, 5};
	std::vector<int> vec(arr, arr + sizeof(arr) / sizeof(arr[0]) );

	try
	{
		std::vector<int>::iterator vec_it = easyfind(vec, 3);
		std::cout << "Found in vector: " << *vec_it << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		easyfind(vec, 42);
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "------------------------------------------" << std::endl;
};

void	ft_test_01(void)
{
	static const int arr2[] = {10, 20, 30, 40, 50};
	std::list<int> lst(arr2, arr2 + sizeof(arr2) / sizeof(arr2[0]) );


	try
	{
		std::list<int>::iterator lst_it = easyfind(lst, 50);
		std::cout << "Found in list: " << *lst_it << std::endl;
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << "------------------------------------------" << std::endl;
};

/*
// Error test
void	ft_test_02(void)
{
	static const std::string arr2[] = {"Maince", "C", "Pa", "1", "int", "!"};
	std::list<std::string> lst(arr2, arr2 + sizeof(arr2) / sizeof(arr2[0]) );

	try {
		std::list<std::string>::iterator lst_it = easyfind(lst, 20);
		std::cout << "Found in list: " << *lst_it << std::endl;
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
};

void	ft_test_03(void)
{
	int	nbr = 1;
	int &arr = nbr;

	try {
		int res = easyfind(arr, 3);
		std::cout << "Found in vector: " << res << std::endl;
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
};
*/

void	ft_test_04(void)
{
	try
	{
		// unsigned int size = std::numeric_limits<int>::max();
		unsigned int size = std::numeric_limits<int>::max() / 250;
		int	recherche = 1;
		std::deque<int> contenaire;
		srand(time(NULL));

		for (unsigned int i = 0; i < size; i++)
		{
			const int value = rand() % size;
			// std::cout << value << std::endl;
			if (value == recherche)
				std::cout << "Il y a " << recherche << " dans le contenair." << std::endl;
			contenaire.push_back(value);
		}
		std::cout << "jai fini dajouter les nombre" << std::endl; 
		std::deque<int>::iterator lst_it = easyfind(contenaire, recherche);
		std::cout << "Found in deque: " << *lst_it << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "------------------------------------------" << std::endl;
};

int main()
{
	ft_test_00();
	ft_test_01();
	// ft_test_02();
	ft_test_04();
	return 0;
}
