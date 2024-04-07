/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 15:28:33 by yzaoui            #+#    #+#             */
/*   Updated: 2024/04/07 00:56:34 by yzaoui           ###   ########.fr       */
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

Fixed::Fixed()
{
	std::string cyan = "\033[36m";
	std::string no_color = "\033[0m";

	this->_rawBits = 0;
	std::cout << cyan << "Default constructor called" << no_color << std::endl;
}

Fixed::Fixed(const int nbr)
{
	std::string	yellow = "\033[33m";
	std::string	no_color = "\033[0m";

	this->_rawBits = nbr << this->_coma;
	std::cout << yellow << "Int constructor called" << no_color << std::endl;
}

Fixed::Fixed(const float nbr)
{
	std::string no_color = "\033[0m";
	std::string magenta = "\033[35m";
	this->_rawBits = nbr * ft_pow(2, this->_coma);
	std::cout << magenta << "Float constructor called" << no_color << std::endl;
}


Fixed::Fixed(Fixed const & src)
{
	std::string no_color = "\033[0m";
	std::string green = "\033[32m";
	
	std::cout << green << "Copy constructor called" << no_color << std::endl;
	*this = src;
}

Fixed	&Fixed::operator=(Fixed const &rf)
{
	std::string no_color = "\033[0m";
	std::string green = "\033[32m";

	std::cout << green << "Copy assignment operator called" << no_color << std::endl;
	if (this != &rf)
		this->_rawBits = rf.getRawBits();
	return (*this);
}

Fixed::~Fixed()
{
	std::string no_color = "\033[0m";
	std::string red = "\033[31m";

	std::cout << red << "Destructor called" << no_color << std::endl;
}

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

std::ostream	&operator<<( std::ostream & o, Fixed const & rf)
{
	o << rf.toFloat();
	return o;
}
