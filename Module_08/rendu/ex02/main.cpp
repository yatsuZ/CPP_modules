/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 12:49:20 by yzaoui            #+#    #+#             */
/*   Updated: 2024/06/22 16:06:25 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./MutantStack/MutantStack.hpp"

void	ft_testConstrcutor(void)
{
	try
	{
		std::cout << YELLOW "STACK TEST : " NOCOLOR << std::endl;
		std::deque<int> mydeque (3,100);          // deque with 3 elements
		std::vector<int> myvector (2,200);        // vector with 2 elements
		
		std::stack<int> first;                    // empty stack
		std::stack<int> second (mydeque);         // stack initialized to copy of deque
		
		std::stack<int,std::vector<int> > third;  // empty stack using vector
		std::stack<int,std::vector<int> > fourth (myvector);
		std::cout << "size of first: " << first.size() << '\n';
		std::cout << "size of second: " << second.size() << '\n';
		std::cout << "size of third: " << third.size() << '\n';
		std::cout << "size of fourth: " << fourth.size() << '\n';
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << GREEN "------------------------------" NOCOLOR << std::endl;
	try
	{
		std::cout << BLUE "MUTANSTACK TEST : " NOCOLOR << std::endl;
		std::deque<int> mydeque (3,100);          // deque with 3 elements
		std::vector<int> myvector (2,200);        // vector with 2 elements
		
		MutantStack<int> first;                    // empty stack
		MutantStack<int> second (mydeque);         // stack initialized to copy of deque
		
		MutantStack<int,std::vector<int> > third;  // empty stack using vector
		MutantStack<int,std::vector<int> > fourth (myvector);
		
		std::cout << "size of first: " << first.size() << '\n';
		std::cout << "size of second: " << second.size() << '\n';
		std::cout << "size of third: " << third.size() << '\n';
		std::cout << "size of fourth: " << fourth.size() << '\n';
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void	ft_testWrongContainer(void)
{
	try
	{
		std::cout << YELLOW "STACK TEST : " NOCOLOR << std::endl;
		// std::stack<int, int> first;                    // Error a la compilation
		// std::cout << "size of first: " << first.size() << '\n';
		std::stack<int, std::string> second;
		
		second.push(48);
		std::cout << "size of second: " << second.size() << '\n';

	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << GREEN "------------------------------" NOCOLOR << std::endl;
	try
	{
		std::cout << BLUE "MUTANSTACK TEST : " NOCOLOR << std::endl;
		
		// MutantStack<int, int> first;                    // Error a la compilation
		// std::cout << "size of first: " << first.size() << '\n';
		MutantStack<int, std::string> second;

		second.push(48);
		std::cout << "size of second: " << second.size() << '\n';

	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void	ft_testMethodEmpty(void)
{
	try
	{
		std::cout << YELLOW "STACK TEST : " NOCOLOR << std::endl;
		std::stack<int> mystack;
		int sum (0);

		mystack.top();

		for (int i=1;i<=10;i++) mystack.push(i);
		while (!mystack.empty())
		{
			std::cout << YELLOW "total: " NOCOLOR << sum << "\t| " YELLOW "size = " NOCOLOR << mystack.size() << std::endl;
			sum += mystack.top();
			mystack.pop();
		}
		std::cout << YELLOW "total: " NOCOLOR << sum << "\t| " YELLOW "size = " NOCOLOR << mystack.size() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << GREEN "------------------------------" NOCOLOR << std::endl;
	try
	{
		std::cout << BLUE "MUTANSTACK TEST : " NOCOLOR << std::endl;
		MutantStack<int> mystack;
		int sum (0);

		mystack.top();// comment gerer ?

		for (int i=1;i<=10;i++) mystack.push(i);
		while (!mystack.empty())
		{
			std::cout << BLUE "total: " NOCOLOR << sum << "\t| " BLUE "size = " NOCOLOR << mystack.size() << std::endl;
			sum += mystack.top();
			mystack.pop();
		}
		std::cout << BLUE "total: " NOCOLOR << sum << "\t| " BLUE "size = " NOCOLOR << mystack.size() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void	ft_testSubject(void)
{
	try
	{
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);
		MutantStack<int> mstack3 = mstack;
		MutantStack<int>::iterator it = mstack3.begin();
		MutantStack<int>::iterator ite = mstack3.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
		MutantStack<int> mstack2(mstack);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}

void	ft_testSubject2(void)
{
	try
	{
		MutantStack2<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);
		MutantStack2<int> mstack3 = mstack;
		MutantStack2<int>::iterator it = mstack3.begin();
		MutantStack2<int>::iterator ite = mstack3.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
		MutantStack2<int> mstack2(mstack);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}

int main(void)
{
	// ft_testConstrcutor();
	// ft_testWrongContainer();
	// ft_testMethodEmpty();
	ft_testSubject();
	return 0;
}
