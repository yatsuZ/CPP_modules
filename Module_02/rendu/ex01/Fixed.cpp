/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 15:28:33 by yzaoui            #+#    #+#             */
/*   Updated: 2024/04/07 19:53:13 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Fixed.hpp"

float	ft_pow(float base, int pow)
{
	float	res = 1;
	
	if (base == 0)
		return (0);
	if (pow < 0)
	{
		for (;pow != 0; pow++)
			res = res * (1 / base);
	}
	else
	{
		for (;pow != 0; pow--)
			res = res * base;
	}
	return (res);
}

// |--- Constructeur ---|

Fixed::Fixed()
{
	this->_rawBits = 0;
	std::cout << BLUE << "Default constructor called" << NOCOLOR << std::endl;
}

Fixed::Fixed(const int nbr)
{
	if (nbr > 8388607 || nbr < -8388608)
		std::cout << RED << "<! RISQUE d'overflow en cas de conversion Float !> " << NOCOLOR;
	this->_rawBits = nbr << this->_coma;
	std::cout << MAGENTA << "Int constructor called" << NOCOLOR << std::endl;
}

Fixed::Fixed(const float nbr)
{
	this->_rawBits = (int)roundf(nbr * ft_pow(2, this->_coma));
	std::cout << MAGENTA << "Float constructor called" << NOCOLOR << std::endl;
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

// |--- Conversion ---|

float	Fixed::toFloat(void) const
{
	float	res;

	res = this->_rawBits * ft_pow(2, (-1 * this->_coma));
	return (res);
}

int	Fixed::toInt(void) const
{
	int	res;

	res = this->_rawBits >> 8;
	return (res);

}

// |--- Autre ---|

int		Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_rawBits);
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "Setteur function called" << std::endl;
	this->_rawBits = raw;
}


std::ostream	&operator<<( std::ostream & o, Fixed const & rf)
{
	o << rf.toFloat();
	return o;
}
