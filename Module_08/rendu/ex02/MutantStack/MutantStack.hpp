/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 21:32:25 by yzaoui            #+#    #+#             */
/*   Updated: 2024/06/12 21:22:29 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <iostream>
#include <deque>
#include <exception>
#include <vector>
#include <stack>

#define NOCOLOR "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"
#define PURPLE "\033[35m"


////////////

template <class T, class Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
public:
	// Types membres
	typedef T value_type;
	typedef Container container_type;
	typedef typename Container::size_type	size_type;
	typedef typename Container::iterator	iterator;
private:
	class MethodeContainerException : public std::exception
	{
	private:
		std::string _message;
	public:
		MethodeContainerException(const std::string &additionalInfo)
		{
			_message = std::string("the MutantStack container had a problem with the method: " MAGENTA) + additionalInfo + NOCOLOR + "." ;
		}
		MethodeContainerException(void)
		{
			_message = std::string("the MutantStack container had a problem with the method.");
		}
		virtual ~MethodeContainerException() throw() {}
		virtual const char *what() const throw()
		{
			return _message.c_str();
		}
	};
	class EmptyContainerException : public std::exception
	{
		virtual const char *what() const throw()
		{
			return (RED "the MutantStack container is empty." NOCOLOR);
		}
	};
	void				push_back(const value_type& __x);

	Container _c;

public:
	MutantStack(void);
	MutantStack(const MutantStack &src);
	MutantStack(const container_type &src);
	MutantStack	&operator=(const MutantStack &src);
	~MutantStack(void);

	bool 				empty() const;
	size_type			size(void) const;
	value_type& 		top();
	const value_type&	top() const;
	void				push(const value_type& __x);
	void 				pop();

///////////////////
	iterator	begin(void);
	iterator	end(void);

};

/////////////////////// Each of these operator overloads calls the same operator on the underlying container objects.

template <typename T, typename Container>
bool operator== (const MutantStack<T, Container> & lhs, const MutantStack<T, Container> & rhs)
{
	return (lhs._c == rhs._c);
}

template <typename T, typename Container>
bool operator!= (const MutantStack<T, Container> & lhs, const MutantStack<T, Container> & rhs)
{
	return (lhs._c != rhs._c);
}

template <typename T, typename Container>
bool operator< (const MutantStack<T, Container> & lhs, const MutantStack<T, Container> & rhs)
{
	return (lhs._c < rhs._c);
}

template <typename T, typename Container>
bool operator<= (const MutantStack<T, Container> & lhs, const MutantStack<T, Container> & rhs)
{
	return (lhs._c <= rhs._c);
}

template <typename T, typename Container>
bool operator> (const MutantStack<T, Container> & lhs, const MutantStack<T, Container> & rhs)
{
	return (lhs._c > rhs._c);
}

template <typename T, typename Container>
bool operator>= (const MutantStack<T, Container> & lhs, const MutantStack<T, Container> & rhs)
{
	return (lhs._c >= rhs._c);
}

#include "MutantStack.tpp"

////////////////////////////////////////////////////////////////

template <class T, class Container = std::deque<T> >
class MutantStack2 : public std::stack<T, Container>
{
public:
	MutantStack2(void){};
	MutantStack2( const MutantStack2& src ): std::stack<T, Container>(src) {}
	~MutantStack2(void){};
	MutantStack2&	operator=( const MutantStack2& src )
	{
		std::stack< T, Container >::operator=( src );
		return *this;
	}

	typedef typename Container::iterator	iterator;
	iterator	begin() { return this->c.begin(); }
	iterator	end() { return this->c.end(); }

};

#endif