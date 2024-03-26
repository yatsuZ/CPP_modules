/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sample.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 21:57:09 by yzaoui            #+#    #+#             */
/*   Updated: 2024/03/25 23:30:42 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Sample.class.hpp"

Sample::Sample( void ){
	std::cout << "Constructor called" << std::endl;
	return;
}

Sample::~Sample(void) {
	std::cout << "Destructor called" << std::endl;
	return;
}

void	Sample::bar( char const c) const {
	std::cout << "Member function bar called with char overload : " << c << std::endl;
	return;
}

void	Sample::bar(int const n) const {
	std::cout << "Member function bar called with int overload : " << n << std::endl;
	return;
}

void	Sample::bar( float const z ) const {
	std::cout << "Member function bar called with float overload : " << z << std::endl;
	return;
}

void	Sample::bar( Sample const & i) const {
	( void ) i;
	std::cout << "Member function bar called with Sample pointer overload." << std::endl;
	return;
}
