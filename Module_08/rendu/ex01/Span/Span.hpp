/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 16:51:15 by yzaoui            #+#    #+#             */
/*   Updated: 2024/06/22 15:57:47 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <string>
#include <iterator>
#include <algorithm>
#include <limits>
#include <list>
#include <vector>

#define NOCOLOR "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"
#define PURPLE "\033[35m"


class Span
{
private:
	unsigned int		_n;
	std::list<int>	 _contenair;
	unsigned int		_place;
	unsigned int		getN(void) const;
	unsigned int		getPlace(void) const;
	void				setN(const int n);
	std::list<int>	getContenair(void) const;
	class ToShort : public std::exception
	{
	private:
		std::string _message;
	public:
		ToShort(const std::string &additionalInfo)
		{
			_message = std::string(MAGENTA "Span is too short") + additionalInfo + NOCOLOR;
		}
		ToShort(void)
		{
			_message = std::string(MAGENTA "Span is too short" NOCOLOR);
		}
		virtual ~ToShort() throw() {}
		virtual const char *what() const throw()
		{
			return _message.c_str();
		}
	};
	class NoMorePlace : public std::exception
	{
		public :
			virtual const char* what() const throw()
			{
				return (RED "Span has no more place for add a new Number." NOCOLOR);
			}
	};
	Span();
public:
	void			showSpan(void) const;
	Span(unsigned int n);
	~Span();
	Span(const Span &src);
	Span			&operator=(const Span &src);

	long				shortestSpan(void) const;
	long				longestSpan(void) const;
	void				addNumber(const int nbr);
	template <typename T>
	void				addNumbers(const T& numbers);
};

template <typename T>
void			Span::addNumbers(const T& numbers)
{
	for (typename T::const_iterator it = numbers.begin(); it != numbers.end() && this->getPlace(); ++it)
	{
		this->addNumber(*it);
	}
}


#endif