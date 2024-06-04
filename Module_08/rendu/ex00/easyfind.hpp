/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 13:05:28 by yzaoui            #+#    #+#             */
/*   Updated: 2024/06/04 14:04:32 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <algorithm>
#include <iterator>
#include <exception>
#include <iostream>
#include <vector>
#include <list>

class NotFoundException : public std::exception
{
	public :
		virtual const char* what() const throw()
		{
			return ("Not Found.");
		}
};

template <typename T>
typename T::iterator easyfind(T &container, int value) {
	typename T::iterator it = std::find(container.begin(), container.end(), value);
	if (it == container.end()) {
		throw NotFoundException();
	}
	return it;
};

#endif