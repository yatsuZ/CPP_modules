/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 21:32:25 by yzaoui            #+#    #+#             */
/*   Updated: 2024/06/11 15:12:08 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <iostream>
#include <deque>
#include <exception>

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
class MutantStack
{
public:
	// Types membres
	typedef T value_type;
	typedef Container container_type;
	typedef typename Container::size_type size_type;
private:
	class MethodeContainerException : public std::exception
	{
	private:
		std::string _message;
	public:
		NotFoundMethodeContainerException(const std::string &additionalInfo)
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

	Container _c;
public:
	MutantStack(void);
	MutantStack(const MutantStack &src);
	MutantStack(const container_type &src);
	MutantStack	&operator=(const MutantStack &src);
	~MutantStack(void);

	bool 		empty() const;
	size_type	size(void) const;

};

#include "MutantStack.tpp"


#endif