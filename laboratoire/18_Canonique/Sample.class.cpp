/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sample.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 21:57:09 by yzaoui            #+#    #+#             */
/*   Updated: 2024/03/26 01:45:49 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Sample.class.hpp"

Sample::Sample( void ) : _foo(0){
	std::cout << "Default Constructor called" << std::endl;
	return;
}

Sample::Sample( int const n ) : _foo(n){
	std::cout << "Parametric Constructor called" << std::endl;
	return;
}

Sample::Sample( Sample const &src){
	std::cout << "Copy Constructor called" << std::endl;
	*this = src;

	return;
}

Sample::~Sample(void) {
	std::cout << "Destructor called" << std::endl;
	return;
}

Sample	&Sample::operator=( Sample const &rhs){
	std::cout << "Assignment opperator called" << std::endl;
	if (this != &rhs)
		this->_foo = rhs.getFoo();
	
	return (*this);
}

int	Sample::getFoo(void) const
{
	return (this->_foo);
}

std::ostream	&operator<<(std::ostream &o, Sample const &i){
	o << "The value of _foo is : " << i.getFoo();
	
	return (o);
}
