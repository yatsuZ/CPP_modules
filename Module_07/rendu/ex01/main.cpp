/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 17:09:50 by yzaoui            #+#    #+#             */
/*   Updated: 2024/05/30 22:35:05 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./iter.hpp"

void	Add(int &var)
{
	try
	{
		++var;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
};

///////////////////////////////////////////////////////

// CRASH
void	test_invalideLenght(void)
{
	try
	{
		// error *** stack smashing detected ***: terminated
		int tab[] = {10, 78, -12, 0, -50};
		
		int	*tab_ptr = tab;
		int	**tab_ptr_ptr = &tab_ptr;
		iter(tab_ptr, 500, Add);
		std::cout << "--------------" << std::endl;
		iter(tab_ptr_ptr, 10, Show<int>);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void	test_NULL(void)
{
	int	*tab_ptr = NULL;
	int	**tab_ptr_ptr = &tab_ptr;
	iter(tab_ptr, 5, Add);
	std::cout << "---" << std::endl;
	iter(tab_ptr_ptr, 5, Show<int>);
}

void	testIntTab(void)
{
	int tab[] = {10, 78, -12, 0, -50};
	
	int	*tab_ptr = tab;
	int	**tab_ptr_ptr = &tab_ptr;
	iter(tab_ptr, 5, Add);
	std::cout << "---" << std::endl;
	iter(tab_ptr_ptr, 5, Show<int>);
}

void	testStdString(void)
{
	std::string tab[] = {"Test", "const", "std::string"};
	
	std::string	*tab_ptr = tab;
	iter(tab_ptr, 3, Show<std::string>);
}

void	testConstChar(void)
{
	const char* tab[] = {"Test", "const", "char *"};
	
	const char	**tab_ptr = tab;
	iter(tab_ptr, 3, Show<const char*>);
}


int main( void ) 
{
	// test_invalideLenght();// Casse
	std::cout << GREEN << "test pointeur NULL : " << NOCOLOR << std::endl << std::endl;
	test_NULL();
	std::cout << std::endl << "------------------" << std::endl << GREEN << "test int tab : " << std::endl << NOCOLOR << std::endl;
	testIntTab();
	std::cout << std::endl << "------------------" << std::endl << GREEN << "test string tab : " << std::endl << NOCOLOR << std::endl;
	testStdString();
	std::cout << std::endl << "------------------" << std::endl << GREEN << "test const char * : " << std::endl << NOCOLOR << std::endl;
	testConstChar();
	return 0;
}