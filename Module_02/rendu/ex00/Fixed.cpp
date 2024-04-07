/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 15:28:33 by yzaoui            #+#    #+#             */
/*   Updated: 2024/04/07 18:56:07 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Fixed.hpp"

// |--- Constructeur ---|

Fixed::Fixed()
{
	this->_rawBits = 0;
	std::cout << BLUE << "Default constructor called" << NOCOLOR << std::endl;
}

Fixed::Fixed(Fixed const & src)
{
	std::cout << YELLOW << "Copy constructor called" << NOCOLOR << std::endl;
	*this = src;
}

// |--- Destructeur ----|

Fixed::~Fixed()
{
	std::cout << RED << "Destructor called" << NOCOLOR << std::endl;
}

// |--- Opperateur d'assignation ---|

Fixed	&Fixed::operator=(Fixed const &rf)
{
	std::cout << YELLOW << "Copy assignment operator called" << NOCOLOR << std::endl;
	if (this != &rf)
		this->_rawBits = rf.getRawBits();
	return (*this);
}

// |--- Autre ---|

int		Fixed::getRawBits(void) const
{
	std::cout << GREEN << "getRawBits member function called" << NOCOLOR << std::endl;
	return (this->_rawBits);
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << GREEN << "Setteur function called" << NOCOLOR << std::endl;
	this->_rawBits = raw;
}

