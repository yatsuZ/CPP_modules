/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 15:28:33 by yzaoui            #+#    #+#             */
/*   Updated: 2024/04/07 21:42:02 by yzaoui           ###   ########.fr       */
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

Fixed::Fixed(): _rawBits(0)
{
}

Fixed::Fixed(const int nbr)
{
	if (nbr > 8388607 || nbr < -8388608)
		std::cout << RED << "<! RISQUE d'overflow en cas de conversion Float \"" << nbr << "\" !> " << NOCOLOR;
	this->_rawBits = nbr << this->_coma;
}

Fixed::Fixed(const float nbr)
{
	this->_rawBits = (int)roundf(nbr * ft_pow(2, this->_coma));
}

Fixed::Fixed(Fixed const & src)
{
	*this = src;
}

// |--- Destructeur ----|

Fixed::~Fixed()
{
}

// |--- Setteur et geteur

int		Fixed::getRawBits(void) const
{
	return (this->_rawBits);
}

void	Fixed::setRawBits(int const raw)
{
	this->_rawBits = raw;
}

// |--- Conversion ----|

float	Fixed::toFloat(void) const
{
	float	res;

	res = (float)this->_rawBits / (float)ft_pow(2, this->_coma);
	return (res);
}

int	Fixed::toInt(void) const
{
	int	res;

	res = this->_rawBits >> 8;
	return (res);
}

//////////////// |--- Opperateur ---|

std::ostream	&operator<<( std::ostream & o, Fixed const & rf)
{
	o << rf.toFloat();
	return o;
}

//////////////// |--- Assignation

Fixed	&Fixed::operator=(Fixed const &rf)
{
	if (this != &rf)
		this->_rawBits = rf.getRawBits();
	return (*this);
}

//////////////// |--- Comparaison logique

bool	Fixed::operator>(Fixed const & rf) const
{
	return (this->getRawBits() > rf.getRawBits());
}

bool	Fixed::operator<(Fixed const & rf) const
{
	return (this->getRawBits() < rf.getRawBits());
}

bool	Fixed::operator<=(Fixed const & rf) const
{
	return (this->getRawBits() <= rf.getRawBits());
}

bool	Fixed::operator>=(Fixed const & rf) const
{
	return (this->getRawBits() >= rf.getRawBits());
}

bool	Fixed::operator==(Fixed const & rf) const
{
	return (this->getRawBits() == rf.getRawBits());
}

bool	Fixed::operator!=(Fixed const & rf) const
{
	return (this->getRawBits() != rf.getRawBits());
}

//////////////// |--- Operrateur Arithematic

Fixed	Fixed::operator+(Fixed const & rf)
{
	return (Fixed(this->toFloat() + rf.toFloat()));
}

Fixed	Fixed::operator-(Fixed const & rf)
{
	return (Fixed(this->toFloat() - rf.toFloat()));
}

Fixed	Fixed::operator*(Fixed const & rf)
{
	return (Fixed(rf.toFloat() * this->toFloat()));
}

Fixed	Fixed::operator/(Fixed const & rf)
{
	if (rf.getRawBits() == 0)
	{
		std::cout << "Error can't divide by 0!" << std::endl;
		return (Fixed(0));
	}
	return (Fixed(this->toFloat() / rf.toFloat()));
}

//////////////// |--- Accrementation / Deccrementation

Fixed	Fixed::operator++(void)
{
	this->_rawBits++;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed temp = *this;
	this->_rawBits++;
	return (temp);
}

Fixed	Fixed::operator--(void)
{
	this->_rawBits--;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed temp = *this;
	this->_rawBits--;
	return (temp);
}

//////////////// |--- BONUS

Fixed	&Fixed::operator+=(Fixed const & rf)
{
	*this = *this + rf;
	return (*this);
}

Fixed	&Fixed::operator-=(Fixed const & rf)
{
	*this = *this - rf;
	return (*this);
}

Fixed	&Fixed::operator*=(Fixed const & rf)
{
	*this = *this * rf;
	return (*this);
}

Fixed	&Fixed::operator/=(Fixed const & rf)
{
	*this = *this / rf;
	return (*this);
}

Fixed	Fixed::operator-(void)
{
	return (*this * -1);
}

// |--- Get min max const

Fixed	Fixed::min(Fixed const & rf1, Fixed const & rf2)
{
	Fixed minRef = (rf1 < rf2) ? rf1 : rf2;
	return minRef;
}

const Fixed	Fixed::minConst(Fixed const & rf1, Fixed const & rf2)
{
	const Fixed minRef = (rf1 < rf2) ? rf1 : rf2;
	return minRef;
}

Fixed	Fixed::max(Fixed const & rf1, Fixed const & rf2)
{
	Fixed maxRef = (rf1 > rf2) ? rf1 : rf2;
	return maxRef;
}

const Fixed	Fixed::maxConst(Fixed const & rf1, Fixed const & rf2)
{
	const Fixed maxRef = (rf1 > rf2) ? rf1 : rf2;
	return maxRef;
}

