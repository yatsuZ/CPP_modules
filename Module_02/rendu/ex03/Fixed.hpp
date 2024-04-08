/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 15:27:55 by yzaoui            #+#    #+#             */
/*   Updated: 2024/04/07 21:31:01 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>
#include <limits>

#define NOCOLOR "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"
#define PURPLE "\033[35m"

class Fixed
{
private:
	int					_rawBits;
	static const int	_coma = 8;

public:
	// Constructeur
	Fixed(void);
	Fixed(const int nbr);
	Fixed(const float nbr);
	Fixed(Fixed const & src);

	// Destructeur
	~Fixed();

	// Autre
	int		getRawBits(void) const;
	void	setRawBits(int const raw);

	// Conversion
	float	toFloat(void) const;
	int		toInt(void) const;
	
	////////////// Opperateur

	Fixed	&operator=(Fixed const & rf);

// Operrateur Arithematic
	Fixed	operator+(Fixed const & rf);
	Fixed	operator-(Fixed const & rf);
	Fixed	operator*(Fixed const & rf);
	Fixed	operator/(Fixed const & rf);

// Comparaison logique
	bool	operator>(Fixed const & rf) const;
	bool	operator<(Fixed const & rf) const;
	bool	operator<=(Fixed const & rf) const;
	bool	operator>=(Fixed const & rf) const;
	bool	operator==(Fixed const & rf) const;
	bool	operator!=(Fixed const & rf) const;

// Accrementation / Deccrementation
	Fixed	operator++(void);
	Fixed	operator++(int);
	Fixed	operator--(void);
	Fixed	operator--(int);

// BONUS
	Fixed	&operator+=(Fixed const & rf);
	Fixed	&operator-=(Fixed const & rf);
	Fixed	&operator*=(Fixed const & rf);
	Fixed	&operator/=(Fixed const & rf);
	Fixed	operator-(void);

// Get min max const
	static Fixed	min(Fixed const & rf1, Fixed const & rf2);
	static const Fixed	minConst(Fixed const & rf1, Fixed const & rf2);
	static Fixed	max(Fixed const & rf1, Fixed const & rf2);
	static const Fixed	maxConst(Fixed const & rf1, Fixed const & rf2);
};

std::ostream & operator<<( std::ostream & o, Fixed const & rf);

float	ft_pow(float base, int pow);

#endif
